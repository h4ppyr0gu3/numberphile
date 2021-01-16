// git@github.com:h4ppyr0gu3/numberphile.git

#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <time.h>

int main() {

	double a, b, n, previousx, previousy, x, y;


	printf("please enter how far apart you'd like the vertices to be\nDistance: ");
	scanf("%lf", &a);
	printf("please enter how many points you'd like plotted\nNumber: ");
	scanf("%lf", &n);
	printf("please enter the starting points(positive x, y)\nX: ");
	scanf("%lf", &previousx);	
	printf("Y: ");
	scanf("%lf", &previousy);	

	FILE *ptr;
	ptr = fopen("vertices.dat", "w");  // Print vertice points to one file
	fprintf(ptr, "#x y\n0 0\n");

	fprintf(ptr, "%lf 0\n", a);
	b = 60 * (M_PI/180);
	printf("%lf\n", b);
	b = sin(b);
	printf("%lf\n", b);
	b = a * b;
	printf("%lf\n", b);
	fprintf(ptr, "%lf %lf\n", a/2, b);
	fclose(ptr);

	FILE *data;
	data = fopen("data.dat", "w");
	fprintf(data, "%lf %lf\n", previousx, previousy); // print the values to another to allow 2 colours

	int *roll;

	roll = malloc(n * 2 * sizeof(int)); // dynamically allocate more storage 
																			// than necessary to avoid segmentation fault
	srand(time(NULL));
	for(int i =  0; i < n; i++) {
		roll[i] = ceil(((double)rand()/RAND_MAX) * 3); // randomly generate numbers between 1 and 3 
		// printf("%d", roll[i]);
	}
	for(int i = 0; i < n; i++) { // print to file for each case after calculating the newpoint using previous point
		if(roll[i] == 1) {
			previousx = previousx/2;
			previousy = previousy/2;
			fprintf(data, "%lf %lf\n", previousx, previousy);
		}
		else if(roll[i] == 2) {
			previousx = (previousx + a/2)/2;
			previousy = (previousy + b)/2;
			fprintf(data, "%lf %lf\n", previousx, previousy);
		}
		else {
			previousx = (previousx + a)/2;
			previousy = previousy/2;
			fprintf(data, "%lf %lf\n", previousx, previousy);
		}
	}

	fclose(data);

	free(roll);

	system("sh numberphile.sh"); // run gnuplot and shellscript

}
