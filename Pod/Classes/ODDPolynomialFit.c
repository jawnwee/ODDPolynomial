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

double *polynomialFitCoordinates(int entries, double y[], int degree) {
    double x[entries];
    for (int i = 0; i < entries; i++) {
        x[i] = i + 1;
    }
    double coeff[degree];
    emxArray_real_T *finalx = emxCreateWrapper_real_T(x, 1, entries);
    emxArray_real_T *finaly = emxCreateWrapper_real_T(y, 1, entries);

    emxArray_real_T *finalCoef = emxCreateWrapper_real_T(coeff, 1, degree);
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

double *polynomialFitCoordinatesExtraData(int entries, double y[], int degree, int factor) {
    double x[entries];
    for (int i = 0; i < entries; i++) {
        x[i] = i + 1;
    }
    double coeff[degree];
    emxArray_real_T *finalx = emxCreateWrapper_real_T(x, 1, entries);
    emxArray_real_T *finaly = emxCreateWrapper_real_T(y, 1, entries);

    emxArray_real_T *finalCoef = emxCreateWrapper_real_T(coeff, 1, degree);
    polyPlot(finalx, finaly, degree, finalCoef);

    double coefResult[degree];

    for (int i = 0 ; i <= degree; i++) {
        coefResult[i] = finalCoef->data[i];
    }
    double adjustedX[entries * factor];
    for (int i = 0; i < entries * factor; i ++) {
        adjustedX[i] = ((double)i / factor) + 1.0;
    }
    double *finalResult = malloc(factor * entries * sizeof(double));
    for (int i = 0; i < entries * factor; i++) {
        double value = 0;
        for (int j = 0; j <= degree; j++) {
            value += coefResult[j]*pow(adjustedX[i], degree - j);
        }
        finalResult[i] = value;
    }

    return finalResult;
}
