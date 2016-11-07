#ifndef SOLUCIONES
#define SOLUCIONES
#include <iostream>
#include <map>
#include <cassert>
using namespace std;

/**
* @file Soluciones.h
* @brief Clase Soluciones, en ella abstraemos el TDA Soluciones con los siguientes atributos:
*Segun mi definicion del TDA Soluciones se compone de un map de int char
**/
class Soluciones{
private:
	map<int,char> respuestas;

/**
* @brief Copia
*copia los datos de un conjunto a otro
* @param otro: pregunta a copiar
**/
	void Copia(const Soluciones & otro);

public:

/**
* @brief Soluciones
*Constructor por defecto
**/
	Soluciones(){}
/**
* @brief Soluciones
*Constructor de copia
* @param otro: conjunto a copiar
**/
	Soluciones(const Soluciones & otro);

/**
* @brief Operador de acceso, Devuelve el valor del vector en la posicion deseada, este operador permite modificacion
* @param num: posicion del map que queremos consultar
* @return char &
**/
	char & operator [] (const int num);
/**
* @brief Operador de acceso. Devuelve el valor del vector en la posicion deseada, este operador NO permite modificacion
* @param num: posicion del map que queremos consultar
* @return char &
**/
	const char & operator [] (const int num)const;

/**
* @brief Esta
* Metodo que comprueba si una char se encuentra en el conjunto
* @param nueva: char que comprobamos
* @return true | false
**/
	bool Esta(const char & nueva);
/**
* @brief Size
*Devuelve el tamaño utilizado del conjunto
* @returnt tamaño del conjunto(int)
**/
	int Size()const;

/**
* @brief Sobrecarga del operador de entrada
*lee un conjunto de un flujo de entrada
* @param is: flujo de entrada
* @param conj: conjunto a leer
* @return devuelve una referencia al flujo de entrada
**/
	friend istream & operator >> (istream & is, Soluciones & conj);
/**
* @brief Sobrecarga del operador de salida
*lee una char de un flujo de salida
* @param os: flujo de salida
* @param conj: conjunto a escribir
* @return devuelve una referencia al flujo de salida
**/
	friend ostream & operator << (ostream & os, Soluciones & conj);

};
/**
* @brief Sobrecarga del operador de entrada
*lee un conjunto de un flujo de entrada
* @param is: flujo de entrada
* @param conj: conjunto a leer
* @return devuelve una referencia al flujo de entrada
**/
istream & operator >> (istream & is, Soluciones & conj);
/**
* @brief Sobrecarga del operador de salida
*lee una char de un flujo de salida
* @param os: flujo de salida
* @param conj: conjunto a escribir
* @return devuelve una referencia al flujo de salida
**/
ostream & operator << (ostream & os, Soluciones & conj);
#endif