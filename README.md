kimTrees
This repository exists to produce skimmed versions of ntuples for my Drell-Yan analysis. This is carried out in four steps:
1. Mass Truncation
2. Lepton Splitting
3. Skim All
4. Combine Skims

## 1. Mass Truncation
Certain samples exist here without an upper bound on mass even though there is a range above that, for example DYLL_M50toInf exists even though there's a DYLL_M100to200 as well. This step simply truncates the mass of the sample with "infinite" range at the value of the next sample.

## 2. Lepton Splitting
The DYLL samples are split into electron (EE), muon (MuMu), and tau lepton (TauTau) samples. We use electrons and muons as signal, but each has different weights and cuts to apply. Tau lepton samples are considered a source of background. 

## 3. Skim All
This is the final skimming step. This step takes each sample, including those that have had their masses truncated and their leptons split into different samples, and removes unwanted information to decrease the size of the files. 
