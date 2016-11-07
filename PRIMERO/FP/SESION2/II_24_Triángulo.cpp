/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 24
 
El área A de un triángulo se puede calcular a partir del valor de dos de sus lados, a y
b, y del ángulo θ que éstos forman entre sí con la fórmula A =(1/2) ab sin(θ). Construid
un programa que pida al usuario el valor de los dos lados (en centímetros), el ángulo
que éstos forman (en grados), y muestre el valor del área.
 */

#include <iostream>
#include <cmath>      


using namespace std;

int main(){
  
  double lado_1;   //variable que almacena el valor del lado del triangulo
  double lado_2;   //variable que almacena el valor del otro lado del triangulo
  double angulo;   //variable que almacena el valor del ángulo del triangulo
  double area;     //variable que almacena el resultado, el valor del área
  const double PI = 3.1416;   //constante PI
  
  cout<<"Introduzca un lado del trianguilo: "; 
  cin>>lado_1;					   //pedimos por teclado los lados del triangulo y
  cout<<"\nIntroduzca otro lado del triangulo: ";  //el angulo
  cin>>lado_2;
  cout<<"\nIntroduzca el ángulo del triangulo; ";
  cin>>angulo;
  
  angulo = angulo * PI / 180;     //fórmula para convertir los angulos en radianes
  
  area = (lado_1 * lado_2 * (sin(angulo)));  //fórmula para calcular el área
  
  cout<<"\nEl área es: " <<area<<"\n\n";   //salida por  pantalla
  
  //system ("pause");
  
  return (0);	
  
  
}