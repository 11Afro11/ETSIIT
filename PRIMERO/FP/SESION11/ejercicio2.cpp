/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 11
// EJERCICIO 8
//
/*	

 Añadir el método Elimina() para eliminar el carácter que se encuentre en una de-
terminada posición, de forma que si el vector contenía, por ejemplo, los caracteres
{’h’,’o’,’l’,’a’}, después de eliminar la componente con índice 2 (la tercera)
se quedará con {’h’,’o’,’a’}.
¿Qué debería hacer el método si el índice no es correcto?

*/
/*********************************************************************/
#include <iostream>

using namespace std;

//clase secuencia de caracteres que trabaja con caracteres dados por teclado

class SecuenciaCaracteres{

	//ambito privado

	private:

		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;

	public:

	//constructor

	SecuenciaCaracteres()
		:total_utilizados(0) {
	}

	//metodos que devuelven los elementos del ambito privado

	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}

	//metodod que añade elementos al ventos y cuante el tamanio de este

	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	//metodo que devuelve un elemento del vector

	char Elemento(int indice){
		return vector_privado[indice];
	}

	//metodo que elimina un elemento del vectos

	void Elimina(int numero){
		for(int i = numero; i < total_utilizados; i++){
			vector_privado[i] = vector_privado[i+1]; 
		}
		total_utilizados--;
	}
};

int main(){

	//llamada a la clase

	SecuenciaCaracteres vector;

	//declaracion de variables

	char variable;
	int posicion;

	//solicitud de datos por pantalla

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	//bucle que pide los datos  del vectso 

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}


	do{
		cout << "\n\nQue posicion elimino?: ";
		cin >> posicion;
	}while(posicion > vector.TotalUtilizados());

	//llamada a un metodo de la clase

	vector.Elimina(posicion);

	//salida de datos por pantalla


	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}
	cout << "\n\n";
}