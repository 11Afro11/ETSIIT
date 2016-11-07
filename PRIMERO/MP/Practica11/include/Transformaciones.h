/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 5
//
// Ejercicio de transformaciones
// (Incluye constructores, destructor, operador de asignación y métodos 
// simples de consulta). 
//
// Fichero: Transformaciones.h
//
/***************************************************************************/

#ifndef TRANSFORMACIONES
#define TRANSFORMACIONES

#include "Conjunto.h"
#include "VectorDinamico.h"

//Metodo que convierte un conjunto en un vector.

VectorDinamico ConjuntoToVectorDinamico (Conjunto & c);

//Metodo que convierte un vector en un conjunto

Conjunto VectorDinamicoToConjunto (VectorDinamico & v);


#endif