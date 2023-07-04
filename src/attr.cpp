#include "abf2/meta.hpp"
#include <Rcpp.h>

Rcpp::List attr_Header(abf2::FileMeta const &meta) {
  Rcpp::List result;
  result("FileSignature") = std::string(meta.header.header.fFileSignature, 4);
  result("FileVersionNumber") =
      static_cast<double>(meta.header.header.fFileVersionNumber1) * 0.001 +
      static_cast<double>(meta.header.header.fFileVersionNumber2) * 0.01 +
      static_cast<double>(meta.header.header.fFileVersionNumber3) * 0.1 +
      static_cast<double>(meta.header.header.fFileVersionNumber4);
  result("FileInfoSize") = meta.header.header.uFileInfoSize;
  result("ActualEpisodes") = meta.header.header.lActualEpisodes;
  result("FileStartDate") = meta.header.header.uFileStartDate;
  result("FileStartTimeMS") = meta.header.header.uFileStartTimeMS;
  result("StopwatchTime") = meta.header.header.uStopwatchTime;
  result("FileType") = meta.header.header.nFileType;
  result("DataFormat") = meta.header.header.nDataFormat;
  result("SimultaneousScan") = meta.header.header.nSimultaneousScan;
  result("CRCEnable") = meta.header.header.nCRCEnable;
  result("FileCRC") = meta.header.header.uFileCRC;
  result("FileGUID1") = meta.header.header.FileGUID1;
  result("FileGUID2") = meta.header.header.FileGUID2;
  result("CreatorVersion") = meta.header.header.uCreatorVersion;
  result("CreatorNameIndex") = meta.header.header.uCreatorNameIndex;
  result("ModifierVersion") = meta.header.header.uModifierVersion;
  result("ModifierNameIndex") = meta.header.header.uModifierNameIndex;
  result("ProtocolPathIndex") = meta.header.header.uProtocolPathIndex;

  return result;
}

