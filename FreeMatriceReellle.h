#include <stdio.h>
#include <stdlib.h>
void FreeMatriceReelle(double**M,int L,int C)
{
	void FreeTabReel(double*T,int N);
	int i;
	for(i=1;i<=L;i++)
	   	FreeTabReel(M[i],C);
	free(M+1);
}
