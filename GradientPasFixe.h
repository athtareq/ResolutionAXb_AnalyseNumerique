#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GAPF(double**A,double*b,int n,double*x0,double eps,int itermax,double alpha)
 {

	double*TabReel(int N);
	int i,j,it=0;
	double somme;
	double *y,*x1,*r0,*r1,*Ark,*Ar0,*alphakrk,*alphakArk,*Ar1;
	y=TabReel(n);
    x1=TabReel(n);
    r0=TabReel(n);
    r1=TabReel(n);
    Ark=TabReel(n);
    Ar0=TabReel(n);
    Ar1=TabReel(n);
    alphakrk=TabReel(n);
    alphakArk=TabReel(n);
 	ProdMatVect(A,x0,y,n);
    SoustrVect(r0,b,y,n);
    EgaliteVect(r0,r1,n);
    EgaliteVect(x0,x1,n);
    ProdMatVect(A,r0,Ar0,n);
    printf("\n Alpha= %lf",alpha);

    double erreur;
    erreur=Norme2(r0,n);

    //meme demarche que G.P.Optimal

  while(erreur>=eps){

    scalVect(r1,alpha,n,alphakrk);

    SommeVect(x1,alphakrk,n,x1);


    ProdMatVect(A,r1,Ark,n);

    scalVect(Ark,alpha,n,alphakArk);

    SoustrVect(r1,r1,alphakArk,n);



        ProdMatVect(A,r1,Ark,n);

    erreur=Norme2(r1,n);
        it++;

  }


     printf("\n Solution: \n");
     AfficherTabReel(x1,n,1);
         printf("\n Convergence au bout de %d iterations ",it);

//freeTabsReels
 FreeTabReel(r1,n);
 FreeTabReel(Ark,n);
 FreeTabReel(alphakArk,n);
 FreeTabReel(alphakrk,n);
 FreeTabReel(r0,n);

    }




