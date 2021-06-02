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

int    nMuon;
int    Nmuons;
double PVz;
double Muon_pT[MPSIZE];
double Muon_Px[MPSIZE];
double Muon_Py[MPSIZE];
double Muon_Pz[MPSIZE];
double Muon_eta[MPSIZE];
double Muon_phi[MPSIZE];
int    Muon_charge[MPSIZE];
double Muon_dxy[MPSIZE];
double Muon_dz[MPSIZE];
bool   Muon_passTightID[MPSIZE];

double Muon_PfChargedHadronIsoR04[MPSIZE];
double Muon_PfNeutralHadronIsoR04[MPSIZE];
double Muon_PfGammaIsoR04[MPSIZE];
double Muon_PFSumPUIsoR04[MPSIZE];
double Muon_trkiso[MPSIZE];

Int_t nPileUp;

// Trigger quantities
int HLT_ntrig;
int HLT_trigType[MPSIZE];
int HLT_trigFired[MPSIZE];
std::vector<std::string> HLT_trigName;
std::vector<std::string> *pHLT_trigName = &HLT_trigName;

std::vector<double> vtxTrkCkt1Pt;
std::vector<double>*pvtxTrkCkt1Pt = &vtxTrkCkt1Pt;

std::vector<double> vtxTrkCkt2Pt;
std::vector<double>*pvtxTrkCkt2Pt = &vtxTrkCkt2Pt;

std::vector<double> vtxTrkChi2;
std::vector<double>*pvtxTrkChi2 = &vtxTrkChi2;

std::vector<double> vtxTrkNdof;
std::vector<double>*pvtxTrkNdof = &vtxTrkNdof;

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

// GEN Others
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
int GenOthers_isPromptFinalState[MPSIZE];

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

// Muons
TBranch*b_nMuon;
TBranch*b_Nmuons;
TBranch*b_PVz;
TBranch*b_Muon_pT;
TBranch*b_Muon_Px;
TBranch*b_Muon_Py;
TBranch*b_Muon_Pz;
TBranch*b_Muon_eta;
TBranch*b_Muon_phi;
TBranch*b_Muon_charge;
TBranch*b_Muon_dxy;
TBranch*b_Muon_dz;
TBranch*b_Muon_passTightID;

TBranch*b_Muon_PfChargedHadronIsoR04;
TBranch*b_Muon_PfNeutralHadronIsoR04;
TBranch*b_Muon_PfGammaIsoR04;
TBranch*b_Muon_PFSumPUIsoR04;
TBranch*b_Muon_trkiso;

// Gen Others
TBranch*b_nGenOthers;
TBranch*b_GenOthers_phi;
TBranch*b_GenOthers_eta;
TBranch*b_GenOthers_pT;
TBranch*b_GenOthers_Px;
TBranch*b_GenOthers_Py;
TBranch*b_GenOthers_Pz;
TBranch*b_GenOthers_E;
TBranch*b_GenOthers_ID;
TBranch*b_GenOthers_isHardProcess;
TBranch * b_GenOthers_isPromptFinalState;
#endif
