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
// Declaraci�n de la clase clase Lista.
// (Incluye constructor de copia, operador de asignaci�n y sobrecarga de []).
//
// Fichero: Lista_Asignacion-Acceso.h
//
/***************************************************************************/

	#ifndef LISTA_ASIGNACION_ACCESO 
	#define LISTA_ASIGNACION_ACCESO 
	
	typedef int TipoBase;
	
	/***********************************************************************/
	/***********************************************************************/
	struct TipoNodo 
	{
		TipoBase   info;  // Valor guardado en el nodo
		TipoNodo * sig;	  // Puntero al siguiente
	};
	/***********************************************************************/
	/***********************************************************************/
	
	class Lista 
	{

	private:
		
		TipoNodo * primero; // Puntero al primer nodo 
		int tamanio;		// N�mero de nodos

		// PRE: tamanio >= 0
		
	public:
		
		/*******************************************************************/
		// Constructor sin argumentos: crea una lista vacia.
		Lista (void);

		/*******************************************************************/
		// Constructor con argumentos: crea una lista con "tam" nodos
		// PRE: tam > 0
		Lista (int tam);

		/*******************************************************************/
		// Constructor de copia
		Lista (const Lista & otro);
		
		/*******************************************************************/
        // Destructor
        ~Lista (void);

		/*******************************************************************/
		// Inicializa la lista al valor dado
		void Inicializar (int valor=0);

		/*******************************************************************/
        // Consulta si la lista esta vacia
		bool EstaVacia (void) const;
		
		/*******************************************************************/
		// Devuelve el numero de elementos
		int  Tamanio (void) const;

		/*******************************************************************/
        // M�todos de acceso para escribir/leer en una posici�n dada: 
        // NO MODIFICAN EL N�MERO DE NODOS

		/*******************************************************************/
		// Busca un alumno con el valor especificado. Devuelve la posici�n  
		// del primer nodo coincidente, o -1 si no se encuentra.
		/*******************************************************************/
		int Busca (TipoBase valor) const;
	
		/*******************************************************************/
		// Metodo de acceso individual a elementos: operator [] y operator()
		// Metodo de escritura / lectura
		// PRE: 0 <= posicion <usados 		
		TipoBase & operator [] (const int posicion);  	
		TipoBase & operator [] (const int posicion) const;  
		
		TipoBase & operator () (const int posicion);
		TipoBase & operator () (const int posicion) const;  
					
		/*******************************************************************/
		// Operador de asignaci�n
		Lista & operator = (const Lista & otro);
		Lista & operator = (const TipoBase & valor);

		/*******************************************************************/
		// Operador suma

		Lista  operator + (const Lista & otra)const;

		Lista  operator + (const TipoBase & otra)const;

		/*******************************************************************/
		// Operador menos

		Lista  operator - (const Lista & otra)const;

		Lista  operator - (const TipoBase & otra)const;

		/*******************************************************************/
		// Operadores += y -=

		Lista&  operator += (const Lista & otra);

		Lista&  operator += (const TipoBase & otra);

		Lista&  operator -= (const Lista & otra);

		Lista&  operator -= (const TipoBase & otra);

		/*******************************************************************/
		// Operador igual

		bool  operator == (const Lista & otra)const;

		/*******************************************************************/
		// Operador distinto

		bool  operator != (const Lista & otra)const;

		/*******************************************************************/
		// Operadores menos mayor menor igual y mayor igual

		bool  operator < (const Lista & otra)const;

		bool  operator > (const Lista & otra)const;

		bool  operator <= (const Lista & otra)const;

		bool  operator >= (const Lista & otra)const;

		/*******************************************************************/
        // M�todos que modifican el tama�o de la lista 
      	// MODIFICAN EL N�MERO DE NODOS
  			
		/*******************************************************************/
		// Aniade (al final) un nuevo elemento
		void Aniade (int TipoBase);

        // Borra el primer nodo que contiene el valor "valor"
    	void Elimina (int TipoBase);
    
		/*******************************************************************/
		// Inserta un nuevo elemento en la posici�n "pos_insertar"
		// PRE: 1 <= pos_insertar <= tamanio+1
		// El criterio seguido para especificar una posicion ser� : 
		// 1 -> primero, 2 -> segundo,...
		// Nota: Si pos_insertar == tamanio+1, el resultado es id�ntico a la 
		// 		 ejecuci�n del m�todo Aniade()
		void Inserta (int TipoBase, int pos_insertar);

		/*******************************************************************/
		// Borra el elemento de la posici�n "pos_borrar" 
		// PRE: 1 <= pos_borrar <= tamanio
		// El criterio seguido para especificar una posicion ser� : 
		// 1 -> primero, 2 -> segundo,...
		void Borra (int pos_borrar);
		
	private:
		
		/*******************************************************************/
		// Petici�n / liberaci�n de memoria
		void ReservarMemoria (int num_elementos);
		void LiberarMemoria (void); 

        // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Lista & otro);
		
    };
    
	/***********************************************************************/
	/***********************************************************************/
	// Otras funciones no pertenecientes a la clase
	
	// Muestra el contenido de una lista 
	void PintaLista (const Lista l, const char * const msg);
	
	
	/***********************************************************************/
	/***********************************************************************/
	
	#endif
