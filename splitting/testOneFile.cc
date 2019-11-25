
{
 TString path = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6";
 TString sampleName = "DYLL_M10to50";
 TString subdir = "v2";
 //TString shortName = "ntuple_skim_sig_56.root";
 TString shortName = "ntuple_skim_sig_111.root";
 gROOT->ProcessLine(".L filterOnDyDecay.C");
 gROOT->ProcessLine("filterOnDyDecay(path,sampleName,subdir,shortName)");
}
