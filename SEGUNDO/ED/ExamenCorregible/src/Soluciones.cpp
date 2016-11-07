#include "Soluciones.h"
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

/*
class Soluciones{
private:

	char * respuestas
		int num_respuestas;
	int tam;
*/

	void Soluciones::Copia(const Soluciones & otro){
		respuestas = otro.respuestas;

	}

//public:

	Soluciones::Soluciones(const Soluciones & otro){
		Copia(otro);
	}



	char & Soluciones::operator [](const int num){
  		// assert(respuestas.find(num) == respuestas.end());
  		map<int, char>::iterator it = respuestas.find(num);
  		assert(it != respuestas.end());
		return it->second;
	}

	const char & Soluciones::operator [](const int num)const{
  		map<int, char>::const_iterator it = respuestas.find(num);
  		assert(it != respuestas.end());
		return it->second;
	}
/*
	void Soluciones::Add(const char & nueva){

		respuestas. = nueva;
		num_respuestas++;
	}*/

/*	bool Soluciones::Esta(const char & nueva){
		for(int i = 0; i < Size(); i++){
			if(respuestas[i] == nueva){
				return true;
			}
		}
		return false;
	}*/

	int Soluciones::Size()const{
		return respuestas.size();
	}


//};

istream & operator >> (istream & is, Soluciones & conj){
	string respuesta;
	int id;
	char aux;
	char res;
	while(!is.eof()){
		getline(is,respuesta);
		istringstream iss(respuesta);
		iss>>id;
		iss >> aux;
		iss >>aux;
		iss >>res;
		// if(conj.Valida(res)){
		conj.respuestas[id] = res;
		// }
	}
	return is;
}


ostream & operator << (ostream & os, Soluciones & conj){
	for(map<int, char>::iterator it = conj.respuestas.begin(); it !=conj.respuestas.end(); ++it){
		os << it->second<<endl;
	}
	return os;
}

