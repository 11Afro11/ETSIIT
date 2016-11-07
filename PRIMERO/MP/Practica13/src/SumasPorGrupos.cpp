/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// EJERCICIO 5
//
//  Se dispone de ficheros de texto que contienen un número indeterminado de líneas, cada una
// de ellas con los datos correspondientes a una serie de grupos de valores reales.
// Escribir un programa que escriba en la salida estándar una línea de resultado por cada línea
// de entrada, y en cada línea mostrará las sumas de los valores de cada grupo que la componen.
//
// Fichero: SumasPorGrupos.cpp
//
/***************************************************************************/



#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

void Suma(istream & in){

	int u;
	int m;
	double n; 
	double sum = 0;

	//bucle de lectura y tratamiento de flujo

	while(!in.eof()){
		in>> u;
		for(int i = 0; i < u; i++){
			in >> m;
			for(int j = 0; j< m; j++){
				in >>n;
				sum += n;
			}

			cout << sum <<" ";
			sum = 0;
		}
		cout << endl;
		
	}
	
}

int main(int argc, char **argv){

	
	//diferencia de tratamiento en funcion de los parametros	

	if(argc == 2){
		//declaramos un flujo
		ifstream fi;
		fi.open(argv[1]);

		//comprobamos la lectura

		if (!fi) {
			cerr << "Error: no puedo abrir "<<argv[1]<<endl;
			exit (1);
		}

		//llamamos a la funcion suma

		Suma(fi);

		//cerramos el fichero

		fi.close();
	}
	else if(argc == 1){
		//llamamos a la funcion suma con cin
		Suma(cin);
	}
	else{
		cerr << "Error: Numero de argumentos no valido.";
		exit(1);
	}
	return(0);
}