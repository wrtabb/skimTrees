#!/usr/bin/env python

import math

sectionNumber = int('1')
numberOfSections = int('3')
rootfiles = [
'skim_1.root'
'skim_10.root'
'skim_11.root'
'skim_12.root'
'skim_2.root'
'skim_3.root'
'skim_4.root'
'skim_5.root'
'skim_6.root'
'skim_7.root'
'skim_8.root'
'skim_9.root'
]

numberOfFiles = len(rootfiles)
filesPerSection = math.ceil( numberOfFiles / numberOfSections )
fileIndexBegin = sectionNumber * filesPerSection

for fileIndex in range(fileIndexBegin,numberOfFiles):
    print rootfiles[fileIndex]
