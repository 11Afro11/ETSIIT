/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 4
//
//  Escribir un programa que permita encriptar y desencriptar el contenido de un fichero de texto.
// Para encriptar sustituiremos cada letra (mayúsculas y minúsculas) por la letra que está p posi-
// ciones más adelante en el alfabeto (para las últimas letras ciclamos el alfabeto). Los caracteres
// que no sean letras se quedarán igual. Para desencriptar la sustitución será a la inversa. La
// llamada al programa se realizará con este esquema:
//
// Fichero: Codifica.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

//metodo que comprueba si se trata de una ayuscula o una minuscula

void CompruebaMayus(char compara, char &base, char & zeta){
	if(compara >= 'A' && compara <= 'Z'){
		base = 'A';
		zeta = 'Z';
	}
	if(compara >= 'a' && compara <= 'z'){
		base = 'a';
		zeta = 'z';
	}

}

//Funcion Encriptar

void Encriptar(ifstream & fi, ofstream & fo, char base, char zeta, int n){
	char c;
	c = fi.get();
	while(!fi.eof()){ 
		if(c != ' ' && c != '\t' && c != '\n'){
			CompruebaMayus(c, base, zeta);
			if(c + n > zeta){
				c = base + (n-(zeta-c));
			}
			else{
				c += n;
			}

		}
		fo << c;
		c = fi.get();
	}
}

//Funcion DesEncriptar

void DesEncriptar(ifstream & fi, ofstream &fo, char base, char zeta, int n){
	char c;
	c = fi.get();
	while(!fi.eof()){ 
		if(c != ' ' && c != '\t' && c != '\n'){
			CompruebaMayus(c, base, zeta);
			if(c - n < base){
				c = zeta - (n-(c - base));
			}
			else{
				c -= n;
			}
		}
		fo << c;
		c = fi.get();
	}
}



//metodo que comprueba si el ultimo parametro es correcto



int main(int argc, char **argv){


	//filtro de argumentos
	if(argc < 5){
		cerr<<"Faltan argumentos";
		exit(1);
	}

	//fichero de entrada y comprobacion de apertura
	ifstream fi;
	fi.open(argv[1]);

	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}

	//fichero de salida y comprobacion de apertura
	ofstream fo;
	fo.open(argv[2]);

	if (!fo) {
		cerr << "Error: no puedo crear "<<argv[2]<<endl;
		exit (1);
	}

	//El tercer argumento es el numero a Encriptarr o DesEncriptarr para codificar 
	int n = atoi(argv[3]);
	char c;

	//caracteres correspondientes a : a A z Z respectivamente


	char base;
	char zeta;

	//llamadas a las funciones dependiendo del ultimo argumento

	if(!strcmp(argv[4], "enc")){
		Encriptar(fi,fo, base, zeta,n);
	}

	else if(strcmp(argv[4], "desenc") == 0){
		DesEncriptar(fi,fo, base, zeta,n);
	}

	else{
		cerr <<endl <<"ultimo argumento no valido"<<endl;
		exit(1);
	}

	fi.close();
	fo.close();

	return(0);

}