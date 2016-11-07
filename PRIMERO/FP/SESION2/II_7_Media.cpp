/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 2

Ejercicio 7

 Redactar un algoritmo para calcular la media aritmética muestral y la desviación es-
tándar (o típica) muestral de las alturas de tres personas. Éstos valores serán reales
(de tipo double). Para resolver este pro-
blema es necesario usar la función sqrt (raíz cuadrada) que se encuentra en la bi-
blioteca cmath.


 */

#include <iostream>
#include <cmath>

using namespace std;

int main(){
  
  double dato1;		//declaramos las variables de las alturas de cada persona 
  double dato2;		//asi como variables para almacenar la media y la desviación típica (desvio)
  double dato3;
  double media;
  double desvio;
  double sumatoria;
  
  //recogemos los datos
  
  cout<<"Introduzca el primer dato: ";
  cin>>dato1;
  cout<<"\nIntroduzca el segundo dato: ";
  cin>>dato2;
  cout<<"\nIntroduzca el tercer dato: ";
  cin>>dato3;
  
  //calculamos la media aritmetica de las 3 alturas 
  
  media = (dato1 + dato2 + dato3)/3;
  
  //calculamos la sumatoria que se encuentrra dentro de la desviación típica fuera pars 
  //simplificar el trabajo
  
  sumatoria = (pow((dato1 - media),2)) + (pow((dato2 - media),2)) + (pow((dato3 - media),2));
  
  //calculamos la deviacion típica
  
  desvio = sqrt(sumatoria/3);
  
  //salida de dotos
  
  cout<<"\nLa media es: " <<media<<"\n";
  cout<<"\nLa desviación típica es: " <<desvio<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}
  
  