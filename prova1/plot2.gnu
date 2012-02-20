file="0.2.dat" 
a=0.2
f(x)=a/((1-a)**2)
plot file u 1:2 title "f(x)"
replot f(x) title "f(x) do gnuplot"
pause -1
set term postscript enhanced color
set output file.".eps"
replot
