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
// Demostración de la funcionalidad de la clase conjunto.
// (Incluye constructor de copia).
//
// Fichero: Demo-conjunto_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	
	#include "Conjunto.h"
	
	using namespace std; 

	/***********************************************************************/
	/***********************************************************************/

	int main (void)
	{

		Conjunto conjunto(5);

		PintaConjunto (conjunto, "Despues de crear la conjunto con tamaño 5");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << "Tercer elemento = " << conjunto.ObtenValor(3) << endl;
		cout << endl;

		conjunto.Inicializar (0);
		PintaConjunto (conjunto, "Despues de conjunto.Inicializar(0)");
		cout << endl;

		conjunto.Inserta(7,2);
		PintaConjunto (conjunto, "Despues de conjunto.Inserta(7,2)");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;	
		cout << endl;

		conjunto.Inserta(9,conjunto.Tamanio()+1);
		PintaConjunto (conjunto, "Despues de conjunto.Inserta(9, conjunto.Tamanio()+1");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl;
		
		conjunto.Inserta(6,3);
		PintaConjunto (conjunto, "Despues de conjunto.Inserta(6,3)");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl;
		
		

		PintaConjunto (conjunto, "Mostrando informacion");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;

		for (int pos=1; pos<=conjunto.Tamanio(); pos++)
			cout << "Elemento " << setw(2) << pos 
			     << " = " << setw (3) << conjunto.ObtenValor(pos) << endl;
		cout << endl;


		cout << "Buscando el 7 ..." << endl;
		
		int pos_7 = conjunto.Busca (7);
		
		if (pos_7 != -1) 
			cout << "Encontrado en la posicion " << pos_7;
		else 
			cout << "No se encontró.";
		cout << endl; 



		conjunto.Elimina(2);
		PintaConjunto (conjunto, "Despues de ELimina(2)");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl;

		conjunto.Elimina(6);
		PintaConjunto (conjunto, "Despues de ELimina(6)");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl;
		

		conjunto.Borra(2);
		PintaConjunto (conjunto, "Despues de Borra(2)");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl;
		

		conjunto.Aniade(3);
		PintaConjunto (conjunto, "Despues de Aniade(3)");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl << endl;

		conjunto.PonValor(1, 1);
		conjunto.PonValor(4, 2);
		PintaConjunto (conjunto, "Despues de cambiar dos elementos");
		cout << "Tamanio = " << conjunto.Tamanio() << endl;
		cout << endl;

		cout << "Borrando " << conjunto.Tamanio() << " nodos..." << endl;

		int num_nodos = conjunto.Tamanio();
		for (int i=1; i<=num_nodos; i++) {
			cout << "Borrando nodo con " << conjunto.ObtenValor(1) << endl; 
			conjunto.Borra (1);
			PintaConjunto (conjunto, "Borrado nodo 1");
			cout << "Quedan " << conjunto.Tamanio() << " nodos..." << endl;
			cout << endl;
		}

		if (conjunto.EstaVacia())
			cout << "La conjunto esta vacia\n";
		else 
			cout << "La conjunto NO esta vacia\n";
		PintaConjunto (conjunto, "");
		cout << endl;


		Conjunto vacia;
		PintaConjunto (vacia, "Despues de crear conjunto vacía");
		cout << "Tamanio = " << vacia.Tamanio() << endl;
		cout << "conjunto: ";
		if (vacia.EstaVacia())
			cout << "La conjunto esta vacia\n";
		else 
			cout << "La conjunto NO esta vacia\n";

		cout << endl;

		Conjunto conjunto_de_6_nodos (6);
		conjunto_de_6_nodos.Inicializar (9);

		PintaConjunto (conjunto_de_6_nodos, "conjunto_de_6_nodos inicializada a 9");
		cout << "Tamanio = " << conjunto_de_6_nodos.Tamanio() << endl;
		cout << "Tercer elemento = " << conjunto_de_6_nodos.ObtenValor(3) << endl;

		if (conjunto_de_6_nodos.EstaVacia())
			cout << "La conjunto esta vacia\n";
		else 
			cout << "La conjunto NO esta vacia\n";

		cout << endl;


		// Prueba de copia
		
		Conjunto copia (conjunto_de_6_nodos);
		PintaConjunto (copia, "copia de conjunto_de_6_nodos");
		
		return (0);
	}

	/***********************************************************************/
	/***********************************************************************/
