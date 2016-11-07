/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 9
//
//  Implementar un programa que similar a head que muestre las primeras líneas de un fichero
// de texto, tal como se encuentran en el fichero.
//
// Fichero: Cabecera.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){

	//filtro para comprobar los argumentos
	if(argc < 3){
		cerr<<"Faltan argumentos";
		exit(1);
	}
	//entero igual al primer argumento. numero de lineas
	int n = atoi(argv[1]);

	//declaramos el flujo de entrada
	ifstream fi;
	fi.open(argv[2]);

	//comprobamos si puede leerse el archivo
	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[2]<<endl;
		exit (1);
	}

	//declaramos las variables
	string linea;
	int i = 0;

	//leemos el fichero
	while(getline(fi,linea) && i < n){
		cout << linea;
		cout << endl;
		i++;
	}
	//cerramos el fichero
	fi.close();

	return(0);
}