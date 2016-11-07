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
// SESION 6
//
/*	

 Ampliar el problema 6 de manera que una vez leídos los datos realice unos cálculos sobre los
datos almacenados en la lista. Se pide que se escriban tres funciones para calcular:
a) el número de celdas enlazadas.
b) la media de los datos almacenados.
c) la varianza de los datos almacenados.

*/
/*********************************************************************/
#include <iostream>
#include "lista.h"
#include <cmath>

using namespace std;

/*************************************************************************************************/
//Funcion Lee:
//Se encarga de leer y almacenaer los datos de la lista.
//esta funcion no recibe parametor y devuelve un puntero de tipo TipoLista
/*************************************************************************************************/

TipoLista * CreaEstructuraLineal (void){


	TipoLista *fin, *primero;

	double n;

	cout << "Introduzca valor (negativo para terminar): ";
	cin >> n;

	if(n >= 0){
		// Pedimos memoria para el primer nodo

		primero = new TipoLista;
		primero->info = n;

		 // Guardar "n" en el nuevo nodo

		primero->sig = 0;

		// Este nodo es, por ahora, el último
		// El ultimo tambien es el primero (solo hay uno)

		fin = primero;

		// Segunda lectura

		cout << "Introduzca valor (negativo para terminar): ";
		cin >> n;
		while (n >= 0) {
			// Pedimos memoria para el siguiente nodo, y enlazamos

			fin->sig = new TipoLista;
			fin = fin->sig; // Actualizar posicion del ultimo
			fin->info = n; // Guardar "n" en el nuevo nodo
			fin->sig = 0; // Este nodo es, por ahora, el último

			// Siguiente lectura

			cout << "Introduzca valor (negativo para terminar): ";
			cin >> n;

		} // while (n != 0)
	} // if (n != 0)

	return primero;

}

/*************************************************************************************************/
//Funcion Muestra:
//Funcion que muestra la lista por pantalla.
//Recibe como parametro un puntero al primer elemento de la lista
/*************************************************************************************************/

void MuestraEstructuraLineal (TipoLista * p)
{
	TipoLista *aux = p; // Colocar "aux" al principio
	
	while (aux != 0) {
		cout << (aux->info) << " "; // Mostrar "info"
		aux = aux->sig;
		// Adelantar "aux"
	}
	cout << endl;
}

/*************************************************************************************************/
//Funcion NumCeldas:
//Funcion que devuelve el numero de celdas anidadas
//Recibe como parametro un puntero al primer elemento de la lista
/*************************************************************************************************/

int NumCeldas(TipoLista *p){

	TipoLista *aux = p; // Colocar "aux" al principio
	int contador = 0;
	
	while (aux != 0) {
		contador++;
		aux = aux->sig;
		// Adelantar "aux"
	}
	return contador;

}

/*************************************************************************************************/
//Funcion Media:
//Funcion que calcula la media de los datos
//Recibe como parametro un puntero al primer elemento de la lista
/*************************************************************************************************/

int Media(TipoLista *p){

	TipoLista *aux = p; // Colocar "aux" al principio
	int sum = 0;
	
	while (aux != 0) {
		sum = sum + aux->info;
		aux = aux->sig;
		// Adelantar "aux"
	}
	return sum/NumCeldas(p);

}

/*************************************************************************************************/
//Funcion varianza:
//Funcion que calcula la Varianza de los datos
//Recibe como parametro un puntero al primer elemento de la lista
/*************************************************************************************************/

int Varianza(TipoLista *p){

	TipoLista *aux = p; // Colocar "aux" al principio
	int sum = 0;
	double N = Media(p);
	
	while (aux != 0) {

		sum = sum + pow(aux->info - N, 2);
		aux = aux->sig;
		// Adelantar "aux"
	}
	return sum/NumCeldas(p);

}

/*************************************************************************************************/
//Funcion EstaOrdenada:
//Funcion que comprueba si la lista esta ordenada
//Recibe como parametro un puntero al primer elemento de la lista
/*************************************************************************************************/

bool EstaOrdenada(TipoLista *p){
	
	bool es_ordenada = true;
	bool condicion;
	TipoLista *aux = p;
	TipoLista *recorre = aux;
	recorre = recorre->sig;

	while (recorre != 0 && es_ordenada) {

		if(aux->info < recorre->info){
			aux = aux->sig;
			recorre = recorre->sig;
		}
		else{
			es_ordenada = false;
		}
		
	}
	return es_ordenada;

}

