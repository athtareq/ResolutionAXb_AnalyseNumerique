#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void GJ(double**A,double*b,int n,double*x0,double eps,int itermax)
 {

	double*TabReel(int N);
	int i,j,it=0;
	double somme;
	double *y,*x1,*r0,*r1,alpha,*Ark,*Ar0,*alphakrk,*alphakArk,*Ar1;
	double *p0,*Ap0,*p1,beta,*alphakpk,*alphakApk,*Apk,*betapk,*Ap1,*rk;
	y=TabReel(n);
    x1=TabReel(n);
    r0=TabReel(n);
    r1=TabReel(n);
    Ark=TabReel(n);
    Ar0=TabReel(n);
    Ar1=TabReel(n);
    p0=TabReel(n);
    p1=TabReel(n);
    Apk=TabReel(n);
    Ap0=TabReel(n);
    Ap1=TabReel(n);
    rk=TabReel(n);
    alphakrk=TabReel(n);
    alphakArk=TabReel(n);
    alphakpk=TabReel(n);
    betapk=TabReel(n);

    alphakApk=TabReel(n);
 	ProdMatVect(A,x0,y,n);
    SoustrVect(r0,b,y,n);
    EgaliteVect(r0,r1,n);
    EgaliteVect(r0,p0,n);
    EgaliteVect(x0,x1,n);
    EgaliteVect(p0,p1,n);

    ProdMatVect(A,p0,Ap0,n);
    alpha=(Norme2(r0,n))*(Norme2(r0,n))/ProdScalaire(Ap0,p0,n);


    //demarche similaire a G.P.Optimal, sauf qu'il y a l'indroduction de beta
    double erreur;

    erreur=Norme2(r0,n);


        while(erreur>=eps){
            scalVect(p1,alpha,n,alphakpk);

    SommeVect(x1,alphakpk,n,x1);

    ProdMatVect(A,p1,Apk,n);

    scalVect(Apk,alpha,n,alphakApk);

    SoustrVect(r1,r1,alphakApk,n);

    //beta est en fonction de rk et r(k+1), or la variable qui contient
    //rk va s'ecraser apres toute iteration sur la ligne 58, donc il faudrait recuperer
    //la bonne valeur, sachant que rk=r(k+1)+alphak.A.pk
        SommeVect(r1,alphakApk,n,rk);

        beta=(Norme2(r1,n)/Norme2(rk,n))*(Norme2(r1,n)/Norme2(rk,n));
        scalVect(p1,beta,n,betapk);

        SommeVect(r1,betapk,n,p1);

        ProdMatVect(A,p1,Apk,n);

        alpha=Norme2(r1,n)*Norme2(r1,n)/ProdScalaire(Apk,p1,n);
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
 FreeTabReel(p0,n);
  FreeTabReel(p1,n);
 FreeTabReel(Apk,n);
 FreeTabReel(alphakApk,n);
 FreeTabReel(alphakpk,n);
 FreeTabReel(betapk,n);
  FreeTabReel(rk,n);



    }




