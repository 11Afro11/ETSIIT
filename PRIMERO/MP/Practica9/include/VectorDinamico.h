/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 1
//
// Declaración  de la clase VectorDinamico (Incluye constructor de copia).
//
// Fichero: VectorDinamico_ConstructorCopia.h
//
/***************************************************************************/

	#ifndef VECTOR_DINAMICO_CONSTRUCTOR_COPIA
	#define VECTOR_DINAMICO_CONSTRUCTOR_COPIA

	typedef int TipoBase;
	
	/***********************************************************************/
	/***********************************************************************/
	// Tipo enumerado para representar los tipos de redimensionamiento.

	enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

	/***********************************************************************/
	/***********************************************************************/

	class VectorDinamico 
	{
	private: 
	
	    // Los datos se almacenan en un vector dinámico de datos 
		// "int". Se accede a ellos a través del puntero "datos". 
		// El número de casillas se establece cuando el constructor crea 
		// el objeto (por defecto, "TAM_DEF") y se guarda en "tam". 
		// PUEDE MODIFICARSE, mediante el método apropiado. 
		// El número de casillas ocupadas se guarda en "usados".
			
		TipoBase * datos;	// Datos.
		int   tam;		// Número de casillas reservadas.
		int   usados;	// Número de casillas usadas.
		
		// PRE: 0 <= usados < tam
		
		// Tipo de redimensionamiento activo. uede modificarse el tipo 
		// de redimensionamiento en tiempo de ejecución.
		TipoRedimension tipo_redimension;
		
		// Capacidad inicial, por defecto 
		static const int TAM_DEF = 10; 

		// Tamanio del bloque para redimensionamiento "EnBloques"
		static const int TAM_BLOQUE = 5;

	public: 

		/*******************************************************************/
		// Constructor sin argumentos, o con un argumento
		VectorDinamico (const int tam_inicial=TAM_DEF);
	
		// Constructor de copia
		VectorDinamico (const VectorDinamico & otro);
		
		/*******************************************************************/
		// Destructor
		~VectorDinamico (void);

		/*******************************************************************/
		// Métodos de consulta de los datos privados

		int Capacidad (void) const;
		int NumDatosGuardados(void) const;
		
		/*******************************************************************/
		// Establece/consulta el tipo de redimensionamiento

		void FijaRedimensionamiento (TipoRedimension tipo);
		TipoRedimension ConsultaRedimensionamiento (void) const;

		/*******************************************************************/
		// Añade un elemento al vector
		// PRE: usados < tam
		void Aniade (TipoBase valor);

		/*******************************************************************/
		// Devuelve el contenido de la casilla "posicion"
		// PRE: 0 <= posicion < usados 
		TipoBase Elemento (int posicion) const;

		void Inicializar (const TipoBase &valor_inicial);


		VectorDinamico & operator= (const VectorDinamico & orig);

		VectorDinamico & operator= (const TipoBase data);

		TipoBase & operator [] (const int posicion);
			
	private:

		/*******************************************************************/
		// Petición / liberación de memoria
		void PideMemoria (const int num_casillas);
		void LiberaMemoria (void);

		// Copiar datos desde otro objeto de la clase
		void CopiarDatos (const VectorDinamico & otro);

    	/*******************************************************************/
		// Redimensiona el vector dinámico de acuerdo al tipo de redimensión 
		// establecido y registrado.
		// Copia todos los datos en el nuevo almacén.  
		void RedimensionaAlmacen (void);

	};
	
	/////////////////////////////////////////////////////////////////////////
	
	// Muestra el contenido de un vector dinámico 
	void PintaVectorDinamico (const VectorDinamico &v, const char * const msg);

	// Función que convierte a string el valor enumerado
	void PintaRedimensionamiento (TipoRedimension tipo);
	
	#endif
