#include <iostream>

using namespace std;

//clase secuencia de caracteres que trabaja con caracteres dados por teclado

class SecuenciaCaracteres{

	//ambito privado

	private:

		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
		char mayuscula;
		int contador;

	public:

	//constructor

	SecuenciaCaracteres(){
		total_utilizados=0;
		contador = 0;
	}

	//metodos que devuelven los valores del ambito privado

	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}

	//metodo que aniade valores al vector y cuenta su tamanio

	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	//metodo que devuelve un elemento del vecctor

	char Elemento(int indice){
		return vector_privado[indice];
	}

	//metodo que modifica un elemento del vectos

	void Modifica(int numero, char letra){
		vector_privado[numero] = letra;
	}
};

int main(){

	//llamada a la clase

	SecuenciaCaracteres vector;

	//declaracion de variables

	char variable;
	char letra;
	int numero;

	//solicitud de datso por teclado

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	//bucle que recoge los elementos del vector

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	cout << "\n\nDime la posicion a modificar: ";
	cin >> numero;
	cout << "\n\nDame la letra: ";
	cin >> letra;

	//llamada a un metodo de la clase

	vector.Modifica(numero, letra);

	//salida de datos por pantalla

	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}

	cout << "\n\n";
}