Rcpp::List attr_Protocol(abf2::FileMeta const &meta) {
  Rcpp::List result;
  result("OperationMode") = meta.protocol.nOperationMode;
  result("ADCSequenceInterval") = meta.protocol.fADCSequenceInterval;
  result("EnableFileCompression") = int(meta.protocol.bEnableFileCompression);
  result("FileCompressionRatio") = meta.protocol.uFileCompressionRatio;
  result("SynchTimeUnit") = meta.protocol.fSynchTimeUnit;
  result("SecondsPerRun") = meta.protocol.fSecondsPerRun;
  result("NumSamplesPerEpisode") = meta.protocol.lNumSamplesPerEpisode;
  result("PreTriggerSamples") = meta.protocol.lPreTriggerSamples;
  result("EpisodesPerRun") = meta.protocol.lEpisodesPerRun;
  result("RunsPerTrial") = meta.protocol.lRunsPerTrial;
  result("NumberOfTrials") = meta.protocol.lNumberOfTrials;
  result("AveragingMode") = meta.protocol.nAveragingMode;
  result("UndoRunCount") = meta.protocol.nUndoRunCount;
  result("FirstEpisodeInRun") = meta.protocol.nFirstEpisodeInRun;
  result("TriggerThreshold") = meta.protocol.fTriggerThreshold;
  result("TriggerSource") = meta.protocol.nTriggerSource;
  result("TriggerAction") = meta.protocol.nTriggerAction;
  result("TriggerPolarity") = meta.protocol.nTriggerPolarity;
  result("ScopeOutputInterval") = meta.protocol.fScopeOutputInterval;
  result("EpisodeStartToStart") = meta.protocol.fEpisodeStartToStart;
  result("RunStartToStart") = meta.protocol.fRunStartToStart;
  result("AverageCount") = meta.protocol.lAverageCount;
  result("TrialStartToStart") = meta.protocol.fTrialStartToStart;
  result("AutoTriggerStrategy") = meta.protocol.nAutoTriggerStrategy;
  result("FirstRunDelayS") = meta.protocol.fFirstRunDelayS;
  result("ChannelStatsStrategy") = meta.protocol.nChannelStatsStrategy;
  result("SamplesPerTrace") = meta.protocol.lSamplesPerTrace;
  result("StartDisplayNum") = meta.protocol.lStartDisplayNum;
  result("FinishDisplayNum") = meta.protocol.lFinishDisplayNum;
  result("ShowPNRawData") = meta.protocol.nShowPNRawData;
  result("StatisticsPeriod") = meta.protocol.fStatisticsPeriod;
  result("StatisticsMeasurements") = meta.protocol.lStatisticsMeasurements;
  result("StatisticsSaveStrategy") = meta.protocol.nStatisticsSaveStrategy;
  result("ADCRange") = meta.protocol.fADCRange;
  result("DACRange") = meta.protocol.fDACRange;
  result("ADCResolution") = meta.protocol.lADCResolution;
  result("DACResolution") = meta.protocol.lDACResolution;
  result("ExperimentType") = meta.protocol.nExperimentType;
  result("ManualInfoStrategy") = meta.protocol.nManualInfoStrategy;
  result("CommentsEnable") = meta.protocol.nCommentsEnable;
  result("FileCommentIndex") = meta.protocol.lFileCommentIndex;
  result("AutoAnalyseEnable") = meta.protocol.nAutoAnalyseEnable;
  result("SignalType") = meta.protocol.nSignalType;
  result("DigitalEnable") = meta.protocol.nDigitalEnable;
  result("ActiveDACChannel") = meta.protocol.nActiveDACChannel;
  result("DigitalHolding") = meta.protocol.nDigitalHolding;
  result("DigitalInterEpisode") = meta.protocol.nDigitalInterEpisode;
  result("DigitalDACChannel") = meta.protocol.nDigitalDACChannel;
  result("DigitalTrainActiveLogic") = meta.protocol.nDigitalTrainActiveLogic;
  result("StatsEnable") = meta.protocol.nStatsEnable;
  result("StatisticsClearStrategy") = meta.protocol.nStatisticsClearStrategy;
  result("LevelHysteresis") = meta.protocol.nLevelHysteresis;
  result("TimeHysteresis") = meta.protocol.lTimeHysteresis;
  result("AllowExternalTags") = meta.protocol.nAllowExternalTags;
  result("AverageAlgorithm") = meta.protocol.nAverageAlgorithm;
  result("AverageWeighting") = meta.protocol.fAverageWeighting;
  result("UndoPromptStrategy") = meta.protocol.nUndoPromptStrategy;
  result("TrialTriggerSource") = meta.protocol.nTrialTriggerSource;
  result("StatisticsDisplayStrategy") =
      meta.protocol.nStatisticsDisplayStrategy;
  result("ExternalTagType") = meta.protocol.nExternalTagType;
  result("ScopeTriggerOut") = meta.protocol.nScopeTriggerOut;
  result("LTPType") = meta.protocol.nLTPType;
  result("AlternateDACOutputState") = meta.protocol.nAlternateDACOutputState;
  result("AlternateDigitalOutputState") =
      meta.protocol.nAlternateDigitalOutputState;
  result("CellID1") = meta.protocol.fCellID1;
  result("CellID2") = meta.protocol.fCellID2;
  result("CellID3") = meta.protocol.fCellID3;
  result("DigitizerADCs") = meta.protocol.nDigitizerADCs;
  result("DigitizerDACs") = meta.protocol.nDigitizerDACs;
  result("DigitizerTotalDigitalOuts") =
      meta.protocol.nDigitizerTotalDigitalOuts;
  result("DigitizerSynchDigitalOuts") =
      meta.protocol.nDigitizerSynchDigitalOuts;
  result("DigitizerType") = meta.protocol.nDigitizerType;
  return result;
}

// TODO: set data.frame

