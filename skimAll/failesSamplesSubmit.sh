#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6"
skimTag="EE"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    ZToEE_M200to400
    WJetsToLNu_ext
    SingleMuon_Run2016E
    SingleMuon_Run2016Hver2
    DoubleEG_RunC
    DoubleEG_RunF
    DoubleEG_RunHver2
)

sampleLocation=(
    ZToEE_M200to400
    WJetsToLNu_amcatnlo_ext
    SingleMuon_Run2016E
    SingleMuon_Run2016Hver2
    crab_DoubleEG_RunC
    crab_DoubleEG_RunF
    crab_DoubleEG_RunHver2
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
# roughly 1 section per 100 files rounded up
numberOfSections=(
   1 # ZToEE_M200to400 2
   27 # WJetsToLNu_ext 2670
   7 # SingleMuon_Run2016E 620
   12 # SingleMuon_Run2016Hver2 1156
   5 # DoubleEG_RunC 435
   5 # DoubleEG_RunF 452
   12 # DoubleEG_RunHver2 1156
 )

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
   true # ZToEE_M200to400
   true # WJetsToLNu_ext
   false # SingleMuon_Run2016E
   false # SingleMuon_Run2016Hver2
   false # DoubleEG_RunC
   false # DoubleEG_RunF
   false # DoubleEG_RunHver2
)

for index in ${!sampleLocation[*]}; do 
    condor_submit \
	sampleShortName=${sampleShortName[$index]} \
	ntuplesGeneralLocation=${ntuplesGeneralLocation} \
	sampleLocation=${sampleLocation[$index]} \
	skimTag=${skimTag} \
	numberOfSections=${numberOfSections[$index]} \
	preserveEventCount=${preserveEventCount[$index]}  \
	skimControlScript.condor
done
