#include <stdio.h>
#include <stdlib.h>
#include<math.h>
 double Norme2(double *x,int n)
 {
 int i;
 double s=0.0;
 for(i=1;i<=n;i++)
    s+=x[i]*x[i];
 return sqrt(s);
 }
