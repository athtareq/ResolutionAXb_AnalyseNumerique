#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ProdMatVect.h"

void GaussSeidel(double**A,double*b,int n,double*x0,double eps,int itermax)
{
	double NormeInfDif(double*x,double*y,int n);
	void AfficherTabReel(double*T,int N,int cas);
	void ProdMatVect(double **A , double *x , double *y, int n);

	double*TabReel(int N);
	int i,j,it=0;
	double erreur,somme;
	double *y;
	y=TabReel(n);
	ProdMatVect(A , x0 , y,  n);
	printf("Produit matrice vecteur \n");
	AfficherTabReel(y,n,0);
     getchar();
     getchar();
	erreur=NormeInfDif(b,y,n);

	AfficherTabReel(x0,n,0);
	printf("\n");

	while(erreur>eps)
	    {

	     for(i=1;i<=n;i++)
	        {
	   	      somme=0.0;
	   	      for(j=1;j<=i-1;j++)
	   	          somme+=A[i][j]*x0[j];
		      for(j=i+1;j<=n;j++)
	   	          somme+=A[i][j]*x0[j];
	   	      x0[i]=(b[i]-somme)/A[i][i];
	   	    }
         ProdMatVect(A , x0 , y,  n);
	   	 erreur=NormeInfDif(b,y,n);
	   	 it++;

    if(it>itermax){
    printf("La methode de Gauss-Seidel ne converge pas au bout de %d iterations",itermax);
    exit(-1);
    }
//getchar();
  //   getchar();

		AfficherTabReel(x0,n,0);
	    printf("\n");
	   }

	printf(" Gauss Seidel converge apres %d iteration\n",it);
	printf("La solution est\n");
	AfficherTabReel(x0,n,1);

}
