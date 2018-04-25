#!/usr/bin/gnuplot   

set terminal png
set output "Grafica.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

plot "Salida.dat" title "Mergesort" with points


set output "Hibrida.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

f(x)=a*x*(log(x)/log(2))+b

fit f(x) 'Salida.dat' via a, b

plot "Salida.dat", f(x) title "Curva ajustada"
