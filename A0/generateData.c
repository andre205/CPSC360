#include <stdio.h>
#include "math.h"
#include <stdlib.h>

double genRan(double m, double v)
{
	//box muller method for generating a random number with a given mean and variation
	double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
	a = ((float) rand() / (float) (RAND_MAX));
	b = ((float) rand() / (float) (RAND_MAX));
	c = sqrt((-2) * log(a) ) * cos(2 * M_PI * b);
	d = (sqrt(v) * c) + m;
	return d;
}

int main(int argc, char** argv)
{
	double m = 0.0, v = 0.0, d= 0.0;
	FILE *ifp = 0;

	//prompt for input
	printf("Enter Mean: ");
	fflush(stdout);
	scanf("%lf", &m);
	printf("Enter Variance: ");
	fflush(stdout);
	scanf("%lf", &v);

	//generate/write to files
	ifp = fopen("small.dat", "w");

	for (int i = 0; i < 10; ++i)
	{
		//generate number, write to file (and go to next line)
		d = genRan(m,v);
		fprintf( ifp, "%f\n", d);
	}
	fclose(ifp);

	printf("small.dat created.\n");

	ifp = fopen("medium.dat", "w");

	for (int i = 0; i < 1000; ++i)
	{
		d = genRan(m,v);
		fprintf( ifp, "%f\n", d);
	}
	fclose(ifp);

	printf("medium.dat created.\n");

	ifp = fopen("large.dat", "w");

	for (int i = 0; i < 1000000; ++i)
	{
		d = genRan(m,v);
		fprintf( ifp, "%f\n", d);
	}
	fclose(ifp);

	printf("large.dat created.\n");

	return 0;
}
