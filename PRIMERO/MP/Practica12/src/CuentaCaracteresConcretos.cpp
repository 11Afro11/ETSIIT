/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 12
//
// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estándar y
// reciba como argumento desde la línea de órdenes un dato de tipo char. El programa mos-
// trará en la salida estándar el número de caracteres leidos de la entrada estándar iguales al
// argumento suministrado.
// Por ejemplo: cuenta_letra a < ElQuijote.txt mostrará el número de caracteres
// a que hay en ElQuijote.txt
//
// Fichero: CuentaCaracteresConcretos.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){

	if(argc != 2){
		cerr << "Falta el argumento" << endl;
		exit(1);
	}

	char c;
	char letra = argv[1][0];
	int i = 0;

	while(cin >> c){
		if(c == letra){
			i++;
		}
	}

	cout<<"Hay "<<i <<" "<<letra<<endl;

}