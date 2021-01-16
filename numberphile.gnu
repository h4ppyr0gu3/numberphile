set term x11 persist
set title "Numberphile" font "Times-New-Roman,15"
set ylabel "Y COORDINATE" font "Times-New-Roman,12"
set xlabel "X COORDINATE" font "Times-New-Roman,12"
set autoscale
set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 pi -1 ps 3
set pointintervalbox 3
plot for [COL=1:2] "vertices.dat" with points ls 1
replot for [COL=1:2] "data.dat" with points pt 1