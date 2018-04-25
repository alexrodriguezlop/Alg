#!/usr/bin/gnuplot   

set terminal png
set output "Grafica.png"
set xlabel "Tamanio"
set ylabel "Tiempo (seg)"

plot "Salida.dat" title "Heapsort" with points

set output "Hibrida.png"
set xlabel "Tamanio"
set ylabel "Tiempo (seg)"

f(x)=a*x*(log(x)/log(2))+b

fit f(x) 'Salida.dat' via a, b

plot "Salida.dat", f(x) title "Curva ajustada"
