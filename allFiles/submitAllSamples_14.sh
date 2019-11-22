#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    TT_Mtt-1000toInf
    ST_tW_top_5f_inclusiveDecays
    ST_tW_antitop_5f_inclusiveDecays
    WJetsToLNu
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
    TT_Mtt-1000toInf_TuneCUETP8M2T4_13TeV-powheg-pythia8                                  # TT_Mtt-1000toInf
    ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1                        # ST_tW_top_5f_inclusiveDecays
    ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1                    # ST_tW_antitop_5f_inclusiveDecays
    WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_amcatnlo           # WJetsToLNu
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
    3 # TT_Mtt-1000toInf total files: 259
    1 # ST_tW_top_5f_inclusiveDecays total files: 81
    1 # ST_tW_antitop_5f_inclusiveDecays total files: 72
    2 # WJetsToLNu total files: 149
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
    true # TT_Mtt-1000toInf
    true # ST_tW_top_5f_inclusiveDecays
    true # ST_tW_antitop_5f_inclusiveDecays
    true # WJetsToLNu
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
