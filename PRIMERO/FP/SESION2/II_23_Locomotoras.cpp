/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 23
 
 Dos locomotoras parten de puntos distintos avanzando en dirección contraria sobre
la misma vía. Se pide redactar un programa para conocer las distancias que habrán
recorrido ambas locomotoras antes de que choquen teniendo en cuenta que la primera
locomotora viaja a una velocidad constante V1 , que la segunda viaja a una velocidad
constante V2 , la fórmula que relaciona velocidad, espacio y tiempo (s = v t) y que
el momento en que se producirá el choque viene dado por la fórmula
      D
t =_________
    V1 + V2

 */


#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  double P1_x;    	//declaramos las variables para conocer las coordenadas
  double P1_y;		//de los trenes y las velocidades de cada uno.
  double P2_x;		//tambien declaramos las variables distancia, tiempo y espacio
  double P2_y;		//para almacenar los resultados.
  double distancia;
  double velocidad_1;
  double velocidad_2;
  double tiempo;
  double espacio_1;
  double espacio_2;
  
  //solicitamos la entrada de datos
  
  cout<<"Introduzca las coordenadas del primer vehículo: ";
  cout<<"\nX: ";
  cin>>P1_x;
  cout<<"\nY: ";
  cin>>P1_y;
  
  cout<<"\nAhora dime la velocidad a la que se mueve: ";
  cin>>velocidad_1;
  
  cout<<"Introduzca las coordenadas del segundo punto: ";
  cout<<"\nX: ";
  cin>>P2_x;
  cout<<"\nY: ";
  cin>>P2_y;
  
  cout<<"\nAhora dime la velocidad a la que se mueve: ";
  cin>>velocidad_2;
  
  //formula para calcular la distancia a partir de las coordenadas
  
  distancia = sqrt(((P1_x - P2_x) * (P1_x - P2_x)) + ((P1_y - P2_y) * (P1_y - P2_y)));
  
  //formula para calcular el tiempo que tardan en chocarse los dos trenes
  
  tiempo = distancia/(velocidad_1 + velocidad_2);
  
  //fórmulas para calcular el espacio recorrido por cada tren
  
  espacio_1 = velocidad_1 * tiempo;
  
  espacio_2 = velocidad_2 * tiempo;
  
  //salida de datos
  
  cout<<"\nLos trenes se encontraran al cabo de " <<tiempo<<" segundos\n";
  cout<<"\nEl primer tren habrá recorrido un espacio de " <<espacio_1<<" metros\n";
  cout<<"\nEl segundo tren habrá recorrido una distancia de "<<espacio_2<<" metros\n\n";
  
  //system ("pause");
  
  return (0);	
  
}