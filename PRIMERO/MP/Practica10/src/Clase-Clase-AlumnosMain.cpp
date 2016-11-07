/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// SESIÓN PRACTICA 10
//
// Fichero: Gestion-ClaseDeAlumnos-ClaseAlumno-Lista.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "Clase-Clase-Alumnos.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/
// PROTOTIPOS DE LAS FUNCIONES
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
// Lee los pesos de las calificaciones, los guarda en un vector 
// dinámico y devuelve su dirección. 
// Por referencia, devuelve el número de pesos (calificaciones)
// Comprueba que la suma sea 100. Si no es así, aborta.

double * LeeCompruebaPesos (int & num_notas);
	
/***************************************************************************/
// Compara dos números decimales.

bool Iguales (double uno, double dos, double precision);	

/***************************************************************************/
// Compone y devuelve una línea de "n" caracteres "c".

char * Linea (int n, char c);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	if (argc > 2) {
		cerr << "Error:    Demasiados parametros." << endl;
		cerr << "Formato:  " << argv[0] << " [-v]" << endl;
		exit (1); 	
	}
	
	bool verbose = false;	
	
	if (argc==2) {
	
		if (strcmp(argv[1],"-v")) {
			cerr << "Error:    argumento incorrecto." << endl;
			cerr << "Formato:  " << argv[0] << " [-v]" << endl;
			exit (2); 		
		}
		else verbose = true;
	}
	
	// Los valores de las dos variables siguientes se desconocen en tiempo 
	// de compilación, y se calculan a partir de los datos leidos . 
	int num_alumnos; 	// Número de alumnos.
	int num_notas; 		// Número de calificaciones.
	

	// Rellenar el vector dinámico de pesos y obtener el valor de "num_notas"
	// (el número de pesos o valores de ponderación copincide con el número 
	// de calificaciones de cada alumno)
	
	double * pesos = LeeCompruebaPesos (num_notas);	
	
	// Si la función devuelve la dirección nula significa que la suma de los 
	// pesos no es la correcta (100.0), por lo que el programa debe abortar.
	if (!pesos) {
		cerr << "Error: los pesos no suman 100" << endl;
		exit (1); 
	}
	
	// Crear un objeto "ClaseDeAlumnos" vacío
	ClaseDeAlumnos PrimeroC;
	
	// Los pesos son correctos: copiar los datos en el objeto "PrimeroC"
	PrimeroC.EstablecePesos(pesos, num_notas);	

	// Lee los datos de los alumnos 
	cout << endl << Linea (80, '-') << endl;	
	PrimeroC.LeeDatosAlumnos (); 

	// Mostrar listado 
	cout << endl << Linea (80, '-') << endl;	
	PrimeroC.Listado ("Listado antes de calcular las medias");
	cout << endl << Linea (80, '-') << endl;	
	
	// Calcular nota media de los alumnos
	PrimeroC.CalculaNotaMedia ();

	// Mostrar listado 
	cout << endl << Linea (80, '-') << endl;	
	PrimeroC.Listado ("Listado despues de calcular las medias");
	cout << endl << Linea (80, '-') << endl;	

	// Ordenar 
	PrimeroC.Ordena_por_Insercion();
	
	// Mostrar listado 
	cout << endl << Linea (80, '-') << endl;	
	PrimeroC.Listado ("Listado despues de ordenar");
	cout << endl << Linea (80, '-') << endl;	
	
	return (0);
}

/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// Compara dos números decimales
//
// Recibe: "uno" y "dos", los dos números a comparar.
//		   "precisión", la precisión deseada en la comparación. 
// Devuelve: true, si se consideran iguales "uno" y "dos". En definitiva, si 
//			 la distancia entre "uno" y "dos" es menor que "precisión".

bool Iguales (double uno, double dos, double precision)
{
	return (fabs(uno-dos) <= precision);	
}

/***************************************************************************/
/***************************************************************************/
// Compone y devuelve una línea de caracteres
// Recibe: 	
//		n, número de caracteres de la línea. 
//		c, el carácter que se empleará en la línea.

char * Linea (int n, char c)
{
	char * la_linea = new char [n];
	memset (la_linea, c, n-1);
	la_linea[n-1] = '\0';
	
	return (la_linea);
}

/***************************************************************************/
/***************************************************************************/
// Lee los pesos de las calificaciones, los guarda en un vector 
// dinámico y devuelve su dirección. 
// Por referencia, devuelve el número de pesos (calificaciones)
// Comprueba que la suma sea 100. Si no es así, abortará a la vuelta.
// Recibe: 	
//		num_pesos, cantidad de casillas reservadas en el vector. 
//			Como se recibe en una referencia y la función modifica el valor 
//			de "num_pesos", en realidad se modifica el valor del parámetro 
//			real usado en la llamada.
// Devuelve: la dirección de memoria del vector de pesos.

double * LeeCompruebaPesos (int & num_pesos)
{
	// Lectura de los pesos asignados a cada calificación y comprobación.  

	cout << "LEYENDO PESOS" << endl << endl; 	
	cout << "Numero de notas: ";
	cin >> nuAVIER FUENTES BARRAGANReserva de memoria paar el vector dinámico de pesos
	double * pesos_leidos = new double [num_pesos]; 
	cout << "Peso de cada nota: ";
	// Lectura y almacenamiento de los pesos 		
	for (int i=0; i<num_pesos; i++) 
		cin >> pesos_leidos[i]; 
	
	cin.ignore(TAM_CAD,'\n'); // Limpiar buffer de entrada
		
	// Comprobación

	double suma_pesos = 0.0;
	for (int i=0; i<num_pesos; i++) 
		suma_pesos += pesos_leidos[i]; 
	
	// Si no suman 100 se abortará la ejecución del programa
	
	if (!Iguales (suma_pesos, 100.0, 0.001)) { 
	
		// Liberar la memoria ocupada hasta el momento
		delete [] pesos_leidos;
		pesos_leidos = 0;
	}
	
	else {
		
		cout << "Los pesos empleados para ponderar las notas son: " << endl;
		
		for (int p=0; p<num_pesos; p++)
			cout << "\tNota " << setw(2) << (p+1) << " = " 
			     << setw(6) << setprecision(2) << right 
				 << pesos_leidos[p] << "%" << endl;
	}

	return (pesos_leidos);
}

/***************************************************************************/
/***************************************************************************/
 
