/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 1
//
// Declaraci�n de la clase VectorDinamico 
// (Incluye constructor de copia, operador de asignaci�n y sobrecarga de []).
//
// Fichero: VectorDinamico_Asignacion-Acceso.h
//
/***************************************************************************/

	#ifndef VECTOR_DINAMICO_ASIGNACION_ACCESO
	#define VECTOR_DINAMICO_ASIGNACION_ACCESO

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
	
	    // Los datos se almacenan en un vector din�mico de datos 
		// "int". Se accede a ellos a trav�s del puntero "datos". 
		// El n�mero de casillas se establece cuando el constructor crea 
		// el objeto (por defecto, "TAM_DEF") y se guarda en "tam". 
		// PUEDE MODIFICARSE, mediante el m�todo apropiado. 
		// El n�mero de casillas ocupadas se guarda en "usados".
			
		TipoBase * datos;	// Datos.
		int   tam;		// N�mero de casillas reservadas.
		int   usados;	// N�mero de casillas usadas.
		
		// PRE: 0 <= usados < tam
		
		// Tipo de redimensionamiento activo. uede modificarse el tipo 
		// de redimensionamiento en tiempo de ejecuci�n.
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
		// M�todos de consulta de los datos privados

		int Capacidad (void) const;
		int NumDatosGuardados(void) const;
		
		/*******************************************************************/
		// Establece/consulta el tipo de redimensionamiento

		void FijaRedimensionamiento (TipoRedimension tipo);
		TipoRedimension ConsultaRedimensionamiento (void) const;

		/*******************************************************************/
		// A�ade un elemento al vector
		// PRE: usados < tam
		void Aniade (TipoBase valor);

		/*******************************************************************/
		// Metodo de acceso individual a elementos: operator []
		// Metodo de escritura / lectura
		// PRE: 0 <= posicion <usados 		
		TipoBase & operator [] (const int posicion);  	
		TipoBase & operator [] (const int posicion) const;  
				
		/*******************************************************************/
		// Operador de asignaci�n
		VectorDinamico & operator = (const VectorDinamico & otro);
		VectorDinamico & operator = (const TipoBase & valor);
		VectorDinamico operator+  (const VectorDinamico &orig)const;

		/*******************************************************************/
		// Operadores de suma

		VectorDinamico operator+  (const TipoBase dato)const;

		VectorDinamico &operator+=  (const VectorDinamico &orig);

		VectorDinamico &operator+=  (const TipoBase dato);

		/*******************************************************************/
		// Operador igual

		bool operator==(const VectorDinamico & otro)const;

		/*******************************************************************/
		// Operador distinto

		bool operator!=(const VectorDinamico & otro)const;

		/*******************************************************************/
		// Operadores menor igual mayor igual menos y mayor

		bool operator>(const VectorDinamico & otro)const;

		bool operator<(const VectorDinamico & otro)const;

		bool operator>=(const VectorDinamico & otro)const;

		bool operator<=(const VectorDinamico & otro)const;

	private:

		/*******************************************************************/
		// Petici�n / liberaci�n de memoria
		void PideMemoria (const int num_casillas);
		void LiberaMemoria (void);

		// Copiar datos desde otro objeto de la clase
		void CopiarDatos (const VectorDinamico & otro);

    	/*******************************************************************/
		// Redimensiona el vector din�mico de acuerdo al tipo de redimensi�n 
		// establecido y registrado.
		// Copia todos los datos en el nuevo almac�n.  
		void RedimensionaAlmacen (void);

	};
	
	/////////////////////////////////////////////////////////////////////////
	
	// Muestra el contenido de un vector din�mico 
	void PintaVectorDinamico (const VectorDinamico &v, const char * const msg);

	// Funci�n que convierte a string el valor enumerado
	void PintaRedimensionamiento (TipoRedimension tipo);
	
	#endif
