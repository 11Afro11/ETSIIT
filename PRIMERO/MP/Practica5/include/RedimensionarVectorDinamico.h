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
// FICHERO MiCadenaClasica.h
//
/*	

este fichero contiene las cabeceras de las funciones


*/
/*********************************************************************/



#ifndef REDIMENSIONA
#define REDIMENSIONA

#include <cstring>

//Declaramos el dato de tipo enumerate

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

//Declaramos la funcion Reedimensiona que se encargara de modificar el tamanio del vector

int * Redimensiona (int *puntero, TipoRedimension opcion, int &TAM);



#endif