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
// EJERCICIO 2 - Matriz2D_1
//
/*	
 Implementar la clase Matriz2D-1 para elementos de tipo TipoBase. Empleando la repre-
sentación básica conocida, se trata de implementar los siguientes métodos:

*/
/*********************************************************************/

#include "Matriz2D_1.h"

#include <iostream>
#include <cstring>
using namespace std;

/*

class Matriz2D_1
{
	private:
		Matriz matriz;
		int filas, columnas;  */


/***************************************************************************//*

Metodo Privado QUe reserva espacio para una Matriz dinamica

*//***************************************************************************/

		void Matriz2D_1::ReservaEspacio(int fila, int columna){
			matriz = new TipoBase*[fila];
			for(int i = 0; i < fila; i++){
				for(int j = 0; j < columna; j++){
					matriz[i] = new TipoBase[columna];
				}
			}
		}

/***************************************************************************//*

Metodo privado que copia en un objetode la clase MatrizDinamica otro objeto
de la clase vector dinamico

*//***************************************************************************/

		void Matriz2D_1::Copia(const Matriz2D_1 &otra_matriz){
			
			filas = otra_matriz.filas;
			columnas = otra_matriz.columnas;
			for(int i = 0; i < filas; i++){
				memcpy(matriz[i], otra_matriz.matriz[i], sizeof(TipoBase)*columnas);
			}
		}

/***************************************************************************//*

Metodo Privado que libera el espacio reservado por un objeto de la clase MatrizDinamica

*//***************************************************************************/

		void Matriz2D_1::LiberaMemoria(){

			if(filas != 0 && columnas != 0){
				for(int i = 0; i < filas;i++){
					delete[] matriz[i];
				}
				delete[]matriz;
			}
		}

//	public:

/***************************************************************************//*

Constructor Por defecto.

*//***************************************************************************/

		Matriz2D_1::Matriz2D_1(){
			filas = 0;
			columnas = 0;
			matriz = NULL;
		}

/***************************************************************************//*

Constrcutor Con un parametro.

*//***************************************************************************/

		Matriz2D_1::Matriz2D_1(int fil){
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

		Matriz2D_1::Matriz2D_1(int fil, int col){
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

		Matriz2D_1::Matriz2D_1(int fil, int col, TipoBase value){
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

		Matriz2D_1::Matriz2D_1(const Matriz2D_1 & matrizd){
			
			ReservaEspacio(matrizd.filas, matrizd.columnas);
			Copia(matrizd);
			
		}

/***************************************************************************//*

Destructor

*//***************************************************************************/

		Matriz2D_1::~Matriz2D_1(){
			
			LiberaMemoria();
		}

/***************************************************************************//*

Metodo Público que compruev si la matriz esta vacio o no.
el metodo devuelve una variable booleana.

*//***************************************************************************/

		bool Matriz2D_1::EstaVacia() const{
			bool esta_vacia;
			esta_vacia = (matriz==NULL);

			return esta_vacia;
		}

/***************************************************************************//*

Metodo Publico que graba un valor pasado por parametro en una fila y una columna
pasadas tambien por parametro 
Se trata de un metodo void

*//***************************************************************************/

		void Matriz2D_1::PonValor (int fila, int col, TipoBase valor){
			matriz[fila][col] = valor;
		}

/***************************************************************************//*

Metodo Publico que devuelve el valor almacenado por la matriz en la posicion pasada 
como parametro.
Este metodo devuelve un dato de tipo TipoBase

*//***************************************************************************/

		TipoBase Matriz2D_1::LeeValor (int fila, int col) const{
			return matriz[fila][col];
		}

/***************************************************************************//*

Metodo Publico que se encarga de igualar todos los elementos de la matriz a un 
valor pasado por parametro.
Se trata de un metodo void

*//***************************************************************************/

		void Matriz2D_1::Asigna (TipoBase valor){
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

		int Matriz2D_1::Filas()const{
			return filas;
		}

/***************************************************************************//*

Metodo Publico que devuelve el numero de columnas que posee la matriz.
El mettodo devuelve un dato de tipo int.

*//***************************************************************************/

		int Matriz2D_1::Columnas()const {
			return columnas;
		}


/***************************************************************************//*

Funcion externa a la clase que se encarga de mostrar por pantalla los 
componentes de un objeto de tipo Matriz2D_2 pasado como parametro

*//***************************************************************************/

		void PintaMatriz (const Matriz2D_1 &matr, char * etiqueta){

			cout << endl <<etiqueta<<endl;
			for(int i = 0; i < matr.Filas(); i++){
				for(int j = 0; j < matr.Columnas(); j++){
					cout << matr.LeeValor(i,j) << " ";
				}
				cout << endl;
			}
		}



//};