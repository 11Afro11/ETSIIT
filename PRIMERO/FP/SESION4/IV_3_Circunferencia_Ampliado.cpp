/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGÁN
//
// SESIÓN 4
// EJERCICIO 3
//
/*	

 Cread un programa que nos pida la longitud del radio, calcule el área del círculo y
la longitud de la circunferencia correspondientes, y nos muestre los resultados en
pantalla. Recordad que:
 long. circunf = 2πr
 área circ = πr2
 
*/
/*********************************************************************/



#include <iostream>

using namespace std;

int main(){
  
  double radio;		//declaramos la variables radio, a la cual se le asignaran valores de entrada 
  double longitud;	//y las variables longitud en las que se guardaran los resultados 
  double area;
  const double PI = 3.1416;  //Tambien la constante PI
  
  //solicitud de datos desde teclado
  
  cout<<"Introduzca la longitud del radio: ";
  cin>>radio;
  
  if(radio > 0){
  
  //calculo del área 
  
	area = PI * radio* radio;
  
  //calculo de la longitud 
  
	longitud = 2 * PI * radio;
  
  //salida de datos por pantalla
  
	cout<<"\nEl area es: " <<area<<"\n";
	cout<<"\nLa longitud es: " <<longitud<<"\n\n";
	
  }
  else {
      cout<<"\n\nRadio no valido\n\n";
  }
  

  
  //system ("pause");
  
  return (0);	
  
  
}