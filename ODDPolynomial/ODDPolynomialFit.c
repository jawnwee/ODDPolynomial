//
//  ODDPolynomialFit.c
//  ODDPoly
//
//  Created by John Lee on 7/1/14.
//  Copyright (c) 2014 OddLook. All rights reserved.
//

#include <stdio.h>
#include "polyPlot.h"
#include "polyPlot_emxAPI.h"

double *polynomailFitCoordinates(int entries, double y[], int degree) {
    double x[entries];
    for (int i = 0; i < entries; i++) {
        x[i] = i + 1;
    }
    double coeff[degree];
    emxArray_real_T *finalx = emxCreateWrapper_real_T(x, 1, 365);
    emxArray_real_T *finaly = emxCreateWrapper_real_T(y, 1, 365);

    emxArray_real_T *finalCoef = emxCreateWrapper_real_T(coeff, 1, 15);
    polyPlot(finalx, finaly, degree, finalCoef);

    double coefResult[degree];

    for (int i = 0 ; i <= degree; i++) {
        coefResult[i] = finalCoef->data[i];
    }

    double *finalResult = malloc(entries * sizeof(double));
    for (int i = 0; i < entries; i++) {
        double value = 0;
        for (int j = 0; j <= degree; j++) {
            value += coefResult[j]*pow(x[i], degree - j);
        }
        finalResult[i] = value;
    }

    return finalResult;
}