#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3"

sampleShortName=(
    DYJetsToLL_M-50
    DYJetsToLL_M-50to100
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
)

sampleName=(
    DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8           # DYJetsToLL_M-50                                                           
    DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_truncated_M50To100 # DYJetsToLL_M-50to100
    DYJetsToLL_M-100to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8     # DYJetsToLL_M-100to200                                                    
    DYJetsToLL_M-100to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8     # DYJetsToLL_M-100to200_ext                                                
    DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8     # DYJetsToLL_M-200to400                                                    
    DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8     # DYJetsToLL_M-400to500AA                                                  
    DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8     # DYJetsToLL_M-500to700                                                    
    DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8     # DYJetsToLL_M-700to800                                                    
    DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8    # DYJetsToLL_M-800to1000                                                   
    DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8   # DYJetsToLL_M-1000to1500                                                  
    DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8   # DYJetsToLL_M-1500to2000                                                  
    DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8   # DYJetsToLL_M-2000to3000                                                  
)

sampleSubdir=(
    ./                       # DYJetsToLL_M-50                                                           
    ./                       # DYJetsToLL_M-50to100
    crab_DYLL_M100to200      # DYJetsToLL_M-100to200                                                    
    crab_DYLL_M100to200_ext  # DYJetsToLL_M-100to200_ext                                                
    ./                       # DYJetsToLL_M-200to400                                                    
    ./                       # DYJetsToLL_M-400to500AA                                                  
    ./                       # DYJetsToLL_M-500to700                                                    
    ./                       # DYJetsToLL_M-700to800                                                    
    ./                       # DYJetsToLL_M-800to1000                                                   
    ./                       # DYJetsToLL_M-1000to1500                                                  
    ./                       # DYJetsToLL_M-1500to2000                                                  
    ./                       # DYJetsToLL_M-2000to3000                                                  
)

numberOfSections=(
    1 # DYJetsToLL_M-50 total files: 726                                                                                                                             
    1 # DYJetsToLL_M-50to100 total files: 726
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

for index in ${!sampleShortName[*]}; do 
    echo "Submit jobs for sample ${sampleShortName[$index]} at ${sampleName[$index]}/${sampleSubdir[$index]} with numberOfSections=${numberOfSections[$index]} sections"
    condor_submit \
	ntuplesGeneralLocation=${ntuplesGeneralLocation} \
	sampleShortName=${sampleShortName[$index]} \
	sampleName=${sampleName[$index]} \
	sampleSubdir=${sampleSubdir[$index]} \
	numberOfSections=${numberOfSections[$index]} \
	filterDyDecayControlScript.condor
done
