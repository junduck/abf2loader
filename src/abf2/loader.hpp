#pragma once

#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#if defined(_WIN32)
#include <windows.h>
#else
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#include "meta.hpp"

namespace abf2 {
namespace detail {
class SimpleFileReader {
  std::string s;

public:
  explicit SimpleFileReader(std::string const &path) {
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs) {
      throw std::runtime_error("Unable to open file");
    }
    std::string read(std::istreambuf_iterator<char>(ifs), {});
    s = std::move(read);
  }

  SimpleFileReader(SimpleFileReader const &) = delete;
  SimpleFileReader &operator=(SimpleFileReader const &) = delete;

  auto data() const -> char const * { return s.data(); }
  size_t size() const { return s.size(); }
};

class SimpleFileMapper {
private:
  char const *mapped;
  size_t mapped_size;

#if defined(_WIN32)
  HANDLE file;
  HANDLE map;
#else
  int file;
#endif

public:
  explicit SimpleFileMapper(std::string const &path) {
#if defined(_WIN32)
    file = CreateFile(path.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING,
                      FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE)
      throw std::runtime_error("Unable to open file");

    LARGE_INTEGER fileSize;
    if (!GetFileSizeEx(file, &fileSize)) {
      CloseHandle(file);
      throw std::runtime_error("Unable to get file size");
    }

    map = CreateFileMapping(file, nullptr, PAGE_READONLY, fileSize.HighPart,
                            fileSize.LowPart, nullptr);
    if (!map) {
      CloseHandle(file);
      throw std::runtime_error("Unable to mmap file");
    }

    mapped = static_cast<const char *>(
      MapViewOfFile(map, FILE_MAP_READ, 0, 0, fileSize.QuadPart));
    mapped_size = fileSize.QuadPart;
#else
    file = open(path.c_str(), O_RDONLY);
    if (file < 0)
      throw std::runtime_error("Unable to open file");

    struct stat fileInfo;
    if (fstat(file, &fileInfo) != 0) {
      close(file);
      throw std::runtime_error("Unable to get file size");
    }

    mapped = static_cast<const char *>(
      mmap(nullptr, fileInfo.st_size, PROT_READ, MAP_SHARED, file, 0));
    if (mapped == MAP_FAILED) {
      close(file);
      throw std::runtime_error("Unable to mmap file");
    }
    mapped_size = fileInfo.st_size;
#endif
  }

  ~SimpleFileMapper() {
#if defined(_WIN32)
    UnmapViewOfFile(mapped);
    CloseHandle(map);
    CloseHandle(file);
#else
    munmap((void *)mapped, mapped_size);
    close(file);
#endif
  }

  SimpleFileMapper(SimpleFileMapper const &) = delete;
  SimpleFileMapper &operator=(SimpleFileMapper const &) = delete;

  auto data() const -> char const * { return mapped; }
  size_t size() const { return mapped_size; }
};
} // namespace detail

class DataLoader {
  size_t nchan, nsweep, ntick;
  std::vector<double> scale, offset;
  std::vector<pack::ABF2SynchArray> sa;
  pack::ABF2SectionInfo data_section;
  int op_mode;

  // data in ram: chan, sweep, tick
  size_t v_idx(size_t chan, size_t sweep, size_t tick) const {
    return chan * nsweep * ntick + sweep * ntick + tick;
  }

  // data on disk: sweep, tick, chan
  size_t raw_idx(size_t chan, size_t sweep, size_t tick) const {
    return sweep * ntick * nchan + tick * nchan + chan;
  }

  template <typename PtrType>
  void copy_data_fixed(PtrType raw, double *target) const {
    for (size_t sweep = 0; sweep < nsweep; ++sweep)
      for (size_t tick = 0; tick < ntick; ++tick)
        for (size_t chan = 0; chan < nchan; ++chan) {
          target[v_idx(chan, sweep, tick)] = raw[raw_idx(chan, sweep, tick)];
        }
  }

