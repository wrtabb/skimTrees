#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    WJetsToLNu
    QCD_Pt-20to30_EMEnriched
    QCD_Pt-30to50_EMEnriched
)

sampleLocation=(
    WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_amcatnlo           # WJetsToLNu
    QCD_Pt-20to30_EMEnriched_TuneCUETP8M1_13TeV_pythia8                                   # QCD_Pt-20to30_EMEnriched
    QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt30to50       # QCD_Pt-30to50_EMEnriched
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    2 # WJetsToLNu total files: 149
    2 # QCD_Pt-20to30_EMEnriched total files: 112
    1 # QCD_Pt-30to50_EMEnriched total files: 34
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # WJetsToLNu
    true # QCD_Pt-20to30_EMEnriched
    true # QCD_Pt-30to50_EMEnriched
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
