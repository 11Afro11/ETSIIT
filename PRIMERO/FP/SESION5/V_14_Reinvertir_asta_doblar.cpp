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
// SESIÓN 5
// EJERCICIO 14
//
/*	

  Sobre el mismo ejercicio del capital y los intereses, construid un programa para cal-
cular cuantos años han de pasar hasta llegar a doblar, como mínimo, el capital inicial.
Los datos que han de leerse desde teclado son el capital inicial y el interés anual.

*/
/*********************************************************************/

#include <iostream>

using namespace std;

int main(){
  
  double capital;   //declaramos las variables capital e intereses las cuales se le asignna valores 
  double interes;   //desde el teclado, el resultado se almacena en la variable capital.
  int anio = 0;
  double capital_inicial;
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca el capital obtenido: ";
  cin>>capital;
  
  do{		//filtro para el porcenttaje
  
    cout<<"\nIntroduzca el interes acumulado: ";
    cin>>interes;
  }while((interes < 0) && (interes > 100));
  
  //calculamos el interes acumulado por el capital
  
  interes = (interes/100)*capital;
  capital_inicial = capital;
  
  while(capital <= 2 * capital_inicial){	//calculamos el interes acumulado por el capital astaa doblar el capital

    //sumamos el interes al capital
  
    capital = capital + interes;
    
    anio++;
  
  }
  
  //salida de datos por pantalla
  
  cout<<"\nSe necesitan "<<anio<<" años para doblar la inversion.\n\n";
  
  //system ("pause");
  
  return (0);	
  
}