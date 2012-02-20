file="dados.dat"
#set log
#c1=0.088200
#c2=-1.119890
#a1=exp(c1)
#a2=-c2
#1/rc=1/a2 -> a2=rc
#q/rc=a1   -> q/a2=a1
#q=a2*a1
#c=a2/r
#q=-0.098774
#c=-0.011199
f(x)=exp(0.088200) * exp(-1.119890*x)
plot file u 1:2 title "dados" with points
replot f(x)
set term postscript enhanced color
set output file.".eps"
replot
pause -1