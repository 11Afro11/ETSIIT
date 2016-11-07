/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
// EJERCICIO 2 - Previo (2)
//
// Lee los datos, los almacena en un vector y los muestra, sin ningún tipo 
// de procesamiento.
// 
// Fichero: Calificaciones_Lectura_y_Almacenamiento.cpp
//
/***************************************************************************/


#include "Calificaciones.h"
using namespace std;

/***************************************************************************/



int main (void)
{
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Las dos variables siguientes serán calculadas por sendas funciones, 
	// y su valor se obtiene a través de una referencia. 
	// Se desconocen en tiempo de compilación, y se calculan a partir de los
	// datos leidos por el programa. 
	// Son dos variables básicas que determinan el tamaño real de los dos 
	// tipos de vectores dinámicos que se gestionan en este programa: 
	//	1) El vector de alumnos (vector de datos RegAlumno).
	//	2) Los vectores de calificaciones (uno por alumno, de datos double. 
	
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
	
	// Rellenar el vector dinámico de alumnos y obtener "num_alumnos"
	
	RegAlumno * PrimeroC = LeeDatosAlumnos (num_notas, num_alumnos);
	
	cout << endl;
	cout << "Numero total de alumnos = " << num_alumnos << endl; 	
	cout << endl;
	
	// Calcular nota media de los alumnos
	CalculaNotaMedia (PrimeroC, num_alumnos, pesos, num_notas);
	
	// Mostrar listado 
	MuestraAlumnos (PrimeroC, num_alumnos, num_notas);

	// Ordenar 
	Ordena_por_Insercion (PrimeroC, num_alumnos);
	
	// Mostrar listado ordenado
	MuestraAlumnos (PrimeroC, num_alumnos, num_notas);
	
	// Liberar memoria
	LiberaMemoria (pesos, PrimeroC, num_alumnos);
	
	return (0);
}

/***************************************************************************/

