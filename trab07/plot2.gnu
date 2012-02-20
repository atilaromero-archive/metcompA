plot "saida.dat" u 1:2 title "dados"
replot
set term postscript enhanced color
set output "saida2.eps"
replot