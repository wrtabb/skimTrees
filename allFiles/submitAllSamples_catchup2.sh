#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0001"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    WJetsToLNu_ext
    TT_Backup
)

sampleLocation=(
    WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_amcatnlo_ext      # WJetsToLNu_ext
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/crab_ttbarBackup                              # TT_Backup
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
   14 # WJetsToLNu_ext
    6 # TT_Backup
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # WJetsToLNu_ext
    true # TT_Backup
)

for index in ${!sampleLocation[*]}; do 
    echo "Submit jobs for sample ${sampleShortName[$index]} at ${sampleLocation[$index]} with numberOfSections=${numberOfSections[$index]} sections and ${preserveEventCount[$index]}"
    condor_submit \
	sampleShortName=${sampleShortName[$index]} \
	ntuplesGeneralLocation=${ntuplesGeneralLocation} \
	sampleLocation=${sampleLocation[$index]} \
	skimTag=${skimTag} \
	numberOfSections=${numberOfSections[$index]} \
	preserveEventCount=${preserveEventCount[$index]}  \
	skimControlScript.condor
done
