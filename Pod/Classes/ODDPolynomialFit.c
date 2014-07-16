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

double *polynomialFitCoordinatesExtraData(int actualEntries, double y[], int degree, int resultingEntries, double startPadding) {
//    printf("*****************\n");
//    printf("startPadding: %f\t actualEntries: %d\t resultingEntries: %d\n", startPadding, actualEntries, resultingEntries);
    double x[actualEntries];
    for (int i = 0; i < actualEntries; i++) {
        x[i] = i;
//        printf("original value: %f\n", y[i]);
    }
    double coeff[degree];
    emxArray_real_T *finalx = emxCreateWrapper_real_T(x, 1, actualEntries);
    emxArray_real_T *finaly = emxCreateWrapper_real_T(y, 1, actualEntries);
    
    emxArray_real_T *finalCoef = emxCreateWrapper_real_T(coeff, 1, degree);
    polyPlot(finalx, finaly, degree, finalCoef);
    
    double coefResult[degree];
    
    for (int i = 0 ; i <= degree; i++) {
        coefResult[i] = finalCoef->data[i];
//        printf("%.10f\n", coefResult[i]);
    }
    
    double adjustedX[resultingEntries];
    
//    printf("numerator: %f\n", (actualEntries - 1.0 - startPadding));
    for (int i = 0; i < resultingEntries; i++) {
        adjustedX[i] = (i * ((actualEntries - 1.0 - startPadding) / (double)resultingEntries));
        adjustedX[i] += startPadding;
//        printf("adjusted: %.10f\n", adjustedX[i]);
    }
    double *finalResult = malloc(resultingEntries * sizeof(double));
    for (int i = 0; i < resultingEntries; i++) {
        double value = 0;
        for (int j = 0; j <= degree; j++) {
            value += coefResult[j]*pow(adjustedX[i], degree - j);
        }
        finalResult[i] = value;
//        printf("value: %f\n", value);
    }
    
    return finalResult;
}
