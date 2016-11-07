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

	void EliminaMayusculas(){
		for(int j = 0; j<total_utilizados; j++){
			if(toupper(vector_privado[j]) == vector_privado[j]){
				for(int i = j; i < total_utilizados; i++){
					vector_privado[i] = vector_privado[i+1]; 
				}
				total_utilizados--;
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

	

	vector.EliminaMayusculas();


	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}
	cout << "\n\n";
}