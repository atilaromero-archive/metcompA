f(x)=a*x**b
a=1.5e-13
as=gprintf("%.2e",a)
b=1
bs=gprintf("%.2e",b)
plot "mMSD-1Kcoef.dat" u 1:2 title "dados da simulacao"
replot f(x) title as."*x**".bs
set xlabel "t"
set ylabel "<r^2>"
set grid
set log
set xrange[700:1e+06]
set title "deslocamento quadratico medio vs tempo"
replot
pause -1
set term postscript enhanced color
set output "x2.eps"
replot