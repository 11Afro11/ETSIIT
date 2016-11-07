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
// EJERCICIO 10
//
/*	

 Realizar un programa que lea desde teclado un entero tope e imprima en pantalla to-
dos sus divisores propios. Para obtener los divisores, basta recorrer todos los enteros
menores que el valor introducido y comprobar si lo dividen. A continuación, mejorar el
ejercicio obligando al usuario a introducir un entero positivo, usando un filtro con un
bucle post test (do while).

*/
/*********************************************************************/


#include <iostream>

using namespace std;

int main(){
    
    int numero;			//declaramos la variable numero que 
    int recorrido = 1;		//almacena los datos de entrada,la variable
    int divisor = 0;		//divisor que guardara el dato a mostrar por pantalla
				//y un contador con la condicion para entrar en el bucle
    
    do{			//filtro para evitar introducir el 0 o numeros negativos
	cout<<"\nDame un numero positivo: ";
	cin>>numero;	
    }while(numero <= 0);
    
    //bucle que calcula los divisores del numero
    
    while(recorrido < numero){
	
	if(numero % recorrido == 0)
	    divisor++;		//incremento de la variable que almacena los divisores
	recorrido++;	//incremento del contador que regula el bucle
    }
    
    //salida de datos por pantalla
    
    cout<<"\n\nEl numero tiene "<<divisor<<" divisores\n\n";

    
    
    
    //system ("pause");
    
    return (0);
    
}