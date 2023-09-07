#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>

#define K 3

int main()
{
	srand(time(NULL));
	FILE *out = fopen("valores.dat","w+");
	double x, xi, r, aux;
	for(r=2;r<=4;r+=0.0005)
	{
		x = rand()/(float)RAND_MAX;
		for(int i=0;i<250;++i)
		{
			xi = r*x*(1-x);
			x=xi;
		}
		for(int i=0;i<200;++i)
		{
			xi = r*x*(1-x);
			aux = xi*pow(10,K);
			aux -= floor(aux);
			fprintf(out,"%.4f %.6f\n",r,aux);
			if(xi==x){break;}
			x=xi;
		}
	}
	return 0;
}
