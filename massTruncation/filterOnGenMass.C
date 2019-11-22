#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "TLorentzVector.h"
#include "TPRegexp.h"


// Constants
const bool useSmallEventNumber = false;
const int smallEventNumber = 1000;

const TString rootDirName = "recoTree";
const TString treeName = "DYTree";
const TString treeNameFull = TString::Format("%s/%s",rootDirName.Data(), treeName.Data());

const int PDG_E = 11;
const int PDG_MU = 13;
const int PDG_TAU = 15;
const int PDG_TOP = 6;

// Declarations
enum SampleType {
  SAMPLE_DYJetsToLL,
  SAMPLE_TT
};

// Function to create all subdirectories on the way to the given file name
// if they don't exist.
int mkpath(char* file_path, mode_t mode);

// Main function
void filterOnGenMass(TString pathToNtupleArea,
		     TString sampleNameIn,
		     TString sampleSubdirIn,
		     TString shortFileNameIn,
		     TString sampleSuffixOut,
		     SampleType sampleType){

  if( sampleType != SAMPLE_DYJetsToLL && sampleType != SAMPLE_TT){
    printf("Unknown sample type requesting, exiting\n");
    return;
  }

  // A few info messages
  if( useSmallEventNumber)
    printf("Debug mode: will process only %d events\n", smallEventNumber);

  //
  // Open the input file and find the tree
  //
  TString fullFileNameIn = TString::Format("%s/%s/%s/%s", pathToNtupleArea.Data(), sampleNameIn.Data(),
					   sampleSubdirIn.Data(), shortFileNameIn.Data());
  printf("Open input file %s\n", fullFileNameIn.Data());
  TFile *fin = new TFile(fullFileNameIn);
  if( fin == 0 ){
    printf("Input file does not exist, tried %s\n", fullFileNameIn.Data());
    return;
  }
  TTree *treeIn = (TTree*)fin->Get(treeNameFull);
  if( treeIn == 0 ){
    printf("Input tree is not found in the file\n");
    return;
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
  int nVertices;

  // Pileup
  Int_t nPileUp;

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

  // GEN non-leptons
  int nGenOthers;
  double GenOthers_phi[MPSIZE];
  double GenOthers_eta[MPSIZE];
  double GenOthers_pT[MPSIZE];
  double GenOthers_Px[MPSIZE];
  double GenOthers_Py[MPSIZE];
  double GenOthers_Pz[MPSIZE];
  double GenOthers_E[MPSIZE];
  int GenOthers_ID[MPSIZE];
  int GenOthers_isHardProcess[MPSIZE];

  double _prefiringweight;
  double _prefiringweightup;
  double _prefiringweightdown;

  // 
  // Define branches for input tree
  // 
  TBranch * b_runNum;
  TBranch * b_evtNum;
  TBranch * b_lumiBlock;
  TBranch * b_PUweight;
  TBranch * b_Nelectrons;
  TBranch * b_nVertices;

  // Prefire Weights
  TBranch * b__prefiringweight;
  TBranch * b__prefiringweightup;
  TBranch * b__prefiringweightdown;

  // Pileup
  TBranch * b_nPileUp;

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

  // GEN other
  TBranch * b_nGenOthers;
  TBranch * b_GenOthers_phi;
  TBranch * b_GenOthers_eta;
  TBranch * b_GenOthers_pT;
  TBranch * b_GenOthers_Px;
  TBranch * b_GenOthers_Py;
  TBranch * b_GenOthers_Pz;
  TBranch * b_GenOthers_E ;
  TBranch * b_GenOthers_ID;
  TBranch * b_GenOthers_isHardProcess;

  //
  // Set up branches for input tree
  //
  treeIn->SetBranchAddress("_prefiringweight", &_prefiringweight,     &b__prefiringweight);
  treeIn->SetBranchAddress("_prefiringweightup", &_prefiringweightup,   &b__prefiringweightup);
  treeIn->SetBranchAddress("_prefiringweightdown", &_prefiringweightdown, &b__prefiringweightdown);

  treeIn->SetBranchAddress("runNum"    , &runNum    , &b_runNum);
  treeIn->SetBranchAddress("evtNum"    , &evtNum    , &b_evtNum);
  treeIn->SetBranchAddress("lumiBlock" , &lumiBlock , &b_lumiBlock);
  treeIn->SetBranchAddress("PUweight"  , &PUweight  , &b_PUweight);
  treeIn->SetBranchAddress("Nelectrons", &Nelectrons, &b_Nelectrons);
  treeIn->SetBranchAddress("nVertices"    , &nVertices    , &b_nVertices);

  treeIn->SetBranchAddress("nPileUp"   ,&nPileUp    , &b_nPileUp);

  treeIn->SetBranchAddress("HLT_ntrig", &HLT_ntrig, &b_HLT_ntrig);
  treeIn->SetBranchAddress("HLT_trigType", &HLT_trigType, &b_HLT_trigType);
  treeIn->SetBranchAddress("HLT_trigFired", &HLT_trigFired, &b_HLT_trigFired);
  treeIn->SetBranchAddress("HLT_trigName", &pHLT_trigName);

  // Electron quantities
  treeIn->SetBranchAddress("Electron_Energy"      ,&Electron_Energy      , &b_Electron_Energy      );
  treeIn->SetBranchAddress("Electron_pT"          ,&Electron_pT          , &b_Electron_pT          );
  treeIn->SetBranchAddress("Electron_Px"          ,&Electron_Px          , &b_Electron_Px          );
  treeIn->SetBranchAddress("Electron_Py"          ,&Electron_Py          , &b_Electron_Py          );
  treeIn->SetBranchAddress("Electron_Pz"          ,&Electron_Pz          , &b_Electron_Pz          );
  treeIn->SetBranchAddress("Electron_eta"         ,&Electron_eta         , &b_Electron_eta         );
  treeIn->SetBranchAddress("Electron_phi"         ,&Electron_phi         , &b_Electron_phi         );
  treeIn->SetBranchAddress("Electron_charge"      ,&Electron_charge      , &b_Electron_charge      );
  treeIn->SetBranchAddress("Electron_etaSC"       ,&Electron_etaSC       , &b_Electron_etaSC       );
  treeIn->SetBranchAddress("Electron_phiSC"       ,&Electron_phiSC       , &b_Electron_phiSC       );
  treeIn->SetBranchAddress("Electron_dxy"         ,&Electron_dxy         , &b_Electron_dxy         );
  treeIn->SetBranchAddress("Electron_dz"          ,&Electron_dz          , &b_Electron_dz          );
  treeIn->SetBranchAddress("Electron_EnergySC"    ,&Electron_EnergySC    , &b_Electron_EnergySC    );
  treeIn->SetBranchAddress("Electron_etSC"        ,&Electron_etSC        , &b_Electron_etSC        );
  treeIn->SetBranchAddress("Electron_passMediumID",&Electron_passMediumID, &b_Electron_passMediumID);

    // GEN quantities
  treeIn->SetBranchAddress("GENnPair"                                         ,&GENnPair                                         , &b_GENnPair                                         );
  treeIn->SetBranchAddress("GENLepton_phi"                                    ,&GENLepton_phi                                    , &b_GENLepton_phi                                    );
  treeIn->SetBranchAddress("GENLepton_eta"                                    ,&GENLepton_eta                                    , &b_GENLepton_eta                                    );
  treeIn->SetBranchAddress("GENLepton_pT"                                     ,&GENLepton_pT                                     , &b_GENLepton_pT                                     );
  treeIn->SetBranchAddress("GENLepton_Px"                                     ,&GENLepton_Px                                     , &b_GENLepton_Px                                     );
  treeIn->SetBranchAddress("GENLepton_Py"                                     ,&GENLepton_Py                                     , &b_GENLepton_Py                                     );
  treeIn->SetBranchAddress("GENLepton_Pz"                                     ,&GENLepton_Pz                                     , &b_GENLepton_Pz                                     );
  treeIn->SetBranchAddress("GENLepton_E"                                      ,&GENLepton_E                                      , &b_GENLepton_E                                      );
  treeIn->SetBranchAddress("GENLepton_mother"                                 ,&GENLepton_mother                                 , &b_GENLepton_mother                                 );
  treeIn->SetBranchAddress("GENLepton_mother_pT"                              ,&GENLepton_mother_pT                              , &b_GENLepton_mother_pT                              );
  treeIn->SetBranchAddress("GENLepton_charge"                                 ,&GENLepton_charge                                 , &b_GENLepton_charge                                 );
  treeIn->SetBranchAddress("GENLepton_status"                                 ,&GENLepton_status                                 , &b_GENLepton_status                                 );
  treeIn->SetBranchAddress("GENLepton_ID"                                     ,&GENLepton_ID                                     , &b_GENLepton_ID                                     );
  treeIn->SetBranchAddress("GENLepton_isPrompt"                               ,&GENLepton_isPrompt                               , &b_GENLepton_isPrompt                               );
  treeIn->SetBranchAddress("GENLepton_isPromptFinalState"                     ,&GENLepton_isPromptFinalState                     , &b_GENLepton_isPromptFinalState                     );
  treeIn->SetBranchAddress("GENLepton_isTauDecayProduct"                      ,&GENLepton_isTauDecayProduct                      , &b_GENLepton_isTauDecayProduct                      );
  treeIn->SetBranchAddress("GENLepton_isPromptTauDecayProduct"                ,&GENLepton_isPromptTauDecayProduct                , &b_GENLepton_isPromptTauDecayProduct                );
  treeIn->SetBranchAddress("GENLepton_isDirectPromptTauDecayProductFinalState",&GENLepton_isDirectPromptTauDecayProductFinalState, &b_GENLepton_isDirectPromptTauDecayProductFinalState);
  treeIn->SetBranchAddress("GENLepton_isHardProcess"                          ,&GENLepton_isHardProcess                          , &b_GENLepton_isHardProcess                          );
  treeIn->SetBranchAddress("GENLepton_isLastCopy"                             ,&GENLepton_isLastCopy                             , &b_GENLepton_isLastCopy                             );
  treeIn->SetBranchAddress("GENLepton_isLastCopyBeforeFSR"                    ,&GENLepton_isLastCopyBeforeFSR                    , &b_GENLepton_isLastCopyBeforeFSR                    );
  treeIn->SetBranchAddress("GENLepton_isPromptDecayed"                        ,&GENLepton_isPromptDecayed                        , &b_GENLepton_isPromptDecayed                        );
  treeIn->SetBranchAddress("GENLepton_isDecayedLeptonHadron"                  ,&GENLepton_isDecayedLeptonHadron                  , &b_GENLepton_isDecayedLeptonHadron                  );
  treeIn->SetBranchAddress("GENLepton_fromHardProcessBeforeFSR"               ,&GENLepton_fromHardProcessBeforeFSR               , &b_GENLepton_fromHardProcessBeforeFSR               );
  treeIn->SetBranchAddress("GENLepton_fromHardProcessDecayed"                 ,&GENLepton_fromHardProcessDecayed                 , &b_GENLepton_fromHardProcessDecayed                 );
  treeIn->SetBranchAddress("GENLepton_fromHardProcessFinalState"              ,&GENLepton_fromHardProcessFinalState              , &b_GENLepton_fromHardProcessFinalState              );
  treeIn->SetBranchAddress("GENLepton_isMostlyLikePythia6Status3"             ,&GENLepton_isMostlyLikePythia6Status3             , &b_GENLepton_isMostlyLikePythia6Status3             );
  treeIn->SetBranchAddress("GENEvt_weight"                                    ,&GENEvt_weight                                    , &b_GENEvt_weight                                    );
  treeIn->SetBranchAddress("GENEvt_QScale"                                    ,&GENEvt_QScale                                    , &b_GENEvt_QScale                                    );
  treeIn->SetBranchAddress("GENEvt_x1"                                        ,&GENEvt_x1                                        , &b_GENEvt_x1                                        );
  treeIn->SetBranchAddress("GENEvt_x2"                                        ,&GENEvt_x2                                        , &b_GENEvt_x2                                        );
  treeIn->SetBranchAddress("GENEvt_alphaQCD"                                  ,&GENEvt_alphaQCD                                  , &b_GENEvt_alphaQCD                                  );
  treeIn->SetBranchAddress("GENEvt_alphaQED"                                  ,&GENEvt_alphaQED                                  , &b_GENEvt_alphaQED                                  );

  // GEN other
  treeIn->SetBranchAddress("nGenOthers",    &nGenOthers,   &b_nGenOthers);
  treeIn->SetBranchAddress("GenOthers_phi", &GenOthers_phi,&b_GenOthers_phi);
  treeIn->SetBranchAddress("GenOthers_eta", &GenOthers_eta,&b_GenOthers_eta);
  treeIn->SetBranchAddress("GenOthers_pT",  &GenOthers_pT, &b_GenOthers_pT);
  treeIn->SetBranchAddress("GenOthers_Px",  &GenOthers_Px, &b_GenOthers_Px);
  treeIn->SetBranchAddress("GenOthers_Py",  &GenOthers_Py, &b_GenOthers_Py);
  treeIn->SetBranchAddress("GenOthers_Pz",  &GenOthers_Pz, &b_GenOthers_Pz);
  treeIn->SetBranchAddress("GenOthers_E",   &GenOthers_E,  &b_GenOthers_E );
  treeIn->SetBranchAddress("GenOthers_ID",  &GenOthers_ID, &b_GenOthers_ID);
  treeIn->SetBranchAddress("GenOthers_isHardProcess",&GenOthers_isHardProcess, &b_GenOthers_isHardProcess); 

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
  treeOut->Branch("nVertices",&nVertices,"nVertices/I");

  treeOut->Branch("_prefiringweight", &_prefiringweight,"_prefiringweight/D");
  treeOut->Branch("_prefiringweightup", &_prefiringweightup,"_prefiringweightup/D");
  treeOut->Branch("_prefiringweightdown", &_prefiringweightdown,"_prefiringweightdown/D");

  treeOut->Branch("nPileUp",&nPileUp,"nPileUp/I");

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
  treeOut->Branch("GENEvt_weight",&GENEvt_weight,"GENEvt_weight/D");
  treeOut->Branch("GENEvt_QScale",&GENEvt_QScale,"GENEvt_QScale/D");
  treeOut->Branch("GENEvt_x1",&GENEvt_x1,"GENEvt_x1/D");
  treeOut->Branch("GENEvt_x2",&GENEvt_x2,"GENEvt_x2/D");
  treeOut->Branch("GENEvt_alphaQCD",&GENEvt_alphaQCD,"GENEvt_alphaQCD/D");
  treeOut->Branch("GENEvt_alphaQED",&GENEvt_alphaQED,"GENEvt_alphaQED/D");
  
  // 
  // Loop over events
  //

  Long64_t nEntries = treeIn->GetEntries();
  Long64_t nEvents = nEntries;
  if( useSmallEventNumber )
    nEvents = smallEventNumber;

  printf("Start the event loop over %lld events\n", nEvents);
  for(Long64_t iEvent = 0; iEvent < nEvents; iEvent++){

    treeIn->GetEntry(iEvent);
    if( iEvent%(nEvents/100) == 0 ){
      printf("\rLooping over events progress %.1f%%", (iEvent*100./nEvents)); fflush(stdout);
    }


    // printf(" GENLep list:\n");
    if( sampleType == SAMPLE_DYJetsToLL ){
      // printf("  lepton %2d  ID=%4d  MO=%4.0f  isP=%d  isPFS=%d  isTauDP=%d  isPTauDP=%d isDPTauDPFS=%d isHP=%d fromHPFS=%d\n",
      // 	     iLep, GENLepton_ID[iLep], GENLepton_mother[iLep], GENLepton_isPrompt[iLep], GENLepton_isPromptFinalState[iLep],
      // 	     GENLepton_isTauDecayProduct[iLep], GENLepton_isPromptTauDecayProduct[iLep], GENLepton_isDirectPromptTauDecayProductFinalState[iLep],
      // 	     GENLepton_isHardProcess[iLep], GENLepton_fromHardProcessFinalState[iLep]);

      // Find the pair of leptons from hard process
      int idxGenLep1, idxGenLep2;
      idxGenLep1 = idxGenLep2 = -1;
      int nGenDileptons = 0;
      for(int kLep=0;kLep<GENnPair;kLep++){
	for(int lLep=kLep+1;lLep<GENnPair;lLep++){
	  // Require opposite signs
	  if(GENLepton_isHardProcess[kLep]==1 && GENLepton_isHardProcess[lLep]==1){
	    // Found a dielectron from hard process
	    idxGenLep1 = kLep;
	    idxGenLep2 = lLep;
	    nGenDileptons++;
	  }
	} // end inner loop over gen leptons
      } // end outer loop over gen leptons
      
      if( nGenDileptons != 1 ){
	printf("WARNING Odd event, have not found exactly one di-top from hard process\n");
      }
      
      // Compute invariant mass
      TLorentzVector lep1P4, lep2P4;
      lep1P4.SetPxPyPzE(GENLepton_Px[idxGenLep1], GENLepton_Py[idxGenLep1], 
			GENLepton_Pz[idxGenLep1], GENLepton_E[idxGenLep1]);
      lep2P4.SetPxPyPzE(GENLepton_Px[idxGenLep2], GENLepton_Py[idxGenLep2], 
			GENLepton_Pz[idxGenLep2], GENLepton_E[idxGenLep2]);
      double invMass = (lep1P4 + lep2P4).M();
      if( invMass < 100 ){
	treeOut->Fill();
      }
    } else if( sampleType == SAMPLE_TT ){

      // Find the pair of top quarks from hard process
      int idxGenTop1, idxGenTop2;
      idxGenTop1 = idxGenTop2 = -1;
      int nGenTops = 0;
      for(int kOther=0;kOther<nGenOthers;kOther++){
	for(int lOther=kOther+1;lOther<nGenOthers;lOther++){
	  if(GenOthers_isHardProcess[kOther]==1 && GenOthers_isHardProcess[lOther]==1
	     && abs(GenOthers_ID[kOther]) == PDG_TOP && abs(GenOthers_ID[lOther]) == PDG_TOP ){
	    // Found a dielectron from hard process
	    idxGenTop1 = kOther;
	    idxGenTop2 = lOther;
	    nGenTops++;
	  }
	} // end inner loop over gen leptons
      } // end outer loop over gen leptons
      
      if( nGenTops != 1 ){
	printf("WARNING Odd event, have not found exactly one di-top from hard process\n");
      }
      
      // Compute invariant mass
      TLorentzVector top1P4, top2P4;
      top1P4.SetPxPyPzE(GenOthers_Px[idxGenTop1], GenOthers_Py[idxGenTop1], 
			GenOthers_Pz[idxGenTop1], GenOthers_E[idxGenTop1]);
      top2P4.SetPxPyPzE(GenOthers_Px[idxGenTop2], GenOthers_Py[idxGenTop2], 
			GenOthers_Pz[idxGenTop2], GenOthers_E[idxGenTop2]);
      double invMass = (top1P4 + top2P4).M();
      if( invMass < 700 ){
	treeOut->Fill();
      }
    } // end if sample type

  }
  printf("\rLooping over events completed               \n");

  treeOut->Write();
  delete treeIn;
  fin->Close();

  //
  // Set up output directory, file name, and move the skim file there
  //
  TString sampleNameOut = sampleNameIn + sampleSuffixOut;
  TString dirNameOut = TString::Format("%s/%s/%s", pathToNtupleArea.Data(), 
				       sampleNameOut.Data(), sampleSubdirIn.Data());
  // TString Data() returns const char*, and here we need to lose const, so we copy
  // the content inro a regular char* in the next few lines.
  int length = strlen( dirNameOut.Data() );
  char *dirNameOutChars = new char[length +1]();
  strncpy(dirNameOutChars, dirNameOut.Data(), length); 
  printf("Create output directory\n %s\n", dirNameOutChars);
  // The following directory creation comes from sys/stat.h:
  mode_t dirMode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // Supposed to result in drwxr-xr-x. directory permissions
  // mkdir(dirNameOut.Data(), dirMode); // This C-style code won't create intermediate directories
  // mkpath(dirNameOutChars, dirMode);
  // Create short file name
  TString shortFileNameOut = shortFileNameIn;
  TString fullFileNameOut = TString::Format("%s/%s", dirNameOut.Data(), shortFileNameOut.Data());
  length = strlen( fullFileNameOut.Data() );
  char *fullFileNameOutChars = new char[length +1]();
  strncpy(fullFileNameOutChars, fullFileNameOut.Data(), length); 
  mkpath(fullFileNameOutChars, dirMode);
  if( useSmallEventNumber )
    fullFileNameOut.ReplaceAll(".root","_debug.root");
  // Copy the output skim into the appropriate location, close file before copying
  fout->Close();
  // Copy the file to the final location and remove the temporary local file
  printf("Create output file\n   %s\n", fullFileNameOut.Data());
  // Path for grid ftp starts with /user while the mounted areas look like /mnt/hadoop/user",
  // so build the ftp path appropriately
  TPRegexp r1("store(.*)");
  TString reducedFileNameOut = fullFileNameOut(r1);
  TString gridCopyCommand = TString::Format("gfal-copy -p file:////${PWD}/%s gsiftp://red-gridftp.unl.edu//user/uscms01/pnfs/unl.edu/data4/cms/%s",
					    fileNameOutTmp.Data(), reducedFileNameOut.Data());
  printf("Execute grid copy command\n");
  printf("%s\n", gridCopyCommand.Data());
  //TString copyCommand = TString::Format("cp %s %s", fileNameOutTmp.Data(), fullFileNameOut.Data());
  gSystem->Exec(gridCopyCommand.Data());
  TString removeCommand = TString::Format("rm %s", fileNameOutTmp.Data());
  gSystem->Exec(removeCommand.Data());

  return;
}

int mkpath(char* file_path, mode_t mode) {
  assert(file_path && *file_path);
  char* p;
  for (p=strchr(file_path+1, '/'); p; p=strchr(p+1, '/')) {
    *p='\0';
    if (mkdir(file_path, mode)==-1) {
      if (errno!=EEXIST) { 
	*p='/'; 
	return -1; 
      }
    }
    *p='/';
  }
  return 0;
}
