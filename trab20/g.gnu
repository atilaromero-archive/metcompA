#plot "1.dat"
#plot "1a.dat" using 1:3
#replot "2.dat"
#replot "3.dat"
#replot "4.dat"
#replot "5.dat"
f(x)=a*x+b
#a =0.149436 # Valor inicial aproximado*
#b =0.000 #// Valor inicial aproximado
#fit f(x) "1a.dat" using 3:1 via a 
#replot f(x)
plot "1b.dat"
pause -1