/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 2
//
// Declaración de la clase Matriz2D_2 (con constructor de copia).
// La versión incluye constructor de copia.
//
// Fichero: Matriz2D_1_ConstructorCopia.h
//
/***************************************************************************/

	#ifndef MATRIZ_2D_1_CONSTRUCTOR_COPIA
	#define MATRIZ_2D_1_CONSTRUCTOR_COPIA

	typedef int TipoBase;
	
	/***********************************************************************/
	/***********************************************************************/

	class Matriz2D_1 
	{

	private:

		// Los datos se almacenan en filas independientes. Cada fila es 
		// accesible desde un vector de punteros (datos[0], datos[1], ...)
		// "datos" contiene la dirección de memoria del primer elemento 
		// del vector de punteros. Ese vector contiene "filas" casillas, 
		// y cada fila contiene "columnas" datos "int".
		 
		TipoBase ** datos;	// Datos. 
		int filas;		// Número de filas
		int columnas;	// Número de columnas

		// PRE: 0 <= filas
		// PRE: 0 <= columnas
		
	public:

		/*******************************************************************/
		// Constructor sin argumentos: crea una matriz vacia 
		Matriz2D_1(void);

		/*******************************************************************/
		// Constructor de matrices cuadradas
		Matriz2D_1 (int orden);

		/*******************************************************************/
		// Constructor de matrices rectangulares 
		Matriz2D_1 (int fils, int cols);

		/*******************************************************************/
		// Constructor de copia
		Matriz2D_1 (const Matriz2D_1 & otro);

		/*******************************************************************/
		// Destructor
		~Matriz2D_1 (void);

		/*******************************************************************/
		// Rellena todas las casillas de la matriz con el valor "valor"
		void Inicializar (const TipoBase valor=0);
		
		/*******************************************************************/
		// Consulta si la matriz esta vacia
		bool EstaVacia (void) const;

		/*******************************************************************/
		// Consulta el número de filas y columnas
		int Filas (void) const;
		int Columnas (void) const;

		/*******************************************************************/
		// Métodos de acceso a los datos

		// Devuelve el contenido de la casilla (fila, columna)
		// PRE: 0 <= fila < Filas()
		// PRE: 0 <= columna < Columnas()
		TipoBase LeeValor (int fila, int columna) const;

		// Escribe un valor en la casilla (fila, columna)
		// PRE: 0 <= fila < Filas()
		// PRE: 0 <= columna < Columnas()
		void PonValor(int fila, int columna, TipoBase valor);

		Matriz2D_1 & operator=(const Matriz2D_1 &otra_matriz);


		Matriz2D_1 & operator=(const TipoBase value);


		TipoBase & operator()(const int f, const int c);
		

	private:
		
		/*******************************************************************/
		// Petición / liberación de memoria
		void ReservarMemoria (int filas, int columnas);
		void LiberarMemoria (void); 

		/*******************************************************************/
        // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Matriz2D_1 & otro);
			
	};

	/***********************************************************************/
	/***********************************************************************/
	// Otras funciones no pertenecientes a la clase
	
	// Muestra el contenido de una matriz 
	void PintaMatriz (const Matriz2D_1 m, const char * const msg);
	
	
	/***********************************************************************/
	/***********************************************************************/
	
	#endif
