/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 4
//
// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estándar y
// muestre en la salida estándar el número de líneas no vacías que hay en esa secuencia.
//
// Fichero: CuentaLineasNoVacias.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
	
	const int TAM = 100;
	char * texto = new char[TAM];
	int cont = 0;
	texto[cont] = '\0';
	cin.getline(texto, TAM);

	while(!cin.eof()){
		
		if(texto[0] != '\0'){
			cont ++;
		}
		cin.clear();
		cin.getline(texto, TAM);
	}
	cout <<"Lineas No vacias: "<<cont<<endl;
}