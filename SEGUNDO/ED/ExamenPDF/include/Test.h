#ifndef TEST
#define TEST

#include "Test.h"
#include "ConjuntoPreguntas.h"
#include "Pregunta.h"
/**
* @file Test.h
* @brief Clase Test, en ella abstraemos el TDA test con los siguientes atributos:
*Segun mi definicion del TDA Test se compone de un string con las preguntas,
*un int con el numero de preguntas
**/
class Test{
private:
	Pregunta *examen;
	int numPreg;

/**
* @brief Reserva
*se encarga de reservar memoria para el vector dinamico de preguntas
* @param num: tamaño de memoria a reservar
**/
	void Reserva(int num);
/**
* @brief Copia
*se encarga de copiar los elementos de otro test
* @param otro: test a copiar
**/
	void Copia(const Test &otro);
/**
* @brief Borra
*Borra la memoria reservada
**/
	void Borra();

public:

/**
* @brief Constructor por defecto
*inicializa pordefecto los valores del test
**/
	Test();
/**
* @brief Constructor con parametros
*inicializa los valores de test segun ciertos parametros
* @param preguntas: conjunto de preguntas del que elegira aleatoriamente las preguntas del test
* @param numero: numero de preguntas que tiene el tipo test
**/
	Test(const ConjuntoPreguntas & preguntas, int numero);
/**
* @brief Constructor de copia
*inicializa los valores de test a los de otro test
* @param otro_test: test a copiar
**/
	Test(const Test & otro_test);
/**
* @brief destructor de test
*Borra la memoria reservada
**/
	~Test();
/**
* @brief Size
*Devuelve el tamaño utilizado del test
* @returnt tamaño del test(int)
**/	
	int Size();
/**
* @brief Operador de acceso
*Devuelve el valor del vector en la posicion deseada, este operador permite modificacion
* @param pos: posicion del vector que queremos consultar
* @return Pregunta &
**/
	Pregunta & operator [] (int pos);
/**
* @brief Sobrecarga del operador de salida
*lee una pregunta de un flujo de salida
* @param os: flujo de salida
* @param exam: test a escribir
* @return devuelve una referencia al flujo de salida
**/
	friend ostream & operator << (ostream & os, const Test &exam);

};
/**
* @brief Sobrecarga del operador de salida
*lee una pregunta de un flujo de salida
* @param os: flujo de salida
* @param exam: test a escribir
* @return devuelve una referencia al flujo de salida
**/
ostream & operator << (ostream & os, const Test &exam);
/**
* @brief Esta
* comprueba si un entero se encuentra dentro del vector
* @param vector: vector de entero
* @param dato: dato a buscar
* @param util: tamaño del vector
* @return true si esta false si no esta
**/
bool Esta(const int * vector, int dato, int util);
#endif