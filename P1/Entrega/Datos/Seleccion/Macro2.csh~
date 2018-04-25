#!/usr/bin/gnuplot   

set terminal png
set output "Grafica.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

plot "Salida.dat" title "Insercion" with points


set output "Hibrida.png"

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

f(x)=a*x*x+b*x+c

fit f(x) 'Salida.dat' via a, b, c

plot "Salida.dat", f(x) title "Curva ajustada"
