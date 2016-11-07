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
// Implementación de la clase Matriz2D_1 (con constructor de copia).
// La versión incluye constructor de copia.
//
// Fichero: Matriz2D_1_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <cstring>
	
	#include "Matriz2D_1_ConstructorCopia.h"
		
	using namespace std;

	/***********************************************************************/
	// Constructor sin argumentos: crea una matriz vacia
	Matriz2D_1 :: Matriz2D_1(void)       
			: filas(0), columnas(0), datos(0) 
	{
	}

	/***********************************************************************/
	// Constructor de matrices cuadradas
	Matriz2D_1 :: Matriz2D_1 (int orden)	
			: filas(orden), columnas(orden) 
	{
		ReservarMemoria(filas, columnas);
	}

	/***********************************************************************/
	// Constructor de matrices rectangulares
	Matriz2D_1 :: Matriz2D_1 (int fils, int cols) 
			: filas(fils), columnas(cols) 
	{
		ReservarMemoria(filas, columnas);
	}

	/***********************************************************************/
	// Constructor de copia
	Matriz2D_1 :: Matriz2D_1 (const Matriz2D_1 & otro)
	{
		// Reserva de memoria para los valores de la matriz
		ReservarMemoria (otro.filas, otro.columnas);

		// Copia el contenido de la matriz y los campos privados
		CopiarDatos(otro);
	}	
	
		
	/***********************************************************************/
	// Destructor
	 Matriz2D_1 :: ~Matriz2D_1 (void)
	{
		LiberarMemoria ();				
	}

	/***********************************************************************/
	// Rellena todas las casillas de la matriz con el valor "valor"
	void Matriz2D_1 :: Inicializar (const int valor)
	{
		for(int i = 0; i < filas; i++)
			for(int j = 0; j < columnas; j++)
				datos[i][j] = valor;	
	}
	
	/***********************************************************************/
	// Consulta si la matriz esta vacia
	bool Matriz2D_1 :: EstaVacia (void) const
	{
		return (datos == 0);
	}

	/***********************************************************************/
	// Consulta el número de filas
	int Matriz2D_1 :: Filas (void) const
	{		
		return (filas);
	}

	/***********************************************************************/
	// Consulta el número de columnas
	int Matriz2D_1 :: Columnas (void) const
	{
		return (columnas);
	}

	/***********************************************************************/
	// Método de acceso a los datos
	// Devuelve el contenido de la casilla (fila, columna)
	// PRE: 0 <= fila < Filas()
	// PRE: 0 <= columna < Columnas()
	int Matriz2D_1 :: LeeValor (int fila, int columna) const
	{
		return (datos[fila][columna]);
	}

	/***********************************************************************/
	// Escribe un valor en la casilla (fila, columna)
	// PRE: 0 <= fila < Filas()
	// PRE: 0 <= columna < Columnas()
	void Matriz2D_1 :: PonValor(int fila, int columna, int valor)
	{
		datos[fila][columna] = valor;
	}

	/***********************************************************************/
	// Pide memoria para la estructura de datos
	void Matriz2D_1 :: ReservarMemoria (int fils, int cols)
	{
		// Reservar para el vector de punteros
		datos = new int * [fils];

		// Reservar para cada fila
		for(int i = 0; i < fils; i++)
			datos[i] = new int[cols];
	}

	/***********************************************************************/
	// Liberar memoria
	void Matriz2D_1 :: LiberarMemoria (void)
	{
		if (datos) {

			for (int i = 0; i < filas; i++)
				// Libera cada fila
				delete [] datos[i]; 

			// Libera el vector de punteros
			delete [] datos; 
		}
	}

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
    // PRE: Se ha reservado memoria para los datos
	void Matriz2D_1 :: CopiarDatos (const Matriz2D_1 & otro)
	{
		// Copiar datos privados
		filas = otro.filas;
		columnas = otro.columnas;

        // Copiar los valores de cada una de las filas
        for (int f=0; f<filas; f++)
            memcpy (datos[f], otro.datos[f], columnas*sizeof(int));
	}


	Matriz2D_1 & Matriz2D_1 :: operator=(const Matriz2D_1 &otra_matriz){
		if(&otra_matriz != this){
			LiberarMemoria();
			ReservarMemoria(otra_matriz.filas,otra_matriz.columnas);
			CopiarDatos(otra_matriz);
		}
		return *this;
	}



	Matriz2D_1 & Matriz2D_1 :: operator=(const TipoBase value){

		Inicializar(value);

		return *this;
	}



	TipoBase & Matriz2D_1 :: operator()(const int f, const int c){
		return datos[f][c];
	}


    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
	/***********************************************************************/
	// Muestra el contenido de una matriz, precedido del mensaje "msg"
	void PintaMatriz (const Matriz2D_1 m, const char * const msg)
	{
		cout << endl; 
		cout << msg << endl;
		
		for (int f=0; f<m.Filas(); f++) {
			
			for (int c=0; c<m.Columnas(); c++)
				cout << m.LeeValor (f,c) << " ";
				
			cout << endl;
		}
		cout << endl;
	}
		
	/***********************************************************************/
	/***********************************************************************/

