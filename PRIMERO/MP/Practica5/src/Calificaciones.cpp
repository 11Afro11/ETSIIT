#include "Calificaciones.h"

using namespace std;

const char * TERMINADOR = "FIN";

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
// Lee los pesos de las calificaciones, los guarda en un vector 
// dinámico y devuelve su dirección. 
// Por referenccia, devuelve el número de pesos (calificaciones)
// Comprueba que la suma sea 100. Si no es así, aborta.
// Recibe: 	
//		num_pesos, cantidad de casillas reservadas en el vector. 
//			Como se recibe en una referencia y la función modifica el valor 
//			de "num_pesos", en realidad se modifica el valor del parámetro 
//			real usado en la llamada.
// Devuelve: la dirección de memoria del vector de pesos.

double * LeeCompruebaPesos (int & num_pesos)
{
	
	cout << endl;
	cout << Linea (80, '-') << endl;	
	
	// Lectura de los pesos asignados a cada calificación y comprobación.  

	cout << "LEYENDO PESOS" << endl << endl; 	
			
	cin >> num_pesos; 

	// Reserva de memoria paar el vector dinámico de pesos
	double * pesos_leidos = new double [num_pesos]; 

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
	cout << endl;
	cout << Linea (80, '-') << endl;	

	return (pesos_leidos);
}

/***************************************************************************/	
// Lee los datos de los alumnos (nombre y notas), los guarda en un 
// vector dinámico y devuelve su dirección. 
// Por referencia, devuelve el número de alumnos 
// Recibe: 	
//		num_notas, número de calificaciones de cada alumno.
//		num_alumnos, número de alumnos que se gardan en el vector. 
//			Como se recibe en una referencia y la función modifica el valor 
//			de "num_alumnos", en realidad se modifica el valor del parámetro 
//			real usado en la llamada.
// Devuelve: la dirección de memoria del vector de alumnos.

RegAlumno * LeeDatosAlumnos (int num_notas, int & num_alumnos)
{
	// Vector dinámico inicial, con TAM_INICIAL casillas
	RegAlumno * alumnos = new RegAlumno[TAM_INICIAL];
	
	int capacidad = TAM_INICIAL;
	num_alumnos = 0;
	
	// Cádena clásicas para lectura de los apellidos y el nombre	
	char nombre_alumno[TAM_CAD];

	cout << endl;
	cout << Linea (80, '-') << endl;
	cout << "LEYENDO DATOS" << endl << endl; 
	
	// Lectura adelantada

	cin.getline (nombre_alumno, TAM_CAD);
			
	while (strcmp(nombre_alumno, TERMINADOR)) {

		// VUESTRA TAREA: 
		
		if (num_alumnos == capacidad) {  // Redimensionar 
			alumnos = Redimensiona (alumnos, capacidad, num_notas);
		}
		

		// Copiar los datos del nuevo alumno en el vector 
		
		//	1) Reservar memoria para el nombre, y copiarlo. 
		
		(alumnos[num_alumnos]).nombre = new char[strlen(nombre_alumno)+1];
		strcpy ((alumnos[num_alumnos]).nombre, nombre_alumno);
		
		cout << "COPIADO --> " << (alumnos[num_alumnos]).nombre << endl;		

		//	2) Reservar memoria para las calificaciones, y copiarlas.
		
		(alumnos[num_alumnos]).notas = new double[num_notas]; 		

		cout << "COPIADO --> "; 		
		for (int n=0; n<num_notas; n++) { 
			cin  >> ((alumnos[num_alumnos]).notas)[n];
			cout << ((alumnos[num_alumnos]).notas)[n] << " ";			
		}
		cout << endl;
		
		
		// Actualizar el número de alumnos registrados	 
		num_alumnos++;
		

		// Lectura adelantada
		
		cin.ignore(TAM_CAD,'\n'); // Limpiar buffer de entrada
		
		cin.getline (nombre_alumno, TAM_CAD);
		
	}

	cout << Linea (80, '-') << endl;
	
	return (alumnos);
}

/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico de acuerdo al tipo de redimensión indicado. 
// Además, copia todos los datos en el nuevo vector.  
// Recibe: 	
//		p, dirección de memoria del primer elemento del vector 
//		capacidad, cantidad de casillas reservadas en el vector. 
//			Como se recibe en una referencia y la función modifica el valor de
//			"capacidad", en realidad se modifica el valor del parámetro real 
//			usado en la llamada.
//		num_notas, el número de casillas del vector de calificaciones.
// Develve: un puntero a la nueva zona de memoria reservada. 

