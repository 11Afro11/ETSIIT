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
// SESIÓN 4
// EJERCICIO 25
//
/*	

. Los compiladores utilizan siempre el mismo número de bits para representar un tipo
de dato entero (este número puede variar de un compilador a otro). Por ejemplo, 32
bits para un int. Pero, realmente, no se necesitan 32 bits para representar el 6, por
ejemplo, ya que bastarían 3 bits:

6 = 1 ∗ 22 + 1 ∗ 21 + 0 ∗ 20 ≡ 110

Se pide crear un programa que lea un entero n, y calcule el mínimo número de dígitos
que se necesitan para su representación. Para simplificar los cómputos, suponed que
sólo queremos representar valores enteros positivos (incluido el cero). Consejo: se
necesitará usar el logaritmo en base 2 y obtener la parte entera de un real (se obtiene
tras el truncamiento que se produce al asignar un real a un entero)


*/
/*********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int numero;		//numero dado por teclado
    int bit;		//variable que almacena la salida

    cout<<"\nDame un numero ";		//solicitud de datos por teclado
    cin>>numero;
    
    //log 0 no existe y dara error
    
    if(numero < 0){
	cout<<"\nDebe introducir un numero positivo\n\n";
    }
    else{
    
	if(numero == 0){
	    bit = 1;
	    }
	else{
    
    //para calcular los bits necesarios para almacenar un numero entero
    //necesitamos calcular el logaritmo en base 2 de dicho numero. Como no podemos expresarlo 
    //tal cual, recurrimos a las propoedades de los logaritmos
    //        log10(x)
    //log2(x)=__________
    //         log10(2)
    
	    bit = (log10(numero))/(log10(2));
    
	    bit ++;	//siempre necesitaremos como minimo un bit para almacenar un numero
	}
	cout<<"\nSe necesitan: "<<bit<<" bits\n\n"; 	//salida de datos por pantalla
    }
    
    return(0);
}