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
    int otro_elevar = 0;
    int sumatoria_1;
    int tope;

    
    //solicitamos datos desde teclado
    cout << "\n\nIntroduce un numero cualquiera: ";
    cin >> numero;
    cout << "\n\nIntroduce un tope de interacciones: ";
    cin>>tope;
    cout<<"\n\n";
    
    
    num_separado = numero;		//guardamos el valor entrado por teclado
					//para no perder la asignacion de la variable
				
    for(int k = 1; k <= tope; k++){
	
	num_separado = numero;
	sumatoria_1 = 0;
					
	while(num_separado > 9){		//calculamos el numero de digitos del numero introducido	
	    num_separado = num_separado / 10;
	    elevar++;
	}
     
	while(elevar >= 0){		//La condicion para que se para el bucle es que el numero al que elevamos 
					//10 llegue a 0, es decir, que dividamos por uno, lo que guardara el ultimo
					//numero
	    potencia = pow(10, elevar);		//inicializamos la variable potencia
	    num_separado = numero / potencia;	//calculamos el primer numero	
	    
	    sumatoria_1 = sumatoria_1 + (pow(num_separado, 2));
	

	    numero = numero % potencia;		//nos aseguramos de que lo siguente que se divida sea el resto
	    elevar--;				//reducimos el exponente
	}
	cout<<"la sumatoria en la "<<k<<"º interaccion vale: "<<sumatoria_1<<"\n";
	numero = sumatoria_1;
	elevar = 0;
    }
    
    if(sumatoria_1 == 1)
	cout << "\n\nEl numero es feliz en "<<tope<<" interacciones";
    else
	cout << "\n\nEl numero no es feliz en "<<tope<<" interacciones";
    
    cout<<"\n\n";
    

    return 0;
}