#include<stdio.h>
#include<stdlib.h>



  void DecompLU(double **A,double *b,double *x,int n)
   {

      int i,j,k,m;
      double **L,coef,*Y;;
      Y=TabReel(n);
      L=MatriceReelle(n,n);
//decomposition LU
for(k=1;k<=n-1;k++)
	{
	for(i=1;i<=k-1;i++) L[i][k]=0;
	L[k][k]=1;
	for(i=k+1;i<=n;i++) L[i][k]= A[i][k]/A[k][k];

	for(i=k+1;i<=n;i++)
        for(j=1;j<=k;j++)
            A[i][j]= 0;
    for(i=k+1;i<=n;i++)
        for(j=k+1;j<=n;j++)
            A[i][j]=A[i][j]-L[i][k]*A[k][j];
    for(i=1;i<=n-1;i++) L[i][n]= 0;

    L[n][n]=1;
}

printf("la matrice L :\n");
AfficheMatriceReelle(L,n,n);
printf("la matrice U :\n");
AfficheMatriceReelle(A,n,n);


//Resolution du systeme


int s;
   Y[1]=b[1]/L[1][1];

    for(i=2;i<=n;i++){
      s=0;
      for(j=1;j<=i-1;j++){
      s+=L[i][j]*Y[j];
      }
      Y[j]=(b[i]-s)/L[i][i];
   }
printf("\n Y est: \n");
AfficherTabReel(Y,n,0);

/*substitution_avant(L,b,Y,N,T);
//substitution_arriere(A,Y,X,N,T);*/
if(fabs(A[n][n])<1.0e-12)
            {
                    printf("La matrice n'est pas inversible!");
                      exit(-1);
            }
        int somme;
 x[n]=Y[n]/A[n][n];
        for(i=n-1;i>=1;i--)
        {
            somme=0.0;
            for(j=i+1;j<=n;j++) somme+=A[i][j]*x[j];
            x[i]=(Y[i]-somme)/A[i][i];
        }

        printf("La solution de ce systeme est:\n");
        AfficherTabReel(x,n,1);




    }





