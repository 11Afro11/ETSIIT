/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 21

. Cread un programa que lea un valor de temperatura expresada en grados Celsius y la
transforme en grados Fahrenheit. Para ello, debe considerar la fórmula siguiente:
Grados Fahrenheit = (Grados Celsius * 180 / 100) + 32

 */

#include <iostream>

using namespace std;

int main(){
  
  double celsius;  //declaramos las variables celsius y farenhait
  double farenheit;
  
  //solicitamos la entrada de datos
  
  cout<<"Introduzca la temperatura en grados celsius: ";
  cin>>celsius;
  
  farenheit = (celsius *180/100) + 32;	//formula para pasar de celsius a farenhait
  
  //salida de datos
  
  cout<<"\nLa temperatura es de: " <<farenheit<<" grados farenhait\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
   