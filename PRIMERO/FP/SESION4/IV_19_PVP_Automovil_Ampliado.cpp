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
// EJERCICIO 19
//
/*	

. El precio final de un automóvil para un comprador es la suma total del costo del vehícu-
lo, del porcentaje de ganancia de dicho vendedor y del I.V.A. Diseñar un algoritmo para
obtener el precio final de un automóvil sabiendo que el porcentaje de ganancia de este
vendedor es del 20 % y el I.V.A. aplicable es del 16 %.

*/
/*********************************************************************/




#include <iostream>

using namespace std;

int main(){
  
  double precio;    //declaramos las variables precio vendedor e iva
  double vendedor;
  double iva;
  
  //solicitamos los datos
  
  cout<<"Introduzca el precio del coche: ";
  cin>>precio;
  
  if(precio <= 0){
      cout<<"\nUsted no ha incluido el precio\n\n";
  }
  else{
  
	vendedor = (precio * 20)/100; //el vendedor se lleva el 20%
	iva = (precio *16)/100;  //el iva aumenta el precio del coche en un 16%
	precio = precio + vendedor + iva;  //precio final del coche sumando los porcentajes
  
  //salida de datos
  
	cout<<"\nEl total precio final es: " <<precio<<"\n\n";
  }
  
  //system ("pause");
  
  return (0);	
  
  
}