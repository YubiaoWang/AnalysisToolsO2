// This is a template. To use the JetQC.C, rename this file to JetQC_inputs.h and edit it how you want.

// TFile* file_AliAnalysis = new TFile("Datasets/Run2_Ritsuya/ComparisonToLO_R0406.root");
TFile* file_AliAnalysis;


// //////// -------- LHC23zzh - apass 4 with area and leadingtrackpt cuts  - central leadTrackPt 5 - run(IR) comparison - run 544013 6.2kHz removed, as it breaks the monotonous progression, and has less tracks/jets than other low IR runs-------- ////////
// TString* texCollisionDataInfo = new TString("Pb-Pb #sqrt{#it{s}} = 5.36 TeV");
// const TString* texDatasetsComparisonType = new TString("run");
// const TString* texDatasetsComparisonCommonDenominator = new TString("LHC23 golden runs");
// const int nDatasets = 27;
// const TString Datasets[nDatasets] = {"run544124","run544123","run544477","run544392","run544492","run544391","run544122","run544476","run544390","run544098","run544454","run544475","run544121","run544032","run544491","run544095","run544389","run544451","run544510","run544474","run544185","run544091","run544028","run544184","run544116","run544508","run544490"};
// // const TString DatasetsNames[nDatasets] = {"0-10%", "50-90%"};
// const TString DatasetsNames[nDatasets] = {"6.6 kHz - run544124","11 kHz - run544123","13 kHz - run544477","13 kHz - run544392","15 kHz - run544492","15 kHz - run544391","16 kHz - run544122","16 kHz - run544476","18 kHz - run544390","18 kHz - run544098","19 kHz - run544454","19 kHz - run544475","22 kHz - run544121","23 kHz - run544032","24 kHz - run544491","25 kHz - run544095","27 kHz - run544389","28 kHz - run544451","29 kHz - run544510","29 kHz - run544474","29 kHz - run544185","29 kHz - run544091","30 kHz - run544028","32 kHz - run544184","38 kHz - run544116","39 kHz - run544508","43 kHz - run544490"};
// TFile* file_O2Analysis_list[nDatasets] = {new TFile("Datasets/"+Datasets[0]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[1]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[2]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[3]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[4]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[5]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[6]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[7]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[8]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[9]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[10]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[11]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[12]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[13]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[14]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[15]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[16]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[17]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[18]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[19]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[20]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[21]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[22]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[23]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[24]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[25]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[26]+"/AnalysisResults.root")
//                                         };
// // const TString analysisWorkflow[nDatasets] = {"jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156",
// //                                           "jet-spectra-charged_central_id26156"
// //                                           };
// const TString analysisWorkflow[nDatasets] = {"jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis",
//                                           "jet-background-analysis"
//                                           };

// const TString wagonId = "";
// const bool isDatasetWeighted[nDatasets] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
// const std::string histDatasetComparisonStructure = "";
// const bool datasetsAreSubsetsofId0 = false;


// //////// -------- LHC23zzh - apass 4 with area and leadingtrackpt cuts  - central leadTrackPt 5 - run(IR) comparison - run 544013 6.2kHz moved to 2d place, as it has ome issues and puts most ratio above 1, and has less tracks/jets than other low IR runs-------- ////////
// TString* texCollisionDataInfo = new TString("Pb-Pb #sqrt{#it{s}_{NN}} = 5.36 TeV");
// const TString* texDatasetsComparisonType = new TString("run");
// const TString* texDatasetsComparisonCommonDenominator = new TString("Centrality: 50-70%");
// const int nDatasets = 28;
// const TString Datasets[nDatasets] = {"run544124","run544013","run544123","run544477","run544392","run544492","run544391","run544122","run544476","run544390","run544098","run544454","run544475","run544121","run544032","run544491","run544095","run544389","run544451","run544510","run544474","run544185","run544091","run544028","run544184","run544116","run544508","run544490"};
// // const TString DatasetsNames[nDatasets] = {"0-10%", "50-90%"};
// const TString DatasetsNames[nDatasets] = {"6.6 kHz - run544124","6.2 kHz - run544013","11 kHz - run544123","13 kHz - run544477","13 kHz - run544392","15 kHz - run544492","15 kHz - run544391","16 kHz - run544122","16 kHz - run544476","18 kHz - run544390","18 kHz - run544098","19 kHz - run544454","19 kHz - run544475","22 kHz - run544121","23 kHz - run544032","24 kHz - run544491","25 kHz - run544095","27 kHz - run544389","28 kHz - run544451","29 kHz - run544510","29 kHz - run544474","29 kHz - run544185","29 kHz - run544091","30 kHz - run544028","32 kHz - run544184","38 kHz - run544116","39 kHz - run544508","43 kHz - run544490"};
// TFile* file_O2Analysis_list[nDatasets] = {new TFile("Datasets/"+Datasets[0]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[1]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[2]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[3]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[4]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[5]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[6]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[7]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[8]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[9]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[10]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[11]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[12]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[13]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[14]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[15]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[16]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[17]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[18]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[19]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[20]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[21]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[22]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[23]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[24]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[25]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[26]+"/AnalysisResults.root"),
//                                         new TFile("Datasets/"+Datasets[27]+"/AnalysisResults.root")
//                                         };
// const TString analysisWorkflow[nDatasets] = {"jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156",
//                                           "jet-spectra-charged_peripheral_id26156"
//                                           };
// // const TString analysisWorkflow[nDatasets] = {"jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis",
// //                                           "jet-background-analysis"
// //                                           };

// const TString wagonId = "";
// const bool isDatasetWeighted[nDatasets] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
// const std::string histDatasetComparisonStructure = "";
// const bool datasetsAreSubsetsofId0 = false;
// const bool collHistIsObsolete[nDatasets] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};


//////// -------- LHC25b6 - pp sim anchored to PbPb localTest ////////
TString* texCollisionDataInfo = new TString("pp #sqrt{#it{s}} = 13.6 TeV");
const TString* texDatasetsComparisonType = new TString("");
const TString* texDatasetsComparisonCommonDenominator = new TString("");
const int nDatasets = 2;
const TString Datasets[nDatasets] = {"pp13TeV_sim_MB", "pp13TeV_sim_jetjet"};
// const TString DatasetsNames[nDatasets] = {"0-10%", "50-90%"};
const TString DatasetsNames[nDatasets] = {"MB", "jet-jet"};
TFile* file_O2Analysis_list[nDatasets] = {new TFile("Datasets/"+Datasets[0]+"/AnalysisResults.root"),
                                          new TFile("Datasets/"+Datasets[1]+"/AnalysisResults.root")
                                        };

const TString analysisWorkflow[nDatasets] = {"jet-spectra-charged", "jet-spectra-charged",
                                          };

const TString wagonId[nDatasets] = {"", ""
                                    };

const bool isDatasetWeighted[nDatasets] = {false, true};
const std::string histDatasetComparisonStructure = "";
const bool datasetsAreSubsetsofId0 = false;
const bool collHistIsObsolete[nDatasets] = {true, false};
