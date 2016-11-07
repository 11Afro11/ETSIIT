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
// Declaración de la clase clase Conjunto.
// (Incluye constructores, destructor, operador de asignación y métodos 
// simples de consulta). Apartados a-h del ejercicio.
//
// Fichero: Conjunto_Asignacion-Acceso.h
//
/***************************************************************************/

#ifndef CONJUNTO
#define CONJUNTO

#include <iostream>
#include <string>
using namespace std;

/***************************************************************************/
// Definición del tipo TipoBase y el valor NULO asociado
typedef int TipoBase;
#define NULO 0

// Un conjunto se representará mediante una lista ordenada.  
// Declaramos el tipo "Nodo" y el tipo "Conjunto".
struct Nodo 
{
	TipoBase  info; // Valor guardado en el nodo
	Nodo	* sig;	// Puntero al siguiente
};

/***************************************************************************/

/////////////////////////////////////////////////////////////////////////////

class Conjunto 
{
	private:
		
		Nodo * primero; // Puntero al primer nodo 
		int	   tamanio;	// Num. de nodos

	public:
		/*******************************************************************/
		// Constructores/destructor

		// Constructor sin argumentos (conjunto vacio)
		Conjunto (void);    

		// Constructor con un único elemento 
		Conjunto (TipoBase valor);
		
		// Constructor de copia 
		Conjunto (const Conjunto & otro);	

		// Destructor
		~Conjunto(void);

		/*******************************************************************/
		// Metodos de consulta sobre el estado del conjunto

		// Consulta si el conjunto esta vacio
		bool EstaVacio(void) const;	

		// Devuelve el numero de elementos
		int  Tamanio(void) const;	

		/*******************************************************************/
		// Consulta de pertenencia 
		bool Contiene (const TipoBase valor) const;	

		/*******************************************************************/
		// Metodo de acceso individual a elementos para lectura
		// PRE: 1 <= posicion <= Tamanio() 
		TipoBase & operator [] (const int posicion) const;  

		/*******************************************************************/
		// Operador de asignación 
		Conjunto & operator = (const Conjunto & otro);

		/*******************************************************************/
		// Operador suma otro conjunto 

		Conjunto operator + (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador suma un dato

		Conjunto operator + (const TipoBase & otra)const;

		/*******************************************************************/
		// Operador resta un conjunto 

		Conjunto operator - (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador resta un dato 

		Conjunto operator - (const TipoBase & otra)const;

		/*******************************************************************/
		// Operador +=

		Conjunto& operator += (const Conjunto & otra);

		/*******************************************************************/
		// Operador += dato 

		Conjunto& operator += (const TipoBase & otra);

		/*******************************************************************/
		// Operador -=

		Conjunto& operator -= (const Conjunto & otra);

		/*******************************************************************/
		// Operador -= dato 

		Conjunto& operator -= (const TipoBase & otra);

		/*******************************************************************/
		// Operador == 

		bool operator == (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador dostinto

		bool operator != (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador menor 

		bool operator < (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador mayor 

		bool operator > (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador menor o igual 

		bool operator <= (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador mayor o igual 

		bool operator >= (const Conjunto & otra)const;

		/*******************************************************************/
		// Operador union 

		Conjunto operator * (const Conjunto & otro)const;

		/*******************************************************************/
		// Operador union con dato 

		Conjunto operator * (const TipoBase & otro)const;

		/*******************************************************************/
		// Métodos para hacer crecer/decrecer el conjunto

		// Añadir un elemento al conjunto
		void Aniade (const TipoBase valor);
		
		// Borra el primer nodo que contiene el valor "valor"
		void Elimina (TipoBase valor);

		int Busca(TipoBase valor) const;

	private:
		/*******************************************************************/
		// Petición / liberación de memoria / Copiar datos
		void ReservarMemoria (int tam);
		void LiberarMemoria (void); 
		void CopiarDatos (const Conjunto & otro);

		// Insertar ordenadamente un elemento al conjunto
		void InsertaOrdenadamente (const TipoBase valor);

		/*******************************************************************/
		// Funcion friend de suma

		friend Conjunto operator + (const TipoBase valor, const Conjunto & con);

		/*******************************************************************/
		// Funcion friend de union

		friend Conjunto operator * (const TipoBase valor, const Conjunto & con);
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Muestra un conjunto en cout
void PintaConjunto (const Conjunto & cto, string s);
		
/***************************************************************************/		
// Devuelve un conjunto vacío
Conjunto ConjuntoVacio (void);

/***************************************************************************/
// Asociación a un literal del conjunto vacío
#define VACIO (ConjuntoVacio ())

/***************************************************************************/

#endif
