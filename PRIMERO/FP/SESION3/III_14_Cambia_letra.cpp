/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 14

 Diseñar un programa que lea un carácter (supondremos que el usuario introduce una
mayúscula), lo pase a minúscula y lo imprima en pantalla. Hacedlo sin usar las fun-
ciones toupper ni tolower de la biblioteca cctype. Para ello, debe considerarse
la equivalencia en C++ entre los tipos enteros y caracteres.


 */

#include <iostream>

using namespace std;

int main(){
  
  char mayuscula;	//variable que almacena la entrada
  char minuscula;	//variable que almacena la salida
  const char distancia = 'a'-'A'; //distancia entre mayusculas y minusculas en la tabla ASCII
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca una letra mayuscula: ";
  cin>>mayuscula;
  
  //calculamos el equivalente sumandole la distancia a nuestra letra
  
  minuscula = mayuscula + distancia;
  
  cout<<"\nSu letra es: " <<minuscula<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}