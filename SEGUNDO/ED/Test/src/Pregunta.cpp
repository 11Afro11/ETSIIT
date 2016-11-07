#include "Pregunta.h"
#include "Latex.h"
#include <iostream>
#include <sstream>
using namespace std;

/*#ifndef Pregunta
#define Pregunta

class Pregunta{
private:
	string pregunta;
	int num_respuestas;
	string *respuestas;
*/
	
	void Pregunta::Reserva(int tam){
		respuestas = new string[tam];
	}
	void Pregunta::Copia(const Pregunta &otra_pregunta){
		pregunta = otra_pregunta.pregunta;
		num_respuestas = otra_pregunta.num_respuestas;
		for(int i = 0; i < num_respuestas; i++){
			respuestas[i] = otra_pregunta.respuestas[i];
		}
	}
	void Pregunta::Borra(){
		delete[] respuestas;
	}
//private:
	Pregunta::Pregunta(){ 
		pregunta = "";
		num_respuestas = 0;
		respuestas = 0;
	}

	Pregunta::Pregunta(string ask, int num_resp, string* resp){
		pregunta = ask;
		num_respuestas = num_resp;
		Reserva(num_resp);
		for(int i = 0; i < num_respuestas; i++){
			respuestas[i] = resp[i];
		}
	}

	Pregunta::Pregunta(const Pregunta &otra_pregunta){
		Reserva(otra_pregunta.num_respuestas);
		Copia(otra_pregunta);
	}

	Pregunta :: ~Pregunta(){
		Borra();
	}

	string Pregunta::getPregunta()const{
		return pregunta;
	}

	int Pregunta::getNumResp()const{
		return num_respuestas;
	}

	string * Pregunta::getRespuestas()const{
		return respuestas;
	}

	void Pregunta::setPregunta(string ask){
		pregunta = ask;
	}

	void Pregunta::setNumResp(int num){
		num_respuestas =num;
	}



	void Pregunta::setRespuestas(string* resp){
		Reserva(num_respuestas);
		for(int i = 0; i < num_respuestas; i++){
			respuestas[i] = resp[i];
		}
	}

	Pregunta & Pregunta::operator = (const Pregunta & otra)
	{
	    if (this != &otra) { // Evitar autoasignación
	
	        // Libera la memoria ocupada
	        Borra();
	
	        // Reserva de memoria para los valores de la matriz
	        Reserva (otra.num_respuestas);
	
	        // Copia el contenido de la matriz y los campos privados
	        Copia(otra);
	    }
	    return (*this);  // Objeto implicito: parte
	                     // izquierda de la asignación
	}

	bool Pregunta::operator == (const Pregunta &otra)const{
		if(pregunta != otra.pregunta || num_respuestas != otra.num_respuestas){
			return false;
		}

		for(int i = 0; i < num_respuestas; i++){
			for(int j = 0; j < num_respuestas; j++){
				if(respuestas[i] != otra.respuestas[j]){
					return false;
				}
			}
		}
		return true;
	}

	istream & operator >> (istream & is, Pregunta & una_pregunta){
		string texto;
		string tex;
		int num;
		string * res;
		getline(is, texto);
		istringstream iss(texto);
		char trash;
		iss>>trash;
		while(trash != '.'){
			iss >> trash;
		}
		getline(iss, texto);
		if(!texto.empty()){
			// getline(is, texto);
			// stringstream(texto) >> num;
			is >> num;
			getline(is, tex);
			una_pregunta.setPregunta(texto);
			una_pregunta.setNumResp(num);
			res = new string[num];
			for(int i = 0; i < num; i++){
				getline(is, texto);
				res[i] = texto;
			}
			una_pregunta.setRespuestas(res);
			is.clear();
			delete[]res;
		}
		return is;
	}

	ostream & operator << (ostream & os, Pregunta & una_pregunta){
		Item(os, "./datos/Item.txt", una_pregunta.pregunta);
		Enumerate(os, "./datos/BeginItemize.txt");
		for(int i = 0; i < una_pregunta.num_respuestas; i++){
			Item(os, "./datos/ItemItem.txt", una_pregunta.respuestas[i]);
		}
		Enumerate(os, "./datos/EndItemize.txt");
		return os;
	}
/*};



#endif*/