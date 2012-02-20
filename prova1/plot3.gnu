file="dados.dat" 
a=0.95
as=gprintf("%f",a)
f(x)=a/((1-a)**2)
set xlabel "N"
set ylabel "f(x)"
plot file u 1:2 title "f(x)"
replot f(x) title "f(".as.") do gnuplot"
pause -1
