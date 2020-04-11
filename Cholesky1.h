#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Cholesky1(double **A, double *b,int n)
{
	int i,j,k,m;
    double pivot,perm;
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
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(A[i][j]!=A[j][i])
            {
                printf("La matrice n'est pas symetrique definie positive\n");
                exit(-1);
            }
        }

    }
    for(i=2;i<=n;i++)
    {
        if(A[1][1]<0.0)
        {
            printf("A n'est pas symetrique definie positive\n");
            exit(-1);
        }
        L[1][1]=sqrt(A[1][1]);
        L[i][1]=A[1][i]/L[1][1] ;
    }
    for(i=2;i<=n;i++)
    {
        somme=0.0;
        for(k=1;k<=i-1;k++)
            somme=somme+pow(L[i][k],2);
        if((A[i][i]-somme)<0.0)
        {
            printf("matrice n est pas symetrique definie positive\n");
            exit(-1);
        }
        L[i][i]=sqrt(A[i][i]-somme);
        
       for(j=i+1;j<=n;j++)
        {
            somme=0.0;
            for(k=1;k<=i-1;k++)
                somme+=L[i][k]*L[j][k];
            L[j][i]=(A[i][j]-somme)/L[i][i] ;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1+i;j<=n;j++)
            L[i][j]=0.0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            A[i][j]=L[j][i];
    }
    printf("\n affichage de L:\n\n");
     AfficheMatriceReelle(L,n,n);
    printf("\naffichage de la transposee de L:\n");
    AfficheMatriceReelle(A,n,n);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        if(fabs(L[i][i])<1.0e-12)
        {
            printf("Matricle L pas inversible!!\n");
            exit(-1);
        }
    }
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
        printf("\n Cholesky : la solution du systeme est:\n\n");
        AfficherTabReel(x,n,1);
}
