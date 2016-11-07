/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 20


Declarar las variables necesarias y traducir las siguientes fórmulas a expresiones vá-
lidas del lenguaje C++.


  1+(x^2)/y
a)________
  x^3/(1+y)
  
  
b)(1+(1/3)sinh-(1/7)cosh)/2h

   ________________
c)V1+((e^x/x^2))^2
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  double var_x;    //Declaramos las variable necesarias para resolver los tres 
  double var_y;	   //apartados y tambien la variables para almacenar los resultados
  double var_h;
  double apart_a;
  double apart_b;
  double apart_c;
  
  //solicitar datos
  
  cout<<"Introduzca la variable x: ";
  cin>>var_x;
  cout<<"\nIntroduzca la variable y: ";
  cin>>var_y;
  cout<<"\nIntroduzca la variable h: ";
  cin>>var_h;
  
  apart_a = (1+((var_x * var_x)/var_y))/((var_x * var_x *var_x)/(1+var_y)); //formula del apartado a
  
  apart_b = (1 + ((sin(var_h))/3) - ((cos(var_h))/7))/(2*var_h); //formula del apartado b
  
  apart_c = sqrt(1 + (pow(((exp(var_x))/(var_x * var_x)),2)));  //formula del apartado c
  
  //salida de datos
  
  cout<<"\nEl resultado del apartado a) es: " <<apart_a<<"\n\n";
  
  cout<<"\nEl resultado del apartado b) es: " <<apart_b<<"\n\n";
  
  cout<<"\nEl resultado del apartado c) es: " <<apart_c<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
  
  