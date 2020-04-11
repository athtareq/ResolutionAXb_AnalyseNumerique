#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DecompositionLU(double**A,double*b,int n)
{
	void ProduitMatrice(double**A,double**B,int n);
	int i,j,k,m;
    double pivot,coef,perm;
    double somme;
    double*TabReel(int N);
    void AfficheMatriceReelle(double**M,int L,int C);
    void Gauss(double**A,double*b,int n);
    double erreur=10.0;
    double max;
    double**MatriceReelle(int L,int C);
    double**L;
    double*x,*y;
    x=TabReel(n);
    y=TabReel(n);
    
    L=MatriceReelle(n,n);
    for(i=1;i<=n;i++){
    	for(j=i+1;j<=n;j++)
    		  L[i][j]=0;
		}
    
    for(k=1;k<=n-1;k++){
    	L[k][k]=1;
    	pivot=A[k][k];
	for(i=k+1;i<=n;i++)
      {
                       coef=A[i][k]/pivot;
                       L[i][k]=coef;
                       for(j=k;j<=n;j++){
                       	A[i][j]=A[i][j]-coef*A[k][j];
					   }
                             
                       
			}
		
	}
	L[n][n]=1;
	printf("\nLa matrice L est : \n\n");
	AfficheMatriceReelle(L,n,n);
	printf("\nLa matrice U est : \n\n");
	AfficheMatriceReelle(A,n,n);
	
	y[1]=b[1]/L[1][1];
    for(i=2;i<=n;i++)
    {
        somme=0.0;
        for(j=1;j<=i-1;j++)
            somme+=L[i][j]*y[j];
        y[i]=(b[i]-somme)/L[i][i] ;
    }
    x[n]=y[n]/A[n][n];
    for(i=n-1;i>=1;i--)
    {
        somme=0.0;
        for(j=i+1;j<=n;j++)
            somme+=A[i][j]*x[j];
        x[i]=(y[i]-somme)/A[i][i];
    }
        printf("\nDecomposition LU : le vecteur solutionn du systeme est : \n\n");
        AfficherTabReel(x,n,1);
}
