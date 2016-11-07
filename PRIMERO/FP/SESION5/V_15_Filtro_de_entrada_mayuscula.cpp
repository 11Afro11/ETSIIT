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
// EJERCICIO 15
//
/*	

 Se pide leer un carácter desde teclado, obligando al usuario a que sea una letra ma-
yúscula. Para ello, habrá que usar una estructura repetitiva do while, de forma que
si el usuario introduce un carácter que no sea una letra mayúscula, se le volverápedir otro carácter. Calculad la minúscula correspondiente e imprimidla en pantalla.
No pueden usarse las funciones tolower ni toupper de la biblioteca cctype. Si se
quiere, se puede usar como base el proyecto que resolvió el ejercicio 14 de la relación
de problemas I.
a

*/
/*********************************************************************/

#include <iostream>

using namespace std;

int main(){
  
  char mayuscula;	//variable que almacena la entrada
  char minuscula;	//variable que almacena la salida
  const char distancia = 'a'-'A'; //distancia entre mayusculas y minusculas en la tabla ASCII
  
  //solicitud de datos por el teclado
  
  
  do{	//filtro que evita que se introduzcan minusculas
    cout<<"Introduzca una letra mayuscula: ";
    cin>>mayuscula;
  }while((mayuscula >= 'a') && (mayuscula <= 'z'));
  
  //calculamos el equivalente sumandole la distancia a nuestra letra solamente
  //si la letra introducida es mayuscula
  
  while(((mayuscula >= 'a') && (mayuscula <= 'z')) || 
      ((mayuscula >= 'A') && (mayuscula <= 'Z'))){
	
	minuscula = mayuscula + distancia;	//calculamos la conversion
  
	cout<<"\nSu letra es: " <<minuscula<<"\n\n";	//salida de datos por pantalla
	
	do{	//volvemos a solicitar los datos usando el mismo filtro
	    cout<<"Introduzca una letra mayuscula: ";
	    cin>>mayuscula;
	}while((mayuscula >= 'a') && (mayuscula <= 'z'));
  
  }
  
  //system ("pause");
  
  return (0);	
  
}