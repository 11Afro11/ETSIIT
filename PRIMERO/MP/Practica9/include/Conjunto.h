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
// Declaración de la clase Conjunto (Incluye constructor de copia).
//
// Fichero: Conjunto_ConstructorCopia.h
//
/***************************************************************************/

	#ifndef CONJUNTO_CONSTRUCTOR_COPIA
	#define CONJUNTO_CONSTRUCTOR_COPIA

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
	
	class Conjunto 
	{

	private:
		
		TipoNodo * primero; // Puntero al primer nodo 
		int tamanio;		// Número de nodos

		// PRE: tamanio >= 0
		
	public:
		
		/*******************************************************************/
		// Constructor sin argumentos: crea una Conjunto vacia.
		Conjunto (void);

		/*******************************************************************/
		// Constructor con argumentos: crea una Conjunto con "tam" nodos
		// PRE: tam > 0
		Conjunto (int tam);

		/*******************************************************************/
		// Constructor de copia
		Conjunto (const Conjunto & otro);
		
		/*******************************************************************/
        // Destructor
        ~Conjunto (void);

		/*******************************************************************/
		// Inicializa la Conjunto al valor dado
		void Inicializar (int valor=0);

		/*******************************************************************/
        // Consulta si la Conjunto esta vacia
		bool EstaVacia (void) const;
		
		/*******************************************************************/
		// Devuelve el numero de elementos
		int  Tamanio (void) const;

		/*******************************************************************/
        // Métodos de acceso para escribir/leer en una posición dada: 
        // NO MODIFICAN EL NÚMERO DE NODOS

		/*******************************************************************/
		// Busca un alumno con el valor especificado. Devuelve la posición  
		// del primer nodo coincidente, o -1 si no se encuentra.
		/*******************************************************************/
		int Busca (TipoBase valor) const;
	
		/*******************************************************************/
		// Devuelve el contenido de un nodo (pos)
		// PRE: 1 <= pos <= tamanio
		// El criterio seguido para especificar una posicion será : 
		// 1 -> primero, 2 -> segundo,...
		TipoBase ObtenValor (int pos) const;

		/*******************************************************************/
		// Escribe un valor en un nodo (pos)
		// PRE: 1 <= pos <= tamanio
		// El criterio seguido para especificar una posicion será : 
		// 1 -> primero, 2 -> segundo,...
		void PonValor (TipoBase valor, int pos);

		/*******************************************************************/
        // Métodos que modifican el tamaño de la Conjunto 
      	// MODIFICAN EL NÚMERO DE NODOS
  			
		/*******************************************************************/
		// Aniade (al final) un nuevo elemento
		void Aniade (int TipoBase);

        // Borra el primer nodo que contiene el valor "valor"
    	void Elimina (int TipoBase);
    
		/*******************************************************************/
		// Inserta un nuevo elemento en la posición "pos_insertar"
		// PRE: 1 <= pos_insertar <= tamanio+1
		// El criterio seguido para especificar una posicion será : 
		// 1 -> primero, 2 -> segundo,...
		// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
		// 		 ejecución del método Aniade()
		void Inserta (TipoBase v)

		/*******************************************************************/
		// Borra el elemento de la posición "pos_borrar" 
		// PRE: 1 <= pos_borrar <= tamanio
		// El criterio seguido para especificar una posicion será : 
		// 1 -> primero, 2 -> segundo,...
		void Borra (int pos_borrar);

		Conjunto operator=(const Conjunto & otra_Conjunto);

		Conjunto operator=(const TipoBase value);

		Conjunto operator[](const int &pos);
		
	private:
		
		/*******************************************************************/
		// Petición / liberación de memoria
		void ReservarMemoria (int num_elementos);
		void LiberarMemoria (void); 

        // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Conjunto & otro);
		
    };
    
	/***********************************************************************/
	/***********************************************************************/
	// Otras funciones no pertenecientes a la clase
	
	// Muestra el contenido de una Conjunto 
	void PintaConjunto (const Conjunto l, const char * const msg);
	
	
	/***********************************************************************/
	/***********************************************************************/
	
	#endif
	
