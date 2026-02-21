#ifndef FITS_H
#define FITS_H

#include "TGraph.h"

TGraphErrors* getFunctionTGraphErrorsFromFitResult(double* xRangeFit, TF1* fitFunctionDrawn, TFitResultPtr fitResult, int nPointsGraph = 1000);
TGraphErrors* getFunctionTGraphErrorsFromCovMatrix(double* xRangeFit, TF1* fitFunctionDrawn, TMatrixDSym* covMatrix, int nPointsGraph = 1000);
std::tuple<TF1*, TMatrixDSym, TFitResultPtr> TsallisFit(TH1D* &histogramInput, double* xRangeFit);
std::pair<TH1D*, TGraphErrors*> RebinWithTsallisFit(TH1D* &histogramInput, int nBinsX, double* binsX, double* xRangeFit);
std::tuple<TF1*, TMatrixDSym, TFitResultPtr> exponentialFitWithLog(TH1D* &histogramInput, double* xRangeFit);

#endif