Rcpp::List attr_ADC(abf2::FileMeta const &meta) {
  struct vect_t {
    std::vector<int16_t> ADCNum;
    std::vector<int16_t> TelegraphEnable;
    std::vector<int16_t> TelegraphInstrument;
    std::vector<float> TelegraphAdditGain;
    std::vector<float> TelegraphFilter;
    std::vector<float> TelegraphMembraneCap;
    std::vector<int16_t> TelegraphMode;
    std::vector<float> TelegraphAccessResistance;
    std::vector<int16_t> ADCPtoLChannelMap;
    std::vector<int16_t> ADCSamplingSeq;
    std::vector<float> ADCProgrammableGain;
    std::vector<float> ADCDisplayAmplification;
    std::vector<float> ADCDisplayOffset;
    std::vector<float> InstrumentScaleFactor;
    std::vector<float> InstrumentOffset;
    std::vector<float> SignalGain;
    std::vector<float> SignalOffset;
    std::vector<float> SignalLowpassFilter;
    std::vector<float> SignalHighpassFilter;
    std::vector<int16_t> LowpassFilterType;
    std::vector<int16_t> HighpassFilterType;
    std::vector<float> PostProcessLowpassFilter;
    std::vector<int16_t> PostProcessLowpassFilterType;
    std::vector<bool> EnabledDuringPN;
    std::vector<int16_t> StatsChannelPolarity;
    std::vector<int32_t> ADCChannelNameIndex;
    std::vector<int32_t> ADCUnitsIndex;
  };
  vect_t v;
  for (auto const &e : meta.adc) {
    v.ADCNum.push_back(e.nADCNum);
    v.TelegraphEnable.push_back(e.nTelegraphEnable);
    v.TelegraphInstrument.push_back(e.nTelegraphInstrument);
    v.TelegraphAdditGain.push_back(e.fTelegraphAdditGain);
    v.TelegraphFilter.push_back(e.fTelegraphFilter);
    v.TelegraphMembraneCap.push_back(e.fTelegraphMembraneCap);
    v.TelegraphMode.push_back(e.nTelegraphMode);
    v.TelegraphAccessResistance.push_back(e.fTelegraphAccessResistance);
    v.ADCPtoLChannelMap.push_back(e.nADCPtoLChannelMap);
    v.ADCSamplingSeq.push_back(e.nADCSamplingSeq);
    v.ADCProgrammableGain.push_back(e.fADCProgrammableGain);
    v.ADCDisplayAmplification.push_back(e.fADCDisplayAmplification);
    v.ADCDisplayOffset.push_back(e.fADCDisplayOffset);
    v.InstrumentScaleFactor.push_back(e.fInstrumentScaleFactor);
    v.InstrumentOffset.push_back(e.fInstrumentOffset);
    v.SignalGain.push_back(e.fSignalGain);
    v.SignalOffset.push_back(e.fSignalOffset);
    v.SignalLowpassFilter.push_back(e.fSignalLowpassFilter);
    v.SignalHighpassFilter.push_back(e.fSignalHighpassFilter);
    v.LowpassFilterType.push_back(e.nLowpassFilterType);
    v.HighpassFilterType.push_back(e.nHighpassFilterType);
    v.PostProcessLowpassFilter.push_back(e.fPostProcessLowpassFilter);
    v.PostProcessLowpassFilterType.push_back(e.nPostProcessLowpassFilterType);
    v.EnabledDuringPN.push_back(e.bEnabledDuringPN);
    v.StatsChannelPolarity.push_back(e.nStatsChannelPolarity);
    v.ADCChannelNameIndex.push_back(e.lADCChannelNameIndex);
    v.ADCUnitsIndex.push_back(e.lADCUnitsIndex);
  }
  Rcpp::List result;
  result("ADCNum") = v.ADCNum;
  result("TelegraphEnable") = v.TelegraphEnable;
  result("TelegraphInstrument") = v.TelegraphInstrument;
  result("TelegraphAdditGain") = v.TelegraphAdditGain;
  result("TelegraphFilter") = v.TelegraphFilter;
  result("TelegraphMembraneCap") = v.TelegraphMembraneCap;
  result("TelegraphMode") = v.TelegraphMode;
  result("TelegraphAccessResistance") = v.TelegraphAccessResistance;
  result("ADCPtoLChannelMap") = v.ADCPtoLChannelMap;
  result("ADCSamplingSeq") = v.ADCSamplingSeq;
  result("ADCProgrammableGain") = v.ADCProgrammableGain;
  result("ADCDisplayAmplification") = v.ADCDisplayAmplification;
  result("ADCDisplayOffset") = v.ADCDisplayOffset;
  result("InstrumentScaleFactor") = v.InstrumentScaleFactor;
  result("InstrumentOffset") = v.InstrumentOffset;
  result("SignalGain") = v.SignalGain;
  result("SignalOffset") = v.SignalOffset;
  result("SignalLowpassFilter") = v.SignalLowpassFilter;
  result("SignalHighpassFilter") = v.SignalHighpassFilter;
  result("LowpassFilterType") = v.LowpassFilterType;
  result("HighpassFilterType") = v.HighpassFilterType;
  result("PostProcessLowpassFilter") = v.PostProcessLowpassFilter;
  result("PostProcessLowpassFilterType") = v.PostProcessLowpassFilterType;
  result("EnabledDuringPN") = v.EnabledDuringPN;
  result("StatsChannelPolarity") = v.StatsChannelPolarity;
  result("ADCChannelNameIndex") = v.ADCChannelNameIndex;
  result("ADCUnitsIndex") = v.ADCUnitsIndex;
  return result;
}

