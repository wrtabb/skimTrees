#!/bin/bash

# This script combines all the skimmed root files from each directory into
# Single files
# It then moves them from the current directory to the storage area

directories=(
        QCDEMEnriched_Pt20to30
        QCDEMEnriched_Pt30to50
        QCDEMEnriched_Pt50to80
        QCDEMEnriched_Pt50to80_ext1
        QCDEMEnriched_Pt80to120
        QCDEMEnriched_Pt80to120_ext1
        QCDEMEnriched_Pt120to170
        QCDEMEnriched_Pt120to170_ext1
        QCDEMEnriched_Pt170to300
        QCDEMEnriched_Pt300toInf
)
output_file=(
        QCDEMEnriched_Pt20to30
        QCDEMEnriched_Pt30to50
        QCDEMEnriched_Pt50to80
        QCDEMEnriched_Pt50to80_ext1
        QCDEMEnriched_Pt80to120
        QCDEMEnriched_Pt80to120_ext1
        QCDEMEnriched_Pt120to170
        QCDEMEnriched_Pt120to170_ext1
        QCDEMEnriched_Pt170to300
        QCDEMEnriched_Pt300toInf
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
