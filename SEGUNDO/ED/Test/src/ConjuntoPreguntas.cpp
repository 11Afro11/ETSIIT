#include "ConjuntoPreguntas.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
class ConjuntoPreguntas{
private:

	Pregunta * preguntas;
	int num_preguntas;
	int tam;
*/
	void ConjuntoPreguntas::Reserva(int tam){
		preguntas = new Pregunta[tam];
	}
	void ConjuntoPreguntas::Copia(const ConjuntoPreguntas & otro){
		tam = otro.num_preguntas;
		Reserva(tam);
		num_preguntas = otro.num_preguntas;
		memcpy(preguntas, otro.preguntas, sizeof(Pregunta)* num_preguntas);
	}
	void ConjuntoPreguntas::Borra(){
		delete[] preguntas;
	}

	void ConjuntoPreguntas::Redimensiona(){
		tam = tam * 2;
		Pregunta * aux = new Pregunta[tam];
		// memcpy(aux, preguntas, sizeof(Pregunta)*num_preguntas);
		for(int i = 0; i < num_preguntas; i++){
			aux[i] = preguntas[i];
		}
		Borra();
		preguntas = aux;
	}

//public:
	ConjuntoPreguntas::ConjuntoPreguntas(){
		tam = 20;
		num_preguntas = 0;
		preguntas = new Pregunta[tam];
	}

	ConjuntoPreguntas::ConjuntoPreguntas(const ConjuntoPreguntas & otro){
		Copia(otro);
	}

	ConjuntoPreguntas::~ConjuntoPreguntas(){
		Borra();
	}

	Pregunta & ConjuntoPreguntas::operator [](int num){
		return preguntas[num];
	}

	Pregunta & ConjuntoPreguntas::operator [](int num)const{
		return preguntas[num];
	}

	void ConjuntoPreguntas::Add(const Pregunta & nueva){
		if(num_preguntas == tam){
			Redimensiona();
		}
		preguntas[num_preguntas] = nueva;
		num_preguntas++;
	}

	bool ConjuntoPreguntas::Esta(const Pregunta & nueva)const{
		for(int i = 0; i < num_preguntas; i++){
			if(preguntas[i] == nueva){
				return true;
			}
		}
		return false;
	}

	bool ConjuntoPreguntas::Valida(const Pregunta & nueva)const{
		if(nueva.getPregunta().empty()){
			return false;
		}
		if(nueva.getNumResp() < 2){
			return false;
		}

		return true;
	}

	int ConjuntoPreguntas::Size()const{
		return num_preguntas;
	}


//};

istream & operator >> (istream & is, ConjuntoPreguntas & conj){
	Pregunta preg;
	while(!is.eof()){
		is >> preg;
		if(conj.Valida(preg)){
			if(!(conj.Esta(preg))){
				conj.Add(preg);
			}
		}
	}
	return is;
}


ostream & operator << (ostream & os, ConjuntoPreguntas & conj){
	for(int i = 0; i < conj.Size(); i++){
		os << conj[i];
	}
	return os;
}

