/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 2

 Un banco presenta la siguiente oferta. Si se deposita una cantidad de euros capital
durante un año a plazo fijo, se dará un interés dado por la variable interes. Realizad
un programa que lea una cantidad capital y un interés interes desde teclado y
calcule en una variable total el dinero que se tendrá al cabo de un año, aplicando la
fórmula:
                            interes
total = capital + capital ∗ _______
                              100

 

 */

#include <iostream>

using namespace std;

int main(){
  
  double capital;   //declaramos las variables capital e intereses las cuales se le asignna valores 
  double interes;   //desde el teclado, el resultado se almacena en la variable capital.
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca el capital obtenido: ";
  cin>>capital;
  cout<<"\nIntroduzca el interes acumulado: ";
  cin>>interes;
  
  //calculamos el interes acumulado por el capital
  
  interes = (interes/100)*capital;
  
  //sumamos el interes al capital
  
  capital = capital + interes;
  
  cout<<"\nEl total acumulado es: " <<capital<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
  
  