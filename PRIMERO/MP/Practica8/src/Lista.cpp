/*********************************************************************/
// METODOLOGÍA DE LA PROGRANACIÓN
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 8
//
//EJERCICIO 3- Clase Lista
//
/*	

 Implementar la clase Lista para trabajar con listas (de tamaño arbitrario, y no definido a
priori, cuyos nodos residen en el heap) de datos de tipo TipoBase.
Proponer una representación para la clase (basada en el almacenamiento de los nodos en
memoria dinámica) e implementar los siguientes métodos:


*/
/*********************************************************************/


#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;
/*

class ListaDinamica
{
private:
	Lista lista;
	int total;
	*/

/***************************************************************************//*

Metodo Privado que reserva memoria para tantos nodos como sean pasados por parametro

*//***************************************************************************/

	void ListaDinamica::ReservaMemoria(int tam){
		lista = NULL;

		if(tam > 0){
			lista = new Nodo;
			Lista final = lista;
			Lista aux;

			for(int i = 1; i < tam; i++){
				aux = new Nodo;
				final->sig = aux;
				final = aux;
			}
			final->sig = NULL;
		}
	}

/***************************************************************************//*

Metodo privado que Libera la memoria que ha dejado de ser util

*//***************************************************************************/

	void ListaDinamica::LiberaMemoria(){
		if(lista){
			Lista aux = lista;

			while (lista->sig){
				lista = lista->sig;
				delete aux;
				aux = lista;
			}
			delete lista;
		}
	}

/***************************************************************************//*

Metodo privado que copia los valores de una lista pasada como parametro a 
la lista del ambito privado del vector

*//***************************************************************************/

	void ListaDinamica::Copia(const ListaDinamica & otra_lista){
		total = otra_lista.total;

		Lista aux_origen = otra_lista.lista;
		Lista aux_destino = lista;

		for(int i = 1; i < total; i++){
			aux_destino->data = aux_origen->data;

			aux_destino = aux_destino->sig;
			aux_origen = aux_origen->sig;
		}
	}


//public:	

/***************************************************************************//*

Constructor por defecto

*//***************************************************************************/

	ListaDinamica::ListaDinamica(){
		total = 0;
		lista = 0;
	}

/***************************************************************************//*

Constructor con un parametro que crea tantos nodos como los pasados por parametro

*//***************************************************************************/

	ListaDinamica::ListaDinamica(int tam){
		total = tam;
		ReservaMemoria(total);
	}

/***************************************************************************//*

Constructor que cera tantos nodos como los pasados por parametro y los inicializa 
al segundo parametro

*//***************************************************************************/

	ListaDinamica::ListaDinamica(int tam, TipoBase valor){
		total = tam;
		ReservaMemoria(total);
		Inicializa(valor);
	}

/***************************************************************************//*

Constructor de copia

*//***************************************************************************/

	ListaDinamica::ListaDinamica(const ListaDinamica &otra_lista){
		ReservaMemoria(otra_lista.total);

		Copia(otra_lista);
	}

/***************************************************************************//*

Destructor

*//***************************************************************************/

	ListaDinamica::~ListaDinamica(){
		LiberaMemoria();
	}

/***************************************************************************//*

Metodo publico que inicia todos los elementos de la lista al mismo valor

*//***************************************************************************/

	void ListaDinamica::Inicializa(TipoBase value){
		Lista aux;
		aux = lista;
		for(int i = 0; i < total; i++){
			aux->data = value;
			aux = aux->sig;
		}
	}

/***************************************************************************//*

Metodo que informa si una listaesta vacia

*//***************************************************************************/

	bool ListaDinamica::Vacia()const{
		bool vacia;
		vacia = (lista == 0);
		return vacia;
	}

/***************************************************************************//*

Metodo que insterta un elemento en una lista

*//***************************************************************************/

	void ListaDinamica::Inserta(TipoBase valor, int posicion){

		if(posicion <= total){

			Lista anterior = lista;
			Lista aux = lista;

			Lista nuevo = new Nodo;
			nuevo->data = valor;

			for(int i = 1; i < posicion; i++){
				anterior = aux;
				aux = aux->sig;
			}

			if(posicion == 1){
				lista = nuevo;
			}
			else{
				anterior->sig = nuevo;
			}

			nuevo->sig = aux;

			total++;
		}
	}

