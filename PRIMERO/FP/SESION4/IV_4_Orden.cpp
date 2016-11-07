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
// EJERCICIO 4
//
/*	

 Escribid un programa en C++ para que lea tres enteros desde teclado y nos diga si
están ordenados (da igual si es de forma ascendente o descendente) o no lo están.


*/
/*********************************************************************/


#include <iostream>

using namespace std;

int main(){
    
    int numero_1;	//declaramos las variables que guardaran los datos dados por teclado
    int numero_2;	//y ina variable logica que almacena la condidion de orden
    int numero_3;
    bool ordenados;
    
    //solicitud de tatos desde taclado
    
    cout<<"\ndame un numero: ";
    cin>>numero_1;
    cout<<"\ndame otro numero: ";
    cin>>numero_2;
    cout<<"\ndame otro numero: ";
    cin>>numero_3;
    
    //la condicion para que los numero esten ordenados es que el primero sea menor o mayor que el
    //segundo y que el segundo sea menor o mayor que el tercero
    
    ordenados = ((numero_1 < numero_2) && (numero_2 < numero_3)) || 
		    ((numero_1 > numero_2) && (numero_2 > numero_3));
		    
    //si la condicion se cumple los numero estaran ordenado, si no, estaran desordenados
    //mostramos los resultados por pantalla en funcion de la condicion.
    
    if(ordenados){
	cout<<"\nLos numero estan ordenados\n\n";
    }
    else{
	cout<<"\nLos numero estan desordenados\n\n";
    }
    
    //system ("pause");
    
    return (0);
    
}