/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 6
//
//  Un fichero de texto contiene números enteros que se disponen en líneas y en cada línea están
// separados por espacios en blanco. Todas las líneas tienen el mismo número de elementos.
// Se trata de escribir un constructor para las clases Matriz2D-1 y Matriz2D-2 que reciba
// el nombre de un fichero con la estructura descrita y rellene las casillas de la matriz con los
// datos (guardados por filas) contenidos en el fichero.

//
// Fichero: Constructores.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "Matriz2D_1.h"

#include "Matriz2D_2.h"

using namespace std;

int main(int argc, char **argv){

	//filtro de argumentos
	if(argc < 2){
		cerr<<"Faltan argumentos";
		exit(1);
	}

	//declaramos y comprobamos los flujos
	ifstream fi;
	fi.open(argv[1]);


	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}

	//construimos la matriz2D_1 a partir de un fichero
	Matriz2D_1 matriz(fi);

	//mostramos la matriz

	cout << "Matriz2D_1:"<<endl;

	for(int i = 0; i < matriz.Filas(); i++){
		for(int j = 0; j < matriz.Columnas(); j++){
			cout << matriz(i,j) << " ";
		}
		cout << endl;
	}
	fi.close();

	cout << endl <<endl;
	//construimos la matriz2D_2 con un fichero

	fi.open(argv[1]);

	Matriz2D_2 matriz2(fi);

	//mostraos la matriz
	cout << "Matriz2D_2:"<<endl;
	for(int i = 0; i < matriz2.Filas(); i++){
		for(int j = 0; j < matriz2.Columnas(); j++){
			cout << matriz2(i,j) << " ";
		}
		cout << endl;
	}
	fi.close();

	return(0);


}