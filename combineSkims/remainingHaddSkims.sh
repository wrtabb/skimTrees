#!/bin/bash

# This script combines all the skimmed root files from each directory into
# Single files
# It then moves them from the current directory to the storage area

directories=(
	ttbar_truncated_M0To700
	ttbarBackup_truncated_M0To700
	ttbar_M700to1000
	ttbar_M1000toInf
	ST_tW
	ST_tbarW
	WJetsToLNu_amcatnlo
	WJetsToLNu_amcatnlo_ext
	WJetsToLNu_amcatnlo_ext2v5
	SingleMuon_Run2016B
	SingleMuon_Run2016C
	SingleMuon_Run2016D
	SingleMuon_Run2016E
	SingleMuon_Run2016F
	SingleMuon_Run2016G
	SingleMuon_Run2016Hver2
	SingleMuon_Run2016Hver3
)
output_file=(
	ttbar_truncated_M0To700
	ttbarBackup_truncated_M0To700
	ttbar_M700to1000
	ttbar_M1000toInf
	ST_tW
	ST_tbarW
	WJetsToLNu_amcatnlo
	WJetsToLNu_amcatnlo_ext
	WJetsToLNu_amcatnlo_ext2v5
	SingleMuon_Run2016B
	SingleMuon_Run2016C
	SingleMuon_Run2016D
	SingleMuon_Run2016E
	SingleMuon_Run2016F
	SingleMuon_Run2016G
	SingleMuon_Run2016Hver2
	SingleMuon_Run2016Hver3
)
root_suffix='.root'
 
for index in ${!directories[*]}; do
echo "************************************************************************************"
echo "* Combining files from ${directories[$index]} *"
echo "************************************************************************************"
root -l << EOF
TString dir="${directories[$index]}"
TString output="${output_file[$index]}"
.L processHadd.C
processHadd(dir,output)
EOF
echo "************************************************************************************"
echo "* Moving ${output_file[$index]}${root_suffix} to hadoop *"
echo "************************************************************************************"
mv ${output_file[$index]}${root_suffix} /mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/skims/skims_MuMu
done
