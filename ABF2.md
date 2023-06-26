# ABF2 file format

## Overview

ABF2 file is composed of several sections:

* Header, contains general file information.

* Protocol, contains protocol information.

* ADC, contains information for each ADC channel.

* DAC, contains information for each DAC channel.

* Epoch, contains overall epoch settings.

* ADCPerDAC, this section is currently unkown.

* EpochPerDAC, contains epoch settings for each DAC channel.

* Strings, strings information are all store in this section and referenced by other sections using string id.

* Data, actual recorded data is stored in this section.

* Synch array, this section describe the lenth/dimension of data.

* There are some other sections that are mostly Axon application specific and is not parsed, which include:
user list, stats region, math, tag, scope config, delta, voice tag, annotation, stats

## Overall file layout

| 512 bytes header and section info | 512 byte protocol | ... various meta 512 bytes blocks depending on section info described in header | ... Strings ... | ... Data ... | ... Other misc info |

## Header

| Header   | Section info | Section info | ... | Section info |
|----------|--------------|--------------|-----|--------------|
| 76 bytes | 16 bytes     | 16 bytes     | ... | 16 bytes     |

* For actual header structure, please see comments on [header definition](/src/abf2/meta.hpp#L14). Most field names are self explanatory.

## Section info

Immediately following header is 18 section info records. The content of each section info is described as follows:

| Name         | Type   | Description                                                                                        |
|--------------|--------|----------------------------------------------------------------------------------------------------|
| uBlockIndex  | uint32 | Location of the section on file. Each block is 512 bytes so the actual location is uBlockIndex*512 |
| uBytes       | uint32 | Could be total bytes or bytes per entry depending on the section                                   |
| llNumEntries | int64  | Number of entries in the section                                                                   |

The order of these 18 records are fixed: Protocol, ADC, DAC, Epoch, ADCPerDAC, EpochPerDAC, UserList, StatsRegion, Math, Strings, Data,
Tag, Scope, Delta, VoiceTag, SynchArray, Annotation, Stats. Some section may not exist, in this case llNumEntries should be zero.

## Protocol section

This section contains the protocol. Please refer to [protocol definition](/src/abf2/meta.hpp#L46) for details, most field names are self
explanatory. There are some significant fields need to be elaborated here:

* nOperationMode: operation mode. Possible values are:

  * 1: Event-driven variable length mode

  * 2: Event-driven fixed length mode

  * 3: Gap-free mode

  * 4: High speed oscilloscope mode

  * 5: Waveform fixed length mode

* fADCRange, lADCResolution: see [Data section](#data-section) below for details.

* fSynchTimeUnit: see [Synch array section](#synch-array-section) below for details.

* fADCSequenceInterval: sampling inverval in us. See [Synch array section](#synch-array-section) below for details.

## Data section

Data section is simply a sequence of data points. The of data points is determined by uBytes in the corresponding section info, and number
of data points is determined by llNumEntries.

Data can be stored in int16 or float32 format. This can be figured out by nDataFormat in header (if 0, int16 format is used), or by 11th
section info entry (if uByte 2, int16 format is used, if uByte 4, float32 format is used). When using int16 format, proper scaling and
offset must be applied using following method:

``` R
# Specified in protocol
resolution = fADCRange / lADCResolution
# Specified per ADC channel
if (nTelegraphEnable)
  scale = resolution / (fInstrumentScaleFactor * fSignalGain * fADCProgrammableGain)
else
  scale = resolution / (fInstrumentScaleFactor * fSignalGain * fADCProgrammableGain * fTelegraphAdditGain)
# Specified per ADC channel
offset = fInstrumentOffset - fSignalOffset

actual_data = raw_int16_data * scale + offset
```

When loading data to memory, proper permutation may be desired. On disk, data is stored by order of channel, tick, sweep i.e the
natual order data is read from device. abf2load permutate data to the order of sweep, tick, channel so that every sweep per channel
is contiguous in memory, allowing more efficient access.

## Strings section

In ABF2, all string data are stored in a single section and are referred to this section by a string id. Every string is null terminated.
This section mostly stores some pClamp application specific data which are not very useful in our context, but it also stores the units of
ADC and DAC channels e.g. ```lADCUnitsIndex``` in ADC section and ```lDACChannelUnitsIndex``` in DAC section. Please notice that the index
is 0 based.

## Synch array section

Synch array contains information of data length. Every synch array entry describes a sweep or an event (in variable length mode). In fixed
length mode, lLength should be same across all entries. In gap free mode, this section is not used (it behaves as if there is only 1 sweep).

| Name    | Type  | Description                     |
|---------|-------|---------------------------------|
| lStart  | int32 | Start of this sweep/event       |
| lLength | int32 | Length of this sweep/event      |

Weirdly, lStart is not simple offset but an arbitrary unit, determined by fSynchTimeUnit and fADCSequenceInterval in
protocol. Here is the conversion rule:

``` R
if (fSynchTimeUnit == 1)
  actual_start_offset = lStart / fADCSequenceInterval
else
  actual_start_offset = lStart / fSynchTimeUnit
```

## Other sections

Please refer to [section definitions](src/abf2/meta.hpp#L123) for details. Field naming convention is Hungarian notation and most are pretty
self explanatory. Many sections are pClamp application specific and may not be used, some are not parsed at all due to lack of structure
knowledge.

## Loading ABF2 files

Loading ABF2 files are mostly simple [memcpy operations](src/abf2/meta.hpp#394) since most information is stored 1 to 1 corresponding to in
memory structures with a couple exceptions:

* Strings section: this section has a magic offset of 44 bytes, and entries are [splitted](src/abf2/meta.hpp#L439) by null terminator ```\0```.
 uBytes here indicates total number of bytes.

* Data section: as discussed above, permutation may be desired. To reduce memory copy, [memory mapping](src/abf2/loader.hpp#L43) file may be
 desired.
