#include <stdio.h>
#include <stdlib.h>
void AfficheMatriceReelle(double**M,int L,int C)
{
	int i, j;
	for(i=1;i<=L;i++)
	{
	  	for(j=1;j<=C;j++)
	  	  	printf("%14.12f ",M[i][j]);
	  	printf("\n");
	}
}
