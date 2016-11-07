/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 1
//
// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estándar y
// los copie literalmente en la salida estándar.
//
// Fichero: CopiaTodo.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

	const int TAM = 999;

	char * texto;

	cin.getline(texto, TAM);

	while(!cin.eof()){
		cout <<texto<<endl;
		cin.getline(texto, TAM);

	}

	

	return(0);
}