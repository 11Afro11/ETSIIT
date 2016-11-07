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
// EJERCICIO 3
//
/*	

Escribir un programa que lea un número indeterminado de caracteres (la lectura ter-
mina cuando se introduce un *) y muestre el número total de apariciones cada letra.
a) Para poder leer un espacio en blanco no puede emplear cin >> caracter,
sino caracter = cin.get(). Cada vez que se ejecute cin.get() el com-
pilador lee un carácter (incluido el espacio en blanco) desde la entrada de datos
por defecto.
b) Para el cómputo se consideran iguales una letra y la mayúscula corespondiente.
c) No se contabilizan dígitos, separadores u otros caracteres.
*/
/*********************************************************************/
#include <iostream>

using namespace std;

int main(){

	//declaramos las variables

	const int MAX = 50;		//variable constante que nos indica el tamaño del vector
    char util;				//variable que se introduce por taclado
    double num[MAX];		//vector
    int  i = 0;
    int cuentaletras=0;

    //bucle while que lee los datos y asigna los valores del vector

    while(util != '#'){
    	cin >> util;
    	num[i] = util;
    	i++;
    }

    //bucle for que recorre el vector y comprueba la igualdad de sus componentes

    for(int j=0; j<i; j++){
    	for(int k=1; k<i; k++){
    		if(num[j]==num[k]){
    			num[k]=num[k+1];
    			cuentaletras++;
    		}

    	}

    	//salida de dalos por pantalla

    	cout << "\n\n"<<num[j]<<" "<<cuentaletras<<"\n\n";
    	cuentaletras = 0;
    }
}