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
#include "Matriz2D_1.h"

using namespace std;

/*********************************************************************/
/*

 Construir una función que cree (reserve memoria para) una matriz de este tipo, recibien-
do el número de filas y columnas. El contenido de la matriz queda indefinido (valores
basura).


*/
/*********************************************************************/


void MatrizDinamica(Matriz &matriz, int filas, int columnas){

	

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

void MatrizDinamicaValores(Matriz &matriz, int filas, int columnas){

	

	MatrizDinamica(matriz, filas,columnas);

	cout << endl <<  "Dame los datos:";

	for(int i = 0; i < filas; i++){
		for(int j = 0; j<columnas; j++){
			cin >> matriz[i][j];
		}
	}
}

/*********************************************************************/
/*

 Construir una función que libere la memoria ocupada por una matriz de este tipo.


*/
/*********************************************************************/

void LiberaMemoria(Matriz &matriz, int filas){
	for(int i = 0; i < filas; i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}

/*********************************************************************/
/*

 Construir una función que muestre los valores guardados en la matriz.

*/
/*********************************************************************/

void MuestraMatriz(const Matriz & matriz, int filas, int columnas){

	for(int i = 0; i < filas; i++){
		for(int j = 0; j<columnas; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

/*********************************************************************/
/*

 Construir una función que reciba una matriz de ese tipo, y cree y devuelva una copia.

*/
/*********************************************************************/

Matriz CopiaMatriz(const Matriz & matrizprimera, int f, int c){
	Matriz matriz;
	int filas = f;
	int columnas = c;

	matriz = new TipoBase*[filas];

	for(int i = 0; i < filas; i++){
		matriz[i] = new int [columnas];
		memcpy(matriz[i], matrizprimera[i], sizeof(int)*(columnas));
	}

	return matriz;

}

/*********************************************************************/
/*

Construir una función que extraiga una submatriz. Como argumento de la función se
introduce desde qué fila y columna y hasta qué fila y columna se debe realizar la copia
de la matriz original. La submatriz devuelta es una nueva matriz.

*/
/*********************************************************************/

Matriz Submatriz(Matriz matrizbase, Cota f, Cota c, int & fils, int & cols){
	Matriz matriz;

	fils = (f.segundo - f.primero);
	cols = (c.segundo - c.primero);

	MatrizDinamica(matriz, fils,cols);

	int a = 0;
	int b = 0;

	for(int i = f.primero; i < f.segundo; i++){
		for(int j = c.primero; j < c.segundo; j++){
			matriz[a][b] = matrizbase[i][j];
			b++;
		}
		a++;
		b=0;
	}
	return matriz;
}

/*********************************************************************/
/*

  Construir una función que elimine una fila de una matriz. Obviamente, no se permiten
“huecos” (filas vacías). La función devuelve una nueva matriz.


*/
/*********************************************************************/


Matriz Borrafila(Matriz matriz, int & fila, int columna, int f){

	Matriz borrafila;
	MatrizDinamica(borrafila, fila-1, columna);
	int a = 0;

	for(int i = 0; i < fila; i++){
		if(i != f){
			memcpy(borrafila[a],matriz[i],sizeof(TipoBase)*columna);
			a++;
		}
	}
	fila--;

	return borrafila;
}

/*********************************************************************/
/*

 Construir una función como el anterior, pero que en vez de eliminar una fila, elimine una
columna. La función devuelve una nueva matriz.

*/
/*********************************************************************/

Matriz BorraColumna(Matriz matriz, int &columna, int c, int fila)
{
	Matriz borracolumna;
	int nueva;

	MatrizDinamica(borracolumna, fila, columna -1);

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			if(j == c){
				j = j+1;
			}
			nueva = j;

			if(j >= c){
				nueva = c-1;
			}
			borracolumna[i][nueva] = matriz[i][j];
		}
	}

	columna +=1;

	return borracolumna;
}

/*********************************************************************/
/*

 Construir una función que devuelva la traspuesta de una matriz. La matriz devuelta es
una nueva matriz.


*/
/*********************************************************************/

Matriz Traspuesta(Matriz matriz, int &columna, int &fila)
{

	Matriz traspuesta;

	MatrizDinamica(traspuesta,columna,fila);

	for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            traspuesta[i][j]= matriz[j][i];
        }
    }

    int aux;
    aux = fila;
    fila = columna;
    columna = aux;

    return traspuesta;
}

/*********************************************************************/
/*

 Construir una función que reciba una matriz y la modifique, de tal manera que “invierta”
las filas: la primera será la última, la segunda la penúltima, y así sucesivamente. La
función devuelve una nueva matriz.


*/
/*********************************************************************/


Matriz Inversa(Matriz matriz, int filas, int columna)
{
	Matriz inversa;

	MatrizDinamica(inversa, filas, columna);


	for (int f = filas -1; f >= 0 ; f--)
		
		{

			for (int c = 0; c < columna; c++){

				int f_invertida;
				f_invertida = (filas - 1) - f;

				inversa[f_invertida][c] = matriz[f][c];

			}//Fin del for de las columnas

		}// Fin del for de las filas



	return ( inversa );
}







