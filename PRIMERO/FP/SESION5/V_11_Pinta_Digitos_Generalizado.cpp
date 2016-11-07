/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGÁN
//
// SESIÓN 5
// EJERCICIO 11
//
/*	

  En el ejercicio 8 de la Relación de Problemas I se pedía escribir un programa que le-
yese un valor entero de tres dígitos e imprimiese los dígitos separados por un espacio
en blanco. Haced lo mismo pero para un número entero arbitrario.
Por ejemplo, si el número es 3519, la salida sería:
3 5 1 9
En este ejercicio se pueden mezclar entradas y salidas con cómputos.


*/
/*********************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

int main (){
    
    int numero;		//variable de entrada
    int potencia;	//variable que efectuara las divisiones necesarias
    int num_separado;	//variable que almacena la salida
    int elevar = 0;	//variable a la que elevaremos 10 para realizar la division

    //solicitamos datos desde teclado
    cout << "Introduce un numero cualquiera: ";
    cin >> numero;
    
    
    num_separado = numero;		//guardamos el valor entrado por teclado
				//para no perder la asignacion de la variable
				
				
    while(num_separado > 9){		//calculamos el numero de digitos del numero introducido	
	num_separado = num_separado / 10;
	elevar++;
    }
    
    //salida de datos por pantalla
    
    cout << "\n\nel numero es: ";
        
    
    while(elevar >= 0){		//La condicion para que se para el bucle es que el numero al que elevamos 
				//10 llegue a 0, es decir, que dividamos por uno, lo que guardara el ultimo
				//numero
	potencia = pow(10, elevar);		//inicializamos la variable potencia
	num_separado = numero / potencia;	//calculamos el primer numero	
	cout<<"  "<<num_separado<< "  ";	//salida de los numero por pantalla
	numero = numero % potencia;		//nos aseguramos de que lo siguente que se divida sea el resto
	elevar--;	//reducimos el exponente	
    }
    
    
    
    cout<<"\n\n";
    

    return 0;
}