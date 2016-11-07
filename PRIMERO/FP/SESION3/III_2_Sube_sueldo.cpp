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

Realizad el mismo ejercicio pero subiendo el salario un 4 % si es mayor de 65 o menor
de 35 años. Además, si también tiene un salario inferior a 300 euros, se le subirá otro
3 %.



 */

#include <iostream>

using namespace std;

int main(){
    
    int edad;		//Declaramos las variables edad y salario, y las variables logicas que nos 
    double salario;	//indican si es aplicable la subida de sueldo
    bool edad_apta;
    bool salario_minimo;
    
    //solicitud de datos por teclado
    
    cout<<"\nIntroduzca su edad:";
    cin>>edad;
    cout<<"\nIntroduzca su salario:";
    cin>>salario;
    
    edad_apta = edad > 65 || 35 > edad;	//la condicion es que tengas mas de 65 o menos de 35
    
    salario_minimo = salario < 300;	//el salario debe ser menor que 300 euros
    
    //solo aplicaremos alguna subida si se cumple la condicion de edad
    
    if(edad_apta){
	
	//primera subida si cumple la condicion de edad
	
	salario = salario + (salario*4/100);
	
	//Si tambien cumple la condicion de salario minimo aplicamos una segunda subida
	
	if(salario_minimo){
	    salario = salario + (salario*3/100);
	}
	else{
	
	    
	}
	cout<<"\nAplicada subida. Su salario es de: "<<salario<<"\n\n";	//salida de datos
    }
    else{
	cout<<"No aplicable la subida. su salario es de: "<<salario<<"\n\n";	//salida de datos
    }
    
    //system ("pause");
    
    return(0);
    
}