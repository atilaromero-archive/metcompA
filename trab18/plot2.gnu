file="dados_g4.dat"
f(x)= 2.299664 -0.429139*x -3.878399*x**2 -3.964130*x**3 + 0.992540*x**4
plot file u 1:2 title "dados" with points
replot f(x)
set term postscript enhanced color
set output file.".eps"
replot
pause -1


