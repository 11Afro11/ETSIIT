/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 4
//
// Demostración de la funcionalidad de la clase Lista.
// (Incluye constructor de copia).
//
// Fichero: Demo-Lista_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	
	#include "Lista_ConstructorCopia.h"
	
	using namespace std; 

	/***********************************************************************/
	/***********************************************************************/

	int main (void)
	{

		Lista lista(5);

		PintaLista (lista, "Despues de crear la lista con tamaño 5");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << "Tercer elemento = " << lista.ObtenValor(3) << endl;
		cout << endl;

		lista.Inicializar (0);
		PintaLista (lista, "Despues de lista.Inicializar(0)");
		cout << endl;

		lista.Inserta(7,2);
		PintaLista (lista, "Despues de lista.Inserta(7,2)");
		cout << "Tamanio = " << lista.Tamanio() << endl;	
		cout << endl;

		lista.Inserta(9,lista.Tamanio()+1);
		PintaLista (lista, "Despues de lista.Inserta(9, lista.Tamanio()+1");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;
		
		lista.Inserta(6,3);
		PintaLista (lista, "Despues de lista.Inserta(6,3)");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;
		
		

		PintaLista (lista, "Mostrando informacion");
		cout << "Tamanio = " << lista.Tamanio() << endl;

		for (int pos=1; pos<=lista.Tamanio(); pos++)
			cout << "Elemento " << setw(2) << pos 
			     << " = " << setw (3) << lista.ObtenValor(pos) << endl;
		cout << endl;


		cout << "Buscando el 7 ..." << endl;
		
		int pos_7 = lista.Busca (7);
		
		if (pos_7 != -1) 
			cout << "Encontrado en la posicion " << pos_7;
		else 
			cout << "No se encontró.";
		cout << endl; 

		Lista igualacion;

		igualacion = lista;

		cout << "Vamos a probar el operador de asignacion:"<<endl;
		cout << "Igualamos dos listas: igualacion = lista ";

		PintaLista(igualacion);

		cout << "Vamos a probar el operador de asignacion:"<<endl;
		cout << "Igualamos a una constante: igualacion = 4";

		igualacion = 4;

		PintaLista(igualacion);


		cout << "Vamos a probar el operador []:"<<endl;
		cout << "Posicion 3: ";

		cout << igualacion[3];

		lista.Elimina(2);
		PintaLista (lista, "Despues de ELimina(2)");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;

		lista.Elimina(6);
		PintaLista (lista, "Despues de ELimina(6)");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;
		

		lista.Borra(2);
		PintaLista (lista, "Despues de Borra(2)");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;
		

		lista.Aniade(3);
		PintaLista (lista, "Despues de Aniade(3)");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl << endl;

		lista.PonValor(1, 1);
		lista.PonValor(4, 2);
		PintaLista (lista, "Despues de cambiar dos elementos");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;

		cout << "Borrando " << lista.Tamanio() << " nodos..." << endl;

		int num_nodos = lista.Tamanio();
		for (int i=1; i<=num_nodos; i++) {
			cout << "Borrando nodo con " << lista.ObtenValor(1) << endl; 
			lista.Borra (1);
			PintaLista (lista, "Borrado nodo 1");
			cout << "Quedan " << lista.Tamanio() << " nodos..." << endl;
			cout << endl;
		}

		if (lista.EstaVacia())
			cout << "La lista esta vacia\n";
		else 
			cout << "La lista NO esta vacia\n";
		PintaLista (lista, "");
		cout << endl;


		Lista vacia;
		PintaLista (vacia, "Despues de crear lista vacía");
		cout << "Tamanio = " << vacia.Tamanio() << endl;
		cout << "Lista: ";
		if (vacia.EstaVacia())
			cout << "La lista esta vacia\n";
		else 
			cout << "La lista NO esta vacia\n";

		cout << endl;

		Lista lista_de_6_nodos (6);
		lista_de_6_nodos.Inicializar (9);

		PintaLista (lista_de_6_nodos, "lista_de_6_nodos inicializada a 9");
		cout << "Tamanio = " << lista_de_6_nodos.Tamanio() << endl;
		cout << "Tercer elemento = " << lista_de_6_nodos.ObtenValor(3) << endl;

		if (lista_de_6_nodos.EstaVacia())
			cout << "La lista esta vacia\n";
		else 
			cout << "La lista NO esta vacia\n";

		cout << endl;


		// Prueba de copia
		
		Lista copia (lista_de_6_nodos);
		PintaLista (copia, "copia de lista_de_6_nodos");
		
		return (0);
	}

	/***********************************************************************/
	/***********************************************************************/
