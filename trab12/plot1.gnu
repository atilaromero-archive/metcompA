file="dados1.dat" 
set ylabel "Erro"
plot file u 1:2 title "integral sin(x)[0 3.1416]" with linespoints
replot file u 1:3 title "erro" with linespoints
set term postscript enhanced color
set output file.".eps"
replot
pause -1