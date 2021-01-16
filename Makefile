numberphile: numberphile.c
	gcc -c numberphile.c 
	gcc -o numberphile numberphile.o -lm
gnuplot: vertices.dat
	gnuplot 
	plot 'vertices.dat'