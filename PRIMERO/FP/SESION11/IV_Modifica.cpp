#include <iostream>

using namespace std;

class SecuenciaCaracteres{
	private:

		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
		char mayuscula;
		int contador;

	public:

	SecuenciaCaracteres(){
		total_utilizados=0;
		contador = 0;
	}
	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}
	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	char Elemento(int indice){
		return vector_privado[indice];
	}

	void Modifica(int numero, char letra){
		vector_privado[numero] = letra;
	}
};

int main(){
	SecuenciaCaracteres vector;
	char variable;
	char letra;
	int numero;

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	cout << "\n\nDime la posicion a modificar: ";
	cin >> numero;
	cout << "\n\nDame la letra: ";
	cin >> letra;

	

	vector.Modifica(numero, letra);


	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}

	cout << "\n\n";
}