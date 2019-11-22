//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 31 04:00:56 2018 by ROOT version 6.06/01
// from TTree DYTree/DYTree
// found on file: /mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3/DoubleEG/crab_DoubleEG_RunB/ntuple_skim_24.root
//////////////////////////////////////////////////////////

#ifndef testclass_h
#define testclass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

class testclass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nTotal;
   Int_t           runNum;
   ULong64_t       evtNum;
   Int_t           lumiBlock;
   Double_t        PUweight;
   Int_t           nVertices;
   Bool_t          Flag_badMuons;
   Bool_t          Flag_duplicateMuons;
   Bool_t          Flag_noBadMuons;
   vector<double>  *PDFWeights;
   Int_t           PVtrackSize;
   Double_t        PVchi2;
   Double_t        PVndof;
   Double_t        PVnormalizedChi2;
   Double_t        PVx;
   Double_t        PVy;
   Double_t        PVz;
   Int_t           HLT_ntrig;
   Int_t           HLT_trigType[65];   //[HLT_ntrig]
   Int_t           HLT_trigFired[65];   //[HLT_ntrig]
   vector<string>  *HLT_trigName;
   vector<int>     *HLT_trigPS;
   Double_t        HLT_trigPt[65];   //[HLT_ntrig]
   Double_t        HLT_trigEta[65];   //[HLT_ntrig]
   Double_t        HLT_trigPhi[65];   //[HLT_ntrig]
   Int_t           Njets;
   Double_t        Jet_pT[28];   //[Njets]
   Double_t        Jet_eta[28];   //[Njets]
   Double_t        Jet_phi[28];   //[Njets]
   Double_t        Jet_Charge[28];   //[Njets]
   Int_t           Jet_Flavor[28];   //[Njets]
   Double_t        Jet_bTag[28];   //[Njets]
   Double_t        Jet_CHfrac[28];   //[Njets]
   Double_t        Jet_NHfrac[28];   //[Njets]
   Double_t        Jet_NHEMfrac[28];   //[Njets]
   Double_t        Jet_CHEMfrac[28];   //[Njets]
   Int_t           Jet_CHmulti[28];   //[Njets]
   Int_t           Jet_NHmulti[28];   //[Njets]
   Int_t           Nelectrons;
   Double_t        Electron_Energy[7];   //[Nelectrons]
   Double_t        Electron_pT[7];   //[Nelectrons]
   Double_t        Electron_Px[7];   //[Nelectrons]
   Double_t        Electron_Py[7];   //[Nelectrons]
   Double_t        Electron_Pz[7];   //[Nelectrons]
   Double_t        Electron_eta[7];   //[Nelectrons]
   Double_t        Electron_phi[7];   //[Nelectrons]
   Int_t           Electron_charge[7];   //[Nelectrons]
   Double_t        Electron_gsfpT[7];   //[Nelectrons]
   Double_t        Electron_gsfPx[7];   //[Nelectrons]
   Double_t        Electron_gsfPy[7];   //[Nelectrons]
   Double_t        Electron_gsfPz[7];   //[Nelectrons]
   Double_t        Electron_gsfEta[7];   //[Nelectrons]
   Double_t        Electron_gsfPhi[7];   //[Nelectrons]
   Int_t           Electron_gsfCharge[7];   //[Nelectrons]
   Double_t        Electron_etaSC[7];   //[Nelectrons]
   Double_t        Electron_phiSC[7];   //[Nelectrons]
   Double_t        Electron_etaWidth[7];   //[Nelectrons]
   Double_t        Electron_phiWidth[7];   //[Nelectrons]
   Double_t        Electron_dEtaIn[7];   //[Nelectrons]
   Double_t        Electron_dEtaInSeed[7];   //[Nelectrons]
   Double_t        Electron_dPhiIn[7];   //[Nelectrons]
   Double_t        Electron_sigmaIEtaIEta[7];   //[Nelectrons]
   Double_t        Electron_Full5x5_SigmaIEtaIEta[7];   //[Nelectrons]
   Double_t        Electron_HoverE[7];   //[Nelectrons]
   Double_t        Electron_fbrem[7];   //[Nelectrons]
   Double_t        Electron_eOverP[7];   //[Nelectrons]
   Double_t        Electron_InvEminusInvP[7];   //[Nelectrons]
   Double_t        Electron_dxyVTX[7];   //[Nelectrons]
   Double_t        Electron_dzVTX[7];   //[Nelectrons]
   Double_t        Electron_dxy[7];   //[Nelectrons]
   Double_t        Electron_dz[7];   //[Nelectrons]
   Double_t        Electron_dxyBS[7];   //[Nelectrons]
   Double_t        Electron_dzBS[7];   //[Nelectrons]
   Double_t        Electron_chIso03[7];   //[Nelectrons]
   Double_t        Electron_nhIso03[7];   //[Nelectrons]
   Double_t        Electron_phIso03[7];   //[Nelectrons]
   Bool_t          Electron_hasConversion[7];   //[Nelectrons]
   Int_t           Electron_mHits[7];   //[Nelectrons]
   Double_t        Electron_EnergySC[7];   //[Nelectrons]
   Double_t        Electron_preEnergySC[7];   //[Nelectrons]
   Double_t        Electron_rawEnergySC[7];   //[Nelectrons]
   Double_t        Electron_etSC[7];   //[Nelectrons]
   Double_t        Electron_E15[7];   //[Nelectrons]
   Double_t        Electron_E25[7];   //[Nelectrons]
   Double_t        Electron_E55[7];   //[Nelectrons]
   Double_t        Electron_ChIso03FromPU[7];   //[Nelectrons]
   Double_t        Electron_RelPFIso_dBeta[7];   //[Nelectrons]
   Double_t        Electron_RelPFIso_Rho[7];   //[Nelectrons]
   Bool_t          Electron_passConvVeto[7];   //[Nelectrons]
   Bool_t          Electron_passVetoID[7];   //[Nelectrons]
   Bool_t          Electron_passLooseID[7];   //[Nelectrons]
   Bool_t          Electron_passMediumID[7];   //[Nelectrons]
   Bool_t          Electron_passTightID[7];   //[Nelectrons]
   Bool_t          Electron_passMVAID_WP80[7];   //[Nelectrons]
   Bool_t          Electron_passMVAID_WP90[7];   //[Nelectrons]
   Bool_t          Electron_passHEEPID[7];   //[Nelectrons]
   Double_t        Electron_r9[7];   //[Nelectrons]
   Int_t           Electron_ecalDriven[7];   //[Nelectrons]
   Double_t        Electron_ambGsf0Pt[7];   //[Nelectrons]
   Double_t        Electron_ambGsf0Eta[7];   //[Nelectrons]
   Double_t        Electron_ambGsf0Phi[7];   //[Nelectrons]
   Double_t        Electron_ambGsf0Charge[7];   //[Nelectrons]
   Double_t        Electron_ambGsf1Pt[7];   //[Nelectrons]
   Double_t        Electron_ambGsf1Eta[7];   //[Nelectrons]
   Double_t        Electron_ambGsf1Phi[7];   //[Nelectrons]
   Double_t        Electron_ambGsf1Charge[7];   //[Nelectrons]
   Double_t        Electron_ambGsf2Pt[7];   //[Nelectrons]
   Double_t        Electron_ambGsf2Eta[7];   //[Nelectrons]
   Double_t        Electron_ambGsf2Phi[7];   //[Nelectrons]
   Double_t        Electron_ambGsf2Charge[7];   //[Nelectrons]
   Double_t        Electron_ambGsf3Pt[7];   //[Nelectrons]
   Double_t        Electron_ambGsf3Eta[7];   //[Nelectrons]
   Double_t        Electron_ambGsf3Phi[7];   //[Nelectrons]
   Double_t        Electron_ambGsf3Charge[7];   //[Nelectrons]
   vector<double>  *vtxTrkDiE1Pt;
   vector<double>  *vtxTrkDiE2Pt;
   vector<double>  *vtxTrkDiEChi2;
   vector<double>  *vtxTrkDiEProb;
   vector<double>  *vtxTrkDiENdof;
   Int_t           nUnCorrElectron;
   Double_t        Electron_pTUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_etaUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_phiUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_PxUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_PyUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_PzUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_EnergyUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_EnergySCUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_etaSCUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_phiSCUnCorr[8];   //[nUnCorrElectron]
   Double_t        Electron_etSCUnCorr[8];   //[nUnCorrElectron]
   vector<double>  *vtxTrkEMu1Pt;
   vector<double>  *vtxTrkEMu2Pt;
   vector<double>  *vtxTrkEMuChi2;
   vector<double>  *vtxTrkEMuProb;
   vector<double>  *vtxTrkEMuNdof;
   vector<double>  *vtxTrkEMu1Pt_TuneP;
   vector<double>  *vtxTrkEMu2Pt_TuneP;
   vector<double>  *vtxTrkEMuChi2_TuneP;
   vector<double>  *vtxTrkEMuProb_TuneP;
   vector<double>  *vtxTrkEMuNdof_TuneP;
   Int_t           nMuon;
   Int_t           Nmuons;
   Int_t           Muon_muonType[18];   //[nMuon]
   Int_t           isPFmuon[18];   //[nMuon]
   Int_t           isGLBmuon[18];   //[nMuon]
   Int_t           isTRKmuon[18];   //[nMuon]
   Int_t           isSTAmuon[18];   //[nMuon]
   Int_t           Muon_nTrig[18];   //[nMuon]
   Int_t           Muon_triggerObjectType[18];   //[nMuon]
   Int_t           Muon_filterName[18];   //[nMuon]
   Double_t        Muon_phi[18];   //[nMuon]
   Double_t        Muon_dB[18];   //[nMuon]
   Double_t        Muon_eta[18];   //[nMuon]
   Double_t        Muon_pT[18];   //[nMuon]
   Double_t        Muon_cktpT[18];   //[nMuon]
   Double_t        Muon_cktPx[18];   //[nMuon]
   Double_t        Muon_cktPy[18];   //[nMuon]
   Double_t        Muon_cktPz[18];   //[nMuon]
   Double_t        Muon_cktpTError[18];   //[nMuon]
   Double_t        Muon_Px[18];   //[nMuon]
   Double_t        Muon_Py[18];   //[nMuon]
   Double_t        Muon_Pz[18];   //[nMuon]
   Double_t        Muon_trkiso[18];   //[nMuon]
   Double_t        Muon_hcaliso[18];   //[nMuon]
   Double_t        Muon_ecaliso[18];   //[nMuon]
   Double_t        Muon_trkisoR05[18];   //[nMuon]
   Double_t        Muon_hcalisoR05[18];   //[nMuon]
   Double_t        Muon_ecalisoR05[18];   //[nMuon]
   Double_t        Muon_Best_pT[18];   //[nMuon]
   Double_t        Muon_Best_pTError[18];   //[nMuon]
   Double_t        Muon_Best_Px[18];   //[nMuon]
   Double_t        Muon_Best_Py[18];   //[nMuon]
   Double_t        Muon_Best_Pz[18];   //[nMuon]
   Double_t        Muon_Best_eta[18];   //[nMuon]
   Double_t        Muon_Best_phi[18];   //[nMuon]
   Double_t        Muon_Inner_pT[18];   //[nMuon]
   Double_t        Muon_Inner_pTError[18];   //[nMuon]
   Double_t        Muon_Inner_Px[18];   //[nMuon]
   Double_t        Muon_Inner_Py[18];   //[nMuon]
   Double_t        Muon_Inner_Pz[18];   //[nMuon]
   Double_t        Muon_Inner_eta[18];   //[nMuon]
   Double_t        Muon_Inner_phi[18];   //[nMuon]
   Double_t        Muon_Outer_pT[18];   //[nMuon]
   Double_t        Muon_Outer_pTError[18];   //[nMuon]
   Double_t        Muon_Outer_Px[18];   //[nMuon]
   Double_t        Muon_Outer_Py[18];   //[nMuon]
   Double_t        Muon_Outer_Pz[18];   //[nMuon]
   Double_t        Muon_Outer_eta[18];   //[nMuon]
   Double_t        Muon_Outer_phi[18];   //[nMuon]
   Double_t        Muon_GLB_pT[18];   //[nMuon]
   Double_t        Muon_GLB_pTError[18];   //[nMuon]
   Double_t        Muon_GLB_Px[18];   //[nMuon]
   Double_t        Muon_GLB_Py[18];   //[nMuon]
   Double_t        Muon_GLB_Pz[18];   //[nMuon]
   Double_t        Muon_GLB_eta[18];   //[nMuon]
   Double_t        Muon_GLB_phi[18];   //[nMuon]
   Double_t        Muon_TuneP_pT[18];   //[nMuon]
   Double_t        Muon_TuneP_pTError[18];   //[nMuon]
   Double_t        Muon_TuneP_Px[18];   //[nMuon]
   Double_t        Muon_TuneP_Py[18];   //[nMuon]
   Double_t        Muon_TuneP_Pz[18];   //[nMuon]
   Double_t        Muon_TuneP_eta[18];   //[nMuon]
   Double_t        Muon_TuneP_phi[18];   //[nMuon]
   Double_t        Muon_PfChargedHadronIsoR05[18];   //[nMuon]
   Double_t        Muon_PfNeutralHadronIsoR05[18];   //[nMuon]
   Double_t        Muon_PfGammaIsoR05[18];   //[nMuon]
   Double_t        Muon_PfChargedHadronIsoR04[18];   //[nMuon]
   Double_t        Muon_PfNeutralHadronIsoR04[18];   //[nMuon]
   Double_t        Muon_PfGammaIsoR04[18];   //[nMuon]
   Double_t        Muon_PFSumPUIsoR04[18];   //[nMuon]
   Double_t        Muon_PfChargedHadronIsoR03[18];   //[nMuon]
   Double_t        Muon_PfNeutralHadronIsoR03[18];   //[nMuon]
   Double_t        Muon_PfGammaIsoR03[18];   //[nMuon]
   Double_t        Muon_PFSumPUIsoR03[18];   //[nMuon]
   Int_t           Muon_charge[18];   //[nMuon]
   Int_t           Muon_nChambers[18];   //[nMuon]
   Int_t           Muon_nMatches[18];   //[nMuon]
   Int_t           Muon_nMatchesRPCLayers[18];   //[nMuon]
   Int_t           Muon_stationMask[18];   //[nMuon]
   Int_t           Muon_nSegments[18];   //[nMuon]
   Double_t        Muon_chi2dof[18];   //[nMuon]
   Int_t           Muon_nhits[18];   //[nMuon]
   Int_t           Muon_trackerHits[18];   //[nMuon]
   Int_t           Muon_trackerLayers[18];   //[nMuon]
   Int_t           Muon_pixelHits[18];   //[nMuon]
   Int_t           Muon_trackerHitsGLB[18];   //[nMuon]
   Int_t           Muon_trackerLayersGLB[18];   //[nMuon]
   Int_t           Muon_pixelHitsGLB[18];   //[nMuon]
   Int_t           Muon_muonHits[18];   //[nMuon]
   Double_t        Muon_qoverp[18];   //[nMuon]
   Double_t        Muon_theta[18];   //[nMuon]
   Double_t        Muon_lambda[18];   //[nMuon]
   Double_t        Muon_dxy[18];   //[nMuon]
   Double_t        Muon_d0[18];   //[nMuon]
   Double_t        Muon_dsz[18];   //[nMuon]
   Double_t        Muon_dz[18];   //[nMuon]
   Double_t        Muon_dxyBS[18];   //[nMuon]
   Double_t        Muon_dszBS[18];   //[nMuon]
   Double_t        Muon_dzBS[18];   //[nMuon]
   Double_t        Muon_dxyVTX[18];   //[nMuon]
   Double_t        Muon_dszVTX[18];   //[nMuon]
   Double_t        Muon_dzVTX[18];   //[nMuon]
   Double_t        Muon_dxycktVTX[18];   //[nMuon]
   Double_t        Muon_dszcktVTX[18];   //[nMuon]
   Double_t        Muon_dzcktVTX[18];   //[nMuon]
   Double_t        Muon_vx[18];   //[nMuon]
   Double_t        Muon_vy[18];   //[nMuon]
   Double_t        Muon_vz[18];   //[nMuon]
   vector<double>  *CosAngle;
   vector<double>  *vtxTrkCkt1Pt;
   vector<double>  *vtxTrkCkt2Pt;
   vector<double>  *vtxTrkChi2;
   vector<double>  *vtxTrkProb;
   vector<double>  *vtxTrkNdof;
   vector<double>  *CosAngle_TuneP;
   vector<double>  *vtxTrk1Pt_TuneP;
   vector<double>  *vtxTrk2Pt_TuneP;
   vector<double>  *vtxTrkChi2_TuneP;
   vector<double>  *vtxTrkNdof_TuneP;
   vector<double>  *vtxTrkProb_TuneP;
   Int_t           nPileUp;
   Double_t        pileUpReweightIn;
   Double_t        pileUpReweight;
   Double_t        pileUpReweightPlus;
   Double_t        pileUpReweightMinus;
   Double_t        pileUpReweightInMuonPhys;
   Double_t        pileUpReweightMuonPhys;
   Double_t        pileUpReweightPlusMuonPhys;
   Double_t        pileUpReweightMinusMuonPhys;
   Double_t        pfMET_pT;
   Double_t        pfMET_phi;
   Double_t        pfMET_Px;
   Double_t        pfMET_Py;
   Double_t        pfMET_SumEt;
   Double_t        pfMET_Type1_pT;
   Double_t        pfMET_Type1_phi;
   Double_t        pfMET_Type1_Px;
   Double_t        pfMET_Type1_Py;
   Double_t        pfMET_Type1_SumEt;
   Double_t        pfMET_Type1_PhiCor_pT;
   Double_t        pfMET_Type1_PhiCor_phi;
   Double_t        pfMET_Type1_PhiCor_Px;
   Double_t        pfMET_Type1_PhiCor_Py;
   Double_t        pfMET_Type1_PhiCor_SumEt;

   // List of branches
   TBranch        *b_nTotal;   //!
   TBranch        *b_runNum;   //!
   TBranch        *b_evtNum;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_PUweight;   //!
   TBranch        *b_nVertices;   //!
   TBranch        *b_Flag_badMuons;   //!
   TBranch        *b_Flag_duplicateMuons;   //!
   TBranch        *b_Flag_noBadMuons;   //!
   TBranch        *b_PDFWeights;   //!
   TBranch        *b_PVtrackSize;   //!
   TBranch        *b_PVchi2;   //!
   TBranch        *b_PVndof;   //!
   TBranch        *b_PVnormalizedChi2;   //!
   TBranch        *b_PVx;   //!
   TBranch        *b_PVy;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_HLT_ntrig;   //!
   TBranch        *b_HLT_trigType;   //!
   TBranch        *b_HLT_trigFired;   //!
   TBranch        *b_HLT_trigName;   //!
   TBranch        *b_HLT_trigPS;   //!
   TBranch        *b_HLT_trigPt;   //!
   TBranch        *b_HLT_trigEta;   //!
   TBranch        *b_HLT_trigPhi;   //!
   TBranch        *b_Njets;   //!
   TBranch        *b_Jet_pT;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_Charge;   //!
   TBranch        *b_Jet_Flavor;   //!
   TBranch        *b_Jet_bTag;   //!
   TBranch        *b_Jet_CHfrac;   //!
   TBranch        *b_Jet_NHfrac;   //!
   TBranch        *b_Jet_NHEMfrac;   //!
   TBranch        *b_Jet_CHEMfrac;   //!
   TBranch        *b_Jet_CHmulti;   //!
   TBranch        *b_Jet_NHmulti;   //!
   TBranch        *b_Nelectrons;   //!
   TBranch        *b_Electron_Energy;   //!
   TBranch        *b_Electron_pT;   //!
   TBranch        *b_Electron_Px;   //!
   TBranch        *b_Electron_Py;   //!
   TBranch        *b_Electron_Pz;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Electron_charge;   //!
   TBranch        *b_Electron_gsfpT;   //!
   TBranch        *b_Electron_gsfPx;   //!
   TBranch        *b_Electron_gsfPy;   //!
   TBranch        *b_Electron_gsfPz;   //!
   TBranch        *b_Electron_gsfEta;   //!
   TBranch        *b_Electron_gsfPhi;   //!
   TBranch        *b_Electron_gsfCharge;   //!
   TBranch        *b_Electron_etaSC;   //!
   TBranch        *b_Electron_phiSC;   //!
   TBranch        *b_Electron_etaWidth;   //!
   TBranch        *b_Electron_phiWidth;   //!
   TBranch        *b_Electron_dEtaIn;   //!
   TBranch        *b_Electron_dEtaInSeed;   //!
   TBranch        *b_Electron_dPhiIn;   //!
   TBranch        *b_Electron_sigmaIEtaIEta;   //!
   TBranch        *b_Electron_Full5x5_SigmaIEtaIEta;   //!
   TBranch        *b_Electron_HoverE;   //!
   TBranch        *b_Electron_fbrem;   //!
   TBranch        *b_Electron_eOverP;   //!
   TBranch        *b_Electron_InvEminusInvP;   //!
   TBranch        *b_Electron_dxyVTX;   //!
   TBranch        *b_Electron_dzVTX;   //!
   TBranch        *b_Electron_dxy;   //!
   TBranch        *b_Electron_dz;   //!
   TBranch        *b_Electron_dxyBS;   //!
   TBranch        *b_Electron_dzBS;   //!
   TBranch        *b_Electron_chIso03;   //!
   TBranch        *b_Electron_nhIso03;   //!
   TBranch        *b_Electron_phIso03;   //!
   TBranch        *b_Electron_hasConversion;   //!
   TBranch        *b_Electron_mHits;   //!
   TBranch        *b_Electron_EnergySC;   //!
   TBranch        *b_Electron_preEnergySC;   //!
   TBranch        *b_Electron_rawEnergySC;   //!
   TBranch        *b_Electron_etSC;   //!
   TBranch        *b_Electron_E15;   //!
   TBranch        *b_Electron_E25;   //!
   TBranch        *b_Electron_E55;   //!
   TBranch        *b_Electron_ChIso03FromPU;   //!
   TBranch        *b_Electron_RelPFIso_dBeta;   //!
   TBranch        *b_Electron_RelPFIso_Rho;   //!
   TBranch        *b_Electron_passConvVeto;   //!
   TBranch        *b_Electron_passVetoID;   //!
   TBranch        *b_Electron_passLooseID;   //!
   TBranch        *b_Electron_passMediumID;   //!
   TBranch        *b_Electron_passTightID;   //!
   TBranch        *b_Electron_passMVAID_WP80;   //!
   TBranch        *b_Electron_passMVAID_WP90;   //!
   TBranch        *b_Electron_passHEEPID;   //!
   TBranch        *b_Electron_r9;   //!
   TBranch        *b_Electron_ecalDriven;   //!
   TBranch        *b_Electron_ambGsf0Pt;   //!
   TBranch        *b_Electron_ambGsf0Eta;   //!
   TBranch        *b_Electron_ambGsf0Phi;   //!
   TBranch        *b_Electron_ambGsf0Charge;   //!
   TBranch        *b_Electron_ambGsf1Pt;   //!
   TBranch        *b_Electron_ambGsf1Eta;   //!
   TBranch        *b_Electron_ambGsf1Phi;   //!
   TBranch        *b_Electron_ambGsf1Charge;   //!
   TBranch        *b_Electron_ambGsf2Pt;   //!
   TBranch        *b_Electron_ambGsf2Eta;   //!
   TBranch        *b_Electron_ambGsf2Phi;   //!
   TBranch        *b_Electron_ambGsf2Charge;   //!
   TBranch        *b_Electron_ambGsf3Pt;   //!
   TBranch        *b_Electron_ambGsf3Eta;   //!
   TBranch        *b_Electron_ambGsf3Phi;   //!
   TBranch        *b_Electron_ambGsf3Charge;   //!
   TBranch        *b_vtxTrkDiE1Pt;   //!
   TBranch        *b_vtxTrkDiE2Pt;   //!
   TBranch        *b_vtxTrkDiEChi2;   //!
   TBranch        *b_vtxTrkDiEProb;   //!
   TBranch        *b_vtxTrkDiENdof;   //!
   TBranch        *b_nUnCorrElectron;   //!
   TBranch        *b_Electron_pTUnCorr;   //!
   TBranch        *b_Electron_etaUnCorr;   //!
   TBranch        *b_Electron_phiUnCorr;   //!
   TBranch        *b_Electron_PxUnCorr;   //!
   TBranch        *b_Electron_PyUnCorr;   //!
   TBranch        *b_Electron_PzUnCorr;   //!
   TBranch        *b_Electron_EnergyUnCorr;   //!
   TBranch        *b_Electron_EnergySCUnCorr;   //!
   TBranch        *b_Electron_etaSCUnCorr;   //!
   TBranch        *b_Electron_phiSCUnCorr;   //!
   TBranch        *b_Electron_etSCUnCorr;   //!
   TBranch        *b_vtxTrkEMu1Pt;   //!
   TBranch        *b_vtxTrkEMu2Pt;   //!
   TBranch        *b_vtxTrkEMuChi2;   //!
   TBranch        *b_vtxTrkEMuProb;   //!
   TBranch        *b_vtxTrkEMuNdof;   //!
   TBranch        *b_vtxTrkEMu1Pt_TuneP;   //!
   TBranch        *b_vtxTrkEMu2Pt_TuneP;   //!
   TBranch        *b_vtxTrkEMuChi2_TuneP;   //!
   TBranch        *b_vtxTrkEMuProb_TuneP;   //!
   TBranch        *b_vtxTrkEMuNdof_TuneP;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Nmuons;   //!
   TBranch        *b_Muon_muonType;   //!
   TBranch        *b_isPFmuon;   //!
   TBranch        *b_isGLBmuon;   //!
   TBranch        *b_isTRKmuon;   //!
   TBranch        *b_isSTAmuon;   //!
   TBranch        *b_Muon_nTrig;   //!
   TBranch        *b_Muon_triggerObjectType;   //!
   TBranch        *b_Muon_filterName;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_dB;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_pT;   //!
   TBranch        *b_Muon_cktpT;   //!
   TBranch        *b_Muon_cktPx;   //!
   TBranch        *b_Muon_cktPy;   //!
   TBranch        *b_Muon_cktPz;   //!
   TBranch        *b_Muon_cktpTError;   //!
   TBranch        *b_Muon_Px;   //!
   TBranch        *b_Muon_Py;   //!
   TBranch        *b_Muon_Pz;   //!
   TBranch        *b_Muon_trkiso;   //!
   TBranch        *b_Muon_hcaliso;   //!
   TBranch        *b_Muon_ecaliso;   //!
   TBranch        *b_Muon_trkisoR05;   //!
   TBranch        *b_Muon_hcalisoR05;   //!
   TBranch        *b_Muon_ecalisoR05;   //!
   TBranch        *b_Muon_Best_pT;   //!
   TBranch        *b_Muon_Best_pTError;   //!
   TBranch        *b_Muon_Best_Px;   //!
   TBranch        *b_Muon_Best_Py;   //!
   TBranch        *b_Muon_Best_Pz;   //!
   TBranch        *b_Muon_Best_eta;   //!
   TBranch        *b_Muon_Best_phi;   //!
   TBranch        *b_Muon_Inner_pT;   //!
   TBranch        *b_Muon_Inner_pTError;   //!
   TBranch        *b_Muon_Inner_Px;   //!
   TBranch        *b_Muon_Inner_Py;   //!
   TBranch        *b_Muon_Inner_Pz;   //!
   TBranch        *b_Muon_Inner_eta;   //!
   TBranch        *b_Muon_Inner_phi;   //!
   TBranch        *b_Muon_Outer_pT;   //!
   TBranch        *b_Muon_Outer_pTError;   //!
   TBranch        *b_Muon_Outer_Px;   //!
   TBranch        *b_Muon_Outer_Py;   //!
   TBranch        *b_Muon_Outer_Pz;   //!
   TBranch        *b_Muon_Outer_eta;   //!
   TBranch        *b_Muon_Outer_phi;   //!
   TBranch        *b_Muon_GLB_pT;   //!
   TBranch        *b_Muon_GLB_pTError;   //!
   TBranch        *b_Muon_GLB_Px;   //!
   TBranch        *b_Muon_GLB_Py;   //!
   TBranch        *b_Muon_GLB_Pz;   //!
   TBranch        *b_Muon_GLB_eta;   //!
   TBranch        *b_Muon_GLB_phi;   //!
   TBranch        *b_Muon_TuneP_pT;   //!
   TBranch        *b_Muon_TuneP_pTError;   //!
   TBranch        *b_Muon_TuneP_Px;   //!
   TBranch        *b_Muon_TuneP_Py;   //!
   TBranch        *b_Muon_TuneP_Pz;   //!
   TBranch        *b_Muon_TuneP_eta;   //!
   TBranch        *b_Muon_TuneP_phi;   //!
   TBranch        *b_Muon_PfChargedHadronIsoR05;   //!
   TBranch        *b_Muon_PfNeutralHadronIsoR05;   //!
   TBranch        *b_Muon_PfGammaIsoR05;   //!
   TBranch        *b_Muon_PfChargedHadronIsoR04;   //!
   TBranch        *b_Muon_PfNeutralHadronIsoR04;   //!
   TBranch        *b_Muon_PfGammaIsoR04;   //!
   TBranch        *b_Muon_PFSumPUIsoR04;   //!
   TBranch        *b_Muon_PfChargedHadronIsoR03;   //!
   TBranch        *b_Muon_PfNeutralHadronIsoR03;   //!
   TBranch        *b_Muon_PfGammaIsoR03;   //!
   TBranch        *b_Muon_PFSumPUIsoR03;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_nChambers;   //!
   TBranch        *b_Muon_nMatches;   //!
   TBranch        *b_Muon_nMatchesRPCLayers;   //!
   TBranch        *b_Muon_stationMask;   //!
   TBranch        *b_Muon_nSegments;   //!
   TBranch        *b_Muon_chi2dof;   //!
   TBranch        *b_Muon_nhits;   //!
   TBranch        *b_Muon_trackerHits;   //!
   TBranch        *b_Muon_trackerLayers;   //!
   TBranch        *b_Muon_pixelHits;   //!
   TBranch        *b_Muon_trackerHitsGLB;   //!
   TBranch        *b_Muon_trackerLayersGLB;   //!
   TBranch        *b_Muon_pixelHitsGLB;   //!
   TBranch        *b_Muon_muonHits;   //!
   TBranch        *b_Muon_qoverp;   //!
   TBranch        *b_Muon_theta;   //!
   TBranch        *b_Muon_lambda;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_d0;   //!
   TBranch        *b_Muon_dsz;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dxyBS;   //!
   TBranch        *b_Muon_dszBS;   //!
   TBranch        *b_Muon_dzBS;   //!
   TBranch        *b_Muon_dxyVTX;   //!
   TBranch        *b_Muon_dszVTX;   //!
   TBranch        *b_Muon_dzVTX;   //!
   TBranch        *b_Muon_dxycktVTX;   //!
   TBranch        *b_Muon_dszcktVTX;   //!
   TBranch        *b_Muon_dzcktVTX;   //!
   TBranch        *b_Muon_vx;   //!
   TBranch        *b_Muon_vy;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_CosAngle;   //!
   TBranch        *b_vtxTrkCkt1Pt;   //!
   TBranch        *b_vtxTrkCkt2Pt;   //!
   TBranch        *b_vtxTrkChi2;   //!
   TBranch        *b_vtxTrkProb;   //!
   TBranch        *b_vtxTrkNdof;   //!
   TBranch        *b_CosAngle_TuneP;   //!
   TBranch        *b_vtxTrk1Pt_TuneP;   //!
   TBranch        *b_vtxTrk2Pt_TuneP;   //!
   TBranch        *b_vtxTrkChi2_TuneP;   //!
   TBranch        *b_vtxTrkNdof_TuneP;   //!
   TBranch        *b_vtxTrkProb_TuneP;   //!
   TBranch        *b_nPileUp;   //!
   TBranch        *b_pileUpReweightIn;   //!
   TBranch        *b_pileUpReweight;   //!
   TBranch        *b_pileUpReweightPlus;   //!
   TBranch        *b_pileUpReweightMinus;   //!
   TBranch        *b_pileUpReweightInMuonPhys;   //!
   TBranch        *b_pileUpReweightMuonPhys;   //!
   TBranch        *b_pileUpReweightPlusMuonPhys;   //!
   TBranch        *b_pileUpReweightMinusMuonPhys;   //!
   TBranch        *b_pfMET_pT;   //!
   TBranch        *b_pfMET_phi;   //!
   TBranch        *b_pfMET_Px;   //!
   TBranch        *b_pfMET_Py;   //!
   TBranch        *b_pfMET_SumEt;   //!
   TBranch        *b_pfMET_Type1_pT;   //!
   TBranch        *b_pfMET_Type1_phi;   //!
   TBranch        *b_pfMET_Type1_Px;   //!
   TBranch        *b_pfMET_Type1_Py;   //!
   TBranch        *b_pfMET_Type1_SumEt;   //!
   TBranch        *b_pfMET_Type1_PhiCor_pT;   //!
   TBranch        *b_pfMET_Type1_PhiCor_phi;   //!
   TBranch        *b_pfMET_Type1_PhiCor_Px;   //!
   TBranch        *b_pfMET_Type1_PhiCor_Py;   //!
   TBranch        *b_pfMET_Type1_PhiCor_SumEt;   //!

   testclass(TTree *tree=0);
   virtual ~testclass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef testclass_cxx
