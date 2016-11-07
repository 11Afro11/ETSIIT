/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// SESI�N PRACTICA 10
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
// din�mico y devuelve su direcci�n. 
// Por referencia, devuelve el n�mero de pesos (calificaciones)
// Comprueba que la suma sea 100. Si no es as�, aborta.

double * LeeCompruebaPesos (int & num_notas);
	
/***************************************************************************/
// Compara dos n�meros decimales.

bool Iguales (double uno, double dos, double precision);	

/***************************************************************************/
// Compone y devuelve una l�nea de "n" caracteres "c".

char * Linea (int n, char c);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
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
	// de compilaci�n, y se calculan a partir de los datos leidos . 
	int num_alumnos; 	// N�mero de alumnos.
	int num_notas; 		// N�mero de calificaciones.
	

	// Rellenar el vector din�mico de pesos y obtener el valor de "num_notas"
	// (el n�mero de pesos o valores de ponderaci�n copincide con el n�mero 
	// de calificaciones de cada alumno)
	
	double * pesos = LeeCompruebaPesos (num_notas);	
	
	// Si la funci�n devuelve la direcci�n nula significa que la suma de los 
	// pesos no es la correcta (100.0), por lo que el programa debe abortar.
	if (!pesos) {
		cerr << "Error: los pesos no suman 100" << endl;
		exit (1); 
	}
	
	// Crear un objeto "ClaseDeAlumnos" vac�o
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
// Compara dos n�meros decimales
//
// Recibe: "uno" y "dos", los dos n�meros a comparar.
//		   "precisi�n", la precisi�n deseada en la comparaci�n. 
// Devuelve: true, si se consideran iguales "uno" y "dos". En definitiva, si 
//			 la distancia entre "uno" y "dos" es menor que "precisi�n".

bool Iguales (double uno, double dos, double precision)
{
	return (fabs(uno-dos) <= precision);	
}

/***************************************************************************/
/***************************************************************************/
// Compone y devuelve una l�nea de caracteres
// Recibe: 	
//		n, n�mero de caracteres de la l�nea. 
//		c, el car�cter que se emplear� en la l�nea.

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
// din�mico y devuelve su direcci�n. 
// Por referencia, devuelve el n�mero de pesos (calificaciones)
// Comprueba que la suma sea 100. Si no es as�, abortar� a la vuelta.
// Recibe: 	
//		num_pesos, cantidad de casillas reservadas en el vector. 
//			Como se recibe en una referencia y la funci�n modifica el valor 
//			de "num_pesos", en realidad se modifica el valor del par�metro 
//			real usado en la llamada.
// Devuelve: la direcci�n de memoria del vector de pesos.

double * LeeCompruebaPesos (int & num_pesos)
{
	// Lectura de los pesos asignados a cada calificaci�n y comprobaci�n.  

	cout << "LEYENDO PESOS" << endl << endl; 	
	cout << "Numero de notas: ";
	cin >> nuAVIER FUENTES BARRAGANReserva de memoria paar el vector din�mico de pesos
	double * pesos_leidos = new double [num_pesos]; 
	cout << "Peso de cada nota: ";
	// Lectura y almacenamiento de los pesos 		
	for (int i=0; i<num_pesos; i++) 
		cin >> pesos_leidos[i]; 
	
	cin.ignore(TAM_CAD,'\n'); // Limpiar buffer de entrada
		
	// Comprobaci�n

	double suma_pesos = 0.0;
	for (int i=0; i<num_pesos; i++) 
		suma_pesos += pesos_leidos[i]; 
	
	// Si no suman 100 se abortar� la ejecuci�n del programa
	
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
 
