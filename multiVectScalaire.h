#include <stdio.h>
#include <stdlib.h>
 void scalVect(double *x , double s, int n, double*z)
 {
    int i;
	for (i = 1; i <= n; i++) {
		z[i] = s * x[i];
	}
 }
