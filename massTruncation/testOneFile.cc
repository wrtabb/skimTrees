#include "EnumType.h"

{
 TString path = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6";
 TString sampleName = "ttbar";
 TString subdir = "";
 TString suffix = "_trunc";
 SampleType sampletype = SAMPLE_TT;
 TString shortName = "ntuple_skim_96.root";
 gROOT->ProcessLine(".L filterOnGenMass.C");
 gROOT->ProcessLine("filterOnGenMass(path,sampleName,subdir,shortName,suffix,sampletype)");
}