Rcpp::List attr_DAC(abf2::FileMeta const &meta) {
  struct vect_t {
    std::vector<int16_t> DACNum;
    std::vector<int16_t> TelegraphDACScaleFactorEnable;
    std::vector<float> InstrumentHoldingLevel;
    std::vector<float> DACScaleFactor;
    std::vector<float> DACHoldingLevel;
    std::vector<float> DACCalibrationFactor;
    std::vector<float> DACCalibrationOffset;
    std::vector<int32_t> DACChannelNameIndex;
    std::vector<int32_t> DACChannelUnitsIndex;
    std::vector<int32_t> DACFilePtr;
    std::vector<int32_t> DACFileNumEpisodes;
    std::vector<int16_t> WaveformEnable;
    std::vector<int16_t> WaveformSource;
    std::vector<int16_t> InterEpisodeLevel;
    std::vector<float> DACFileScale;
    std::vector<float> DACFileOffset;
    std::vector<int32_t> DACFileEpisodeNum;
    std::vector<int16_t> DACFileADCNum;
    std::vector<int16_t> ConditEnable;
    std::vector<int32_t> ConditNumPulses;
    std::vector<float> BaselineDuration;
    std::vector<float> BaselineLevel;
    std::vector<float> StepDuration;
    std::vector<float> StepLevel;
    std::vector<float> PostTrainPeriod;
    std::vector<float> PostTrainLevel;
    std::vector<int16_t> MembTestEnable;
    std::vector<int16_t> LeakSubtractType;
    std::vector<int16_t> PNPolarity;
    std::vector<float> PNHoldingLevel;
    std::vector<int16_t> PNNumADCChannels;
    std::vector<int16_t> PNPosition;
    std::vector<int16_t> PNNumPulses;
    std::vector<float> PNSettlingTime;
    std::vector<float> PNInterpulse;
    std::vector<int16_t> LTPUsageOfDAC;
    std::vector<int16_t> LTPPresynapticPulses;
    std::vector<int32_t> DACFilePathIndex;
    std::vector<float> MembTestPreSettlingTimeMS;
    std::vector<float> MembTestPostSettlingTimeMS;
    std::vector<int16_t> LeakSubtractADCIndex;
  } v;
  for (auto const &e : meta.dac) {
    v.DACNum.push_back(e.nDACNum);
    v.TelegraphDACScaleFactorEnable.push_back(e.nTelegraphDACScaleFactorEnable);
    v.InstrumentHoldingLevel.push_back(e.fInstrumentHoldingLevel);
    v.DACScaleFactor.push_back(e.fDACScaleFactor);
    v.DACHoldingLevel.push_back(e.fDACHoldingLevel);
    v.DACCalibrationFactor.push_back(e.fDACCalibrationFactor);
    v.DACCalibrationOffset.push_back(e.fDACCalibrationOffset);
    v.DACChannelNameIndex.push_back(e.lDACChannelNameIndex);
    v.DACChannelUnitsIndex.push_back(e.lDACChannelUnitsIndex);
    v.DACFilePtr.push_back(e.lDACFilePtr);
    v.DACFileNumEpisodes.push_back(e.lDACFileNumEpisodes);
    v.WaveformEnable.push_back(e.nWaveformEnable);
    v.WaveformSource.push_back(e.nWaveformSource);
    v.InterEpisodeLevel.push_back(e.nInterEpisodeLevel);
    v.DACFileScale.push_back(e.fDACFileScale);
    v.DACFileOffset.push_back(e.fDACFileOffset);
    v.DACFileEpisodeNum.push_back(e.lDACFileEpisodeNum);
    v.DACFileADCNum.push_back(e.nDACFileADCNum);
    v.ConditEnable.push_back(e.nConditEnable);
    v.ConditNumPulses.push_back(e.lConditNumPulses);
    v.BaselineDuration.push_back(e.fBaselineDuration);
    v.BaselineLevel.push_back(e.fBaselineLevel);
    v.StepDuration.push_back(e.fStepDuration);
    v.StepLevel.push_back(e.fStepLevel);
    v.PostTrainPeriod.push_back(e.fPostTrainPeriod);
    v.PostTrainLevel.push_back(e.fPostTrainLevel);
    v.MembTestEnable.push_back(e.nMembTestEnable);
    v.LeakSubtractType.push_back(e.nLeakSubtractType);
    v.PNPolarity.push_back(e.nPNPolarity);
    v.PNHoldingLevel.push_back(e.fPNHoldingLevel);
    v.PNNumADCChannels.push_back(e.nPNNumADCChannels);
    v.PNPosition.push_back(e.nPNPosition);
    v.PNNumPulses.push_back(e.nPNNumPulses);
    v.PNSettlingTime.push_back(e.fPNSettlingTime);
    v.PNInterpulse.push_back(e.fPNInterpulse);
    v.LTPUsageOfDAC.push_back(e.nLTPUsageOfDAC);
    v.LTPPresynapticPulses.push_back(e.nLTPPresynapticPulses);
    v.DACFilePathIndex.push_back(e.lDACFilePathIndex);
    v.MembTestPreSettlingTimeMS.push_back(e.fMembTestPreSettlingTimeMS);
    v.MembTestPostSettlingTimeMS.push_back(e.fMembTestPostSettlingTimeMS);
    v.LeakSubtractADCIndex.push_back(e.nLeakSubtractADCIndex);
  }
  Rcpp::List result;
  result("DACNum") = v.DACNum;
  result("TelegraphDACScaleFactorEnable") = v.TelegraphDACScaleFactorEnable;
  result("InstrumentHoldingLevel") = v.InstrumentHoldingLevel;
  result("DACScaleFactor") = v.DACScaleFactor;
  result("DACHoldingLevel") = v.DACHoldingLevel;
  result("DACCalibrationFactor") = v.DACCalibrationFactor;
  result("DACCalibrationOffset") = v.DACCalibrationOffset;
  result("DACChannelNameIndex") = v.DACChannelNameIndex;
  result("DACChannelUnitsIndex") = v.DACChannelUnitsIndex;
  result("DACFilePtr") = v.DACFilePtr;
  result("DACFileNumEpisodes") = v.DACFileNumEpisodes;
  result("WaveformEnable") = v.WaveformEnable;
  result("WaveformSource") = v.WaveformSource;
  result("InterEpisodeLevel") = v.InterEpisodeLevel;
  result("DACFileScale") = v.DACFileScale;
  result("DACFileOffset") = v.DACFileOffset;
  result("DACFileEpisodeNum") = v.DACFileEpisodeNum;
  result("DACFileADCNum") = v.DACFileADCNum;
  result("ConditEnable") = v.ConditEnable;
  result("ConditNumPulses") = v.ConditNumPulses;
  result("BaselineDuration") = v.BaselineDuration;
  result("BaselineLevel") = v.BaselineLevel;
  result("StepDuration") = v.StepDuration;
  result("StepLevel") = v.StepLevel;
  result("PostTrainPeriod") = v.PostTrainPeriod;
  result("PostTrainLevel") = v.PostTrainLevel;
  result("MembTestEnable") = v.MembTestEnable;
  result("LeakSubtractType") = v.LeakSubtractType;
  result("PNPolarity") = v.PNPolarity;
  result("PNHoldingLevel") = v.PNHoldingLevel;
  result("PNNumADCChannels") = v.PNNumADCChannels;
  result("PNPosition") = v.PNPosition;
  result("PNNumPulses") = v.PNNumPulses;
  result("PNSettlingTime") = v.PNSettlingTime;
  result("PNInterpulse") = v.PNInterpulse;
  result("LTPUsageOfDAC") = v.LTPUsageOfDAC;
  result("LTPPresynapticPulses") = v.LTPPresynapticPulses;
  result("DACFilePathIndex") = v.DACFilePathIndex;
  result("MembTestPreSettlingTimeMS") = v.MembTestPreSettlingTimeMS;
  result("MembTestPostSettlingTimeMS") = v.MembTestPostSettlingTimeMS;
  result("LeakSubtractADCIndex") = v.LeakSubtractADCIndex;
  return result;
}

