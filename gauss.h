#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Gauss(double**A,double*b,int n)
{
    int i,j,k,m;
    double pivot,perm;
    double somme;
    double*TabReel(int N);
    void AfficherTabReel(double*T,int N,int cas);
    void AfficheMatriceReelle(double**M,int L,int C);
    double erreur=10.0;

    double*x;
    x=TabReel(n);
    double coef;

    while((erreur+1)>1) erreur/=2;
    printf("erreur=%e\n",erreur);

    for(k=1;k<=n-1;k++)
        {
           pivot=A[k][k];
           if(fabs(pivot)<1.0e-12)
              {
                  m=k+1;
                  while(m<=n&&fabs(A[m][k])<1.0e-12)
                        m++;
                  if(m>n)
                  {
                      printf("La matrice n'est pas inversible!");
                      exit(-1);
                  }
                  for(j=k;j<=n;j++)
                      {
                         perm=A[k][j];
                         A[k][j]=A[m][j];
                         A[m][j]=perm;
                      }
                    perm=b[k];
                    b[k]=b[m];
                    b[m]=perm;

                    pivot=A[k][k];


              }
              for(i=k+1;i<=n;i++)
                   {
                       coef=A[i][k]/pivot;
                       //printf("%f",coef);
                       for(j=k;j<=n;j++)
                         A[i][j]-=coef*A[k][j];
                       b[i]-=coef*b[k];
                   }

        printf("Pivot=%18.16f\n",pivot);
        AfficheMatriceReelle(A,n,n);
        getchar();
        getchar();
        }

        if(fabs(A[n][n])<1.0e-12)
            {
                    printf("La matrice n'est pas inversible!");
                      exit(-1);
            }

        x[n]=b[n]/A[n][n];
        for(i=n-1;i>=1;i--)
        {
            somme=0.0;
            for(j=i+1;j<=n;j++) somme+=A[i][j]*x[j];
            x[i]=(b[i]-somme)/A[i][i];
        }
        printf("La solution de ce systeme est:\n");
        AfficherTabReel(x,n,1);





}
