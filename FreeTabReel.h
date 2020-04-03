#include <stdio.h>
#include <stdlib.h>

void FreeTabReel(double*T,int N)
{
	free (T+1);
}
