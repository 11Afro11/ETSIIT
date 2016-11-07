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

 Considere una secuencia de datos almacenada en una lista. Implemente una función para
ordenar la secuencia empleando el método de ordenación por selección.


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

}