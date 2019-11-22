#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"

const bool useSmallEventNumber = false;
const int smallEventNumber = 1000;

const bool useSmallNumberOfFiles = true;
const int smallNumberOfFiles = 3;

const TString sampleBaseDir = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3";

//const TString sampleSubDir = "DoubleEG/crab_DoubleEG_RunB";

// Main function
void debug(TString sampleSubDir){

  // A few info messages
  if( useSmallNumberOfFiles)
    printf("Debug mode: will use only %d files\n", smallNumberOfFiles);
  if( useSmallEventNumber)
    printf("Debug mode: will process only %d events\n", smallEventNumber);

  //
  // Put together the list of all root files in the input sample directory
  //
  TString fullInputDirName = TString::Format("%s/%s", sampleBaseDir.Data(), sampleSubDir.Data());
  printf("Looking up all .root files from the directory\n    %s\n", fullInputDirName.Data());
  struct dirent *entry;
  DIR *dir = opendir(fullInputDirName.Data());
  if (dir == NULL) {
    printf("Directory name is invalid %s\n", fullInputDirName.Data());
    return;
  }

  vector<TString> shortFileNames;
  while ((entry = readdir(dir)) != NULL) {
    TString thisFileName = TString( entry->d_name );
    if( thisFileName.EndsWith(".root") )
      shortFileNames.push_back( thisFileName );
  }
  closedir(dir);

  // 
  // Set up the input TChain and the input tree
  //
  const TString rootDirName = "recoTree";
  const TString treeName = "DYTree";
  const TString treeNameFull = TString::Format("%s/%s",rootDirName.Data(), treeName.Data());
  TChain *inputChain = new TChain(treeNameFull);
  printf("Creating a chain of %d files\n", (int)shortFileNames.size());
  for(uint iFile = 0; iFile < shortFileNames.size(); iFile++){
    if( useSmallNumberOfFiles && (int)iFile > smallNumberOfFiles )
      break;
    TString fullFileName = TString::Format("%s/%s/%s", sampleBaseDir.Data(), sampleSubDir.Data(), 
					   shortFileNames.at(iFile).Data());
    inputChain->Add(fullFileName);
  }

  //
  // Define variables
  //
  static const int MPSIZE = 2000;
  // Global quantities
  int runNum;
  unsigned long long evtNum;
  int lumiBlock;
  double PUweight;
  int Nelectrons;
  int Nmuons;
  int nVertices;
  // -- PDf weights -- //
  std::vector< double > PDFWeights;
  std::vector< double > *pPDFWeights = &PDFWeights;
  // 
  // Define branches for input tree
  // 
  TBranch * b_runNum;
  TBranch * b_evtNum;
  TBranch * b_lumiBlock;
  TBranch * b_PUweight;
  TBranch * b_Nelectrons;
  TBranch * b_Nmuons;
  TBranch * b_nVertices;


  //
  // Set up branches for input tree
  //
  inputChain->SetBranchAddress("runNum"    , &runNum    , &b_runNum);
  inputChain->SetBranchAddress("evtNum"    , &evtNum    , &b_evtNum);
  inputChain->SetBranchAddress("lumiBlock" , &lumiBlock , &b_lumiBlock);
  inputChain->SetBranchAddress("PUweight"  , &PUweight  , &b_PUweight);
  inputChain->SetBranchAddress("Nelectrons", &Nelectrons, &b_Nelectrons);
  inputChain->SetBranchAddress("Nmuons"    , &Nmuons    , &b_Nmuons);
  inputChain->SetBranchAddress("nVertices"    , &nVertices    , &b_nVertices);



  Long64_t nEntries = inputChain->GetEntries();
  Long64_t nEvents = nEntries;
  if( useSmallEventNumber )
    nEvents = smallEventNumber;

  printf("Start the event loop over %lld events\n", nEvents);
  for(Long64_t iEvent = 0; iEvent < nEvents; iEvent++){
    inputChain->GetEntry(iEvent);
    if( iEvent%(nEvents/100) == 0 ){
      printf("\rLooping over events progress %.1f%%", (iEvent*100./nEvents)); fflush(stdout);
    }
  }
  printf("\rLooping over events completed               \n");

  delete inputChain;

  return;
}
