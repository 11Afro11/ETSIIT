/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
// EJERCICIO 9
//
// Escribir un programa que lea una serie indefinida de números enteros de la entrada estándar
// y los copie, en orden inverso, en la salida estándar.
// - En la secuencia de entrada se pueden usar espacios, tabuladores o saltos de líneas (en
// cualquier número y combinación) para separar dos números enteros consecutivos.
// - En la secuencia de salida se separan dos enteros consecutivos con un salto de línea.
// - Usar un objeto Pila para invertir la secuencia.
//
// Fichero: CopiaEnteros-OrdenInverso.cpp
//
/***************************************************************************/

#include <iostream>
#include <stack> //incluimos la clase Pila de c++

using namespace std;



int main(){

	stack<int> p;  //declaramos un dato de tipo entero de esta clase

	int n;

	while(cin>>n){
		p.push(n);
	}

	while (! p.empty() )
	{
	    cout << p.top() << " " ;
	    p.pop();
	}

	cout << endl;

	return 0;
}