#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TSystem.h"
#include "TPRegexp.h"
#include "DYTreeVars.h"

const bool useSmallEventNumber = false;
const int smallEventNumber = 1000;

const TString rootDirName = "recoTree";
const TString treeName = "DYTree";
const TString treeNameFull = TString::Format("%s/%s",rootDirName.Data(), treeName.Data());

const TString signalHLTEle = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v*";
const TString signalHLTMuon1 = "HLT_IsoMu24_v*";
const TString signalHLTMuon2 = "HLT_IsoTkMu24_v*";
const float ptMin = 15;
const float etaMax = 2.4;

enum DecayMode {
  MODE_EE,
  MODE_MUMU,
  MODE_TAUTAU,
  MODE_NONE
};

void configureInputTree(TTree*tree,DecayMode lepType,bool hasGenInfo);
void configureOutputTree(TTree*tree,DecayMode lepType,bool hasGenInfo);
bool PassHLT(DecayMode lepType);

// Main function
void skimGoodEvents(TString pathToFileIn,
		    TString shortFileNameIn,
		    TString skimDirTag,
		    bool preserveEventCount = true){

  // A few info messages
  if( useSmallEventNumber)
    printf("Debug mode: will process only %d events\n", smallEventNumber);

  if( preserveEventCount == true ){
    printf("This processing will preserve event count\n");
  }else{
    printf("This processing will skip events that do not pass selection\n");
  }

  //
  // Open the input file and find the tree
  //
  TString fullFileNameIn = TString::Format("%s/%s", pathToFileIn.Data(), shortFileNameIn.Data());
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

  // Global GEN quantities
  // Check if GEN info is present. It won't be there for data events, for example
  bool hasGenInfo = false;
  TBranch *testBranch = (TBranch*)treeIn->GetListOfBranches()->FindObject("GENEvt_weight");
  if( testBranch ){
    hasGenInfo = true;
    printf("GEN info will be saved\n");
  }else{
    printf("No GEN info is found in the input file, so it won't be saved in the output root files\n");
  }

  //Determine lepton type
  DecayMode lepType = MODE_MUMU;
//  TBranch*testEle = (TBranch*)treeIn->GetListOfBranches()->FindObject("Nelectrons"); 
//  TBranch*testMuon = (TBranch*)treeIn->GetListOfBranches()->FindObject("Nmuons"); 
//  if(testEle && !testMuon) lepType = MODE_EE;
//  else if(testMuon && !testEle) lepType = MODE_MUMU;
//  else lepType = MODE_NONE;

  configureInputTree(treeIn,lepType,hasGenInfo);

  // Note: we cannot write directly to hadoop, the file system does not support
  // writing of a root file from a script. So instead, we create it locally
  // and later copy it.
  TString fileNameOutTmp = "test.root";
  printf("Create a temporary skim file locally\n");
  TFile*fout = new TFile(fileNameOutTmp,"RECREATE");
  TDirectory *dirOut = fout->mkdir(rootDirName);
  dirOut->cd();
  TTree*treeOut = new TTree(treeName, "Skimmed tree");

  configureOutputTree(treeOut,lepType,hasGenInfo);

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
    // Check if this event passes the skim selection criteria
    // HLT check
    bool passHLT = PassHLT(lepType);
    // Check if this event has at least two electrons that pass ID and
    // loose kinematic cuts
    int nGoodLeptons = 0;


	// If the lepton type is not muons, then fill with electron branches
	// If the lepton type is not electron, then fill with muon branches
	// For data, lepton type will be NONE, and so the branches for both
	// Get filled
    	if(lepType==MODE_EE){
	    for(int iLep=0;iLep<Nelectrons;iLep++){
	      if( Electron_pT[iLep] > ptMin && abs(Electron_eta[iLep]) < etaMax
		  && Electron_passMediumID[iLep]==1 ) {
		nGoodLeptons++;
	      }
	    } // end loop over electrons
	}//end if MODE_EE
	else if(lepType==MODE_MUMU){
	    for(int iLep=0;iLep<Nmuons;iLep++){
	      if( Muon_pT[iLep] > ptMin && abs(Muon_eta[iLep]) < etaMax
		  && Muon_passTightID[iLep]==1 ) {
		nGoodLeptons++;
	      }
	    } // end loop over electrons
	}//end if MODE_MUMU

    bool passEnoughGoodLeptons = false;
    if(nGoodLeptons>=2) passEnoughGoodLeptons = true;

    if( ! (passHLT && passEnoughGoodLeptons) ) {
      // Event fails the skimming criteria, but if event count is needed for normalization, 
      // save only the general quantities but empty the electrons array
      if( preserveEventCount ){
	if(lepType==MODE_EE)Nelectrons = 0;
        else if(lepType==MODE_MUMU)nMuon = 0;
	treeOut->Fill();
      }
    } else {
      // Event passed the skimming criteria
      treeOut->Fill();
    }

  }// end loop over events
  printf("\rLooping over events completed\n");

  treeOut->Write();
  delete treeIn;
  fin->Close();

  //
  // Set up output directory, file name, and move the skim file there
  //
  TString dirNameOut = TString::Format("%s/skims_%s", pathToFileIn.Data(), 
				       skimDirTag.Data() );
  // printf("Create output directory\n %s\n", dirNameOut.Data());
  // // The following directory creation comes from sys/stat.h:
  // mode_t dirMode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // Supposed to result in drwxr-xr-x. directory permissions
  // mkdir(dirNameOut.Data(), dirMode);
  // Create short file name
  TString shortFileNameOut = shortFileNameIn;
  // TString suffixOut = TString::Format("_skim_%s.root",skimDirTag.Data());
  // shortFileNameOut.ReplaceAll(".root", suffixOut.Data());
  TString fullFileNameOut = TString::Format("%s/%s", dirNameOut.Data(), shortFileNameOut.Data());
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
  TString gridCopyCommand = TString::Format("eval `scram unsetenv -sh`; gfal-copy -p file:////${PWD}/%s gsiftp://red-gridftp.unl.edu//user/uscms01/pnfs/unl.edu/data4/cms/%s",
					    fileNameOutTmp.Data(), reducedFileNameOut.Data());
  printf("\n\n File name tmp listing:\n");
  TString checkFileCommand = TString::Format("ls -l ${PWD}/%s",fileNameOutTmp.Data() );
  gSystem->Exec(checkFileCommand.Data());
  printf("Executing gridftp copy command:\n");
  printf("%s\n", gridCopyCommand.Data());
  //TString copyCommand = TString::Format("cp %s %s", fileNameOutTmp.Data(), fullFileNameOut.Data());
  gSystem->Exec(gridCopyCommand.Data());
  TString removeCommand = TString::Format("rm %s", fileNameOutTmp.Data());
  gSystem->Exec(removeCommand.Data());

  return;
}

