#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/"

sampleShortName=(
	DYJetsToLL_M-10to50_v1 #
	DYJetsToLL_M-10to50_v2 #
	DYJetsToLL_M-10to50_ext1v1 #
	DYJetsToLL_M-50to100  
	DYJetsToLL_M-100to200
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
	3  # M10to50_v1 242
	8  # M10to50_v2 765
	5  # M10to50_ext1v1 472 
	15 # M50to100 1451
	3  # M100to200 219
	1  # M200to400 81
	1  # M400to500 10
	1  # M500to700 22
	1  # M700to800 23
	1  # M800to1000 16
	1  # M1000to1500 17
	1  # M1500to2000 26
	1  # M2000to3000 14
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
