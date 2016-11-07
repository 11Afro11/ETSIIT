/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Declaración de la clase Alumno
//
// Fichero: Clase-Alumno.h
//
/***************************************************************************/

#ifndef CLASE_ALUMNO
#define CLASE_ALUMNO

/////////////////////////////////////////////////////////////////////////////
// El tipo de dato "Alumno" se emplea para representar los datos de 
// interés de cada alumno.

class Alumno
{
private:

	double * notas;		// Vector dinámico de notas
	int 	 num_notas; // Número de notas
	
	char   * nombre; 	// Vector dinámico de caracteres (cad. clásica)
	char   * DNI;    	// Vector dinámico de caracteres (cad. clásica)		
	
	double nota_media;	// Calificación media del alumno
	
public:
	/***********************************************************************/
    // Constructores / destructor
    
	/***********************************************************************/
	// Constructor sin argumentos: crea una clase vacia.
	Alumno (void);

	/***********************************************************************/
	// Constructor con argumentos: crea un objeto "Alumno" inicializando los 
	// cammpos con los valores suministrados. 
	Alumno (char * el_nombre,char * el_DNI,double * las_notas,int num_notas);
	
	/***********************************************************************/
	// Constructor de copia
	Alumno (const Alumno & otro);
		
	/***********************************************************************/
    // Destructor
    ~Alumno (void);

	/***********************************************************************/
    // Métodos de lectura

	/***********************************************************************/
	// Devuelve el nombre de un alumno
	char *  NombreAlumno (void) const;
	
	/***********************************************************************/
	// Devuelve el DNI de un alumno
	char *  DNIAlumno (void) const;
	
	/***********************************************************************/
	// Devuelve las notas de un alumno
	const double *  NotasAlumno (void) const;
	
	/***********************************************************************/
	// Devuelve el número de notas registradas de un alumno
	int NumNotasAlumno (void) const;
	
	/***********************************************************************/
	// Devuelve la nota media de un alumno
	double  NotaMediaAlumno (void) const;
	
	/***********************************************************************/
    // Métodos de escritura

	/***********************************************************************/
	// Establece el nombre de un alumno
	void PonNombreAlumno (char * el_nombre);
	
	/***********************************************************************/
	// Establece el DNI de un alumno
	void PonDNIAlumno (char * el_DNI);
	
	/***********************************************************************/
	// Establece las notas de un alumno
	void PonNotasAlumno (double * las_notas, int num_notas);
	
	/***********************************************************************/
	// Establece la nota media de un alumno
	void  CalculaNotaMediaAlumno (const double * pesos);

	void Asigna(char * el_nombre,char * el_DNI,double * las_notas,int num_notas);
	/***********************************************************************/
	// Operador de asignación
	Alumno & operator =  (const Alumno & otro);
	
	/***********************************************************************/
	// Muestra datos de un alumno  
	void PintaAlumno (void) const;	
	
	/***********************************************************************/

private:
		
	/***********************************************************************/
	// Petición / liberación de memoria / Copia de datos
	void ReservarMemoria (const Alumno & otro);
	void CopiarDatos (const Alumno & otro);
	void LiberarMemoria (void); 

	int longitud_cadena(char *cadena);
		
};
/////////////////////////////////////////////////////////////////////////////

#endif
 
