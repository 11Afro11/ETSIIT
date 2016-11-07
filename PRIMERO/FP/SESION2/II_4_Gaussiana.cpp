/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 4

 Realizar un programa que lea los coeficientes reales μ y σ de una función gaussiana
(ver definición abajo). A continuación el programa leerá un valor de abscisa x y se
imprimirá el valor que toma la función en x.El parámetro μ se conoce como esperanza o 
media y σ como desviación típica (meany standard deviation en inglés). Para definir la 
función matemática e usad la función exp de la biblioteca cmath. En la misma biblioteca 
está la función sqrt para calcular la raíz cuadrada. Para elevar un número al cuadrado se puede usar la función pow,

 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  double nu;		//declaramos las variable nu, sigma y equis que son los parametros que
  double sigma;		//se introducen desde el teclado, y las variables gausiana y exponencial
  double equis;		//para almacenar los valores y la variable constante pi que usaremos 
  double gausiana;	//a continuacion
  double exponencial;
  const double PI = 3.14159265;
  
  //solicitud de datos
  
  cout<<"Introduzca el coeficiente nu: ";
  cin>>nu;
  cout<<"\nIntroduzca el coeficiente sigma: ";
  cin>>sigma;
  cout<<"\nIntroduzca el valor de abcisa: ";
  cin>>equis;
  
  //calculamos la exponencial al margen de la gausiana para facilitar el trabajo
  
  exponencial = exp(-0.5 * (pow(((equis - nu)/sigma),2)));
  
  //calculamos la gaussiana
  
  gausiana = (exponencial/(sigma * (sqrt(2 * PI))));
  
  //mostramos los resultados
  
  cout<<"\nEl valor de la gausiana para X = "<<equis<<": " <<gausiana<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
  
  