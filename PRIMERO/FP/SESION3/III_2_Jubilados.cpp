/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 2

. Cread un programa que lea el valor de la edad (dato de tipo entero) y salario (dato de
tipo real) de una persona. Subid el salario un 5 % si es un jubilado con unos ingresos
inferiores a 300 euros e imprimid el resultado por pantalla. En caso contrario imprimid
el mensaje "No es aplicable la subida". En ambos casos imprimid el salario
resultante.


 */

#include <iostream>

using namespace std;

int main(){
    
    int edad;		//Declaramos las variables edad y salario, y las variables logicas que nos 
    double salario;	//indican si es aplicable la subida de sueldo
    bool jubilado, salario_minimo;
    
    //solicitud de datos por teclado
    
    cout<<"\nIntroduzca su edad:";
    cin>>edad;
    cout<<"\nIntroduzca su salario:";
    cin>>salario;
    
    jubilado = edad >= 65;	//65 años es la edad de jubilación, la condicion es que tengas 65 o mas
    
    salario_minimo = salario < 300;	//el salario debe ser menor que 300 euros
    
    //solo se le aplicara la subida si se cumplen las dos condiciones
    
    if(jubilado && salario_minimo){
	salario = salario + (salario*5/100);
	cout<<"\nAplicada subida. Su salario es de: "<<salario<<"\n\n";	//salida de datos
    }
    else{
	cout<<"No aplicable la subida. su salario es de: "<<salario<<"\n\n";	//salida de datos
    }
    
    //system ("pause");
    
    return(0);
    
}
	
	
	
	
	