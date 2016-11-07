/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 2
//
// Demostración de la funcionalidad de la clase Matriz2D_1.
// (Incluye constructor de copia, operador de asignación y sobrecarga de ()).
//
// Fichero: Demo-Matriz2D_1_Asignacion-Acceso.cpp
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

		if (m1.EstaVacia()) cout << "Matriz m1 esta vacia" << endl;
		else  cout << "Matriz m1 NO esta vacia" << endl;
		cout << endl << endl;


		Matriz2D_1 m2(5);

		if (m2.EstaVacia()) cout << "Matriz m2 (5x5) esta vacia" << endl;
		else  cout << "Matriz m2 (5x5) NO esta vacia" << endl;
		cout << endl << endl;

		PintaMatriz (m2, "m2 (5x5)");
		cout << endl << endl;

		m2.Inicializar ();
		PintaMatriz (m2, "m2 recien inicializada");
		cout << endl << endl;

		// Prueba del operador de acceso () para escritura
		for (int f=0; f<m2.Filas(); f++)
			m2 (f, f) = 1;

		PintaMatriz (m2, "m2 diagonal a 1");
		cout << endl << endl;


		Matriz2D_1 m3 (2, 5); 

		if (m3.EstaVacia()) cout << "Matriz m3 (2x5) esta vacia" << endl;
		else  cout << "Matriz m3 (2x5) NO esta vacia" << endl;
		cout << endl << endl;

		m3.Inicializar ();

		PintaMatriz (m3, "m3 (2x5) a ceros");
		cout << endl << endl;


		Matriz2D_1 m4 (5, 8); 

		if (m4.EstaVacia()) cout << "Matriz m4 (5x8) esta vacia" << endl;
		else cout << "Matriz m4 (5x8) NO esta vacia" << endl;
		cout << endl << endl;

		m4.Inicializar (9);

		PintaMatriz (m4, "m4 (5x8) a nueves");
		cout << endl << endl;

       // "m5" se construye como copia de "m4"
       
		Matriz2D_1 m5 (m4);
		
        PintaMatriz (m5, "m5 creada como copia de m4");
      	cout << endl << endl;  
        
 		// Operador de asignación 
  		
		Matriz2D_1 m6(6, 3); // Constructor de matriz 6x3
	  
	  	PintaMatriz (m6, "m5 vacia de dimension 6x3");
      	cout << endl << endl;  
      			  
		m6 = 9; // Operador de asignación
	
	  	PintaMatriz (m6, "m6 tras la asignacion m6 = 9");
      	cout << endl << endl;  

		Matriz2D_1 m7; // Constructor sin argumentos (matriz vacía)
	
		m7 = m6; // Operador de asignación 
	
	  	PintaMatriz (m7, "m7 tras la asignacion m7 = m6");
      	cout << endl << endl; 
	
		m7 = m3; // Operador de asignación 
	
	  	PintaMatriz (m7, "m7 tras la asignacion m7 = m3");
      	cout << endl << endl; 
/******************************************************************/
      	Matriz2D_1 suma;

		suma = m7 + m6;

		PintaMatriz (suma, "m7 + m6");

		cout << "Vamos a Sumar un dato:"<<endl;

		Matriz2D_1 suma_num;

		suma_num = m7 + 3;

		PintaMatriz (suma_num, "Nuevo + 3");

		cout << "Vamos a Sumar un dato:"<<endl;

		Matriz2D_1 suma_num2;

		suma_num2 = 3 + m7;

		PintaMatriz (suma_num2, "m7 + 3");

		cout << "Operador +=:"<<endl;

		m6 += m7;

		PintaMatriz (m6, "m6 +=m7");

		cout << "operado +=:"<<endl;

		m7 += 3;

		PintaMatriz (m7, "m6 +=3");

		cout << "Operador -=:"<<endl;

		m6 -= m7;

		PintaMatriz (m6, "m6 -=m7");

		cout << "operado -=:"<<endl;

		m7 -= 3;

		PintaMatriz (m7, "m6 -=3");

		if(m7 == m6){
			cout <<"m7 igual a m6"<<endl;
		}

		if(m7 != m6){
			cout <<"m7 distinto a m6"<<endl;
		}

		return (0);
	}

	/**********************************************************************/
	/**********************************************************************/
