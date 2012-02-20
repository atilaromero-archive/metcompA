file="dados_par.dat"
f(x)= 3.759647 + 1.936607*x -1.007578*x*x
plot file u 1:2 title "dados" with points
replot f(x)
set term postscript enhanced color
set output file.".eps"
replot
pause -1