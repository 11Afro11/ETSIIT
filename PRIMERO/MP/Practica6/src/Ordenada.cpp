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
// SESION 6
//
/*	

 Utilizando como base el problema 6, escribir un programa que lea una secuencia de valores y
los almacene en una lista. Escribir una función que determine si la secuencia está ordenada.


*/
/*********************************************************************/
#include <iostream>
#include "lista.h"

using namespace std;


int main(){

	pinta();
	cout <<endl<<endl;

	TipoLista *puntero;
	TipoLista *puntero2;
	puntero = CreaEstructuraLineal();

	if(EstaOrdenada(puntero) == true){
		cout << endl << "La lista esta ordenada"<<endl;
	}
	else{
		cout <<endl << "La lista NO esta ordenada"<<endl;
	}
	pinta();
}