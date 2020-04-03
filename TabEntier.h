#include <stdio.h>
#include <stdlib.h>
int*TabEntier(int N)
{
	int *T;
	T=(int*)malloc(N*sizeof(int));
	if(T==NULL)
	  {
	  	printf("TabEntier:pas assez de memoire\n");
	  	exit(-1);
	  }
	return T-1;
}
