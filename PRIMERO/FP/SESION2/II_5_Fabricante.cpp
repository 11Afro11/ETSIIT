/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 5

. Las ganancias de un determinado producto se reparten entre el diseñador y los tres
fabricantes del mismo. Diseñar un programa que pida la ganancia total de la empresa (los ingresos realizados con la venta del producto) y diga cuanto cobran cada uno de
ellos, sabiendo que el diseñador cobra el doble que cada uno de los fabricantes. El
dato de entrada será la ganancia total a repartir. Utilizad el tipo double para todas las
variables.


 */

#include <iostream>

using namespace std;

int main(){
  
  double total;		//declaramos las variables total jefe y ofreo (obrero se refiere a los dos 
  double obrero;	//trabajadores
  double jefe;
  
  //solicitamos la estrada de datso
  
  cout<<"Introduzca el total ganado en la venta del producto: ";
  cin>>total;
  
  //cada trabajadorgana el 25% del total y el jefe el doble de cada trabajador: 50%
  obrero = total - ((75 * total)/100);
  jefe = total - ((50 * total)/100);
  
  //salida de datos
  
  cout<<"\nCada trabajador cobra " <<obrero<<"\n";
  cout<<"\nEl jefe cobra " <<jefe<<"\n\n";
  
  //system ("pause");
 
  return (0);	
  
}
  
  