/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIERIA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 8
//
//
Definid la clase ConjuntoOrdenado para que permita
almacenar una secuencia ordenada de números enteros sin repetidos. Definid métodos
para:
 Añadir un entero (de forma ordenada y sin almacenar repetidos).
 Calcular la unión con otro conjunto. En la unión se deben incluir los elementos
que estén en cualquiera de ellos.
Calcular la intersección con otro conjunto. En la intersección se deben incluir los
elementos que sean comunes a ambos conjuntos.

/******************************************************************
*/
#include <iostream>

using namespace std;

//Clase que trabaja sobre una secuencia ordenada de enteros

class SecuenciaOrdenada{

private:
	
	//elementos del vector privado
	
	static const int TAMANIO = 100;
	int vector[TAMANIO];
	int total_utilizados;
	
public:

	//constructor sin argumentos

	SecuenciaOrdenada(){
		total_utilizados = 0;
	}	

	//metodo que devuelve eltamaniodel vector

	int TotalUtilizados(){
		return total_utilizados;
	}
	
	//metodo que devuelve la capacidad del vector
	
	int Capacidad(){
		return TAMANIO;
	}
	
	//metodo que aniade elementos al vector
	
	void Aniade(int nuevo){
		bool se_repite = false;
		if (total_utilizados < TAMANIO){
			for(int i = 0; i < total_utilizados; i++){
				if(nuevo == vector[i])
					se_repite = true;
			}
			if(!se_repite){
				vector[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
	}
	int Elemento(int indice){
		return vector[indice];
	}
	
	//metodo que calcula la interseccion
	
	SecuenciaOrdenada Interseccion(SecuenciaOrdenada otra_secuencia){
		
		SecuenciaOrdenada interseccion;
		
		bool compartido = false;
		
		for(int i = 0; i < total_utilizados; i++){
			for(int j = 0; j < otra_secuencia.total_utilizados; j++){
				if(vector[i] == otra_secuencia.vector[j]){
					compartido = true;
				}
			}
			if(compartido){
				interseccion.Aniade(vector[i]);
				compartido = false;
			}
		}
		return interseccion;
	}
	
	//metodo que calcula la union
	
	SecuenciaOrdenada Union(SecuenciaOrdenada otra_secuencia){
		SecuenciaOrdenada unir;
		int i = 0, j = 0;
		
		while(i < total_utilizados && j < otra_secuencia.total_utilizados){
			if(vector[i] < otra_secuencia.vector[j]){
	      		unir.Aniade(vector[i]);
	      		i++;
	      	}
	      	
	      	else if(otra_secuencia.vector[j] < vector[i]){
	      		unir.Aniade(otra_secuencia.vector[j]);
	      		j++;
			  }
			
			else{
				unir.Aniade(otra_secuencia.vector[j]);
				i++;
			}
			
		}
		
		return unir;		
	}
};


int main(){
	
	//llamada a la clase y creacion de objeos
	
	SecuenciaOrdenada primera_secuencia, segunda_secuencia, interseccion,auxiliar, unionn;
	int elemento;
	
	//solicitud de datos por pantalla
	
	cout << "\n\nIntroduce la primera secuencia: ";
	cin >>elemento;
	
	while(elemento != -1){
		primera_secuencia.Aniade(elemento);
		cin>>elemento;
	}
	
	cout << "\n\nIntroduce la segunda secuencia: ";
	cin >>elemento;
	
	while(elemento != -1){
		segunda_secuencia.Aniade(elemento);
		cin>>elemento;
	}
	
	//calculamos la interseccion
	
	interseccion = primera_secuencia.Interseccion(segunda_secuencia);
	
	//salida de datso por pantalla
	
	cout << "\n\nLa interseccion de los elementos es: \n";
	
	for(int i= 0; i < interseccion.TotalUtilizados();i++){
		cout << interseccion.Elemento(i);
	}
	
	//calculamos la union
	
	unionn = primera_secuencia.Union(segunda_secuencia);
	
	//salida de datos por pantalla
	
	cout << "\n\nLa union de los elementos es: \n";
	
	for(int i= 0; i < unionn.TotalUtilizados();i++){
		cout << unionn.Elemento(i);
	}
	
	return(0);
	
}