Rcpp::List attr_Epoch(abf2::FileMeta const &meta) {
  struct vect_t {
    std::vector<int16_t> EpochNum;
    std::vector<int16_t> DigitalValue;
    std::vector<int16_t> DigitalTrainValue;
    std::vector<int16_t> AlternateDigitalValue;
    std::vector<int16_t> AlternateDigitalTrainValue;
    std::vector<bool> EpochCompression;
  } v;
  for (auto const &e : meta.epoch) {
    v.EpochNum.push_back(e.nEpochNum);
    v.DigitalValue.push_back(e.nDigitalValue);
    v.DigitalTrainValue.push_back(e.nDigitalTrainValue);
    v.AlternateDigitalValue.push_back(e.nAlternateDigitalValue);
    v.AlternateDigitalTrainValue.push_back(e.nAlternateDigitalTrainValue);
    v.EpochCompression.push_back(e.bEpochCompression);
  }
  Rcpp::List result;
  result("EpochNum") = v.EpochNum;
  result("DigitalValue") = v.DigitalValue;
  result("DigitalTrainValue") = v.DigitalTrainValue;
  result("AlternateDigitalValue") = v.AlternateDigitalValue;
  result("AlternateDigitalTrainValue") = v.AlternateDigitalTrainValue;
  result("EpochCompression") = v.EpochCompression;
  return result;
}

