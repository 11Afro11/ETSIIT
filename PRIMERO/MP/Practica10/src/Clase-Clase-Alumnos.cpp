
#include "Clase-Clase-Alumnos.h"
#include <iostream>
#include <cstring>

using namespace std;
/*
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
*/
	/***********************************************************************/
	// Constructor sin argumentos: crea una clase vacia.
	ClaseDeAlumnos::ClaseDeAlumnos (void) : datos(0) , pesos(0) , numero_alumnos(0) , numero_notas(0)
	{}

	/***********************************************************************/
	// Constructor con argumentos: crea una clase con "n_alumnos" almunos y 
	// "n_notas" notas. 
	// PRE: n_alumnos > 0
	ClaseDeAlumnos::ClaseDeAlumnos (int n_alumnos, int n_notas) : numero_alumnos(n_alumnos), numero_notas(n_notas)
	{
		ReservarMemoria(numero_alumnos, numero_notas);
	} 

	/***********************************************************************/
	// Constructor de copia
	ClaseDeAlumnos::ClaseDeAlumnos (const ClaseDeAlumnos & otro){
		ReservarMemoria(otro.numero_alumnos, otro.numero_notas);
		CopiarDatos(otro);
	}
		
	/***********************************************************************/
    // Destructor
    ClaseDeAlumnos::~ClaseDeAlumnos (void){ClaseDeAlumnos::
    	LiberarMemoria();
    }

	/***********************************************************************/
    // Consulta si la clase esta vacia
	bool ClaseDeAlumnos::EstaVacia(void) const{
		bool esta_vacia = (datos==0);
		return esta_vacia;
	}
		
	/***********************************************************************/
	// Devuelve el numero de alumnos
	int  ClaseDeAlumnos::NumeroAlumnos (void) const{
		return numero_alumnos;
	}
	
	/***********************************************************************/
	// Devuelve el numero de notas
	int  ClaseDeAlumnos::NumeroNotas (void) const{
		return numero_notas;
	}

	/***********************************************************************/
	// Inicializa los campos privados "numero_notas" y "pesos", reservando la 
	// memoria precisa para los pesos
	void ClaseDeAlumnos::EstablecePesos (double * los_pesos, int num_pesos){
		if(los_pesos != 0){
			numero_notas = num_pesos;
			pesos = new double [numero_notas];

			for(int i = 0; i < numero_notas; i++){
				pesos[i] = los_pesos[i];
			}
		}
	}
	
	/***********************************************************************/
	// Inicializa los campos privados "datos" y "numero_alumnos" leyendo los 
	// datos de cin 
	void ClaseDeAlumnos::LeeDatosAlumnos (void){
		
		char * name = new char[TAM_CAD];
		char * DNA= new char [TAM_CAD];

		double * marks = new double[numero_notas];

		cout << "Alumno 1 ->";
		cin.getline(name, TAM_CAD);
		if (strcmp(name, "FIN") != 0){
			cout << "DNI -> ";
			cin.getline(DNA,TAM_CAD);
			cout << "Notas -> ";
			for(int j = 0; j < numero_notas; j++){
				cin >> marks[j];
			}

			Alumno alumno(name, DNA, marks, numero_notas);

			cin.ignore(TAM_CAD,'\n'); // Limpiar buffer de entrada

			datos = new TipoNodo;
			datos->info = alumno;

			TipoNodo *aux = datos;

			int i = 2;
			cout << "Alumno "<<i<<" ->";
			cin.getline(name, TAM_CAD);
			

			while(strcmp(name, "FIN") != 0) {
				
				cout << "DNI -> ";
				cin.getline(DNA,TAM_CAD);
				cout << "Notas -> ";
				for(int j = 0; j < numero_notas; j++){
					cin >> marks[j];
				}

				alumno.Asigna(name, DNA, marks, numero_notas);
				cin.ignore(TAM_CAD,'\n'); // Limpiar buffer de entrada
				
				aux->sig = new TipoNodo;
				aux = aux->sig;
				aux->info = alumno;
				i++;

				cout << "Alumno "<<i<<" ->";
				cin.getline(name, TAM_CAD);
			}
			numero_alumnos = i-1;
		}
	}

	/***********************************************************************/
	// Muestra un listado de los alumnos  
	void ClaseDeAlumnos::Listado (const char * msg) const{
		cout << msg<<endl;
		TipoNodo* aux = datos;
		for(int i = 0; i < numero_alumnos; i++){
			cout <<"Alumno "<<i+1<<" -> "<<aux->info.NombreAlumno()<<endl;
			cout <<"DNI -> "<<aux->info.DNIAlumno()<<endl;
			cout <<"Notas -> ";
			for(int i =0; i < numero_notas;i++){
				cout << aux->info.NotasAlumno()[i]<< " ";
			}
			cout << " -> "<<aux->info.NotaMediaAlumno();
			aux = aux->sig;
			cout << endl <<"------------o-------------"<<endl;
		}
	}
	
	/***********************************************************************/
	// Calcula la nota media de los alumnos. Se emplean los valores del 
	// campo "pesos" para la ponderación. 	
	void ClaseDeAlumnos::CalculaNotaMedia (void){
		TipoNodo*aux = datos;
		for(int i = 0; i < numero_alumnos; i++){
			aux->info.CalculaNotaMediaAlumno(pesos);
		}
	}
	
	/***********************************************************************/
	// Ordena los datos de los alumnos usando como clave la nota media.
	// Se emplea el algoritmo de ordenación por inserción.
	void ClaseDeAlumnos::Ordena_por_Insercion (void)
	{
		if (datos!=0) { // si la lista esta vacia, no se hace nada

			TipoNodo* primero = datos; // marca el inicio de la parte NO ordenada
			
			while (primero->sig != 0) {

				// El primer menor es el primer elemento de la parte no ordenada
				Alumno val_min = primero->info; 
				TipoNodo* pos_min = primero;           

				// Para buscar el menor de la parte no ordenada
				TipoNodo* p = primero->sig;  

				while (p!=0) {

					if (p->info.NotaMediaAlumno() < val_min.NotaMediaAlumno()) {   // se encuentra un nuevo menor
						val_min = p->info;
						pos_min = p;
					}
					p = p->sig;  // se sigue avanzando
				}

				// Intercambio: el menor pasa a ocupar la posicion marcada 
				// por el puntero "primero"
				  
				Alumno tmp = primero->info; 
				primero->info = pos_min->info;
				pos_min->info = tmp; 

				primero = primero->sig; // avanza la parte no ordenada
			
			} // while (primero->sig != 0)
			
		} // if (l!=0)
	}

	/***********************************************************************/
	// Busca un alumno con el DNI especificado. Devuelve la posición del 
	// primer nodo coincidente, o -1 si no se encuentra.
	/***********************************************************************/
	int ClaseDeAlumnos::Busca (char * DNI){

		TipoNodo * aux = datos;
		bool encontrado = false;
		int i = 1;

		while(aux && !encontrado){
			if(aux->info.DNIAlumno() == DNI){
				encontrado = true;
			}
			else{
				aux = aux->sig;
				i++;
			}
		}
		return i;
	}
	
	/***********************************************************************/
    // Métodos de acceso para escribir/leer en una posición dada: 
    // NO MODIFICAN EL NÚMERO DE NODOS
	/***********************************************************************/

	Alumno & ClaseDeAlumnos::operator [] (int pos){

		TipoNodo * p = datos;
		for (int i = 1; i < pos; i++) 
			p = p->sig;
		
		// "p" apunta al nodo de la posición "pos"

		return (p->info);
	}

	Alumno & ClaseDeAlumnos::operator [] (int pos) const{

		TipoNodo * p = datos;
		for (int i = 1; i < pos; i++) 
			p = p->sig;
		
		// "p" apunta al nodo de la posición "pos"

		return (p->info);

	}

	/***********************************************************************/
    // Métodos que modifican el tamaño de la lista 
  	// MODIFICAN EL NÚMERO DE NODOS
	/***********************************************************************/
	// Aniade (al final) un nuevo elemento
	//
	// PRE: El objeto que se va a añadir ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).
	void ClaseDeAlumnos::Aniade (Alumno valor){
		// Crear un nuevo (último) nodo y rellenar sus campos
		TipoNodo * nuevo = new TipoNodo;
		nuevo->info = valor;
		nuevo->sig = 0;
		
		// Buscar el último nodo
		TipoNodo * p = datos;
		
		for(int i=1; i<numero_alumnos; i++)
			p = p->sig;

		// "p" apunta al último nodo

		if (p!=0) 	// La lista no estaba vacía
			p->sig = nuevo;
		else	 	// La lista estaba vacía
			datos = nuevo; 

		numero_alumnos++;
	}

    // Borra el primer nodo que contiene el DNI indicado
	void ClaseDeAlumnos::Elimina (char * DNI){
		int pos = Busca (DNI);
	
 		// Si pos > 0 se encontró el alumno buscado: eliminarlo
		if (pos > 0) Borra (pos);
	}

	/***********************************************************************/
	// Inserta un nuevo elemento en la posición "pos_insertar"
	// PRE: 1 <= pos_insertar <= numero_alumnos+1
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	// Nota: Si pos_insertar == tamanio+1, el resultado es idéntico a la 
	// 		 ejecución del método Aniade()
	//
	// PRE: El objeto que se va a insertar ha reservado su propia memoria 
	// 		para alojar una copia propia de sus datos (nombre, DNI y notas).
	void ClaseDeAlumnos::Inserta (Alumno valor, int pos_insertar){
		TipoNodo * ant = datos;
		TipoNodo * resto = datos;

		// Crear el nodo que se va a insertar e iniciarlo
		TipoNodo * nuevo = new TipoNodo; 
		nuevo->info = valor; 

		// Buscar el sitio que le corresponde 
		for (int i=1; i<pos_insertar; i++) { 
			ant = resto; 
			resto = resto->sig;
		}

		if (pos_insertar==1)   // El nuevo nodo sera el datos 
			datos = nuevo;
		else		  // Enlazar el nuevo con el anterior 
			ant->sig = nuevo;

		nuevo->sig = resto; // Enlazar el nuevo nodo con el resto

		numero_alumnos++; // Actualizar tamanio
	}

	/***********************************************************************/
	// Borra el elemento de la posición "pos_borrar" 
	// PRE: 1 <= pos_borrar <= tamanio
	// El criterio seguido para especificar una posicion será : 
	// 1 -> primero, 2 -> segundo,...
	void ClaseDeAlumnos::Borra (int pos_borrar){
		TipoNodo * ant = datos;
		TipoNodo * pos = datos;

		// Colocar "ant" y "act" 
		for (int i=1; i<pos_borrar; i++) { 
			ant = pos; 
			pos = pos->sig;
		}

		// "pos" apunta al nodo que se va a borrar
		// "ant" apunta al nodo anterior

		if (pos_borrar==1)   // Saltar el datos 
			datos = datos->sig;
		else 
			ant->sig = pos->sig;
			// Enlazar el anterior con el siguiente 

		delete pos; // Borrar nodo
		
		numero_alumnos--;  // Actualizar tamanio
	}
	
	/***********************************************************************/
	// Operador de asignación
	ClaseDeAlumnos & ClaseDeAlumnos::operator =  (const ClaseDeAlumnos & otro){
		if(&otro != this){
			LiberarMemoria();
			ReservarMemoria(otro.numero_alumnos, otro.numero_notas);
			CopiarDatos(otro);
		}
		return *this;
	}
		
	/***********************************************************************/
	

