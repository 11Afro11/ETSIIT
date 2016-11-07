/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIERIA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 6
//
//
Cread una clase Permutacion para representar una permutación de enteros.
 Para almacenar los valores enteros usaremos como dato miembro privado un
vector de enteros.
 Pasaremos como parámetro al constructor un objeto de la clase
SecuenciaEnteros. Supondremos como precondición que el vector es
una permutación correcta, es decir, que contiene todos los enteros sin repetir
entre el mínimo y el máximo de dichos valores. Por ejemplo, (2,3,6,5,4)
es una permutación correcta pero no lo es (7,7,6,5) (tiene el 7 como valor
repetido) ni tampoco (7,6,4) (le falta el 5).
 Añadid un método que calcule el número de lecturas de dicha permutación. Una
permutación de un conjunto de enteros, C = f1;    ; ng, tiene k lecturas, si
para leer sus elementos en orden creciente (de izquierda a derecha) tenemos
que recorrer la permutación k veces. Por ejemplo, la siguiente permutación del
conjunto f0; : : : ; 8g:
4 0 8 1 2 5 3 6 7
necesita 3 lecturas. En la primera obtendríamos 0, 1, 2 y 3. En la segunda 4, 5, 6
y 7 y finalmente, en la tercera, 8.
/******************************************************************
*/
#include <iostream>

using namespace std;

//clase secuencia de enteros

class SecuenciaEnteros{
	private:
		//ambito privado
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO];
		int total_utilizados;

	public:
	//constructor sin argumentos
	SecuenciaEnteros()
		:total_utilizados(0) {
	}
	//metodo que devuelve el tamanio del vector
	int TotalUtilizados(){
		return total_utilizados;
	}
	//metodo que devuelve la capacidad del vector
	int Capacidad(){
		return TAMANIO;
	}
	//metodo que aniade un elemento al vector
	void Aniade(int nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	//metodo que devuelve un elemento del vector
	int Elemento(int indice){
		return vector_privado[indice];
	}

	//metodo que elimina un elemento del vector

	void Elimina(int numero){
		for(int i = numero; i < total_utilizados; i++){
			vector_privado[i] = vector_privado[i+1]; 
		}
		total_utilizados--;
	}
};

//clase permutacion que lee una cadena de enteros

class Permutacion{
	
private:
	
	//ambito privado
	SecuenciaEnteros cadena;

public:
	//constructor con argumentos
	Permutacion(SecuenciaEnteros vector){
		for(int i= 0; i<vector.TotalUtilizados(); i++){
			cadena.Aniade(vector.Elemento(i));
		}
	}
	
	//metodo que calcula la posicion minima del vector
	
	int PosicionMinimo(){
		int posicion_minimo;
		int minimo;
		minimo = cadena.Elemento(0);
		posicion_minimo = 0;
		for (int i = 1; i < cadena.TotalUtilizados() ; i++){
			if (cadena.Elemento(i) < minimo){
				minimo = cadena.Elemento(i);
				posicion_minimo = i;
			}
		}
		return posicion_minimo;
	}
	//metodo que calcula el maximo del vector
	int Maximo(){
		int maximo;
		maximo = cadena.Elemento(0);
		for (int i = 1; i < cadena.TotalUtilizados() ; i++){
			if (cadena.Elemento(i) > maximo){
				maximo = cadena.Elemento(i);
			}
		}
		return maximo;
	}
	//metodo que recorre el vector
	int RecorreVector(){
		int contador = 0;
		int tope = cadena.TotalUtilizados();
		int i = PosicionMinimo();
		int valor = cadena.Elemento(i);
		while(valor != Maximo()){
			for(i; i<tope; i++){
				if(cadena.Elemento(i+1) == valor + 1)
					valor = cadena.Elemento(i+1);
			}
			
			contador++;
			i = 0;			
		}
		
		return contador;
	}
	
	
};


int main(){
	
	//llamada a la clase y creacion de objetos
	SecuenciaEnteros cadena;
	
	//solicitud de datos por teclado
	
	int variable;
	
	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	while(variable != -1){
		cadena.Aniade(variable);
		cin >> variable;
	}
	//salida de datos
	for(int i = 0; i < cadena.TotalUtilizados();i++){
		cout << cadena.Elemento(i);
	}
	//salida de datos; cuantas veces hay que leerel vector
	
	Permutacion permuta(cadena);
	
	cout<< "\n\n Necesitamos recorrer el vector " << permuta.RecorreVector() << " veces\n\n";
	
	return(0);
}


















