#include "haddDirectories.h"

void haddFiles()
{
	int nDirectories = file_list.size();
	
	for(int i=0;i<nDirectories;i++){
		TString file_location = base_directory;	
		file_location += file_list.at(i);
		file_location += "/skims_0001/*.root";
		TString hadd_execute = "hadd -f ";
		hadd_execute += output_list.at(i);
		hadd_execute += ".root ";
		hadd_execute += file_location;
		gSystem->Exec(hadd_execute);	
	}
}
