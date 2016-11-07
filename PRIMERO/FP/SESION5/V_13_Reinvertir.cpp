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
// EJERCICIO 13
//
/*	

 Modifiquemos el ejercicio 2 del capital y los intereses de la primera relación. Supon-
gamos ahora que se quiere reinvertir todo el dinero obtenido (el original C más los
intereses producidos) en otro plazo fijo a un año. Y así, sucesivamente. Construid un
programa para que lea el capital, el interés y un número de años N , y calcule e im-
prima todo el dinero obtenido durante cada uno de los N años, suponiendo que todo
lo ganado (incluido el capital original C) se reinvierte a plazo fijo durante el siguiente
año. El programa debe mostrar una salida del tipo:
Total en el año número 1 = 240
Total en el año número 2 = 288
Total en el año número 3 = 345.6
......................
*/
/*********************************************************************/

#include <iostream>

using namespace std;

int main(){
  
  double capital;   //declaramos las variables capital e intereses las cuales se le asignna valores 
  double interes;   //desde el teclado, el resultado se almacena en la variable capital.
  int anio;	    //y la variable anio que dara la condicion para repetir las operaciones
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca el capital obtenido: ";
  cin>>capital;
  
  do{		//filtro para el porcenttaje
  
    cout<<"\nIntroduzca el interes acumulado: ";
    cin>>interes;
  }while((interes < 0) && (interes > 100);
  
  //introducimos los años
  
  cout<<"\n\nIntroduza el numero de años que tendra el dinero: ";
  cin>>anio;
    
  //calculamos el interes acumulado por el capital
  
  interes = (interes/100)*capital;
  
  for(int i = 0; i <= anio; i++){	//bucle for que declara un contador condicionado

  
    //sumamos el interes al capital
  
    capital = capital + interes;
    
    //salida de datos por pantalla
  
    cout<<"\nEl total acumulado en el año numero "<<i<<" es: " <<capital<<"\n\n";
  }
  
  //system ("pause");
  
  return (0);	
  
}