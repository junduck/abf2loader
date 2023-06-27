#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

namespace abf2 {
namespace pack {
// clang-format off
#pragma pack(push, 1)
struct ABF2Header {
  char fFileSignature[4];      // File signature, should be "ABF2"
                               // FileVersionNumber =
  int8_t fFileVersionNumber1;  // fFileVersionNumber1 * 0.001 +
  int8_t fFileVersionNumber2;  // fFileVersionNumber2 * 0.01 +
  int8_t fFileVersionNumber3;  // fFileVersionNumber3 * 0.1 +
  int8_t fFileVersionNumber4;  // fFileVersionNumber4
  uint32_t uFileInfoSize;      //
  uint32_t lActualEpisodes;    //
  uint32_t uFileStartDate;     // YYYYMMDD, only if FileVersionNumber >= 2.0
  uint32_t uFileStartTimeMS;   // ms since midnight of FileStartDate
  uint32_t uStopwatchTime;     //
  int16_t nFileType;           //
  int16_t nDataFormat;         // if 0, int16 data record is used, otherwise float32.
  int16_t nSimultaneousScan;   //
  int16_t nCRCEnable;          //
  uint32_t uFileCRC;           //
  int64_t FileGUID1;           //
  int64_t FileGUID2;           //
  uint32_t uCreatorVersion;    //
  uint32_t uCreatorNameIndex;  // corresponds to string table index
  uint32_t uModifierVersion;   //
  uint32_t uModifierNameIndex; // corresponds to string table index
  uint32_t uProtocolPathIndex; // corresponds to string table index
};

struct ABF2SectionInfo {
  uint32_t uBlockIndex; // Where the section starts in the file, each block is 512 bytes
  uint32_t uBytes;      // could be total bytes or bytes per entry depending on the section
  int64_t llNumEntries; // number of entries in the section
};

struct ABF2Protocol {
  int16_t nOperationMode;
  float fADCSequenceInterval;
  int8_t bEnableFileCompression;
  char sUnused1[3];
  uint32_t uFileCompressionRatio;
  float fSynchTimeUnit;
  float fSecondsPerRun;
  int32_t lNumSamplesPerEpisode;
  int32_t lPreTriggerSamples;
  int32_t lEpisodesPerRun;
  int32_t lRunsPerTrial;
  int32_t lNumberOfTrials;
  int16_t nAveragingMode;
  int16_t nUndoRunCount;
  int16_t nFirstEpisodeInRun;
  float fTriggerThreshold;
  int16_t nTriggerSource;
  int16_t nTriggerAction;
  int16_t nTriggerPolarity;
  float fScopeOutputInterval;
  float fEpisodeStartToStart;
  float fRunStartToStart;
  int32_t lAverageCount;
  float fTrialStartToStart;
  int16_t nAutoTriggerStrategy;
  float fFirstRunDelayS;
  int16_t nChannelStatsStrategy;
  int32_t lSamplesPerTrace;
  int32_t lStartDisplayNum;
  int32_t lFinishDisplayNum;
  int16_t nShowPNRawData;
  float fStatisticsPeriod;
  int32_t lStatisticsMeasurements;
  int16_t nStatisticsSaveStrategy;
  float fADCRange;
  float fDACRange;
  int32_t lADCResolution;
  int32_t lDACResolution;
  int16_t nExperimentType;
  int16_t nManualInfoStrategy;
  int16_t nCommentsEnable;
  int32_t lFileCommentIndex;
  int16_t nAutoAnalyseEnable;
  int16_t nSignalType;
  int16_t nDigitalEnable;
  int16_t nActiveDACChannel;
  int16_t nDigitalHolding;
  int16_t nDigitalInterEpisode;
  int16_t nDigitalDACChannel;
  int16_t nDigitalTrainActiveLogic;
  int16_t nStatsEnable;
  int16_t nStatisticsClearStrategy;
  int16_t nLevelHysteresis;
  int32_t lTimeHysteresis;
  int16_t nAllowExternalTags;
  int16_t nAverageAlgorithm;
  float fAverageWeighting;
  int16_t nUndoPromptStrategy;
  int16_t nTrialTriggerSource;
  int16_t nStatisticsDisplayStrategy;
  int16_t nExternalTagType;
  int16_t nScopeTriggerOut;
  int16_t nLTPType;
  int16_t nAlternateDACOutputState;
  int16_t nAlternateDigitalOutputState;
  float fCellID1;
  float fCellID2;
  float fCellID3;
  int16_t nDigitizerADCs;
  int16_t nDigitizerDACs;
  int16_t nDigitizerTotalDigitalOuts;
  int16_t nDigitizerSynchDigitalOuts;
  int16_t nDigitizerType;
  char sUnused[304];
};

struct ABF2ADC {
  int16_t nADCNum;
  int16_t nTelegraphEnable;
  int16_t nTelegraphInstrument;
  float fTelegraphAdditGain;
  float fTelegraphFilter;
  float fTelegraphMembraneCap;
  int16_t nTelegraphMode;
  float fTelegraphAccessResistance;
  int16_t nADCPtoLChannelMap;
  int16_t nADCSamplingSeq;
  float fADCProgrammableGain;
  float fADCDisplayAmplification;
  float fADCDisplayOffset;
  float fInstrumentScaleFactor;
  float fInstrumentOffset;
  float fSignalGain;
  float fSignalOffset;
  float fSignalLowpassFilter;
  float fSignalHighpassFilter;
  int8_t nLowpassFilterType;
  int8_t nHighpassFilterType;
  float fPostProcessLowpassFilter;
  int8_t nPostProcessLowpassFilterType;
  int8_t bEnabledDuringPN;
  int16_t nStatsChannelPolarity;
  int32_t lADCChannelNameIndex;
  int32_t lADCUnitsIndex;
  char sUnused[46];
};

struct ABF2DAC {
  int16_t nDACNum;
  int16_t nTelegraphDACScaleFactorEnable;
  float fInstrumentHoldingLevel;
  float fDACScaleFactor;
  float fDACHoldingLevel;
  float fDACCalibrationFactor;
  float fDACCalibrationOffset;
  int32_t lDACChannelNameIndex;
  int32_t lDACChannelUnitsIndex;
  int32_t lDACFilePtr;
  int32_t lDACFileNumEpisodes;
  int16_t nWaveformEnable;
  int16_t nWaveformSource;
  int16_t nInterEpisodeLevel;
  float fDACFileScale;
  float fDACFileOffset;
  int32_t lDACFileEpisodeNum;
  int16_t nDACFileADCNum;
  int16_t nConditEnable;
  int32_t lConditNumPulses;
  float fBaselineDuration;
  float fBaselineLevel;
  float fStepDuration;
  float fStepLevel;
  float fPostTrainPeriod;
  float fPostTrainLevel;
  int16_t nMembTestEnable;
  int16_t nLeakSubtractType;
  int16_t nPNPolarity;
  float fPNHoldingLevel;
  int16_t nPNNumADCChannels;
  int16_t nPNPosition;
  int16_t nPNNumPulses;
  float fPNSettlingTime;
  float fPNInterpulse;
  int16_t nLTPUsageOfDAC;
  int16_t nLTPPresynapticPulses;
  int32_t lDACFilePathIndex;
  float fMembTestPreSettlingTimeMS;
  float fMembTestPostSettlingTimeMS;
  int16_t nLeakSubtractADCIndex;
  char sUnused[124];
};

struct ABF2Epoch {
  int16_t nEpochNum;
  int16_t nDigitalValue;
  int16_t nDigitalTrainValue;
  int16_t nAlternateDigitalValue;
  int16_t nAlternateDigitalTrainValue;
  int8_t bEpochCompression;
  char sUnused[21];
};

// ADCPerDAC is unknown
struct ADCPerDAC {
};

struct ABF2EpochPerDAC {
  int16_t nEpochNum;
  int16_t nDACNum;
  int16_t nEpochType;
  float fEpochInitLevel;
  float fEpochLevelInc;
  int32_t lEpochInitDuration;
  int32_t lEpochDurationInc;
  int32_t lEpochPulsePeriod;
  int32_t lEpochPulseWidth;
  char sUnused[18];
};

struct ABF2UserList {
  int16_t nListNum;
  int16_t nULEnable;
  int16_t nULParamToVary;
  int16_t nULRepeat;
  int32_t lULParamValueListIndex;
  char sUnused[52];
};

struct ABF2StatsRegion {
  int16_t nRegionNum;
  int16_t nADCNum;
  int16_t nStatsActiveChannels;
  int16_t nStatsSearchRegionFlags;
  int16_t nStatsSelectedRegion;
  int16_t nStatsSmoothing;
  int16_t nStatsSmoothingEnable;
  int16_t nStatsBaseline;
  int32_t lStatsBaselineStart;
  int32_t lStatsBaselineEnd;
  int32_t lStatsMeasurements;
  int32_t lStatsStart;
  int32_t lStatsEnd;
  int16_t nRiseBottomPercentile;
  int16_t nRiseTopPercentile;
  int16_t nDecayBottomPercentile;
  int16_t nDecayTopPercentile;
  int16_t nStatsSearchMode;
  int16_t nStatsSearchDAC;
  int16_t nStatsBaselineDAC;
  char sUnused[78];
};

struct ABF2Math {
  int16_t nMathEnable;
  int16_t nMathExpression;
  uint32_t uMathOperatorIndex;
  uint32_t uMathUnitsIndex;
  float fMathUpperLimit;
  float fMathLowerLimit;
  int16_t nMathADCNum1;
  int16_t nMathADCNum2;
  char sUnused1[16];
  float fMathK1;
  float fMathK2;
  float fMathK3;
  float fMathK4;
  float fMathK5;
  float fMathK6;
  char sUnused2[64];
};

// ABF1 specification

struct ABF2Tag {
  int32_t lTagTime;
  char sComment[56];
  int16_t nTagType;
  int16_t nVoiceTagNumber_nAnnotationIndex;
};

struct ABF2SynchArray {
  int32_t lStart;
  int32_t lLength;
};

// TODO: theses sections are not parsed yet
// Scope
// Delta
// VoiceTag
// Annotation
// Stats
#pragma pack(pop)
// clang-format on

constexpr static size_t ABF2HeaderSize = sizeof(ABF2Header);
constexpr static size_t ABF2SectionInfoSize = sizeof(ABF2SectionInfo);
constexpr static size_t ABF2ProtocolSize = sizeof(ABF2Protocol);
constexpr static size_t ABF2ADCSize = sizeof(ABF2ADC);
constexpr static size_t ABF2DACSize = sizeof(ABF2DAC);
constexpr static size_t ABF2EpochSize = sizeof(ABF2Epoch);
constexpr static size_t ABF2EpochPerDACSize = sizeof(ABF2EpochPerDAC);
constexpr static size_t ABF2UserListSize = sizeof(ABF2UserList);
constexpr static size_t ABF2StatsRegionSize = sizeof(ABF2StatsRegion);
constexpr static size_t ABF2MathSize = sizeof(ABF2Math);
constexpr static size_t ABF2TagSize = sizeof(ABF2Tag);
constexpr static size_t ABF2SynchArraySize = sizeof(ABF2SynchArray);

constexpr static size_t ABF2BlockSize = 512;
constexpr static size_t ABF2StringsOffset = 44; // funny. Axon, why???!!!
} // namespace pack

// ABF2 section list (in order)
// Protocol
// ADC
// DAC
// Epoch
// ADCPerDAC         *not parsed, no info found for this section
// EpochPerDAC
// UserList
// StatsRegion
// Math
// Strings           *null terminated list of strings
// Data              *actual data
// Tag
// Scope             *not parsed yet
// Delta             *not parsed yet
// VoiceTag          *not parsed yet
// SynchArray
// Annotation        *ABF1 only, not parsed
// Stats             *ABF1 only, not parsed

// DEBUG: there is no way to tell endianess from the file
// little endian is always assumed

// ABF2 File structure
// Header:
// | ABF2FileHeader | ABF2SectionInfo ... (18) |
struct FileHeader {
  pack::ABF2Header header;
  std::array<pack::ABF2SectionInfo, 18> sections;

