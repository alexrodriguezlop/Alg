#!/usr/bin/gnuplot   

set terminal png

set autoscale                        # Pone la escala en modo automático
unset log
unset label                          # Quita etiquetas anteriores
set xtic auto                        # set xtics automatically
set ytic auto                        # set ytics automatically

set xlabel "Tamaño"
set ylabel "Tiempo (seg)"

set output "O(nLog(n)).png"

set title "Comparacion de algoritmos O(nLog(n))"

plot "Heapsort.dat" title "Heapsort" w lp, "Mergesort.dat" title "Mergesort" w lp , "Quicksort.dat" title "Quicksort" w lp

set output "O(n^2).png"

set title "Comparacion de algoritmos O(n^2)"

plot "Burbuja.dat" title "Burbuja" w lp, "Seleccion.dat" title "Seleccion" w lp, "Insercion.dat" title "Insercion" w lp

set output "Ordenacion de vectores.png"

set title "Comparacion de algoritmos de ordenacion de vectores"

plot "Heapsort.dat" title "Heapsort" w lp, "Mergesort.dat" title "Mergesort" w lp , "Quicksort.dat" title "Quicksort" w lp, "Burbuja.dat" title "Burbuja" w lp, "Seleccion.dat" title "Seleccion" w lp, "Insercion.dat" title "Insercion" w lp
