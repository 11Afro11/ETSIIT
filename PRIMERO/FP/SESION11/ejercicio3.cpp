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
// EJERCICIO 9
//
/*	

 Añadir el método EliminaMayusculas() para eliminar todas las ma-
yúsculas. Por ejemplo, después de aplicar dicho método al vector
{’S’,’o’,’Y’,’ ’,’y’,’O’}, éste debe quedarse con {’o’,’ ’,’y’}.
En este ejercicio proponemos implementar el siguiente algoritmo:
Recorrer todas las componentes del vector
Si la componente es una mayúscula, borrarla
Para borrar la mayúscula, se desplazan una posición a la izquierda todas las com-
ponentes que hay a su derecha. Para ello, llamad al método Elimina() que se ha
definido en el ejercicio 8 de esta relación de problemas.


*/
/*********************************************************************/
#include <iostream>

using namespace std;

//clase secuencia de caracteres que trabaja con caracteres dados por teclado

class SecuenciaCaracteres{

	//elementos del ambito privado

	private:

		static const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;

	public:

	//constructor

	SecuenciaCaracteres()
		:total_utilizados(0) {
	}

	//metodos que devuelven los datos del ambito privado

	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}

	//metodo que llena el vectos y cuenta el tamaño

	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	//metodo que devuelve los valores del vector

	char Elemento(int indice){
		return vector_privado[indice];
	}

	//metodo que elimina las mayusculas

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

	//lamada a la clase

	SecuenciaCaracteres vector;
	char variable;

	//solicitud de datos por pantalla

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	//bucle que solicita los datos del vectos

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	//llamada a un metodo de la clase	

	vector.EliminaMayusculas();

	//salida de datos por pantalla

	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}
	cout << "\n\n";
}