#include <stdio.h>
#include <stdlib.h>

void AfficherTabEntier(int*T,int N)
{
	int i;
	for(i=1;i<=N;i++)
	  {
	  	printf("%d ",*(T+i));
	  }
}
