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
// EJERCICIO 2
//
/*  
 Escribir un programa que lea un número indeterminado de números positivos (termina
la lectura cuando se introduce un negativo) aunque nunca leerá más de 50. Conforme
los va leyendo, los va almacenando en un vector.
A continuación elimina del vector los valores repetidos, dejando una sola copia. No se
dejan huecos en el vector y todos los números quedan agrupados en las posiciones
más bajas del vector.
*/
/*********************************************************************/
#include <iostream>

using namespace std;

int main(){
    //declaracion de variables
    const int MAX = 50;
    int util;
    double num[MAX];
    int  i = 0;

    //bucle de lectura con asignacion de los valores del vector

    while(util != -1){
    	cin >> util;
    	num[i] = util;
    	i++;
    }

    //bucle que comprueba el vector y borra los valores repetidos

    for(int j=0; j<i; j++){
    	for(int k=1; k<i; k++){
    		if(num[j]==num[k])
    			num[k]=num[k+1];

    	}
    }

    //bucle que muestra por pantalla los elementos del vectos

    for(int h=0; h<i; h++){
    	cout << " "<<num[h]<<" ";
    }
}