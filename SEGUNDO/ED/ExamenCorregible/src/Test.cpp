#include <stdlib.h>    // incluye "rand(...)" y "srand"
#include "Test.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
/*

class Test{
private:
	Pregunta *examen;
	int numPreg;

*/

	void Test::Copia(const Test &otro){
		examen = otro.examen;
	}


//public:

	Test::Test(const ConjuntoPreguntas & preguntas, int numero, const Soluciones & solve){
		srand( time(NULL) );
		int util = 0;
		int numPreg = numero;
		int dato;
		int * vector = new int[numPreg];
		for(int i = 0; i < numPreg; i++){
			do{
				dato = rand() % preguntas.Size();
			}while(Esta(vector, dato, util));
			vector[i] = dato;
			util++;
		}

		for(int i = 0; i < numPreg; i++){
			examen.push_back(preguntas[vector[i]]);
			soluciones.push_back(solve[vector[i]]);
		}
	}
	Test::Test(const Test & otro_test){
		Copia(otro_test);
	}

	char Test::MuestraSolucion(int i){
		return tolower(soluciones[i]);
	}

	int Test::Size(){
		return examen.size();
	}

	Pregunta & Test::operator [] (int pos){
		return examen[pos];
	}

//};

ostream & operator << (ostream & os, const Test &exam){
	// Cabecera(os, "./datos/Cabecera.txt");
	
	for(int i = 0; i < exam.examen.size(); i++){
		os << i+1;
		os << exam.examen[i];
	}

	// Cabecera(os, "./datos/Final.txt");
	return os;
}

bool Esta(const int * vector, int dato, int util){
	int num_preguntas = util;
	for(int i = 0; i < num_preguntas; i++){
		if(vector[i] == dato){
			return true;
		}
	}
	return false;
}