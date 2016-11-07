/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIERIA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 6
//
//
Supongamos que tenemos una clase para generar números enteros aleatorios entre
un mínimo y un máximo, con la siguiente interfaz pública:
MyRandom
+ MyRandom(int minimo, int maximo)
+ int Next()
+ int Min()
+ int Max()
Puede usarse cualquiera de las implementaciones que encontrará en la página web
de la asignatura. Para generar 10 números aleatorios entre 4 y 7, por ejemplo, bastaría
hacer lo siguiente:
MyRandom generador_aleatorio(4, 7);
for (int i=0; i<10; i++)
cout << generador_aleatorio.Next();
Hay que destacar lo siguiente:
 Cada llamada a generador_aleatorio.Next() genera un valor aleatorio
(entre 4 y 7 en el ejemplo)
 Los valores generados pueden repetirse antes de que se hayan generado todos
los posibles valores. Por lo tanto, una posible secuencia de números generados
podría ser la siguiente: 5 4 5 6 4 7 4 5
Se pide crear la clase GeneradorPermutaciones para generar permutaciones
aleatorias de un conjunto de enteros entre un valor mínimo y un valor máximo. La
clase tendrá un único método con la siguiente cabecera:
Permutacion Genera(int primero, int ultimo)
dónde la clase Permutacion es la vista en el problema 5 de esta misma relación
de problemas. Por ejemplo, si mínimo = 1 y máximo = 6, una permutación válida sería
{3,1,6,4,5,2}. Como puede observarse, no pueden aparecer elementos repetidos
y deben estar todos los valores entre 1 y 6.
Finalidad: Métodos que devuelven objetos y

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








