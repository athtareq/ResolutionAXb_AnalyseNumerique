#include <stdio.h>
#include <stdlib.h>


double**MatriceReelle(int L,int C)
{
	double*TabReel(int N);
	int i;
	double**M;
	M=(double**)malloc(L*sizeof(double*));
	if(M==NULL)
	  {
	  	printf("MatriceRelle: Pas assez de memoire");
	  	exit(-1);
	  }
	  M--;
	  for(i=1;i<=L;i++)
	     {
	     	*(M+i)=TabReel(C);
		 }
	return M;
}
