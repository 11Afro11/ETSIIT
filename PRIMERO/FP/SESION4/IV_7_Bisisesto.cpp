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
// SESIÓN 4
// EJERCICIO 7
//
/*	

 Cread un programa que acepte el número de un año e indique si es bisiesto o no.
Un año es bisiesto si es múltiplo de cuatro, pero no de cien. Excepción a la regla
anterior son los múltiplos de cuatrocientos que siempre son bisiestos. Son bisiestos:
1600,1996, 2000, 2004. No son bisiestos: 1700, 1800, 1900, 1998, 2002.



*/
/*********************************************************************/



#include <iostream>

using namespace std;

int main(){
    
    int anio;		//declaramos la variable anio, que guarda los datos de entrada y 
    bool bisiesto;	//la variable booleana bisiesto que dara la condicion
    
    
    //solicitud de datos por teclado
    
    cout<<"\nDame un año: ";
    cin>>anio;
    
    //condicion para que un año sea bisiesto
    
    bisiesto = ((anio % 4 ==0) && (anio % 100 != 0)) || (anio % 400 == 0);
    
    //imprimimos por pantalla en funcion de la condicion
    
    if(bisiesto){
	cout<<"\nEl año es bisiesto\n\n";
    }
    else{
	cout<<"\nEl año no es bisiesto\n\n";
    }
    
    //system ("pause");
    
    return (0);
    
}