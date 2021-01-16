numberphile: numberphile.c
	gcc -c numberphile.c 
	gcc -o numberphile numberphile.o -lm
gnuplot: vertices.dat
	gnuplot 
	plot 'vertices.dat'
clean: vertices.dat data.dat numberphile numberphile.o
	rm vertices.dat data.dat numberphile numberphile.o