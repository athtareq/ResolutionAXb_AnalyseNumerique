#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void GaussPivotPartiel(double**A,double*b,double *x,int n)
{


	int i,j,k,pospiv;
	double aux;
    double mx;
	double pivot,temp,somme,coef;


	for(k=1;k<=n-1;k++)
	{
		mx=fabs(A[k][k]);
		pospiv=k;
		for(i=k+1;i<=n;i++){
		   	   if(fabs(A[i][k])>mx) pospiv=i;}

			for(j=1;j<=n;j++)
			{
				aux=A[pospiv][j];
				A[pospiv][j]=A[k][j];
				A[k][j]=aux;
			}
			aux=b[k];
			b[k]=b[pospiv];
			b[pospiv]=aux;


			pivot=A[k][k];
			if(pivot==0)

			{
				printf("\n pas de solution \n");
				exit(-1);
		    }

           printf("\t Pivot : %lf \n",pivot);

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
        x[n]=b[n]/A[n][n];
        for(i=n-1;i>=1;i--)
        {
            somme=0.0;
            for(j=i+1;j<=n;j++)
                somme+=A[i][j]*x[j];
            x[i]=(b[i]-somme)/A[i][i];
        }
        printf("La solution de ce systeme est:\n");
        AfficherTabReel(x,n,1);



}
