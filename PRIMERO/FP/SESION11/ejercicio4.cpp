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
// EJERCICIO 11
//
/*	

 Añadir un método EliminaRepetidos() que quite los elementos repetidos, de for-
ma que cada componente sólo aparezca una única vez. Se mantendrá la primera
aparición, de izquierda a derecha. Por ejemplo, si el vector contiene
{’b’,’a’,’a’,’h’,’a’,’a’,’a’,’a’,’c’,’a’,’a’,’a’,’g’}
después de quitar los repetidos, se quedaría como sigue:
{’b’,’a’,’h’,’c’,’g’}



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

	//metodos que devuelven los elemtentos del ambito privado

	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}

	//metodo que aniade elementos al vectos y cuenta su tamanio

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

	//metodo que elimina los repetidos

	void EliminaRepetidos(){
		for(int i = 0; i < total_utilizados; i++){
			for(int j = i+1; j < total_utilizados; j++){
				if(vector_privado[i] == vector_privado[j]){
					for(int k = j+1; k < total_utilizados; k++){
						vector_privado[k] = vector_privado[k+1]; 
					}
					j--;
					total_utilizados--;
				}
			}
		}
	}
};

int main(){

	//llamada a la clase

	SecuenciaCaracteres vector;
	char variable;

	//solicitud de datos por teclado

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	//bucle que recoge los elementos del vector

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	//llamada a un metodo del vector

	vector.EliminaRepetidos();

	//salida de datos por pantalla

	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}
	cout << "\n\n";
}