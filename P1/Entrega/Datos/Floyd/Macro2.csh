#!/usr/bin/gnuplot   

set terminal png
set output "Grafica.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

plot "Salida.dat" title "Floyd" with points


set output "Hibrida.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

f(x)=a*x*x*x+b*x*x+c*x+d

fit f(x) 'Salida.dat' via a, b, c, d

plot "Salida.dat", f(x) title "Curva ajustada"
