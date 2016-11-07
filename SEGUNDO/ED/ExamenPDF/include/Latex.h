#ifndef LATEX
#define LATEX

#include <iostream>
#include <cstring>
using namespace std;

/**
* @file Latex.h
* @brief Cabecera
*Inserta en el flujo de salida del examen la cabecera de latex
* @param os: flujo de salida del examen
* @param nombre del archivo en el que se encuentra
**/
void Cabecera(ostream & os, string nombre);
/**
* @brief Enumerate
*Inserta en el flujo de salida del examen la las cabeceras delenumerate de latex
* @param os: flujo de salida del examen
* @param nombre del archivo en el que se encuentra
**/
void Enumerate(ostream & os, string nombre);
/**
* @brief Item
*Inserta en el flujo de salida del examen la los items
* @param os: flujo de salida del examen
* @param nombre del archivo en el que se encuentra
**/
void Item(ostream & os,string nombre, string item);

#endif