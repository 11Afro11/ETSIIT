#include <iostream>

using namespace std;

class SecuenciaCaracteres{
	private:

		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;

	public:

	SecuenciaCaracteres()
		:total_utilizados(0) {
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
	SecuenciaCaracteres vector;
	char variable;

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	

	vector.EliminaRepetidos();


	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}
	cout << "\n\n";
}