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
// SESION 8
// EJERCICIO 27
//
/*	

  Un número entero de n dígitos se dice que es narcisista si se puede obtener como la
suma de las potencias n-ésimas de cada uno de sus dígitos. Por ejemplo 153 y 8208
son números narcisistas porque 153 = 13 + 53 + 33 y 8208 = 84 + 24 + 04 + 84 .
Construir un programa que, dado un número entero positivo, nos indique si el número
es o no narcisista. Si se va a usar la función pow, no pueden ser ambos argumentos
enteros, por lo que forzaremos a que la base (por ejemplo) sea double, multiplicando
por 1.0.


*/
/*********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

//declaramos la funcion que nos cuenta los digitos del numero intrioducido

int CuentaDigitos(int numero){
    
    int elevar = 0;
    
    while(numero > 9){	
	numero = numero / 10;
	elevar++;
    }
    
    return elevar;
}

//funcion que comprueba si el numero es narcisista

int Narcisista(int numero){
    
    int potencia;
    int sumatoria = 0;
    int num_separado = numero;
    int elevar = CuentaDigitos(numero);
    int exponente = elevar + 1;
    
    while(elevar >= 0){
		
	potencia = pow(10, elevar);
	num_separado = numero / potencia;	
	
	sumatoria = sumatoria + (pow(num_separado, exponente));

	numero = numero % potencia;
	elevar--;
    }
    
    return sumatoria;
    
}

//funcion que compara el resultado de la anterior funcion con el valor introducido y compruebasi es 
//narcisista

bool Es_Narcisista(int numero){
    
    bool es_narcisista = false;
    
    if (numero == Narcisista(numero))
	es_narcisista = true;
    return es_narcisista;
}

int main(){
    
    int numero;	//declaracion  de variables
    
    //solicitud de datos por pantalla
    
    cout << "\n\nIntroduce un numero cualquiera: ";
    cin >> numero;
    
    //llamada a la funcion
    
    cout<<Narcisista(numero);
    
    //llamada a la funcion con comparacion
    
    if (Es_Narcisista(numero))
	cout << "\n\nEs narcisista.\n\n";
    else 
	cout << "\n\nNo es narcisista.\n\n";
    
    
    return (0);
    
}


	
    
    
    