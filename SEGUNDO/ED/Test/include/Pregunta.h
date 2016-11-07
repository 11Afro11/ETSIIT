#ifndef PREGUNTA
#define PREGUNTA
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
/**
* @file Pregunta.h
* @brief Clase Pregunta, en ella abstraemos el TDA Pregunta con los siguientes atributos:
*Segun mi definicion del TDA Pregunta se compone de un string con el enunciado,
*un int con el numero de respuestas y un vector dinemico de respuestas
**/

class Pregunta{
private:
/**
* Atributos privados
**/
	string pregunta;
	int num_respuestas;
	string *respuestas;

/**
* @brief Reserva
*se encarga de reservar memoria para el vector dinamico de preguntas
* @param tam: tamaño de memoria a reservar
**/
	void Reserva(int tam);
/**
* @brief Copia
*copia los datos de un conjunto a otro
* @param otro: pregunta a copiar
**/
	void Copia(const Pregunta &otra_pregunta);
/**
* @brief Borra
*Borra la memoria reservada
**/
	void Borra();
public:

/**
* @brief Preguntas
*Constructor por defecto
**/
	Pregunta();
/**
* @brief Preguntas
*Constructor por parametros
* @param ask: pregunta
* @param num_resp: numero de respuestas
* @param resp: vector de respuestas
**/
	Pregunta(string ask, int num_resp, string* resp);
/**
* @brief Preguntas
*Constructor de copia
* @param otro: conjunto a copiar
**/
	Pregunta(const Pregunta &otra_pregunta);
/**
* @brief ~Preguntas
* Destructor
**/
	~Pregunta();
/**
* @brief getPregunta
* Metodo que devuelve el enunciado de una pregunta
* @return devuelve un string con la pregunta
**/
	string getPregunta()const;
/**
* @brief getNumResp
* Metodo que devuelve el numero de respuestas
* @return devuelve un int con el numero de respuesta
**/
	int getNumResp()const;
/**
* @brief getPregunta
* Metodo que devuelve las respuestas
* @return devuelve un array de string con las respuestas
**/
	string * getRespuestas()const;
/**
* @brief setPregunta
* Metodo que asigna el enunciado de una pregunta
* @param ask: string de la pregunta
**/
	void setPregunta(string ask);
/**
* @brief setNumResp
* Metodo que asigna el numero de respuestas
* @param num: numero de respuestas
**/
	void setNumResp(int num);
/**
* @brief setPregunta
* Metodo que asigna las respuestas
* @param resp: vector de respuestas
**/
	void setRespuestas(string* resp);
/**
* @brief sobrecarga del operador de asignacion
* @param otra: Pregunta a asiganar
* @return devuelve la referencia a la pregunta asignada
**/
	Pregunta & operator = (const Pregunta & otra);
/**
* @brief sobrecarga del operador ==
* @param otra: Pregunta a comparar
* @return devuelve true si son iguales y false cuando son distintas
**/
	bool operator == (const Pregunta &otra)const;
/**
* @brief sobrecarga del operador de entrada
* @param is: flujo de entrada
* @param una_pregunta: pregunta a leer
* @return devuelve una referencia al flujo de entrada
**/
	friend istream & operator >> (istream & is, Pregunta & una_pregunta);
/**
* @brief sobrecarga del operador de salida
* @param os: flujo de salida
* @param una_pregunta: pregunta a escribir
* @return devuelve una referencia al flujo de salida
**/
	friend ostream & operator << (ostream & os, Pregunta & una_pregunta);
};

/**
* @brief sobrecarga del operador de entrada
* @param is: flujo de entrada
* @param una_pregunta: pregunta a leer
* @return devuelve una referencia al flujo de entrada
**/
istream & operator >> (istream & is, Pregunta & una_pregunta);
/**
* @brief sobrecarga del operador de salida
* @param os: flujo de salida
* @param una_pregunta: pregunta a escribir
* @return devuelve una referencia al flujo de salida
**/
ostream & operator << (ostream & os, Pregunta & una_pregunta);


#endif