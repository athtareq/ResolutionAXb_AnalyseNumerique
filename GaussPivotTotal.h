#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void GaussPivotTotal(double **A,double *b,double*X,int n)
{
	int i,j,k;
	int permutations=0;
	int p,q;
	double pivot,aux,somme,coef;
	double mx;
	double aux1,aux2,aux3;
    int*ordre;
    ordre=TabEntier(n);
    for(i=1;i<=n;i++) ordre[i]=i;
    int temp;
    double*Xord;
    Xord=TabReel(n);



	for(k=1;k<=n-1;k++)
	{
	mx=fabs(A[k][k]);
	p=k;
	q=k;
		for(i=k;i<=n;i++)
		{
			for(j=k;j<=n;j++)
			{
				if(fabs(A[i][j])>mx) {
				p=i;
				q=j;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			aux3=A[i][q];
			A[i][q]=A[i][k];
			A[i][k]=aux3;
		}

		for(j=1;j<=n;j++)
		{
			aux3=A[p][j];
			A[p][j]=A[k][j];
			A[k][j]=aux3;
		}

		aux1=b[p];
		b[p]=b[k];
		b[k]=aux1;


        aux2=X[k];
		X[k]=X[q];
		X[q]=aux2;

		temp=ordre[k];
        ordre[k]=ordre[q];
        ordre[q]=temp;


		//permutations++;


		pivot=A[k][k];
		printf("Pivot=%18.16f\n",pivot);

		if(pivot<1e-12)
		{
				printf("\n pas de solution \n");
				exit(-1);
		}
     for(i=k+1;i<=n;i++)
                   {
                       coef=A[i][k]/pivot;
                       for(j=k;j<=n;j++)
                         A[i][j]-=coef*A[k][j];
                       b[i]-=coef*b[k];
                   }

        AfficheMatriceReelle(A,n,n);
        getchar();
        getchar();
        }

        if(fabs(A[n][n])<1.0e-12)
            {
                    printf("La matrice n'est pas inversible!");
                      exit(-1);
            }






        X[n]=b[n]/A[n][n];
        for(i=n-1;i>=1;i--)
        {
            somme=0.0;
            for(j=i+1;j<=n;j++)
                somme+=A[i][j]*X[j];
            X[i]=(b[i]-somme)/A[i][i];
        }

         for(i=1;i<=n;i++) Xord[ordre[i]]=X[i];




        printf("La solution de ce systeme est:\n");
        AfficherTabReel(Xord,n,1);
        FreeTabReel(Xord,n);

}