Rcpp::List attr_EpochPerDAC(abf2::FileMeta const &meta) {
  struct vect_t {
    std::vector<int16_t> EpochNum;
    std::vector<int16_t> DACNum;
    std::vector<int16_t> EpochType;
    std::vector<float> EpochInitLevel;
    std::vector<float> EpochLevelInc;
    std::vector<int32_t> EpochInitDuration;
    std::vector<int32_t> EpochDurationInc;
    std::vector<int32_t> EpochPulsePeriod;
    std::vector<int32_t> EpochPulseWidth;
  } v;
  for (auto const &e : meta.epochPerDac) {
    v.EpochNum.push_back(e.nEpochNum);
    v.DACNum.push_back(e.nDACNum);
    v.EpochType.push_back(e.nEpochType);
    v.EpochInitLevel.push_back(e.fEpochInitLevel);
    v.EpochLevelInc.push_back(e.fEpochLevelInc);
    v.EpochInitDuration.push_back(e.lEpochInitDuration);
    v.EpochDurationInc.push_back(e.lEpochDurationInc);
    v.EpochPulsePeriod.push_back(e.lEpochPulsePeriod);
    v.EpochPulseWidth.push_back(e.lEpochPulseWidth);
  }
  Rcpp::List result;
  result("EpochNum") = v.EpochNum;
  result("DACNum") = v.DACNum;
  result("EpochType") = v.EpochType;
  result("EpochInitLevel") = v.EpochInitLevel;
  result("EpochLevelInc") = v.EpochLevelInc;
  result("EpochInitDuration") = v.EpochInitDuration;
  result("EpochDurationInc") = v.EpochDurationInc;
  result("EpochPulsePeriod") = v.EpochPulsePeriod;
  result("EpochPulseWidth") = v.EpochPulseWidth;
  return result;
}

Rcpp::List attr_UserList(abf2::FileMeta const &meta) {
  struct vect_t {
    std::vector<int16_t> ListNum;
    std::vector<int16_t> ULEnable;
    std::vector<int16_t> ULParamToVary;
    std::vector<int16_t> ULRepeat;
    std::vector<int32_t> ULParamValueListIndex;
  } v;
  for (auto const &e : meta.userList) {
    v.ListNum.push_back(e.nListNum);
    v.ULEnable.push_back(e.nULEnable);
    v.ULParamToVary.push_back(e.nULParamToVary);
    v.ULRepeat.push_back(e.nULRepeat);
    v.ULParamValueListIndex.push_back(e.lULParamValueListIndex);
  }
  Rcpp::List result;
  result("ListNum") = v.ListNum;
  result("ULEnable") = v.ULEnable;
  result("ULParamToVary") = v.ULParamToVary;
  result("ULRepeat") = v.ULRepeat;
  result("ULParamValueListIndex") = v.ULParamValueListIndex;
  return result;
}

Rcpp::List attr_SynchArray(abf2::FileMeta const &meta) {
  struct vect_t {
    std::vector<int32_t> Start;
    std::vector<int32_t> Length;
  } v;
  for (auto const &e : meta.synchArray) {
    v.Start.push_back(e.lStart);
    v.Length.push_back(e.lLength);
  }
  Rcpp::List result;
  result("Start") = v.Start;
  result("Length") = v.Length;
  return result;
}