  explicit FileHeader(char const *data) {
    std::memcpy(&header, data, pack::ABF2HeaderSize);
    std::memcpy(sections.data(), data + pack::ABF2HeaderSize,
                pack::ABF2SectionInfoSize * 18);
  }
};

struct FileMeta {
  FileHeader header;
  // ABF2 specific
  pack::ABF2Protocol protocol;
  std::vector<pack::ABF2ADC> adc;     // one for each ADC channel
  std::vector<pack::ABF2DAC> dac;     // one for each DAC channel
  std::vector<pack::ABF2Epoch> epoch; // one for each epoch
  // ? adcPerDac
  std::vector<pack::ABF2EpochPerDAC> epochPerDac; // one for each epoch per DAC
  std::vector<pack::ABF2UserList> userList;       // one for each user list
  std::vector<pack::ABF2StatsRegion> statsRegion; // one for each stats region
  std::vector<pack::ABF2Math> math;               // one for each math operation
  std::vector<std::string> strings; // null terminated list of strings

  // Data section not store in meta

  // ABF1 specific
  std::vector<pack::ABF2Tag> tag; // one for each tag
  // ? scope
  // ? delta
  // ? voiceTag
  std::vector<pack::ABF2SynchArray> synchArray; // one for each synch array
  // ? annotation
  // ? stats

