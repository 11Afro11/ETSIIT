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
// Implementación de la clase Lista (Iincluye constructor de copia).
//
// Fichero: Lista_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>

	#include "Lista_ConstructorCopia.h"

	using namespace std; 

	/***********************************************************************/
	// Constructor sin argumentos: crea una lista vacia.
	Lista :: Lista (void)  : primero(0), tamanio(0)
	{ }

	/***********************************************************************/
	// Constructor con argumentos: crea una lista con "tam" nodos
	// PRE: tam > 0
	Lista :: Lista (int tam) : tamanio(tam) 
	{
		ReservarMemoria (tamanio);
	}
		
	/***********************************************************************/		
	// Constructor de copia
	Lista :: Lista (const Lista & otro)
	{	
		// Reservar memoria para los nodos de la lista
		ReservarMemoria (otro.tamanio);

		// Copiar campos privados y los valores de la lista
		CopiarDatos (otro);
	}		
		
	/***********************************************************************/
    // Destructor
    Lista :: ~Lista (void)
    {
        LiberarMemoria ();
    }

	/*******************************************************************/
	// Inicializa la lista al valor dado
	void  Lista :: Inicializar (TipoBase valor)
	{
		TipoNodo * p = primero; // Apuntar al primero.

		for(int i = 0; i < tamanio; i++) {
			p->info = valor; // Inicializar nodo.
			p = p->sig;		 // Adelantar "p".
		}						
	}
	
	/***********************************************************************/
    // Consulta si la lista esta vacia
	bool Lista :: EstaVacia(void) const
	{
		return (tamanio == 0);
	}		
	
	/***********************************************************************/
	// Devuelve el número de nodos de la lista
	int Lista :: Tamanio(void)	const
	{
		return tamanio;
	}

	/*******************************************************************/
	// Busca un alumno con el valor especificado. Devuelve la posición  
	// del primer nodo coincidente, o -1 si no se encuentra.
	//
	// NO MODIFICA EL NÚMERO DE NODOS
    //	
	/*******************************************************************/
	int Lista :: Busca (TipoBase valor) const
	{
        TipoNodo * p = primero;

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
	
	/*******************************************************************/
    // Método de acceso para leer en una posición dada: 
	// 		Devuelve el contenido de un nodo (pos)
	//
	// PRE: 1 <= pos <= tamanio    
	// El criterio seguido para especificar una posicion será: 
	// 1 -> primero, 2 -> segundo,...
	//
	// NO MODIFICA EL NÚMERO DE NODOS
    //	
	/*******************************************************************/		
	TipoBase Lista :: ObtenValor (int pos) const
	{
		TipoNodo * p = primero;
		for (int i = 1; i < pos; i++) 
			p = p->sig;
		
		// "p" apunta al nodo de la posición "pos"

		return (p->info);
	}	
	
	/*******************************************************************/
    // Método de acceso para escribir en una posición dada: 
	// 		Devuelve el contenido de un nodo (pos)
	//
	// PRE: 1 <= pos <= tamanio    
	// El criterio seguido para especificar una posicion será: 
	// 1 -> primero, 2 -> segundo,...
	//
	// NO MODIFICA EL NÚMERO DE NODOS
    //	
	/*******************************************************************/
	void  Lista :: PonValor (TipoBase valor, int pos) 
	{
		TipoNodo * p = primero;
		for (int i = 1; i < pos; i++) 
			p = p->sig;

		// "p" apunta al nodo de la posición "pos"

		p->info = valor;
	}

	/*******************************************************************/
    // Métodos que modifican el número de nodos 

	/*******************************************************************/
	// Aniade (al final) un nuevo elemento
	void  Lista :: Aniade (TipoBase valor)
	{
		// Crear un nuevo (último) nodo y rellenar sus campos
		TipoNodo * nuevo = new TipoNodo;
		nuevo->info = valor;
		nuevo->sig = 0;
		
		// Buscar el último nodo
		TipoNodo * p = primero;
		
		for(int i=1; i<tamanio; i++)
			p = p->sig;

		// "p" apunta al último nodo

		if (p!=0) 	// La lista no estaba vacía
			p->sig = nuevo;
		else	 	// La lista estaba vacía
			primero = nuevo; 

		tamanio++;
	}

	/*******************************************************************/
    // Borra el primer nodo que contiene el valor "valor"
    void Lista :: Elimina (TipoBase valor)
    {
		int pos = Busca (valor);
	
 		// Si pos > 0 se encontró el alumno buscado: eliminarlo
		if (pos > 0) Borra (pos);
    }
        
	/*******************************************************************/
	// Inserta un nuevo elemento en la posición "pos_insertar"
	//
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
	// 		 ejecución del método Aniade()
	void  Lista :: Inserta (TipoBase val, int pos_insertar)
	{
		TipoNodo * ant = primero;
		TipoNodo * resto = primero;

		// Crear el nodo que se va a insertar e iniciarlo
		TipoNodo * nuevo = new TipoNodo; 
		nuevo->info = val; 

		// Buscar el sitio que le corresponde 
		for (int i=1; i<pos_insertar; i++) { 
			ant = resto; 
			resto = resto->sig;
		}

		if (pos_insertar==1)   // El nuevo nodo sera el primero 
			primero = nuevo;
		else		  // Enlazar el nuevo con el anterior 
			ant->sig = nuevo;

		nuevo->sig = resto; // Enlazar el nuevo nodo con el resto

		tamanio++; // Actualizar tamanio
	}

	/*******************************************************************/
	// Borra el elemento de "pos_borrar" 
	//
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion será: 
	// 1 -> primero, 2 -> segundo,...	
	void  Lista :: Borra (int pos_borrar) 
	{
		TipoNodo * ant = primero;
		TipoNodo * pos = primero;

		// Colocar "ant" y "act" 
		for (int i=1; i<pos_borrar; i++) { 
			ant = pos; 
			pos = pos->sig;
		}

		// "pos" apunta al nodo que se va a borrar
		// "ant" apunta al nodo anterior

		if (pos_borrar==1)   // Saltar el primero 
			primero = primero->sig;
		else 
			ant->sig = pos->sig;
			// Enlazar el anterior con el siguiente 

		delete pos; // Borrar nodo
		
		tamanio--;  // Actualizar tamanio
	}
	
	/*******************************************************************/
	// Pide memoria para "num_elementos" nodos
	// PRE: num_elementos > 0
	void  Lista :: ReservarMemoria (int num_elementos)
	{
		primero = new TipoNodo;		// Crear primer nodo.

		TipoNodo * ultimo = primero; // Apuntar al último.
		TipoNodo * p;

		for (int i = 1; i < num_elementos; i++) {

			p = new TipoNodo;	// Crear un nodo.
			ultimo->sig = p;	// Enlazar el nuevo nodo. 
			ultimo = p;			// Pasa a ser el último.
		}						

		ultimo->sig = 0; // Finalizar la lista
	}

	/*******************************************************************/
    // Liberar memoria
    void  Lista :: LiberarMemoria (void)
	{

		if (primero !=0) {
			
			TipoNodo *p = primero; // Colocar "p" al principio

			while (primero->sig != 0) {

				primero = primero->sig;  // Nuevo "primero"
				delete p;     // Borrar el antiguo primero
				p = primero;  // Actualizar "p"
			}

			delete primero; // Borrar el único que queda
		}
	}

	/*******************************************************************/
    // Copiar datos desde otro objeto de la clase
    // PRE: Se ha reservado memoria para los datos
	void Lista :: CopiarDatos (const Lista & otro)
	{
        // Copia los campos privados

        tamanio = otro.tamanio; // Copia el núm. de nodos

        // Copia el contenido de los nodos

		TipoNodo * p_este = primero; 
		TipoNodo * p_otro = otro.primero; 

		for(int i = 0; i < tamanio; i++) {

			// Copiar valor
			p_este->info = p_otro->info; 

			// Adelantar punteros
			p_este = p_este->sig;		 
			p_otro = p_otro->sig;		 
		}	
	}

	Lista Lista::operator=(const Lista & otra_lista){
		if(&otra_lista != this){
			LiberarMemoria();
			ReservarMemoria(otra_lista.tamanio);
			CopiarDatos(otra_lista);
		}
		return *this;
	}

	Lista Lista::operator=(const TipoBase value){
		Inicializar(value);
		return *this;
	}

	Lista Lista::operator[](const int &pos){
		return Busca(pos);
	}

    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
	/***********************************************************************/
	// Muestra el contenido de una lista, precedido del mensaje "msg"
	void PintaLista (const Lista l, const char * msg)
	{
		cout << endl;
		cout << msg << endl;

		int tamanio = l.Tamanio();
	
		for(int pos=1; pos<=tamanio; pos++) 
			cout << l.ObtenValor (pos) << ((pos != tamanio)?" - ":"");
		cout << endl; 
	}
	
	/*******************************************************************/
	/*******************************************************************/
