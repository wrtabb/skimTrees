#!/usr/bin/env python

import sys
import os
import glob
import math
import subprocess

# Note that the list of arguments always has the script name itself
# as the first element
if ( len(sys.argv) != 7 ) :
    print "ERROR: this script expects exactly 6 arguments"
    sys.exit(0)

generalNtupleLocation = sys.argv[1]
sampleToProcessDir    = sys.argv[2]
skimTag               = sys.argv[3]
sectionNumber         = int(sys.argv[4])
numberOfSections      = int(sys.argv[5])
preserveEventCount    = sys.argv[6].lower() == 'true'

print "General location of ntuples {}".format(generalNtupleLocation)
print "Location of the sample to process {}".format(sampleToProcessDir)
print "Skim tag           {}".format(skimTag)
print "Section number     {}".format(sectionNumber)
print "Number of sections {}".format(numberOfSections)
print "Preserve event count {}".format(preserveEventCount)

# Construct name of the input directory and check if the input directory exists
fullSampleDirName = generalNtupleLocation + "/" + sampleToProcessDir
if( os.path.isdir(fullSampleDirName) ):
    print "Input directory exists, ok"
else:
    print "ERROR: Input directory is not found, exiting"
    sys.exit(0)

# Construct the list of files to run on
fullFileNamePattern = fullSampleDirName + "/*.root"
rootfiles = []
for file in glob.glob(fullFileNamePattern):
    rootfiles.append(file)
numberOfFiles = len(rootfiles)
print "Found {} files".format(numberOfFiles)

# we will use the subset of files that corresponds to the section number
filesPerSection = int(math.ceil( (1.0*numberOfFiles) / numberOfSections)) # round upward
fileIndexBegin  = sectionNumber * filesPerSection
fileIndexEnd    = fileIndexBegin + filesPerSection
if( fileIndexEnd > numberOfFiles ):
    fileIndexEnd = numberOfFiles;

# Run skimming for the files in this section one file at a time
for fileIndex in range(fileIndexBegin, fileIndexEnd):
    thisFile = rootfiles[fileIndex]
    print "\nProcess file {}\n".format(thisFile)
    dirName = os.path.dirname( thisFile )
    shortFileName = os.path.basename( thisFile )
    scriptSpecs = 'skimGoodEvents.C+(\"' + dirName + '\",\"' + shortFileName + '\",\"' + skimTag + '\",' + str(preserveEventCount).lower() + ')'
    rootCommand = ['root']
    rootCommand.append('-b')
    rootCommand.append('-q')
    rootCommand.append(scriptSpecs)
    #print(rootCommand)
    (out,err) = subprocess.Popen(rootCommand,
                                 stdout=subprocess.PIPE).communicate()
    print(out)
    print("Any errors?")
    print(err)

