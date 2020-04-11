#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SOR(double**A,double*b,int n,double*x0,double eps,double omega,int itermax)
 {

	int i,j,it;
//	it=0;
	double erreur,somme;
	double *y,*x1;
	y=TabReel(n);
    x1=TabReel(n);
    for(i=1;i<=n;i++)
	    x1[i]=x0[i];
	ProdMatVect(A , x1 , y,  n);
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
	   	          somme+=A[i][j]*x1[j];
		      for(j=i+1;j<=n;j++)
	   	          somme+=A[i][j]*x1[j];
	   	      x1[i]=(1-omega)*x1[i] + omega*(b[i]-somme)/A[i][i];
	   	    }
	   	 ProdMatVect(A , x1 , y,  n);
	   	 erreur=NormeInfDif(b,y,n);
	   	 it++;

    if(it>itermax){
    printf("La methode SOR ne converge pas au bout de %d iterations",itermax);
    exit(-1);
    }
        //   getchar();
        //   getchar();

		AfficherTabReel(x1,n,0);
	    printf("\n");
	   }

	printf(" SOR converge apres %d iteration\n",it);
	printf("La solution est\n");
	AfficherTabReel(x1,n,1);

}
