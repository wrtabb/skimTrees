#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3/DYJetsToLL_allMasses_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8"

dirName=(
    DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/EE
)

pushd $ntuplesGeneralLocation

for index in ${!dirName[*]}; do 
    echo
    echo "Process ${dirName[$index]}"
    pushd ${dirName[$index]}
    ls -l *.root | wc -l
    mergedFileShortName=`echo ${dirName[$index]} | sed 's/\//_/g' `
    mergedFileName="/home/hep/ikrav/${mergedFileShortName}.root"
    hadd ${mergedFileName} *.root
    sleep 5
    echo "ls -l ${mergedFileName}"
    ls -rtl /home/hep/ikrav
    ls -l ${mergedFileName}
    #mkdir -p skims
    #mergedFileNewDir="skims/."
    #cp ${mergedFileName} ${mergedFileNewDir}
    #rm ${mergedFileName}
    popd
done

popd
