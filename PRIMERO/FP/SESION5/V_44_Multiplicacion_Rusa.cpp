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
// EJERCICIO 44
//
/*	

 El algoritmo de la multiplicación rusa es una forma distinta de calcular la multiplicación
de dos números enteros n ∗ m. Para ello este algoritmo va multiplicando por 2 el
multiplicador m y dividiendo (sin decimales) por dos el multiplicando n hasta que
n tome el valor 1 y suma todos aquellos multiplicadores cuyos multiplicandos sean
impares. Por ejemplo, para multiplicar 37 y 12 se harían las siguientes iteraciones
Iteración
    Multiplicando		Multiplicador
1   37  			12
2   18  			24
3   9   			48
4   4   			96
5   2   			192
6   1   			384


El resultado de multiplicar 37 y 12 sería la suma de los multiplicadores correspondien-
tes a los multiplicandos impares (en negrita), es decir 12+48+384=444
Cread un programa que lea dos enteros y calcule su producto con este algoritmo.

*/
/*********************************************************************/

#include <iostream>

using namespace std;

int main(){
    
    int multiplicando;		//declaramos las variables miltiplicando(n)	
    int multiplicador;		//y multiplicador (m)
    int mult_rusa = 0;		//y la variable que acumula el resultado
    
    //solicitud de datos por pantalla
    
    cout<<"\n\nDame el multiplicando: ";
    cin>>multiplicando;
    cout<<"\n\nDame el multiplicador: ";
    cin>>multiplicador;
    
    //declaramos  un bucle for con un contador i, cuya condicion es que el 
    //multiplicador sea mayor o igual que 1. el este bucle tambien se incrementa el contador
    
    while(multiplicando >= 1){
	
	//si el numero es impar, aplicando el algoritmo de la multiplicacion
	//debemos realizar la suma acumulada de multiplicador
	
	if(multiplicando % 2 != 0)
	    mult_rusa = mult_rusa + multiplicador;
	
	//dividimos el multiplicando por 2 y multiplicamos el multiplicador por 2,
	//tal y como dice el algoritmo de la multiplicacion rusa, usandolo como 
	//condicion del bucle.
	
	multiplicando = multiplicando / 2;
	multiplicador = multiplicador * 2;
	
    }
    
    //salida de datos por pantalla
    
    cout<<"\n\nEl producto es: "<<mult_rusa<<"\n\n";

    return (0);
    
}

	    