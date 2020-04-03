#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NormeInfDif.h"

void Jacobi(double**A,double*b,int n,double*x0,double eps,int itermax)
{
	double NormeInfDif(double*x,double*y,int n);
	void AfficherTabReel(double*T,int N,int cas);

	double*TabReel(int N);
	int i,j,it;
	double erreur,somme;
	double *x1;
	x1=TabReel(n);
	for(i=1;i<=n;i++)
	   {
	   	somme=0.0;
	   	for(j=1;j<=i-1;j++)
	   	   somme+=A[i][j]*x0[j];
		for(j=i+1;j<=n;j++)
	   	   somme+=A[i][j]*x0[j];
	   	x1[i]=(b[i]-somme)/A[i][i];

	}
	it=1;
	erreur=NormeInfDif(x0,x1,n);

	AfficherTabReel(x1,n,0);
	printf("\n");

	while(erreur>eps)
	    {
	    	for(i=1;i<=n;i++)
	    	   x0[i]=x1[i];
	    	   for(i=1;i<=n;i++)
	   {
	   	somme=0.0;
	   	for(j=1;j<=i-1;j++)
	   	   somme+=A[i][j]*x0[j];
		for(j=i+1;j<=n;j++)
	   	   somme+=A[i][j]*x0[j];
	   	x1[i]=(b[i]-somme)/A[i][i];
	   	erreur=NormeInfDif(x0,x1,n);
	   	 it++;
	   	 if(it>itermax){
    printf("La methode de Jacobi ne converge pas au bout de %d iterations",itermax);
    exit(-1);
    }

		AfficherTabReel(x1,n,0);
	    printf("\n");
	}
		}



	printf(" Jacobi converge apres %d iteration\n",it);
	printf("La solution est\n");
	AfficherTabReel(x1,n,1);

}
