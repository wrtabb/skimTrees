#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6"
skimTag="MuMu"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    DYLL_M10to50_EE_v1
    DYLL_M10to50_MuMu_v1
    DYLL_M10to50_TauTau_v1
    DYLL_M10to50_EE_v2
    DYLL_M10to50_MuMu_v2
    DYLL_M10to50_TauTau_v2
    DYLL_M10to50_EE_ext1v1
    DYLL_M10to50_MuMu_ext1v1
    DYLL_M10to50_TauTau_ext1v1
    DYLL_M50to100_EE
    DYLL_M50to100_MuMu
    DYLL_M50to100_TauTau
    DYLL_M100to200_EE
    DYLL_M100to200_MuMu
    DYLL_M100to200_TauTau
    DYLL_M200to400_EE
    DYLL_M200to400_MuMu
    DYLL_M200to400_TauTau
    DYLL_M400to500_EE
    DYLL_M400to500_MuMu
    DYLL_M400to500_TauTau
    DYLL_M500to700_EE
    DYLL_M500to700_MuMu
    DYLL_M500to700_TauTau
    DYLL_M700to800_EE
    DYLL_M700to800_MuMu
    DYLL_M700to800_TauTau
    DYLL_M800to1000_EE
    DYLL_M800to1000_MuMu
    DYLL_M800to1000_TauTau
    DYLL_M1000to1500_EE
    DYLL_M1000to1500_MuMu
    DYLL_M1000to1500_TauTau
    DYLL_M1500to2000_EE
    DYLL_M1500to2000_MuMu
    DYLL_M1500to2000_TauTau
    DYLL_M2000to3000_EE
    DYLL_M2000to3000_MuMu
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
    WJetsToLNu
    WJetsToLNu_ext
    WJetsToLNu_ext2v5
    SingleMuon_Run2016B
    SingleMuon_Run2016C
    SingleMuon_Run2016D
    SingleMuon_Run2016E
    SingleMuon_Run2016F
    SingleMuon_Run2016G
    SingleMuon_Run2016Hver2
    SingleMuon_Run2016Hver3
    DoubleEG_RunB
    DoubleEG_RunC
    DoubleEG_RunD
    DoubleEG_RunE
    DoubleEG_RunF
    DoubleEG_RunG
    DoubleEG_RunHver2
    DoubleEG_RunHver3
)

