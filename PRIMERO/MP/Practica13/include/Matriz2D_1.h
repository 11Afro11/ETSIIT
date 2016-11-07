/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 2
//
// Declaración de la clase clase Matriz2D_1.
// (Incluye constructor de copia, operador de asignación y sobrecarga de ()).
//
// Fichero: Matriz2D_1_Asignacion-Acceso.cpp
//
/***************************************************************************/

	#ifndef MATRIZ_2D_1_ASIGNACION_ACCESO
	#define MATRIZ_2D_1_ASIGNACION_ACCESO

	#include <istream>


	
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
		// Constructor de copia
		Matriz2D_1 (std::istream & fi);

		int CuentaColumnas(std::istream & fi);


		void AniadeFila(const TipoBase *numeros);

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
		// Metodo de acceso individual a elementos: Operator ()
		// Metodo de escritura / lectura
		// PRE: 0 <= fila < filas
		// PRE: 0 <= columna < columnas
		TipoBase & operator () (const int fila, const int columna);
		TipoBase & operator () (const int fila, const int columna) const;

		/*******************************************************************/
		// Operador de asignación 
		Matriz2D_1 & operator = (const Matriz2D_1 & otro);
		Matriz2D_1 & operator = (const TipoBase & valor);

		/*******************************************************************/
		// Operadores suma y resta

		Matriz2D_1 operator + (const Matriz2D_1 & otra)const;

		Matriz2D_1 operator + (const TipoBase & otra)const;

		Matriz2D_1 operator - (const Matriz2D_1 & otra)const;

		Matriz2D_1 operator - (const TipoBase & otra)const;

		/*******************************************************************/
		// Operadores += y -=

		Matriz2D_1 & operator += (const Matriz2D_1 & otra);

		Matriz2D_1 & operator += (const TipoBase & otra);

		Matriz2D_1 & operator -= (const Matriz2D_1 & otra);

		Matriz2D_1 & operator -= (const TipoBase & otra);

		/*******************************************************************/
		// Operadores igual y distinto

		bool operator == (const Matriz2D_1 & otra)const;
		bool operator != (const Matriz2D_1 & otra)const;

	private:
		
		/*******************************************************************/
		// Petición / liberación de memoria
		void ReservarMemoria (int filas, int columnas);
		void LiberarMemoria (void); 

		/*******************************************************************/
        // Copiar datos desde otro objeto de la clase
		void CopiarDatos (const Matriz2D_1 & otro);

		/*******************************************************************/
		// Funciones friend para la suma
		
		friend Matriz2D_1 operator - (const TipoBase & otra, const Matriz2D_1 &matr);

		friend Matriz2D_1 operator + (const TipoBase & otra, const Matriz2D_1 &matr);
			
	};

	/***********************************************************************/
	/***********************************************************************/
	// Otras funciones no pertenecientes a la clase
	
	// Muestra el contenido de una matriz 
	void PintaMatriz (const Matriz2D_1 m, const char * const msg);
	
	
	/***********************************************************************/
	/***********************************************************************/
	
	#endif
