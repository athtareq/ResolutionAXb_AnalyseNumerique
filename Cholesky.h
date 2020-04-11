#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Cholesky(double **	A,double*b,double *X,int N)
{
	double **L;
	int i,j,k;
	double som,som2;
	double p,s;

    double **Lt;
	double *Y;
	L=MatriceReelle(N,N);
	Y=TabReel(N);
    Lt=MatriceReelle(N,N);
    int sym=1;

     for (i=1;i<=N;i++){
        for (j=1;j<=N;j++){
            if (A[i][j] != A[j][i]){
                printf("La matrice n'est pas symetrique, on ne peut pas appliquer la methode de Cholesky\n");
                sym=1;break;}
           }
                sym=1;
                break;
                sym=1;
      }
if(sym!=0){
	L[1][1]=sqrt(A[1][1]);
	for(i=2;i<=N;i++)
        L[i][1]=A[i][1]/L[1][1];
	for(k=2;k<=N;k++)
	{
		som=0;
		for(j=1;j<=k-1;j++){
		som+=pow(L[k][j],2);
       }
                if ((A[k][k]-som)<=0)
                {
                      printf("On ne peut pas appliquer la methode de Cholesky \n");
                      exit(-1);
                 }
		L[k][k]=sqrt(A[k][k]-som);

		for  (i=k+1;i<=N;i++)
		{
			som2=0;
			for(j=1;j<=k-1;j++){
			som2+=L[i][j]*L[k][j];}
			L[i][k]=(A[i][k]-som2)/L[k][k];
		}
	}

        for( i=1;i<=N;i++){
        for( j=1;j<=N;j++){

         if(j>i)
         {
         L[i][j]=0;
           }
           }
           }
	printf("la matrice L \n");
	AfficheMatriceReelle(L,N,N);
    Transposee(L,Lt,N);
    printf("la matrice Lt \n");
    AfficheMatriceReelle(Lt,N,N);


  double s1;
    Y[1]=b[1]/L[1][1];
    for(i=2;i<=N;i++){
      s1=0;
      for(j=1;j<=i-1;j++){
        s1+=L[i][j]*Y[j];
        }
        Y[i]=(b[i]-s1)/L[i][i];
        }

  double s2;
  X[N]=Y[N]/Lt[N][N];
  for(i=N-1;i>=1;i--){
	s2=0;
   	for(j=i+1;j<=N;j++){
   	s2+=Lt[i][j]*X[j];
		}

   X[i]=(Y[i]-s2)/Lt[i][i];
	}

	AfficherTabReel(X,N,1);

	}

}
