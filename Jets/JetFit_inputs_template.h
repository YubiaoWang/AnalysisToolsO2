// This is a template. To use the JetFit_DrawingMacro.C, rename this file to JetFit_inputs.h and edit it how you want.



//////// Full jets analysis from run 2, pp 5.02 TeV R=0.6 https://www.hepdata.net/record/ins1755387 ////////
TString* texCollisionDataInfo = new TString("pp #sqrt{#it{s}} = 13.6 TeV");
const TString* texDatasetsComparisonType = new TString("");
const TString* texDatasetsComparisonCommonDenominator = new TString("");

TFile* file_O2Analysis_list = new TFile("HEPData-ins1755387-v2-Table_6.root");
