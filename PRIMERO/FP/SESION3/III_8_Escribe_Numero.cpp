/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 8

 Escribir un programa que lea un valor entero. Supondremos que el usuario introduce
siempre un entero de tres dígitos, como por ejemplo 351. Escribid en pantalla los
dígitos separados por tres espacios en blanco. Con el valor anterior la salida sería:
3 5 1

 */

#include <iostream>

using namespace std;

int main (){
    
    int numero;		//declaramos las variables que almacenaran el numero entero y separado
    int numero_1;
    int numero_2;
    int numero_3;
    int resto;

    //solicitamos datos desde teclado
    
    cout << "Introduce un numero cualquiera: ";
    cin >> numero;
    
    

    numero_1 = numero/100;	//separamos el primer numero. 351/100=3 (variable int)
    resto = numero - (numero_1 * 100);	//el resto corresponde a los dos datos restantes del numero
					//en nuestro ejemplo sería 51 (351 - 300)

    numero_2 = resto / 10;	//igual que antes separamos el segundo numero. 51/10=5 (variable int)
    resto = resto - (numero_2 * 10);	//calculamos el resto (51 - 50) lo cual nos dara el ultimo numero.

    numero_3 = resto;	//el ultimo numero es el resto;
    
    //salida de datos por pantalla
    
    cout << "el numero es: " << numero_1 << "  " << numero_2 << "  " << numero_3 <<"\n\n";

    return 0;
}