/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 7
//
//  Construir un programa que divida un fichero de texto en diferentes ficheros indicando como
// argumentos el nombre del fichero original y el máximo número de líneas que contendrá cada
// fichero resultante.
// Se creará un fichero de control que contendrá con los datos necesario para la reconstrucción
// del fichero original.
//
// Fichero: ParteFicheroPorNumLineas.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv){

	//comprobamos los argumentos
	if(argc < 3){
		cerr<<"Faltan argumentos";
		exit(1);
	}

	//declaramos el flujo de entrada y comprobamos si puede abrirse
	ifstream fi;
	fi.open(argv[1]);

	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}

	//declaramos un flujo de salida
	ofstream fo;

	//declaramos las variables necesarias
	string texto;

	string name = argv[1];//nombre del objeto
	string extension = ".txt";//extension
	int j = 1;	//cuenta numero de fichero
	int lines = atoi(argv[2]); 	//numero de lineas tope
 	

	getline(fi, texto);

	while(!fi.eof()){

		//flijo asociado a string que se encarga de numerar los ficheros
		ostringstream oss;
		oss <<setfill('0')<< setw(3)<<j;

		//declaramos el string que lleva el numero y creamos el nombre del fichero
		string num(oss.str());
		//creamos el fichero y comprobamos si puede crearse
		fo.open(name + num + extension);

		if (!fo) {
			cerr << "Error: no puedo crear "<<name + num + extension<<endl;
			exit (1);
		}

		//leemos las lineas y las guardamos en el fichero
		for(int i = 0; i < lines && !fi.eof();i++){
			fo << texto;
			fo << endl;
			getline(fi, texto);
		}
		//cerramos el fichero de salida
		fo.close();
		//incrementamos el numero de fichero
		j++;
	}
	//cerramos los ficheros
	fi.close();
	fo.close();

	return(0);
}