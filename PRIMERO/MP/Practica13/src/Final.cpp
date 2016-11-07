/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 10
//
//  Implementar un programa que similar a tail que muestre las últimas líneas de un fichero de
// texto, tal como se encuentran en el fichero.
// Por ejemplo, la ejecución de
// Final 15 reconstruye.cpp
// mostrará las últimas 15 líneas del fichero de texto reconstruye.cpp
//
// Fichero: Final.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

//declaramos un dato de tipo Nodo para guardar las lineas

struct Nodo{
	string info;
	Nodo *sig;
};

typedef Nodo *Circular;

int main(int argc, char **argv){

	//comprobamos el nuero de argumentos

	if(argc < 3){
		cerr<<"Faltan argumentos";
		exit(1);
	}

	int n = atoi(argv[1]);

	//comprobamos las lineas que debemos mostrar(deben se mayores que 0)

	if(n > 0){

		ifstream fi;
		fi.open(argv[2]);	

		//comprobamos si se puede abrir y crear el fichero	

		if (!fi) {
			cerr << "Error: no puedo abrir "<<argv[2]<<endl;
			exit (1);
		}



		Circular base;

		//Creamos una lista circular con el numero de elementos deseado

		base = new Nodo;
		Nodo *aux = base;

		for(int i = 1; i < n; i++){
			aux->sig = new Nodo;
			aux = aux->sig;
		}
		aux->sig = base;
		aux = aux->sig;

		//recogemos las lineas
		while(getline(fi,aux->info)){			
			aux = aux->sig;
		}

		//volvemos a la "primera" posicion

		base = aux;
		aux = aux->sig;

		//Mostramos las lista

		cout << base->info;
		cout <<endl;
		while(aux != base){
			cout << aux->info;
			cout << endl;
			aux = aux->sig;
		}

		fi.close();
	}
	else{
		cout << "No hay lineas que mostrar.";
	}

	return(0);
}