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
// EJERCICIO 31
//
/*	
 Vamos a modificar el ejercicio 3 de la siguiente forma. Queremos leer dos valores
enteros desde teclado y, en el caso de que uno cualquiera de ellos divida al otro, el
programa nos debe decir quién divide a quién.

    a) En primer lugar, resolved el ejercicio mezclando entradas, cómputos y salidas de
	resultados
    b) En segundo lugar, se pide resolver el ejercicio sin mezclar cálculos con entradas
	y salidas. Para ello, se ofrecen varias alternativas. ¿Cual sería la mejor? Escoged
	una e implementar la solución.
I )
 Utilizar un variable de tipo string de la forma siguiente:
string quien_divide;
.............
    if (a%b==0)
    quien_divide = "b divide a a" ;
.............
    if (quien_divide == "b divide a a")
    cout << b << " divide a " << a;
    Nota. Para poder usar el operador de comparación == entre dos string,
    hay que incluir la biblioteca string.
    Si se opta por esta alternativa, el suspenso está garantizado. ¿Por qué?
    
II ) Utilizar dos variables lógicas de la forma siguiente:
bool a_divide_b, b_divide_a;
.............
    if (a%b==0)
    a_divide_b = true;
.............
    if (a_divide_b)
    cout << a << "divide a " << b;
III )
 Detectamos si se dividen o no y usamos otras dos variables que me indiquen
quien es el dividendo y quien el divisor:

    bool se_dividen;
    int Divdo, Divsor;
.............
    if (a%b==0){
    Divdo = a;
.............
    if (se_dividen)
    cout << Dvsor << " divide a " << Dvdo;

*/
/*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main(){
    
    //apartado a
/*   
    int numero_1;
    int numero_2;
    bool uno_dos;
    bool dos_uno;
    bool no_dividen;

    
    
   
    cout<<"\nDame un numero entero: ";
    cin>>numero_1;
    cout<<"\nDame un numero entero: ";
    cin>>numero_2;
    
    no_dividen = (numero_1 == 0) || (numero_2 == 0);
    
    uno_dos = numero_2 % numero_1 == 0;
    dos_uno = numero_1 % numero_2 == 0;
    
    if(no_dividen){
	cout<<"Los numero no se pueden dividir";
    }
    if(uno_dos){
	cout<<"\n\n"<<numero_1<<" divide a "<<numero_2;
    }
     if(dos_uno){
	cout<<"\n\n"<<numero_2<<" divide a "<<numero_1;
    }
 
*/


    int numero_a;
    int numero_b;
    
    
    //apartado b
    
/*  char quien_divide [25];
    
    
    cout<<"\nDame el numero a: ";
    cin>>numero_a;
    cout<<"\nDame el numero b: ";
    cin>>numero_b;
    
    if(numero_a % numero_b == 0){
	quien_divide == "b divide a a";
    }
    else{
	if(numero_b % numero_a == 0){
	    quien_divide == "a divide a b";
	}
	else{ 
	    quien_divide == "los numero no se dividen";
	}
    
    
    cout<<"\n\n"<<quien_divide<<"\n\n";
    
    */

//apartado c

    bool se_dividen;
    int divdo , divor;
    
    cout<<"\nDame el numero a: ";
    cin>>numero_a;
    cout<<"\nDame el numero b: ";
    cin>>numero_b;
    
    if((numero_a == 0) || (numero_b == 0)){
	cout<<"\n\nLos numero no se pueden dividir\n\n";
    }
    else{
    
	se_dividen = (numero_b % numero_a == 0) || (numero_a % numero_b == 0);
    
	if(numero_a % numero_b == 0){
	
	    divdo = numero_a;
	    divor = numero_b;
	
	}
	else if(numero_b % numero_a == 0){
	    divdo = numero_b;
	    divor = numero_a;
	
	if(se_dividen){
	
	    cout<<"\n\n"<<divor<<" divide a "<<divdo<<"\n\n";
	
	}
	else{
	    cout<<"\n\nNo se dividen\n\n";
	}
	
    
	
	}
    
    return (0);
    }
    
 

    
    //system ("pause");
    
    return (0);
    
}