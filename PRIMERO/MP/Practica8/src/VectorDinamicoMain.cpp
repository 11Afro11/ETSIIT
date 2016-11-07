/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 1
//
// Demostración de la funcionalidad de la clase VectorDinamico.
// (Incluye constructor de copia).
//
// Fichero: Demo-VectorDinamico_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	
	#include "VectorDinamico.h"
	
	using namespace std; 

	/***********************************************************************/
	/***********************************************************************/

	int main (void)
	{
		
		// Constructor con un argumento
		VectorDinamico almacen (3);

		 
		PintaVectorDinamico (almacen, "almacen");
		
		
		almacen.Redimensiona (Duplicando);

		int valor;

		cout << "Introducir un valor (para finalizar, un negativo): ";
		cin >> valor;

		while (valor >= 0) {

			almacen.Aniade (valor);

			cout << "Introducir un valor (para finalizar, un negativo): ";
			cin >> valor;
		}
   

		PintaVectorDinamico (almacen, "almacen");
		
		
		// Prueba de constructor de copia
		
		VectorDinamico copia_almacen (almacen);


		PintaVectorDinamico (copia_almacen,"copia_almacen");
		
		
		// Prueba de constructor sin argumentos
		
		VectorDinamico otro_almacen;

		
		PintaVectorDinamico (otro_almacen, "otro_almacen");

		return (0);
	}

	/***********************************************************************/
	/***********************************************************************/
