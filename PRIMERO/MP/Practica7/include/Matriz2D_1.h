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
#ifndef MATRIZ
#define MATRIZ
#include <cstring>

typedef int TipoBase;
typedef TipoBase **Matriz;

struct Cota{
	int primero;
	int segundo;
};

void MatrizDinamica(Matriz &matriz, int filas, int columnas);

void MatrizDinamicaValores(Matriz &matriz, int filas, int columnas);

void LiberaMemoria(Matriz &matriz, int filas);

void MuestraMatriz(const Matriz & matriz, int filas, int columnas);

Matriz CopiaMatriz(const Matriz & matrizprimera, int f, int c);

Matriz Submatriz(Matriz matrizbase, Cota f, Cota c,int &fils, int &cols);

Matriz Borrafila(Matriz matriz, int & fila,int columna, int f);

Matriz BorraColumna(Matriz matriz, int &columna, int c, int fila);

Matriz Traspuesta(Matriz matriz, int &columna, int &fila);

Matriz Inversa(Matriz matriz, int filas, int columna);

#endif