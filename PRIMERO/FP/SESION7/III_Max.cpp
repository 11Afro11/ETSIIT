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
// SESION 7
// EJERCICIO 2
//
/*	

 Cread una funcion que calcule el maximo entre tres double. La cabecera de la fun-
cion sera la siguiente:
double Max(double primero, double segundo, double tercero)
Construid un programa principal que llame a dicha función con los parámetros actuales
que se quiera.

*/
/*********************************************************************/

#include <iostream>

using namespace std;

//funcion que calcula el maximo de 3 numeros

double Max(double primero, double segundo, double tercero){
    
    int max;
    
    if((primero > segundo) && (primero > tercero))
	max=primero;
    if((segundo > primero) && (segundo > tercero))
	max=segundo;
    if((tercero > segundo) && (tercero > primero))
	max=tercero;
    
    return max;
}

int main(){
    double primero, segundo, tercero;	//declaracion de variables
    
    cout<<"\n\nDame tres numeros:";	//solicitud de datos por teclado
    cin>>primero>>segundo>>tercero;
    
    //salida de datos por pantalla y llamada a la funcion
    
    cout<<"\n\nEl mayos de los tres numero es: "<<Max(primero, segundo, tercero);
    cout<<"\n\n";
    
    return(0);
}