/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//  
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIOS 21
//
/*
. Se desea crear una matriz dentada de valores reales leyendo sus valores de la entrada
estándar y realizar algunos cálculos con ella.
Todos los valores necesarios (número de secuencias, número de datos de cada se-
cuencia y los valores de cada secuencia) se introducen en una sola línea.
Por ejemplo, una línea de entrada podría ser la siguiente:
3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7
Se puede observar que se distinguen tres grupos de datos (lo indica el primer nú-
mero (int) de la línea). Cada grupo empieza por un valor (int) que indica el número
de elementos que lo componen (en el ejemplo, los grupos tienen dos, cinco y dos ele-
mentos, respectivamente). A continuación de este valor se encentran tantos valores
(double) como indique el valor entero que encabeza cada grupo.
En el ejemplo, el primer grupo contendrá los valores 3.1 y 0.4, el segundo 1.0, 1.0,
1.0, 1.0 y 1.0 y el tercero 5.2 y 4.7.
Escribir un programa que escriba en la salida estándar la suma de los valores de cada
grupo.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////

class SecuenciaReales 
{

private:

	static const int TAMANIO = 50; // Número de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaReales (void) 
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

	void Aniade(double nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	char Elemento(int indice){
		return vector_privado[indice];
	}

	void Elimina(int numero){
		for(int i = numero; i < total_utilizados; i++){
			vector_privado[i] = vector_privado[i+1]; 
		}
		total_utilizados--;
	}
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Tabla dentada de datos <TIPO>
//
// Representación: matriz "clásica"

class TablaDentadaReales 
{
private:

  	static const int MAX_FIL = 50;  // Filas disponibles
    static const int MAX_COL = 40;  // Columnas disponibles

    double matriz_privada[MAX_FIL][MAX_COL];

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
	
	double Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}

	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaReales"
	//
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaReales Fila (int indice_fila)
	{
		SecuenciaReales la_fila;
					
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
	
	void Aniade (SecuenciaReales fila_nueva)
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
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva)
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
	//metodo que suma columnas de la matriz acudienco al metdodo inserta


	void SumaColumnas(){
		int i = 0;
		SecuenciaReales suma;

		while(i < filas_utilizadas){
			while(j < num_cols_utilizadas){
				suma.Aniade(matriz_privada[i][j] + matriz_privada[i][j+1]);
				j+2;
			}
			Inserta(i, suma);
			filas_utilizadas--;
			i++;
		}
		

};

/////////////////////////////////////////////////////////////////////////////
			

int main(){

	SecuenciaReales una_secuencia;
	TablaDentadaReales una_tabla;

	int filas;
	int columnas;
	int elementos;

	cout << "\nintroduce la cadena: ";
	cin >> filas;

	for(int i = 0; i < filas; i++){
		cin >> columnas;
		for(int j = 0; j < columnas; j++){
			cin >> elemento;
			una_secuencia.Aniade(elemento);
		}
		una_tabla.Aniade(una_secuencia);
	}

	for(int i = 0; i < una_tabla.FilasUtilizadas(); i++){
		for(int j = 0; j < una_tabla.ColumnasUtilizadas();j++){
			cout <<una_tabla.Elemento(i,j)<<" ";
		}
		cout << "\n";
	}
