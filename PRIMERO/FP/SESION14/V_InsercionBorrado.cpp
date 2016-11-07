/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACIÓN DE PROBLEMAS V
// EJERCICIO 13 (apartados a - g)
//
/*	
 Añadid dos métodos a la clase TablaRectangularCaracteres para que inserte
una fila completa en una posición (de fila) determinada, o borre la fila indicada. Los
métodos serán:
void Inserta (int num_fila, SecuenciaCaracteres fila_nueva);
void Elimina (int num_fila);
El valor de num_fila en el método Inserta() indica la posición que ocupará la
nueva fila en la matriz tras la inserción. Así, si queremos que la nueva fila sea la
primera num_fila será 0 mientras que si queremos que sea la última,num_fila
será TotalUtilizados().
El valor de num_fila en el método Elimina() indica la fila que queremos eliminar.

*/
/*********************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


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
	// Constructor con argumento string
	// Recibe: la_palabra, dato string que se usa para iniciar el objeto.
	// Si "la_palabra" tiene más caracteres que caben en el objeto, no se 
	// copia nada y se crea un objeto vacío.
	// 
	// PRE: "la_palabra" está formada por una única palabra
	
	SecuenciaCaracteres (string la_palabra) 	
	{		
		total_utilizados = 0;
	
		int longitud_la_palabra = la_palabra.length();
			
		if (longitud_la_palabra <= TAMANIO) {
			
			for (int i=0; i<longitud_la_palabra; i++)
				vector_privado[i]= la_palabra[i];
				
			total_utilizados = longitud_la_palabra;
		}
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

	/***********************************************************************/
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (char nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	char Elemento (int indice)
	{
		return vector_privado[indice];
	}

	/***********************************************************************/
	// "Limpia" completamente una secuencia
	
	void EliminaTodos (void) 
	{
			total_utilizados = 0;    
	}
	
	
	/***********************************************************************/
	// FIN METODOS BASICOS
	/***********************************************************************/
	
	
	/***********************************************************************/
	// Devuelve una secuencia incluida en la secuencia implícita, que empieza 
	// en la posición "pos_init" y tiene "num_datos" valores
	//
	// Recibe: pos_init, posición inicial desde donde empieza la copia a la 
	//					 subsecuencia. 
	//		   num_datos, número de valores que se copian a la subsecuencia. 
	// Devuelve: una subsecuencia de la secuencia implícita. 
	// 
	// Casos: 1) Si 0 <= pos_init < total_utilizados Y 
	//			 pos_init+num_datos<=total_utilizados
	//			 se devuelve una subsecuencia de tamaño "num_datos"
	//		  2) Si 0 <= pos_init < total_utilizados Y 
	//			 pos_init+num_datos>total_utilizados, se devuelve una 
	//			 subsecuencia de tamaño total_utilizados-pos_init
	//		  3) Si pos_init < 0 Ó pos_init >= total_utilizados, 
	//			 se devuelve una subsecuencia vacía.
	//		  4) Si num_datos = 0, se devuelve una subsecuencia vacía.

	SecuenciaCaracteres Subsecuencia (int pos_init, int num_datos)
	{
		SecuenciaCaracteres a_devolver; // inicialmente vacía
		
		if ((pos_init>=0) && (pos_init<total_utilizados) && (num_datos>0)) {
			
			int pos_end;
			
			if (pos_init+num_datos>total_utilizados) 
				pos_end = total_utilizados;
			else 
				pos_end = pos_init+num_datos;
			
			for (int pos=pos_init; pos<pos_end; pos++)
				a_devolver.Aniade(vector_privado[pos]);
		}
		
		return (a_devolver);
	}
	
};

/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// La clase "PosicionEnMatriz" es útil para representar posiciones 
// (coordenadas) en una tabla bidimensional.

class PosicionEnMatriz
{
private:
	int fila;
	int columna;

public: 
	
	/*****************************************************************/
	// Constructor por defecto
	// La posición {-1,-1} debe interpretarse como "posición no válida"
	// (resulta útil en métodos de búsqueda, por ejemplo). 

	PosicionEnMatriz (void) : fila(-1), columna(-1) { }

	/*****************************************************************/
	// Método de escritura: establece simultaneamente los dos valores

	void SetPosicion (int la_fila, int la_columna)
	{
		fila = la_fila;
		columna = la_columna;
	}

	/*****************************************************************/
	// Métodos Get

	int GetFila (void)
	{
		return (fila);
	}
	
	int GetColumna (void)
	{
		return (columna);
	}

	/*****************************************************************/
	// Devuelve TRUE si la posición no es válida--> {-1,-1}

