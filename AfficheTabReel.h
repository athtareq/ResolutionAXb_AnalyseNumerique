#include <stdio.h>
#include <stdlib.h>

void AfficherTabReel(double*T,int N, int cas)
{	
	int i;
	if(cas==1){	

	for(i=1;i<=N;i++)
	  {
	  	printf(" x%d = %14.12f \n",i,*(T+i));
	  }
}
else 	for(i=1;i<=N;i++)
	  {
	  	printf("%14.12f \n",*(T+i));
	  }
}
