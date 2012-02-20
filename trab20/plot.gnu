file1="1.dat"
file2="2.dat"
file3="3.dat"
file4="4.dat"
file5="5.dat"
set term postscript enhanced color
set output "dados.eps"
plot file1 u 1:2 with lines#points
replot file2 u 1:2 with lines#points
replot file3 u 1:2 with lines#points
replot file4 u 1:2 with lines#points
replot file5 u 1:2 with lines#points
#replot
#pause -1