bool PassHLT(DecayMode lepType)
{
	bool passHLT = false;
	int nTriggers = pHLT_trigName->size();
	for(int iHLT=0;iHLT<nTriggers;iHLT++){
		TString trigName = pHLT_trigName->at(iHLT);
		if(lepType==MODE_EE){
			if(trigName.CompareTo(signalHLTEle)==0 && 
			   HLT_trigFired[iHLT]==1) passHLT = true;
		}//end if leptypeEE
		else if(lepType==MODE_MUMU){
			if((trigName.CompareTo(signalHLTMuon1)==0 ||
			    trigName.CompareTo(signalHLTMuon2)==0) && 
			    HLT_trigFired[iHLT]==1) passHLT = true;
		}//end if leptypeMuMu
		else{
			if((trigName.CompareTo(signalHLTMuon1)==0 ||
			    trigName.CompareTo(signalHLTMuon2)==0 ||
			    trigName.CompareTo(signalHLTEle)==0) && 
			    HLT_trigFired[iHLT]==1) passHLT = true;
		} 
	}//end for loop
	return passHLT;
}   

void configureOutputTree(TTree*tree,DecayMode lepType,bool hasGenInfo)
{
  if(lepType==MODE_MUMU){ 
	  tree->Branch("nMuon",&nMuon,"nMuon/I");
	  tree->Branch("Nmuons",&Nmuons,"Nmuons/I");
	  tree->Branch("Muon_pT",&Muon_pT,"Muon_pT[nMuon]/D");
  	  tree->Branch("Muon_Inner_pT",&Muon_Inner_pT,"Muon_Inner_pT[nMuon]/D");
	  tree->Branch("Muon_Px",&Muon_Px,"Muon_Px[nMuon]/D");
	  tree->Branch("Muon_Py",&Muon_Py,"Muon_Py[nMuon]/D");
	  tree->Branch("Muon_Pz",&Muon_Pz,"Muon_Pz[nMuon]/D");
	  tree->Branch("Muon_eta",&Muon_eta,"Muon_eta[nMuon]/D");
	  tree->Branch("Muon_phi",&Muon_phi,"Muon_phi[nMuon]/D");
	  tree->Branch("Muon_charge",&Muon_charge,"Muon_charge[nMuon]/I");
	  tree->Branch("Muon_dxy",&Muon_dxy,"Muon_dxy[nMuon]/D");
	  tree->Branch("Muon_dz",&Muon_dz,"Muon_dz[nMuon]/D");
	  tree->Branch("Muon_passTightID",&Muon_passTightID,"Muon_passTightID[nMuon]/I");

	  tree->Branch("Muon_PfChargedHadronIsoR04", &Muon_PfChargedHadronIsoR04,
			 "Muon_PfChargedHadronIsoR04[nMuon]/D");
	  tree->Branch("Muon_PfNeutralHadronIsoR04", &Muon_PfNeutralHadronIsoR04,
			 "Muon_PfNeutralHadronIsoR04[nMuon]/D");
	  tree->Branch("Muon_PfGammaIsoR04", &Muon_PfGammaIsoR04, "Muon_PfGammaIsoR04[nMuon]/D");
	  tree->Branch("Muon_PFSumPUIsoR04", &Muon_PFSumPUIsoR04, "Muon_PFSumPUIsoR04[nMuon]/D");
	  tree->Branch("Muon_trkiso", &Muon_trkiso, "Muon_trkiso[nMuon]/D");
  }

  if(lepType==MODE_EE){
	  tree->Branch("Nelectrons", &Nelectrons,"Nelectrons/I");
	  tree->Branch("Electron_Energy", &Electron_Energy, "Electron_Energy[Nelectrons]/D");
	  tree->Branch("Electron_pT", &Electron_pT, "Electron_pT[Nelectrons]/D");
	  tree->Branch("Electron_Px", &Electron_Px, "Electron_Px[Nelectrons]/D");
	  tree->Branch("Electron_Py", &Electron_Py, "Electron_Py[Nelectrons]/D");
	  tree->Branch("Electron_Pz", &Electron_Pz, "Electron_Pz[Nelectrons]/D");
	  tree->Branch("Electron_eta", &Electron_eta, "Electron_eta[Nelectrons]/D");
	  tree->Branch("Electron_phi", &Electron_phi, "Electron_phi[Nelectrons]/D");
	  tree->Branch("Electron_charge", &Electron_charge, "Electron_charge[Nelectrons]/I");
	  tree->Branch("Electron_etaSC", &Electron_etaSC, "Electron_etaSC[Nelectrons]/D");
	  tree->Branch("Electron_phiSC", &Electron_phiSC, "Electron_phiSC[Nelectrons]/D");
	  tree->Branch("Electron_dxy", &Electron_dxy, "Electron_dxy[Nelectrons]/D");
	  tree->Branch("Electron_dz", &Electron_dz, "Electron_dz[Nelectrons]/D");
	  tree->Branch("Electron_EnergySC", &Electron_EnergySC, "Electron_EnergySC[Nelectrons]/D");
	  tree->Branch("Electron_etSC", &Electron_etSC, "Electron_etSC[Nelectrons]/D");
	  tree->Branch("Electron_passMediumID", &Electron_passMediumID, "Electron_passMediumID[Nelectrons]/O");
  }
  tree->Branch("vtxTrkCkt1Pt", &vtxTrkCkt1Pt);
  tree->Branch("vtxTrkCkt2Pt", &vtxTrkCkt2Pt);
  tree->Branch("vtxTrkChi2", &vtxTrkChi2);
  tree->Branch("vtxTrkNdof", &vtxTrkNdof);
  tree->Branch("vtxTrkProb",&pvtxTrkProb);
  tree->Branch("PVz",&PVz,"PVz/D");

  tree->Branch("_prefiringweight", &_prefiringweight,"_prefiringweight/D");
  tree->Branch("_prefiringweightup", &_prefiringweightup,"_prefiringweightup/D");
  tree->Branch("_prefiringweightdown", &_prefiringweightdown,"_prefiringweightdown/D");

  tree->Branch("runNum",&runNum,"runNum/I");
  tree->Branch("evtNum",&evtNum,"evtNum/l");
  tree->Branch("lumiBlock",&lumiBlock,"lumiBlock/I");
  tree->Branch("PUweight",&PUweight,"PUweight/D");
  tree->Branch("nVertices",&nVertices,"nVertices/I");

  tree->Branch("nPileUp",&nPileUp,"nPileUp/I");

  // Trigger quantities
  tree->Branch("HLT_ntrig"     , &HLT_ntrig,"HLT_ntrig/I");
  tree->Branch("HLT_trigType" , &HLT_trigType,"HLT_trigType[HLT_ntrig]/I");
  tree->Branch("HLT_trigFired", &HLT_trigFired,"HLT_trigFired[HLT_ntrig]/I");
  tree->Branch("HLT_trigName"  , &HLT_trigName);

  // Global GEN quantities
  if( hasGenInfo ){
    tree->Branch("GENnPair",&GENnPair,"GENnPair/I");
    tree->Branch("GENEvt_weight",&GENEvt_weight,"GENEvt_weight/D");
    tree->Branch("GENEvt_QScale",&GENEvt_QScale,"GENEvt_QScale/D");
    tree->Branch("GENEvt_x1",&GENEvt_x1,"GENEvt_x1/D");
    tree->Branch("GENEvt_x2",&GENEvt_x2,"GENEvt_x2/D");
    tree->Branch("GENEvt_alphaQCD",&GENEvt_alphaQCD,"GENEvt_alphaQCD/D");
    tree->Branch("GENEvt_alphaQED",&GENEvt_alphaQED,"GENEvt_alphaQED/D");

    tree->Branch("GENLepton_eta",&GENLepton_eta,"GENLepton_eta[GENnPair]/D");
    tree->Branch("GENLepton_phi",&GENLepton_phi,"GENLepton_phi[GENnPair]/D");
    tree->Branch("GENLepton_pT",&GENLepton_pT,"GENLepton_pT[GENnPair]/D");
    tree->Branch("GENLepton_ID",&GENLepton_ID,"GENLepton_ID[GENnPair]/I");
    tree->Branch("GENLepton_isHardProcess",&GENLepton_isHardProcess,"GENLepton_isHardProcess[GENnPair]/I");
    tree->Branch("GENLepton_fromHardProcessFinalState",&GENLepton_fromHardProcessFinalState,"GENLepton_fromHardProcessFinalState[GENnPair]/I");
    tree->Branch("GENLepton_isPromptFinalState", &GENLepton_isPromptFinalState,"GENLepton_isPromptFinalState[GENnPair]/I");

  //Gen others
  tree->Branch("nGenOthers",&nGenOthers,"nGenOthers/I");
  tree->Branch("GenOthers_phi",&GenOthers_phi,"GenOthers_phi[nGenOthers]/D");
  tree->Branch("GenOthers_eta",&GenOthers_eta,"GenOthers_eta[nGenOthers]/D");
  tree->Branch("GenOthers_pT",&GenOthers_pT,"GenOthers_pT[nGenOthers]/D");
  tree->Branch("GenOthers_Px",&GenOthers_Px,"GenOthers_Px[nGenOthers]/D");
  tree->Branch("GenOthers_Py",&GenOthers_Py,"GenOthers_Py[nGenOthers]/D");
  tree->Branch("GenOthers_Pz",&GenOthers_Pz,"GenOthers_Pz[nGenOthers]/D");
  tree->Branch("GenOthers_E",&GenOthers_E,"GenOthers_E[nGenOthers]/D");
  tree->Branch("GenOthers_ID",&GenOthers_ID,"GenOthers_ID[nGenOthers]/I");
  tree->Branch("GenOthers_isHardProcess",&GenOthers_isHardProcess,"GenOthers_isHardProcess[nGenOthers]/I");
  tree->Branch("GenOthers_isPromptFinalState",&GenOthers_isPromptFinalState,"GenOthers_isPromptFinalState[nGenOthers]/I");
  }
return;
}

