

#ifndef MATRIZ
#define MATRIZ
#include <cstring>

typedef int TipoBase;
typedef TipoBase **Matriz;

struct Cota{
	int primero;
	int segundo;
};

void MatrizDinamica_1(Matriz &matriz, int filas, int columnas);

void MatrizDinamicaValores_1(Matriz &matriz, int filas, int columnas);

void MatrizDinamica_2(Matriz &matriz, int filas, int columnas);

void MatrizDinamicaValores_2(Matriz &matriz, int filas, int columnas);

Matriz CopiaMatriz_1_2(Matriz matriz2D_1, int filas, int columnas);

Matriz CopiaMatriz_2_1(Matriz matriz2D_2, int filas, int columnas);

void MuestraMatriz(const Matriz & matriz, int filas, int columnas);


#endif