	bool EsPosicionNoValida (void)
	{
		return ((fila == -1) && (columna == -1));
	}
	/*****************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de caracteres
//
// Representación: matriz "clásica"

class TablaRectangularCaracteres
{

private:

	static const int MAX_FIL = 50;
	static const int MAX_COL = 40;

	char matriz_privada[MAX_FIL][MAX_COL];

    // PRE: 0 <= filas_utilizadas < MAX_FIL
    // PRE: 0 <= col_utilizadas < MAX_COL
	
	int filas_utilizadas;
	int cols_utilizadas;

public:

	/*
	Para obligar a que una matriz sea rectangular, lo podemos hacer 
	de varias formas. Por ejemplo:
	a)	El constructor de la matriz recibe "numero_de_columnas", que 
		indica el número de columnas que deben tener todas las filas.
	b)	El constructor de la matriz recibe una secuencia. La longitud 
		(número de casillas utilizadas) de esa secuencia será el valor 
		que se use dentro de la matriz como "numero_de_columnas"

	Para permitir ambas formas, sobrecargamos el constructor.
	*/
	
	/***********************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el número de columnas 
	// que deben tener TODAS las filas.

	TablaRectangularCaracteres (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor b)
	// Recibe una secuencia de caracteres. El número de elementos de la 
	// secencia es el valor que se usa como "col_utilizadas"

	TablaRectangularCaracteres (SecuenciaCaracteres primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// Método de lectura: número máximo de filas

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
	// Método de lectura: número real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// Método de lectura: devuelve el caracter que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	char Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla está vacía

	bool EstaVacia (void) 
	{
		return (filas_utilizadas == 0);
	}
	
	/*****************************************************************/
	// Devuelve una fila completa, como un objeto de la clase 
	// "SecuenciaCaracteres"
	// PRE: 0 <= indice_fila < filas_utilizadas
	
	SecuenciaCaracteres Fila (int indice_fila)
	{
		SecuenciaCaracteres fila;

		for (int col=0; col<cols_utilizadas; col++)
			fila.Aniade(matriz_privada[indice_fila][col]);

		return (fila);
	}

	/*****************************************************************/
	// Devuelve una columna completa, como un objeto de la clase 
	// "SecuenciaCaracteres"
	// PRE: 0 <= indice_columna < cols_utilizadas
	
	SecuenciaCaracteres Columna (int indice_columna)
	{
		SecuenciaCaracteres columna;

		for (int fil=0; fil<filas_utilizadas; fil++)
			columna.Aniade (matriz_privada[fil][indice_columna]);

		return (columna);
	}

	/*****************************************************************/
	// Añade una fila completa. La fila se porporciona en un objeto de 
	// la clase "SecuenciaCaracteres".
	// 
	// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
	// PRE:  filas_utilizadas < MAX_FIL
	
	void Aniade (SecuenciaCaracteres fila_nueva)
	{
		int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas)) {

			for (int col = 0; col < numero_columnas_fila_nueva; col++)
				matriz_privada[filas_utilizadas][col]=fila_nueva.Elemento(col);

			filas_utilizadas++;
		}
	}

	/*****************************************************************/
	// Devuelve TRUE si la matriz contiene el valor "buscado"
	
	bool Contiene (char buscado)
	{
		bool encontrado = false;

		// Recorrido por columnas 

		int col = 0;

		while (col < cols_utilizadas && !encontrado) {

			int fil=0;

			while (fil < filas_utilizadas && !encontrado) {

				if (matriz_privada[fil][col] == buscado)
					encontrado = true;
				
				fil++;

			} // while fil

			col++; 

		} // while col

		return (encontrado);
	}
		
	/*****************************************************************/
	// Encontrar un carácter en la matriz y devolver su posición.
	// El valor devuelto contiene información acerca de la posición 
	// (fila y columna) de "buscado".  
	// 		En el caso de que no esté contendrá {-1,-1}. 
	// La consulta de la fila y la columna se delega en los métodos de 
	// la clase "PosicionEnMatriz" 

	PosicionEnMatriz PrimeraOcurrencia (char buscado)
	{
		PosicionEnMatriz posicion_dato_buscado; // Inicialmente {-1,-1}.
      
		bool encontrado = false;

		// Recorrido por filas 

		for (int i=0; i < filas_utilizadas && !encontrado ; i++){

			for (int j=0; j < cols_utilizadas && !encontrado; j++){

				if (matriz_privada[i][j] == buscado){
					encontrado = true;
					posicion_dato_buscado.SetPosicion (i,j);
				}

			} // for j

		} // for i
      
		return (posicion_dato_buscado);
	} 

	/*****************************************************************/
	// Calcula si dos matrices rectangulares son iguales
	//
	// PRE: filas_utilizadas = otra_tabla.FilasUtilizadas()
	// PRE: cols_utilizadas  = otra_tabla.ColumnasUtilizadas()

	bool EsIgual (TablaRectangularCaracteres otra_tabla)
	{
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra_tabla.FilasUtilizadas()) && 
			 (cols_utilizadas != otra_tabla.ColumnasUtilizadas()))		
			
			son_iguales = false;
		
		else {
			
			int f=0; 
			
			while (f<filas_utilizadas && son_iguales) {
				
				int c=0; 
				
				while (c<cols_utilizadas && son_iguales) {
			
					if (matriz_privada[f][c] != otra_tabla.Elemento(f,c)) 
						son_iguales = false;
						
					c++;
					
				} // while c
	
				f++;
					
			} // while f
					
		} // else 
	
		return (son_iguales);
	}

	/***********************************************************************/
	// "Vacía" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/

	//calculamos la traspuesta

	TablaRectangularCaracteres Traspuesta(){
		TablaRectangularCaracteres traspuesta;

		for(int i = 0; i < filas_utilizadas; i++){
			for(int j = 0; j < cols_utilizadas; j++){
				traspuesta[i][j] = matriz_privada[j][i];			
			}
		}
		return traspuesta;
	}

	//metrodo que comprueba si es simetrica

	bool EsSimetrica(){
		int i = 0;
		int j = 0;
		bool simetrica = true;

		while(i < filas_utilizadas && simetrica){
			while(j < cols_utilizadas && simetrica){
				if(matriz_privada[i][j] != Traspuesta.Elemento(i,j)){
					simetrica = false;
				}
				j++;
			}
			i++;
		}
		return simetrica;
	}

	//metodo que inserta una fila

	void Inserta(int num_fila, SecuenciaCaracteres fila_nueva){
		for(int i = 0; i < filas_utilizadas; i++){
			matriz_privada[num_fila][i] = fila_nueva.Elemento(i);
		}
	}

	//metodoque elimina una fila

	void Elimina(int num_fila){
		for(int i = num_fila; i < filas_utilizadas; i++){
			for(int j= 0; j < cols_utilizadas; j++){
					matriz_privada[i][j] = matriz_privada[i+1][j]; 
			}
		}
		filas_utilizadas--;
	}

			
};