sampleLocation=(
    DYLL_M10to50/DYLL_M10to50/EE/v1
    DYLL_M10to50/DYLL_M10to50/MuMu/v1
    DYLL_M10to50/DYLL_M10to50/TauTau/v1
    DYLL_M10to50/DYLL_M10to50/EE/v2
    DYLL_M10to50/DYLL_M10to50/MuMu/v2
    DYLL_M10to50/DYLL_M10to50/TauTau/v2
    DYLL_M10to50/DYLL_M10to50/EE/ext1v1
    DYLL_M10to50/DYLL_M10to50/MuMu/ext1v1
    DYLL_M10to50/DYLL_M10to50/TauTau/ext1v1
    DYLL_M50toInf/DYLL_M50toInf_truncated_M50To100/EE/base
    DYLL_M50toInf/DYLL_M50toInf_truncated_M50To100/MuMu/base
    DYLL_M50toInf/DYLL_M50toInf_truncated_M50To100/TauTau/base
    DYLL_M100to200/DYLL_M100to200/EE
    DYLL_M100to200/DYLL_M100to200/MuMu
    DYLL_M100to200/DYLL_M100to200/TauTau
    DYLL_M200to400/DYLL_M200to400/EE
    DYLL_M200to400/DYLL_M200to400/MuMu
    DYLL_M200to400/DYLL_M200to400/TauTau
    DYLL_M400to500/DYLL_M400to500/EE
    DYLL_M400to500/DYLL_M400to500/MuMu
    DYLL_M400to500/DYLL_M400to500/TauTau
    DYLL_M500to700/DYLL_M500to700/EE
    DYLL_M500to700/DYLL_M500to700/MuMu
    DYLL_M500to700/DYLL_M500to700/TauTau
    DYLL_M700to800/DYLL_M700to800/EE
    DYLL_M700to800/DYLL_M700to800/MuMu
    DYLL_M700to800/DYLL_M700to800/TauTau
    DYLL_M800to1000/DYLL_M800to1000/EE
    DYLL_M800to1000/DYLL_M800to1000/MuMu
    DYLL_M800to1000/DYLL_M800to1000/TauTau
    DYLL_M1000to1500/DYLL_M1000to1500/EE
    DYLL_M1000to1500/DYLL_M1000to1500/MuMu
    DYLL_M1000to1500/DYLL_M1000to1500/TauTau
    DYLL_M1500to2000/DYLL_M1500to2000/EE
    DYLL_M1500to2000/DYLL_M1500to2000/MuMu
    DYLL_M1500to2000/DYLL_M1500to2000/TauTau
    DYLL_M2000to3000/DYLL_M2000to3000/EE
    DYLL_M2000to3000/DYLL_M2000to3000/MuMu
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

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
# roughly 1 section per 100 files rounded up
numberOfSections=(
   3 # DYLL_M10to50_EE_v1 236
   3 # DYLL_M10to50_MuMu_v1 236
   3 # DYLL_M10to50_TauTau_v1 236 
   8 # DYLL_M10to50_EE_v2 765
   8 # DYLL_M10to50_MuMu_v2 765 
   8 # DYLL_M10to50_TauTau_v2 765
   5 # DYLL_M10to50_EE_ext1v1 467
   5 # DYLL_M10to50_MuMu_ext1v1 467
   5 # DYLL_M10to50_TauTau_ext1v1 467
   15 # DYLL_M50to100_EE 1451
   15 # DYLL_M50to100_MuMu 1451
   15 # DYLL_M50to100_TauTau 1451
   3 # DYLL_M100to200_EE 213
   3 # DYLL_M100to200_MuMu 213
   3 # DYLL_M100to200_TauTau 213
   1 # DYLL_M200to400_EE 75
   1 # DYLL_M200to400_MuMu 75
   1 # DYLL_M200to400_TauTau 75
   1 # DYLL_M400to500_EE 4
   1 # DYLL_M400to500_MuMu 4
   1 # DYLL_M400to500_TauTau 4
   1 # DYLL_M500to700_EE 16
   1 # DYLL_M500to700_MuMu 16
   1 # DYLL_M500to700_TauTau 16
   1 # DYLL_M700to800_EE 17
   1 # DYLL_M700to800_MuMu 17
   1 # DYLL_M700to800_TauTau 17
   1 # DYLL_M800to1000_EE 10
   1 # DYLL_M800to1000_MuMu 10
   1 # DYLL_M800to1000_TauTau 10
   1 # DYLL_M1000to1500_EE 11
   1 # DYLL_M1000to1500_MuMu 11
   1 # DYLL_M1000to1500_TauTau 11
   1 # DYLL_M1500to2000_EE 20
   1 # DYLL_M1500to2000_MuMu 20
   1 # DYLL_M1500to2000_TauTau 20
   1 # DYLL_M2000to3000_EE 8
   1 # DYLL_M2000to3000_MuMu 8
   1 # DYLL_M2000to3000_TauTau 8
   2 # WW 116
   2 # WZ 128
   1 # ZZ 66
   1 # ZToEE_M50to120 29
   1 # ZToEE_M120to200 2
   1 # ZToEE_M200to400 2
   1 # ZToEE_M400to800 2
   1 # ZToEE_M800to1400 4
   1 # ZToEE_M1400to2300 2
   1 # ZToEE_M2300to3500 2
   1 # ZToEE_M3500to4500 2
   1 # ZToEE_M4500to6000 3
   1 # ZToEE_M6000toInf 2
   10 # ttbar 980
   12 # ttbarBackup 1190
   10 # ttbar_truncated_M0To700 980
   12 # ttbarBackup_truncated_M0To700 1190
   8 # ttbar_M700to1000 745
   6 # ttbar_M1000toInf 518
   2 # ST_tW 161
   2 # ST_tbarW 144
   3 # WJetsToLNu 297
   27 # WJetsToLNu_ext 2670
   36 # WJetsToLNu_ext2v5 3568
   14 # SingleMuon_Run2016B 1317
   5 # SingleMuon_Run2016C 435
   8 # SingleMuon_Run2016D 729
   7 # SingleMuon_Run2016E 620
   5 # SingleMuon_Run2016F 452
   11 # SingleMuon_Run2016G 1068
   12 # SingleMuon_Run2016Hver2 1156
   1 # SingleMuon_Run2016Hver3 31
   14 # DoubleEG_RunB 1318
   5 # DoubleEG_RunC 435
   8 # DoubleEG_RunD 729
   7 # DoubleEG_RunE 620
   5 # DoubleEG_RunF 452
   11 # DoubleEG_RunG 1068
   12 # DoubleEG_RunHver2 1156
   1 # DoubleEG_RunHver3 31
 )

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
   true # DYLL_M10to50_EE_v1
   true # DYLL_M10to50_MuMu_v1
   true # DYLL_M10to50_TauTau_v1
   true # DYLL_M10to50_EE_v2
   true # DYLL_M10to50_MuMu_v2
   true # DYLL_M10to50_TauTau_v2
   true # DYLL_M10to50_EE_ext1v1
   true # DYLL_M10to50_MuMu_ext1v1
   true # DYLL_M10to50_TauTau_ext1v1
   true # DYLL_M50to100_EE
   true # DYLL_M50to100_MuMu
   true # DYLL_M50to100_TauTau
   true # DYLL_M100to200_EE
   true # DYLL_M100to200_MuMu
   true # DYLL_M100to200_TauTau
   true # DYLL_M200to400_EE
   true # DYLL_M200to400_MuMu
   true # DYLL_M200to400_TauTau
   true # DYLL_M400to500_EE
   true # DYLL_M400to500_MuMu
   true # DYLL_M400to500_TauTau
   true # DYLL_M500to700_EE
   true # DYLL_M500to700_MuMu
   true # DYLL_M500to700_TauTau
   true # DYLL_M700to800_EE
   true # DYLL_M700to800_MuMu
   true # DYLL_M700to800_TauTau
   true # DYLL_M800to1000_EE
   true # DYLL_M800to1000_MuMu
   true # DYLL_M800to1000_TauTau
   true # DYLL_M1000to1500_EE
   true # DYLL_M1000to1500_MuMu
   true # DYLL_M1000to1500_TauTau
   true # DYLL_M1500to2000_EE
   true # DYLL_M1500to2000_MuMu
   true # DYLL_M1500to2000_TauTau
   true # DYLL_M2000to3000_EE
   true # DYLL_M2000to3000_MuMu
   true # DYLL_M2000to3000_TauTau
   true # WW
   true # WZ
   true # ZZ
   true # ZToEE_M50to120
   true # ZToEE_M120to200
   true # ZToEE_M200to400
   true # ZToEE_M400to800
   true # ZToEE_M800to1400
   true # ZToEE_M1400to2300
   true # ZToEE_M2300to3500
   true # ZToEE_M3500to4500
   true # ZToEE_M4500to6000
   true # ZToEE_M6000toInf
   true # ttbar
   true # ttbarBackup
   true # ttbar_truncated_M0To700
   true # ttbarBackup_truncated_M0To700
   true # ttbar_M700to1000
   true # ttbar_M1000toInf
   true # ST_tW
   true # ST_tbarW
   true # WJetsToLNu
   true # WJetsToLNu_ext
   true # WJetsToLNu_ext2v5
   false # SingleMuon_Run2016B
   false # SingleMuon_Run2016C
   false # SingleMuon_Run2016D
   false # SingleMuon_Run2016E
   false # SingleMuon_Run2016F
   false # SingleMuon_Run2016G
   false # SingleMuon_Run2016Hver2
   false # SingleMuon_Run2016Hver3
   false # DoubleEG_RunB
   false # DoubleEG_RunC
   false # DoubleEG_RunD
   false # DoubleEG_RunE
   false # DoubleEG_RunF
   false # DoubleEG_RunG
   false # DoubleEG_RunHver2
   false # DoubleEG_RunHver3
)

for index in ${!sampleLocation[*]}; do 
    condor_submit \
	sampleShortName=${sampleShortName[$index]} \
	ntuplesGeneralLocation=${ntuplesGeneralLocation} \
	sampleLocation=${sampleLocation[$index]} \
	skimTag=${skimTag} \
	numberOfSections=${numberOfSections[$index]} \
	preserveEventCount=${preserveEventCount[$index]}  \
	skimControlScript.condor
done
