#include <math.h>

double NormeInfDif(double*x,double*y,int n)
{
	int i;
	double mx;
	mx=fabs(x[1]-y[1]);
	for(i=2;i<=n;i++)
	   if(fabs(x[i]-y[i])>mx)
	      mx=fabs(x[i]-y[i]);
     return mx;
}
