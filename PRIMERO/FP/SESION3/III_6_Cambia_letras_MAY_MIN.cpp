/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 6

 Queremos modificar el ejercicio 5 para leer un carácter letra_original desde te-
clado y hacer lo siguiente:
• Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.
• Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.
• Si es un carácter no alfabético, almacenaremos el mismo carácter en la variable
letra_convertida




 */

#include <iostream>

using namespace std;

int main(){
  
  char letra_original;	//variable que almacena la entrada
  char letra_convertida;	//variable que almacena la salida
  const char distancia = 'a'-'A'; //distancia entre mayusculas y minusculas en la tabla ASCII
  bool es_mayuscula; 	//variable booleana que nos indica si es mayuscula
  bool es_minuscula;
  
  //solicitud de datos por el teclado
  
  cout<<"Introduzca una letra: ";
  cin>>letra_original;
  
  //escribimos la condición para que sea maysucula
  
  es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
  
  //escribimos la condiciín para que sea minuscula
  
  es_minuscula = (letra_original >= 'a') && (letra_original <= 'z'); 
  
  
  //los casos posibles segun la condicion dada, si es_mayuscula es cierta la convertimos a minuscula
  //si e_mayuscula es falsa comprabamos si es_minuscula es cierta, si lo es cambiamos a mayuscula.
  //si ninguna de las dos es cierta dejamos el valor tal cual.
  
  
  if(es_mayuscula){
      letra_convertida = letra_original + distancia;	//conversion a minuscula
  }
  else{
       if(es_minuscula){
	   
	   letra_convertida = letra_original - distancia;	//conversion a mayuscula
       }
       else{
	   
           letra_convertida = letra_original;	//no se convierte
       }
  }
  
  //Salida de datos por pantalla.
  
  cout<<"\nLa letra es "<<letra_convertida<<"\n\n";
  
  //system ("pause");
  
  return (0);	
  
}