/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 10
// EJERCICIO 4
//
/*	
 Escribir un programa que lea un número indeterminado de caracteres (la lectura ter-
mina cuando se introduce un *) y los guarde en un vector. Finalmente, nos dirá si el
vector es un palíndromo, es decir, que se lee igual de izquierda a derecha que de
derecha a izquierda. Por ejemplo, {’a’,’b’,’b’,’a’} sería un palíndromo.

*/
/*********************************************************************/
#include <iostream>

using namespace std;

int main(){

	//declaracion de variables

	const int TAMANIO = 50;

	int contador = 0;

	char car[TAMANIO];

	char caracter;

	bool es_palindromo = true;

	int i = 0;

	cout << "\n\nIntroduce los caracteres: ";

	caracter = cin.get();

	//bucle de lectura

	while(caracter != '#'){
		car[i]=caracter;
		caracter = cin.get();
		contador++;
		i++;

	}

	//bucle que comprueba si es un palindromo

	for(int j = 0; j <= contador; j++){

		for(int k = (contador - 1); k>=0; k--){

			if(car[j] != car[k])
				es_palindromo = false;

		}

	}

	//salida de datos por pantalla con la condicion de que sea un palindromo o no 

	if(es_palindromo)
		cout << "\n\nEs un palindromo\n\n";
	else
		cout << "\n\nNO es un palindromo\n\n";



} 