#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6"
skimTag="MuMu"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    ZToEE_M2300to3500
    ttbar_truncated_M0To700
    ttbar_M700to1000
    WJetsToLNu_ext
    WJetsToLNu_ext2v5
    SingleMuon_Run2016B
    SingleMuon_Run2016C
    SingleMuon_Run2016E
    DoubleEG_RunB
    DoubleEG_RunG
    DoubleEG_RunHver2
)

sampleLocation=(
    ZToEE_M2300to3500
    ttbar_truncated_M0To700
    ttbar_M700to1000
    WJetsToLNu_amcatnlo_ext
    WJetsToLNu_amcatnlo_ext2v5
    SingleMuon_Run2016B
    SingleMuon_Run2016C
    SingleMuon_Run2016E
    crab_DoubleEG_RunB
    crab_DoubleEG_RunG
    crab_DoubleEG_RunHver2
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
# roughly 1 section per 100 files rounded up
numberOfSections=(
   1 # ZToEE_M2300to3500 2
   10 # ttbar_truncated_M0To700 980
   8 # ttbar_M700to1000 745
   27 # WJetsToLNu_ext 2670
   36 # WJetsToLNu_ext2v5 3568
   14 # SingleMuon_Run2016B 1317
   5 # SingleMuon_Run2016C 435
   7 # SingleMuon_Run2016E 620
   14 # DoubleEG_RunB 1318
   11 # DoubleEG_RunG 1068
   12 # DoubleEG_RunHver2 1156
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
   true # ZToEE_M2300to3500
   true # ttbar_truncated_M0To700
   true # ttbar_M700to1000
   true # WJetsToLNu_ext
   true # WJetsToLNu_ext2v5
   false # SingleMuon_Run2016B
   false # SingleMuon_Run2016C
   false # SingleMuon_Run2016E
   false # DoubleEG_RunB
   false # DoubleEG_RunG
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
