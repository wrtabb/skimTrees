#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    QCD_Pt-30to50_EMEnriched_ext1
    QCD_Pt-50to80_EMEnriched
    QCD_Pt-50to80_EMEnriched_ext1
    QCD_Pt-80to120_EMEnriched
    QCD_Pt-80to120_EMEnriched_ext1
)

sampleLocation=(
    QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt30to50_ext1  # QCD_Pt-30to50_EMEnriched_ext1
    QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt50to80       # QCD_Pt-50to80_EMEnriched
    QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt50to80_ext1  # QCD_Pt-50to80_EMEnriched_ext1
    QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt80to120     # QCD_Pt-80to120_EMEnriched
    QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt80to120_ext1 # QCD_Pt-80to120_EMEnriched_ext1
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    1 # QCD_Pt-30to50_EMEnriched_ext1 total files: 58
    1 # QCD_Pt-50to80_EMEnriched total files: 186
    1 # QCD_Pt-50to80_EMEnriched_ext1 total files: 148
    1 # QCD_Pt-80to120_EMEnriched total files: 271
    1 # QCD_Pt-80to120_EMEnriched_ext1 total files: 279
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # QCD_Pt-30to50_EMEnriched_ext1
    true # QCD_Pt-50to80_EMEnriched
    true # QCD_Pt-50to80_EMEnriched_ext1
    true # QCD_Pt-80to120_EMEnriched
    true # QCD_Pt-80to120_EMEnriched_ext1
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
