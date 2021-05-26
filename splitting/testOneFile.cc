
{
	TString path = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6";
	TString sampleName = "DYLL_M1500to2000";
	TString subdir = "./";
	int nFiles = 23;
	TString shortName;
	for(int i=20;i<nFiles;i++){
		shortName = "ntuple_skim_sig_";
		shortName += i;
		shortName += ".root";
		gROOT->ProcessLine(".L filterOnDyDecay.C");
		gROOT->ProcessLine("filterOnDyDecay(path,sampleName,subdir,shortName)");
	}
}
