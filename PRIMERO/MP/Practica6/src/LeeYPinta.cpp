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

 Escriba un programa para que lea una secuencia con un número indefinido de valores
double hasta que se introduzca un valor negativo. Estos valores (excepto el último, el nega-
tivo) los almacenará en una estructura de celdas enlazadas (una lista) y después mostará los
valores almacenados.
Escribir un programa para solucionar este problema, con dos funciones:
a) Una para leer y almacenar los valores. Tenga en cuenta que podríamos decidir no intro-
ducir ningún valor y la lista resultante sería una lista vacía.
b) Otra para mostrarlos.



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

	cout << endl << "Su vector es: "<<endl;
	MuestraEstructuraLineal(puntero);
	pinta();

}