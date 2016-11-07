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
// EJERCICIO 25
//
/*	

 Reescribir el programa construido para implementar la solución al ejercicio 48 (Nú-
mero aureo) de la Relación de Problemas II modularizando con funciones.


*/
/*********************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

//funcion que calcula el numero apriximado de la funcion de fibonacci

int Aureo(double landa){
    
    const double AUREO = (1+(sqrt(5))/2);
    double anterior_1 = 1;
    double anterior_2 = 0;
    double fibonacci;
    double compara;
    int n = 0;
    
    fibonacci = 0;
    
    compara = AUREO - fibonacci;
    
    while(compara >= landa){
	n++;
	
	if(n==1)
	    fibonacci = 1;
	else{
	    fibonacci = anterior_1 + anterior_2;
	    
	}
	compara = AUREO - fibonacci;
	anterior_2 = anterior_1;
	anterior_1 = fibonacci;
    }
    
   return n;
}

int main(){
    
    double landa;	//declaramos las variables
    
    //solicitud de datos por teclado
    
    cout << "\n\n Dame un margen de error: ";
    cin >> landa;
    
    //salida de datos por pantallla con llamada a la funcion
    
    cout <<"\n\nPara un valor de "<<landa<<" el valor de salida es: "<<Aureo(landa)<<"\n\n";
    
    return(0);
}
    
    
    