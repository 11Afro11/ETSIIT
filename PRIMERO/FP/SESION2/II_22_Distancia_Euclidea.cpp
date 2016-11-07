/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 22
 
Cread un programa que lea las coordenadas de dos puntos P1 = (x1, y1 ) y P2 =
(x2 , y2) y calcule la distancia euclídea entre ellos:

              ____________________________
d(P1 , P2 ) =V(x1 − x2 )^2 + (y1 − y2 )^2

 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  double P1_x;		//declaramos las variables de las coordenadas de los puntos
  double P1_y;		//y tambien la variable en la que almacenamos la distancia
  double P2_x;		
  double P2_y;
  double distancia;
  
  //solicitamos la entrada de datos
  
  cout<<"Introduzca las coordenadas del primer punto: "; 
  cout<<"\nX: ";
  cin>>P1_x;
  cout<<"\nY: ";
  cin>>P1_y;
  
  cout<<"Introduzca las coordenadas del segundo punto: ";
  cout<<"\nX: ";
  cin>>P2_x;
  cout<<"\nY: ";
  cin>>P2_y;
  
  //formula para calcular la distancia entre dos puntos
  
  distancia = sqrt(((P1_x - P2_x) * (P1_x - P2_x)) + ((P1_y - P2_y) * (P1_y - P2_y)));
  
  //salida de datos
  
  cout<<"\nLa distancia entre los dos puntos es: " <<distancia<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
  