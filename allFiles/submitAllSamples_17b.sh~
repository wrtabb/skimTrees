#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    TT_Backup
    TT_truncated_M0To700
    TT_Backup_truncated_M0To700
    WJetsToLNu_ext
)

sampleLocation=(
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/crab_ttbarBackup                               # TT_Backup
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_truncated_M0To700/crab_ttbar        # TT_truncated_M0To700
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_truncated_M0To700/crab_ttbarBackup        # TT_Backup_truncated_M0To700
    WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_amcatnlo_ext       # WJetsToLNu_ext
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    1 # TT_Backup total files: 595
    1 # TT_truncated_M0To700 total files 492
    1 # TT_truncated_M0To700_Backup total files 595
    1 # WJetsToLNu_ext total files: 1336
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # TT_Backup
    true # TT_truncated_M0To700
    true # TT_Backup_truncated_M0To700
    true # WJetsToLNu_ext
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
