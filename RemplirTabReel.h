#include <stdio.h>
#include <stdlib.h>

void RemplirTabReel(double*T,int N,FILE*pfichier)
{
	int i;
	for(i=1;i<=N;i++)
	  {
	  	fscanf(pfichier,"%lf",T+i);
	  }
}
