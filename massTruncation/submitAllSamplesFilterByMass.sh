#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/"


sampleShortName=(
    DYJetsToLL
    TT
    TT_Backup
)

sampleName=(
    DYLL_M50toInf # DYJetsToLL
    ttbar         # TT
    ttbarBackup   # TT_Backup
)

sampleSubdir=(
    base    # DYJetsToLL
    ./      # TT
    ./      # TT_Backup
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
    15 # DYJetsToLL total number of files 1451
    10 # TT total number of files 980
    12 # TT_Backup number of files 1190
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
