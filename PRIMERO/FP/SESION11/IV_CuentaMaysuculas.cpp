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

	void CuentaMayusculas(){
		for(int i = 0; i < total_utilizados; i++){

			if(toupper(vector_privado[i]) == vector_privado[i]){

				mayuscula = vector_privado[i];

				for(int j = i+1; j < total_utilizados; j++){

					if(vector_privado[j] == mayuscula){

						contador++;

					}
				}
			}
			cout << "\n\nHay "<<contador<<" "<<mayuscula<<" \n";
			contador=0;
		}
	}
};

int main(){
	SecuenciaCaracteres vector;
	char variable;

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	

	vector.CuentaMayusculas();

	cout << "\n\n";
}