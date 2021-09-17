#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6"
skimTag="EE"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    WJetsToLNu_ext2v5
    DoubleEG_RunB
    DoubleEG_RunC
    DoubleEG_RunD
    DoubleEG_RunE
    DoubleEG_RunF
    DoubleEG_RunG
    DoubleEG_RunHver2
    DoubleEG_RunHver3
)

sampleLocation=(
    WJetsToLNu_amcatnlo_ext2v5
    crab_DoubleEG_RunB
    crab_DoubleEG_RunC
    crab_DoubleEG_RunD
    crab_DoubleEG_RunE
    crab_DoubleEG_RunF
    crab_DoubleEG_RunG
    crab_DoubleEG_RunHver2
    crab_DoubleEG_RunHver3
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
# roughly 1 section per 100 files rounded up
numberOfSections=(
   36 # WJetsToLNu_ext2v5 3568
   14 # DoubleEG_RunB 1318
   5 # DoubleEG_RunC 435
   8 # DoubleEG_RunD 729
   7 # DoubleEG_RunE 620
   5 # DoubleEG_RunF 452
   11 # DoubleEG_RunG 1068
   12 # DoubleEG_RunHver2 1156
   1 # DoubleEG_RunHver3 31
 )

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
   true # WJetsToLNu_ext2v5
   false # DoubleEG_RunB
   false # DoubleEG_RunC
   false # DoubleEG_RunD
   false # DoubleEG_RunE
   false # DoubleEG_RunF
   false # DoubleEG_RunG
   false # DoubleEG_RunHver2
   false # DoubleEG_RunHver3
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
