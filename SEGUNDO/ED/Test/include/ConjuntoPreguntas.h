#ifndef CONJUNTOPREGUNTAS
#define CONJUNTOPREGUNTAS

#include "Pregunta.h"
/**
* @file ConjuntoPreguntas.h
* @brief Clase ConjuntoPregunta, en ella abstraemos el TDA ConjuntoPregunta con los siguientes atributos:
*Segun mi definicion del TDA ConjuntoPregunta se compone de un string con las preguntas almacenadas,
*un int con el numero de preguntas y otro int con el tamaño maximo del conjunto
**/
class ConjuntoPreguntas{
private:
	Pregunta * preguntas;
	int num_preguntas;
	int tam;

/**
* @brief Reserva
* @se encarga de reservar memoria para el vector dinamico de preguntas
* @param tam: tamaño de memoria a reservar
**/
	void Reserva(int tam);
/**
* @brief Copia
*copia los datos de un conjunto a otro
* @param otro: pregunta a copiar
**/
	void Copia(const ConjuntoPreguntas & otro);
/**
* @brief Borra
*Borra la memoria reservada
**/
	void Borra();
/**
* @brief Redimensiona
*Cambia el tamaño del vector cuando sea necesario
* @pre num_preguntas == tam
**/
	void Redimensiona();
public:

/**
* @brief ConjuntoPreguntas
*Constructor por defecto
**/
	ConjuntoPreguntas();
/**
* @brief ConjuntoPreguntas
*Constructor de copia
* @param otro: conjunto a copiar
**/
	ConjuntoPreguntas(const ConjuntoPreguntas & otro);
/**
* @brief ~ConjuntoPreguntas Destructor
**/
	~ConjuntoPreguntas();
/**
* @brief Operador de acceso, Devuelve el valor del vector en la posicion deseada, este operador permite modificacion
* @param num: posicion del vector que queremos consultar
* @return Pregunta &
**/
	Pregunta & operator [] (int num);
/**
* @brief Operador de acceso. Devuelve el valor del vector en la posicion deseada, este operador NO permite modificacion
* @param num: posicion del vector que queremos consultar
* @return Pregunta &
**/
	Pregunta & operator [] (int num)const;
/**
* @brief Add
*Agregaun elemento al vector dinámico
* @param nueva: Pregunta que deseamos agregar al vector
**/
	void Add(const Pregunta & nueva);
/**
* @brief Esta
* Metodo que comprueba si una pregunta se encuentra en el conjunto
* @param nueva: pregunta que comprobamos
* @return true | false
**/
	bool Esta(const Pregunta & nueva)const;
/**
* @brief Size
*Devuelve el tamaño utilizado del conjunto
* @returnt tamaño del conjunto(int)
**/
	int Size()const;
/**
* @brief Valida
*Comprueba si una pregunta es valida según ciertas condiciones
* @param nueva: Pregunta que vamos a comprobar
* @pre vector de preguntas != null
* @pre tamaño vector >= 2
**/
	bool Valida(const Pregunta & nueva)const;

/**
* @brief Sobrecarga del operador de entrada
*lee un conjunto de un flujo de entrada
* @param is: flujo de entrada
* @param conj: conjunto a leer
* @return devuelve una referencia al flujo de entrada
**/
	friend istream & operator >> (istream & is, ConjuntoPreguntas & conj);
/**
* @brief Sobrecarga del operador de salida
*lee una pregunta de un flujo de salida
* @param os: flujo de salida
* @param conj: conjunto a escribir
* @return devuelve una referencia al flujo de salida
**/
	friend ostream & operator << (ostream & os, ConjuntoPreguntas & conj);

};
/**
* @brief Sobrecarga del operador de entrada
*lee un conjunto de un flujo de entrada
* @param is: flujo de entrada
* @param conj: conjunto a leer
* @return devuelve una referencia al flujo de entrada
**/
istream & operator >> (istream & is, ConjuntoPreguntas & conj);
/**
* @brief Sobrecarga del operador de salida
*lee una pregunta de un flujo de salida
* @param os: flujo de salida
* @param conj: conjunto a escribir
* @return devuelve una referencia al flujo de salida
**/
ostream & operator << (ostream & os, ConjuntoPreguntas & conj);
#endif