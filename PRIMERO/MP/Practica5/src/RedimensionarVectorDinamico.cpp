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
// SESION 5
// FICHERO Redimensiona.cpp
//
/*	

Este fichero contiene el desarrollo de las cabeceras del Redimensiona.h 


*/
/*********************************************************************/

//referencia a Redimensiona.h
#include <iostream>
#include "RedimensionarVectorDinamico.h"


/*
Funcion que recibe como parámetros un puntero, un dato de tipo TipoRedimension, y un tamanio pasado por referencia
La funcion incrementa la memoria existente en el vector y devuelve un puntero a la nueva posicion de memoria
*/


int * Redimensiona (int *puntero, TipoRedimension opcion, int & TAM){

	
	int tam_primero = TAM; 

	int *aux;
	aux = puntero;
	if(opcion == 0){
		TAM = TAM + 1;
	}
	if(opcion == 1){
		TAM = TAM + sizeof(int);
	}
	if(opcion == 2){
		TAM = 2 * TAM;
	}

	puntero = new int[TAM];

	memcpy(puntero, aux, sizeof(int)*tam_primero);
	
	delete[] aux;

	return puntero;
}