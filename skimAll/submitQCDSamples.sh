#!/usr/bin/env bash

ntuplesGeneralLocation="/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6"
skimTag="MuMu"

# This name will be part of log file names, so it should be appropriate
sampleShortName=(
	QCDMuEnriched_Pt15to20
	QCDMuEnriched_Pt20to30
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

sampleLocation=(
	QCDMuEnriched_Pt15to20
	QCDMuEnriched_Pt20to30
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

# Choose number of sections to be appropriate for the total
# number and size of input ntuple files
# roughly 1 section per 100 files rounded up
numberOfSections=(
	1 # QCDMuEnriched_Pt15to20		22
	2 # QCDMuEnriched_Pt20to30		152
	4 # QCDMuEnriched_Pt30to50		302
	1 # QCDMuEnriched_Pt50to80		96
	2 # QCDMuEnriched_Pt80to120		146
	2 # QCDMuEnriched_Pt80to120_ext1		113
	1 # QCDMuEnriched_Pt120to170		45
	2 # QCDMuEnriched_Pt120to170_backup	137
	1 # QCDMuEnriched_Pt170to300		53
	4 # QCDMuEnriched_Pt170to300_backup	383
	1 # QCDMuEnriched_Pt170to300_ext1		58
	1 # QCDMuEnriched_Pt300to470		67
	2 # QCDMuEnriched_Pt300to470_ext1		128
	2 # QCDMuEnriched_Pt300to470_ext2		169
	1 # QCDMuEnriched_Pt470to600		32
	1 # QCDMuEnriched_Pt600to800		32
	2 # QCDMuEnriched_Pt600to800_backup	189
	1 # QCDMuEnriched_Pt600to800_ext1		50
	1 # QCDMuEnriched_Pt800to1000		35
	1 # QCDMuEnriched_Pt800to1000_ext1	50
	1 # QCDMuEnriched_Pt800to1000_ext2	76
	1 # QCDMuEnriched_Pt1000toInf		67
	2 # QCDMuEnriched_Pt1000toInf_ext1	166
 )	

# For MC we want usually to preserve the event count by
# saving info for each event, even if it is minimal info, because
# we need to know the event count for sample normalizations (use true).
# For data we can drop events of no interest (use false).
preserveEventCount=(
	true	# QCDMuEnriched_Pt15to20
	true	# QCDMuEnriched_Pt30to50
	true	# QCDMuEnriched_Pt50to80
	true	# QCDMuEnriched_Pt80to120
	true	# QCDMuEnriched_Pt80to120_ext1
	true	# QCDMuEnriched_Pt120to170
	true	# QCDMuEnriched_Pt120to170_backup
	true	# QCDMuEnriched_Pt170to300
	true	# QCDMuEnriched_Pt170to300_backup
	true	# QCDMuEnriched_Pt170to300_ext1
	true	# QCDMuEnriched_Pt300to470
	true	# QCDMuEnriched_Pt300to470_ext1
	true	# QCDMuEnriched_Pt300to470_ext2
	true	# QCDMuEnriched_Pt470to600
	true	# QCDMuEnriched_Pt600to800
	true	# QCDMuEnriched_Pt600to800_backup
	true	# QCDMuEnriched_Pt600to800_ext1
	true	# QCDMuEnriched_Pt800to1000
	true	# QCDMuEnriched_Pt800to1000_ext1
	true	# QCDMuEnriched_Pt800to1000_ext2
	true	# QCDMuEnriched_Pt1000toInf
	true	# QCDMuEnriched_Pt1000toInf_ext1
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
