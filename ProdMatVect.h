#include <stdio.h>
#include <stdlib.h>
 void ProdMatVect(double **A , double *x , double *y, int n)
 {
 	int i , j;
 	double som;
 	for ( i=1; i<=n; i++)
 	    {
 	    	som =0;
 	    	for ( j=1; j<=n; j++)
 	    	     som+= A[i][j]*x[j];
 	    	 y[i]=som;    
 	    	
		 }
 }
