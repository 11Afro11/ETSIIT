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

 Considere dos secuencias de datos ordenadas almacenadas en sendas listas. Implemente
una función para mezclar ordenadamente las dos secuencias en una nueva, de forma que
las dos listas originales se queden vacías tras realizar la mezcla y la lista resultante contenga
todos los datos.
Observe se trata de una variante del algoritmo mergesort. Ahora se exige la modificación de
las secuencias originales: en esta versión los datos se “mueven” hacia la lista resultante en
lugar de copiarlos.


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
		cout << endl << "Vamos a ordenar la lista: "<<endl;
		Ordena_por_Seleccion(puntero);
	}

	MuestraEstructuraLineal(puntero);

	pinta();

	cout << endl << "Introduzca otra lista: "<<endl;
	puntero2 = CreaEstructuraLineal();

	if(EstaOrdenada(puntero2) == true){
		cout << endl << "La lista esta ordenada"<<endl;
	}
	else{
		cout <<endl << "La lista NO esta ordenada"<<endl;
		cout << endl << "Vamos a ordenar la lista: "<<endl;
		Ordena_por_Seleccion(puntero2);
	}
	pinta();
	MuestraEstructuraLineal(puntero2);

	pinta();

	TipoLista *enlazada;

	cout << endl << "Vamos a unir las listas: "<< endl;

	enlazada = Enlaza(puntero, puntero2);

	MuestraEstructuraLineal(enlazada);

	pinta();
}

	