/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIERIA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 7
//
//
Reescribir la solución al ejercicio 6 de esta relación de problemas (generador de permutaciones
aleatorias) usando como dato miembro de la clase Permutacion un objeto
de la clase SecuenciaEnteros, en vez de un vector clásico.
Al constructor le seguimos pasando un objeto de la clase SecuenciaEnteros. Observad
que al cambiar la representación, habrá que modificar los métodos de la clase
Permutacion porque el acceso que realizaban, libremente, al vector donde se guardaban
los valores de la permutación ya no es posible. El acceso a los valores de
la permutación se hará en esta versión empleando los métodos públicos de la clase
SecuenciaEnteros.

/******************************************************************
*/
#include <iostream>
#include <cstdlib>	// para "MyRandom"
#include <ctime>

using namespace std;

class MyRandom{
	
private:
	
	// PRE: minVal <= MaxVal
	
    int minVal;	// Mínimo Valor
    int maxVal;	// Máximo valor

	/***********************************************************************/
	// Inicializa el generador de números aleatorios 
	// Es un método privado que se invoca solo al actuar el constructor.
	
	void InitMyRandom (void){
        time_t t;
        srand ((int) time(&t));     // Inicializa el generador
                                    // con el reloj del sistema
    }
    
public:
	
	/***********************************************************************/	
	// Constructor
	
    MyRandom (int el_minimo, int el_maximo) :
        minVal(el_minimo), maxVal(el_maximo)
    {
        InitMyRandom();

        int no_lo_uso = Next(); // Desecho el primero
    }

	/***********************************************************************/	
	// Calcula y devuelve un número aleatorio en el rango prefijado.
	
    int Next (void){
    	
        int rango = (maxVal - minVal)+1;
        int v1 = rango * (rand() / (RAND_MAX*1.0));
        int v2 = minVal + (v1 % rango);

        return (v2);
    }

	/***********************************************************************/
	
    int Min (void){
        return (minVal);
    }

	/***********************************************************************/
	
    int Max (void){
        return (maxVal);
    }

	/***********************************************************************/
};

/***********************************************************************/
/***********************************************************************/

//clase secuencia de enteros

class SecuenciaEnteros{
	private:
		//ambito privado
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO];
		int total_utilizados;
	
	/***********************************************************************/
	
	public:
	
	//constructor con argumentos
	
	SecuenciaEnteros()
		:total_utilizados(0) {
	}
	
	/***********************************************************************/
	
	//metodo que devuelve el tamanio del vector
	
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	/***********************************************************************/
	
	//metodo que devuelve la capacidad del vector
	
	int Capacidad(){
		return TAMANIO;
	}
	
	/***********************************************************************/
	
	//metodo que aniade un elemento al vector
	
	void Aniade(int nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	/***********************************************************************/
	
	//metodo que devuelve un elemento del vector
	
	int Elemento(int indice){
		return vector_privado[indice];
	}
	
	/***********************************************************************/

	//metodo que elimina un elemnto del vector

	void Elimina(int numero){
		for(int i = numero; i < total_utilizados; i++){
			vector_privado[i] = vector_privado[i+1]; 
		}
		total_utilizados--;
	}
	
	
};

/***********************************************************************/
/***********************************************************************/

//clase que lee una perutacion

class Permutacion{
	
private:
	//ambito privado
	SecuenciaEnteros cadena;
	
	/***********************************************************************/

public:
	
	//constructor conargumentos
	
	Permutacion(SecuenciaEnteros vector){
		for(int i= 0; i<vector.TotalUtilizados(); i++){
			cadena.Aniade(vector.Elemento(i));
		}
	}
	
	//metodo que añadeun elemento a la clase
	
	void Aniade(int elemento){
		cadena.Aniade(elemento);
	}
	
	/***********************************************************************/
	
	//metodo que devuelve un elemento del vector
	
	int Elemento(int indice){
		return cadena.Elemento(indice);
	}
	/***********************************************************************/
	
	//metodo que devuelve el tamanio del vector
	
	int Tamanio(){
		return cadena.TotalUtilizados();
	}
	/***********************************************************************/
	//metodo que calcula la posicion minima
	
	int PosicionMinimo(){
		int posicion_minimo;
		int minimo;
		minimo = cadena.Elemento(0);
		posicion_minimo = 0;
		for (int i = 1; i < cadena.TotalUtilizados() ; i++){
			if (cadena.Elemento(i) < minimo){
				minimo = cadena.Elemento(i);
				posicion_minimo = i;
			}
		}
		return posicion_minimo;
	}
	
	/***********************************************************************/
	//metodo que calcula el numero maximo del vector
	
	int Maximo(){
		int maximo;
		maximo = cadena.Elemento(0);
		for (int i = 1; i < cadena.TotalUtilizados() ; i++){
			if (cadena.Elemento(i) > maximo){
				maximo = cadena.Elemento(i);
			}
		}
		return maximo;
	}
	
	/***********************************************************************/
	//metodo que recorreel vector
	int RecorreVector(){
		int contador = 0;
		int tope = cadena.TotalUtilizados();
		int i = PosicionMinimo();
		int valor = cadena.Elemento(i);
		while(valor != Maximo()){
			for(i; i<tope; i++){
				if(cadena.Elemento(i+1) == valor + 1)
					valor = cadena.Elemento(i+1);
			}
			
			contador++;
			i = 0;			
		}
		
		return contador;
	}
	
	/***********************************************************************/	
	
};

//clase que genera permutaciones aleatoriamente

class GeneradorPermutaciones{
	
private:
	//ambito privado
	Permutacion permutado;
public:
	//metodo que genera permutaciones
	Permutacion Genera(int primero, int ultimo){
		MyRandom random(primero, ultimo);
		int i = 0;
		int valor;
		bool ya_esta = false;
		valor = random.Next();
		permutado.Aniade(valor);
		while(i < 11){
			valor = random.Next();
			for(int j = 0; j < permutado.Tamanio();j++){
				if(valor == permutado.Elemento(j))
					ya_esta = true;
			}
			
			if(!ya_esta){
				permutado.Aniade(valor);
				i++;
			}			
		}
		return permutado;
	}	
	
};



int main(){
	
	//llamada a la clase y creacion de objetos
	
	GeneradorPermutaciones aleatorio;
	Permutacion devuelve;
	int maximo, minimo;
	
	//solicitud de datos 
	
	cout << "\nDame un maximo yun minimo: ";
	cin >> maximo >> minimo;
	
	//calculamos el vector random
	
	devuelve = aleatorio.Genera(minimo, maximo);
	
	//salida de datos por pantalla
	
	for(int i = 0; i < devuelve.Tamanio();i++){
		cout << devuelve.Elemento(i);
	}
	
	
}
