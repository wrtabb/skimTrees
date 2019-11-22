#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    QCD_Pt-120to170_EMEnriched
    QCD_Pt-120to170_EMEnriched_ext1
    QCD_Pt-300toInf
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
    QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt120to170   # QCD_Pt-120to170_EMEnriched
    QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt120to170_ext1 # QCD_Pt-120to170_EMEnriched_ext1
    QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8                                 # QCD_Pt-300toInf
    DoubleEG/crab_DoubleEG_RunB                                                           # DoubleEG_RunB
    DoubleEG/crab_DoubleEG_RunC                                                           # DoubleEG_RunC
    DoubleEG/crab_DoubleEG_RunD                                                           # DoubleEG_RunD
    DoubleEG/crab_DoubleEG_RunE                                                           # DoubleEG_RunE
    DoubleEG/crab_DoubleEG_RunF                                                           # DoubleEG_RunF
    DoubleEG/crab_DoubleEG_RunG                                                           # DoubleEG_RunG
    DoubleEG/crab_DoubleEG_RunHver2                                                       # DoubleEG_RunHver2
    DoubleEG/crab_DoubleEG_RunHver3                                                       # DoubleEG_RunHver3
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    1 # QCD_Pt-120to170_EMEnriched total files: 316
    1 # QCD_Pt-120to170_EMEnriched_ext1 total files: 306
    1 # QCD_Pt-300toInf total files: 93
    1 # DoubleEG_RunB total files 1318
    1 # DoubleEG_RunC total files 435
    1 # DoubleEG_RunD total files 729
    1 # DoubleEG_RunE total files 620
    1 # DoubleEG_RunF total files 452
    1 # DoubleEG_RunG total files 1068
    1 # DoubleEG_RunHver2 total files 1156
    1 # DoubleEG_RunHver3 total files 31
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # QCD_Pt-120to170_EMEnriched
    true # QCD_Pt-120to170_EMEnriched_ext1
    true # QCD_Pt-300toInf
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