  constexpr static size_t get_offset(pack::ABF2SectionInfo const &section) {
    return section.uBlockIndex * pack::ABF2BlockSize;
  }

  explicit FileMeta(char const *data) : header(data) {
    size_t offset, n, bsize;

    // read protocol
    if (!header.sections[0].llNumEntries) {
      throw std::runtime_error("No protocol section found");
    }
    offset = get_offset(header.sections[0]);
    std::memcpy(&protocol, data + offset, pack::ABF2ProtocolSize);

#define DO_READ(id, mem_name, pack_name)                                       \
  do {                                                                         \
    offset = get_offset(header.sections[id]);                                  \
    n = header.sections[id].llNumEntries;                                      \
    bsize = pack::ABF2##pack_name##Size;                                       \
    mem_name.reserve(n);                                                       \
    for (size_t i = 0; i < n; ++i) {                                              \
      mem_name.push_back({});                                                  \
      std::memcpy(&mem_name.back(), data + offset, bsize);                     \
      offset += bsize;                                                         \
    }                                                                          \
  } while (0)

    // read ADC
    if (!header.sections[1].llNumEntries) {
      throw std::runtime_error("No ADC section found");
    }
    DO_READ(1, adc, ADC);

    // read DAC
    if (header.sections[2].llNumEntries) {
      DO_READ(2, dac, DAC);
    }
    // read Epoch
    if (header.sections[3].llNumEntries) {
      DO_READ(3, epoch, Epoch);
    }
    // skip ADCPerDAC
    // read EpochPerDAC
    if (header.sections[5].llNumEntries) {
      DO_READ(5, epochPerDac, EpochPerDAC);
    }
    // read UserList
    if (header.sections[6].llNumEntries) {
      DO_READ(6, userList, UserList);
    }
    // read StatsRegion
    if (header.sections[7].llNumEntries) {
      DO_READ(7, statsRegion, StatsRegion);
    }
    // read Math
    if (header.sections[8].llNumEntries) {
      DO_READ(8, math, Math);
    }
    // read Strings
    offset = get_offset(header.sections[9]);
    if (header.sections[9].llNumEntries > 0) {
      auto begin = data + offset + pack::ABF2StringsOffset;
      auto size = header.sections[9].uBytes;
      std::string all(begin, size);
      // split by null terminator
      std::istringstream iss(all);
      n = header.sections[9].llNumEntries;
      for (size_t i = 0; i < n; ++i) {
        std::string s;
        if (std::getline(iss, s, '\0'))
          strings.push_back(std::move(s));
      }
    }
    // skip Data section
    // read Tag
    if (header.sections[11].llNumEntries) {
      DO_READ(11, tag, Tag);
    }
    // skip Scope section
    // skip Delta section
    // skip VoiceTag section
    // read SynchArray
    if (header.sections[15].llNumEntries) {
      DO_READ(15, synchArray, SynchArray);
    }
    // skip Annotation section
    // skip Stats section

#undef DO_READ
  }
};

} // namespace abf2