void configureInputTree(TTree*tree,DecayMode lepType,bool hasGenInfo)
{
  if(lepType==MODE_MUMU){ 
	  tree->SetBranchAddress("nMuon",&nMuon,&b_nMuon);
	  tree->SetBranchAddress("Nmuons",&Nmuons,&b_Nmuons);
	  tree->SetBranchAddress("PVz",&PVz,&b_PVz);
	  tree->SetBranchAddress("Muon_pT",&Muon_pT,&b_Muon_pT);
	  tree->SetBranchAddress("Muon_Inner_pT",&Muon_Inner_pT,&b_Muon_Inner_pT);
	  tree->SetBranchAddress("Muon_Px",&Muon_Px,&b_Muon_Px);
	  tree->SetBranchAddress("Muon_Py",&Muon_Py,&b_Muon_Py);
	  tree->SetBranchAddress("Muon_Pz",&Muon_Pz,&b_Muon_Pz);
	  tree->SetBranchAddress("Muon_eta",&Muon_eta,&b_Muon_eta);
	  tree->SetBranchAddress("Muon_phi",&Muon_phi,&b_Muon_phi);
	  tree->SetBranchAddress("Muon_charge",&Muon_charge,&b_Muon_charge);
	  tree->SetBranchAddress("Muon_dxy",&Muon_dxy,&b_Muon_dxy);
	  tree->SetBranchAddress("Muon_dz",&Muon_dz,&b_Muon_dz);
	  tree->SetBranchAddress("Muon_passTightID",&Muon_passTightID,&b_Muon_passTightID);
	  tree->SetBranchAddress("Muon_PfChargedHadronIsoR04", Muon_PfChargedHadronIsoR04,
				   &b_Muon_PfChargedHadronIsoR04);
	  tree->SetBranchAddress("Muon_PfNeutralHadronIsoR04", Muon_PfNeutralHadronIsoR04,
				   &b_Muon_PfNeutralHadronIsoR04);
	  tree->SetBranchAddress("Muon_PfGammaIsoR04", Muon_PfGammaIsoR04, &b_Muon_PfGammaIsoR04);
	  tree->SetBranchAddress("Muon_PFSumPUIsoR04", Muon_PFSumPUIsoR04, &b_Muon_PFSumPUIsoR04);
	  tree->SetBranchAddress("Muon_trkiso", Muon_trkiso, &b_Muon_trkiso);
  }
  if(lepType==MODE_EE){
  	  tree->SetBranchAddress("Nelectrons", &Nelectrons, &b_Nelectrons);
	  tree->SetBranchAddress("Electron_Energy",&Electron_Energy,&b_Electron_Energy);
	  tree->SetBranchAddress("Electron_pT",&Electron_pT,&b_Electron_pT);
	  tree->SetBranchAddress("Electron_Px",&Electron_Px,&b_Electron_Px);
	  tree->SetBranchAddress("Electron_Py",&Electron_Py,&b_Electron_Py);
	  tree->SetBranchAddress("Electron_Pz",&Electron_Pz,&b_Electron_Pz);
	  tree->SetBranchAddress("Electron_eta",&Electron_eta,&b_Electron_eta);
	  tree->SetBranchAddress("Electron_phi",&Electron_phi,&b_Electron_phi);
	  tree->SetBranchAddress("Electron_charge",&Electron_charge,&b_Electron_charge);
	  tree->SetBranchAddress("Electron_etaSC",&Electron_etaSC,&b_Electron_etaSC);
	  tree->SetBranchAddress("Electron_phiSC",&Electron_phiSC,&b_Electron_phiSC);
	  tree->SetBranchAddress("Electron_dxy",&Electron_dxy,&b_Electron_dxy);
	  tree->SetBranchAddress("Electron_dz",&Electron_dz,&b_Electron_dz);
	  tree->SetBranchAddress("Electron_EnergySC",&Electron_EnergySC,&b_Electron_EnergySC);
	  tree->SetBranchAddress("Electron_etSC",&Electron_etSC,&b_Electron_etSC);
	  tree->SetBranchAddress("Electron_passMediumID",&Electron_passMediumID,&b_Electron_passMediumID);
  }

  tree->SetBranchAddress("vtxTrkCkt1Pt", &pvtxTrkCkt1Pt);
  tree->SetBranchAddress("vtxTrkCkt2Pt", &pvtxTrkCkt2Pt);
  tree->SetBranchAddress("vtxTrkChi2",   &pvtxTrkChi2);
  tree->SetBranchAddress("vtxTrkNdof",   &pvtxTrkNdof);
  tree->SetBranchAddress("vtxTrkProb",&pvtxTrkProb);

  tree->SetBranchAddress("_prefiringweight", &_prefiringweight,     &b__prefiringweight);
  tree->SetBranchAddress("_prefiringweightup", &_prefiringweightup,   &b__prefiringweightup);
  tree->SetBranchAddress("_prefiringweightdown", &_prefiringweightdown, &b__prefiringweightdown);

  tree->SetBranchAddress("runNum"    , &runNum    , &b_runNum);
  tree->SetBranchAddress("evtNum"    , &evtNum    , &b_evtNum);
  tree->SetBranchAddress("lumiBlock" , &lumiBlock , &b_lumiBlock);
  tree->SetBranchAddress("PUweight"  , &PUweight  , &b_PUweight);
  tree->SetBranchAddress("nVertices" , &nVertices , &b_nVertices);

  tree->SetBranchAddress("nPileUp"   ,&nPileUp    , &b_nPileUp);

  tree->SetBranchAddress("HLT_ntrig", &HLT_ntrig, &b_HLT_ntrig);
  tree->SetBranchAddress("HLT_trigType", &HLT_trigType, &b_HLT_trigType);
  tree->SetBranchAddress("HLT_trigFired", &HLT_trigFired, &b_HLT_trigFired);
  tree->SetBranchAddress("HLT_trigName", &pHLT_trigName);

  if(hasGenInfo){
    tree->SetBranchAddress("GENnPair",&GENnPair,&b_GENnPair);
    tree->SetBranchAddress("GENEvt_weight",&GENEvt_weight,&b_GENEvt_weight);
    tree->SetBranchAddress("GENEvt_QScale",&GENEvt_QScale,&b_GENEvt_QScale);
    tree->SetBranchAddress("GENEvt_x1",&GENEvt_x1,&b_GENEvt_x1);
    tree->SetBranchAddress("GENEvt_x2",&GENEvt_x2,&b_GENEvt_x2);
    tree->SetBranchAddress("GENEvt_alphaQCD",&GENEvt_alphaQCD,&b_GENEvt_alphaQCD);
    tree->SetBranchAddress("GENEvt_alphaQED",&GENEvt_alphaQED,&b_GENEvt_alphaQED);

    tree->SetBranchAddress("GENLepton_eta",&GENLepton_eta,&b_GENLepton_eta);
    tree->SetBranchAddress("GENLepton_phi",&GENLepton_phi,&b_GENLepton_phi);
    tree->SetBranchAddress("GENLepton_pT",&GENLepton_pT,&b_GENLepton_pT);
    tree->SetBranchAddress("GENLepton_ID",&GENLepton_ID,&b_GENLepton_ID);
    tree->SetBranchAddress("GENLepton_isHardProcess",&GENLepton_isHardProcess,&b_GENLepton_isHardProcess);
    tree->SetBranchAddress("GENLepton_fromHardProcessFinalState",&GENLepton_fromHardProcessFinalState,&b_GENLepton_fromHardProcessFinalState);
    tree->SetBranchAddress("GENLepton_isPromptFinalState",&GENLepton_isPromptFinalState,&b_GENLepton_isPromptFinalState);

  //Gen others
  tree->SetBranchAddress("nGenOthers",    &nGenOthers,   &b_nGenOthers);
  tree->SetBranchAddress("GenOthers_phi", &GenOthers_phi,&b_GenOthers_phi);
  tree->SetBranchAddress("GenOthers_eta", &GenOthers_eta,&b_GenOthers_eta);
  tree->SetBranchAddress("GenOthers_pT",  &GenOthers_pT, &b_GenOthers_pT);
  tree->SetBranchAddress("GenOthers_Px",  &GenOthers_Px, &b_GenOthers_Px);
  tree->SetBranchAddress("GenOthers_Py",  &GenOthers_Py, &b_GenOthers_Py);
  tree->SetBranchAddress("GenOthers_Pz",  &GenOthers_Pz, &b_GenOthers_Pz);
  tree->SetBranchAddress("GenOthers_E",   &GenOthers_E,  &b_GenOthers_E );
  tree->SetBranchAddress("GenOthers_ID",  &GenOthers_ID, &b_GenOthers_ID);
  tree->SetBranchAddress("GenOthers_isHardProcess",&GenOthers_isHardProcess,
			   &b_GenOthers_isHardProcess);
  tree->SetBranchAddress("GenOthers_isPromptFinalState",&GenOthers_isPromptFinalState, &b_GenOthers_isPromptFinalState);
  }//end if hasGenInfo
  return;
}
