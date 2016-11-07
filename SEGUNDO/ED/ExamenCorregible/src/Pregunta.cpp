#include "Pregunta.h"
#include <iostream>
#include <sstream>
using namespace std;

/*#ifndef Pregunta
#define Pregunta

class Pregunta{
private:
	string pregunta;
	int num;
	string *respuestas;
*/
	

	void Pregunta::Copia(const Pregunta &otra_pregunta){
		pregunta = otra_pregunta.pregunta;
		num = otra_pregunta.num;
	}
//private:
	Pregunta::Pregunta(){ 
		pregunta = "";
		num = 0;
	}

/*	Pregunta::Pregunta(string ask, int num_resp, string* resp){
		pregunta = ask;
		num = num_resp;
		// Reserva(num_resp);
		for(int i = 0; i < num; i++){
			respuestas.push_back(resp[i]);
		}
	}*/

	Pregunta::Pregunta(const Pregunta &otra_pregunta){
		Copia(otra_pregunta);
	}

/*	Pregunta :: ~Pregunta(){
		Borra();
	}*/

	string Pregunta::getPregunta()const{
		return pregunta;
	}

	int Pregunta::getNum()const{
		return num;
	}

	void Pregunta::setPregunta(string ask){
		pregunta = ask;
	}

	void Pregunta::setNum(int num){
		num =num;
	}



	Pregunta & Pregunta::operator = (const Pregunta & otra)
	{
	    if (this != &otra) { // Evitar autoasignación
	
	        // Libera la memoria ocupada
	
	        // Copia el contenido de la matriz y los campos privados
	        Copia(otra);
	    }
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignación
	}

	bool Pregunta::operator == (const Pregunta &otra)const{
		if(pregunta != otra.pregunta || num != otra.num){
			return false;
		}/*

		for(int i = 0; i < num; i++){
			for(int j = 0; j < num; j++){
				if(respuestas[i] != otra.respuestas[j]){
					return false;
				}
			}
		}*/
		return true;
	}

	istream & operator >> (istream & is, Pregunta & una_pregunta){
		string texto;
		string preg;
		int num;
		getline(is, texto);
		char letra;
		if(!texto.empty()){
			// getline(is, texto);
			// stringstream(texto) >> num;
			is >> num;
			// getline(is, texto);
			una_pregunta.setPregunta(texto);
			una_pregunta.setNumResp(num);
			for(int i = 0; i < num; i++){
				is >> letra;
				getline(is, preg);
				una_pregunta.respuestas[letra] = preg;
			}
			is.clear();
		}
		return is;
	}

	ostream & operator << (ostream & os, const Pregunta & una_pregunta){
		map<char, string> aux(una_pregunta.getRespuestas());
		/*Item(os, "./datos/Item.txt", una_pregunta.getPregunta());
		Enumerate(os, "./datos/BeginItemize.txt");*/
		os << una_pregunta.getPregunta()<<endl;
		for(map<char, string>::iterator it = aux.begin(); it !=aux.end(); ++it){
			// Item(os, "./datos/ItemItem.txt", aux[i]);
			os << it->first;
			os << it->second <<endl;
		}
		os << endl;
		return os;
	}
/*};



#endif*/