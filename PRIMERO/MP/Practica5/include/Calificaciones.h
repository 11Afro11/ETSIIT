// PROTOTIPOS DE LAS FUNCIONES
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
// El tipo de dato "RegAlumno" se emplea para representar los datos de 
// interés de cada alumno.
// Como el conjunto de datos es fijo y heterogéneo se emplea un struct.


#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>

	
struct RegAlumno {
	
	double * notas;		// Vector dinámico de notas
	char   * nombre; 	// Vector dinámico de caracteres (cad. clásica)
	
	double nota_media;	// Calificación media del alumno
};

// Constantes asociadas al vector dinámico de alumnos	 	
const int TAM_INICIAL = 85;	// Tamaño inicial del vector

// Máximo número de caracteres permitido en cadenas. Se supone que apellidos 
// más nombre no superá los 100 (realmente 99) caracteres.  
const int TAM_CAD = 100; 
		
// Cadena que sirve de "terminador" para la lectura de datos de alumnos.  


/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
// Lee los pesos de las calificaciones, los guarda en un vector 
// dinámico y devuelve su dirección. 
// Por referencia, devuelve el número de pesos (calificaciones)
// Comprueba que la suma sea 100. Si no es así, aborta.

double * LeeCompruebaPesos (int & num_pesos);
	
/***************************************************************************/	
// Lee los datos de los alumnos (nombre y notas), los guarda en un 
// vector dinámico y devuelve su dirección. 
// Por referencia, devuelve el número de alumnos.

RegAlumno * LeeDatosAlumnos (int num_notas, int & num_alumnos);

/***************************************************************************/	
// Redimensiona un vector dinámico de acuerdo al tipo de redimensión 
// indicado. Copia todos los datos en el nuevo vector.

// VUESTRA TAREA: 

RegAlumno * Redimensiona (RegAlumno * p,  int &capacidad, int num_notas);

/***************************************************************************/
// Calcula la nota media de los "num_alumnos" alumnos del vector "alumnos"
// ponderando las notas por los "num_pesos" del vector "pesos".

// VUESTRA TAREA: 

void CalculaNotaMedia (RegAlumno * alumnos, int num_alumnos, double *pesos, int num_pesos);

/***************************************************************************/
// Muestra el contenido del vector de alumnos.

void MuestraAlumnos (RegAlumno *p, int num_alumnos, int num_notas);

/***************************************************************************/
// Ordena el contenido del vector de alumnos de acuerdo a la nota media.

// VUESTRA TAREA: 

void Ordena_por_Insercion (RegAlumno *p, int num_alumnos);

/***************************************************************************/
// Libera la memoria ocupada por las estructuras de datos dinámicas.

void LiberaMemoria (double * & pesos, RegAlumno * & alumnos, int num_alumnos);
		
/***************************************************************************/
// Compara dos números decimales.

bool Iguales (double uno, double dos, double precision);	

/***************************************************************************/
// Compone y devuelve una línea de "n" caracteres "c".

char * Linea (int n, char c);

#endif