/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 5
//
// Implementación de la clase clase Conjunto.
// (Incluye constructores, destructor, operador de asignación y métodos 
// simples de consulta). Apartados a-j del ejercicio.
//
// Fichero: Conjunto_Asignacion-Acceso.cpp
//
/***************************************************************************/

#include "Conjunto.h"

#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

/***************************************************************************/
// Constructor sin argumentos
// Crea un conjunto vacio
Conjunto :: Conjunto(void) : tamanio(0), primero(0)
{
}
	
/***************************************************************************/
// Constructor con un unico elemento
// Crea un conjunto con un único elemento, el dado
Conjunto :: Conjunto (TipoBase valor) : tamanio(0) 
{
	Aniade (valor);
}

/***************************************************************************/
// Constructor de copia
Conjunto :: Conjunto (const Conjunto & otro)
{
	// Reservar memoria para los valores del conjunto
	ReservarMemoria (otro.tamanio);

    // Copiar campos privados y los valores del conjunto
    CopiarDatos (otro);
}


/***************************************************************************/
// Destructor
Conjunto :: ~Conjunto(void) 
{
	LiberarMemoria();
}

/***************************************************************************/
// Consulta si el conjunto esta vacio
bool Conjunto :: EstaVacio(void) const
{
	return (tamanio == 0);
}

/***************************************************************************/
// Devuelve el numero de elementos
int Conjunto :: Tamanio(void) const
{
	return tamanio;
}

/***************************************************************************/
// Consulta de pertenencia 
bool Conjunto :: Contiene (const TipoBase valor) const
{
	bool sigo = true;
	bool encontrado = false;
	Nodo * p = primero;

	int cont = 1;

	while (sigo && (cont <= tamanio)) {

		if (p->info == valor) {		// Éxito: se encontró.
			sigo = false;
			encontrado = true;
		}
		else 
			if (p->info > valor) {	// Los elementos están ordenados: la
				sigo = false;		// búsqueda termina (fracaso) cuando 
				encontrado = false;	// el valor consultado es mayor que 
			}						// el buscado ("valor").
			else
				p = p->sig;

		cont++;
	}

	return (encontrado); 
}	

/***************************************************************************/
// Metodo de acceso individual a elementos para lectura
// PRE: 1 <= posicion <= Tamanio() 
TipoBase & Conjunto :: operator [] (const int posicion) const
{
	Nodo * p = primero;

	for (int i=1; i<posicion; i++) {
		p = p->sig;
	}
	return (p->info);
}

/***************************************************************************/
// Operador de asignacion
Conjunto & Conjunto :: operator = (const Conjunto & otro)
{
	if (this != &otro) // Importantisimo: evitar autoasignacion
	{
		// Libera la memoria ocupada
        LiberarMemoria();

		// Reservar memoria para los valores del conjunto
		ReservarMemoria (otro.tamanio);

		// Copiar campos privados y los valores del conjunto
		CopiarDatos (otro);
	}
	return (*this); // Objeto implicito: parte 
					// izquierda de la asignación
}

/***************************************************************************/
// Operadores aritmeticos
/***************************************************************************/
// Suma
Conjunto Conjunto :: operator + (const Conjunto & otra)const{
	Conjunto sum(*this);

	for(int i = 0; i < otra.tamanio; i++){
		if(Busca(otra[i] == -1))
			sum.Aniade(otra[i]);
	}

	return sum;
}

Conjunto Conjunto :: operator + (const TipoBase & otra)const{
	Conjunto sum(*this);

	if(Busca(otra == -1))
		sum.Aniade(otra);

	return sum;
}

/***************************************************************************/
// resta

Conjunto Conjunto :: operator - (const Conjunto & otra)const{
	Conjunto res(*this);

	for(int i = 0; i < otra.tamanio; i++){
		if(Busca(otra[i] != -1))
			res.Elimina(otra[i]);
	}

	return res;		
}

Conjunto Conjunto :: operator - (const TipoBase & otra)const{
	Conjunto res(*this);

	if(Busca(otra != -1))
		res.Elimina(otra);

	return res;		
}

/***************************************************************************/
// Mas igual

Conjunto& Conjunto :: operator += (const Conjunto & otra){
	*this = *this + otra;

	return *this;
}

