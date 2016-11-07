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
// EJERCICIO 1
//
/*  
 Se desea realizar un estudio sobre las calificaciones de una clase. Escribir un progra-
ma que sea capaz de realizar el estudio con un número máximo de 100 alumnos.
El programa leerá en primer lugar el número de alumnos y a continuación leeráalmacenará las calificaciones. Seguidamente pedirá el número de intervalos, n, para
realizar el estudio y finalmente calculará cuántas calificaciones hay en cada intervalo
y mostrará los resultados obtenidos.
Por ejemplo, si n = 10 los intervalos son: [0, 1), [1, 2), . . . , [9, 10]; si n = 2 los
intervalos son: [0, 5), [5, 10].
y

*/
/*********************************************************************/
#include <iostream>

using namespace std;

int main(){

    //declaracion de variables

	const int MAX = 100;
    int util;
    double num[MAX];

    int intervalo;

    //filtro de asigancion de valores a la variable tope util

    do{
		cout << "Introduzca los numeros: ";
		cin >> util;
    }while (util < 1 || util > MAX);
   
    //bucle que recoje los datos y los asigna dentro del vector
    
    for (int i=0; i < util; i++){
		cout << "nota[" << (i+1) << "] --> ";
		cin >> num[i];
    }

    //solicitud del intervalo

    cout << "\n\nDame un tintervalo: ";
    cin >> intervalo;

    //salida de los datos por pantalla mediante un bucle for

    for (int j = 0; j <= (intervalo-1); j++){

    	cout << "\n["<<num[j]<<" , "<<num[j+1]<<"]\n\n";

    }
}