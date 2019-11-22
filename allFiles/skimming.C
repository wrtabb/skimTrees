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

enum SaveLevel {
  LEVEL_NONE,
  // Minimal: event#, run#, lumi#
  // This level is needed to preserve the fact that event is recorded but nothing else
  LEVEL_MIN,
  // Reduced reco: all useful event-level info and reco-level electron quantities
  // This 
  LEVEL_REDUCED_RECO, 
  // Reduced reco and gen: all useful event-level and reco-level electron quantities, 
  // most of gen-level info
  LEVEL_REDUCED_RECO_AND_GEN
};

enum SampleType {DATA, 
		 MC_SIGNAL_EE, 
		 MC_BG_TAUTAU, MC_BG_TTLOWMASS,  MC_BG_GENERIC};

const TString sampleBaseDir = "/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3";

//const SampleType sampleType = DATA;
//const TString sampleSubDir = "DoubleEG/crab_DoubleEG_RunB";

// Main function
void reduceNtuples(TString sampleSubDir, SampleType sampleType){

  // A few info messages
  if( useSmallEventNumber)
    printf("Debug mode: will process only %d events\n", smallEventNumber);

  // Figure out what is the level of saving information
  SaveLevel saveLevel = LEVEL_NONE;
  if( sampleType == DATA ){
    saveLevel = LEVEL_REDUCED_RECO;
  }else if( sampleType == MC_SIGNAL_EE ){
    saveLevel = LEVEL_REDUCED_RECO_AND_GEN;
  }else if( sampleType == MC_BG_TAUTAU || sampleType == MC_BG_TTLOWMASS
	    || sampleType == MC_BG_GENERIC ){
    saveLevel == LEVEL_REDUCED_RECO;
  }else{
    printf("Unknown sample type, exiting");
    return;
  }

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
  //for(uint iFile = 0; iFile < shortFileNames.size(); iFile++){
  for(uint iFile = 1200; iFile < shortFileNames.size(); iFile++){
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

  // Trigger quantities
  int HLT_ntrig;
  int HLT_trigType[MPSIZE];
  int HLT_trigFired[MPSIZE];
  std::vector<std::string> HLT_trigName;
  std::vector<std::string> *pHLT_trigName = &HLT_trigName;

  // Electron quantities
  double Electron_Energy[MPSIZE];
  double Electron_pT[MPSIZE];
  double Electron_Px[MPSIZE];
  double Electron_Py[MPSIZE];
  double Electron_Pz[MPSIZE];
  double Electron_eta[MPSIZE];
  double Electron_phi[MPSIZE];
  int Electron_charge[MPSIZE];
  double Electron_etaSC[MPSIZE];
  double Electron_phiSC[MPSIZE];
  double Electron_dxy[MPSIZE];
  double Electron_dz[MPSIZE];
  double Electron_EnergySC[MPSIZE];
  double Electron_etSC[MPSIZE];
  bool Electron_passMediumID[MPSIZE];
  // GEN quantities
  int GENnPair;
  double GENLepton_phi[MPSIZE];
  double GENLepton_eta[MPSIZE];
  double GENLepton_pT[MPSIZE];
  double GENLepton_Px[MPSIZE];
  double GENLepton_Py[MPSIZE];
  double GENLepton_Pz[MPSIZE];
  double GENLepton_E[MPSIZE];
  double GENLepton_mother[MPSIZE];
  double GENLepton_mother_pT[MPSIZE];
  int GENLepton_charge[MPSIZE];
  int GENLepton_status[MPSIZE];
  int GENLepton_ID[MPSIZE];
  int GENLepton_isPrompt[MPSIZE];
  int GENLepton_isPromptFinalState[MPSIZE];
  int GENLepton_isTauDecayProduct[MPSIZE];
  int GENLepton_isPromptTauDecayProduct[MPSIZE];
  int GENLepton_isDirectPromptTauDecayProductFinalState[MPSIZE];
  int GENLepton_isHardProcess[MPSIZE];
  int GENLepton_isLastCopy[MPSIZE];
  int GENLepton_isLastCopyBeforeFSR[MPSIZE];
  int GENLepton_isPromptDecayed[MPSIZE];
  int GENLepton_isDecayedLeptonHadron[MPSIZE];
  int GENLepton_fromHardProcessBeforeFSR[MPSIZE];
  int GENLepton_fromHardProcessDecayed[MPSIZE];
  int GENLepton_fromHardProcessFinalState[MPSIZE];
  int GENLepton_isMostlyLikePythia6Status3[MPSIZE];
  double GENEvt_weight;
  double GENEvt_QScale;
  double GENEvt_x1;
  double GENEvt_x2;
  double GENEvt_alphaQCD;
  double GENEvt_alphaQED;

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

  // Trigger quantities
  TBranch * b_HLT_ntrig;
  TBranch * b_HLT_trigType;
  TBranch * b_HLT_trigFired;

  // Electron quantities
  TBranch *  b_Electron_Energy;
  TBranch *  b_Electron_pT;
  TBranch *  b_Electron_Px;
  TBranch *  b_Electron_Py;
  TBranch *  b_Electron_Pz;
  TBranch *  b_Electron_eta;
  TBranch *  b_Electron_phi;
  TBranch *  b_Electron_charge;
  TBranch *  b_Electron_etaSC;
  TBranch *  b_Electron_phiSC;
  TBranch *  b_Electron_dxy;
  TBranch *  b_Electron_dz;
  TBranch *  b_Electron_EnergySC;
  TBranch *  b_Electron_etSC;
  TBranch *  b_Electron_passMediumID;

  // GEN quantities
  TBranch *  b_GENnPair;
  TBranch *  b_GENLepton_phi;
  TBranch *  b_GENLepton_eta;
  TBranch *  b_GENLepton_pT;
  TBranch *  b_GENLepton_Px;
  TBranch *  b_GENLepton_Py;
  TBranch *  b_GENLepton_Pz;
  TBranch *  b_GENLepton_E;
  TBranch *  b_GENLepton_mother;
  TBranch *  b_GENLepton_mother_pT;
  TBranch *  b_GENLepton_charge;
  TBranch *  b_GENLepton_status;
  TBranch *  b_GENLepton_ID;
  TBranch *  b_GENLepton_isPrompt;
  TBranch *  b_GENLepton_isPromptFinalState;
  TBranch *  b_GENLepton_isTauDecayProduct;
  TBranch *  b_GENLepton_isPromptTauDecayProduct;
  TBranch *  b_GENLepton_isDirectPromptTauDecayProductFinalState;
  TBranch *  b_GENLepton_isHardProcess;
  TBranch *  b_GENLepton_isLastCopy;
  TBranch *  b_GENLepton_isLastCopyBeforeFSR;
  TBranch *  b_GENLepton_isPromptDecayed;
  TBranch *  b_GENLepton_isDecayedLeptonHadron;
  TBranch *  b_GENLepton_fromHardProcessBeforeFSR;
  TBranch *  b_GENLepton_fromHardProcessDecayed;
  TBranch *  b_GENLepton_fromHardProcessFinalState;
  TBranch *  b_GENLepton_isMostlyLikePythia6Status3;
  TBranch *  b_GENEvt_weight;
  TBranch *  b_GENEvt_QScale;
  TBranch *  b_GENEvt_x1;
  TBranch *  b_GENEvt_x2;
  TBranch *  b_GENEvt_alphaQCD;
  TBranch *  b_GENEvt_alphaQED;

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

  inputChain->SetBranchAddress("HLT_ntrig", &HLT_ntrig, &b_HLT_ntrig);
  inputChain->SetBranchAddress("HLT_trigType", &HLT_trigType, &b_HLT_trigType);
  inputChain->SetBranchAddress("HLT_trigFired", &HLT_trigFired, &b_HLT_trigFired);
  inputChain->SetBranchAddress("HLT_trigName", &pHLT_trigName);

  if( MC_SIGNAL )
    inputChain->SetBranchAddress("PDFWeights", &pPDFWeights);

  // Electron quantities
  inputChain->SetBranchAddress("Electron_Energy"      ,&Electron_Energy      , &b_Electron_Energy      );
  inputChain->SetBranchAddress("Electron_pT"          ,&Electron_pT          , &b_Electron_pT          );
  inputChain->SetBranchAddress("Electron_Px"          ,&Electron_Px          , &b_Electron_Px          );
  inputChain->SetBranchAddress("Electron_Py"          ,&Electron_Py          , &b_Electron_Py          );
  inputChain->SetBranchAddress("Electron_Pz"          ,&Electron_Pz          , &b_Electron_Pz          );
  inputChain->SetBranchAddress("Electron_eta"         ,&Electron_eta         , &b_Electron_eta         );
  inputChain->SetBranchAddress("Electron_phi"         ,&Electron_phi         , &b_Electron_phi         );
  inputChain->SetBranchAddress("Electron_charge"      ,&Electron_charge      , &b_Electron_charge      );
  inputChain->SetBranchAddress("Electron_etaSC"       ,&Electron_etaSC       , &b_Electron_etaSC       );
  inputChain->SetBranchAddress("Electron_phiSC"       ,&Electron_phiSC       , &b_Electron_phiSC       );
  inputChain->SetBranchAddress("Electron_dxy"         ,&Electron_dxy         , &b_Electron_dxy         );
  inputChain->SetBranchAddress("Electron_dz"          ,&Electron_dz          , &b_Electron_dz          );
  inputChain->SetBranchAddress("Electron_EnergySC"    ,&Electron_EnergySC    , &b_Electron_EnergySC    );
  inputChain->SetBranchAddress("Electron_etSC"        ,&Electron_etSC        , &b_Electron_etSC        );
  inputChain->SetBranchAddress("Electron_passMediumID",&Electron_passMediumID, &b_Electron_passMediumID);
  if( sampleType == MC_SIGNAL ){
    // GEN quantities
    inputChain->SetBranchAddress("GENnPair"                                         ,&GENnPair                                         , &b_GENnPair                                         );
    inputChain->SetBranchAddress("GENLepton_phi"                                    ,&GENLepton_phi                                    , &b_GENLepton_phi                                    );
    inputChain->SetBranchAddress("GENLepton_eta"                                    ,&GENLepton_eta                                    , &b_GENLepton_eta                                    );
    inputChain->SetBranchAddress("GENLepton_pT"                                     ,&GENLepton_pT                                     , &b_GENLepton_pT                                     );
    inputChain->SetBranchAddress("GENLepton_Px"                                     ,&GENLepton_Px                                     , &b_GENLepton_Px                                     );
    inputChain->SetBranchAddress("GENLepton_Py"                                     ,&GENLepton_Py                                     , &b_GENLepton_Py                                     );
    inputChain->SetBranchAddress("GENLepton_Pz"                                     ,&GENLepton_Pz                                     , &b_GENLepton_Pz                                     );
    inputChain->SetBranchAddress("GENLepton_E"                                      ,&GENLepton_E                                      , &b_GENLepton_E                                      );
    inputChain->SetBranchAddress("GENLepton_mother"                                 ,&GENLepton_mother                                 , &b_GENLepton_mother                                 );
    inputChain->SetBranchAddress("GENLepton_mother_pT"                              ,&GENLepton_mother_pT                              , &b_GENLepton_mother_pT                              );
    inputChain->SetBranchAddress("GENLepton_charge"                                 ,&GENLepton_charge                                 , &b_GENLepton_charge                                 );
    inputChain->SetBranchAddress("GENLepton_status"                                 ,&GENLepton_status                                 , &b_GENLepton_status                                 );
    inputChain->SetBranchAddress("GENLepton_ID"                                     ,&GENLepton_ID                                     , &b_GENLepton_ID                                     );
    inputChain->SetBranchAddress("GENLepton_isPrompt"                               ,&GENLepton_isPrompt                               , &b_GENLepton_isPrompt                               );
    inputChain->SetBranchAddress("GENLepton_isPromptFinalState"                     ,&GENLepton_isPromptFinalState                     , &b_GENLepton_isPromptFinalState                     );
    inputChain->SetBranchAddress("GENLepton_isTauDecayProduct"                      ,&GENLepton_isTauDecayProduct                      , &b_GENLepton_isTauDecayProduct                      );
    inputChain->SetBranchAddress("GENLepton_isPromptTauDecayProduct"                ,&GENLepton_isPromptTauDecayProduct                , &b_GENLepton_isPromptTauDecayProduct                );
    inputChain->SetBranchAddress("GENLepton_isDirectPromptTauDecayProductFinalState",&GENLepton_isDirectPromptTauDecayProductFinalState, &b_GENLepton_isDirectPromptTauDecayProductFinalState);
    inputChain->SetBranchAddress("GENLepton_isHardProcess"                          ,&GENLepton_isHardProcess                          , &b_GENLepton_isHardProcess                          );
    inputChain->SetBranchAddress("GENLepton_isLastCopy"                             ,&GENLepton_isLastCopy                             , &b_GENLepton_isLastCopy                             );
    inputChain->SetBranchAddress("GENLepton_isLastCopyBeforeFSR"                    ,&GENLepton_isLastCopyBeforeFSR                    , &b_GENLepton_isLastCopyBeforeFSR                    );
    inputChain->SetBranchAddress("GENLepton_isPromptDecayed"                        ,&GENLepton_isPromptDecayed                        , &b_GENLepton_isPromptDecayed                        );
    inputChain->SetBranchAddress("GENLepton_isDecayedLeptonHadron"                  ,&GENLepton_isDecayedLeptonHadron                  , &b_GENLepton_isDecayedLeptonHadron                  );
    inputChain->SetBranchAddress("GENLepton_fromHardProcessBeforeFSR"               ,&GENLepton_fromHardProcessBeforeFSR               , &b_GENLepton_fromHardProcessBeforeFSR               );
    inputChain->SetBranchAddress("GENLepton_fromHardProcessDecayed"                 ,&GENLepton_fromHardProcessDecayed                 , &b_GENLepton_fromHardProcessDecayed                 );
    inputChain->SetBranchAddress("GENLepton_fromHardProcessFinalState"              ,&GENLepton_fromHardProcessFinalState              , &b_GENLepton_fromHardProcessFinalState              );
    inputChain->SetBranchAddress("GENLepton_isMostlyLikePythia6Status3"             ,&GENLepton_isMostlyLikePythia6Status3             , &b_GENLepton_isMostlyLikePythia6Status3             );
    inputChain->SetBranchAddress("GENEvt_weight"                                    ,&GENEvt_weight                                    , &b_GENEvt_weight                                    );
    inputChain->SetBranchAddress("GENEvt_QScale"                                    ,&GENEvt_QScale                                    , &b_GENEvt_QScale                                    );
    inputChain->SetBranchAddress("GENEvt_x1"                                        ,&GENEvt_x1                                        , &b_GENEvt_x1                                        );
    inputChain->SetBranchAddress("GENEvt_x2"                                        ,&GENEvt_x2                                        , &b_GENEvt_x2                                        );
    inputChain->SetBranchAddress("GENEvt_alphaQCD"                                  ,&GENEvt_alphaQCD                                  , &b_GENEvt_alphaQCD                                  );
    inputChain->SetBranchAddress("GENEvt_alphaQED"                                  ,&GENEvt_alphaQED                                  , &b_GENEvt_alphaQED                                  );
  }

  // Note: we cannot write directly to hadoop, the file system does not support
  // writing of a root file from a script. So instead, we create it locally
  // and later copy it.
  TString fileNameOutTmp = "test.root";
  printf("Create a temporary skim file locally\n");
  TFile* fout = new TFile(fileNameOutTmp, "RECREATE");
  TDirectory *dirOut = fout->mkdir(rootDirName);
  dirOut->cd();
  TTree* treeOut = new TTree(treeName, "Skimmed tree");

  // Configure the tree
  treeOut->Branch("runNum",&runNum,"runNum/I");
  treeOut->Branch("evtNum",&evtNum,"evtNum/l");
  treeOut->Branch("lumiBlock",&lumiBlock,"lumiBlock/I");
  treeOut->Branch("PUweight",&PUweight,"PUweight/D");
  treeOut->Branch("Nelectrons", &Nelectrons,"Nelectrons/I");
  treeOut->Branch("Nmuons", &Nmuons,"Nmuons/I");
  treeOut->Branch("nVertices",&nVertices,"nVertices/I");

  // if( sampleType == MC_SIGNAL )
  //    treeOut->Branch("PDFWeights", &PDFWeights);

  // Trigger quantities
  treeOut->Branch("HLT_ntrig"     , &HLT_ntrig,"HLT_ntrig/I");
  treeOut->Branch("HLT_trigType" , &HLT_trigType,"HLT_trigType[HLT_ntrig]/I");
  treeOut->Branch("HLT_trigFired", &HLT_trigFired,"HLT_trigFired[HLT_ntrig]/I");
  treeOut->Branch("HLT_trigName"  , &HLT_trigName);

  treeOut->Branch("Electron_Energy", &Electron_Energy, "Electron_Energy[Nelectrons]/D");
  treeOut->Branch("Electron_pT", &Electron_pT, "Electron_pT[Nelectrons]/D");
  treeOut->Branch("Electron_Px", &Electron_Px, "Electron_Px[Nelectrons]/D");
  treeOut->Branch("Electron_Py", &Electron_Py, "Electron_Py[Nelectrons]/D");
  treeOut->Branch("Electron_Pz", &Electron_Pz, "Electron_Pz[Nelectrons]/D");
  treeOut->Branch("Electron_eta", &Electron_eta, "Electron_eta[Nelectrons]/D");
  treeOut->Branch("Electron_phi", &Electron_phi, "Electron_phi[Nelectrons]/D");
  treeOut->Branch("Electron_charge", &Electron_charge, "Electron_charge[Nelectrons]/I");
  treeOut->Branch("Electron_etaSC", &Electron_etaSC, "Electron_etaSC[Nelectrons]/D");
  treeOut->Branch("Electron_phiSC", &Electron_phiSC, "Electron_phiSC[Nelectrons]/D");
  treeOut->Branch("Electron_dxy", &Electron_dxy, "Electron_dxy[Nelectrons]/D");
  treeOut->Branch("Electron_dz", &Electron_dz, "Electron_dz[Nelectrons]/D");
  treeOut->Branch("Electron_EnergySC", &Electron_EnergySC, "Electron_EnergySC[Nelectrons]/D");
  treeOut->Branch("Electron_etSC", &Electron_etSC, "Electron_etSC[Nelectrons]/D");
  treeOut->Branch("Electron_passMediumID", &Electron_passMediumID, "Electron_passMediumID[Nelectrons]/O");

  if( sampleType == MC_SIGNAL ){
    treeOut->Branch("GENnPair",&GENnPair,"GENnPair/I");
    treeOut->Branch("GENLepton_phi", &GENLepton_phi,"GENLepton_phi[GENnPair]/D");
    treeOut->Branch("GENLepton_eta", &GENLepton_eta,"GENLepton_eta[GENnPair]/D");
    treeOut->Branch("GENLepton_pT", &GENLepton_pT,"GENLepton_pT[GENnPair]/D");
    treeOut->Branch("GENLepton_Px", &GENLepton_Px,"GENLepton_Px[GENnPair]/D");
    treeOut->Branch("GENLepton_Py", &GENLepton_Py,"GENLepton_Py[GENnPair]/D");
    treeOut->Branch("GENLepton_Pz", &GENLepton_Pz,"GENLepton_Pz[GENnPair]/D");
    treeOut->Branch("GENLepton_E", &GENLepton_E,"GENLepton_E[GENnPair]/D");
    treeOut->Branch("GENLepton_mother", &GENLepton_mother,"GENLepton_mother[GENnPair]/D");
    treeOut->Branch("GENLepton_mother_pT", &GENLepton_mother_pT,"GENLepton_mother_pT[GENnPair]/D");
    treeOut->Branch("GENLepton_charge", &GENLepton_charge,"GENLepton_charge[GENnPair]/I");
    treeOut->Branch("GENLepton_status", &GENLepton_status,"GENLepton_status[GENnPair]/I");
    treeOut->Branch("GENLepton_ID", &GENLepton_ID,"GENLepton_ID[GENnPair]/I");
    treeOut->Branch("GENLepton_isPrompt", &GENLepton_isPrompt,"GENLepton_isPrompt[GENnPair]/I");
    treeOut->Branch("GENLepton_isPromptFinalState", &GENLepton_isPromptFinalState,"GENLepton_isPromptFinalState[GENnPair]/I");
    treeOut->Branch("GENLepton_isTauDecayProduct", &GENLepton_isTauDecayProduct,"GENLepton_isTauDecayProduct[GENnPair]/I");
    treeOut->Branch("GENLepton_isPromptTauDecayProduct", &GENLepton_isPromptTauDecayProduct,"GENLepton_isPromptTauDecayProduct[GENnPair]/I");
    treeOut->Branch("GENLepton_isDirectPromptTauDecayProductFinalState", &GENLepton_isDirectPromptTauDecayProductFinalState,"GENLepton_isDirectPromptTauDecayProductFinalState[GENnPair]/I");
    treeOut->Branch("GENLepton_isHardProcess",&GENLepton_isHardProcess,"GENLepton_isHardProcess[GENnPair]/I");
    treeOut->Branch("GENLepton_isLastCopy",&GENLepton_isLastCopy,"GENLepton_isLastCopy[GENnPair]/I");
    treeOut->Branch("GENLepton_isLastCopyBeforeFSR",&GENLepton_isLastCopyBeforeFSR,"GENLepton_isLastCopyBeforeFSR[GENnPair]/I");
    treeOut->Branch("GENLepton_isPromptDecayed",&GENLepton_isPromptDecayed,"GENLepton_isPromptDecayed[GENnPair]/I");
    treeOut->Branch("GENLepton_isDecayedLeptonHadron",&GENLepton_isDecayedLeptonHadron,"GENLepton_isDecayedLeptonHadron[GENnPair]/I");
    treeOut->Branch("GENLepton_fromHardProcessBeforeFSR",&GENLepton_fromHardProcessBeforeFSR,"GENLepton_fromHardProcessBeforeFSR[GENnPair]/I");
    treeOut->Branch("GENLepton_fromHardProcessDecayed",&GENLepton_fromHardProcessDecayed,"GENLepton_fromHardProcessDecayed[GENnPair]/I");
    treeOut->Branch("GENLepton_fromHardProcessFinalState",&GENLepton_fromHardProcessFinalState,"GENLepton_fromHardProcessFinalState[GENnPair]/I");
    treeOut->Branch("GENLepton_isMostlyLikePythia6Status3", &GENLepton_isMostlyLikePythia6Status3, "GENLepton_isMostlyLikePythia6Status3[GENnPair]/I");
    // treeOut->Branch("GENEvt_weight",&GENEvt_weight,"GENEvt_weight/D");
    // treeOut->Branch("GENEvt_QScale",&GENEvt_QScale,"GENEvt_QScale/D");
    // treeOut->Branch("GENEvt_x1",&GENEvt_x1,"GENEvt_x1/D");
    // treeOut->Branch("GENEvt_x2",&GENEvt_x2,"GENEvt_x2/D");
    // treeOut->Branch("GENEvt_alphaQCD",&GENEvt_alphaQCD,"GENEvt_alphaQCD/D");
    // treeOut->Branch("GENEvt_alphaQED",&GENEvt_alphaQED,"GENEvt_alphaQED/D");
  }
  Long64_t nEntries = inputChain->GetEntries();
  Long64_t nEvents = nEntries;
  if( useSmallEventNumber )
    nEvents = smallEventNumber;

  printf("Start the event loop over %lld events\n", nEvents);
  for(Long64_t iEvent = 0; iEvent < nEvents; iEvent++){
    inputChain->GetEntry(iEvent);
    treeOut->Fill();
    if( iEvent%(nEvents/100) == 0 ){
      printf("\rLooping over events progress %.1f%%", (iEvent*100./nEvents)); fflush(stdout);
    }
  }
  printf("\rLooping over events completed               \n");

  treeOut->Write();
  delete inputChain;

  //
  // Set up output directory, file name, and move the skim file there
  //
  TString dirNameOut = TString::Format("%s/%s/skims", sampleBaseDir.Data(), sampleSubDir.Data());
  printf("Create output directory\n %s\n", dirNameOut.Data());
  // The following directory creation comes from sys/stat.h:
  mode_t dirMode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // Supposed to result in drwxr-xr-x. directory permissions
  mkdir(dirNameOut.Data(), dirMode);
  // Create short file name for the skim: take the subdirectory and replace all / with _:
  TString shortFileNameOut = sampleSubDir;
  shortFileNameOut.ReplaceAll("/","_");
  TString fileNameOut = TString::Format("%s/%s_skim.root", dirNameOut.Data(), shortFileNameOut.Data());
  if( useSmallNumberOfFiles || useSmallEventNumber )
    fileNameOut = TString::Format("%s/%s_skim_debug.root", dirNameOut.Data(), shortFileNameOut.Data());
  // Copy the output skim into the appropriate location
  fout->Close();
  // Copy the file to the final location and remove the temporary local file
  printf("Create output file\n   %s\n", fileNameOut.Data());
  TString copyCommand = TString::Format("cp %s %s", fileNameOutTmp.Data(), fileNameOut.Data());
  gSystem->Exec(copyCommand.Data());
  TString removeCommand = TString::Format("rm %s", fileNameOutTmp.Data());
  gSystem->Exec(removeCommand.Data());

  return;
}
