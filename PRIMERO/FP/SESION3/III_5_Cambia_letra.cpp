/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 5

 Se quiere leer un carácter letra_original desde teclado, y comprobar con una
estructura condicional si es una letra mayúscula. En dicho caso, hay que calcu-
lar la minúscula correspondiente en una variable llamada letra_convertida.
En cualquier otro caso, le asignaremos a letra_convertida el valor que
tenga letra_original. Finalmente, imprimiremos en pantalla el valor de
letra_convertida. No pueden usarse las funciones tolower ni toupper de la
biblioteca cctype.



 */

#include <iostream>

using namespace std;

int main(){
  
  char letra_original;	//variable que almacena la entrada
  char letra_convertida;	//variable que almacena la salida
  const char distancia = 'a'-'A'; //distancia entre mayusculas y minusculas en la tabla ASCII
  bool es_mayuscula; 	//variable booleana que nos indica si es mayuscula
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca una letra mayuscula: ";
  cin>>letra_original;
  
  //escribimos la condición para que sea maysucula
  
  es_mayuscula = ('A'>=letra_original) && (letra_original <= 'Z');
  
  //los casos posibles segun la condicion dada, si es_mayuscula es cierta la convertimos a minuscula
  //si e_mayuscula es falsa la dejamos como esta e imprimimos el valor en pantalla
  
  
  if(es_mayuscula){
      letra_convertida = letra_original + distancia;	//conversion a minuscula
  }
  else{
      letra_convertida = letra_original;	//no es necesaria la conversion
  }
  
  //Salida de datos por pantalla.
  
  cout<<"\nLa letra es "<<letra_convertida<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}