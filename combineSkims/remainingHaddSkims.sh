#!/bin/bash

# This script combines all the skimmed root files from each directory into
# Single files
# It then moves them from the current directory to the storage area

directories=(
	DYLL_M50toInf/DYLL_M50toInf_truncated_M50To100/TauTau/base
	DYLL_M100to200/DYLL_M100to200/EE
	DYLL_M100to200/DYLL_M100to200/TauTau
	DYLL_M200to400/DYLL_M200to400/EE
	DYLL_M200to400/DYLL_M200to400/TauTau
	DYLL_M400to500/DYLL_M400to500/EE
	DYLL_M400to500/DYLL_M400to500/TauTau
	DYLL_M500to700/DYLL_M500to700/EE
	DYLL_M500to700/DYLL_M500to700/TauTau
	DYLL_M700to800/DYLL_M700to800/EE
	DYLL_M700to800/DYLL_M700to800/TauTau
	DYLL_M800to1000/DYLL_M800to1000/EE
	DYLL_M800to1000/DYLL_M800to1000/TauTau
	DYLL_M1000to1500/DYLL_M1000to1500/EE
	DYLL_M1000to1500/DYLL_M1000to1500/TauTau
	DYLL_M1500to2000/DYLL_M1500to2000/EE
	DYLL_M1500to2000/DYLL_M1500to2000/TauTau
	DYLL_M2000to3000/DYLL_M2000to3000/EE
	DYLL_M2000to3000/DYLL_M2000to3000/TauTau
	WW
	WZ
	ZZ
	ZToEE_M50to120
	ZToEE_M120to200
	ZToEE_M200to400
	ZToEE_M400to800
	ZToEE_M800to1400
	ZToEE_M1400to2300
	ZToEE_M2300to3500
	ZToEE_M3500to4500
	ZToEE_M4500to6000
	ZToEE_M6000toInf
	ttbar
	ttbarBackup
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
	DYLL_M50To100_TauTau
	DYLL_M100to200_EE
	DYLL_M100to200_TauTau
	DYLL_M200to400_EE
	DYLL_M200to400_TauTau
	DYLL_M400to500_EE
	DYLL_M400to500_TauTau
	DYLL_M500to700_EE
	DYLL_M500to700_TauTau
	DYLL_M700to800_EE
	DYLL_M700to800_TauTau
	DYLL_M800to1000_EE
	DYLL_M800to1000_TauTau
	DYLL_M1000to1500_EE
	DYLL_M1000to1500_TauTau
	DYLL_M1500to2000_EE
	DYLL_M1500to2000_TauTau
	DYLL_M2000to3000_EE
	DYLL_M2000to3000_TauTau
	WW
	WZ
	ZZ
	ZToEE_M50to120
	ZToEE_M120to200
	ZToEE_M200to400
	ZToEE_M400to800
	ZToEE_M800to1400
	ZToEE_M1400to2300
	ZToEE_M2300to3500
	ZToEE_M3500to4500
	ZToEE_M4500to6000
	ZToEE_M6000toInf
	ttbar
	ttbarBackup
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
