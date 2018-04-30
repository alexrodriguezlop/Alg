//**********************************************************************
//Autor: Alejandro Rodr�guez L�pez
//Email: alexrodriguezlop@correo.ugr.es
//Fichero: Pr�ctica3-Algoritmica (Greedy) Varios Electricistas
//**********************************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <stack>
#include <chrono>

using namespace std::chrono;
using namespace std;


//Algoritmo Greedy:-----------------------------------------------------------------------------------
/**
@brief Obtiene la tarea con un tiempo de ejecuci�n mayor.
@param v: vector de pares que contiene el n�mero de tarea y su tiempo correspondiente. 
@pre: V debe contener al menos un elemento.
@return: Devuelve un iterador a aquella tarea con un mayor tiempo de ejecuci�n.
*/
vector<pair<int, int>>::iterator tareaMayorTiempo(vector<pair<int, int>> & v){
	vector<pair<int, int>>::iterator itElemento, it;
	
	it = itElemento = v.begin();
	
	//para ahorrar una compraci�n
	++ it;
	
	
	
	
	for(; it != v.end(); ++it){
		if((*it).second > (*itElemento).second)
			itElemento = it;
	}
	
	return itElemento;
}


/**
@brief Obtiene el orden de ejecuci�n de tareas mas �ptimo en funci�n al tiempo de ejecuci�n de las mismas.
@param v: vector de pares que contiene el n�mero de tarea y su tiempo correspondiente. 
@param numTareas: n�mero de tareas. 
*/
vector<stack<pair<int, int>>> optimizacionTareas(vector<pair<int, int>> & conjuntoTareas, int numElectricistas){
	vector<stack<pair<int, int>>> solucion;
	vector<pair<int, int>>::iterator tarea;
	vector<stack<pair<int, int>>>::iterator lectura, insercion, ultimaInsercion;

	//Inicializacion de solucion
	stack<pair<int, int>> aux;
	aux.push(make_pair(0,0));

	for (int i=0; i<numElectricistas; i++)
	{
		solucion.push_back(aux);
	}
	
	
	ultimaInsercion = solucion.begin();	
	
	//(Mientras queden candidatos y no se haya encontrado la soluci�n)
	while(!conjuntoTareas.empty()){
		
		insercion = solucion.begin();	
		lectura = ++ solucion.begin();	
		
		//Seleciono una tarea
		tarea = tareaMayorTiempo(conjuntoTareas);
		
		//Buscamos a que electricista asignar la tarea.
		
		while(lectura != solucion.end()){	

			//S� la tarea es factible, la incluyo en la soluci�n
			//Comprueba entre aquellos en los que no se a llevado a cabo la �ltima inserci�n
			if((*lectura).size() < (*ultimaInsercion).size() && (*lectura).top().second < (*insercion).top().second){	
				insercion = lectura;
			}

			++ lectura;
		}

		//Asignamos la tarea a la cola del electricista seleccionado.
		(*insercion).push(*tarea);
		
		//Guardamos el ultimo que recibio tarea
		ultimaInsercion = insercion;
		
		
		//La elimino del vector conjuntoTareas
		conjuntoTareas.erase(tarea);
			
	}

	return solucion;
} 


//MAIN
int main(int argc, char * argv[]){

	  if (argc != 3)
		{
		  cerr << "Formato " << argv[0] << " <num_tareas> <num_electricistas>" << endl;
		  return -1;
		}
	  //n-> n�m tareas; e->n�m electricistas
	  int n = atoi(argv[1]);
	  int e = atoi(argv[2]);
	  
	//Vector de pares tarea-tiempo de ejecuci�n
	vector<pair<int, int>> T;
  


	//Rellenamos el vector T con tiempos aleatorios para las tareas.
	pair<int, int> aux;
	
	srand(time(0));
	
	for (int i=1; i<=n; i++)
	{
		aux.first = i;
		aux.second = (rand() % n*2)+1;
		T.push_back(aux);
	}

	//~ //Imprimimos las tareas antes de pasarles el algoritmo
	//~ cout << "#########**Conjunto de candidatos**###########" << endl;
		//~ 
	//~ for (int i=0; i<n; i++)
	//~ {
		//~ cout << "Tarea "  << T[i].first << "		Tiempo de ejecucion:" << T[i].second << endl;
	//~ };
	//~ cout << endl;
		
	//Declaraci�n de variables de tiempo
	high_resolution_clock::time_point tantes, tdespues;
	duration<double> transcurrido;

	//Medida de tiempo antes de la ejecuci�n del algoritmo	******
	tantes = high_resolution_clock::now();

	//Ejecuci�n del algoritmo
	vector<stack<pair<int, int>>> TT = optimizacionTareas(T, e);


	//Medida de tiempo desp�es de la ejecuci�n del algoritmo  *****
	tdespues = high_resolution_clock::now();

	transcurrido = duration_cast<duration<double>>(tdespues - tantes);
			
	cout << n << " "  << transcurrido.count() << endl;


	//~ //Imprimimos las tareas despues de pasarles el algoritmo
	//~ cout << "#########**Resultado**###########" << endl;
	//~ 
	//~ for (int j=0; j<e; j++){
		//~ cout << "------Electricista " << j+1 << "--------" <<  endl;
		//~ int contador = 0;
		//~ 
		//~ for (int i=0; i<(TT[j]).size(); i++)
		//~ {
			//~ cout << "Tarea "  << TT[j].top().first << "		Tiempo de ejecucion:" << TT[j].top().second << endl;
			//~ contador += TT[j].top().second;
			//~ TT[j].pop();
		//~ };
		//~ cout << "Total tiempo en tareas: "  << contador << endl;
		//~ cout << endl;
	//~ }

}
