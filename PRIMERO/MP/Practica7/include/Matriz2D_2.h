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