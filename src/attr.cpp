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
