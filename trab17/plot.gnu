file="dados.dat"
f(x)=5.577838 + 2.007040*x
plot file u 1:2 title "dados" with points
replot f(x)
set term postscript enhanced color
set output file.".eps"
replot
pause -1