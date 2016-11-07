/*********************************************************************/
// METODOLOGÍA DE LA PROGRANACIÓN
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 4
// EJERCICIO 6
//
/*	

 Las cadenas de caracteres (tipo “C”, o cadenas “clásicas”) son una buena fuente para ejerci-
tarse en el uso de punteros. Una cadena de este tipo almacena un número indeterminado de
caracteres (para los ejercicios basatará un valor siempre menor que 100) delimitados al final
por el carácter nulo (’\0’).
Escriba un programa que lea una cadena y localice la posición del primer carácter espacio
(’ ’) en una cadena de caracteres “clásica”. El programa debe indicar su posición (0: primer
carácter, 1: segundo carácter, etc.).


*/
/*********************************************************************/

#include <iostream>


using namespace std;


int main(){

	//declaracion de variables

	const int TAM = 100;

	char cadena[TAM];

	char *puntero;


	//solicitud de datos por pantalla

	cout << "Introcuce el texto: ";
	cin.getline(cadena, TAM);

	puntero = cadena;

	//bucle que busca el espacio en blanco

	while(*puntero != ' ' && *puntero != '\0'){
		puntero++;
	}

	//salida de datos con filtro que tiene en cuenta si existen o no espacios en blanco

	if(isspace(*puntero)){

		cout << "El espacio en blanco se encuentra en la poscición "<< puntero - cadena <<endl;
	}

	else{
		cout << "no hay espacios en blanco."<<endl;
	}

}

