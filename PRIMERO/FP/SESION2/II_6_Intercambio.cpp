/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 6

  Queremos realizar un programa para intercambiar los contenidos de dos variables
enteras. El programa leerá desde teclado dos variables edad_Pedro y edad_Juan
e intercambiará sus valores. A continuación, mostrará en pantalla las variables ya
modificadas. El siguiente código no funciona correctamente.
edad_Pedro = edad_Juan;
edad_Juan = edad_Pedro;
¿Por qué no funciona? Buscad una solución.



 */

#include <iostream>

using namespace std;

int main(){
  
  int edad_Pedro;		//Declaramos las variables para la edad de Juan, 
  int edad_Juan;		//la edad de Pedro y una variable auxuliar
  double edad_Vacia;
  
  //Solicitamos los datos
  
  cout<<"Introduzca la edad de Pedro: ";
  cin>>edad_Pedro;
  cout<<"\nIntroduzca la edad de Juan: ";
  cin>>edad_Juan;
  
  edad_Vacia = edad_Pedro;	//a la variable auxiliar le grabamos el valor de la edad de Pedro
  edad_Pedro = edad_Juan;	//la edad de Pedro se iguala a la edad de Juan 
  edad_Juan = edad_Vacia;	//finalmente igualamos la  edad de Juan a la variable auxiliar en
				//en la que se encontraba la edad de Pedro
  
  //salida de datos
  
  cout<<"\nLa edad de Pedro es : " <<edad_Pedro<<"\n";
  cout<<"\nLa edad de Juan es : " <<edad_Juan<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
  
  