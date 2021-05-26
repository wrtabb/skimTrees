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

const TString signalHLTType = "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v*";
const float ptMin = 15;
const float etaMax = 2.5;

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


  //
  // Set up branches for input tree
  //
  treeIn->SetBranchAddress("nMuon",&nMuon,&b_nMuon);
  treeIn->SetBranchAddress("Nmuons",&Nmuons,&b_Nmuons);
  treeIn->SetBranchAddress("PVz",&PVz,&b_PVz);
  treeIn->SetBranchAddress("Muon_pT",&Muon_pT,&b_Muon_pT);
  treeIn->SetBranchAddress("Muon_Px",&Muon_Px,&b_Muon_Px);
  treeIn->SetBranchAddress("Muon_Py",&Muon_Py,&b_Muon_Py);
  treeIn->SetBranchAddress("Muon_Pz",&Muon_Pz,&b_Muon_Pz);
  treeIn->SetBranchAddress("Muon_eta",&Muon_eta,&b_Muon_eta);
  treeIn->SetBranchAddress("Muon_phi",&Muon_phi,&b_Muon_phi);
  treeIn->SetBranchAddress("Muon_charge",&Muon_charge,&b_Muon_charge);
  treeIn->SetBranchAddress("Muon_dxy",&Muon_dxy,&b_Muon_dxy);
  treeIn->SetBranchAddress("Muon_dz",&Muon_dz,&b_Muon_dz);
  treeIn->SetBranchAddress("Muon_passTightID",&Muon_passTightID,&b_Muon_passTightID);

  treeIn->SetBranchAddress("vtxTrkCkt1Pt", &pvtxTrkCkt1Pt);
  treeIn->SetBranchAddress("vtxTrkCkt2Pt", &pvtxTrkCkt2Pt);
  treeIn->SetBranchAddress("vtxTrkChi2",   &pvtxTrkChi2);
  treeIn->SetBranchAddress("vtxTrkNdof",   &pvtxTrkNdof);

  treeIn->SetBranchAddress("Muon_PfChargedHadronIsoR04", Muon_PfChargedHadronIsoR04,
                           &b_Muon_PfChargedHadronIsoR04);
  treeIn->SetBranchAddress("Muon_PfNeutralHadronIsoR04", Muon_PfNeutralHadronIsoR04,
                           &b_Muon_PfNeutralHadronIsoR04);
  treeIn->SetBranchAddress("Muon_PfGammaIsoR04", Muon_PfGammaIsoR04, &b_Muon_PfGammaIsoR04);
  treeIn->SetBranchAddress("Muon_PFSumPUIsoR04", Muon_PFSumPUIsoR04, &b_Muon_PFSumPUIsoR04);
  treeIn->SetBranchAddress("Muon_trkiso", Muon_trkiso, &b_Muon_trkiso);


  treeIn->SetBranchAddress("_prefiringweight", &_prefiringweight,     &b__prefiringweight);
  treeIn->SetBranchAddress("_prefiringweightup", &_prefiringweightup,   &b__prefiringweightup);
  treeIn->SetBranchAddress("_prefiringweightdown", &_prefiringweightdown, &b__prefiringweightdown);

  treeIn->SetBranchAddress("runNum"    , &runNum    , &b_runNum);
  treeIn->SetBranchAddress("evtNum"    , &evtNum    , &b_evtNum);
  treeIn->SetBranchAddress("lumiBlock" , &lumiBlock , &b_lumiBlock);
  treeIn->SetBranchAddress("PUweight"  , &PUweight  , &b_PUweight);
  treeIn->SetBranchAddress("Nelectrons", &Nelectrons, &b_Nelectrons);
  treeIn->SetBranchAddress("nVertices" , &nVertices , &b_nVertices);

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
  if( hasGenInfo ){
    treeIn->SetBranchAddress("GENEvt_weight"        ,&GENEvt_weight        , &b_GENEvt_weight  );
    treeIn->SetBranchAddress("GENEvt_QScale"        ,&GENEvt_QScale        , &b_GENEvt_QScale  );
    treeIn->SetBranchAddress("GENEvt_x1"            ,&GENEvt_x1            , &b_GENEvt_x1      );
    treeIn->SetBranchAddress("GENEvt_x2"            ,&GENEvt_x2            , &b_GENEvt_x2      );
    treeIn->SetBranchAddress("GENEvt_alphaQCD"      ,&GENEvt_alphaQCD      , &b_GENEvt_alphaQCD);
    treeIn->SetBranchAddress("GENEvt_alphaQED"      ,&GENEvt_alphaQED      , &b_GENEvt_alphaQED);

  treeIn->SetBranchAddress("GENLepton_eta",&GENLepton_eta,&b_GENLepton_eta);
  treeIn->SetBranchAddress("GENLepton_phi",&GENLepton_phi,&b_GENLepton_phi);
  treeIn->SetBranchAddress("GENLepton_pT",&GENLepton_pT,&b_GENLepton_pT);
  treeIn->SetBranchAddress("GENLepton_ID",&GENLepton_ID,&b_GENLepton_ID);
  treeIn->SetBranchAddress("GENLepton_isHardProcess",&GENLepton_isHardProcess,&b_GENLepton_isHardProcess);
  treeIn->SetBranchAddress("GENLepton_fromHardProcessFinalState",&GENLepton_fromHardProcessFinalState,&b_GENLepton_fromHardProcessFinalState);
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
  treeOut->Branch("nMuon",&nMuon,"nMuon/I");
  treeOut->Branch("Nmuons",&Nmuons,"Nmuons/I");
  treeOut->Branch("PVz",&PVz,"PVz/D");
  treeOut->Branch("Muon_pT",&Muon_pT,"Muon_pT/D");
  treeOut->Branch("Muon_Px",&Muon_Px,"Muon_Px/D");
  treeOut->Branch("Muon_Py",&Muon_Py,"Muon_Py/D");
  treeOut->Branch("Muon_Pz",&Muon_Pz,"Muon_Pz/D");
  treeOut->Branch("Muon_eta",&Muon_eta,"Muon_eta/D");
  treeOut->Branch("Muon_phi",&Muon_phi,"Muon_phi/D");
  treeOut->Branch("Muon_charge",&Muon_charge,"Muon_charge/I");
  treeOut->Branch("Muon_dxy",&Muon_dxy,"Muon_dxy/D");
  treeOut->Branch("Muon_dz",&Muon_dz,"Muon_dz/D");
  treeOut->Branch("Muon_passTightID",&Muon_passTightID,"Muon_passTightID/I");

  treeOut->Branch("Muon_PfChargedHadronIsoR04", Muon_PfChargedHadronIsoR04,
                 "Muon_PfChargedHadronIsoR04/D");
  treeOut->Branch("Muon_PfNeutralHadronIsoR04", Muon_PfNeutralHadronIsoR04,
                 "Muon_PfNeutralHadronIsoR04/D");
  treeOut->Branch("Muon_PfGammaIsoR04", Muon_PfGammaIsoR04, "Muon_PfGammaIsoR04/D");
  treeOut->Branch("Muon_PFSumPUIsoR04", Muon_PFSumPUIsoR04, "Muon_PFSumPUIsoR04/D");
  treeOut->Branch("Muon_trkiso", Muon_trkiso, "Muon_trkiso/D");

  treeOut->Branch("vtxTrkCkt1Pt", &vtxTrkCkt1Pt);
  treeOut->Branch("vtxTrkCkt2Pt", &vtxTrkCkt2Pt);
  treeOut->Branch("vtxTrkChi2", &vtxTrkChi2);
  treeOut->Branch("vtxTrkNdof", &vtxTrkNdof);

  treeOut->Branch("_prefiringweight", &_prefiringweight,"_prefiringweight/D");
  treeOut->Branch("_prefiringweightup", &_prefiringweightup,"_prefiringweightup/D");
  treeOut->Branch("_prefiringweightdown", &_prefiringweightdown,"_prefiringweightdown/D");

  treeOut->Branch("runNum",&runNum,"runNum/I");
  treeOut->Branch("evtNum",&evtNum,"evtNum/l");
  treeOut->Branch("lumiBlock",&lumiBlock,"lumiBlock/I");
  treeOut->Branch("PUweight",&PUweight,"PUweight/D");
  treeOut->Branch("Nelectrons", &Nelectrons,"Nelectrons/I");
  treeOut->Branch("nVertices",&nVertices,"nVertices/I");

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

  // Global GEN quantities
  if( hasGenInfo ){
    treeOut->Branch("GENEvt_weight",&GENEvt_weight,"GENEvt_weight/D");
    treeOut->Branch("GENEvt_QScale",&GENEvt_QScale,"GENEvt_QScale/D");
    treeOut->Branch("GENEvt_x1",&GENEvt_x1,"GENEvt_x1/D");
    treeOut->Branch("GENEvt_x2",&GENEvt_x2,"GENEvt_x2/D");
    treeOut->Branch("GENEvt_alphaQCD",&GENEvt_alphaQCD,"GENEvt_alphaQCD/D");
    treeOut->Branch("GENEvt_alphaQED",&GENEvt_alphaQED,"GENEvt_alphaQED/D");

    treeOut->Branch("GENLepton_eta",&GENLepton_eta,"GENLepton_eta/D");
    treeOut->Branch("GENLepton_phi",&GENLepton_phi,"GENLepton_phi/D");
    treeOut->Branch("GENLepton_pT",&GENLepton_pT,"GENLepton_pT/D");
    treeOut->Branch("GENLepton_ID",&GENLepton_ID,"GENLepton_ID/I");
    treeOut->Branch("GENLepton_isHardProcess",&GENLepton_isHardProcess,"GENLepton_isHardProcess/I");
    treeOut->Branch("GENLepton_fromHardProcessFinalState",&GENLepton_fromHardProcessFinalState,"GENLepton_fromHardProcessFinalState/I");
  }

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
    //if( iEvent%(nEvents/100) == 0 ){
    //  printf("\rLooping over events progress %.1f%%", (iEvent*100./nEvents)); fflush(stdout);
   // }

    // Check if this event passes the skim selection criteria
    // HLT check
    bool passHLT = false;
    for(uint iHLT=0; iHLT < pHLT_trigName->size(); iHLT++){
      TString trigName = pHLT_trigName->at(iHLT);
      if(trigName.CompareTo(signalHLTType)==0 && HLT_trigFired[iHLT]==1){ // compareTo returns 0 for exact match
	passHLT = true;
      }
    } // end loop over HLT trigger lines
    
    // Check if this event has at least two electrons that pass ID and
    // loose kinematic cuts
    int nGoodElectrons = 0;
    for(int iEle=0;iEle<Nelectrons;iEle++){
      if( Electron_pT[iEle] > ptMin && abs(Electron_eta[iEle]) < etaMax
	  && Electron_passMediumID[iEle]==1 ) {
	nGoodElectrons++;
      }
    } // end loop over electrons
    bool passEnoughGoodElectrons = false;
    if( nGoodElectrons >= 2 )
      passEnoughGoodElectrons = true;

    if( ! (passHLT && passEnoughGoodElectrons) ) {
      // Event fails the skimming criteria, but if event count is needed for normalization, 
      // save only the general quantities but empty the electrons array
      if( preserveEventCount ){
	Nelectrons = 0;
	treeOut->Fill();
      }
    } else {
      // Event passed the skimming criteria
      treeOut->Fill();
    }

  }
  printf("\rLooping over events completed               \n");

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
