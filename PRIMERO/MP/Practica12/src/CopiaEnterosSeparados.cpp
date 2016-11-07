/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 10
//
// Escribir un programa que lea una serie indefinida de números enteros de la entrada estándar
// y los copie, en el mismo orden, en la salida estándar.
// - En la secuencia de entrada los números están separados por el carácter ’*’.
// - En la secuencia de salida se separan dos enteros consecutivos con un salto de línea.
//
// Fichero: CopiaEnterosSeparados.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

	char *c = new char;

	while(cin >> c){
		if(*c != '*'){
			cout << atoi(c)<<endl;
		}
	}
	cout << endl;

	delete []c;

	return 0;
}