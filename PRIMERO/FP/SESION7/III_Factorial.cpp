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
// EJERCICIO 3
//
/*	

 Reescribir el programa construido para implementar la solucion al ejercicio 17 (calculo
del factorial y potencia) de la Relacion de Problemas II modularizando con funciones.
Presentar un menu que permita seleccionar la operacion a realizar.


*/
/*********************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

//Funcion para el calculo del factorial

long long Factorial(int numero){
    
    long long fact = 1;
    
    //bucle for que repite las instrucciones
    
    for(int i = 1; i <=numero; i++)
	fact = fact * i;
    return fact;
}

//Funcion que calcula la potencia

long long Potencia(int numero, int exponente){
    
    int producto = numero;
    
    //bucle for que repita las instrucciones
    
    for(int multiplicar = 1; multiplicar <= numero; multiplicar++)
	    producto = producto * numero;
    return producto;
}

int main(){
    int numero, exponente;	//declaramos las variables
    char condicion;

    //Menu, solicitamos la opcion que sse desea realizar
    
    cout<<"\n\nQue desea hacer, el factorial o la potencia[F/P]: ";
    cin>>condicion;
    
    //menu realizado con estructura if/else
    
    if(toupper(condicion)== 'F'){	//primera opcion, solicitud y salida de datos
	cout<<"\n\nDame un numero: ";
	cin>>numero;
	cout<<"\n\nEl factorial vale: "<<Factorial(numero)<<"\n\n";
    }
    else{
	
	
	if(toupper(condicion) == 'P'){		//segunda opcion, solicitud y salida de datos
	    cout<<"\n\nDame un numero y su exponente: ";
	    cin >> numero >> exponente;
	    cout<<"\n\nLa potencia vale: "<<Potencia(numero, exponente)<<"\n\n";
	}
	else
	    cout<<"\n\nCondicion no valida.";	//tercera opcion, salida de datos
    }
    
    return(0);
}
	
	
	