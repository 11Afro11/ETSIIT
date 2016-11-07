/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 8
//
// Escribir un programa que lea una serie indefinida de números enteros de la entrada estándar
// y los copie, en el mismo orden, en la salida estándar.
// - En la secuencia de entrada se pueden usar espacios, tabuladores o saltos de líneas (en
// cualquier número y combinación) para separar dos números enteros consecutivos.
// - En la secuencia de salida se separan dos enteros consecutivos con un salto de línea.
//
// Fichero: CopiaEnteros.cpp
//
/***************************************************************************/

#include <iostream>

using namespace std;

int main(){

	int c;

	while(cin>>c){
		cout << c<<endl;
	}
	cout << endl;

	return 0;
}