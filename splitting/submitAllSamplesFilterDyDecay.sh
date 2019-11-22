#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/"

sampleShortName=(
    DYJetsToLL_M-10to50_v1
    DYJetsToLL_M-10to50_v2
    DYJetsToLL_M-10to50_ext1v1
    DYJetsToLL_M-50to100
    DYJetsToLL_M-100to200
    DYJetsToLL_M-100to200_ext
    DYJetsToLL_M-200to400
    DYJetsToLL_M-400to500
    DYJetsToLL_M-500to700
    DYJetsToLL_M-700to800
    DYJetsToLL_M-800to1000
    DYJetsToLL_M-1000to1500
    DYJetsToLL_M-1500to2000
    DYJetsToLL_M-2000to3000
)

sampleName=(
    DYLL_M10to50                                 
    DYLL_M10to50                    
    DYLL_M10to50                                
    DYLL_M50toInf_truncated_M50To100
    DYLL_M100to200                          
    DYLL_M200to400                  
    DYLL_M400to500                              
    DYLL_M500to700                         
    DYLL_M700to800                  
    DYLL_M800to1000                 
    DYLL_M1000to1500                
    DYLL_M1500to2000                
    DYLL_M2000to3000                
)

sampleSubdir=(
    v1     # DYLL_M10to50_v1
    v2     # DYLL_M10to50_v2
    ext1v1 # DYLL_M10to50_ext1v1
    base   # DYLL_M50to100
    ./     # DYLL_M100to200
    ./     # DYLL_M200to400
    ./     # DYLL_M400to500
    ./     # DYLL_M500to700
    ./     # DYLL_M700to800
    ./     # DYLL_M800to1000
    ./     # DYLL_M1000to1500
    ./     # DYLL_M1500to2000
    ./     # DYLL_M2000to3000
)

numberOfSections=(
    3  # DYLL_M10to50_v1     files: 236
    8  # DYLL_M10to50_v2     files: 765
    5  # DYLL_M10to50_ext1v2 files: 467
    15 # DYLL_M50to100       files: 1451
    3  # DYLL_M100to200      files: 213
    1  # DYLL_M200to400      files: 75
    1  # DYLL_M400to500      files: 4
    1  # DYLL_M500to700      files: 16
    1  # DYLL_M700to800      files: 17
    1  # DYLL_M800to1000     files: 10
    1  # DYLL_M1000to1500    files: 11
    1  # DYLL_M1500to2000    files: 20
    1  # DYLL_M2000to3000    files: 8

)

for index in ${!sampleShortName[*]}; do 
    echo "Submit jobs for sample ${sampleShortName[$index]} at ${sampleName[$index]}/${sampleSubdir[$index]} with numberOfSections=${numberOfSections[$index]} sections"
    condor_submit \
	ntuplesGeneralLocation=${ntuplesGeneralLocation} \
	sampleShortName=${sampleShortName[$index]} \
	sampleName=${sampleName[$index]} \
	sampleSubdir=${sampleSubdir[$index]} \
	numberOfSections=${numberOfSections[$index]} \
	filterDyDecayControlScript.condor
done
