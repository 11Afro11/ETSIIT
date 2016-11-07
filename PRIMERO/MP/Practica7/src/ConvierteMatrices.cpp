
// METODOLOGÍA DE LA PROGRANACIÓN
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 7
//
/*	

 Supongamos que para definir matrices bidimensionales dinámicas de datos de tipo
TipoBase usamos una estructura como la que aparece en la figura 22 (tipo Matriz2D_1,
filas independientes).
Nota: Recuerde que los módulos que procesan estructuras de este tipo necesitan recibir como
parámetros el número de filas y columnas de la matriz.


*/
/*********************************************************************/

#include <iostream>
#include "CopiaMatrices.h"

using namespace std;

void MatrizDinamica_1(Matriz &matriz, int filas, int columnas){

	

	if(filas != 0 && columnas!=0){
		matriz = new TipoBase *[filas];
		for(int i = 0; i < filas; i++){
			matriz[i] = new TipoBase [columnas];
			
		}
	}
}

/*********************************************************************/
/*

 Construir una función que cree una matriz (como el anterior) pero además lea del teclado
los valores y los copie en la matriz. La matriz se rellena completamente.


*/
/*********************************************************************/

void MatrizDinamicaValores_1(Matriz &matriz, int filas, int columnas){

	

	MatrizDinamica_1(matriz, filas,columnas);

	cout << endl <<  "Dame los datos:";

	for(int i = 0; i < filas; i++){
		for(int j = 0; j<columnas; j++){
			cin >> matriz[i][j];
		}
	}
}


void MatrizDinamica_2(Matriz &matriz, int filas, int columnas){

	

	if(filas != 0 && columnas!=0){
		matriz = new TipoBase * [filas];
		matriz[0] = new TipoBase [filas*columnas];
		for(int i = 1; i < filas; i++){
			matriz[i] = matriz[i - 1]+columnas;
		}
	}
}

/*********************************************************************/
/*

 Construir una función que cree una matriz (como el anterior) pero además lea del teclado
los valores y los copie en la matriz. La matriz se rellena completamente.


*/
/*********************************************************************/

void MatrizDinamicaValores_2(Matriz &matriz, int filas, int columnas){

	

	MatrizDinamica_2(matriz, filas,columnas);

	cout << endl <<  "Dame los datos:";

	for(int i = 0; i < filas; i++){
		for(int j = 0; j<columnas; j++){
			cin >> matriz[i][j];
		}
	}
}


Matriz CopiaMatriz_1_2(Matriz matriz2D_1, int filas, int columnas){
	Matriz matriz2D_2;

	MatrizDinamica_2(matriz2D_2, filas, columnas);

	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz2D_2[i][j] = matriz2D_1[i][j];
		}
	}

	return matriz2D_2;
}


Matriz CopiaMatriz_2_1(Matriz matriz2D_2, int filas, int columnas){
	Matriz matriz2D_1;

	MatrizDinamica_2(matriz2D_1, filas, columnas);

	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			matriz2D_1[i][j] = matriz2D_2[i][j];
		}
	}

	return matriz2D_1;
}

void MuestraMatriz(const Matriz & matriz, int filas, int columnas){

	for(int i = 0; i < filas; i++){
		for(int j = 0; j<columnas; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}