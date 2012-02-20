#!/usr/bin/gnuplot
a='ttrajetoria_particulas-10_20_30_40-1Kcoef.dat'
b='ttrajetoria_particulas-15_22_33_54-1Kcoef.dat'
graf=b
splot graf u 1:2:9 with lines title graf." u 1:2:9"
replot graf u 3:4:9 with lines title graf." u 3:4:9"
replot graf u 5:6:9 with lines title graf." u 5:6:9"
set term postscript enhanced color
set output "trab3.eps"
replot