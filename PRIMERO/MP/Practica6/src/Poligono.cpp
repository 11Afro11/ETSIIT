/*********************************************************************/
// METODOLOGÍA DE LA PROGRANACIÓN
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 6
//
/*	

funciones del ejercicio poligono desarrolladas

*/
/*********************************************************************/
#include <iostream>
#include "Poligono.h"
#include <cstring>
#include <cmath>

using namespace std;


Poligono CreaEstructuraGeometrica (Punto2D *vector, int total_utilizados){


	Poligono fin, primero;

	int i = 0;

	if(total_utilizados != 0){
	
		// Pedimos memoria para el primer nodo
		primero = new Nodo;
		primero->punto.x = vector[i].x;
		primero->punto.y = vector[i].y;

		 // Guardar "n" en el nuevo nodo

		primero->sigpunto = primero;

		// Este nodo es, por ahora, el último
		// El ultimo tambien es el primero (solo hay uno)

		fin = primero;

		// Segunda lectura

		
		for(int j = 1; j < total_utilizados; j++){
			// Pedimos memoria para el siguiente nodo, y enlazamos

			fin->sigpunto = new Nodo;
			fin = fin->sigpunto; // Actualizar posicion del ultimo
			fin->sigpunto = primero;
			fin->punto.x = vector[j].x;
			fin->punto.y = vector[j].y; // Guardar en el nuevo nodo
			

		}
	} // if (x != 0)

	return primero;

}


void MuestraEstructuraGeometrica (Poligono  p)
{
	Poligono aux = p; // Colocar "aux" al principio
	cout << (aux->punto).x << "," << (aux->punto).y << " "; // Mostrar valor
	aux = aux->sigpunto;
	while (aux != p) {
		cout << (aux->punto).x << "," << (aux->punto).y << " "; // Mostrar valor
		aux = aux->sigpunto;
		// Adelantar "aux"
	}
	cout << (aux->punto).x << "," << (aux->punto).y << " "; // Mostrar valor

	cout << endl;
}

Punto2D * Redimensiona (Punto2D *  p,  int & capacidad)
{
	
	Punto2D * aux;
	aux = p;
	p = new Punto2D[capacidad+1];


	memcpy(p, aux, sizeof(Punto2D)*capacidad);
	
	delete[] aux;
	capacidad++;

	return p;
}


void LiberaEspacio(Poligono &poligono){
	
	Poligono elim = poligono->sigpunto;
	Poligono sig = elim->sigpunto;

	while(sig != poligono){
		delete elim;
		elim = sig;
		sig = sig->sigpunto;
	}
	delete sig;
}

int CuentaCaras(const Poligono &poligono){
	Poligono cuenta = poligono;
	int contador = 1;
	cuenta = cuenta->sigpunto;
	while(cuenta != poligono){
		cuenta = cuenta->sigpunto;
		contador++;
	}
	return contador;
}
/*
void PintaRecta(Poligono poligono){

	Poligono recorre = poligono;
	Poligono siguiente = recorre->sigpunto;

	PintaRecta(recorre->punto, siguiente->punto);

	recorre = recorre->sigpunto;
	siguiente = siguiente->sigpunto;

	while(recorre != poligono){
		PintaRecta(recorre->punto, siguiente->punto);
		recorre = recorre->sigpunto;
		siguiente = siguiente->sigpunto;
	}
}
*/

Poligono TrianguloCuadrado(Poligono cuadrado){

	Poligono triangulos;
	Poligono aux = cuadrado;
	triangulos = cuadrado;
	int contador = 1;

	aux = aux->sigpunto;
	triangulos->sigpunto = aux;
	triangulos =triangulos->sigpunto;

	while(triangulos != cuadrado){
		if(contador == 2){
			triangulos->sigpunto = cuadrado;
			triangulos = triangulos->sigpunto;
			triangulos->sigpunto = aux;
		}
		aux = aux->sigpunto;
		triangulos->sigpunto = aux;
		triangulos =triangulos->sigpunto;
		contador++;
	}

	return triangulos;

}


Poligono TrianguloCentral (Poligono triangulo){

	Poligono central;
	central = new Nodo;
	Poligono aux = central;

	for(int i = 0; i < 3 ; i++){
		aux->punto.x = (central->punto.x + central->sigpunto->punto.x)/2;
		aux->punto.y = (central->punto.y + central->sigpunto->punto.y)/2;
		aux->sigpunto = central;

	}
	return central;
}

Poligono Circunferencia(Punto2D centro, double radio, double a){
	Poligono circulo = new Nodo;
	Poligono aux = circulo;
	int contador = 0; 
	while(a <= 360){
		a = a * contador;
		circulo->punto.x =  centro.x + radio * cos(a);
		circulo->punto.y =  centro.y + radio * sin(a);
		aux->sigpunto = new Nodo;
		aux = aux->sigpunto;
		contador ++;
	}
		

}
