/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 1
//
// 
// 
//
// Fichero: Transformaciones.cpp
//
/***************************************************************************/

#include "Transformaciones.h"



/*********************************************************************/
// Funcion que convierte un conjunto en un vector

VectorDinamico ConjuntoToVectorDinamico (Conjunto & c){
	VectorDinamico vec(c.Tamanio());

	for(int i = 0; i < c.Tamanio(); i++){
		vec[i] = c[i];
	}
	return vec;
}

/*********************************************************************/
// Funcion que transforma un vector en un conjunto


Conjunto VectorDinamicoToConjunto (VectorDinamico & v){
	Conjunto con;
	for(int i = 0; i < v.NumDatosGuardados(); i++){
		con.Aniade(v[i]);
	}
	return con;
}