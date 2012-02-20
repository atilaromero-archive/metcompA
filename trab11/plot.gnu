file="derivada_float.dat" 
set log
set xlabel "h"
set ylabel "Erro"
f(x)=a*x**b
g(x)=c*x**d
plot file u 1:2 title "erro central" with linespoints
replot file u 1:3 title "erro direita" with linespoints
fit [0.0001:0.1]  f(x)  "derivada_float.dat" u 1:2  via a,b
fit [0.0001:0.1]  g(x)  "derivada_float.dat" u 1:3  via c,d
replot f(x)
replot g(x)
set term postscript enhanced color
set output file.".eps"
replot
pause -1