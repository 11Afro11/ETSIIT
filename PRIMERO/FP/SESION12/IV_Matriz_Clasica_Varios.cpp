/*/*******************************************
//FUNDAMENTOS DE PROGRAMACI√ìN
//GRADO EN INGENIER√çA INFORM√ÅTICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACI√ìN DE PROBLEMAS 3
//PROBLEMA N√öMERO 6
//
//
. Definir las constantes que especifican el n˙mero de filas y columnas de la matriz (su
capacidad) y leer (filtr·ndo adecuadamente) los valores de dos variables filas y
columnas que contendr·n el n˙mero de filas y columnas que se utilizar·n.
Leer los filas ◊ columnas datos de la matriz, y realizar las siguientes tareas:
a) Calcular la traspuesta de la matriz, guardando el resultado en otra matriz (siempre
que sea posible).
b) (Examen Septiembre 2011) La posiciÛn del elemento que sea el mayor de entre
los mÌnimos de cada fila. Por ejemplo, dada la matriz M (3 ◊ 4),
9 7 4 5
2 18 2 12
7 9 1 5
el m·ximo entre 4, 2 y 1 (los mÌnimos de cada fila) es 4 y se encuentra en la
posiciÛn (0,2).
c) Ver si existe un valor MaxiMin, es decir, que sea a la vez m·ximo de su fila y
mÌnimo de su columna.
d) Leer los datos de otra matriz (incluidas sus dimensiones) que tenga la misma ca-
pacidad y multiplicar ambas matrices. Guardar el resultado en otra matriz (siem-
pre que sea posible efectuar la multiplicaciÛn).


/******************************************************************
*/
#include <iostream>

using namespace std;

int main(){

	const int FILA = 100;
	const int COLUMNA = 100;
	int fila;
	int columna;
	int fila2;
	int columna2;
	int matriz[FILA][COLUMNA];
	int matrizauxiliar[FILA][COLUMNA];
	int otramatriz[FILA][COLUMNA];
	int minimo;
	int temporal;

	cout << "\n\nIntroduce el numero de filas: " ;
	cin >> fila;
	cout << "\n\nIntroduce el numero de columnas: ";
	cin >> columna;

	cout << "\n\nDame una matriz: ";

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			cin >> matriz[i][j];
		}
	} 

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			matrizauxiliar[i][j] = matriz[j][i];			
		}
	}

	cout << "\n\n";

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			cout << matrizauxiliar[i][j] << " ";
		}
		cout << "\n";
	} 

	minimo = matriz[0][0];

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < (columna-1); j++){
			if(matriz[i][j+1] <= minimo){
				minimo = matriz[i][j+1];
			}
		}
		cout << "\n\nEn la fila "<<(i+1)<<" el minimo es "<<minimo<<"\n"; 
		minimo = matriz[i+1][0];
	}

	cout <<"\n\nDame las dimensiones de otra matriz:\n";

	cout << "\n\nIntroduce el numero de filas: " ;
	cin >> fila2;
	cout << "\n\nIntroduce el numero de columnas: ";
	cin >> columna2;


if((fila == fila2) && (columna == columna2)){
	cout << "\n\nDame otra matriz: ";

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			cin >> otramatriz[i][j];
		}
	} 

	
	for (int i = 0 ; i < fila ; i++ ){
		    for (int k = 0 ; k < columna; k++ ){
		        temporal = 0 ;
		        for (int j = 0 ; j < columna ; j++ ){
		            temporal += matriz[i][j] * otramatriz[j][k];
		            matrizauxiliar[i][k] = temporal ;
		        }
		    }
	
	}
}

	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
			cout << matrizauxiliar[i][j] << " ";
		}
		cout << "\n";
	} 

}	