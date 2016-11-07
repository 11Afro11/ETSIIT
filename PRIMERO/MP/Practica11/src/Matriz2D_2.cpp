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
// Implementación de la clase clase Matriz2D_2.
// (Incluye constructor de copia, operador de asignación y sobrecarga de []).
//
// Fichero: Matriz2D_2_Asignacion-Acceso.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <cstring>
	
	#include "Matriz2D_2.h"
		
	using namespace std;

	/***********************************************************************/
	// Constructor sin argumentos: crea una matriz vacia
	Matriz2D_2 :: Matriz2D_2(void)       
			: filas(0), columnas(0), datos(0) 
	{ }

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

	/*******************************************************************/
	// Metodo de acceso individual a elementos: operator []
	// Metodo de escritura / lectura
	// PRE: 0 <= posicion <usados 
	TipoBase & Matriz2D_2 :: operator () (const int fila, 
									      const int columna)
	{
		return (datos[fila][columna]);
	}
	TipoBase & Matriz2D_2 :: operator () (const int fila, 
										  const int columna) const
	{
		return (datos[fila][columna]);
	}

	/*********************************************************************/
	// Operador de asignación desde otro dato Matriz2D_2
	Matriz2D_2 & Matriz2D_2 :: operator = (const Matriz2D_2 & otro)
	{
	    if (this != &otro) { // Evitar autoasignación
	
	        // Libera la memoria ocupada
	        LiberarMemoria();
	
	        // Reserva de memoria para los valores de la matriz
	        ReservarMemoria (otro.filas, otro.columnas);
	
	        // Copia el contenido de la matriz y los campos privados
	        CopiarDatos(otro);
	    }
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignación
	}
	
	/*********************************************************************/
	// Operador de asignación desde otro dato TipoBase
	Matriz2D_2 & Matriz2D_2 :: operator = (const TipoBase & valor)
	{
		// Escribir "valor" en todas las casillas 
	    Inicializar(valor);
	 
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignación
	}

	/*********************************************************************/
	// Operadores Aritmeticos

	/*********************************************************************/
	// Suma

	Matriz2D_2 Matriz2D_2 :: operator + (const Matriz2D_2 & otra)const{
		Matriz2D_2 suma;
		if(filas == otra.filas && columnas == otra.columnas){
			suma = *this;
			for(int i = 0; i < otra.filas; i++){
				for(int j = 0; j < otra.columnas; j++){
					suma.datos[i][j] = suma.datos[i][j] + otra.datos[i][j];
				}
			}
		}
		return suma;
	}

	Matriz2D_2 Matriz2D_2 :: operator + (const TipoBase & otra)const{
	
		Matriz2D_2 suma;
		Matriz2D_2 a_sum(filas,columnas);
		a_sum.Inicializar(otra);

		suma = *this + a_sum;
		
		return suma;
	}

	/*********************************************************************/
	// Resta

	Matriz2D_2 Matriz2D_2 :: operator - (const Matriz2D_2 & otra)const{
		Matriz2D_2 res;
		if(filas == otra.filas && columnas == otra.columnas){
			res = *this;
			for(int i = 0; i < otra.filas; i++){
				for(int j = 0; j < otra.columnas; j++){
					res.datos[i][j] = res.datos[i][j] - otra.datos[i][j];
				}
			}
		}
		return res;
	}

	Matriz2D_2 Matriz2D_2 :: operator - (const TipoBase & otra)const{
	
		Matriz2D_2 res;
		Matriz2D_2 a_res(filas, columnas);

		a_res.Inicializar(otra);

		res = *this - a_res;
		
		return res;
	}

	/*********************************************************************/
	// Funciones friend de suma y resta

	Matriz2D_2 operator - (const TipoBase & otra, const Matriz2D_2 &matr){
	
		Matriz2D_2 res;
		Matriz2D_2 a_res(matr.filas, matr.columnas);

		a_res.Inicializar(otra);
		
		res = a_res - matr;
		
		return res;
	}

	Matriz2D_2 operator + (const TipoBase & otra, const Matriz2D_2 &matr){
	
		Matriz2D_2 suma;
		Matriz2D_2 a_sum(matr.filas, matr.columnas);
		a_sum.Inicializar(otra);

		suma = a_sum + matr;
		
		return suma;
	}

	/*********************************************************************/
	// Operadores Aritmaticos

	/*********************************************************************/
	//ma igual

	Matriz2D_2 & Matriz2D_2 :: operator += (const Matriz2D_2 & otra){
		
		*this = *this + otra;

		return *this;
	}

	

	Matriz2D_2 & Matriz2D_2 :: operator += (const TipoBase & otra){
	
		*this = *this +otra;
		
		return *this;
	}

	/*********************************************************************/
	// Menos igual

	Matriz2D_2 & Matriz2D_2 :: operator -= (const Matriz2D_2 & otra){
		
		*this = *this - otra;

		return *this;
	}

	Matriz2D_2 & Matriz2D_2 :: operator -= (const TipoBase & otra){
	
		*this = *this - otra;
		
		return *this;
	}

	/*********************************************************************/
	// Operadores booleanos
	/*********************************************************************/
	// igual

	bool Matriz2D_2 :: operator == (const Matriz2D_2 & otra)const{
		bool igual = filas == otra.filas && columnas == otra.columnas;


		for(int i = 0; i < filas && igual; i++){
			for(int j = 0; j < columnas && igual; j++){
				igual = datos[i][j] == otra.datos[i][j];
			}
		}
		return igual;
	}

	/*********************************************************************/
	// Distinto

	bool Matriz2D_2 :: operator != (const Matriz2D_2 & otra)const{
		bool distinto = !(*this == otra);
		return distinto;
	}

	/***********************************************************************/
	// Pide memoria para la estructura de datos
	void Matriz2D_2 :: ReservarMemoria (int fils, int cols)
	{
		// Reservar para el vector de punteros
		datos = new TipoBase * [fils];

		// Reservar para el vector de datos
		datos[0] = new TipoBase[fils*cols];

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
        memcpy (datos[0], otro.datos[0], filas*columnas*sizeof(TipoBase));
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
				cout << m (f,c) << " "; // Prueba del operador de acceso () 
										// para lectura
			cout << endl;
		}
		cout << endl;
	}
	
	/***********************************************************************/
	/***********************************************************************/
