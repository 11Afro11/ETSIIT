/*/*******************************************
//FUNDAMENTOS DE PROGRAMACI�N
//GRADO EN INGENIER�A INFORM�TICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACI�N DE PROBLEMAS 3
//PROBLEMA N�MERO 17
//
//
Escribir un programa que lea los valores de dos enteros, n y k y calcule, almacene y
muestre por pantalla los k primeros t�rminos de la sucesi�n de Fibonacci de orden n.
Para almacenar los enteros, se usar� un vector de enteros.
La sucesi�n de Fibonacci de orden n es una secuencia de n�meros en la que los
dos primeros son el 1 y el 1. A partir del tercero, los elementos se calculan como la
suma de los n anteriores, si ya hay n elementos disponibles, o la suma de todos los
anteriores si hay menos de n elementos disponibles.

El programa debe definir una clase llamada Fibonacci. Al constructor se le pasar�
como par�metro el valor de n y la clase tendr� m�todos para observar el valor de n y
tres m�todos:
 void CalculaPrimeros(int tope) para que calcule los tope primeros
elementos de la sucesi�n.
 int TotalCalculados() que devuelva cu�ntos elementos hay actualmente
almacenados (el valor tope del m�todo anterior)
 int Elemento(int indice) para que devuelva el elemento indice-�simo
de la sucesi�n. 
/******************************************************************
*/
#include <iostream>   
#include <iomanip>    
#include <string>   

using namespace std; 

class Fibonacci {
	
private:

	static const int TAMANIO = 100;
	int vector_privado[TAMANIO];
	int total_utilizados;
	int n;
		
public:
	Fibonacci(int orden) 
		: total_utilizados (0) 
	{
		n = orden;		
	}
	
	//Para calcular los tope primeros elementos de la sucesi�n.
	void CalculaPrimeros(int tope) {
		
		vector_privado[0]=1;
		vector_privado[1]=1;
		total_utilizados = 2;
		
		int termino_a_sumar;
		int pos;
		int intervalo;
		
		for(int i=1; i<tope; i++) {
			
			pos = i;
			termino_a_sumar = 0;
			intervalo = (i - n) +1;
			if(intervalo < 0) {
				
				intervalo = 0;
				
			}
			for(pos; pos >=intervalo; pos--) {
				
				termino_a_sumar += vector_privado[pos];
			
			}
			
			vector_privado[i+1] = termino_a_sumar;
			total_utilizados++;
			
			}
		
	}
	
	//Devuelve cuantos elementos hay actualmente almacenados.
	//(El valor tope del m�todo anterior)
	int TotalCalculados() {
		
		return (total_utilizados -1 );
		
	}
	
	//Devuelve el elemento indice-�simo de la sucesi�n.	
	int Elemento(int indice) {
		
		return(vector_privado[indice]);
		
	}
	
	int DevolverVector(int i) {
		
		return (vector_privado[i]);
	}
	
;


int main(){
	
	int k, n;
	
	cout << "Dame el valor k: " ;
	cin  >> k;
	cout << "\nDame el valor n: ";
	cin  >> n;
	
	
	Fibonacci mi_fibonacci(n);
	
	//Calculamos fibonacci en el vector.
	
	mi_fibonacci.CalculaPrimeros(k);
	
	//Mostrar el vector que tenemos.
	
	cout << "El vector estaria asi: \n" ;
	
	for(int i=0; i<k; i++) {
		
		cout << mi_fibonacci.DevolverVector(i);
		cout << " " ;
		
	}
	
	cout << endl << endl;
	
	
	//Para obtener el total de calculados (tope, o elementos del 
	//vector utilizados.
	
	cout << "Total Calculados: " 
		 <<	mi_fibonacci.TotalCalculados();
	cout << endl;
	
	
	//Para obtener el valor de un elemento indice-�simo 
	//de la sucesi�n.
	int posicion;
	do{
	
		
		cout << "\nIntroduzca la posicion de la sucesion de fibonacci "
			 << "cuyo valor quiere saber. (Las posiciones validas se encuentran "
			 << "entre 1 y " << mi_fibonacci.TotalCalculados() << "): "; 
		cin  >> posicion;
		
		
	}while( (posicion < 1) || (posicion > mi_fibonacci.TotalCalculados()) );
	
	//Una vez pasado el filtro para saber que se ha introducido una 
	//posici�n correcta, mostramos la posici�n solicitada:
	
	cout << "\n\nEl valor de la posicion numero " << posicion
		 << " de la sucesion de fibonacci es: " 
		 << mi_fibonacci.Elemento(posicion - 1) << "\n";
	
	//Para mostrar toda la sucesi�n hasta el elemento solicitado
	
	cout << "\nSucesion de Fibonacci hasta la posicion solicitada: ";
	
	for (int i=0; i<posicion; i++) {
	
		cout << mi_fibonacci.Elemento(i) << " ";
		
	}
	
	cout <<"\n\n";
		
	
	
	system("pause");
	
	return(0);
	
}
