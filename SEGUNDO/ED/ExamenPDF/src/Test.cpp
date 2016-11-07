#include <stdlib.h>    // incluye "rand(...)" y "srand"
#include "Test.h"
#include "Latex.h"
#include <iostream>
#include <cstring>

using namespace std;
/*

class Test{
private:
	Pregunta *examen;
	int numPreg;

*/
	void Test::Reserva(int num){
		examen = new Pregunta[num];
	}
	void Test::Copia(const Test &otro){
		numPreg = otro.numPreg;
		memcpy(examen, otro.examen, sizeof(Pregunta)*numPreg);
	}
	void Test::Borra(){
		delete[] examen;
	}

//public:

	Test::Test(){
		numPreg = 0;
		examen = 0;
	}
	Test::Test(const ConjuntoPreguntas & preguntas, int numero){
		srand( time(NULL) );
		int util = 0;
		numPreg = numero;
		Reserva(numPreg);
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
			examen[i] = preguntas[vector[i]];
		}
	}
	Test::Test(const Test & otro_test){
		Reserva(otro_test.numPreg);
		Copia(otro_test);
	}
	Test::~Test(){
		delete[] examen;
	}

	int Test::Size(){
		return numPreg;
	}

	Pregunta & Test::operator [] (int pos){
		return examen[pos];
	}

//};

ostream & operator << (ostream & os, const Test &exam){
	Cabecera(os, "./datos/Cabecera.txt");
	
	for(int i = 0; i < exam.numPreg; i++){
		os << exam.examen[i];
	}

	Cabecera(os, "./datos/Final.txt");
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