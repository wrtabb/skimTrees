#!/bin/bash

# This script combines all the skimmed root files from each directory into
# Single files
# It then moves them from the current directory to the storage area

directories=(
	WJetsToLNu_amcatnlo_ext
)
output_file=(
	WJetsToLNu_amcatnlo_ext
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
