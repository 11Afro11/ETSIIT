/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 7
// EJERCICIO 4b
//
//Escriba dos programas para transformar ficheros con datos correspondientes a una serie de
//grupos de valores reales (como están descritos en el problema 5 de la Relación de Problemas
//VI), para transformar entre formato binario y texto:
//
// Fichero: Bin2text.cpp
//
/***************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main (int argc, char **argv)
{
	const int TAM_BUFFER = 1024; // Num. de bytes del buffer de lectura
	char buffer [TAM_BUFFER];
	 // Buffer de lectura
	ifstream fi; //Flujo de entrada
	ofstream fo; //Flujo de salida
	if (argc != 3) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <fichE> <fichS>\n";
		exit (1);
	}

	fi.open (argv[1]);
	 // Apertura (para lectura)
	// en modo binario
	if (!fi) {
		cerr << "Error: no puedo abrir " << argv[1] << endl;
		exit (1);
	}

	fo.open (argv[2], ios::binary);
	 // Apertura (para escritura)
	// en modo binario
	if (!fo) {
		cerr << "Error: no puedo crear " << argv[2] << endl;
		exit (1);
	}
	// Procesamiento: lectura por bloques del fichero asociado a "fi",
	// copiando los datos leidos en "buffer" y escribiendo despues
	// los datos de "buffer" en el fichero asociado a "fo"

	while (fi.read (reinterpret_cast<char*>(buffer), TAM_BUFFER))
		fo.write (buffer, TAM_BUFFER);

	//En cada iteración se intentan leer TAM_BUFFER bytes a través
	// de "fi". Mientras sea posible, se escribirán esos mismos datos
	// en el fichero asociado a "fo".
	//Cuando no sea posible (último bloque) se sale del ciclo.

	fo.write(buffer, fi.gcount());

	// Escribir exactamento los datos
	// que pudieron leerse en la
	// última operación read().

	fi.close ();

	 // Cerrar el fichero asociado a "fi"

	fo.close ();

	 // Cerrar el fichero asociado a "fo"
	
	return (0);
}
