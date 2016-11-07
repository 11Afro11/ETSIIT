#ifndef PREGUNTA
#define PREGUNTA
#include <string>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
/**
* @file Pregunta.h
* @brief Clase Pregunta, en ella abstraemos el TDA Pregunta con los siguientes atributos:
*Segun mi definicion del TDA Pregunta se compone de un string con el enunciado,
*un int con el numero de respuestas y un vector de respuestas
**/

class Pregunta{
private:
/**
* Atributos privados
**/
	string pregunta;
	int num_respuestas;
	map<char,string> respuestas;


/**
* @brief Copia
*copia los datos de un conjunto a otro
* @param otro: pregunta a copiar
**/
	void Copia(const Pregunta &otra_pregunta);

public:

/**
* @brief Preguntas
*Constructor por defecto
**/
	Pregunta();

/**
* @brief Preguntas
*Constructor de copia
* @param otro: conjunto a copiar
**/
	Pregunta(const Pregunta &otra_pregunta);

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
* @return devuelve un map char string
**/
	map<char,string>  getRespuestas()const;
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
	friend ostream & operator << (ostream & os, const Pregunta & una_pregunta);
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
ostream & operator << (ostream & os, const Pregunta & una_pregunta);


#endif