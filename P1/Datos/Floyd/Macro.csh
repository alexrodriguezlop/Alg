#!/bin/csh -vx

set NOMBRE="Floyd"


echo "" >> Salida.dat
@ i = 50

while ( $i < 1800 )
./${NOMBRE} $i >> Salida.dat
@ i += 50
end

./Macro2.csh

