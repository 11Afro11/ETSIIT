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

int main(){
	Matriz matriz;

	int filas;
	int columnas;

	//solicitud de datos

	cout << "Cuantas filas va a tener?: "<<endl;
	cin >> filas;
	cout << endl <<"Cuantas columnas va a tener?: "<<endl;
	cin >> columnas;

	//rellenamos la matriz

	MatrizDinamicaValores_1(matriz, filas, columnas);

	cout << "su matriz es: "<<endl;

	//mostramos la matriz

	MuestraMatriz(matriz, filas, columnas);

	cout << "Vamos a copiar la matriz: ";

	Matriz otra_matriz;


	otra_matriz = CopiaMatriz_1_2(matriz, filas, columnas);

	//copiamos la matriz

	cout <<"Las matrices son: "<< endl;

	MuestraMatriz(matriz, filas, columnas);

	MuestraMatriz(otra_matriz, filas, columnas);


	cout << "Introduzca otra matriz: "<<endl;


	cout << "Cuantas filas va a tener?: "<<endl;
	cin >> filas;
	cout << endl <<"Cuantas columnas va a tener?: "<<endl;
	cin >> columnas;

	//rellenamos la matriz

	MatrizDinamicaValores_2(matriz, filas, columnas);

	cout << "su matriz es: "<<endl;

	//mostramos la matriz

	MuestraMatriz(matriz, filas, columnas);

	cout << "Vamos a copiar la matriz: ";


	otra_matriz = CopiaMatriz_2_1(matriz, filas, columnas);

	//copiamos la matriz

	cout <<"Las matrices son: "<< endl;

	MuestraMatriz(matriz, filas, columnas);

	MuestraMatriz(otra_matriz, filas, columnas);


}
