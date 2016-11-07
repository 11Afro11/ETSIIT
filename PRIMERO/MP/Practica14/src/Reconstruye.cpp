/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
// EJERCICIO 6
//
// Construir un programa que reconstruya un fichero a partir de una serie de ficheros que con-
//tienen sus “partes”. Los ficheros que pueden emplearse como origen se han creado con los
//programas descritos en los problemas 7 (Relación de Problemas VI) y 5 (Relación de Proble-
//mas VII) y por ese motivo se empleará el fichero de control creado por esos programas.
//Por ejemplo, la ejecución de reconstruye Fichero genera como resultado Fichero.
//Usará .Fichero.ctrl para conocer los ficheros que debe usar y el orden a seguir.
//Recomendación: La construcción de los nombres de los ficheros que contienen las partes
//(Fichero_001, Fichero_002, . . . ) es sencilla si se emplea un flujo asociado a una ca-
//dena. En este caso, se tratará de un objeto ostringstream.
//
// Fichero: Reconstruye.cpp
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
	if (argc < 2) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <fichE>\n";
		exit (1);
	}
	string name(argv[1]);

	fi.open ("."+name+"ctrl");

	if (!fi) {
		cerr << "Error: no puedo abrir " << argv[1] << endl;
		exit (1);
	}

	string nombre;
	getline(fi,nombre);
	string extension(".txt");


	// Apertura (para lectura)
	// en modo binario

	int j;	//cuenta numero de fichero
	fi >> j;

	fi.close();
	fo.open(nombre, ios::binary);

	for(int i = 1; i < j; i++){

		ostringstream oss;
		oss <<setfill('0')<< setw(3)<<i;

		//declaramos el string que lleva el numero y creamos el nombre del fichero
		string num(oss.str());
		//creamos el fichero y comprobamos si puede crearse
		fi.open(name + "_" + num + extension, ios::binary);

		while (fi.read (reinterpret_cast<char*>(buffer), TAM_BUFFER))
			fo.write (buffer, TAM_BUFFER);
		//En cada iteración se intentan leer TAM_BUFFER bytes a través
		// de "fi". Mientras sea posible, se escribirán esos mismos datos
		// en el fichero asociado a "fo".
		//Cuando no sea posible (último bloque) se sale del ciclo.
		fo.write(buffer, fi.gcount());

		fi.close();
	}

	fi.close();
	fo.close();

	return(0);
}