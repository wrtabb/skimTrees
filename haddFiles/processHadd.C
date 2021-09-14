#include <TString.h>
#include <TSystem.h>

TString base_directory = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/wtabb/DrellYan_13TeV_2016/v2p6/";	

void processHadd(TString input_directory,TString output_file)
{
	TString file_location = base_directory;	
	file_location += input_directory;
	file_location += "/skims_EE/*.root";
	TString hadd_execute = "hadd -f ";
	hadd_execute += output_file;
	hadd_execute += " ";
	hadd_execute += file_location;
	gSystem->Exec(hadd_execute);	

	TString directory_out = "/store/user/wtabb/DrellYan_13TeV_2016/v2p6/";
	directory_out += "skims/skims_EE";

	//TString gridCopy = TString::Format("eval `scram unsetenv -sh`; gfal-copy -p file:////${PWD}/%s gsiftp://red-gridftp.unl.edu//user/uscms01/pnfs/unl.edu/data4/cms/%s",output_file,directory_out);

	//TString gridCopy = "eval `scram unsetenv -sh`; gfal-copy -p file:////${PWD}/";
	//gridCopy += output_file; 
	//gridCopy += " gsiftp://red-gridftp.unl.edu//user/uscms01/pnfs/unl.edu/data4/cms/";
	//gridCopy += directory_out;
	
	//gSystem->Exec(gridCopy);
//	TString rmFile = "rm ";
//	rmFile += output_file;
	//gSystem->Exec(rmFile);
}
