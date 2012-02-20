file="derivada_float.dat" 
set log
plot file u 1:2 title "float DD(x)" with linespoints
replot file u 1:3 title "float DC(x)" with linespoints
replot file u 1:4 title "double DD(x)" with linespoints
replot file u 1:5 title "double DC(x)" with linespoints
set term postscript enhanced color
set output file.".eps"
replot
pause -1