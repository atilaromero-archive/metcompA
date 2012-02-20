file="dados2.dat" 
set ylabel "Erro"
plot file u 1:4 title "integral f2(x)" with linespoints
replot file u 1:5 title "erro2" with linespoints
set term postscript enhanced color
set output file.".eps"
replot
pause -1