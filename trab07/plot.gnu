plot "saida1.dat" u 1:2 title "dados 1"
replot "saida2.dat" u 1:2 title "dados 2"
replot "saida3.dat" u 1:2 title "dados 3"
replot
set term postscript enhanced color
set output "saida.eps"
replot