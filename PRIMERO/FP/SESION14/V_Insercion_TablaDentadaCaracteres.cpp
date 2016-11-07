/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//  
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN	
// 
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIOS 20 
/*
Añadid un método a la clase TablaDentadaCaracteres
(almacenamiento con matriz clásica, de dos índices) para que inserte una fila com-
pleta en una posición (de fila) determinada. La fila a insertar se proporciona como un
objeto de la clase SecuenciaCaracteres. Tras la inserción, la nueva fila ocupará
la posición indicada, y la que ocupaba esa posición, y todas las superiores, se habrán
desplazado una posición.


//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////

class SecuenciaCaracteres 
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaCaracteres (void) 
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el número de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	// ......

};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos <TIPO>
//
// Representación: matriz "clásica"

class TablaDentadaCaracteres 
{
private:

  	static const int MAX_FIL = 50;  // Filas disponibles
    static const int MAX_COL = 40;  // Columnas disponibles

    char matriz_privada[MAX_FIL][MAX_COL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL

    int filas_utilizadas;

    // PRE: 0 <= num_cols_utilizadas[i] < MAX_COL
    //      para i=0,1,...,filas_utilizadas-1
    // Número de columnas ocupadas en cada fila

    int num_cols_utilizadas[MAX_FIL];
	
public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	TablaDentadaReales (void) 	
	{
		filas_utilizadas = 0;
	}

	/***********************************************************************/
	// Devuelve el número de casillas disponibles
	
	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}
	
	/*****************************************************************/
	// Método de lectura: número máximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}
	
	/*****************************************************************/
	// Método de lectura: número real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}
			
	/*****************************************************************/
	// Método de lectura: número real de columnas usadas en la fila "fila"
	// 
	// PRE: 0 <= fila < filas_utilizadas
	
	int ColumnasUtilizadas (int fila)
	{
		return (num_cols_utilizadas[fila]);
	}
	
	/*****************************************************************/
	// Método de lectura: devuelve el dato que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < num_cols_utilizadas[fila]	
	
	char Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	//
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaCaracteres Fila (int indice_fila)
	{
		SecuenciaCaracteres la_fila;
					
		if ((0 <= indice_fila) && (indice_fila < filas_utilizadas)) {
					
			int num_columnas = num_cols_utilizadas[indice_fila];
			
			for (int c=0; c<num_columnas; c++) 
				la_fila.Aniade (matriz_privada[indice_fila][c]);
		}
		return (la_fila);
	}
	
	/***********************************************************************/
	// Añade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaReales".
	// 
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	//
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	
	
	void Aniade (SecuenciaCaracteres fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva <= MAX_COL)) {

			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[filas_utilizadas][c] = fila_nueva.Elemento(c);

			num_cols_utilizadas[filas_utilizadas]=numero_columnas_fila_nueva;
			
			filas_utilizadas++;

		}
	}

	/*****************************************************************/
	// Inserta una fila completa en una posición dada. 
	// La fila se porporciona en un objeto "SecuenciaReales".
	// 
	// Recibe: num_fila, la posición que ocupará "fila_nueva" cuando se 
	//		 		inserte en la tabla.
	//		   fila_nueva, la secuencia que se va a insertar. Se trata 
	//				de un objeto de la clase SecuenciaReales. 
	//
	// PRE:  fila_nueva.TotalUtilizados() <= MAX_COL
	// PRE:  filas_utilizadas < MAX_FIL
	// PRE:  0 <= num_fila <= TotalUtilizados()
	//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
	//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
	//		 última fila (el resultado será equivalente al de "Aniade()" 
	
	void Inserta (int num_fila, SecuenciaCaracteres fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		// Comprobar precondiciones
		
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva <= MAX_COL) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			// "Desplazar" las filas hacia posiciones altas. 
			// La última fila se copia en una NUEVA FILA que ocupa la 
			// posición "filas_utilizadas", la penúltima se copia en 
			// "filas_utilizadas"-1, ... y se queda un "hueco" en 
			// la fila "num_fila ".
			// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) {	
			
				int num_columnas = num_cols_utilizadas[fil-1];
					
				for (int c=0; c<num_columnas; c++) 
					matriz_privada[fil][c] = matriz_privada[fil-1][c]; 
					
				num_cols_utilizadas[fil] = num_cols_utilizadas[fil-1];
			}
					
			// Copiar en el "hueco" (fila "num_fila") el contenido de 
			// la secuencia "fila_nueva"
			
			for (int c=0; c<numero_columnas_fila_nueva; c++) 
				matriz_privada[num_fila][c] = fila_nueva.Elemento(c);
			
			num_cols_utilizadas[num_fila] = numero_columnas_fila_nueva;
			
			filas_utilizadas++; // Actualización del tamaño de la tabla.
		}
	}

	/***********************************************************************/
	// "Vacía" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Calcula si dos matrices dentadas son iguales

	bool EsIgual (TablaDentadaReales otra_tabla)
	{
		bool son_iguales = true; 
		
		if (filas_utilizadas != otra_tabla.FilasUtilizadas())
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				if (num_cols_utilizadas[f] != otra_tabla.ColumnasUtilizadas(f)) 
				
					son_iguales = false;	
				
				else {
					
					int c=0; 
					
					while (c<num_cols_utilizadas[f] && son_iguales) {
				
						if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
							son_iguales = false;
							
						c++;
						
					} // while c
		
					f++;
					
				} // else 
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}
	
	/***********************************************************************/		
};

/////////////////////////////////////////////////////////////////////////////
			

int main(){

	// Solicitar y filtrar las dimensiones de la tabla
	
	int num_filas, num_columnas; // filas y columnas de la tabla rectangular

	do{
		cout << "Número de filas: ";
		cin >> num_filas; 
	} while (num_filas < 0);

	do{
		cout << "Número de columnas: ";
		cin >> num_columnas; 
	} while (num_columnas < 0);

	TablaDentadaCaracteres una_tabla


	char letra;

	
	for (int f=0; f<num_filas; f++) {

		SecuenciaCaracteres una_secuencia;

		cout << "Fila " << setw(3) << f << ": "; 

		for(int c = 0; c < num_columnas; c++){

			cin >> letra;

			una_secuencia.Aniade(letra);
		}
		una_tabla.Aniade(una_secuencia);
	}
	
	// Impresión de la tabla
	
	cout << endl << endl;
		
	for (int f=0; f<matriz.FilasUtilizadas(); f++) {

		for (int c=0; c<matriz.ColumnasUtilizadas(); c++) {
			cout << matriz.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;

	//insertamos la fila

	SecuenciaCaracteres otra_secuencia;

	cout << " \n\n Dame la fila a insertar: ";

	for(int i = 0; i < num_columnas; i++){

		cin >> letra;

		otra_secuencia.Aniade(letra);
	}

	int pos_fila;

	cout << "\n\nDime donde quieres que inserte la fila: ";

	cin >> pos_fila;

	una_tabla.Inserta(pos_fila, otra_secuencia);


	for (int p=0; p<una_tabla.FilasUtilizadas(); p++) {

		for (int j=0; j<una_tabla.ColumnasUtilizadas(); j++) {
			cout << una_tabla.Elemento(p,j) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;

	return(0);
}
