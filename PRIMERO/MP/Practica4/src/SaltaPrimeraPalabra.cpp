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
// EJERCICIO 7
//
/*	

 Consideremos una cadena de caracteres “clásica”. Escriba un programa que lea una cadena
y la imprima pero saltándose la primera palabra, evitando escribirla carácter a carácter.
Considere que puede haber ninguna, una o más palabras, y si hay más de una palabra, están
separadas por espacios en blanco.

*/
/*********************************************************************/

#include <iostream>
#include <cstring>


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

	//busqueda de blancos iniciales

	while(*puntero == ' '){
		puntero++;
	}

	//busqueda de estacios

	while(*puntero != ' '){
		puntero++;
	}


	//filtro que comprueba si hay espacios en blanco y salida de datos

	if(isspace(*puntero)){

		for(int i = (puntero - cadena)+1; i < strlen(cadena); i++){

			cout <<*(cadena + i);

		}
	}

	cout <<endl<<endl;

}