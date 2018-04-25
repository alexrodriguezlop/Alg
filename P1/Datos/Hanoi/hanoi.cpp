/**
   @file Resolución del problema de las Torres de Hanoi
*/
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;


/**
   @brief Resuelve el problema de las Torres de Hanoi
   @param M: número de discos. M > 1.
   @param i: número de columna en que están los discos.
             i es un valor de {1, 2, 3}. i != j.
   @param j: número de columna a que se llevan los discos.
             j es un valor de {1, 2, 3}. j != i.

   Esta función imprime en la salida estándar la secuencia de 
   movimientos necesarios para desplazar los M discos de la
   columna i a la j, observando la restricción de que ningún
   disco se puede situar sobre otro de tamaño menor. Utiliza
   una única columna auxiliar.
*/
void hanoi (int M, int i, int j);




void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      //cout << i << " -> " << j << endl;
      hanoi (M-1, 6-i-j, j);
  }
}

int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }
  //Obtencion de n
  int n = atoi(argv[1]);

  //Declaración de variables	
  high_resolution_clock::time_point tantes, tdespues;
  duration<double> transcurrido;



  //Medida de tiempo antes	******
  tantes = high_resolution_clock::now();
  //Algoritmo
  hanoi(n, 1, 2);
  
  //Medida de tiempo despúes  *****
  tdespues = high_resolution_clock::now();

  transcurrido = duration_cast<duration<double>>(tdespues - tantes);
  cout << n << " "  << transcurrido.count() << endl;


  return 0;
};
