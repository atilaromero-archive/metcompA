file="dados2.dat" 
file2="dados.dat"
plot file u 1:2 title "interpolacao" with points
replot file2 u 1:2 title "dados" with points
set term postscript enhanced color
set output file.".eps"
replot
pause -1