#!/bin/csh -vx

set NOMBRE="Seleccion"


echo "" >> Salida.dat
@ i = 1000

while ( $i < 30000 )
./${NOMBRE} $i >> Salida.dat
@ i += 1000
end

./Macro2.csh

