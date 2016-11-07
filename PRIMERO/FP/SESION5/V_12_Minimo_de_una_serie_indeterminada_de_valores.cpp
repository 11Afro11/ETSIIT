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
// EJERCICIO 12
//
/*	

  Realizar un programa que lea reales desde teclado y calcule cuántos se han introduci-
do y cual es el mínimo de dichos valores (pueden ser positivos o negativos). Se dejará
de leer datos cuando el usuario introduzca el valor 0. Realizad la lectura de los reales
dentro de un bucle sobre una única variable llamada dato. Es importante controlar los
casos extremos, como por ejemplo, que el primer valor leído fuese ya el terminador de
entrada (en este caso, el cero).

*/
/*********************************************************************/


#include <iostream>

using namespace std;

int main(){
    
    int dato;		//declaramos la variable de entrada dato
    int minimo;		//la variable de salida
    int num_ciclos = 0;	//y un contador
    
    //solicitud de datos por teclado
    
    cout<<"\n\nDame un dato: ";		//lectura adelantada
    cin>>dato;
    minimo = dato;  //hacemos una primera asignacion dado que el primer dato
		    //que entra es el minimo
    if(dato != 0){	//filtro que prevee si el primer dato es el finalizador
    
	while(dato != 0){	//el bucle se ejecutara mientras el dato introducido no sea 0
	
	    if(dato <= minimo)	//si el dato en menos que el minimo anterior 
		minimo = dato;	//ese dato pasa a ser el minimo
	
	    num_ciclos++;	//incrementamos el contador 
	
	    cout<<"\n\nDame otro dato: ";	//volvemos a leer el dato
	    cin>>dato;
	}
    
	cout<<"\n\nSe han introducido "<<num_ciclos<<	//salida de datos por pantalla
	" numeros, y el minimo es: "<<minimo<<"\n\n";
    }
    else
	cout<<"\n\nNo se ejecuto el programa.\n\n";	//mensaje de finalizacion
							//sin ejecucion
    
    //system ("pause");
    
    return (0);
    
}