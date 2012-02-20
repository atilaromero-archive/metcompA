set output "2d.eps"
plot "ttrajetoria_particulas-10_20_30_40-1Kcoef.dat" u 1:2 with impulses
replot "ttrajetoria_particulas-10_20_30_40-1Kcoef.dat" u 3:4 with steps
replot "ttrajetoria_particulas-10_20_30_40-1Kcoef.dat" u 5:6 with dots
pause -1