/*************************************************************************************************/
//Funcion Ordena por seleccion:
//Funcion que ordena la lista usando el metodo de seleccion
//Recibe como parametro un puntero al primer elemento de la lista
/*************************************************************************************************/

void Ordena_por_Seleccion(TipoLista *&primero){
	
	if(!EstaOrdenada(primero)){

		TipoLista *aux = primero;
		TipoLista *recorre;
		double min;
		double valor_aux;

		while(aux != 0){
			min = aux->info;
			recorre = aux;
			while(recorre != 0){
				if(recorre->info <= min){
					min = recorre->info;
				}
				recorre = recorre->sig;
			}
			recorre = aux;
			while(recorre->info > min){
				recorre = recorre->sig;
			}
			valor_aux = recorre->info;
			recorre->info = aux->info;
			aux->info = valor_aux;

			aux = aux->sig;

		}
	}
}

/*************************************************************************************************/
//Funcion insertar elemento:
//Funcion que inserta un elemento dentro de una lista
//Recibe como parametro un puntero al primer elemento de la lista porreferencia y el valor a insertar
/*************************************************************************************************/

void InsertarElemento(TipoLista *&lista, double valor)
{
	TipoLista *aux=lista;
	TipoLista *recorre = aux;
	recorre = recorre->sig;
	int pos = 0;
	bool encontrado = false;

	while (recorre != 0 && !encontrado) {

		if(aux->info <= valor && recorre->info >= valor){
			encontrado = true;
		}
		else{
			aux = aux->sig;
			recorre = recorre->sig;
		}

		pos ++;
		
	}

    TipoLista *q, *t;
    int i;
    q = new TipoLista;
    q->info = valor;
 
    if(pos==1)
    {
        q->sig = lista;
        lista = q;
    }
    else
    {
        t = lista;
 
        for(i=1; t!=NULL && i<=pos; i++)
        {
            t = t->sig;
        }
        if(i==pos)
        {
            q->sig = t->sig;
            t->sig = q;
        }
    }
}

/*************************************************************************************************/
//Funcion elimina elemento:
//Funcion que elimina un valor de la lista
//Recibe como parametro un puntero al primer elemento de la lista y el valor a eliminar
/*************************************************************************************************/

void EliminarElemento(TipoLista *&lista, int valor)
{
    TipoLista *p, *ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->info==valor)
            {
                if(p==lista)
                    lista = lista->sig;
                else
                    ant->sig = p->sig;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sig;
        }
    }
    else
        cout<<" Lista vacia..!";
}

/*************************************************************************************************/
//Funcion enlaza:
//Funcion que uno dos lista de forma ordenada
//Recibe como parametro un puntero al primer elemento de la lista , ey el primer elen¡mento de 
// la lista 2 
/*************************************************************************************************/

TipoLista * Enlaza(TipoLista *&lista1, TipoLista *&lista2){

	if(lista1 != 0 && lista2 != 0){
	
		TipoLista *primero;
		TipoLista *aux;

		
		// Pedimos memoria para el primer nodo

		if(lista1->info <= lista2->info){
			primero = lista1;
			lista1 = lista1->sig;
		}
		else{
			primero = lista2;
			lista2 = lista2->sig;
		}

		// Este nodo es, por ahora, el último
		// El ultimo tambien es el primero (solo hay uno)

		aux = primero;

		// Segunda lectura

		while (lista1 != 0 && lista2 != 0) {
			// Pedimos memoria para el siguiente nodo, y enlazamos


			if(lista1->info <= lista2->info){
				aux->sig = lista1;
				lista1 = lista1->sig;
			}
			else{
				aux->sig = lista2;
				lista2 = lista2->sig;
			}
			aux = aux->sig;

		}

		//Comprobamos cual es la lista que ha terminado

		while(lista2 != 0){
			aux->sig = lista2;
			lista2 = lista2->sig;
			aux = aux->sig;
		}

		while(lista1 != 0){
			aux->sig = lista1;
			lista1 = lista1->sig;
			aux = aux->sig;
		}


		return primero;
	}
}


/*************************************************************************************************/
//Funcion pinta:
//funcion estetica, separa las salidas en la consola.
/*************************************************************************************************/

void pinta(){

	cout <<endl<<"#################################################################################"<<endl;
	cout <<"#################################################################################"<<endl;
}
