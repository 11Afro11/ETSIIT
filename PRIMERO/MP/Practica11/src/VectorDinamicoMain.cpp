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
// Demostración de la funcionalidad de la clase VectorDinamico.
// (Incluye constructor de copia, operador de asignación y sobrecarga de []).
//
// Fichero: Demo-VectorDinamico_Asignacion-Acceso.cpp
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

		// Muestra el vector	
		
		int usados = almacen.NumDatosGuardados();
		int capacidad = almacen.Capacidad();

		cout << endl;
		cout << "Capacidad del vector = " << capacidad << " datos" << endl; 
		cout << "Contiene = " << usados << " datos" << endl; 
		
		PintaVectorDinamico (almacen, "almacen");
		
		
		// Prueba de constructor de copia
		
		VectorDinamico copia_almacen (almacen);

		cout << "Capacidad del vector = " << copia_almacen.Capacidad() 
		     << " datos" << endl; 
		cout << "Contiene = " << copia_almacen.NumDatosGuardados()
		     << " datos" << endl; 
		PintaVectorDinamico (copia_almacen, "copia_almacen");
		
			
		// Prueba del operador de asignacion
		
		VectorDinamico nuevo;
		
		cout << "Creado el vector nuevo" << endl;
		cout << "Capacidad del vector = " << nuevo.Capacidad() 
		     << " datos" << endl; 
		cout << "Contiene = " << nuevo.NumDatosGuardados()
		     << " datos" << endl; 
		PintaVectorDinamico (nuevo, "nuevo");		
		
		nuevo = almacen;
		
		cout << "Se ha asignado nuevo=almacen" << endl;		
		cout << "Capacidad del vector = " << nuevo.Capacidad() 
		     << " datos" << endl; 
		cout << "Contiene = " << nuevo.NumDatosGuardados()
		     << " datos" << endl;
		PintaVectorDinamico (nuevo, "nuevo despues de nuevo=almacen");			
		
		VectorDinamico copia_nuevo;
		copia_nuevo = nuevo;			// Asignación desde VectorDinamico
		copia_nuevo = 9;				// Asignación desde TipoBase
		PintaVectorDinamico (copia_nuevo, "copia_nuevo con 9");		
		
		
		// Prueba del operador de acceso []
		
		cout << "Primer elemento = " << nuevo[0] << endl;
		cout << "Ultimo elemento = " << nuevo[nuevo.NumDatosGuardados()-1] << endl;
		cout << endl;
			
		cout << "Intercambiando primero y ultimo." << endl;
		
		TipoBase tmp = nuevo[0];
		nuevo[0] = nuevo[nuevo.NumDatosGuardados()-1];
		nuevo[nuevo.NumDatosGuardados()-1] = tmp;
			
		PintaVectorDinamico (nuevo, "nuevo despues de intercambiar extremos");	

		cout << "Vamos a Sumar Vectores:"<<endl;

		VectorDinamico suma;

		suma = nuevo + almacen;

		PintaVectorDinamico (suma, "Nuevo + almacen");

		cout << "Vamos a Sumar un dato:"<<endl;

		VectorDinamico suma_num;

		suma_num = nuevo + 3;

		PintaVectorDinamico (suma_num, "Nuevo + 3");

		cout << "Operador +=:"<<endl;

		nuevo += suma;

		PintaVectorDinamico (nuevo, "Nuevo +=suma");

		cout << "operado +=:"<<endl;

		nuevo += 3;

		PintaVectorDinamico (nuevo, "Nuevo += 3");

		if(nuevo == suma){
			cout <<"nuevo igual a suma"<<endl;
		}

		if(nuevo != suma){
			cout <<"nuevo distinto a suma"<<endl;
		}

		if(nuevo < suma){
			cout <<"nuevo menor que suma"<<endl;
		}

		if(nuevo > suma){
			cout <<"nuevo mayor que suma"<<endl;
		}

		if(nuevo <= suma){
			cout <<"nuevo menor o igual que suma"<<endl;
		}

		if(nuevo >= suma){
			cout <<"nuevo mayor o igual que suma"<<endl;
		}


						
		return (0);
	}

	/***********************************************************************/
	/***********************************************************************/
