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
// Implementación de la clase clase Matriz2D_1.
// (Incluye constructor de copia, operador de asignación y sobrecarga de []).
//
// Fichero: Matriz2D_1_Asignacion-Acceso.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
	
	#include "Matriz2D_1.h"
		
	using namespace std;
class Matriz2D_1{
private:
	TipoBase ** datos;	// Datos. 
	int filas;		// Número de filas
	int columnas;	// Número de columnas

public:
	/***********************************************************************/
	// Constructor sin argumentos: crea una matriz vacia
 Matriz2D_1(void)       
			: filas(0), columnas(0), datos(0) 
	{ }

	/***********************************************************************/
	// Constructor de matrices cuadradas
 Matriz2D_1 (int orden)	
			: filas(orden), columnas(orden) 
	{
		ReservarMemoria(filas, columnas);
	}

	/***********************************************************************/
	// Constructor de matrices rectangulares
 Matriz2D_1 (int fils, int cols) 
			: filas(fils), columnas(cols) 
	{
		ReservarMemoria(filas, columnas);
	}

	/***********************************************************************/
	// Constructor de copia
 Matriz2D_1 (const Matriz2D_1 & otro)
	{
		// Reserva de memoria para los valores de la matriz
		ReservarMemoria (otro.filas, otro.columnas);

		// Copia el contenido de la matriz y los campos privados
		CopiarDatos(otro);
	}	
		
	/***********************************************************************/
	// Destructor
	 ~Matriz2D_1 (void)
	{
		LiberarMemoria ();				
	}

	/***********************************************************************/
	// Rellena todas las casillas de la matriz con el valor "valor"
	void Inicializar (const int valor)
	{
		for(int i = 0; i < filas; i++)
			for(int j = 0; j < columnas; j++)
				datos[i][j] = valor;	
	}
	
	/***********************************************************************/
	// Consulta si la matriz esta vacia
	bool EstaVacia (void) const
	{
		return (datos == 0);
	}

	/***********************************************************************/
	// Consulta el número de filas
	int Filas (void) const
	{		
		return (filas);
	}

	/***********************************************************************/
	// Consulta el número de columnas
	int Columnas (void) const
	{
		return (columnas);
	}

	/*******************************************************************/
	// Metodo de acceso individual a elementos: operator []
	// Metodo de escritura / lectura
	// PRE: 0 <= posicion <usados 
	TipoBase & operator () (const int fila, 
									      const int columna)
	{
		return (datos[fila][columna]);
	}
	TipoBase & operator () (const int fila, 
										  const int columna) const
	{
		return (datos[fila][columna]);
	}

	/*********************************************************************/
	// Operador de asignación desde otro dato Matriz2D_1
	Matriz2D_1 & operator = (const Matriz2D_1 & otro)
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
	Matriz2D_1 & operator = (const TipoBase & valor)
	{
		// Escribir "valor" en todas las casillas 
	    Inicializar(valor);
	 
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignación
	}

	/***************************************************************************/
	//Operadores Aritmeticos
	/***************************************************************************/
	//Suma

	Matriz2D_1 operator + (const Matriz2D_1 & otra)const{
		Matriz2D_1 suma;
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

	Matriz2D_1 operator + (const TipoBase & otra)const{
	
		Matriz2D_1 suma;
		Matriz2D_1 a_sum(filas,columnas);
		a_sum.Inicializar(otra);

		suma = *this + a_sum;
		
		return suma;
	}

	/***************************************************************************/
	//Resta

	Matriz2D_1 operator - (const Matriz2D_1 & otra)const{
		Matriz2D_1 res;
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

	Matriz2D_1 operator - (const TipoBase & otra)const{
	
		Matriz2D_1 res;
		Matriz2D_1 a_res(filas, columnas);

		a_res.Inicializar(otra);

		res = *this - a_res;
		
		return res;
	}

	/***************************************************************************/
	//Funciones friend de suma y resta

	Matriz2D_1 operator - (const TipoBase & otra, const Matriz2D_1 &matr){
	
		Matriz2D_1 res;
		Matriz2D_1 a_res(matr.filas, matr.columnas);

		a_res.Inicializar(otra);
		
		res = a_res - matr;
		
		return res;
	}

	Matriz2D_1 operator + (const TipoBase & otra, const Matriz2D_1 &matr){
	
		Matriz2D_1 suma;
		Matriz2D_1 a_sum(matr.filas, matr.columnas);
		a_sum.Inicializar(otra);

		suma = a_sum + matr;
		
		return suma;
	}

	/***************************************************************************/
	//Mas igual

	Matriz2D_1 & operator += (const Matriz2D_1 & otra){
		
		*this = *this + otra;

		return *this;
	}



	Matriz2D_1 & operator += (const TipoBase & otra){
	
		*this = *this +otra;
		
		return *this;
	}

	/***************************************************************************/
	//Menos igual

	Matriz2D_1 & operator -= (const Matriz2D_1 & otra){
		
		*this = *this - otra;

		return *this;
	}

	Matriz2D_1 & operator -= (const TipoBase & otra){
	
		*this = *this - otra;
		
		return *this;
	}

	/***************************************************************************/
	//Operadores booleanos
	/***************************************************************************/
	//Igual

	Matriz2D_1 operator * (const Matriz2D_1 & otra)const{
		Matriz2D_1 por(2, 2);
		
		for (i=1;i<=m;i++){


			for (j=1;j<=c;j++){

		       por[i][j]=0;

		       for (k=1;k<=n;k++){

		          por[i][j]=datos[i][j]+otra(i,k);

		        }

		    }

	    }
		return por;
	}


	bool operator == (const Matriz2D_1 & otra)const{
		bool igual = filas == otra.filas && columnas == otra.columnas;


		for(int i = 0; i < filas && igual; i++){
			for(int j = 0; j < columnas && igual; j++){
				igual = datos[i][j] == otra.datos[i][j];
			}
		}
		return igual;
	}

	/***************************************************************************/
	//Distinto

	bool operator != (const Matriz2D_1 & otra)const{
		bool distinto = !(*this == otra);
		return distinto;
	}

	/***********************************************************************/
	// Pide memoria para la estructura de datos
	void ReservarMemoria (int fils, int cols)
	{
		// Reservar para el vector de punteros
		datos = new int * [fils];

		// Reservar para cada fila
		for(int i = 0; i < fils; i++)
			datos[i] = new int[cols];
	}

	/***********************************************************************/
	// Liberar memoria
	void LiberarMemoria (void)
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
	void CopiarDatos (const Matriz2D_1 & otro)
	{
		// Copiar datos privados
		filas = otro.filas;
		columnas = otro.columnas;

        // Copiar los valores de cada una de las filas
        for (int f=0; f<filas; f++)
            memcpy (datos[f], otro.datos[f], columnas*sizeof(int));
	}

    /***********************************************************************/
};


int main (void)
{

	Matriz2D_1 m1, m2, m3;

	int n;
	srand(time(0));
	n = rand() % 10; 
	m1.Inicializar(n);
	n= rand() % 10;
	m2.Inicializar(n);


	clock_t tini;    // Anotamos el tiempo de inicio
	tini=clock();
	  
	int x = vmax+1;  // Buscamos un valor que no está en el vector
	m3 = m1 * m2; // de esta forma forzamos el peor caso
	  
	clock_t tfin;    // Anotamos el tiempo de finalización
	tfin=clock();



	return (0);
}

/**********************************************************************/
/**********************************************************************/