testclass::testclass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3/DoubleEG/crab_DoubleEG_RunB/ntuple_skim_24.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3/DoubleEG/crab_DoubleEG_RunB/ntuple_skim_24.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/mnt/hadoop/user/uscms01/pnfs/unl.edu/data4/cms/store/user/ikrav/DrellYan_13TeV_2016/v2p3/DoubleEG/crab_DoubleEG_RunB/ntuple_skim_24.root:/recoTree");
      dir->GetObject("DYTree",tree);

   }
   Init(tree);
}

testclass::~testclass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t testclass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t testclass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void testclass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   PDFWeights = 0;
   HLT_trigName = 0;
   HLT_trigPS = 0;
   vtxTrkDiE1Pt = 0;
   vtxTrkDiE2Pt = 0;
   vtxTrkDiEChi2 = 0;
   vtxTrkDiEProb = 0;
   vtxTrkDiENdof = 0;
   vtxTrkEMu1Pt = 0;
   vtxTrkEMu2Pt = 0;
   vtxTrkEMuChi2 = 0;
   vtxTrkEMuProb = 0;
   vtxTrkEMuNdof = 0;
   vtxTrkEMu1Pt_TuneP = 0;
   vtxTrkEMu2Pt_TuneP = 0;
   vtxTrkEMuChi2_TuneP = 0;
   vtxTrkEMuProb_TuneP = 0;
   vtxTrkEMuNdof_TuneP = 0;
   CosAngle = 0;
   vtxTrkCkt1Pt = 0;
   vtxTrkCkt2Pt = 0;
   vtxTrkChi2 = 0;
   vtxTrkProb = 0;
   vtxTrkNdof = 0;
   CosAngle_TuneP = 0;
   vtxTrk1Pt_TuneP = 0;
   vtxTrk2Pt_TuneP = 0;
   vtxTrkChi2_TuneP = 0;
   vtxTrkNdof_TuneP = 0;
   vtxTrkProb_TuneP = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nTotal", &nTotal, &b_nTotal);
   fChain->SetBranchAddress("runNum", &runNum, &b_runNum);
   fChain->SetBranchAddress("evtNum", &evtNum, &b_evtNum);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("PUweight", &PUweight, &b_PUweight);
   fChain->SetBranchAddress("nVertices", &nVertices, &b_nVertices);
   fChain->SetBranchAddress("Flag_badMuons", &Flag_badMuons, &b_Flag_badMuons);
   fChain->SetBranchAddress("Flag_duplicateMuons", &Flag_duplicateMuons, &b_Flag_duplicateMuons);
   fChain->SetBranchAddress("Flag_noBadMuons", &Flag_noBadMuons, &b_Flag_noBadMuons);
   fChain->SetBranchAddress("PDFWeights", &PDFWeights, &b_PDFWeights);
   fChain->SetBranchAddress("PVtrackSize", &PVtrackSize, &b_PVtrackSize);
   fChain->SetBranchAddress("PVchi2", &PVchi2, &b_PVchi2);
   fChain->SetBranchAddress("PVndof", &PVndof, &b_PVndof);
   fChain->SetBranchAddress("PVnormalizedChi2", &PVnormalizedChi2, &b_PVnormalizedChi2);
   fChain->SetBranchAddress("PVx", &PVx, &b_PVx);
   fChain->SetBranchAddress("PVy", &PVy, &b_PVy);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("HLT_ntrig", &HLT_ntrig, &b_HLT_ntrig);
   fChain->SetBranchAddress("HLT_trigType", HLT_trigType, &b_HLT_trigType);
   fChain->SetBranchAddress("HLT_trigFired", HLT_trigFired, &b_HLT_trigFired);
   fChain->SetBranchAddress("HLT_trigName", &HLT_trigName, &b_HLT_trigName);
   fChain->SetBranchAddress("HLT_trigPS", &HLT_trigPS, &b_HLT_trigPS);
   fChain->SetBranchAddress("HLT_trigPt", HLT_trigPt, &b_HLT_trigPt);
   fChain->SetBranchAddress("HLT_trigEta", HLT_trigEta, &b_HLT_trigEta);
   fChain->SetBranchAddress("HLT_trigPhi", HLT_trigPhi, &b_HLT_trigPhi);
   fChain->SetBranchAddress("Njets", &Njets, &b_Njets);
   fChain->SetBranchAddress("Jet_pT", Jet_pT, &b_Jet_pT);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_Charge", Jet_Charge, &b_Jet_Charge);
   fChain->SetBranchAddress("Jet_Flavor", Jet_Flavor, &b_Jet_Flavor);
   fChain->SetBranchAddress("Jet_bTag", Jet_bTag, &b_Jet_bTag);
   fChain->SetBranchAddress("Jet_CHfrac", Jet_CHfrac, &b_Jet_CHfrac);
   fChain->SetBranchAddress("Jet_NHfrac", Jet_NHfrac, &b_Jet_NHfrac);
   fChain->SetBranchAddress("Jet_NHEMfrac", Jet_NHEMfrac, &b_Jet_NHEMfrac);
   fChain->SetBranchAddress("Jet_CHEMfrac", Jet_CHEMfrac, &b_Jet_CHEMfrac);
   fChain->SetBranchAddress("Jet_CHmulti", Jet_CHmulti, &b_Jet_CHmulti);
   fChain->SetBranchAddress("Jet_NHmulti", Jet_NHmulti, &b_Jet_NHmulti);
   fChain->SetBranchAddress("Nelectrons", &Nelectrons, &b_Nelectrons);
   fChain->SetBranchAddress("Electron_Energy", Electron_Energy, &b_Electron_Energy);
   fChain->SetBranchAddress("Electron_pT", Electron_pT, &b_Electron_pT);
   fChain->SetBranchAddress("Electron_Px", Electron_Px, &b_Electron_Px);
   fChain->SetBranchAddress("Electron_Py", Electron_Py, &b_Electron_Py);
   fChain->SetBranchAddress("Electron_Pz", Electron_Pz, &b_Electron_Pz);
   fChain->SetBranchAddress("Electron_eta", Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_phi", Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Electron_charge", Electron_charge, &b_Electron_charge);
   fChain->SetBranchAddress("Electron_gsfpT", Electron_gsfpT, &b_Electron_gsfpT);
   fChain->SetBranchAddress("Electron_gsfPx", Electron_gsfPx, &b_Electron_gsfPx);
   fChain->SetBranchAddress("Electron_gsfPy", Electron_gsfPy, &b_Electron_gsfPy);
   fChain->SetBranchAddress("Electron_gsfPz", Electron_gsfPz, &b_Electron_gsfPz);
   fChain->SetBranchAddress("Electron_gsfEta", Electron_gsfEta, &b_Electron_gsfEta);
   fChain->SetBranchAddress("Electron_gsfPhi", Electron_gsfPhi, &b_Electron_gsfPhi);
   fChain->SetBranchAddress("Electron_gsfCharge", Electron_gsfCharge, &b_Electron_gsfCharge);
   fChain->SetBranchAddress("Electron_etaSC", Electron_etaSC, &b_Electron_etaSC);
   fChain->SetBranchAddress("Electron_phiSC", Electron_phiSC, &b_Electron_phiSC);
   fChain->SetBranchAddress("Electron_etaWidth", Electron_etaWidth, &b_Electron_etaWidth);
   fChain->SetBranchAddress("Electron_phiWidth", Electron_phiWidth, &b_Electron_phiWidth);
   fChain->SetBranchAddress("Electron_dEtaIn", Electron_dEtaIn, &b_Electron_dEtaIn);
   fChain->SetBranchAddress("Electron_dEtaInSeed", Electron_dEtaInSeed, &b_Electron_dEtaInSeed);
   fChain->SetBranchAddress("Electron_dPhiIn", Electron_dPhiIn, &b_Electron_dPhiIn);
   fChain->SetBranchAddress("Electron_sigmaIEtaIEta", Electron_sigmaIEtaIEta, &b_Electron_sigmaIEtaIEta);
   fChain->SetBranchAddress("Electron_Full5x5_SigmaIEtaIEta", Electron_Full5x5_SigmaIEtaIEta, &b_Electron_Full5x5_SigmaIEtaIEta);
   fChain->SetBranchAddress("Electron_HoverE", Electron_HoverE, &b_Electron_HoverE);
   fChain->SetBranchAddress("Electron_fbrem", Electron_fbrem, &b_Electron_fbrem);
   fChain->SetBranchAddress("Electron_eOverP", Electron_eOverP, &b_Electron_eOverP);
   fChain->SetBranchAddress("Electron_InvEminusInvP", Electron_InvEminusInvP, &b_Electron_InvEminusInvP);
   fChain->SetBranchAddress("Electron_dxyVTX", Electron_dxyVTX, &b_Electron_dxyVTX);
   fChain->SetBranchAddress("Electron_dzVTX", Electron_dzVTX, &b_Electron_dzVTX);
   fChain->SetBranchAddress("Electron_dxy", Electron_dxy, &b_Electron_dxy);
   fChain->SetBranchAddress("Electron_dz", Electron_dz, &b_Electron_dz);
   fChain->SetBranchAddress("Electron_dxyBS", Electron_dxyBS, &b_Electron_dxyBS);
   fChain->SetBranchAddress("Electron_dzBS", Electron_dzBS, &b_Electron_dzBS);
   fChain->SetBranchAddress("Electron_chIso03", Electron_chIso03, &b_Electron_chIso03);
   fChain->SetBranchAddress("Electron_nhIso03", Electron_nhIso03, &b_Electron_nhIso03);
   fChain->SetBranchAddress("Electron_phIso03", Electron_phIso03, &b_Electron_phIso03);
   fChain->SetBranchAddress("Electron_hasConversion", Electron_hasConversion, &b_Electron_hasConversion);
   fChain->SetBranchAddress("Electron_mHits", Electron_mHits, &b_Electron_mHits);
   fChain->SetBranchAddress("Electron_EnergySC", Electron_EnergySC, &b_Electron_EnergySC);
   fChain->SetBranchAddress("Electron_preEnergySC", Electron_preEnergySC, &b_Electron_preEnergySC);
   fChain->SetBranchAddress("Electron_rawEnergySC", Electron_rawEnergySC, &b_Electron_rawEnergySC);
   fChain->SetBranchAddress("Electron_etSC", Electron_etSC, &b_Electron_etSC);
   fChain->SetBranchAddress("Electron_E15", Electron_E15, &b_Electron_E15);
   fChain->SetBranchAddress("Electron_E25", Electron_E25, &b_Electron_E25);
   fChain->SetBranchAddress("Electron_E55", Electron_E55, &b_Electron_E55);
   fChain->SetBranchAddress("Electron_ChIso03FromPU", Electron_ChIso03FromPU, &b_Electron_ChIso03FromPU);
   fChain->SetBranchAddress("Electron_RelPFIso_dBeta", Electron_RelPFIso_dBeta, &b_Electron_RelPFIso_dBeta);
   fChain->SetBranchAddress("Electron_RelPFIso_Rho", Electron_RelPFIso_Rho, &b_Electron_RelPFIso_Rho);
   fChain->SetBranchAddress("Electron_passConvVeto", Electron_passConvVeto, &b_Electron_passConvVeto);
   fChain->SetBranchAddress("Electron_passVetoID", Electron_passVetoID, &b_Electron_passVetoID);
   fChain->SetBranchAddress("Electron_passLooseID", Electron_passLooseID, &b_Electron_passLooseID);
   fChain->SetBranchAddress("Electron_passMediumID", Electron_passMediumID, &b_Electron_passMediumID);
   fChain->SetBranchAddress("Electron_passTightID", Electron_passTightID, &b_Electron_passTightID);
   fChain->SetBranchAddress("Electron_passMVAID_WP80", Electron_passMVAID_WP80, &b_Electron_passMVAID_WP80);
   fChain->SetBranchAddress("Electron_passMVAID_WP90", Electron_passMVAID_WP90, &b_Electron_passMVAID_WP90);
   fChain->SetBranchAddress("Electron_passHEEPID", Electron_passHEEPID, &b_Electron_passHEEPID);
   fChain->SetBranchAddress("Electron_r9", Electron_r9, &b_Electron_r9);
   fChain->SetBranchAddress("Electron_ecalDriven", Electron_ecalDriven, &b_Electron_ecalDriven);
   fChain->SetBranchAddress("Electron_ambGsf0Pt", Electron_ambGsf0Pt, &b_Electron_ambGsf0Pt);
   fChain->SetBranchAddress("Electron_ambGsf0Eta", Electron_ambGsf0Eta, &b_Electron_ambGsf0Eta);
   fChain->SetBranchAddress("Electron_ambGsf0Phi", Electron_ambGsf0Phi, &b_Electron_ambGsf0Phi);
   fChain->SetBranchAddress("Electron_ambGsf0Charge", Electron_ambGsf0Charge, &b_Electron_ambGsf0Charge);
   fChain->SetBranchAddress("Electron_ambGsf1Pt", Electron_ambGsf1Pt, &b_Electron_ambGsf1Pt);
   fChain->SetBranchAddress("Electron_ambGsf1Eta", Electron_ambGsf1Eta, &b_Electron_ambGsf1Eta);
   fChain->SetBranchAddress("Electron_ambGsf1Phi", Electron_ambGsf1Phi, &b_Electron_ambGsf1Phi);
   fChain->SetBranchAddress("Electron_ambGsf1Charge", Electron_ambGsf1Charge, &b_Electron_ambGsf1Charge);
   fChain->SetBranchAddress("Electron_ambGsf2Pt", Electron_ambGsf2Pt, &b_Electron_ambGsf2Pt);
   fChain->SetBranchAddress("Electron_ambGsf2Eta", Electron_ambGsf2Eta, &b_Electron_ambGsf2Eta);
   fChain->SetBranchAddress("Electron_ambGsf2Phi", Electron_ambGsf2Phi, &b_Electron_ambGsf2Phi);
   fChain->SetBranchAddress("Electron_ambGsf2Charge", Electron_ambGsf2Charge, &b_Electron_ambGsf2Charge);
   fChain->SetBranchAddress("Electron_ambGsf3Pt", Electron_ambGsf3Pt, &b_Electron_ambGsf3Pt);
   fChain->SetBranchAddress("Electron_ambGsf3Eta", Electron_ambGsf3Eta, &b_Electron_ambGsf3Eta);
   fChain->SetBranchAddress("Electron_ambGsf3Phi", Electron_ambGsf3Phi, &b_Electron_ambGsf3Phi);
   fChain->SetBranchAddress("Electron_ambGsf3Charge", Electron_ambGsf3Charge, &b_Electron_ambGsf3Charge);
   fChain->SetBranchAddress("vtxTrkDiE1Pt", &vtxTrkDiE1Pt, &b_vtxTrkDiE1Pt);
   fChain->SetBranchAddress("vtxTrkDiE2Pt", &vtxTrkDiE2Pt, &b_vtxTrkDiE2Pt);
   fChain->SetBranchAddress("vtxTrkDiEChi2", &vtxTrkDiEChi2, &b_vtxTrkDiEChi2);
   fChain->SetBranchAddress("vtxTrkDiEProb", &vtxTrkDiEProb, &b_vtxTrkDiEProb);
   fChain->SetBranchAddress("vtxTrkDiENdof", &vtxTrkDiENdof, &b_vtxTrkDiENdof);
   fChain->SetBranchAddress("nUnCorrElectron", &nUnCorrElectron, &b_nUnCorrElectron);
   fChain->SetBranchAddress("Electron_pTUnCorr", Electron_pTUnCorr, &b_Electron_pTUnCorr);
   fChain->SetBranchAddress("Electron_etaUnCorr", Electron_etaUnCorr, &b_Electron_etaUnCorr);
   fChain->SetBranchAddress("Electron_phiUnCorr", Electron_phiUnCorr, &b_Electron_phiUnCorr);
   fChain->SetBranchAddress("Electron_PxUnCorr", Electron_PxUnCorr, &b_Electron_PxUnCorr);
   fChain->SetBranchAddress("Electron_PyUnCorr", Electron_PyUnCorr, &b_Electron_PyUnCorr);
   fChain->SetBranchAddress("Electron_PzUnCorr", Electron_PzUnCorr, &b_Electron_PzUnCorr);
   fChain->SetBranchAddress("Electron_EnergyUnCorr", Electron_EnergyUnCorr, &b_Electron_EnergyUnCorr);
   fChain->SetBranchAddress("Electron_EnergySCUnCorr", Electron_EnergySCUnCorr, &b_Electron_EnergySCUnCorr);
   fChain->SetBranchAddress("Electron_etaSCUnCorr", Electron_etaSCUnCorr, &b_Electron_etaSCUnCorr);
   fChain->SetBranchAddress("Electron_phiSCUnCorr", Electron_phiSCUnCorr, &b_Electron_phiSCUnCorr);
   fChain->SetBranchAddress("Electron_etSCUnCorr", Electron_etSCUnCorr, &b_Electron_etSCUnCorr);
   fChain->SetBranchAddress("vtxTrkEMu1Pt", &vtxTrkEMu1Pt, &b_vtxTrkEMu1Pt);
   fChain->SetBranchAddress("vtxTrkEMu2Pt", &vtxTrkEMu2Pt, &b_vtxTrkEMu2Pt);
   fChain->SetBranchAddress("vtxTrkEMuChi2", &vtxTrkEMuChi2, &b_vtxTrkEMuChi2);
   fChain->SetBranchAddress("vtxTrkEMuProb", &vtxTrkEMuProb, &b_vtxTrkEMuProb);
   fChain->SetBranchAddress("vtxTrkEMuNdof", &vtxTrkEMuNdof, &b_vtxTrkEMuNdof);
   fChain->SetBranchAddress("vtxTrkEMu1Pt_TuneP", &vtxTrkEMu1Pt_TuneP, &b_vtxTrkEMu1Pt_TuneP);
   fChain->SetBranchAddress("vtxTrkEMu2Pt_TuneP", &vtxTrkEMu2Pt_TuneP, &b_vtxTrkEMu2Pt_TuneP);
   fChain->SetBranchAddress("vtxTrkEMuChi2_TuneP", &vtxTrkEMuChi2_TuneP, &b_vtxTrkEMuChi2_TuneP);
   fChain->SetBranchAddress("vtxTrkEMuProb_TuneP", &vtxTrkEMuProb_TuneP, &b_vtxTrkEMuProb_TuneP);
   fChain->SetBranchAddress("vtxTrkEMuNdof_TuneP", &vtxTrkEMuNdof_TuneP, &b_vtxTrkEMuNdof_TuneP);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Nmuons", &Nmuons, &b_Nmuons);
   fChain->SetBranchAddress("Muon_muonType", Muon_muonType, &b_Muon_muonType);
   fChain->SetBranchAddress("isPFmuon", isPFmuon, &b_isPFmuon);
   fChain->SetBranchAddress("isGLBmuon", isGLBmuon, &b_isGLBmuon);
   fChain->SetBranchAddress("isTRKmuon", isTRKmuon, &b_isTRKmuon);
   fChain->SetBranchAddress("isSTAmuon", isSTAmuon, &b_isSTAmuon);
   fChain->SetBranchAddress("Muon_nTrig", Muon_nTrig, &b_Muon_nTrig);
   fChain->SetBranchAddress("Muon_triggerObjectType", Muon_triggerObjectType, &b_Muon_triggerObjectType);
   fChain->SetBranchAddress("Muon_filterName", Muon_filterName, &b_Muon_filterName);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_dB", Muon_dB, &b_Muon_dB);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_pT", Muon_pT, &b_Muon_pT);
   fChain->SetBranchAddress("Muon_cktpT", Muon_cktpT, &b_Muon_cktpT);
   fChain->SetBranchAddress("Muon_cktPx", Muon_cktPx, &b_Muon_cktPx);
   fChain->SetBranchAddress("Muon_cktPy", Muon_cktPy, &b_Muon_cktPy);
   fChain->SetBranchAddress("Muon_cktPz", Muon_cktPz, &b_Muon_cktPz);
   fChain->SetBranchAddress("Muon_cktpTError", Muon_cktpTError, &b_Muon_cktpTError);
   fChain->SetBranchAddress("Muon_Px", Muon_Px, &b_Muon_Px);
   fChain->SetBranchAddress("Muon_Py", Muon_Py, &b_Muon_Py);
   fChain->SetBranchAddress("Muon_Pz", Muon_Pz, &b_Muon_Pz);
   fChain->SetBranchAddress("Muon_trkiso", Muon_trkiso, &b_Muon_trkiso);
   fChain->SetBranchAddress("Muon_hcaliso", Muon_hcaliso, &b_Muon_hcaliso);
   fChain->SetBranchAddress("Muon_ecaliso", Muon_ecaliso, &b_Muon_ecaliso);
   fChain->SetBranchAddress("Muon_trkisoR05", Muon_trkisoR05, &b_Muon_trkisoR05);
   fChain->SetBranchAddress("Muon_hcalisoR05", Muon_hcalisoR05, &b_Muon_hcalisoR05);
   fChain->SetBranchAddress("Muon_ecalisoR05", Muon_ecalisoR05, &b_Muon_ecalisoR05);
   fChain->SetBranchAddress("Muon_Best_pT", Muon_Best_pT, &b_Muon_Best_pT);
   fChain->SetBranchAddress("Muon_Best_pTError", Muon_Best_pTError, &b_Muon_Best_pTError);
   fChain->SetBranchAddress("Muon_Best_Px", Muon_Best_Px, &b_Muon_Best_Px);
   fChain->SetBranchAddress("Muon_Best_Py", Muon_Best_Py, &b_Muon_Best_Py);
   fChain->SetBranchAddress("Muon_Best_Pz", Muon_Best_Pz, &b_Muon_Best_Pz);
   fChain->SetBranchAddress("Muon_Best_eta", Muon_Best_eta, &b_Muon_Best_eta);
   fChain->SetBranchAddress("Muon_Best_phi", Muon_Best_phi, &b_Muon_Best_phi);
   fChain->SetBranchAddress("Muon_Inner_pT", Muon_Inner_pT, &b_Muon_Inner_pT);
   fChain->SetBranchAddress("Muon_Inner_pTError", Muon_Inner_pTError, &b_Muon_Inner_pTError);
   fChain->SetBranchAddress("Muon_Inner_Px", Muon_Inner_Px, &b_Muon_Inner_Px);
   fChain->SetBranchAddress("Muon_Inner_Py", Muon_Inner_Py, &b_Muon_Inner_Py);
   fChain->SetBranchAddress("Muon_Inner_Pz", Muon_Inner_Pz, &b_Muon_Inner_Pz);
   fChain->SetBranchAddress("Muon_Inner_eta", Muon_Inner_eta, &b_Muon_Inner_eta);
   fChain->SetBranchAddress("Muon_Inner_phi", Muon_Inner_phi, &b_Muon_Inner_phi);
   fChain->SetBranchAddress("Muon_Outer_pT", Muon_Outer_pT, &b_Muon_Outer_pT);
   fChain->SetBranchAddress("Muon_Outer_pTError", Muon_Outer_pTError, &b_Muon_Outer_pTError);
   fChain->SetBranchAddress("Muon_Outer_Px", Muon_Outer_Px, &b_Muon_Outer_Px);
   fChain->SetBranchAddress("Muon_Outer_Py", Muon_Outer_Py, &b_Muon_Outer_Py);
   fChain->SetBranchAddress("Muon_Outer_Pz", Muon_Outer_Pz, &b_Muon_Outer_Pz);
   fChain->SetBranchAddress("Muon_Outer_eta", Muon_Outer_eta, &b_Muon_Outer_eta);
   fChain->SetBranchAddress("Muon_Outer_phi", Muon_Outer_phi, &b_Muon_Outer_phi);
   fChain->SetBranchAddress("Muon_GLB_pT", Muon_GLB_pT, &b_Muon_GLB_pT);
   fChain->SetBranchAddress("Muon_GLB_pTError", Muon_GLB_pTError, &b_Muon_GLB_pTError);
   fChain->SetBranchAddress("Muon_GLB_Px", Muon_GLB_Px, &b_Muon_GLB_Px);
   fChain->SetBranchAddress("Muon_GLB_Py", Muon_GLB_Py, &b_Muon_GLB_Py);
   fChain->SetBranchAddress("Muon_GLB_Pz", Muon_GLB_Pz, &b_Muon_GLB_Pz);
   fChain->SetBranchAddress("Muon_GLB_eta", Muon_GLB_eta, &b_Muon_GLB_eta);
   fChain->SetBranchAddress("Muon_GLB_phi", Muon_GLB_phi, &b_Muon_GLB_phi);
   fChain->SetBranchAddress("Muon_TuneP_pT", Muon_TuneP_pT, &b_Muon_TuneP_pT);
   fChain->SetBranchAddress("Muon_TuneP_pTError", Muon_TuneP_pTError, &b_Muon_TuneP_pTError);
   fChain->SetBranchAddress("Muon_TuneP_Px", Muon_TuneP_Px, &b_Muon_TuneP_Px);
   fChain->SetBranchAddress("Muon_TuneP_Py", Muon_TuneP_Py, &b_Muon_TuneP_Py);
   fChain->SetBranchAddress("Muon_TuneP_Pz", Muon_TuneP_Pz, &b_Muon_TuneP_Pz);
   fChain->SetBranchAddress("Muon_TuneP_eta", Muon_TuneP_eta, &b_Muon_TuneP_eta);
   fChain->SetBranchAddress("Muon_TuneP_phi", Muon_TuneP_phi, &b_Muon_TuneP_phi);
   fChain->SetBranchAddress("Muon_PfChargedHadronIsoR05", Muon_PfChargedHadronIsoR05, &b_Muon_PfChargedHadronIsoR05);
   fChain->SetBranchAddress("Muon_PfNeutralHadronIsoR05", Muon_PfNeutralHadronIsoR05, &b_Muon_PfNeutralHadronIsoR05);
   fChain->SetBranchAddress("Muon_PfGammaIsoR05", Muon_PfGammaIsoR05, &b_Muon_PfGammaIsoR05);
   fChain->SetBranchAddress("Muon_PfChargedHadronIsoR04", Muon_PfChargedHadronIsoR04, &b_Muon_PfChargedHadronIsoR04);
   fChain->SetBranchAddress("Muon_PfNeutralHadronIsoR04", Muon_PfNeutralHadronIsoR04, &b_Muon_PfNeutralHadronIsoR04);
   fChain->SetBranchAddress("Muon_PfGammaIsoR04", Muon_PfGammaIsoR04, &b_Muon_PfGammaIsoR04);
   fChain->SetBranchAddress("Muon_PFSumPUIsoR04", Muon_PFSumPUIsoR04, &b_Muon_PFSumPUIsoR04);
   fChain->SetBranchAddress("Muon_PfChargedHadronIsoR03", Muon_PfChargedHadronIsoR03, &b_Muon_PfChargedHadronIsoR03);
   fChain->SetBranchAddress("Muon_PfNeutralHadronIsoR03", Muon_PfNeutralHadronIsoR03, &b_Muon_PfNeutralHadronIsoR03);
   fChain->SetBranchAddress("Muon_PfGammaIsoR03", Muon_PfGammaIsoR03, &b_Muon_PfGammaIsoR03);
   fChain->SetBranchAddress("Muon_PFSumPUIsoR03", Muon_PFSumPUIsoR03, &b_Muon_PFSumPUIsoR03);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_nChambers", Muon_nChambers, &b_Muon_nChambers);
   fChain->SetBranchAddress("Muon_nMatches", Muon_nMatches, &b_Muon_nMatches);
   fChain->SetBranchAddress("Muon_nMatchesRPCLayers", Muon_nMatchesRPCLayers, &b_Muon_nMatchesRPCLayers);
   fChain->SetBranchAddress("Muon_stationMask", Muon_stationMask, &b_Muon_stationMask);
   fChain->SetBranchAddress("Muon_nSegments", Muon_nSegments, &b_Muon_nSegments);
   fChain->SetBranchAddress("Muon_chi2dof", Muon_chi2dof, &b_Muon_chi2dof);
   fChain->SetBranchAddress("Muon_nhits", Muon_nhits, &b_Muon_nhits);
   fChain->SetBranchAddress("Muon_trackerHits", Muon_trackerHits, &b_Muon_trackerHits);
   fChain->SetBranchAddress("Muon_trackerLayers", Muon_trackerLayers, &b_Muon_trackerLayers);
   fChain->SetBranchAddress("Muon_pixelHits", Muon_pixelHits, &b_Muon_pixelHits);
   fChain->SetBranchAddress("Muon_trackerHitsGLB", Muon_trackerHitsGLB, &b_Muon_trackerHitsGLB);
   fChain->SetBranchAddress("Muon_trackerLayersGLB", Muon_trackerLayersGLB, &b_Muon_trackerLayersGLB);
   fChain->SetBranchAddress("Muon_pixelHitsGLB", Muon_pixelHitsGLB, &b_Muon_pixelHitsGLB);
   fChain->SetBranchAddress("Muon_muonHits", Muon_muonHits, &b_Muon_muonHits);
   fChain->SetBranchAddress("Muon_qoverp", Muon_qoverp, &b_Muon_qoverp);
   fChain->SetBranchAddress("Muon_theta", Muon_theta, &b_Muon_theta);
   fChain->SetBranchAddress("Muon_lambda", Muon_lambda, &b_Muon_lambda);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_d0", Muon_d0, &b_Muon_d0);
   fChain->SetBranchAddress("Muon_dsz", Muon_dsz, &b_Muon_dsz);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dxyBS", Muon_dxyBS, &b_Muon_dxyBS);
   fChain->SetBranchAddress("Muon_dszBS", Muon_dszBS, &b_Muon_dszBS);
   fChain->SetBranchAddress("Muon_dzBS", Muon_dzBS, &b_Muon_dzBS);
   fChain->SetBranchAddress("Muon_dxyVTX", Muon_dxyVTX, &b_Muon_dxyVTX);
   fChain->SetBranchAddress("Muon_dszVTX", Muon_dszVTX, &b_Muon_dszVTX);
   fChain->SetBranchAddress("Muon_dzVTX", Muon_dzVTX, &b_Muon_dzVTX);
   fChain->SetBranchAddress("Muon_dxycktVTX", Muon_dxycktVTX, &b_Muon_dxycktVTX);
   fChain->SetBranchAddress("Muon_dszcktVTX", Muon_dszcktVTX, &b_Muon_dszcktVTX);
   fChain->SetBranchAddress("Muon_dzcktVTX", Muon_dzcktVTX, &b_Muon_dzcktVTX);
   fChain->SetBranchAddress("Muon_vx", Muon_vx, &b_Muon_vx);
   fChain->SetBranchAddress("Muon_vy", Muon_vy, &b_Muon_vy);
   fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("CosAngle", &CosAngle, &b_CosAngle);
   fChain->SetBranchAddress("vtxTrkCkt1Pt", &vtxTrkCkt1Pt, &b_vtxTrkCkt1Pt);
   fChain->SetBranchAddress("vtxTrkCkt2Pt", &vtxTrkCkt2Pt, &b_vtxTrkCkt2Pt);
   fChain->SetBranchAddress("vtxTrkChi2", &vtxTrkChi2, &b_vtxTrkChi2);
   fChain->SetBranchAddress("vtxTrkProb", &vtxTrkProb, &b_vtxTrkProb);
   fChain->SetBranchAddress("vtxTrkNdof", &vtxTrkNdof, &b_vtxTrkNdof);
   fChain->SetBranchAddress("CosAngle_TuneP", &CosAngle_TuneP, &b_CosAngle_TuneP);
   fChain->SetBranchAddress("vtxTrk1Pt_TuneP", &vtxTrk1Pt_TuneP, &b_vtxTrk1Pt_TuneP);
   fChain->SetBranchAddress("vtxTrk2Pt_TuneP", &vtxTrk2Pt_TuneP, &b_vtxTrk2Pt_TuneP);
   fChain->SetBranchAddress("vtxTrkChi2_TuneP", &vtxTrkChi2_TuneP, &b_vtxTrkChi2_TuneP);
   fChain->SetBranchAddress("vtxTrkNdof_TuneP", &vtxTrkNdof_TuneP, &b_vtxTrkNdof_TuneP);
   fChain->SetBranchAddress("vtxTrkProb_TuneP", &vtxTrkProb_TuneP, &b_vtxTrkProb_TuneP);
   fChain->SetBranchAddress("nPileUp", &nPileUp, &b_nPileUp);
   fChain->SetBranchAddress("pileUpReweightIn", &pileUpReweightIn, &b_pileUpReweightIn);
   fChain->SetBranchAddress("pileUpReweight", &pileUpReweight, &b_pileUpReweight);
   fChain->SetBranchAddress("pileUpReweightPlus", &pileUpReweightPlus, &b_pileUpReweightPlus);
   fChain->SetBranchAddress("pileUpReweightMinus", &pileUpReweightMinus, &b_pileUpReweightMinus);
   fChain->SetBranchAddress("pileUpReweightInMuonPhys", &pileUpReweightInMuonPhys, &b_pileUpReweightInMuonPhys);
   fChain->SetBranchAddress("pileUpReweightMuonPhys", &pileUpReweightMuonPhys, &b_pileUpReweightMuonPhys);
   fChain->SetBranchAddress("pileUpReweightPlusMuonPhys", &pileUpReweightPlusMuonPhys, &b_pileUpReweightPlusMuonPhys);
   fChain->SetBranchAddress("pileUpReweightMinusMuonPhys", &pileUpReweightMinusMuonPhys, &b_pileUpReweightMinusMuonPhys);
   fChain->SetBranchAddress("pfMET_pT", &pfMET_pT, &b_pfMET_pT);
   fChain->SetBranchAddress("pfMET_phi", &pfMET_phi, &b_pfMET_phi);
   fChain->SetBranchAddress("pfMET_Px", &pfMET_Px, &b_pfMET_Px);
   fChain->SetBranchAddress("pfMET_Py", &pfMET_Py, &b_pfMET_Py);
   fChain->SetBranchAddress("pfMET_SumEt", &pfMET_SumEt, &b_pfMET_SumEt);
   fChain->SetBranchAddress("pfMET_Type1_pT", &pfMET_Type1_pT, &b_pfMET_Type1_pT);
   fChain->SetBranchAddress("pfMET_Type1_phi", &pfMET_Type1_phi, &b_pfMET_Type1_phi);
   fChain->SetBranchAddress("pfMET_Type1_Px", &pfMET_Type1_Px, &b_pfMET_Type1_Px);
   fChain->SetBranchAddress("pfMET_Type1_Py", &pfMET_Type1_Py, &b_pfMET_Type1_Py);
   fChain->SetBranchAddress("pfMET_Type1_SumEt", &pfMET_Type1_SumEt, &b_pfMET_Type1_SumEt);
   fChain->SetBranchAddress("pfMET_Type1_PhiCor_pT", &pfMET_Type1_PhiCor_pT, &b_pfMET_Type1_PhiCor_pT);
   fChain->SetBranchAddress("pfMET_Type1_PhiCor_phi", &pfMET_Type1_PhiCor_phi, &b_pfMET_Type1_PhiCor_phi);
   fChain->SetBranchAddress("pfMET_Type1_PhiCor_Px", &pfMET_Type1_PhiCor_Px, &b_pfMET_Type1_PhiCor_Px);
   fChain->SetBranchAddress("pfMET_Type1_PhiCor_Py", &pfMET_Type1_PhiCor_Py, &b_pfMET_Type1_PhiCor_Py);
   fChain->SetBranchAddress("pfMET_Type1_PhiCor_SumEt", &pfMET_Type1_PhiCor_SumEt, &b_pfMET_Type1_PhiCor_SumEt);
   Notify();
}

Bool_t testclass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void testclass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t testclass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef testclass_cxx
