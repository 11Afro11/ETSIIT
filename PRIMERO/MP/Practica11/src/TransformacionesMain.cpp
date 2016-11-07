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
// Fichero: TransformacionesMain.cpp
//
/***************************************************************************/


#include "Transformaciones.h"

#include <iostream>

using namespace std;


int main(){

	VectorDinamico almacen (3);
	almacen.FijaRedimensionamiento (EnBloques);

	int valor;

	cout << "Introducir un valor (para finalizar, un negativo): ";
	cin >> valor;

	while (valor >= 0) {

		almacen.Aniade (valor);

		cout << "Introducir un valor (para finalizar, un negativo): ";
		cin >> valor;
	}

	PintaVectorDinamico (almacen, "Vector Dinamico");

	Conjunto conjunto;

	conjunto = VectorDinamicoToConjunto (almacen);

	PintaConjunto (conjunto, "Conjunto");

	VectorDinamico otro;

	otro = ConjuntoToVectorDinamico (conjunto);

	PintaVectorDinamico (almacen, "Vector Dinamico");


}