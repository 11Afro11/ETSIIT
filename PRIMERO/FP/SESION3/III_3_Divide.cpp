/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 3

 Realizar un programa en C++ que lea dos valores enteros desde teclado y diga si
cualquiera de ellos divide o no (de forma entera) al otro. En este problema no hace
falta decir quién divide a quién. Supondremos que los valores leídos desde teclado
son ambos distintos de cero.




 */

#include <iostream>

using namespace std;

int main(){
    
    int numero_1;	//declaramos las variables de los dos numero entero y la variable booleana de
    int numero_2;	//condición.
    bool divide;
    
    //solicitamos los datos por teclado
    
    cout<<"\nDame un numero entero: ";
    cin>>numero_1;
    cout<<"\nDame otro numero entero: ";
    cin>>numero_2;
    
    //la condición es que los numero se dividan de forma entera, bien el primero divide al seguno o
    //el segundo divide al primero.
    
    divide = (numero_1 % numero_2 == 0) || (numero_2 % numero_1 == 0);
    
    //mostramos los casos que ocurren dependiendo del resultado de la condicion dada
    
    if(divide){
	cout<<"\nLos numeros se dividen\n\n";	//salida de datos
    }
    else{
	cout<<"\nLos numeros no se dividen\n\n";	//salida de datos
    }
    
    return (0);
    
    //system ("pause");
    
}
   
    