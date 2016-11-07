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
// EJERCICIO 7
//
/*	

Añadir el método IntercambiaComponentes() para intercambiar dos componen-
tes del vector. Por ejemplo, si el vector contiene {’h’,’o’,’l’,’a’}, después de
intercambiar las componentes 1 y 3, se quedaría con {’h’,’a’,’l’,’o’}.
¿Qué debería hacer este método si los índices no son correctos?
Añadir otro método llamado Invierte() para invertir el vector, de forma que si el
vector contenía, por ejemplo, los caracteres {’m’,’u’,’n’,’d’,’o’}, después
de llamar al método se quedará con {’o’,’d’,’n’,’u’,’m’}.
Nota: Para implementar este método, llamad a IntercambiaComponentes().
Imprimir las componentes del vector desde main(), antes y después de llamar a
dicho método. Observad que se repite el mismo tipo de código cuando se imprimen
las componentes del vector. Ya lo arreglaremos en el tema siguiente.


*/
/*********************************************************************/
#include <iostream>

using namespace std;

//clase secuencia de caracteres que realizara operaciones con los caracteres introducidos 

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

	//metodos que devuelven los elemetos del ambito privado 

	int TotalUtilizados(){
		return total_utilizados;
	}
	int Capacidad(){
		return TAMANIO;
	}

	//metodo que se encarga de aniadir los elementos al vectos asi como de contar el tamanio

	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	//metodo que devuelve un elemanto del vectos

	char Elemento(int indice){
		return vector_privado[indice];
	}

	//metodo que invierte el vector 

	void InvierteVector(){
		char auxiliar;
		int k = total_utilizados -1;

		for (int i = 0; i < (total_utilizados/2); i++){

			auxiliar = vector_privado[i];
			vector_privado[i] = vector_privado[k];
			vector_privado[k] = auxiliar;
			k--;

		}
	}

	void Intercambia(int posicion1, int posicion2){
		int auxiliar;
		auxiliar = posicion1;
		posicion1 = posicion2;
		posicion2 = auxiliar;
	}
};

int main(){

	//llamada a la clase

	SecuenciaCaracteres vector;

	//declaracion de variables

	char variable;
	char opcionSN;
	int posicion1;
	int posicion2;

	//solicitud de datos por teclado

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	//bucle que se encarga de recoger los datos

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	do{

		cout << "¿Intercambiar (S/N)? : ";
	    cin >> opcionSN;
	    opcionSN = toupper(opcionSN);
	} while (opcionSN != 'S' && opcionSN != 'N');

	if (opcionSN == 'S'){
		cout <<"\nposicion 1: ";
		cin >> posicion1;

		cout << "\nPosicion 2: ";
		cin >> posicion2;

		vector.Intercambia(posicion1,posicion2);
	}

	else
		vector.InvierteVector();

	

	//salida de datos por pantalla

	for(int i = 0; i < vector.TotalUtilizados(); i++){
		cout <<vector.Elemento(i)<<" ";
	}

}