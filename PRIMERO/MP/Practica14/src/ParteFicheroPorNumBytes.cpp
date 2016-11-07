/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
// EJERCICIO 5
//
//  Construir un programa que divida un fichero de cualquier tipo en diferentes ficheros, indicando
//como argumentos el nombre del fichero original y el máximo número de bytes que contendrá
//cada fichero resultante.
//
// Fichero: ParteFicherosPorNumeroBytes.cpp
//
/***************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int main (int argc, char **argv)
{
	const int TAM_BUFFER = 4; // Num. de bytes del buffer de lectura
	char buffer [TAM_BUFFER];
	 // Buffer de lectura
	ifstream fi; //Flujo de entrada
	ofstream fo; //Flujo de salida
	if (argc != 2) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <fichE>\n";
		exit (1);
	}

	fi.open (argv[1], ios::binary);
	 // Apertura (para lectura)
	// en modo binario
	if (!fi) {
		cerr << "Error: no puedo abrir " << argv[1] << endl;
		exit (1);
	}

	if (!fo) {
		cerr << "Error: no puedo crear " << argv[2] << endl;
		exit (1);
	}
	string name = argv[1];//nombre del objeto
	string extension = ".txt";//extension
	int j = 1;	//cuenta numero de fichero
	int lines = atoi(argv[2]); 	//numero de lineas tope
 	



	while (fi.read (reinterpret_cast<char*>(buffer), TAM_BUFFER)){
		//flijo asociado a string que se encarga de numerar los ficheros
		ostringstream oss;
		oss <<setfill('0')<< setw(3)<<j;

		//declaramos el string que lleva el numero y creamos el nombre del fichero
		string num(oss.str());
		//creamos el fichero y comprobamos si puede crearse
		fo.open(name + "_" + num + extension, ios::binary);

		if (!fo) {
			cerr << "Error: no puedo crear "<<name + num + extension<<endl;
			exit (1);
		}

		fo.write (buffer, TAM_BUFFER);

		cout << "Creado "<<name + "_" + num + extension<<" con exito\n";

		//cerramos el fichero de salida
		fo.close();
		//incrementamos el numero de fichero
		j++;
	}
	fo.write(buffer, fi.gcount());

	fo.open("." + name + ".ctrl");
	fo << name<<endl;
	fo << j<<endl;

	//cerramos los ficheros
	fi.close();
	fo.close();

	return(0);
}