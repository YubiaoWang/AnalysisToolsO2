#ifndef FITS_H
#define FITS_H

TGraphErrors* GetFunctionTGraphErrorsFromFitResult(double* xRangeFit, TF1* fitFunctionDrawn, TFitResultPtr fitResult, int nPointsGraph);
TGraphErrors* GetFunctionTGraphErrorsFromCovMatrix(double* xRangeFit, TF1* fitFunctionDrawn, TMatrixDSym* covMatrix, int nPointsGraph);
std::tuple<TF1*, TMatrixDSym, TFitResultPtr> TsallisFit(TH1D* &histogramInput, double* xRangeFit);
std::pair<TH1D*, TGraphErrors*> RebinWithTsallisFit(TH1D* &histogramInput, int nBinsX, double* binsX, double* xRangeFit);
std::tuple<TF1*, TMatrixDSym, TFitResultPtr> ExponentialFitWithLogTransfo(TH1D* &histogramInput, double* xRangeFit);

#endif