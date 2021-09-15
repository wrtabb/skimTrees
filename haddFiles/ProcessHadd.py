#!/usr/bin/env python

import sys
import subprocess

if (len(sys.argv)!=4) :
    print("ERROR: this script expects exactly 3 arguments")
    print("Variables: "+sys.argv[1]+", "+sys.argv[2]+", "+sys.argv[3])
    sys.exit(0)

file_location     = sys.argv[1]
output_file	  = sys.argv[2]

print("File location: "+file_location )
print("Ouput file: "+output_file)

scriptSpecs = 'processHadd.C+('+ str(file_location) + ','+str(output_file)+')'

print(scriptSpecs)
rootCommand = ['root']
rootCommand.append('-b')
rootCommand.append('-q')
rootCommand.append(scriptSpecs)

(out,err) = subprocess.Popen(rootCommand,stdout=subprocess.PIPE).communicate()
print(out)
print("Any errors?")
print(err)
