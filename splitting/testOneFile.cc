
{
 TString path = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6";
 TString sampleName = "DYLL_M1000to1500";
 TString subdir = "./";
 TString shortName = "ntuple_skim_sig_7.root";
 gROOT->ProcessLine(".L filterOnDyDecay.C");
 gROOT->ProcessLine("filterOnDyDecay(path,sampleName,subdir,shortName)");
}
