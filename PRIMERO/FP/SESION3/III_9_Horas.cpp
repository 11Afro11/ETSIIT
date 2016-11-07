/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 9

 Leed desde teclado tres variables correspondientes a un número de horas, minutos
y segundos, respectivamente. Diseñar un algoritmo que calcule las horas, minutos
y segundos dentro de su rango correspondiente. Por ejemplo, dadas 10 horas, 119
minutos y 280 segundos, debería dar como resultado 12 horas, 3 minutos y 40 se-
gundos. En el caso de que nos salgan más de 24 horas, daremos también los días
correspondientes (pero ya no pasamos a ver los meses, años, etc)


Para reslver este ejercicio debemos usar divisiones utilizzando los restos y los cocientes. 
Por ejemplo para pasar de segundos a minutos debemos dividir los segundo entre 60 (segundos
en un minuto), el resto seran los segundos y el cociente se debera sumar a los minutos. En 
el casi de pasar de horas a dias deberiamos dividir entre 24 (horas en un día).
 

 */

#include <iostream>

using namespace std;

int main(){
  
  int segundos; 	//declaramos las variables para almacenar las horas, minutos y segundos
  int minutos;		//asi como dos variables para almacenar el cociente y el resto de cada división
  int horas;
  int dias = 0;
  int cociente;
  int resto;
  
  //entrada de datos por teclado
    
  cout<<"Introduzca las horas: ";
  cin>>horas;
  cout<<"\nIntroduzca los minutos: ";
  cin>>minutos;
  cout<<"\nIntroduzca los segundos: ";
  cin>>segundos;
  
  //calculamos los segundos y cuanto debemos sumar a los minutos
  
  cociente = segundos / 60;
  resto = segundos % 60;
  
  segundos = resto;
  minutos = minutos + cociente;
  
  //calculamos los minutos y cuanto debemos sumar a las horas
  
  cociente = minutos / 60;
  resto = minutos % 60;
  
  minutos = resto;
  horas = horas + cociente;
  
  //calculamos las horas y los dias
  
  cociente = horas / 24;
  resto = horas % 24;
  
  horas = resto;
  dias = dias + cociente;
  
  //salida de datos por pantalla
  
  cout<<"\nEl tiempo transcurrido es: " <<dias<<" dias "<<horas<<" horas "<<minutos<<" minutos "<<segundos<<" segundos\n\n";
  
  //system ("pause");
  
  return (0);	
  
}