/***********************************************************************/
	
///////////////////////////////////////////////////////////////////////

int main (void)
{
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


	// Crear la tabla (inicialmente vacía)
	
	TablaRectangularCaracteres matriz (num_columnas);


	// Lectura de los datos que compondrán la tabla

	cout << endl;
	cout << "Introduzca los caracteres de la matriz por filas:" << endl;
	cout << "(solo se consideraran los primeros " << setw(3) << num_columnas 
		 << " caracteres)" << endl;
	cout << endl;
	
	// Los datos que compondrán cada fila se leerán en un string.
	// De esta manera permitimos espacios en blanco.
	// A partir del string construimos una SecuenciaCaracteres y de esa 
	// secuencia nos quedaremos con los primeros "num_columnas" elementos.
	
	string una_cadena;

	
	for (int f=0; f<num_filas; f++) {

		cout << "Fila " << setw(3) << f << ": "; 

		// Leer cadena. Descartar las que sen demasiado cortas.  
		do {
			getline(cin, una_cadena);
		} while (una_cadena.length() < num_columnas);
/*		
		cout << "string = " << una_cadena;
		cout << endl << endl; 
*/			
		// Crear una secuencia a partir de la cadena leida
		SecuenciaCaracteres una_fila (una_cadena); 

/*
		cout << "una_fila = ";	
		cout << "|";
		for (int p=0; p<una_fila.TotalUtilizados(); p++)
			cout << una_fila.Elemento(p) << "|";
		cout << endl << endl; 
*/
			 
		// Nos quedamos con la subsecuencia inicial de tamaño "num_columnas"
		una_fila = una_fila.Subsecuencia(0,num_columnas); 
		
/*		
		cout << "una_fila (después de ajustar) = ";	
		cout << "|";
		for (int p=0; p<una_fila.TotalUtilizados(); p++)
			cout << una_fila.Elemento(p) << "|";
		cout << endl << endl;
*/	
		
		// Añadimos la secuencia a la matriz
		// Estamos seguros de que tiene el tamaño correcto. 
		
		matriz.Aniade (una_fila);
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


	// Búsqueda

	char caracter_a_buscar; 

	cout << endl << endl;
	cout << "Introduzca el caracter a buscar: ";
	
	caracter_a_buscar = cin.get();	

	bool encontrado_caracter = matriz.Contiene (caracter_a_buscar);


	cout << endl;
	if (encontrado_caracter) 
		cout << "SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	else 
		cout << "NO SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	cout << endl << endl;


	PosicionEnMatriz posicion = matriz.PrimeraOcurrencia (caracter_a_buscar);

	if (posicion.EsPosicionNoValida()) 
		cout << "NO SE HA ENCONTRADO el caracter " << caracter_a_buscar;
	else {
		cout << "SE HA ENCONTRADO el caracter " << caracter_a_buscar;
		cout << " en la posicion (" << posicion.GetFila() 
			 << ", " <<posicion.GetColumna() << ")";
	}
	cout << endl << endl;

	return (0);
}