/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 2
//
// Escribir un programa que lea una secuencia indefinida de caracteres de la entrada estándar y
// los copie en la salida estándar, exceptuando las vocales.
//
// Fichero: CopiaExceptoVocales.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;


int main(){

	char texto;
	texto = cin.get();
	while(!cin.eof()){
		 switch(tolower(texto)){ 
	      case 'a': 
	      case 'e': 
	      case 'i': 
	      case 'o': 
	      case 'u': 
	        /* se ignoran */ 
	        break; 
	      default: 
	        cout << texto; 
	        break;
	    }
	    texto = cin.get();

	}

	return(0);
}