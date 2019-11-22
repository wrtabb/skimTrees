#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"

sampleShortName=(
    DYJetsToLL
    TT
    TT_Backup
)

sampleName=(
    DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 # DYJetsToLL
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8                  # TT
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8                  # TT_Backup
)

sampleSubdir=(
    ./                # DYJetsToLL
    crab_ttbar        # TT
    crab_ttbarBackup  # TT_Backup
)

sampleSuffixOut=(
    _truncated_M50To100 # DYJetsToLL
    _truncated_M0To700  # TT
    _truncated_M0To700  # TT_Backup
)

sampleType=(
    SAMPLE_DYJetsToLL # DYJetsToLL
    SAMPLE_TT         # TT
    SAMPLE_TT         # TT_Backup
)

numberOfSections=(
    8 # DYJetsToLL total number of files 726
    5 # TT total number of files 491
    6 # TT_Backup number of files 595
)

for index in ${!sampleShortName[*]}; do 
    echo "Submit jobs for sample ${sampleShortName[$index]} at ${sampleName[$index]}/${sampleSubdir[$index]} with numberOfSections=${numberOfSections[$index]} sections"
    condor_submit \
	ntuplesGeneralLocation=${ntuplesGeneralLocation} \
	sampleShortName=${sampleShortName[$index]} \
	sampleName=${sampleName[$index]} \
	sampleSubdir=${sampleSubdir[$index]} \
	sampleSuffixOut=${sampleSuffixOut[$index]} \
	sampleType=${sampleType[$index]} \
	numberOfSections=${numberOfSections[$index]} \
	filterGenMassControlScript.condor
done
