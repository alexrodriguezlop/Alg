#!/bin/csh -vx

set NOMBRE="Hanoi"


echo "" >> Salida.dat
@ i = 1

while ( $i < 35 )
./${NOMBRE} $i >> Salida.dat
@ i += 1
end

./Macro2.csh
