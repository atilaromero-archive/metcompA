file="0.95.dat" 
a=0.95
f(x)=a/((1-a)**2)
set xlabel "N"
set ylabel "f(0.95)"
plot file u 1:2 title "f(0.95)"
replot f(x) title "f(0.95) do gnuplot"
pause -1
set term postscript enhanced color
set output file.".eps"
replot
