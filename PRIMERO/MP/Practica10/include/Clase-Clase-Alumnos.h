/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Declaración de la clase ClaseDeAlumnos
//
// Fichero: Clase-ClaseDeAlumnos-ClaseAlumno-Lista.h
//
/***************************************************************************/

#ifndef CLASE_CLASE_ALUMNOS
#define CLASE_CLASE_ALUMNOS

#include "Clase-Alumnos.h"
 
/***************************************************************************/
// Comentar cuando no se quiera ejecutar en modo DEBUG
#define DEBUG
/***************************************************************************/

// Máximo número de caracteres permitido en cadenas. Se supone que apellidos 
// más nombre no superá los 100 (realmente 99) caracteres.  
const int TAM_CAD = 100; 


		
// Declaración del tipo asociado a cada nodo de la lista
struct TipoNodo 
{
	Alumno info;      // Valor guardado en el nodo
	TipoNodo * sig;   // Puntero al siguiente nodo
};

/////////////////////////////////////////////////////////////////////////////

class ClaseDeAlumnos 
{
private:

	TipoNodo * datos; // Dirección del primer nodo de datos de alumnos. 
	double   * pesos; // Dirección del vector dinámico de pesos.	
	
	int numero_alumnos;	 // Número de alumnos de la clase (=número de nodos).
	int numero_notas;	 // Número de calificaciones (=número de pesos). 
	
	// PRE: numero_alumnos >= 0
	// PRE: numero_notas >= 0
		
public:

	/***********************************************************************/
	// Constructor sin argumentos: crea una clase vacia.
	ClaseDeAlumnos (void);

	/***********************************************************************/
	// Constructor con argumentos: crea una clase con "n_alumnos" almunos y 
	// "n_notas" notas. 
	// PRE: n_alumnos > 0
	ClaseDeAlumnos (int n_alumnos, int n_notas);  

	/***********************************************************************/
	// Constructor de copia
	ClaseDeAlumnos (const ClaseDeAlumnos & otro);
		
	/***********************************************************************/
    // Destructor
    ~ClaseDeAlumnos (void);

	/***********************************************************************/
    // Consulta si la clase esta vacia
	bool EstaVacia(void) const;
		
	/***********************************************************************/
	// Devuelve el numero de alumnos
	int  NumeroAlumnos (void) const;
	
	/***********************************************************************/
	// Devuelve el numero de notas
	int  NumeroNotas (void) const;

	/***********************************************************************/
	// Inicializa los campos privados "numero_notas" y "pesos", reservando la 
	// memoria precisa para los pesos
	void EstablecePesos (double * los_pesos, int num_pesos);
	
	/***********************************************************************/
	// Inicializa los campos privados "datos" y "numero_alumnos" leyendo los 
	// datos de cin 
	void LeeDatosAlumnos (void); 

	/***********************************************************************/
	// Muestra un listado de los alumnos  
	void Listado (const char * msg) const;	
	
	/***********************************************************************/
	// Calcula la nota media de los alumnos. Se emplean los valores del 
	// campo "pesos" para la ponderación. 	
	void CalculaNotaMedia (void);
	
	/***********************************************************************/
	// Ordena los datos de los alumnos usando como clave la nota media.
	// Se emplea el algoritmo de ordenación por inserción.
	void Ordena_por_Insercion (void);

	/***********************************************************************/
	// Busca un alumno con el DNI especificado. Devuelve la posición del 
	// primer nodo coincidente, o -1 si no se encuentra.
	/***********************************************************************/
	int Busca (char * DNI);
	
	/***********************************************************************/
    // Métodos de acceso para escribir/leer en una posición dada: 
    // NO MODIFICAN EL NÚMERO DE NODOS
	/***********************************************************************/

	Alumno & operator [] (int pos);
	Alumno & operator [] (int pos) const;

	/***********************************************************************/
    // Métodos que modifican el tamaño de la lista 
  	// MODIFICAN EL NÚMERO DE NODOS
	/***********************************************************************/
	// Aniade (al final) un nuevo elemento
	//
	// PRE: El objeto que se va a añadir ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).
	void Aniade (Alumno valor);

    // Borra el primer nodo que contiene el DNI indicado
	void Elimina (char * DNI);

	/***********************************************************************/
	// Inserta un nuevo elemento en la posición "pos_insertar"
	// PRE: 1 <= pos_insertar <= tamanio+1
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
	// 		 ejecución del método Aniade()
	//
	// PRE: El objeto que se va a insertar ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).
	void Inserta (Alumno valor, int pos_insertar);

	/***********************************************************************/
	// Borra el elemento de la posición "pos_borrar" 
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	void Borra (int pos_borrar);
	
	/***********************************************************************/
	// Operador de asignación
	ClaseDeAlumnos & operator =  (const ClaseDeAlumnos & otro);
		
	/***********************************************************************/

private:
		
	/***********************************************************************/
	// Petición / liberación de memoria
	void ReservarMemoria (int num_alumnos, int num_notas);
	void LiberarMemoria (void); 

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
	void CopiarDatos (const ClaseDeAlumnos & otro);			
		
};

/////////////////////////////////////////////////////////////////////////////

#endif
 
