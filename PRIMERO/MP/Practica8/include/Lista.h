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
// EJERCICIO 3 -Clase Lista
//
/*	

 Implementar la clase Lista para trabajar con listas (de tamaño arbitrario, y no definido a
priori, cuyos nodos residen en el heap) de datos de tipo TipoBase.
Proponer una representación para la clase (basada en el almacenamiento de los nodos en
memoria dinámica) e implementar los siguientes métodos:


*/
/*********************************************************************/


#ifndef _LISTA_
#define _LISTA_

//definimos el dato de tipo TipoBase
typedef int TipoBase;

//definimos la estructura Nodo

struct Nodo{

	TipoBase data;
	Nodo *sig;
};

//declaramos un puntero a datsde tupo Nodo
typedef Nodo * Puntero;

class Lista
{
private:

	//Atributos del ambito privado
	Lista lista;
	int total;

/***************************************************************************//*

Metodos privados

*//***************************************************************************/

	void Copia(const Lista & otra_lista);

	void ReservaMemoria (int tam);

	void LiberaMemoria();

public:

/***************************************************************************//*

Constructores

*//***************************************************************************/

	Lista();

	Lista(int tam);

	Lista(int tam, TipoBase valor);

	Lista(const Lista &otra_lista);

/***************************************************************************//*

Destructor

*//***************************************************************************/

	~Lista();

/***************************************************************************//*

Metodo que inicializa los elementos de una lista

*//***************************************************************************/

	void Inicializa(TipoBase value);

/***************************************************************************//*

Metodo que nos informa de si una lista esta o no vacia

*//***************************************************************************/

	bool Vacia()const;

/***************************************************************************//*

Metodo que inserta un elemento en una fila

*//***************************************************************************/

	void Inserta(TipoBase valor, int posicion);

/***************************************************************************//*

Metodo que busca una posicion CONST

*//***************************************************************************/

	int BuscaPosicion(TipoBase valor)const;

/***************************************************************************//*

Metodo que busca una posicion NO CONST

*//***************************************************************************/

	int BuscaPosicion(TipoBase valor);

/***************************************************************************//*

Metodo que borra una posicion

*//***************************************************************************/

	void Borra(int posicion);

/***************************************************************************//*

Metodo que aniade un elemento

*//***************************************************************************/

	void Aniade(TipoBase dato);

/***************************************************************************//*

Metodo que elimina un valor

*//***************************************************************************/

	void Eliminar(TipoBase dato);

/***************************************************************************//*

Metodo que devuelve un elemento de la lista

*//***************************************************************************/

	TipoBase ObtenerValor(int posicion)const;

/***************************************************************************//*

Metodo que asigna un valor a un aposicion de la lista

*//***************************************************************************/

	void PonerValor(int posicion, TipoBase dato);

/***************************************************************************//*

Metodo que devuelve al tamanio de la lista

*//***************************************************************************/

	int Tamanio()const;

	Lista Lista::operator=(const Lista & otra_lista);

	Lista Lista::operator=(const TipoBase value);

	Lista Lista::operator[](const int &pos);

};

/***************************************************************************//*

Funcion que pinta una lista

*//***************************************************************************/

	void PintaLista(const Lista &una_lista, char* etiqueta = "wiiiiiii");

#endif