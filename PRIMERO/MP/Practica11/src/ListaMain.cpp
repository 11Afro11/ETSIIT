/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 4
//
// Demostración de la funcionalidad de la clase Lista.
// (Incluye constructor de copia, operador de asignación y sobrecarga de []).
//
// Fichero: Demo-Lista_Asignacion-Acceso.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	
	#include "Lista.h"
	
	using namespace std; 

	/***********************************************************************/
	/***********************************************************************/

	int main (void)
	{

		Lista lista(5);

		PintaLista (lista, "Despues de crear la lista con tamaño 5");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << "Tercer elemento = " << lista[3] << endl;
		cout << endl;

		lista.Inicializar (0);
		PintaLista (lista, "Despues de lista.Inicializar(0)");
		cout << endl;

		lista.Inserta(7,2);
		PintaLista (lista, "Despues de lista.Inserta(7,2)");
		cout << "Tamanio = " << lista.Tamanio() << endl;	
		cout << endl;

		lista.Inserta(9,lista.Tamanio()+1);
		PintaLista (lista, "Despues de lista.Inserta(9, lista.Tamanio()+1)");
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
			     << " = " << setw (3) << lista(pos)<< endl;
		cout << endl;


		cout << "Buscando el 7 ..." << endl;
		
		int pos_7 = lista.Busca (7);
		
		if (pos_7 != -1) 
			cout << "Encontrado en la posicion " << pos_7;
		else 
			cout << "No se encontró.";
		cout << endl; 



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

		lista[1] = 1;
		lista(4) = 2;
		
		PintaLista (lista, "Despues de cambiar dos elementos");
		cout << "Tamanio = " << lista.Tamanio() << endl;
		cout << endl;

		cout << "Borrando " << lista.Tamanio() << " nodos..." << endl;

		int num_nodos = lista.Tamanio();
		for (int i=1; i<=num_nodos; i++) {
			cout << "Borrando nodo con " << lista[1] << endl; 
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
		PintaLista (vacia, "Despues de crear lista vacia");
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
		cout << "Tercer elemento = " << lista_de_6_nodos[3] << endl;

		if (lista_de_6_nodos.EstaVacia())
			cout << "La lista esta vacia\n";
		else 
			cout << "La lista NO esta vacia\n";

		cout << endl;


		// Prueba de copia
		
		Lista copia_lista_de_6_nodos (lista_de_6_nodos);
		PintaLista (copia_lista_de_6_nodos, "copia de lista_de_6_nodos");
		
		
		for (int pos=1; pos <= copia_lista_de_6_nodos.Tamanio(); pos++)
			// Poner ceros en las posiciones pares
			if (pos%2==0) copia_lista_de_6_nodos[pos] = 0;
			
		PintaLista (copia_lista_de_6_nodos, "Con posiciones pares a 0");	
		
		
		// Operador de asignación
		
		lista = copia_lista_de_6_nodos;
		PintaLista (lista, "lista despues de lista = copia_lista_de_6_nodos");
		
		lista = 5;
		PintaLista (lista, "lista despues de lista = 5");

/*******************************************************************************/

		cout << "Vamos a Sumar Listas:"<<endl;

		Lista suma;

		suma = lista + copia_lista_de_6_nodos;

		PintaLista (suma, "lista + copia_lista_de_6_nodos");

		cout << "Vamos a Sumar un dato:"<<endl;

		Lista suma_num;

		suma_num = lista + 3;

		PintaLista (suma_num, "lista + 3");

		cout << "Operador +=:"<<endl;

		lista += suma;

		PintaLista (lista, "lista +=suma");

		cout << "operado +=:"<<endl;

		lista += 3;

		PintaLista (lista, "lista += 3");

		cout << "Vamos a Restar Listas:"<<endl;

		Lista resta;

		resta = lista - copia_lista_de_6_nodos;

		PintaLista (resta, "lista - copia_lista_de_6_nodos");

		cout << "Vamos a Restar un dato:"<<endl;

		Lista resta_num;

		resta_num = lista - 3;

		PintaLista (resta_num, "lista - 3");

		cout << "Operador -=:"<<endl;

		lista -= resta;

		PintaLista (lista, "lista -=resta");

		cout << "operado -=:"<<endl;

		lista -= 3;

		PintaLista (lista, "lista -= 3");

		if(lista == suma){
			cout <<"lista igual a suma"<<endl;
		}

		if(lista != suma){
			cout <<"lista distinto a suma"<<endl;
		}

		if(lista < resta){
			cout <<"lista menor que resta"<<endl;
		}

		if(lista > resta){
			cout <<"lista mayor que resta"<<endl;
		}

		if(lista <= suma){
			cout <<"lista menor o igual que suma"<<endl;
		}

		if(lista >= suma){
			cout <<"lista mayor o igual que suma"<<endl;
		}


		
			
		
		return (0);
	}

	/***********************************************************************/
	/***********************************************************************/
