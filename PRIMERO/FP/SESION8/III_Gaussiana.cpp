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
// EJERCICIO 7
//
/*	

 En el ejercicio 4 de la Relación de Problemas I (página RP-I.1) se vio cómo obtener el
valor de ordenada asignado por la función gaussiana, sabiendo el valor de abscisa x.
Recordemos que esta función matemática dependía de dos parámetros μ (esperanza)
y σ (desviación).

Cread una función para calcular el valor de la función gaussiana en un punto arbitrario
leído desde teclado. Escribid un programa que haga uso de esa función.
Hacedlo de dos maneras: a) con una función que admita un sólo parámetro (x) y con
una función que admita tres parámetros (x, μ y σ).
Finalidad: Entender el ámbito de los parámetros de las funciones, el uso de constantes
globales o locales, el uso de funciones completamente parametrizadas, así como las
llamadas entre funciones. Dificultad Media.



*/
/*********************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

//funcion que calcula la gaussiana

double Gaussiana(double nu, double equis, double sigma){
    
  double gausiana;
  double exponencial;
  const double PI = 3.14159265;
  
  exponencial = exp(-0.5 * (pow(((equis - nu)/sigma),2)));
  
  gausiana = (exponencial/(sigma * (sqrt(2 * PI))));
  
  return gausiana;
  
}


int main(){
    
    double nu;			//declaracion de variables
    double equis;
    double sigma;
    
    //solicitud de datos por teclado
    
    cout<<"Introduzca el coeficiente nu: ";
    cin>>nu;
    cout<<"\nIntroduzca el coeficiente sigma: ";
    cin>>sigma;
    cout<<"\nIntroduzca el valor de abcisa: ";
    cin>>equis;
    
    
    //salida de datos por pantalla con lla mada a la funcion gaussiana
    
    cout<<"\nEl valor de la gausiana para X = "<<equis<<": " <<Gaussiana(nu, equis, sigma)<<"\n\n";
    
    return(0);
    
}
    
    
    
    
    
    