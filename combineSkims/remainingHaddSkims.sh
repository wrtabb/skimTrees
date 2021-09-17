#!/bin/bash

# This script combines all the skimmed root files from each directory into
# Single files
# It then moves them from the current directory to the storage area

directories=(
	ttbarBackup_truncated_M0To700
	ttbar_M700to1000
	ttbar_M1000toInf
	ST_tW
	ST_tbarW
	WJetsToLNu_amcatnlo
	WJetsToLNu_amcatnlo_ext
	WJetsToLNu_amcatnlo_ext2v5
	crab_DoubleEG_RunB
	crab_DoubleEG_RunC
	crab_DoubleEG_RunD
	crab_DoubleEG_RunE
	crab_DoubleEG_RunF
	crab_DoubleEG_RunG
	crab_DoubleEG_RunHver2
	crab_DoubleEG_RunHver3
)
output_file=(
	ttbarBackup_truncated_M0To700
	ttbar_M700to1000
	ttbar_M1000toInf
	ST_tW
	ST_tbarW
	WJetsToLNu_amcatnlo
	WJetsToLNu_amcatnlo_ext
	WJetsToLNu_amcatnlo_ext2v5
	crab_DoubleEG_RunB
	crab_DoubleEG_RunC
	crab_DoubleEG_RunD
	crab_DoubleEG_RunE
	crab_DoubleEG_RunF
	crab_DoubleEG_RunG
	crab_DoubleEG_RunHver2
	crab_DoubleEG_RunHver3
)
root_suffix='.root'
 
for index in ${!directories[*]}; do
echo "************************************************************************************"
echo "* Combining files from ${directories[$index]} *"
echo "************************************************************************************"
root -l << EOF
gROOT->SetBatch(true);
TString dir="${directories[$index]}"
TString output="${output_file[$index]}"
.L processHadd.C
processHadd(dir,output)
EOF
echo "************************************************************************************"
echo "* Moving ${output_file[$index]}${root_suffix} to hadoop *"
echo "************************************************************************************"
mv ${output_file[$index]}${root_suffix} /mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/skims/skims_EE
done
