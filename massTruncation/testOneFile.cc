#include "EnumType.h"

{
	TString path = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6";
	vector<TString> sampleName = {
	       "ttbar",
	       "ttbar",
	       "ttbarBackup",
	       "ttbarBackup",
	       "ttbarBackup"
	};
	TString subdir = "";
	TString suffix = "_truncated";
	vector<SampleType> sampletype ={
		SAMPLE_TT,
		SAMPLE_TT,
		SAMPLE_TT,
		SAMPLE_TT,
		SAMPLE_TT
	};

	vector<TString> shortName = {
		"ntuple_skim_19.root",
		"ntuple_skim_546.root",
		"ntuple_skim_381.root",
		"ntuple_skim_831.root",
		"ntuple_skim_864.root"
	} ;
	gROOT->ProcessLine(".L filterOnGenMass.C");
	gROOT->ProcessLine("filterOnGenMass(path,sampleName.at(i),subdir,shortName.at(i),suffix,sampletype.at(i)");
}
