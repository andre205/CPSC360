#include <stdio.h>
#include "math.h"
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE *ifp = 0;
	double n = 0.0, sum = 0.0, mean = 0.0, devsum = 0.0, devmean = 0.0, variance = 0.0;

	if (argc == 4)
	{
		//declare line buffer size
		char line[15];

		//SMALL
		//open file, read each line, increase sum
		ifp = fopen(argv[1], "r");

		while( fgets( line,15, ifp ) )
		{
		  if( 1==sscanf(line,"%lf",&n) )
		    sum += n;
		}
		//find mean with sum
		mean = sum / 10.0;
		fclose(ifp);

		//reopen file, calculate variance
		ifp = fopen(argv[1], "r");
		while( fgets( line,15, ifp ) )
		{
			if( 1==sscanf(line,"%lf",&n) )
				devsum += pow(n - mean, 2);
		}
		devmean = devsum / 10.0;
		variance = (devmean);
		fclose(ifp);

		//display data
		printf("Small data set (10 points)\n");
		//printf("Sum: %f\n", sum);
		printf("Mean: %f\n", mean);
		//printf("Devsum: %f\n", devsum);
		//printf("Devmean: %f\n", devmean);
		printf("Variance: %f\n", variance);
		printf("---------------------\n");

		n = 0.0, sum = 0.0, mean = 0.0, devsum = 0.0, devmean = 0.0, variance = 0.0;

		//repeat process for 2 other files
		//MEDIUM
		ifp = fopen(argv[2], "r");

		while( fgets( line,15, ifp ) )
		{
		  if( 1==sscanf(line,"%lf",&n) )
		    sum += n;
		}
		mean = sum / 1000.0;
		fclose(ifp);

		ifp = fopen(argv[2], "r");
		while( fgets( line,15, ifp ) )
		{
			if( 1==sscanf(line,"%lf",&n) )
				devsum += pow(n - mean, 2);
		}
		devmean = devsum / 1000.0;
		variance = (devmean);
		fclose(ifp);

		printf("Medium data set (1,000 points)\n");
		//printf("Sum: %f\n", sum);
		printf("Mean: %f\n", mean);
		//printf("Devsum: %f\n", devsum);
		//printf("Devmean: %f\n", devmean);
		printf("Variance: %f\n", variance);
		printf("---------------------\n");

		n = 0.0, sum = 0.0, mean = 0.0, devsum = 0.0, devmean = 0.0, variance = 0.0;

		//LARGE
		ifp = fopen(argv[3], "r");

		while(fgets(line, 15, ifp))
		{
			if(1 == sscanf(line, "%lf", &n))
				sum += n;
		}
		mean = sum / 1000000.0;
		fclose(ifp);

		ifp = fopen(argv[3], "r");
		while( fgets( line,15, ifp ) )
		{
			if( 1==sscanf(line,"%lf",&n) )
			{
				devsum += pow(n - mean, 2);
			}
		}
		devmean = devsum / (1000000.0);
		variance = (devmean);
		fclose(ifp);

		printf("Large data set (1,000,000 points)\n");
		//printf("Sum: %f\n", sum);
		printf("Mean: %f\n", mean);
		//printf("Devsum: %f\n", devsum);
		//printf("Devmean: %f\n", devmean);
		printf("Variance: %f\n", variance);
		printf("---------------------\n");
	}

	else
	{
		printf("This program takes 3 command line arguments.\nPlease enter 3 file names in the command line.\n");
	}

	return 0;
}