//private:
		
	/***********************************************************************/
	// Petición / liberación de memoria
	void ClaseDeAlumnos::ReservarMemoria (int num_alumnos, int num_notas){
		datos = new TipoNodo;		// Crear primer nodo.

		TipoNodo * ultimo = datos; // Apuntar al último.
		TipoNodo * p;

		for (int i = 1; i < num_alumnos; i++) {

			p = new TipoNodo;	// Crear un nodo.
			ultimo->sig = p;	// Enlazar el nuevo nodo. 
			ultimo = p;			// Pasa a ser el último.
		}						

		ultimo->sig = 0; // Finalizar la lista
		pesos = new double [numero_notas];
	}
	void ClaseDeAlumnos::LiberarMemoria (void){
		if (datos !=0) {
			
			TipoNodo *p = datos; // Colocar "p" al principio

			while (datos->sig != 0) {

				datos = datos->sig;  // Nuevo "datos"
				delete p;     // Borrar el antiguo datos
				p = datos;  // Actualizar "p"
			}

			delete datos; // Borrar el único que queda
		}
	}

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
	void ClaseDeAlumnos::CopiarDatos (const ClaseDeAlumnos & otro){
		// Copia los campos privados

        numero_alumnos = otro.numero_alumnos; // Copia el núm. de nodos

        // Copia el contenido de los nodos

		TipoNodo * p_este = datos; 
		TipoNodo * p_otro = otro.datos; 

		for(int i = 0; i < numero_alumnos; i++) {

			// Copiar valor
			p_este->info = p_otro->info; 

			// Adelantar punteros
			p_este = p_este->sig;		 
			p_otro = p_otro->sig;		 
		}
		numero_notas = otro.numero_notas;
	}	


		
//};

/////////////////////////////////////////////////////////////////////////////

 
