/*/*******************************************
//FUNDAMENTOS DE PROGRAMACIÓN
//GRADO EN INGENIERÍA INFORMÁTICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACIÓN DE PROBLEMAS 3
//PROBLEMA NÚMERO 19
//
//
. Cread una clase Frase para almacenar un conjunto de caracteres. Internamente,
como dato miembro privado, se usará un vector de caracteres.
Añadid los siguientes métodos:
• Constructor que recibe como argumento un string.
• void EliminaBlancosIniciales() para borrar todos los blancos iniciales.
• void EliminaBlancosFinales() para borrar todos los blancos finales.
• int NumeroPalabras() que indique cuántas palabras hay en la frase (una
palabra está separada por otra por uno o más espacios en blanco)
• void BorraPalabra(int k_esima) para que borre la palabra k-ésima.
• string Palabra(int k_esima) que devuelva la k-ésima palabra de la ca-
dena. Si hay menos de k palabras, devolverá la cadena vacía "".

/******************************************************************
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <string>    //  Para utilizar cadenas de caracteres (recursos string)
#include <cctype>

using namespace std; 

class Frase {
	
	private:
	
		static const int TAMANIO = 100;
		char vector_privado[TAMANIO];
		int total_utilizados;
		
	public:
		
		Frase(string mensaje) 
			: total_utilizados (0) //Inicialización de la constante en el 
									//contructor.
		{
			Aniade(mensaje);			
		}
		
		int TotalUtilizados(void)
		{
			return (total_utilizados);
		}
		
		int Capacidad(void)
		{
			return (TAMANIO);
		}
		
		//Pasamos la frase que hemos recogido en el string a 
		//caracteres en nuestro vector privado
		void Aniade(string mensaje)
		{	
			for(int i=0; i < mensaje.size(); i++) {
				
				if (total_utilizados < TAMANIO){
					
					vector_privado[total_utilizados] = mensaje[i];
					total_utilizados++;
				}
				
			}
			
		}

		//metodo que elimina un elemento

		void Elimina(int numero){
			for(int i = numero; i < total_utilizados; i++){
				vector_privado[i] = vector_privado[i+1]; 
			}
			total_utilizados--;
		}

		//metodo que elimina los espacios en blanco iniciales
		
		void EliminaBlancosIniciales() {
			
			char caracter;
			
			while((isspace(vector_privado[0]))) {
			
				for(int i=0; i <= total_utilizados; i++) {
					
					vector_privado[i] = vector_privado[i+1];
					
				}
				
				total_utilizados--;
				
			}
		
		}

		//metodo que elimina los espacios en blanco finales
		
		void EliminaBlancosFinales() {
			
			char caracter;
			
			while((isspace(vector_privado[total_utilizados-1]))) {
			
				total_utilizados--;
				
			}
			
		}

		//metodo que cuenta las palabras

		int NumeroPalabras(){
			int cuentapalabra = 0;
			for(int i = 0; i < total_utilizados; i++){
				if(isspace(vector_privado[i]) && !isspace(vector_privado[i+1])){
					cuentapalabra++;
				}
			}
			return cuentapalabra;
		}

		//metodo que elimina la palabra

		void BorraPalabra(int k_esima){
			int i = k_esima;
			while(!isspace(vector_privado[i])
				Elimina(i);
				i++;
			}
		}

		//metodo que devuelve una palabra
		
		sring DevuelvePalabra(int k_esima){
			string palabra;
			int i = k_esima;
			int j = 0;
			while(!isspace(vector_privado[i])
				palabra[j] = vector_privado[i];
				i++;
				j++;
			}
			return palabra;
		}

		char Elemento(int indice){
			return (vector_privado[indice]);
		}
		



};//Fin de clase 


int main(){
	
	int posicion;
	string mensaje;
	
	getline(cin,mensaje);
	
	//Creacion del objeto
	Frase mi_frase(mensaje);
	
	//Limpiar los blancos iniciales
	mi_frase.EliminaBlancosIniciales();

	mi_frase.EliminaBlancosFinales();

	cout << "\n\nHay "<<mi_frase.NumeroPalabras()<<"\n\n";

	cout << "\n\nDame una posicion de palabra: ";
	cin >> posicion;

	cout << mi_frase.DevuelvePalabra(k_esima);

	mi_frase.BorraPalabra(k_esima);

	//Para mostrar el vector
	
	cout << "Ahora el vector quedaria: ";
	
	for(int i=0; i <= mi_frase.TotalUtilizados(); i++) {
		
		cout << " " << mi_frase.Elemento(i);
		
	}
	
	
	return(0);
	
}