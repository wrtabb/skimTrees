#ifndef DYTREEVARS_H
#define DYTREEVARS_H

#include <vector>

//
// This file defines variables associated with DY ntuples
//

static const int MPSIZE = 2000;
// Global quantities
int runNum;
unsigned long long evtNum;
int lumiBlock;
double PUweight;
int Nelectrons;
int nVertices;

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

// 
// Define branches for input tree
// 
TBranch * b_runNum;
TBranch * b_evtNum;
TBranch * b_lumiBlock;
TBranch * b_PUweight;
TBranch * b_Nelectrons;
TBranch * b_nVertices;

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


#endif
