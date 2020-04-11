#include <stdio.h>
#include <stdlib.h>
 double ProdScalaire(double *a , double *b, int n)
 {
	double s = 0.0;
	int i;
	for (i = 1; i <= n; i++) {
		s += (a[i] * b[i]);
	}
	return s;
 }
