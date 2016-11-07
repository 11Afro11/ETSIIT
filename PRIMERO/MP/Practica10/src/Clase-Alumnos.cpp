#include "Clase-Alumnos.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;
/*
class Alumno
{
private:

	double * notas;		// Vector dinámico de notas
	int 	 num_notas; // Número de notas
	
	char   * nombre; 	// Vector dinámico de caracteres (cad. clásica)
	char   * DNI;    	// Vector dinámico de caracteres (cad. clásica)		
	
	double nota_media;	// Calificación media del alumno
	
public:
*/
	/***********************************************************************/
    // Constructores / destructor
    
	/***********************************************************************/
	// Constructor sin argumentos: crea una clase vacia.
	Alumno::Alumno (void){
		notas = 0; 
		num_notas = 0; 
		nombre = '\0';
		DNI = '\0';
		nota_media = 0;
	}

	/***********************************************************************/
	// Constructor con argumentos: crea un objeto "Alumno" inicializando los 
	// cammpos con los valores suministrados. 
	Alumno::Alumno (char * el_nombre,char * el_DNI,double * las_notas,int num_notas){
		nombre = new char[sizeof(el_nombre)];
		DNI = new char[sizeof(el_DNI)];
		strcpy(nombre, el_nombre);
		strcpy(DNI, el_DNI);
		this->num_notas = num_notas;
		notas = new double [num_notas];
		memcpy(notas, las_notas, sizeof(double)*num_notas);
	}
	
	/***********************************************************************/
	// Constructor de copia
	Alumno::Alumno (const Alumno & otro){
		
		ReservarMemoria(otro);
		CopiarDatos(otro);
	}
		
	/***********************************************************************/
    // Destructor
    Alumno::~Alumno (void){
    	LiberarMemoria();
    }

	/***********************************************************************/
    // Métodos de lectura

	/***********************************************************************/
	// Devuelve el nombre de un alumno
	char *  Alumno::NombreAlumno (void) const{
		return nombre;
	}
	
	/***********************************************************************/
	// Devuelve el DNI de un alumno
	char *  Alumno::DNIAlumno (void) const{
		return DNI;
	}
	
	/***********************************************************************/
	// Devuelve las notas de un alumno
	const double *  Alumno::NotasAlumno (void) const{
		return notas;
	}
	
	/***********************************************************************/
	// Devuelve el número de notas registradas de un alumno
	int Alumno::NumNotasAlumno (void) const{
		return num_notas;
	}
	
	/***********************************************************************/
	// Devuelve la nota media de un alumno
	double  Alumno::NotaMediaAlumno (void) const{
		return nota_media;
	}
	
	/***********************************************************************/
    // Métodos de escritura

	/***********************************************************************/
	// Establece el nombre de un alumno
	void Alumno::PonNombreAlumno (char * el_nombre){
		nombre = new char [sizeof(el_nombre)];
		strcpy(nombre, el_nombre);
	}
	
	/***********************************************************************/
	// Establece el DNI de un alumno
	void Alumno::PonDNIAlumno (char * el_DNI){
		DNI = new char[sizeof(el_DNI)];
		strcpy(DNI, el_DNI);
	}
	
	/***********************************************************************/
	// Establece las notas de un alumno
	void Alumno::PonNotasAlumno (double * las_notas, int num_notas){
		memcpy(notas, las_notas, sizeof(double)* num_notas);
	}
	
	/***********************************************************************/
	// Establece la nota media de un alumno
	void  Alumno::CalculaNotaMediaAlumno (const double * pesos){
		for(int i = 0; i < num_notas; i++){
			nota_media = nota_media + notas[i] * pesos[i]/100;
		}
		nota_media = nota_media / num_notas;
	}

	
	/***********************************************************************/
	// Operador de asignación
	Alumno & Alumno::operator =  (const Alumno & otro){
		if(this != &otro){
			LiberarMemoria();
			ReservarMemoria(otro);
			CopiarDatos(otro);
		}
		return *this;
	}
	
	/***********************************************************************/
	// Muestra datos de un alumno  
	void Alumno::PintaAlumno (void) const{
		cout <<endl<< "Los datos del alumno: "<<nombre<<endl;
		cout << "DNI: "<<DNI<<endl;
		cout << "notas";
		for(int i = 0; i < num_notas; i++){
			cout << notas[i] <<" ";
		}
		cout << endl;
	}
	
	/***********************************************************************/


	void Alumno::Asigna(char * el_nombre,char * el_DNI,double * las_notas,int num_notas){
		nombre = new char[sizeof(el_nombre)];
		DNI = new char[sizeof(el_DNI)];
		strcpy(nombre, el_nombre);
		strcpy(DNI, el_DNI);
		this->num_notas = num_notas;
		notas = new double [num_notas];
		memcpy(notas, las_notas, sizeof(double)*num_notas);
	}

//private:
		
	/***********************************************************************/
	// Petición / liberación de memoria / Copia de datos
	void Alumno::ReservarMemoria (const Alumno & otro){
		nombre = new char[sizeof(otro.nombre)];
		DNI = new char[sizeof(otro.DNI)];
		notas = new double[otro.num_notas];
	}

	void Alumno::CopiarDatos (const Alumno & otro){
		num_notas = otro.num_notas;
		memcpy(notas, otro.notas, sizeof(double)* num_notas);
		nombre = new char[sizeof(otro.nombre)];
		DNI = new char[sizeof(otro.DNI)];
		strcpy(nombre,otro.nombre);
		strcpy(DNI, otro.DNI);
		nota_media = otro.nota_media;
	}

	void Alumno::LiberarMemoria (void){
		delete[]notas;
    	delete[]nombre;
    	delete[]DNI;
    	num_notas = nota_media = 0;
	}

	int Alumno::longitud_cadena(char *cadena){

		char *comienzo =cadena;
		char *final = comienzo;

		while(*final != '\0'){
			final++;
		}

		return (final-comienzo);

	}
		
//};