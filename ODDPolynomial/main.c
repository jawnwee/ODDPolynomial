//
//  main.c
//  TestPoly
//
//  Created by John Lee on 7/1/14.
//  Copyright (c) 2014 OddLook. All rights reserved.
//

#include <stdio.h>
#include "polyPlot.h"
#include "polyPlot_emxAPI.h"
#include "ODDPolynomialFit.h"

/* Test function for Polynomial fits */
int main(int argc, const char * argv[]) {
    // insert code here...
    int XEntries = 3;
    double x[XEntries];
    for (int i = 0; i < XEntries; i++) {
        x[i] = i + 1;
    }
    double y[] = {5, 1, 2, 3, 4, 1, 2, 4, 2, 1, 2, 4, 2, 1, 4, 2, 5, 2, 1, 4, 2, 1 ,4 ,2 ,3 ,4 ,1 ,2 ,3, 1, 2};
//    double *result = polynomialFitCoordinates(XEntries, y, 7);
//    for (int i = 0 ; i < XEntries; i++) {
//        printf("%d, %f\n", i, result[i]);
    double *resultExtraDataTwo = polynomialFitCoordinatesExtraData(31, y, 7, 20, 14);
    for (int i = 0 ; i < 20; i++) {
        printf("%d, %f\n", i, resultExtraDataTwo[i]);
    }

    return 0;
}
