#include <stdio.h>
#include <stdlib.h>

void RemplirMatrcieReelle(double**M,int L,int C,FILE*pfichier)
{
	int i,j;
	for(i=1;i<=L;i++)
	  	for(j=1;j<=C;j++)
	  	  	fscanf(pfichier,"%lf",*(M+i)+j);
}
