/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 2
//
// Demostración de la clase Matriz2D_1 (con constructor de copia).
// La versión incluye constructor de copia.
//
// Fichero: Demo-Matriz2D_1_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	
	#include "Matriz2D_1.h"
	
	using namespace std; 

	/**********************************************************************/
	/**********************************************************************/
	
	int main (void)
	{

		Matriz2D_1 m1;

		if (m1.EstaVacia())
			cout << "Matriz m1 esta vacia" << endl;
		else 
			cout << "Matriz m1 NO esta vacia" << endl;
		cout << endl << endl;


		Matriz2D_1 m2(5);

		if (m2.EstaVacia())
			cout << "Matriz m2 (5x5) esta vacia" << endl;
		else 
			cout << "Matriz m2 (5x5) NO esta vacia" << endl;
		cout << endl << endl;


		PintaMatriz (m2, "m2 (5x5)");
		cout << endl << endl;

		m2.Asigna ();


		PintaMatriz (m2, "m2 recien inicializada");
		cout << endl << endl;


		for (int f=0; f<m2.Filas(); f++)
			m2.PonValor (f, f, 1);


		PintaMatriz (m2, "m2 diagonal a 1");
		cout << endl << endl;


		Matriz2D_1 m3 (2, 5); 

		if (m3.EstaVacia())
			cout << "Matriz m3 (2x5) esta vacia" << endl;
		else 
			cout << "Matriz m3 (2x5) NO esta vacia" << endl;
		cout << endl << endl;

		m3.Asigna ();


		PintaMatriz (m3, "m3 (2x5) a ceros");
		cout << endl << endl;


		Matriz2D_1 m4 (5, 8); 

		if (m4.EstaVacia())
			cout << "Matriz m4 (5x8) esta vacia" << endl;
		else 
			cout << "Matriz m4 (5x8) NO esta vacia" << endl;
		cout << endl << endl;

		m4.Asigna (9);


		PintaMatriz (m4, "m4 (5x8) a nueves");
		cout << endl << endl;


        // "m5" se construye como copia de "m4"
       
		Matriz2D_1 m5 (m4);

		
        PintaMatriz (m5, "m5 creada como copia de m4");
      	cout << endl << endl;  
        
		return (0);
	}

	/**********************************************************************/
	/**********************************************************************/
