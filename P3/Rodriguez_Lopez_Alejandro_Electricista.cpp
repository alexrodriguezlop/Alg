//**********************************************************************
//Autor: Alejandro Rodr�guez L�pez
//Email: alexrodriguezlop@correo.ugr.es
//Fichero: Pr�ctica3-Algoritmica (Greedy)
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


//Algoritmo Greedy:-----------------------------------------------------------------------------------
/**
@brief Obtiene la tarea con un tiempo de ejecuci�n menor.
@param v: vector de pares que contiene el n�mero de tarea y su tiempo correspondiente. 
@pre: V debe contener al menos un elemento.
@return: Devuelve un iterador a aquella tarea con un menor tiempo de ejecuci�n.
*/
vector<pair<int, int>>::iterator tareaMenortiempo(vector<pair<int, int>> & v){
	vector<pair<int, int>>::iterator itElemento, it;
	
	//para ahorrar una compraci�n
	it = (++ v.begin());
	
	itElemento = v.begin();
	
	
	for(; it != v.end(); ++it){
		if((*it).second < (*itElemento).second)
			itElemento = it;
	}
	
	return itElemento;
}




/**
@brief Obtiene el orden de ejecuci�n de tareas mas �ptimo en funci�n al tiempo de ejecuci�n de las mismas.
@param v: vector de pares que contiene el n�mero de tarea y su tiempo correspondiente. 
*/
void optimizacionTareas(vector<pair<int, int>> & conjuntoTareas){
	vector<pair<int, int>> solucion;
	vector<pair<int, int>>::iterator tarea;
	
	
	//(Mientras queden candidatos y no se haya encontrado la soluci�n)
	while(!conjuntoTareas.empty()){
		
		//Seleciono una tarea
		tarea = tareaMenortiempo(conjuntoTareas);
		
		//S� la tarea es factible, la incluyo en la soluci�n
		solucion.push_back(*tarea);
		
		
		//La elimino del vector conjuntoTareas
		conjuntoTareas.erase(tarea);		
	}
	
	conjuntoTareas = solucion;
} 


//MAIN
int main(int argc, char * argv[]){

	  if (argc != 2)
		{
		  cerr << "Formato " << argv[0] << " <num_tareas>" << endl;
		  return -1;
		}

	  int n = atoi(argv[1]);
	
	//Vector de pares tarea-tiempo de ejecuci�n
	vector<pair<int, int>> T;
  


	//Rellenamos el vector T con tiempos aleatorios para las tareas.
	pair<int, int> aux;

	for (int i=0; i<n; i++)
	{
		aux.first = i+1;
		aux.second = (rand() % n*2)+1;
		T.push_back(aux);
	}



	//Imprimimos las tareas antes de pasarles el algoritmo
	//~ cout << "#########**Conjunto de candidatos**###########" << endl;
//~ 
	//~ for (int i=0; i<n; i++)
	//~ {
		//~ cout << "Tarea "  << T[i].first << "		Tiempo de ejecucion:" << T[i].second << endl;
	//~ }
	//~ cout << endl;

	//Declaraci�n de variables de tiempo
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;

	//Medida de tiempo antes de la ejecuci�n del algoritmo	******
	tantes = high_resolution_clock::now();

	//Ejecuci�n del algoritmo
	optimizacionTareas(T);


	//Medida de tiempo desp�es de la ejecuci�n del algoritmo  *****
	tdespues = high_resolution_clock::now();

	transcurrido = duration_cast<duration<double>>(tdespues - tantes);
			
	cout << n << " "  << transcurrido.count() << endl;


	//~ //Imprimimos las tareas despues de pasarles el algoritmo
	//~ cout << "#########**Resultado**###########" << endl;
//~ 
	//~ for (int i=0; i<n; i++)
	//~ {
		//~ cout << "Tarea "  << T[i].first << "		Tiempo de ejecucion:" << T[i].second << endl;
	//~ };
	//~ cout << endl;

}
