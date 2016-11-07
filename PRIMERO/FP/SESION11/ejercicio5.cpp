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
// EJERCICIO 13
//
/*	

. Realizar un programa que vaya leyendo caracteres hasta que se encuentre un pun-
to ’.’. Queremos contar el número de veces que aparece cada una de las letras
mayúsculas.
Una posibilidad sería leer el carácter, y después de comprobar si es una mayúscula,
ejecutar un conjunto de sentencias del tipo:
if (letra == ’A’)
contador_mayusculas[0] = contador_mayusculas[0] + 1;
else if (letra == ’B’)
contador_mayusculas[1] = contador_mayusculas[1] + 1;
else if (letra == ’C’)
contador_mayusculas[2] = contador_mayusculas[2] + 1;
else ....
Sin embargo, este código es muy redundante. Proponed una solución e implementarla.
Para resolver este ejercicio puede usarse o bien un vector clásico -array - de enteros,
o bien un objeto de la clase SecuenciaEnteros. La idea es que todos los if-else
anteriores los podamos resumir en una única sentencia del tipo:

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

	//metodo que aniade elementos al vectos y cuenta su tamanio

	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	//metodo que devuelve un elemento del vectos

	char Elemento(int indice){
		return vector_privado[indice];
	}

	//metodo que cuenta las mayusculas

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

	//llamada a la clase

	SecuenciaCaracteres vector;
	char variable;

	//solicitud de datos por pantalla

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	//bucle que recoge los datos del vectos

	while(variable != '#'){
		vector.Aniade(variable);
		cin >> variable;
	}

	//llamada a un metodo de la clase

	vector.CuentaMayusculas();

	cout << "\n\n";
}