#!/usr/bin/env python

import sys
import os
import glob
import math
import subprocess

# Note that the list of arguments always has the script name itself
# as the first element
if ( len(sys.argv) != 8 ) :
    print "ERROR: this script expects exactly 7 arguments"
    sys.exit(0)

generalNtupleLocation = sys.argv[1]
sampleToProcessDir    = sys.argv[2]
sampleSubdir          = sys.argv[3]
sampleSuffixOut       = sys.argv[4]
sampleType            = sys.argv[5]
sectionNumber         = int(sys.argv[6])
numberOfSections      = int(sys.argv[7])

print "General location of ntuples {}".format(generalNtupleLocation)
print "Name of the sample to process {}".format(sampleToProcessDir)
print "Subdirectory name of the input sample {}".format(sampleSubdir)
print "Suffix of the out sample {}".format(sampleSuffixOut)
print "Sample type {}"             .format(sampleType)
print "Section number     {}".format(sectionNumber)
print "Number of sections {}".format(numberOfSections)

# Construct name of the input directory and check if the input directory exists
fullSampleDirName = generalNtupleLocation + "/" + sampleToProcessDir + "/" + sampleSubdir
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
    scriptSpecs = 'filterOnGenMass.C+(\"' + generalNtupleLocation \
    + '\",\"' + sampleToProcessDir \
    + '\",\"' + sampleSubdir \
    + '\",\"' + shortFileName \
    + '\",\"' + sampleSuffixOut \
    + '\",' + sampleType + ')'
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

