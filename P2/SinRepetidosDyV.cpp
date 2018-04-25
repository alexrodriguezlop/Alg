//**********************************************************************
//Autor: Alejandro Rodr�guez L�pez
//Email: alexrodriguezlop@correo.ugr.es
//Fichero: Pr�ctica2-Algoritmica (Divide y vencer�s)
//**********************************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std::chrono;
using namespace std;

// generador de ejemplos para el problema del elemento en su posici�n. Para rellenar el vector de tama�o n, genera todos los enteros entre -(n-1) y (n-1) en un vector auxiliar; despu�s obtiene una permutaci�n aleatoria de ese vector, se queda con los n primeros elementos, y los ordena de forma creciente

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

//Algoritmo Divide y Venceras:-----------------------------------------------------------------------------------
/**
@brief Determina si existe un indice i tal que v[i] = i. 
@param v: vector de elementos. Tiene un n�mero de elementos mayor o igual a final.
@param inicio: Posici�n que marca el incio de la parte del vector a verificar.
@param fin: Posici�n final del vector a verificar. inicio <= fin.
@pre: v debe estar ordenado de forma no decreciente. 
@return: int con el �ndice de la primera coincidencia, -1 en caso de no encontrar ning�n �ndice que cumpla la condici�n.
*
*/
int Divide_y_venceras(vector<int> &v, int inicio, int fin) {
	int valor = -1;
	int mitad = (inicio + fin)/2;
	
	if(inicio <= fin){
		if(v[mitad]==mitad){
			valor = mitad;
		}
		else{
			if(v[mitad] > mitad) 
				valor =  Divide_y_venceras(v, inicio, mitad-1);
			else 
				valor =  Divide_y_venceras(v, mitad+1, fin);
		}
	}
	return valor;
}
//Algoritmo Fuerza bruta:-----------------------------------------------------------------------------------
/**
@brief Determina si existe un indice i tal que v[i] = i 
@param v: vector de elementos. Tiene un n�mero de elementos mayor o igual a final.
@return: int con el �ndice de la primera coincidencia, -1 en caso de no encontrar ning�n �ndice que cumpla la condici�n.
*/
int Fuerza_bruta(vector<int> &v){
	for(int i=0;i<v.size();i++)
		if(v[i]==i) 
			return i;
	return -1;
}


//MAIN
int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);
  int m=2*n-1;

  int * T = new int[n];
  assert(T);
  int * aux = new int[m];
  assert(aux);
  
//Da a la funci�n random una nueva semilla, basada en los segundos.
srand(time(0));

//genero todos los enteros entre -(n-1) y n-1
for (int j=0; j<m; j++) aux[j]=j-(n-1);

//algoritmo de random shuffling the Knuth (permutaci�n aleatoria) 
for (int j=m-1; j>0; j--) {
   double u=uniforme();
   int k=(int)(j*u);
   int tmp=aux[j];
   aux[j]=aux[k];
   aux[k]=tmp;
}
//me quedo con los n primeros del vector
for (int j=0; j<n; j++) T[j]=aux[j];
//for (int j=0; j<n; j++) cout << T[j] << " ";

//Y ahora ordeno el vector T
vector<int> myvector (T, T+n);
vector<int>::iterator it;

sort(myvector.begin(),myvector.end());

//Declaraci�n de variables de tiempo
high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;

//Medida de tiempo antes de la ejecuci�n del algoritmo	******
tantes = high_resolution_clock::now();

//Ejecuci�n del algoritmo
int encontradoDyV = Divide_y_venceras(myvector, 0, n-1);
//int encontradoFb = Fuerza_bruta(myvector);

//Medida de tiempo desp�es de la ejecuci�n del algoritmo  *****
tdespues = high_resolution_clock::now();

transcurrido = duration_cast<duration<double>>(tdespues - tantes);
/**
if(encontradoDyV != encontradoFb && encontradoDyV == -1)
  cout << "FALLO!: " << "Caso: " << n << "-->" << encontradoFb << "-vs " << encontradoDyV << endl;
*/	
		
cout << n << " "  << transcurrido.count() << endl;
 

delete [] aux;

}
