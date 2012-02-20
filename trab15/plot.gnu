plot file2 u 1:2 title "dados" with points
replot file u 1:2 title "interpolacao" with points
set term postscript enhanced color
set output file.".eps"
replot
pause -1