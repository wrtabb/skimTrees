#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"
skimTag="0002"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
    DYJetsToLL_M-10to50_v1_EE
    DYJetsToLL_M-10to50_v2_EE
    DYJetsToLL_M-10to50_ext1v1_EE
    DYJetsToLL_M-50_EE
    DYJetsToLL_M-50_truncated_M50To100_EE
    DYJetsToLL_M-100to200_EE
    DYJetsToLL_M-100to200_ext_EE
    DYJetsToLL_M-200to400_EE
    DYJetsToLL_M-400to500_EE
    DYJetsToLL_M-500to700_EE
    DYJetsToLL_M-700to800_EE
    DYJetsToLL_M-800to1000_EE
    DYJetsToLL_M-1000to1500_EE
    DYJetsToLL_M-1500to2000_EE
    DYJetsToLL_M-2000to3000_EE
)

sampleLocation=(
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE/crab_DYLL_M10to50_v1     # DYJetsToLL_M-10to50_v1
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE/crab_DYLL_M10to50_v2     # DYJetsToLL_M-10to50_v2
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE/crab_DYLL_M10to50_ext1v1 # DYJetsToLL_M-10to50_ext1v1
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                              # DYJetsToLL_M-50
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_truncated_M50To100/EE           # DYJetsToLL_M-50_truncated_M50To100
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-100to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE/crab_DYLL_M100to200     # DYJetsToLL_M-100to200
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-100to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE/crab_DYLL_M100to200_ext # DYJetsToLL_M-100to200_ext
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                         # DYJetsToLL_M-200to400
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                         # DYJetsToLL_M-400to500AA
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                         # DYJetsToLL_M-500to700
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                         # DYJetsToLL_M-700to800
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                        # DYJetsToLL_M-800to1000
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                       # DYJetsToLL_M-1000to1500
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                       # DYJetsToLL_M-1500to2000
    DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE                       # DYJetsToLL_M-2000to3000
)

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
numberOfSections=(
    1 # DYJetsToLL_M-10to50_v1 total files: 125
    1 # DYJetsToLL_M-10to50_v2 total files: 389
    1 # DYJetsToLL_M-10to50_ext1v1 total files: 240
    1 # DYJetsToLL_M-50 total files: 739
    1 # DYJetsToLL_M-50_truncated_M50To100 total files 726
    1 # DYJetsToLL_M-100to200 total files: 13
    1 # DYJetsToLL_M-100to200_ext total files: 236
    1 # DYJetsToLL_M-200to400 total files: 6
    1 # DYJetsToLL_M-400to500 total files: 2
    1 # DYJetsToLL_M-500to700 total files: 8
    1 # DYJetsToLL_M-700to800 total files: 9
    1 # DYJetsToLL_M-800to1000 total files: 5
    1 # DYJetsToLL_M-1000to1500 total files: 6
    1 # DYJetsToLL_M-1500to2000 total files: 10
    1 # DYJetsToLL_M-2000to3000
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