Conjunto& Conjunto :: operator += (const TipoBase & otra){
	*this = *this + otra;

	return *this;
}

/***************************************************************************/
// Menos igual

Conjunto& Conjunto :: operator -= (const Conjunto & otra){
	*this = *this - otra;

	return *this;
}

Conjunto& Conjunto :: operator -= (const TipoBase & otra){
	*this = *this - otra;

	return *this;
}

/***************************************************************************/
// Operadores booleanos

/***************************************************************************/
// igual

bool Conjunto :: operator == (const Conjunto & otra)const{
	bool igual = tamanio == otra.tamanio;

	for(int i = 0; i < tamanio && igual; i++){
		igual = *this+i == otra[i];
	}

	return igual;
}

/***************************************************************************/
// Distinto

bool Conjunto :: operator != (const Conjunto & otra)const{
	bool distinto = !(*this == otra);

	return distinto;
}

/***************************************************************************/
// Menor

bool Conjunto :: operator < (const Conjunto & otra)const{
	bool menor = tamanio < otra.tamanio;

	if(tamanio == otra.tamanio || menor){
		for(int i = 0; i < tamanio && menor; i++){
			menor = *this+i < otra[i];
		}
	}
	return menor;
}

/***************************************************************************/
// Mayor

bool Conjunto :: operator > (const Conjunto & otra)const{
	bool mayor = tamanio > otra.tamanio;

	
	if(tamanio == otra.tamanio || mayor){
		for(int i = 0; i < tamanio && mayor; i++){
			mayor = *this+i > otra[i];
		}
	}
	return mayor;
}

/***************************************************************************/
// Menor igual

bool Conjunto :: operator <= (const Conjunto & otra)const{
	bool menor_igual = *this < otra || *this == otra;

	return menor_igual;
}

/***************************************************************************/
// Mayor igual

bool Conjunto :: operator >= (const Conjunto & otra)const{
	bool mayor_igual = *this > otra || *this == otra;

	return mayor_igual;
}

/***************************************************************************/
// Operadores de union

/***************************************************************************/
// Union con unconjunto

Conjunto Conjunto :: operator * (const Conjunto & otro)const{
	Conjunto inserta;

	for(int i = 0; i < otro.tamanio; i++){
		if(Busca(otro[i] != -1))
			inserta.Aniade(otro[i]);
	}

	return inserta;
}

/***************************************************************************/
// Union con un dato

Conjunto Conjunto :: operator * (const TipoBase & otro)const{
	Conjunto inserta;

	if(Busca(otro != -1))
		inserta.Aniade(otro);

	return inserta;
}

/***************************************************************************/
// Aniade un nuevo elemento
void Conjunto :: Aniade (TipoBase valor) 
{
	InsertaOrdenadamente (valor);
}


int Conjunto :: Busca (TipoBase valor) const
	{
        Nodo * p = primero;

        bool sigo = true;
        bool encontrado = false;
    
    	int pos = 0;
    	
        while ((p!=0) && sigo) {
        	
			pos++; // Actualizar posición

            if (p->info == valor) {
                sigo = false;
                encontrado = true;
            }
            else 
                p = p->sig;
		}
		
   		return (encontrado ? (pos) : -1); 
	}


/***************************************************************************/
// Elimina el primer (y único) nodo que contiene el valor "valor"
void Conjunto :: Elimina (TipoBase valor)
{
	// Buscar el primer nodo que contiene el valor "valor" 
	Nodo * p, *ant;
	ant = p = primero;

	bool sigo = true;
	bool encontrado = false;

	while ((p!=0) && sigo)

		if (p->info == valor) {
			sigo = false;
			encontrado = true;
		}
		else {
			ant = p;
			p = p->sig;
		}

	// Si se ha encontrado, Eliminarlo

	if (encontrado) { 
		
		if (p==primero)   // Saltar el primero 
			primero = primero->sig;
		else 
			ant->sig = p->sig;
			// Enlazar el anterior con el siguiente 

		delete p; // Eliminar nodo
	
		tamanio--;  // Actualizar tamanio
	}
}

/***************************************************************************/
// METODOS PRIVADOS
/***************************************************************************/

