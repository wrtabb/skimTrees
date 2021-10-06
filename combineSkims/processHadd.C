TString base_directory = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/";	

void processHadd(TString sample,TString output_file)
{
	TString file_location = base_directory;	
	file_location += sample;
	file_location += "/*.root";
	TString hadd_execute = "hadd -f ";
	hadd_execute += output_file;
	hadd_execute += ".root ";
	hadd_execute += file_location;
	gSystem->Exec(hadd_execute);	
}
