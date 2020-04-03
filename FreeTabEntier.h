#include <stdio.h>
#include <stdlib.h>

void FreeTabEntier(int*T,int N)
{
	free (T+1);
}