/***************************************************************************/
// Pide memoria para "tam" elementos
// PRE: tam > 0
void Conjunto :: ReservarMemoria (int tam) 
{
	primero = 0;

	if (tam > 0) {

		primero = new Nodo;
		primero->info = NULO;

		Nodo * ultimo = primero;
		Nodo * p;

		for(int i = 1; i < tam; i++) {
			p = new Nodo;
			ultimo->sig = p;
			ultimo = p; 
		}
		ultimo->sig = 0;
	}
} 

/***************************************************************************/
// Liberar memoria
void Conjunto :: LiberarMemoria(void) 
{
	if (primero) {

		Nodo * p = primero->sig;
		Nodo * tmp; 

		for(int i = 1; i < tamanio; i++) {
			tmp = p->sig;
			delete p;
			p = tmp;
		}

		delete primero;
		primero = 0;	// Importante
	}
}


/***************************************************************************/
// Copiar campos privados y los valores de la Conjunto
void Conjunto :: CopiarDatos (const Conjunto & otro)
{
    // Copia los campos privados
	tamanio = otro.tamanio; // Copia el núm. de nodos

    // Copia el contenido de los nodos

    Nodo * p_este = primero;
    Nodo * p_otro = otro.primero;

	for (int i = 0; i < tamanio; i++) {

		// Copiar valor
        p_este->info = p_otro->info;

        // Adelantar punteros
        p_este = p_este->sig;
        p_otro = p_otro->sig;
    }

}

/***************************************************************************/
// Inserta un nodo en la posición que le corresponde en una 
// Conjunto ordenada.
// Si "valor" ya está en la Conjunto no hace nada 
void Conjunto :: InsertaOrdenadamente (const TipoBase valor)
{
	if (tamanio == 0) 
	{ 
		primero = new Nodo;

		primero->info = valor; 
		primero->sig = 0;

		tamanio++;
	}

	else { // tamanio > 0

		// Buscar el primer nodo mayor o igual que "valor"
		// (si no lo hay, se recorre la Conjunto entera) 

		Nodo * p, *ant;
		ant = p = primero;

		bool sigo = true;
		bool encontrado_mayor = false;
		bool encontrado_igual = false;

		while ((p!=0) && sigo)

			if (p->info >= valor) { // Terminar 

				sigo = false;
				
				if (p->info > valor) 
					encontrado_mayor = true;
				else
					encontrado_igual = true;
			}

			else { // Seguir buscando

				ant = p;
				p = p->sig;
			}

		// Insertaré (inicio/otra posición) si no 
		// he encontrado el valor en la Conjunto 

		if (!encontrado_igual) {

			Nodo * nuevo = new Nodo;
			nuevo->info = valor; 

			if (p==primero) { // Nuevo primer nodo
				nuevo->sig = primero;
				primero = nuevo;
			}
			else {	// Nodo intermedio 0 final
				ant->sig = nuevo;
				nuevo->sig = p; 
			}
				
			tamanio++;

		} // if (!encontrado_igual)
	
	} // else de if (tamanio == 0)

}


/***************************************************************************/
// FUNCIONES ADICIONALES
/***************************************************************************/

/***************************************************************************/
// Muestra un conjunto en cout
void PintaConjunto (const Conjunto & cto, string s)
{
	cout << s << endl;
	
	if (cto.EstaVacio()) 
	
		cout << "Conjunto vacio"; 
		
	else { // El conjunto tiene datos
		
		int tam = cto.Tamanio();
		
		cout << "Conjunto NO vacio --> "; 
		cout <<  tam << " elementos.\n";
		cout << "\t";

		for (int i=1; i<=tam; i++) 
			cout << cto[i] << ((i!=tam)?" - ":"");
		cout << endl; 
	}
	cout << endl;
}

/***************************************************************************/

Conjunto ConjuntoVacio (void)
{
	Conjunto vacio;
	return (vacio);
}

/***************************************************************************/
/***************************************************************************/
// Funcion friend para sumar
Conjunto operator + (const TipoBase valor, const Conjunto & con){
	Conjunto sum(con);

	sum = sum + valor;

	return sum;
}

/****************************************************************************/
/***************************************************************************/
// Funcion friend para la union
Conjunto operator * (const TipoBase valor, const Conjunto & con){
	Conjunto inserta;

	if(con.Busca(valor != -1))
		inserta.Aniade(valor);

	return inserta;
}

/***************************************************************************/
/***************************************************************************/
