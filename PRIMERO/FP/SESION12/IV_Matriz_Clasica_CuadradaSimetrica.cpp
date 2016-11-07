/*/*******************************************
//FUNDAMENTOS DE PROGRAMACIÓN
//GRADO EN INGENIERÍA INFORMÁTICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACIÓN DE PROBLEMAS 3
//PROBLEMA NÚMERO 6
//
//
 Para ahorrar espacio en el almacenamiento de matrices cuadradas simétricas de ta-
maño k × k se puede usar un vector con los valores de la diagonal principal y los
que están por debajo de ella. Por ejemplo, para una matriz M = {mij } el vector
correspondiente sería:
{m11 , m21 , m22, m31, m32 , m33 , m41 , · · · , mkk }
Declarar una matriz clásica double matriz[50][50] en el main, asignarle valo-
res de forma que sea cuadrada simétrica y construid el vector pedido. Haced lo mismo
pero a la inversa, es decir, construir la matriz a partir del vector. En este ejercicio, no
hay que construir ninguna clase ni función. Es un ejercicio sobre recorridos de una
matriz.


/******************************************************************
*/
#include <iostream>

using namespace std;

int main(){

	const int FILA = 50;
	const int COLUMNA = 50;
	int fila;
	int columna;
	int matriz[FILA][COLUMNA];
	int vector[COLUMNA];
	int total=0;

	//solicitud de datos de la matriz[exigimos que sea cuadrada]

	do{
		cout << "\n\nIntroduce el numero de filas: " ;
		cin >> fila;
		cout << "\n\nIntroduce el numero de columnas: ";
		cin >> columna;
	}while(fila != columna);

	//recogemos los datos de la matriz

	cout << "\n\nDame una matriz: ";

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			cin >> matriz[i][j];
		}
	} 

	//guardamos loa elemantoa por sebajo de su diagonal en un vectos

	for(int j=0; j<columna; j++){
		for(int i=j; i<fila; i++){
			vector[total] = matriz[i][j];
			total++;

		}
	}

	//imprimimos el vector

	for (int i = 0; i < total; i++){
		cout <<vector[i]<<" ";
	}


}