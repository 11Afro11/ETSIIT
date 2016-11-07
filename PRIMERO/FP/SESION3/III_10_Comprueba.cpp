/*

Fundamentos de la Progración

Francisco Javier Fuentes Barragán

1ºC

Sesión 3

Ejercicio 10


 Indicar si se produce un problema de precisión o de desbordamiento en los siguientes
ejemplos indicando cuál sería el resultado final de las operaciones.



 */


#include <iostream>

using namespace std;

int main(){
    
    int resultado, entero1, entero2;		//no se produce desbordamiento ni error de aproximacion
   
    entero1 = 123456789;
    entero2 = 123456780;
    
    resultado = entero1 * entero2;
    
    
    cout<<"\nEl resultado del apartado A es: "<<resultado<<"\n\n";
    
    double resultado1, real1, real2;	//no se produce desbordamiento ni error de aproximacion
   
    real1 = 123.1;
    real2 = 124.2;
    
    resultado1 = real1 * real2;
    
    
    cout<<"\nEl resultado del apartado B es: "<<resultado1<<"\n\n";
    
    
    double resultado2, real11, real21;	//si se produce error de aproximación y desbordamiento
   
    real11 = 123456789.1;
    real21 = 123456789.2;
    
    resultado2 = real11 * real21;
    
    
    cout<<"\nEl resultado del apartado C es: "<<resultado2<<"\n\n";
    
    double real, otro_real;	//se produce errosr de aproximacion y desbordamiento
   
    real = 2e34;
    
    otro_real = real + 1;
    otro_real = otro_real - real;
    
    cout<<"\nEl resultado del apartado D es: "<<otro_real<<"\n\n";
    
    
    //system ("pause");
    
    return (0);
    
}