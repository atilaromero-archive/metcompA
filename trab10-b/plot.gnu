file="derivada_float.dat" 
set log
plot file u 1:2 title "g'(-2)" with linespoints
replot file u 1:3 title "g'(0.5)" with linespoints
replot file u 1:4 title "g'(2)" with linespoints
replot file u 1:5 title "g'(5)" with linespoints
set term postscript enhanced color
set output file.".eps"
replot
pause -1