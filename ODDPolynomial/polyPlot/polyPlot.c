/*
 * polyPlot.c
 *
 * Code generation for function 'polyPlot'
 *
 * C source code generated on: Tue Jul  1 16:42:21 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "polyPlot.h"
#include "polyfit.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void polyPlot(const emxArray_real_T *x, const emxArray_real_T *y, int32_T degree,
              emxArray_real_T *coeff)
{
  polyfit(x, y, degree, coeff);
}

/* End of code generation (polyPlot.c) */