// VUESTRA TAREA: 

RegAlumno * Redimensiona (RegAlumno * p,  int &capacidad, int num_notas)
{
	
	RegAlumno *aux;
	aux = p;
	p = new RegAlumno[capacidad+1];


	memcpy(p, aux, sizeof(RegAlumno)*capacidad);
	
	delete[] aux;
	capacidad++;

	return p;
}


/***************************************************************************/
// Calcula la nota media de los "num_alumnos" alumnos del vector "alumnos"
// ponderando las notas por los "num_pesos" del vector "pesos".
// Recibe: 	
//		alumnos, dirección de memoria del vector de alumnos. 
//		num_alumnos, número de alumnos en el vector "alumnos".
//		pesos, dirección de memoria del vector de pesos.
//		num_pesos, número de pesos en el vector "pesos".

// VUESTRA TAREA: 

void CalculaNotaMedia (RegAlumno * alumnos, int num_alumnos, double *pesos, int num_pesos)
{	

	for(int i = 0; i < num_alumnos;i++){
		alumnos[i].nota_media =0;
		for(int j = 0; j < num_pesos; j++){
			alumnos[i].nota_media = alumnos[i].nota_media + (alumnos[i].notas[j] * pesos[j]/100);
		}
	}	
}


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
// Muestra el contenido del vector de alumnos
// Recibe: 	
//		p, dirección de memoria del primer elemento del vector 
//		num_alumnos, cantidad de casillas usadas en el vector. 
//		num_notas, el número de casillas del vector de calificaciones.

void MuestraAlumnos (RegAlumno *p, int num_alumnos, int num_notas)
{
	cout << endl;
	cout << "Listado de alumnos" << endl;
	cout << Linea (80, '-') << endl;	
	
	RegAlumno un_alumno;
	
	for (int i=0; i<num_alumnos; i++) {

		un_alumno = p[i];
		
		cout << setw (3) << i+1 << " ";
		cout << left << setw(30) << un_alumno.nombre << " " << right;
				
		for (int n=0; n<num_notas; n++) 
			cout << setw(6)<<setprecision(2) << (un_alumno.notas)[n] << " ";

		cout << "|" << setw(7)<<setprecision(2) << un_alumno.nota_media;
		cout << endl;
	}
	
	cout << Linea (80, '-') << endl;	
	cout << endl;
}

/***************************************************************************/
// Ordena los datos de los alumnos usando como clave la nota media.
// Se emplea el algoritmo de ordenación por inserción.
// Recibe: 	
//		p, dirección de memoria del primer elemento del vector 
//		num_alumnos, cantidad de casillas usadas en el vector. 
//		num_notas, el número de casillas del vector de calificaciones.

// VUESTRA TAREA: 

void Ordena_por_Insercion (RegAlumno *p, int num_alumnos)
{	

	int izda, i;
	RegAlumno a_desplazar;
	for (izda = 1; izda < num_alumnos; izda++){
		a_desplazar = p[izda];
		for (i = izda; i>0 && a_desplazar.nota_media < p[i-1].nota_media; i--){
			p[i] = p[i-1];
		}
			p[i] = a_desplazar;
		
	}



}


/***************************************************************************/
// Libera la memoria ocupada por las estructuras de datos dinámicas.
// Recibe: 	
//		pesos, dirección de memoria del primer elemento del vector de pesos. 
//		alumnos, dirección de memoria del primer elemento del vector de alumnos.
//		num_alumnos, número de casillas ocupadas del vector "alumnos".
// Nota: Como se reciben en sendas referencias y la función modifica el valor 
//		de "pesos" y "alumnos", en realidad se modifica el valor de los 
//		parámetros reales usados en la llamada.

void LiberaMemoria (double * & pesos, RegAlumno * & alumnos, int num_alumnos)
{
	delete [] pesos;
	pesos = 0;
	
	for (int i=0; i<num_alumnos; i++) 
		delete [] alumnos[i].nombre;
		
	delete [] alumnos;
	alumnos = 0;	
}

/***************************************************************************/
/***************************************************************************/