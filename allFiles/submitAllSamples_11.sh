#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    DYJetsToLL_M-10to50_v1
    DYJetsToLL_M-10to50_v2
    DYJetsToLL_M-10to50_ext1v1
)

sampleLocation=(
    DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M10to50_v1     # DYJetsToLL_M-10to50_v1
    DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M10to50_v2     # DYJetsToLL_M-10to50_v2
    DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M10to50_ext1v1 # DYJetsToLL_M-10to50_ext1v1
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    2 # DYJetsToLL_M-10to50_v1 total files: 125
    4 # DYJetsToLL_M-10to50_v2 total files: 389
    3 # DYJetsToLL_M-10to50_ext1v1 total files: 240
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # DYJetsToLL_M-10to50_v1
    true # DYJetsToLL_M-10to50_v2
    true # DYJetsToLL_M-10to50_ext1v1
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
