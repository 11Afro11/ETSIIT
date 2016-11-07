/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 14
. Escribid una expresión lógica que sea verdadera si una variable de tipo carácter lla-
mada letra es una letra minúscula y falso en otro caso.
Escribid una expresión lógica que sea verdadera si una variable de tipo entero llamada
edad es menor de 18 o mayor de 65.
Escribid una expresión lógica que nos informe cuando un año es bisiesto. Los años
bisiestos son aquellos que o bien son divisibles por 4 pero no por 100, o bien son
divisibles por 400.
Nota: Cuando se imprime por pantalla (con cout) una expresión lógica que es true,
se imprime 1. Si es false, se imprime un 0. En el tema 2 veremos la razón.



 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  char letra;		//Declaramos las variables letra , edad y anio, las cuales guardaran la 
  bool minuscula;	//entrada desde teclado, y las variables logicas minuscula apto y bisiesto
  int edad;		//que mostraran la veracidad de los enunciados.
  bool apto;
  int anio;
  bool bisiesto;
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca una letra minuscula: ";
  cin>>letra;
  cout<<"Introduzca una su edad: ";
  cin>>edad;
  cout<<"Introduzca el año: ";
  cin>>anio;
  
  //la variable booleana minuscula sera verdadera si la letra se encuentra entre 'a' y 'z'
  //y devolvera el valor 1, si no devolvera valor 0
  
  minuscula = (letra >= 'a') && (letra <= 'z');
   
  cout<<"\nEl primer enunciado es "<<minuscula;  //salida de datos por pantalla

  //la variable apto sera cierta si la edad esta fuera del intervalo (18 , 65)
  // en ese caso devolvera un el valor 1.
  
  apto = (18 > edad) || (edad > 65 );
  
  cout<<"\nEl segundo enunciado es "<<apto;	//salida de datos por pantalla
  
  //la variable booleana bisiento sera cierta si nuestro año es divisible por 4,
  //no es divisible por 100 pero si por 400.
  
  bisiesto = (anio % 4 == 0) && (anio % 100 != 0) || (anio % 400 == 0 );
  
  cout<<"\nEl tercer enunciado es "<<bisiesto<<"\n\n"; //salida de datos por pantalla
  
  //system ("pause");
  
  return (0);	
  
}