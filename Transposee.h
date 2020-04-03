#include<stdio.h>
#include<stdlib.h>

void Transposee(double**A,double **At,int N)
{
  int i,j;
  for(i=1;i<=N;i++)
      for(j=1;j<=N;j++)
    	    At[i][j]=A[j][i];

}

