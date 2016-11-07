/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 1
//
//  Escribir un programa que reciba los nombres de dos ficheros de texto de la línea de órdenes. El
// programa creará un fichero (cuyo nombre se especifica en el segundo argumento) a partir de
// un fichero existente (cuyo nombre se especifica en el primer argumento) copiando su contenido
// y añadiendo al principio de cada línea, su número.
//
// Fichero: NumeraLineas.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){

	//comprobamos los argumentos
	if(argc < 3){
		cerr<<"Faltan argumentos";
		exit(1);
	}
	//declaramos el flujo de entrada  y salida y comprobamos si pueden abrirse y crearse
	ifstream fi;
	fi.open(argv[1]);

	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}


	ofstream fo;
	fo.open(argv[2]);

	if (!fo) {
		cerr << "Error: no puedo crear "<<argv[2]<<endl;
		exit (1);
	}

	//declaramos las variables
	int i = 1;

	string texto;

	while(getline(fi,texto)){
		fo << i<<" ";		
		fo << texto<<endl;
		i++;
	}
	fi.close();
	fo.close();

	return(0);

}