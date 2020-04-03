#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "AfficheTabReel.h"
#include "AfficheMatriceReelle.h"
#include "TabReel.h"
#include "MatriceReelle.h"
#include "RemplirTabReel.h"
#include "RemplirMatriceReelle.h"
#include "TabEntier.h"
#include "Transposee.h"
#include "FreeMatriceReellle.h"
#include "FreeTabReel.h"
#include "FreeTabEntier.h"
#include "gauss.h"
#include "Jacobi.h"
#include "GaussSeidel.h"
#include "SOR.h"
#include "GaussPivotPartiel.h"
#include "GaussPivotTotal.h"
#include "DecompLU.h"
#include "Cholesky.h"



int main()
{

        int n;
        double**A;
        double*b;
        double*x0;
    	int N,i;
	    char c;
        double eps,omega;
        int typeMeth,choixDir,choixIt;
        int itermax;
        int rep=1;

        int *T;
        void menu();
        void menuP();
        printf("\t \t \t RESOLUTION NUMERIQUE DE Ax=b\n\n");
        printf("On considere un systeme lineaire Ax=b, A est une matrice carree d'ordre N et b est un vecteur de taille N.");
        printf("Les donnees: N (dimension de la matrice), A(matrice), b(vecteur), X0(vecteur), le parametre Omega, Itermax ");
        printf("(nombre maximal d'iterations) et eps(precision) sont stockes dans un fichier. \n");
        printf("La resolution de ce systeme lineaire sera faite par les methodes directes et iteratives \n");
        printf("Appuyer sur la touche <ENTREE> pour continuer \n");
        getchar();
//Fichier
do{
    char nomfichier[20];
    FILE*pfichier;
    pfichier=NULL;
    do{printf("Saisir le nom du fichier: ");
    scanf("%s", nomfichier);
    printf("Le nom du fichier est: %s \n", nomfichier);
	 pfichier=fopen(nomfichier,"r");
	 if(pfichier==NULL)
	 {
	 	printf("Fichier introuvable ou pas de droit pour l'ouvrir\n");
	 	//exit(-1);
	 }
	 }while(pfichier==NULL);

	fscanf(pfichier,"%d",&n);

	printf("Les donnees du systeme lineaire sont: \n");

	//Donnees de la matrice

	printf("L'ordre de la matrice N = %d\n",n);
	A=MatriceReelle(n,n);
	b=TabReel(n);
	x0=TabReel(n);
	RemplirMatrcieReelle(A,n,n,pfichier);
	printf("\n La matrice A est: \n");
	AfficheMatriceReelle(A,n,n);
	getchar();
	RemplirTabReel(b,n,pfichier);
    RemplirTabReel(x0,n,pfichier);
	printf("\n Le second membre b est: \n");
	AfficherTabReel(b,n,0);
	getchar();
	printf("\n X0 est: \n");
	AfficherTabReel(x0,n,0);
    printf("\n");
    printf("\n");
//omega, precision et itermax
    getchar();
        fscanf(pfichier,"%lf",&omega);
        printf("La valeur de omega : %lf \n ",omega);
        fscanf(pfichier,"%c",&c);
        while(c!='\n')
           fscanf(pfichier,"%c",&c);
	getchar();
        fscanf(pfichier,"%d",&itermax);
        printf("Le nombre maximal des iterations: %d \n",itermax);
        fscanf(pfichier,"%c",&c);
        while(c!='\n')
          fscanf(pfichier,"%c",&c);
	getchar();
        fscanf(pfichier,"%lf",&eps);
        printf("La precision : %.15f \n ", eps);
        fscanf(pfichier,"%c",&c);
        while(c!='\n')
          fscanf(pfichier,"%c",&c);
   	getchar();


    //Methodes directes ou iteratives ?


       do{printf("\n \n \t Choississez le type de resolution du systeme Ax=b : \n");
        printf("<1> methode directe \n");
        printf("<2> methode iterative \n");
        printf("Choix <1-2> ? ");
        scanf("%d",&typeMeth);}while(typeMeth!=1 && typeMeth!=2);

 if(typeMeth==1){
    printf("Vous avez choisi de resoudre le systeme lineaire par une methode directe \n");
    // Choix des methodes directes:
     do{printf("Choisissez une methode parmi les suivantes : \n");
     printf(" <1> methode de Gauss \n <2> methode de Gauss Pivot Partiel \n <3> methode de Gauss Pivot Total");
     printf("\n <4> methode de Decomposition L U \n <5> methode de Cholesky \n Choix <1-5> ? ");
     scanf("%d",&choixDir);}while(choixDir<1 || choixDir>5);

     switch(choixDir){
     case 1:
             printf("Vous avez choisi la methode de Gauss pour resoudre le systeme Ax=b: \n");
             Gauss(A,b,n);
             break;
     case 2:
             printf("Vous avez choisi la methode de Gauss Pivot Partiel pour resoudre le systeme Ax=b: \n");
             GaussPivotPartiel(A,b,x0,n);
             break;
     case 3:
             printf("Vous avez choisi la methode de Gauss Pivot Total pour resoudre le systeme Ax=b: \n");
             GaussPivotTotal(A,b,x0,n);
             break;
     case 4:
             printf("Vous avez choisi la methode de Decompostion L U  pour resoudre le systeme Ax=b: \n");
             DecompLU(A,b,x0,n);
             break;

     case 5:
             printf("Vous avez choisi la methode de Cholesky  pour resoudre le systeme Ax=b: \n");
             Cholesky(A,b,x0,n);
             break;
     }


     }

else {
printf("Vous avez choisi de resoudre le systeme lineaire par une methode iterative \n");

     do{printf("Choisissez une methode parmi les suivantes : \n");
     printf(" <1> methode de Jacobi \n <2> methode de Gauss-Seidel \n <3> methode SOR \n");
     printf("Choix <1-3> ? ");
     scanf("%d",&choixIt);}while(choixIt<1 || choixIt>3);

switch(choixIt){
     case 1:
             printf("Vous avez choisi la methode de Jacobi  pour resoudre le systeme Ax=b: \n");
             Jacobi(A,b,n,x0,eps,itermax);
             break;

     case 2:
             printf("Vous avez choisi la methode de Gauss-Seidel  pour resoudre le systeme Ax=b: \n");
             GaussSeidel(A,b,n,x0,eps,itermax);
             break;

     case 3:
             printf("Vous avez choisi la methode SOR  pour resoudre le systeme Ax=b: \n");
             SOR(A,b,n,x0,eps,omega,itermax);
             break;
  }



}
fclose(pfichier);
FreeMatriceReelle(A,n,n);
FreeTabReel(x0,n);
FreeTabReel(b,n);

 printf("\n \t Recommencer ?\n <1>-Oui \n <2>-Non \n <1-2> ? ");
 scanf("%d",&rep);
 }while(rep==1 && rep!=2);




	return 0;
}
