/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 13
//
// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estándar y
// reciba como argumento desde la línea de órdenes un dato de tipo int.
// El programa mostrará en la salida estándar el número de palabras leidas de la entrada están-
// dar cuya longitud sea igual al argumento suministrado.
// Por ejemplo: cuenta_palabras 10 < ElQuijote.txt mostrará el número de pala-
// bras que hay en ElQuijote.txt que tienen 10 caracteres.
//
// Fichero: CuentaPalabraslongitudCroqueta.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){

	if(argc != 2){
		cerr << "Falta el argumento" << endl;
		exit(1);
	}

	char c[100];
	int  n = atoi(argv[1]);
	int j = 0;	

	while(cin >> c){

		if(strlen(c) == n){
			j++;
		}
		
	}

	cout<<endl<<"Hay " <<j << " palabra que miden "<<n<<endl;

}