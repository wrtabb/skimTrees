#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    DYJetsToLL_M-10to50_v1
    DYJetsToLL_M-10to50_v2
    DYJetsToLL_M-10to50_ext1v1
    DYJetsToLL_M-50
    DYJetsToLL_M-50_truncated_M50To100
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
    WW
    WWTo2L2Nu
    WZ
    WZTo3LNu
    ZZ
    ZZTo4L
    TT
    TT_Backup
    TT_truncated_M0To700
    TT_Backup_truncated_M0To700
    TT_Mtt-700to1000
    TT_Mtt-1000toInf
    ST_tW_top_5f_inclusiveDecays
    ST_tW_antitop_5f_inclusiveDecays
    WJetsToLNu
    WJetsToLNu_ext
    QCD_Pt-20to30_EMEnriched
    QCD_Pt-30to50_EMEnriched
    QCD_Pt-30to50_EMEnriched_ext1
    QCD_Pt-50to80_EMEnriched
    QCD_Pt-50to80_EMEnriched_ext1
    QCD_Pt-80to120_EMEnriched
    QCD_Pt-80to120_EMEnriched_ext1
    QCD_Pt-120to170_EMEnriched
    QCD_Pt-120to170_EMEnriched_ext1
    QCD_Pt-170to300_EMEnriched
    QCD_Pt-300toInf
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
    DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M10to50_v1     # DYJetsToLL_M-10to50_v1
    DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M10to50_v2     # DYJetsToLL_M-10to50_v2
    DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M10to50_ext1v1 # DYJetsToLL_M-10to50_ext1v1
    DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                              # DYJetsToLL_M-50
    DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_truncated_M50To100           # DYJetsToLL_M-50_truncated_M50To100
    DYJetsToLL_M-100to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M100to200     # DYJetsToLL_M-100to200
    DYJetsToLL_M-100to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYLL_M100to200_ext # DYJetsToLL_M-100to200_ext
    DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                         # DYJetsToLL_M-200to400
    DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                         # DYJetsToLL_M-400to500AA
    DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                         # DYJetsToLL_M-500to700
    DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                         # DYJetsToLL_M-700to800
    DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                        # DYJetsToLL_M-800to1000
    DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                       # DYJetsToLL_M-1000to1500
    DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                       # DYJetsToLL_M-1500to2000
    DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8                       # DYJetsToLL_M-2000to3000
    WW_TuneCUETP8M1_13TeV-pythia8                                                         # WW
    WWTo2L2Nu_13TeV-powheg                                                                # WWTo2L2Nu
    WZ_TuneCUETP8M1_13TeV-pythia8                                                         # WZ
    WZTo3LNu_TuneCUETP8M1_13TeV-powheg-pythia8                                            # WZTo3LNu
    ZZ_TuneCUETP8M1_13TeV-pythia8                                                         # ZZ
    ZZTo4L_13TeV_powheg_pythia8                                                           # ZZTo4L
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/crab_ttbar                                     # TT
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/crab_ttbarBackup                               # TT_Backup
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_truncated_M0To700/crab_ttbar        # TT_truncated_M0To700
    TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_truncated_M0To700/crab_ttbarBackup        # TT_Backup_truncated_M0To700
    TT_Mtt-700to1000_TuneCUETP8M2T4_13TeV-powheg-pythia8                                  # TT_Mtt-700to1000
    TT_Mtt-1000toInf_TuneCUETP8M2T4_13TeV-powheg-pythia8                                  # TT_Mtt-1000toInf
    ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1                        # ST_tW_top_5f_inclusiveDecays
    ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1                    # ST_tW_antitop_5f_inclusiveDecays
    WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_amcatnlo           # WJetsToLNu
    WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_amcatnlo_ext       # WJetsToLNu_ext
    QCD_Pt-20to30_EMEnriched_TuneCUETP8M1_13TeV_pythia8                                   # QCD_Pt-20to30_EMEnriched
    QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt30to50       # QCD_Pt-30to50_EMEnriched
    QCD_Pt-30to50_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt30to50_ext1  # QCD_Pt-30to50_EMEnriched_ext1
    QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt50to80       # QCD_Pt-50to80_EMEnriched
    QCD_Pt-50to80_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt50to80_ext1  # QCD_Pt-50to80_EMEnriched_ext1
    QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt80to120     # QCD_Pt-80to120_EMEnriched
    QCD_Pt-80to120_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt80to120_ext1 # QCD_Pt-80to120_EMEnriched_ext1
    QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt120to170   # QCD_Pt-120to170_EMEnriched
    QCD_Pt-120to170_EMEnriched_TuneCUETP8M1_13TeV_pythia8/crab_QCDEMEnriched_Pt120to170_ext1 # QCD_Pt-120to170_EMEnriched_ext1
    QCD_Pt-170to300_EMEnriched_TuneCUETP8M1_13TeV_pythia8                                 # QCD_Pt-170to300_EMEnriched
    QCD_Pt-300toInf_EMEnriched_TuneCUETP8M1_13TeV_pythia8                                 # QCD_Pt-300toInf
    DoubleEG/crab_DoubleEG_RunB                                                           # DoubleEG_RunB
    DoubleEG/crab_DoubleEG_RunC                                                           # DoubleEG_RunC
    DoubleEG/crab_DoubleEG_RunD                                                           # DoubleEG_RunD
    DoubleEG/crab_DoubleEG_RunE                                                           # DoubleEG_RunE
    DoubleEG/crab_DoubleEG_RunF                                                           # DoubleEG_RunF
    DoubleEG/crab_DoubleEG_RunG                                                           # DoubleEG_RunG
    DoubleEG/crab_DoubleEG_RunHver2                                                       # DoubleEG_RunHver2
    DoubleEG/crab_DoubleEG_RunHver3                                                       # DoubleEG_RunHver3
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    2 # DYJetsToLL_M-10to50_v1 total files: 125
    4 # DYJetsToLL_M-10to50_v2 total files: 389
    3 # DYJetsToLL_M-10to50_ext1v1 total files: 240
    8 # DYJetsToLL_M-50 total files: 726
    8 # DYJetsToLL_M-50_truncated_M50To100 total files 726
    1 # DYJetsToLL_M-100to200 total files: 13
    3 # DYJetsToLL_M-100to200_ext total files: 236
    1 # DYJetsToLL_M-200to400 total files: 6
    1 # DYJetsToLL_M-400to500 total files: 2
    1 # DYJetsToLL_M-500to700 total files: 8
    1 # DYJetsToLL_M-700to800 total files: 9
    1 # DYJetsToLL_M-800to1000 total files: 5
    1 # DYJetsToLL_M-1000to1500 total files: 6
    1 # DYJetsToLL_M-1500to2000 total files: 10
    1 # DYJetsToLL_M-2000to3000
    1 # WW total files: 58
    1 # WWTo2L2Nu total files: 12
    1 # WZ
    2 # WZTo3LNu total files: 144
    1 # ZZ total files: 33
    1 # ZZTo4L total files: 48
    5 # TT total files: 491
    6 # TT_Backup total files: 595
    5 # TT_truncated_M0To700 total files 492
    6 # TT_truncated_M0To700_Backup total files 595
    4 # TT_Mtt-700to1000 total files: 372
    3 # TT_Mtt-1000toInf total files: 259
    1 # ST_tW_top_5f_inclusiveDecays total files: 81
    1 # ST_tW_antitop_5f_inclusiveDecays total files: 72
    2 # WJetsToLNu total files: 149
   14 # WJetsToLNu_ext total files: 1336
    2 # QCD_Pt-20to30_EMEnriched total files: 112
    1 # QCD_Pt-30to50_EMEnriched total files: 34
    1 # QCD_Pt-30to50_EMEnriched_ext1 total files: 58
    2 # QCD_Pt-50to80_EMEnriched total files: 186
    2 # QCD_Pt-50to80_EMEnriched_ext1 total files: 148
    3 # QCD_Pt-80to120_EMEnriched total files: 271
    3 # QCD_Pt-80to120_EMEnriched_ext1 total files: 279
    4 # QCD_Pt-120to170_EMEnriched total files: 316
    4 # QCD_Pt-120to170_EMEnriched_ext1 total files: 306
    2 # QCD_Pt-170to300_EMEnriched total files: 116
    1 # QCD_Pt-300toInf total files: 93
   14 # DoubleEG_RunB total files 1318
    5 # DoubleEG_RunC total files 435
    8 # DoubleEG_RunD total files 729
    7 # DoubleEG_RunE total files 620
    5 # DoubleEG_RunF total files 452
   11 # DoubleEG_RunG total files 1068
   12 # DoubleEG_RunHver2 total files 1156
    1 # DoubleEG_RunHver3 total files 31
)

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
    true # DYJetsToLL_M-10to50_v1
    true # DYJetsToLL_M-10to50_v2
    true # DYJetsToLL_M-10to50_ext1v1
    true # DYJetsToLL_M-50
    true # DYJetsToLL_M-50_truncated_M50To100
    true # DYJetsToLL_M-100to200
    true # DYJetsToLL_M-100to200_ext
    true # DYJetsToLL_M-200to400
    true # DYJetsToLL_M-400to500
    true # DYJetsToLL_M-500to700
    true # DYJetsToLL_M-700to800
    true # DYJetsToLL_M-800to1000
    true # DYJetsToLL_M-1000to1500
    true # DYJetsToLL_M-1500to2000
    true # DYJetsToLL_M-2000to3000
    true # WW
    true # WWTo2L2Nu
    true # WZ
    true # WZTo3LNu
    true # ZZ
    true # ZZTo4L
    true # TT
    true # TT_Backup
    true # TT_truncated_M0To700
    true # TT_Backup_truncated_M0To700
    true # TT_Mtt-700to1000
    true # TT_Mtt-1000toInf
    true # ST_tW_top_5f_inclusiveDecays
    true # ST_tW_antitop_5f_inclusiveDecays
    true # WJetsToLNu
    true # WJetsToLNu_ext
    true # QCD_Pt-20to30_EMEnriched
    true # QCD_Pt-30to50_EMEnriched
    true # QCD_Pt-30to50_EMEnriched_ext1
    true # QCD_Pt-50to80_EMEnriched
    true # QCD_Pt-50to80_EMEnriched_ext1
    true # QCD_Pt-80to120_EMEnriched
    true # QCD_Pt-80to120_EMEnriched_ext1
    true # QCD_Pt-120to170_EMEnriched
    true # QCD_Pt-120to170_EMEnriched_ext1
    true # QCD_Pt-170to300_EMEnriched
    true # QCD_Pt-300toInf
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
