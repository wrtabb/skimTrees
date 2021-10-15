#!/bin/bash

# This script combines all the skimmed root files from each directory into
# Single files
# It then moves them from the current directory to the storage area

directories=(
	QCDMuEnriched_Pt15to20
        QCDMuEnriched_Pt20to30
        QCDMuEnriched_Pt20toInf
        QCDMuEnriched_Pt30to50
        QCDMuEnriched_Pt50to80
        QCDMuEnriched_Pt80to120
        QCDMuEnriched_Pt80to120_ext1
        QCDMuEnriched_Pt120to170
        QCDMuEnriched_Pt120to170_backup
        QCDMuEnriched_Pt170to300
        QCDMuEnriched_Pt170to300_backup
        QCDMuEnriched_Pt170to300_ext1
        QCDMuEnriched_Pt300to470
        QCDMuEnriched_Pt300to470_ext1
        QCDMuEnriched_Pt300to470_ext2
        QCDMuEnriched_Pt470to600
        QCDMuEnriched_Pt600to800
        QCDMuEnriched_Pt600to800_backup
        QCDMuEnriched_Pt600to800_ext1
        QCDMuEnriched_Pt800to1000
        QCDMuEnriched_Pt800to1000_ext1
        QCDMuEnriched_Pt800to1000_ext2
        QCDMuEnriched_Pt1000toInf
        QCDMuEnriched_Pt1000toInf_ext1
)
output_file=(
	QCDMuEnriched_Pt15to20
        QCDMuEnriched_Pt20to30
        QCDMuEnriched_Pt20toInf
        QCDMuEnriched_Pt30to50
        QCDMuEnriched_Pt50to80
        QCDMuEnriched_Pt80to120
        QCDMuEnriched_Pt80to120_ext1
        QCDMuEnriched_Pt120to170
        QCDMuEnriched_Pt120to170_backup
        QCDMuEnriched_Pt170to300
        QCDMuEnriched_Pt170to300_backup
        QCDMuEnriched_Pt170to300_ext1
        QCDMuEnriched_Pt300to470
        QCDMuEnriched_Pt300to470_ext1
        QCDMuEnriched_Pt300to470_ext2
        QCDMuEnriched_Pt470to600
        QCDMuEnriched_Pt600to800
        QCDMuEnriched_Pt600to800_backup
        QCDMuEnriched_Pt600to800_ext1
        QCDMuEnriched_Pt800to1000
        QCDMuEnriched_Pt800to1000_ext1
        QCDMuEnriched_Pt800to1000_ext2
        QCDMuEnriched_Pt1000toInf
        QCDMuEnriched_Pt1000toInf_ext1
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