/***************************************************************************//*

Metodo que busca la posicion en la que se encuentra un valor.
Si no se encuentra dara como estado de salida -1

CONST

*//***************************************************************************/

	int ListaDinamica::BuscaPosicion(TipoBase valor)const{
		Lista aux;
		aux = lista;
		bool encontrado = false;
		int salida =0;
		while(salida < total && !encontrado){
			salida++;
			if(aux->data == valor){
				encontrado = true;
			}
			aux = aux->sig;

		}
		if(!encontrado){
			salida = -1;
		}

		return salida;
	}

/***************************************************************************//*

Metodo que busca la posicion en la que se encuentra un valor.
Si no se encuentra dara como estado de salida -1

NO CONST

*//***************************************************************************/

	int ListaDinamica::BuscaPosicion(TipoBase valor){
		Lista aux;
		aux = lista;
		bool encontrado = false;
		int salida =0;
		while(salida < total && !encontrado){
			salida++;
			if(aux->data == valor){
				encontrado = true;
			}
			aux = aux->sig;

		}
		if(!encontrado){
			salida = -1;
		}

		return salida;
	}

/***************************************************************************//*

Metodo que borra una posicion de una lista

*//***************************************************************************/

	void ListaDinamica::Borra(int posicion){
		if(posicion <= total){
			if(posicion != 1){
				Lista aux;
				aux = lista;
				Lista anterior;
				anterior = lista;
				for(int i = 1; i < posicion; i++){
					anterior = aux;
					aux = aux->sig;
				}
				anterior = aux;
				aux = aux->sig;
				delete aux;
				anterior->sig = aux->sig;
				
			}
			else{
				delete lista;
				if(total > 1){
					lista = lista->sig;
				}
				else{
					lista = NULL;
				}
			}
			total --;
		}
	}

/***************************************************************************//*

Metodo publico que aniadeun elemento al final de la lista

*//***************************************************************************/

	void ListaDinamica::Aniade(TipoBase dato){
		
		Lista nuevo = new Nodo;
		nuevo->data = dato;
		nuevo->sig = NULL;

		Lista aux = lista;

		for(int i = 1; i < total; i++){
			aux = aux->sig;
		}

		if(aux != NULL){
			aux->sig = nuevo;
		}

		else{
			lista = nuevo;
		}
		total++;
	}

/***************************************************************************//*

Metodo que Busca unelemento en la lista y lo elimina si se encuentra

*//***************************************************************************/

	void ListaDinamica::Eliminar(TipoBase dato){
		
		Lista aux = lista;
		Lista anterior = lista;

		int encontrado = BuscaPosicion(dato);		

		if(encontrado > 0){

			for(int i = 1; i < encontrado; i++){
				aux = aux->sig;
			}

			if(aux = lista){
				lista = lista->sig;
			}
			else{
				anterior->sig = aux->sig;
			}

			delete[]aux;

			total--;
		}

	}

/***************************************************************************//*

Metodo que devuelve el valor que se encuentra en una posicion de la lista

*//***************************************************************************/

	TipoBase ListaDinamica::ObtenerValor(int posicion)const{
		Lista aux;
		aux = lista;
		int pos = 1;
		while(pos < posicion && pos < total){
			aux = aux->sig;
			pos++;
		}	

		return aux->data;
	}

/***************************************************************************//*

Metodo que cambia el valor de un elemento de la lista

*//***************************************************************************/

	void ListaDinamica::PonerValor(int posicion, TipoBase dato){
		Lista aux;
		aux = lista;
		int pos = 1;
		while(pos < posicion){
			aux = aux->sig;
			pos++;
		}
		aux->data = dato;
	}

/***************************************************************************//*

Metodo que devuelve el tamanio de la lista

*//***************************************************************************/


	int ListaDinamica::Tamanio()const{
		return total;
	}

/***************************************************************************//*

Funcion que muestra la lista por pantalla

*//***************************************************************************/


	void PintaLista(const ListaDinamica &una_lista, char *etiqueta){

		
		cout << endl <<etiqueta<<endl;
		for(int i = 1; i < una_lista.Tamanio(); i++){
			cout << una_lista.ObtenerValor(i) << " -> ";
		}
		cout << "FIN" <<endl;
	}


//};