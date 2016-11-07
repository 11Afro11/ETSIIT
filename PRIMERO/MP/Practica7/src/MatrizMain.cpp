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
#include "Matriz2D_2.h"

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

	MatrizDinamicaValores(matriz, filas, columnas);

	cout << "sumatriz es: "<<endl;

	//mostramos la matriz

	MuestraMatriz(matriz, filas, columnas);

	cout << "Vamos a copiar la matriz: ";

	Matriz otra_matriz;


	otra_matriz = CopiaMatriz(matriz, filas, columnas);

	//copiamos la matriz

	cout <<"Las matrices son: "<< endl;
	cout << "Original:"<<endl;
	MuestraMatriz(matriz, filas, columnas);
	cout << "Copia:"<<endl;
	MuestraMatriz(otra_matriz, filas, columnas);

	Cota cota1;
	Cota cota2;

	//creamos submatriz

	cout << "Vamos a crear una submatriz, introduzca las cotas: "<<endl;
	cin>>cota1.primero;
	cin>>cota1.segundo;
	cin>>cota2.primero;
	cin>>cota2.segundo;

	cout << "La submatriz es: "<<endl;

	Matriz submatriz;
	int f = filas;
	int c = columnas;

	submatriz = Submatriz(matriz, cota1, cota2, f, c);

	MuestraMatriz(submatriz,f, c);

	int borra;

	//borramos fila

	cout << "Vamos a borrar una fila. Introduzca la fila a borrar: ";
	cin >> borra;

	int borrada = filas;

	Matriz matrizborrada;

	matrizborrada = Borrafila(matriz,borrada,columnas,borra);

	MuestraMatriz(matrizborrada,borrada, columnas);

	//calculamos la traspuesta

	cout << "La traspuesta es: "<<endl;

	Matriz traspuesta = Traspuesta(matriz, columnas, filas);

	MuestraMatriz(traspuesta,columnas,filas);

	//invertimos las filas

	cout << "La inversa es :"<<endl;

	Matriz inversa = Inversa(matriz,filas,columnas);

	MuestraMatriz(inversa, filas, columnas);



}