  template <typename PtrType>
  void copy_data_var(PtrType raw, double *target) const {
    size_t p = 0;
    for (size_t event = 0; event < nsweep; ++event) {
      for (size_t tick = 0; tick < sa[event].lLength; ++tick) {
        for (size_t chan = 0; chan < nchan; ++chan) {
          target[v_idx(chan, event, tick)] = raw[p];
          ++p;
        }
      }
    }
  }

public:
  explicit DataLoader(FileMeta const &meta) {
    data_section = meta.header.sections[10];
    sa = meta.synchArray;
    op_mode = meta.protocol.nOperationMode;

    nchan = meta.adc.size();
    switch (op_mode) {
    case 1:
      // event driven variable length mode
      // in this mode, every "sweep" is a recorded event
      nsweep = meta.synchArray.size();
      ntick = 0;
      for (auto const &sa : meta.synchArray) {
        ntick = std::max<size_t>(ntick, sa.lLength);
      }
      ntick /= nchan;
      break;
    case 2: // event driven fixed length
    case 4: // high speed oscilloscope
    case 5: // waveform fixed length
      nsweep = meta.synchArray.size();
      assert(nsweep == meta.protocol.lEpisodesPerRun);
      ntick = meta.synchArray[0].lLength / nchan;
      assert(ntick == meta.protocol.lNumSamplesPerEpisode / nchan);
      break;
    case 3: // gap free
      nsweep = 1;
      ntick = data_section.llNumEntries / nchan;
      break;
    default:
      throw std::runtime_error("Unsupported operation mode");
    }

    if (data_section.uBytes == 2) {
      // int16 mode, handle scale and offset
      double resol = meta.protocol.fADCRange / meta.protocol.lADCResolution;
      scale = std::vector<double>(nchan);
      offset = std::vector<double>(nchan);
      for (size_t i = 0; i < nchan; ++i) {
        // instrument scale factor
        scale[i] = meta.adc[i].fInstrumentScaleFactor;
        // signal gain
        scale[i] *= meta.adc[i].fSignalGain;
        // telegraph gain
        scale[i] *= meta.adc[i].fADCProgrammableGain;
        // telegraph additional gain
        if (meta.adc[i].nTelegraphEnable)
          scale[i] *= meta.adc[i].fTelegraphAdditGain;
        // rescale to resolution
        scale[i] = resol / scale[i];
        // Axon: why are we subtracting fSignalOffset? this is not what "offset"
        // means
        offset[i] = meta.adc[i].fInstrumentOffset - meta.adc[i].fSignalOffset;
      }
    } else if (data_section.uBytes == 4) {
      // float mode, no scale and offset
      scale = std::vector<double>(nchan, 1.0);
      offset = std::vector<double>(nchan, 0.0);
    } else {
      throw std::runtime_error("Unsupported data type");
    }
  }

  size_t alloc_size() const { return nchan * nsweep * ntick; }
  size_t n_chan() const { return nchan; }
  size_t n_sweep() const { return nsweep; }
  size_t n_tick() const { return ntick; }

  void fill_data(char const *raw, double *target) const {
    // regarding to reinterpret_cast:
    // raw should be allocated aligned to stricter alignment requirement than
    // int16_t on 32/64 bit (4/8 bytes, while we need 2) because offset is
    // always multiple of 512 (see FileMeta::get_offset)
    auto ofs = FileMeta::get_offset(data_section);
    if (data_section.uBytes == 2) {
      auto ptr = reinterpret_cast<int16_t const *>(raw + ofs);
      if (op_mode == 1) {
        copy_data_var(ptr, target);
      } else {
        copy_data_fixed(ptr, target);
      }
      for (size_t chan = 0; chan < nchan; ++chan)
        for (size_t sweep = 0; sweep < nsweep; ++sweep)
          for (size_t tick = 0; tick < ntick; ++tick)
            target[v_idx(chan, sweep, tick)] =
              scale[chan] * target[v_idx(chan, sweep, tick)] + offset[chan];
    } else {
      auto ptr = reinterpret_cast<float const *>(raw + ofs);
      if (op_mode == 1) {
        copy_data_var(ptr, target);
      } else {
        copy_data_fixed(ptr, target);
      }
    }
  }
};

} // namespace abf2
