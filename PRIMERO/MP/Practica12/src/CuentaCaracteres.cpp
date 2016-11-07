/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 3
//
// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estándar y
// muestre en la salida estándar el número total de caracteres leidos.
//
// Fichero: CuentaCaracteres.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;


int main(){

	char texto;
	int i=0;
	texto = cin.get();

	while(!cin.eof()){
		i++;
		texto = cin.get();
	}

	cout <<i<<endl;

	return(0);
}