/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIER√çA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 1
//
//
Cread la clase RLE para codificar/descodificar una secuencia seg˙n indica el ejercicio
23 de la RelaciÛn de Problemas II. Los mÈtodos a implementar tendr·n las siguientes
cabeceras:
SecuenciaEnteros Codifica (SecuenciaEnteros
secuencia_descodificada)
SecuenciaEnteros Descodifica (SecuenciaEnteros
secuencia_codificada)
Por ejemplo, la llamada al mÈtodo Codifica() pas·ndole como par·metro
el vector (1 1 1 2 2 2 2 2 3 3 3 3 3 3 5) debe devolver el vector
(3 1 5 2 6 3 1 5) mientras que el mÈtodo Descodifica() hace lo contrario.
Escribid un programa principal que lea un n˙mero indeterminado de enteros (terminando
con un -1) y los guarde en un objeto de la clase SecuenciaEnteros. A
continuaciÛn la codificar· y descodificar· en una nueva secuencia.
AÒadir un mÈtodo p˙blico a la clase SecuenciaEnteros:
bool EsIgualA (SecuenciaEnteros otro);
que sirva para comparar dos datos de tipo SecuenciaEnteros: ser·n iguales si
contienen el mismo n˙mero de elementos, son iguales y est·n en el mismo orden.
Usad este mÈtodo para demostrar que la secuencia original es igual a la secuencia
obtenida despuÈs de codificarla y descodificarla.
Finalidad: Ver mÈtodos a los que se les pasa como

/******************************************************************
*/
#include <iostream>

using namespace std;

//clase secuencia de enteros

class SecuenciaEnteros{
private:
	//datos delambito privado
	static const int TAMANIO = 50;
	int vector_privado[TAMANIO];
	int total_utilizados;

public:

	//constructor

	SecuenciaEnteros(){
		total_utilizados=0;
	}
	
	//metodo que devuelve el taanio del vector

	int TotalUtilizados(){
		return total_utilizados;
	}

	//metodo que devuelve la capacidad del vecor

	int Capacidad(){
		return TAMANIO;
	}

	//metodo que aÒada un eemento l vectos

	void Aniade(int nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	int Elemento(int indice){
		return vector_privado[indice];
	}
	
};

//clase que trabaja sobre la clase SecuenciaEnteros

class RLE{
private:
	//ambito privado
	SecuenciaEnteros una_secuencia;
public:
	
	//constructos con parametros
	
	RLE(SecuanciaEnteros constrye){
		una_secuencia = construye;
	}
	
	//metodo que codifica la cadena

	SecuenciaEnteros Codifica(SecuenciaEnteros secuencia_descodificada){
		SecuenciaEnteros codificada;
		int cuenta_numero=1;
		int i = 0;
		int j=0;
		while(i < total_utilizados){
			if(secuencia_descodificada.Elemento(i+1) == secuencia_descodificada.Elemento(i))
			    cuenta_numero++;
			else{
			    codificada.Elemento(j) = cuenta_numero;
			    codificada.Elemento(j+1) = secuencia_descodificada.Elemento(i);
			    cuenta_numero = 1;
			    j+=2;
			}
			i++;
		}
		return codificada;
	}
	
	//metodo que descodifica la cadena

	SecuenciaEnteros Descodifica(SecuenciaEnteros secuencia_codificada){
		SecuenciaEnteros descodificada;
		int i=0;
		while(i<secuencia_codificada.TotalUtilizados()){
			for(int j = 0; j < secuencia_codificada.Elemento(i); j++){
				descodificada.Aniade(secuencia_codificada.Elemento(j));
			}
			i=i+2;
		}
		return descodificada;
	}

};

int main(){
	
	//llamamos a laclase secuencia
	
	SecuenciaEnteros entero, codificado,descodificado;

	int variable;
	
	//recogemos los datos de entrada

	cout << "\n\nIntroduzca el vector: ";

	cin >> variable;

	while(variable != -1){
		entero.Aniade(variable);
		cin >> variable;
	}
	
	//creamos un objeto RLE

	RLE rle;
	
	//codificamos la secuencia
	
	codificado = rle.Codifica(entero);
	
	//mostramos el codificado de la secuencia por pantalla
	
	for(int i = 0; i < codificado.TotalUtilizados();i++){
		cout << codificado.Elemento(i);
	}
	
	//descodificamos la secuencia
	
	descodificado = rle.Descodifica(codificado);
	
	//mostraos las secuencia descodificada;
	
	for(int i = 0; i < descodificado.TotalUtilizados();i++){
		cout << descodificado.Elemento(i);
	}

	return(0);
}

