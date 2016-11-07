/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 8
//
//  Escribir un programa similar a grep que busque una cadena en una serie de ficheros de texto.
// La cadena a buscar y los ficheros en los que buscar se proporcionan en la línea de órdenes.
// Cada vez que encuentre la cadena buscada, debe indicar el fichero en el que es localizada, el
// número de línea y la línea completa que la contiene.
//
// Fichero: Busca.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <istream>

using namespace std;

int main(int argc, char **argv){


	if(argc < 3){
		cerr << "Faltan argumentos"<<endl;
		exit(1);
	}

	ifstream fi;
	ofstream fo;
	fo.open("Busqueda.txt");

	if (!fo) {
		cerr << "Error: no puedo crear "<<"Busqueda.txt"<<endl;
		exit (1);
	}


	const char* buscar = argv[1];
	string compara;
	int line;
	char *n = new char[50];


	for(int i = 2; i < argc; i++){
		fi.open(argv[i]);

		if (!fi) {
			cerr << "Error: no puedo abrir "<<argv[i]<<endl;
			exit (1);
		}

		line = 1;
		while(getline(fi, compara)){
			istringstream iss;
 			iss.str (compara);
 
			while(iss >> n){					
				if(!strcmp(n, buscar)){
					fo << argv[i];
					fo << " (linea "<<line << "): ";
					fo << compara;
					fo << endl;
				}
			}
			line++;
		}
		fi.close();
	}

	
	fo.close();

	cout << endl<<"Creado \"Busqueda.txt\""<<endl;

	return 0;
}