/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 2
//
//  Escribir un programa similar a diff para comparar dos ficheros de texto. El programa impri-
// mirá el número de la primera línea en la que difieren y el contenido de éstas.
//
// Fichero: Diferencias.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){

	//filtro paralos argumentos

	if(argc < 3){
		cerr<<"Faltan argumentos";
		exit(1);
	}

	//declaramos los flujos de entrada y comprobamos si se pueden abrir

	ifstream fi;
	fi.open(argv[1]);

	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}

	ifstream fo;
	fo.open(argv[2]);

	if (!fo) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}

	//declaramos tanto el contador de lineas como las cadenas que reciben
	//los datos

	int i = 1;

	string c;
	string q;

	bool iguales = true;

	//lectura y tratamientode ficheros

	getline(fi,c);
	getline(fo,q);
	if(c[0] != '\n' && q[0] != '\n')
		iguales = strcmp(c.c_str(),q.c_str()) == 0;

	while(!fi.eof() && !fo.eof() && iguales){

		if(c[0] != '\n' && q[0] != '\n')
			iguales = strcmp(c.c_str(),q.c_str()) == 0;

		getline(fi,c);
		getline(fo,q);
		i++;
	}

	//siun fichero termina antes que otro los ficheros no son iguales

	if((fi.eof() && !fo.eof()) || (!fi.eof() && fo.eof()) )
		iguales = false;

	//salida de datos por pantalla

	if(!iguales){
		cout << endl <<"Primera diferencia en linea: "<<endl<<endl << "("<<i<<")"<<endl;
		cout << "\t" << argv[1] << " : " << c;
		cout << endl;
		cout << "\t" << argv[2] << " : " << q;
		cout <<endl<<endl;
	}
	else{
		cout << endl <<"Los ficheros son iguales."<<endl<<endl;
	}

	return(0);
}