#!/usr/bin/gnuplot   

set terminal png
set output "Grafica.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

plot "Salida.dat" title "Hanoi" with points


set output "Hibrida.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

f(x)= a*(2**x)+b

fit f(x) 'Salida.dat' via a, b

plot "Salida.dat", f(x) title "Curva ajustada"