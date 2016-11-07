/*********************************************************************/
// METODOLOGÍA DE LA PROGRANACIÓN
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 8
//
// EJERCICIO 2 - Matriz2D_2
//
/*	

 Implementar la clase Matriz2D-2 para elementos de tipo TipoBase. Empleando la repre-
sentación básica conocida, se trata de implementar los siguientes métodos:


*/
/*********************************************************************/

#include "Matriz2D_2.h"
#include <iostream>
#include <cstring>
using namespace std;
/*

class Matriz2D_2
{
	private:
		Matriz matriz;
		int filas, columnas;	*/

/***************************************************************************//*

Metodo Privado QUe reserva espacio para una Matriz dinamica

*//***************************************************************************/


		void Matriz2D_2::ReservaEspacio(int fila, int columna){
			matriz = 0;
			if(filas != 0 && columnas!=0){
				matriz = new TipoBase * [filas];
				matriz[0] = new TipoBase [filas*columnas];
				for(int i = 1; i < filas; i++){
					matriz[i] = matriz[i - 1]+columnas;
				}
			}
		}

/***************************************************************************//*

Metodo privado que copia en un objetode la clase MatrizDinamica otro objeto
de la clase vector dinamico

*//***************************************************************************/


		void Matriz2D_2::Copia(const Matriz2D_2 &otra_matriz){			

			filas = otra_matriz.filas;
			columnas = otra_matriz.columnas;
			memcpy(matriz[0], otra_matriz.matriz[0], filas * columnas * sizeof(TipoBase));
			for(int i = 1; i < filas; i++){
				matriz[i] = matriz[i - 1]+columnas;
			}
		}

/***************************************************************************//*

Metodo Privado que libera el espacio reservado por un objeto de la clase MatrizDinamica

*//***************************************************************************/


		void Matriz2D_2::LiberaMemoria(){

			delete[]matriz[0];
			delete[]matriz;
		}

//	public:

/***************************************************************************//*

Constructor Por defecto.

*//***************************************************************************/

		Matriz2D_2::Matriz2D_2(){
			filas = 0;
			columnas = 0;
			matriz = NULL;
		}

/***************************************************************************//*

Constrcutor Con un parametro.

*//***************************************************************************/

		Matriz2D_2::Matriz2D_2(int fil){
			matriz = 0;
			filas = fil;
			columnas = fil;
			if(filas != 0){
				ReservaEspacio(filas, columnas);
			}
		}

/***************************************************************************//*

Constrcutor con dos parametros

*//***************************************************************************/

		Matriz2D_2::Matriz2D_2(int fil, int col){
			matriz = 0;
			filas = fil;
			columnas = col;

			if(filas != 0 && columnas != 0){
				ReservaEspacio(filas, columnas);
			}
		}

/***************************************************************************//*

Constrcutor Con 3 parametros.

*//***************************************************************************/

		Matriz2D_2::Matriz2D_2(int fil, int col, TipoBase value){
			matriz = 0;
			filas = fil;
			columnas = col;
			if(filas != 0 && columnas != 0){
				ReservaEspacio(filas, columnas);
				for(int i = 0; i < filas; i++){
					for(int j = 0; j < columnas; j++){
						matriz[i][j] = value;
					}
				}
			}
		}

/***************************************************************************//*

Constrcutor Constructor de copia.

*//***************************************************************************/

		Matriz2D_2::Matriz2D_2(const Matriz2D_2 & matrizd){
			
			ReservaEspacio(matrizd.filas, matrizd.columnas);
			Copia(matrizd);
			
		}

/***************************************************************************//*

Destructor

*//***************************************************************************/

		Matriz2D_2::~Matriz2D_2(){
			
			LiberaMemoria();
		}

/***************************************************************************//*

Metodo Público que compruev si la matriz esta vacio o no.
el metodo devuelve una variable booleana.

*//***************************************************************************/

		bool Matriz2D_2::EstaVacia() const{
			bool esta_vacia;
			esta_vacia = (matriz==NULL);

			return esta_vacia;
		}

/***************************************************************************//*

Metodo Publico que graba un valor pasado por parametro en una fila y una columna
pasadas tambien por parametro 
Se trata de un metodo void

*//***************************************************************************/

		void Matriz2D_2::PonValor (int fila, int col, TipoBase valor){
			matriz[fila][col] = valor;
		}

/***************************************************************************//*

Metodo Publico que devuelve el valor almacenado por la matriz en la posicion pasada 
como parametro.
Este metodo devuelve un dato de tipo TipoBase

*//***************************************************************************/

		TipoBase Matriz2D_2::LeeValor (int fila, int col) const{
			return matriz[fila][col];
		}

/***************************************************************************//*

Metodo Publico que se encarga de igualar todos los elementos de la matriz a un 
valor pasado por parametro.
Se trata de un metodo void

*//***************************************************************************/

		void Matriz2D_2::Asigna (TipoBase valor){
			for(int i = 0; i < filas; i++){
				for(int j = 0; j < columnas; j++){
					matriz[i][j] = valor;
				}
			}
		}

/***************************************************************************//*

Metodo Publico que devuelve el numero de filas que posee la matriz.
El mettodo devuelve un dato de tipo int.

*//***************************************************************************/

		int Matriz2D_2::Filas()const{
			return filas;
		}

/***************************************************************************//*

Metodo Publico que devuelve el numero de columnas que posee la matriz.
El mettodo devuelve un dato de tipo int.

*//***************************************************************************/

		int Matriz2D_2::Columnas()const {
			return columnas;
		}


/***************************************************************************//*

Funcion externa a la clase que se encarga de mostrar por pantalla los 
componentes de un objeto de tipo Matriz2D_2 pasado como parametro

*//***************************************************************************/

		void PintaMatriz (const Matriz2D_2 &matr, char * etiqueta){
			cout << endl << etiqueta <<endl;
			for(int i = 0; i < matr.Filas(); i++){
				for(int j = 0; j < matr.Columnas(); j++){
					cout << matr.LeeValor(i,j) << " ";
				}
				cout << endl;
			}
		}



//};