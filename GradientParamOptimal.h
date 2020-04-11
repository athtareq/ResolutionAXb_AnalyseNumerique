#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GAPO(double**A,double*b,int n,double*x0,double eps,int itermax)
 {

	double*TabReel(int N);
	int i,j,it=0;
	double somme;
	double *y,*x1,*r0,*r1,alpha,*Ark,*Ar0,*alphakrk,*alphakArk,*Ar1;
	y=TabReel(n);
    x1=TabReel(n);
    r0=TabReel(n);
    r1=TabReel(n);
    Ark=TabReel(n);
    Ar0=TabReel(n);
    Ar1=TabReel(n);
    alphakrk=TabReel(n);
    alphakArk=TabReel(n);

    //Ax0=y :
 	ProdMatVect(A,x0,y,n);
 	//r0=b-Ax0:
    SoustrVect(r0,b,y,n);
    //copier r0 dans r1
    EgaliteVect(r0,r1,n);
    //coper x0 dans x1
    EgaliteVect(x0,x1,n);
 // alpha dans le cas de k=0:
    //<Ar0,r0>:
    ProdMatVect(A,r0,Ar0,n);
    //Calcul de alpha
    alpha=(Norme2(r0,n))*(Norme2(r0,n))/ProdScalaire(Ar0,r0,n);
    double erreur;
    erreur=Norme2(r0,n);


  while(erreur>=eps){

  //Calcul de alphak.rk qui est r1 pour cette premiere iteration
    scalVect(r1,alpha,n,alphakrk);
  //calcul de x(k+1) qui est x1 dans cette premiere iteration:
    SommeVect(x1,alphakrk,n,x1);
  //Calcul de A.rk
    ProdMatVect(A,r1,Ark,n);
  // alphak.Ark
    scalVect(Ark,alpha,n,alphakArk);
  //calcul de r(k+1), soustraction entre les 2 vecteurs precedents
    SoustrVect(r1,r1,alphakArk,n);
  //Mise a jour de Ark qui change apres changement de r1, Ark necessaire pour alpha
    ProdMatVect(A,r1,Ark,n);
  //Mise a jour de alpha
    alpha=Norme2(r1,n)*(Norme2(r1,n))/ProdScalaire(Ark,r1,n);

  //mise a jour de la norme/erreur
    erreur=Norme2(r1,n);
  //compteur d'iterations, quitter si itermax est depassee
    it++;

  }
     printf("\n Solution: \n");
     AfficherTabReel(x1,n,1);
    printf("\n Convergence au bout de %d iterations ",it);


 FreeTabReel(r1,n);
 FreeTabReel(Ark,n);
 FreeTabReel(alphakArk,n);
 FreeTabReel(alphakrk,n);
 FreeTabReel(r0,n);



    }




