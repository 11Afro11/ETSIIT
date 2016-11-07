/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 3
//
//  Escribir un programa que reciba como parámetros tres nombres de ficheros de texto. Los dos
// primeros ficheros contienen números reales y están ordenados. El programa tomará los datos
// de esos ficheros y los irá copiando ordenadamente en el tercer fichero, de forma que al finalizar
// esté también ordenado.
//
// Fichero: MezclaFicheros.cpp
//
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){

	//comprobamos el numero de argumentos
	if(argc < 4){
		cerr<<"Faltan argumentos";
		exit(1);
	}

	//declaramos los flujos de entrada y comprobamos si pueden abrirse
	ifstream fi;
	fi.open(argv[1]);

	if (!fi) {
		cerr << "Error: no puedo abrir "<<argv[1]<<endl;
		exit (1);
	}

	ifstream fo;
	fo.open(argv[2]);

	if (!fo) {
		cerr << "Error: no puedo abrir "<<argv[2]<<endl;
		exit (1);
	}

	//declaramos el fichero de salida y comprobamos si puede crearse
	ofstream sol;
	sol.open(argv[3]);

	if (!sol) {
		cerr << "Error: no puedo crear "<<argv[3]<<endl;
		exit (1);
	}

	//declaramos las variables
	int c;
	int q;
	
	//primear lectura
	fi >> c;
	fo >> q;

	//primera comparacion
	if(c>=q){
		sol << c << " ";	//si uno es mayor que otro volvemos a leer el el menos
		fo >> c;
	}
	else{
		sol << q << " ";
		fi >> q;
	}

	//continuamos con la lectura del mismo modo
	while(!fi.eof() && !fo.eof()){

		if(c>=q){
			sol << c << " ";
			fo >> c;
		}
		else{
			sol << q << " ";
			fi >> q;
		}
	}

	//si acaba algun fichero antes que otro terminamos de leer el que 
	//aun no este acabado
	if(fi.eof()){
		while(!fo.eof()){
			sol << q << " ";
			fo >> q;
		}
	}

	if(fo.eof()){
		while(!fi.eof()){
			sol << c << " ";
			fi >> c;
		}
	}

	return(0);
}