#include <iostream>

using namespace std;

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

	void Elimina(int numero){
		for(int i = numero; i < total_utilizados; i++){
			vector_privado[i] = vector_privado[i+1]; 
		}
		total_utilizados--;
	}
};

int main(){
	SecuenciaCaracteres vector;
	char variable;
	int posicion;

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	do{
		cout << "\n\nQue posicion elimino?: ";
		cin >> posicion;
	}while(posicion > vector.TotalUtilizados());

	vector.Elimina(posicion);


	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}
	cout << "\n\n";
}