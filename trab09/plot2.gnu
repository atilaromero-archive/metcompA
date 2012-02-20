file="0-5.dat" 
f(x)=exp(x)
plot file u 1:2 title "exp(x)"
replot file u 1:4 title "exp(x) com long double"
replot file u 1:3 title "algoritmo otimizado(x)"
replot f(x) title "exp(x) do gnuplot"
set term postscript enhanced color
set output file.".eps"
replot
pause -1