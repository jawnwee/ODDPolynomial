//
//  ODDPolynomialFit.h
//  ODDPolynomial
//
//  Created by John Lee on 7/1/14.
//  Copyright (c) 2014 OddLook. All rights reserved.
//

double *polynomialFitCoordinates(int entries, double y[], int degree);

double *polynomialFitCoordinatesExtraData(int actualEntries, double y[], int degree, int resultingEntries, double startPadding);