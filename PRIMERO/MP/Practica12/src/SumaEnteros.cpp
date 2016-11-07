/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 11
//
// Escribir un programa que lea un fichero como los generados en los problemas 8, 9 y 10 y que
// muestre en la salida estándar la suma de todos esos números.
//
// Fichero: SumaEnteros.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main(){


	int c;
	int sum = 0;

	while(cin >> c){
		sum += c;
	}

	cout <<endl<< "La suma es : "<<sum <<endl;

}