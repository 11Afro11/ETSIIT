#include "ConjuntoPreguntas.h"
#include <iostream>
#include <cstring>
using namespace std;

/*
class ConjuntoPreguntas{
private:

	Pregunta * preguntas
		int num_preguntas;
	int tam;
*/

	void ConjuntoPreguntas::Copia(const ConjuntoPreguntas & otro){
		preguntas = otro.preguntas;

	}

//public:

	ConjuntoPreguntas::ConjuntoPreguntas(const ConjuntoPreguntas & otro){
		Copia(otro);
	}



	Pregunta & ConjuntoPreguntas::operator [](const int num){
  		// assert(preguntas.find(num) == preguntas.end());
  		map<int, Pregunta>::iterator it = preguntas.find(num);
  		assert(it != preguntas.end());
		return it->second;
	}

	const Pregunta & ConjuntoPreguntas::operator [](const int num)const{
  		map<int, Pregunta>::const_iterator it = preguntas.find(num);
  		assert(it != preguntas.end());
		return it->second;
	}
/*
	void ConjuntoPreguntas::Add(const Pregunta & nueva){

		preguntas. = nueva;
		num_preguntas++;
	}*/

/*	bool ConjuntoPreguntas::Esta(const Pregunta & nueva){
		for(int i = 0; i < Size(); i++){
			if(preguntas[i] == nueva){
				return true;
			}
		}
		return false;
	}*/

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
		return preguntas.size();
	}


//};

istream & operator >> (istream & is, ConjuntoPreguntas & conj){
	Pregunta preg;
	int id;
	string aux;
	while(is >> preg){
		istringstream iss(preg.getPregunta());
		iss>>id;
		getline(iss, aux);
		preg.setPregunta(aux);
		// if(conj.Valida(preg)){
			conj.preguntas[id] = preg;
		// }
	}
	return is;
}


ostream & operator << (ostream & os, ConjuntoPreguntas & conj){
	for(int i = 0; i < conj.Size(); i++){
		os << conj[i];
	}
	return os;
}

