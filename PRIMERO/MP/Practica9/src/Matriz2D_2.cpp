/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 3
//
// Implementación de la clase Matriz2D_2 (con constructor de copia).
// La versión incluye constructor de copia.
//
// Fichero: Matriz2D_2_ConstructorCopia.cpp
//
/***************************************************************************/
	#include <iostream>
	#include <cstring>
	
	#include "Matriz2D_2_ConstructorCopia.h"
		
	using namespace std;

	/***********************************************************************/
	// Constructor sin argumentos: crea una matriz vacia
	Matriz2D_2 :: Matriz2D_2 (void)       
			: filas(0), columnas(0), datos(0) 
	{}

	/***********************************************************************/
	// Constructor de matrices cuadradas
	Matriz2D_2 :: Matriz2D_2 (int orden)	
			: filas(orden), columnas(orden) 
	{
		ReservarMemoria(filas, columnas);
	}

	/***********************************************************************/
	// Constructor de matrices rectangulares
	Matriz2D_2 :: Matriz2D_2 (int fils, int cols) 
			: filas(fils), columnas(cols) 
	{
		ReservarMemoria(filas, columnas);
	}

	/***********************************************************************/
	// Constructor de copia
	Matriz2D_2 :: Matriz2D_2 (const Matriz2D_2 & otro)
	{
		// Reserva de memoria para los valores de la matriz
		ReservarMemoria (otro.filas, otro.columnas);

		// Copia el contenido de la matriz y los campos privados
		CopiarDatos(otro);
	}	
	
	/***********************************************************************/
	// Destructor
	 Matriz2D_2 :: ~Matriz2D_2 (void)
	{
		LiberarMemoria ();				
	}

	/***********************************************************************/
	// Rellena todas las casillas de la matriz con el valor "valor"
	void Matriz2D_2 :: Inicializar (const int valor)
	{
		for(int i = 0; i < filas; i++)
			for(int j = 0; j < columnas; j++)
				datos[i][j] = valor;	
	}
	
	/***********************************************************************/
	// Consulta si la matriz esta vacia
	bool Matriz2D_2 :: EstaVacia (void) const
	{
		return (datos == 0);
	}

	/***********************************************************************/
	// Consulta el número de filas
	int Matriz2D_2 :: Filas (void) const
	{		
		return (filas);
	}

	/***********************************************************************/
	// Consulta el número de columnas
	int Matriz2D_2 :: Columnas (void) const
	{
		return (columnas);
	}

	/***********************************************************************/
	// Método de acceso a los datos
	// Devuelve el contenido de la casilla (fila, columna)
	// PRE: 0 <= fila < Filas()
	// PRE: 0 <= columna < Columnas()
	TipoBase Matriz2D_2 :: LeeValor (int fila, int columna) const
	{
		return (datos[fila][columna]);
	}

	/***********************************************************************/
	// Escribe un valor en la casilla (fila, columna)
	// PRE: 0 <= fila < Filas()
	// PRE: 0 <= columna < Columnas()
	void Matriz2D_2 :: PonValor(int fila, int columna, TipoBase valor)
	{
		datos[fila][columna] = valor;
	}

	/***********************************************************************/
	// Pide memoria para la estructura de datos
	void Matriz2D_2 :: ReservarMemoria (int fils, int cols)
	{
		// Reservar para el vector de punteros
		datos = new int * [fils];

		// Reservar para el vector de datos
		datos[0] = new int[fils*cols];

		// Inicializar el vector de punteros
		for(int f = 1; f < fils; f++)
			datos[f] = datos[f-1] + cols;
	}

	/***********************************************************************/
	// Liberar memoria
	void Matriz2D_2 :: LiberarMemoria (void)
	{
		if (datos) {

			// Liberar la zona de datos
			delete [] datos[0]; 

			// Libera el vector de punteros
			delete [] datos; 
		}
	}

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
    // PRE: Se ha reservado memoria para los datos
	void Matriz2D_2 :: CopiarDatos (const Matriz2D_2 & otro)
	{
		// Copiar datos privados
		filas = otro.filas;
		columnas = otro.columnas;

        // Copiar los valores de cada una de las filas
        memcpy (datos[0], otro.datos[0], filas*columnas*sizeof(int));
	}


	Matriz2D_2 & Matriz2D_2::operator=(const Matriz2D_2 &otra_matriz){
		if(&otra_matriz != this){
			LiberarMemoria();
			ReservarMemoria(otra_matriz.filas,otra_matriz.columnas);
			CopiarDatos(otra_matriz);
		}
		return *this;
	}



	Matriz2D_2 & Matriz2D_2::operator=(const TipoBase value){

		Inicializar(value);

		return *this;
	}



	TipoBase & Matriz2D_2 :: operator()(const int f, const int c){
		return datos[f][c];
	}

    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
	/***********************************************************************/
	// Muestra el contenido de una matriz, precedido del mensaje "msg"
	void PintaMatriz (const Matriz2D_2 m, const char * const msg)
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
