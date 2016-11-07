/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN

//
// RELACI�N DE PROBLEMAS V
// EJERCICIO 13 (apartados a - g)
//
/*	
	Este programa presenta la clase TablaRectangularCaracteres. 
	Esta clase es �til cuando se desea que forzosamente todas las filas 
	tengan el mismo n�mero de columnas--> que sea una matriz rectangular.

	Se emplea como dato miembro privado una matriz "cl�sica" en la forma:

		char matriz_privada[MAX_FIL][MAX_COL];

	y se ofrecen, entre otros, m�todos para:

	a)	Obtener el n�mero de filas y columnas utilizadas.

			int FilasUtilizadas();
			int ColumnasUtilizadas();

	b)	Obtener como el car�cter que hay en una fila y columna dadas.

			char Elemento (int fila, int columna);

	c-d) Devolver una fila y una columna completas. 
		Una fila y una columna son realmente una secuencia de caracteres: 
		ambos m�todos devolver�n un objeto de la clase SecuenciaCaracteres.

			SecuenciaCaracteres Fila    (int indice_fila);
			SecuenciaCaracteres Columna (int indice_columna);

	e) A�adir una fila entera. 
		La fila se proporciona como un objeto de la clase SecuenciaCaracteres.
	
			void Aniade(SecuenciaCaracteres fila_nueva);

	f-1) Encontrar un valor.

			bool Contiene (char buscado);

		Devuelve TRUE si la tabla contiene el car�cter "buscado"

	f-2) Encontrar un car�cter.

			PosicionEnMatriz PrimeraOcurrencia (char buscado);

		El valor devuelto contiene informaci�n acerca de la posici�n 
		(fila y columna) de "buscado".  En el caso de que no est� 
		contendr� {-1,-1}. 
		La consulta de la fila y la columna se delega en los m�todos de 
		la clase "PosicionEnMatriz" 

	g)	Comprobar si es igual a otra matriz rectangular.

			bool EsIgual (TablaRectangularCaracteres otra_matriz);
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

	static const int TAMANIO = 50; // N�mero de casillas disponibles
	char vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// N�mero de casillas ocupadas

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
	// Si "la_palabra" tiene m�s caracteres que caben en el objeto, no se 
	// copia nada y se crea un objeto vac�o.
	// 
	// PRE: "la_palabra" est� formada por una �nica palabra
	
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
	// M�todos de lectura (Get) de los datos individuales 

	// Devuelve el n�mero de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el n�mero de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// A�ade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a a�adir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adici�n se realiza si hay espacio para el nuevo elemento. 
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
	// Devuelve una secuencia incluida en la secuencia impl�cita, que empieza 
	// en la posici�n "pos_init" y tiene "num_datos" valores
	//
	// Recibe: pos_init, posici�n inicial desde donde empieza la copia a la 
	//					 subsecuencia. 
	//		   num_datos, n�mero de valores que se copian a la subsecuencia. 
	// Devuelve: una subsecuencia de la secuencia impl�cita. 
	// 
	// Casos: 1) Si 0 <= pos_init < total_utilizados Y 
	//			 pos_init+num_datos<=total_utilizados
	//			 se devuelve una subsecuencia de tama�o "num_datos"
	//		  2) Si 0 <= pos_init < total_utilizados Y 
	//			 pos_init+num_datos>total_utilizados, se devuelve una 
	//			 subsecuencia de tama�o total_utilizados-pos_init
	//		  3) Si pos_init < 0 � pos_init >= total_utilizados, 
	//			 se devuelve una subsecuencia vac�a.
	//		  4) Si num_datos = 0, se devuelve una subsecuencia vac�a.

	SecuenciaCaracteres Subsecuencia (int pos_init, int num_datos)
	{
		SecuenciaCaracteres a_devolver; // inicialmente vac�a
		
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
// La clase "PosicionEnMatriz" es �til para representar posiciones 
// (coordenadas) en una tabla bidimensional.

class PosicionEnMatriz
{
private:
	int fila;
	int columna;

public: 
	
	/*****************************************************************/
	// Constructor por defecto
	// La posici�n {-1,-1} debe interpretarse como "posici�n no v�lida"
	// (resulta �til en m�todos de b�squeda, por ejemplo). 

	PosicionEnMatriz (void) : fila(-1), columna(-1) { }

	/*****************************************************************/
	// M�todo de escritura: establece simultaneamente los dos valores

	void SetPosicion (int la_fila, int la_columna)
	{
		fila = la_fila;
		columna = la_columna;
	}

	/*****************************************************************/
	// M�todos Get

	int GetFila (void)
	{
		return (fila);
	}
	
	int GetColumna (void)
	{
		return (columna);
	}

	/*****************************************************************/
	// Devuelve TRUE si la posici�n no es v�lida--> {-1,-1}

	bool EsPosicionNoValida (void)
	{
		return ((fila == -1) && (columna == -1));
	}
	/*****************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
// Tabla rectangular de caracteres
//
// Representaci�n: matriz "cl�sica"

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
		indica el n�mero de columnas que deben tener todas las filas.
	b)	El constructor de la matriz recibe una secuencia. La longitud 
		(n�mero de casillas utilizadas) de esa secuencia ser� el valor 
		que se use dentro de la matriz como "numero_de_columnas"

	Para permitir ambas formas, sobrecargamos el constructor.
	*/
	
	/***********************************************************************/
	// Constructor a)
	// Recibe "numero_de_columnas" que indica el n�mero de columnas 
	// que deben tener TODAS las filas.

	TablaRectangularCaracteres (int numero_de_columnas)
		: filas_utilizadas(0), 
		  cols_utilizadas(numero_de_columnas)
	{
	}

	/***********************************************************************/
	// Constructor b)
	// Recibe una secuencia de caracteres. El n�mero de elementos de la 
	// secencia es el valor que se usa como "col_utilizadas"

	TablaRectangularCaracteres (SecuenciaCaracteres primera_fila)
		: filas_utilizadas(0), 
		  cols_utilizadas (primera_fila.TotalUtilizados())
	{
		Aniade(primera_fila); // Actualiza "filas_utilizadas"
	}

	/***********************************************************************/
	// M�todo de lectura: n�mero m�ximo de filas

	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero m�ximo de columnas

	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de filas usadas

	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: n�mero real de columnas usadas

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

	/*****************************************************************/
	// M�todo de lectura: devuelve el caracter que ocupa la casilla 
	// de coordenadas (fila, columna)
	//
	// PRE: 0 <= fila < filas_utilizadas
	// PRE: 0 <= columna < cols_utilizadas	
	
	char Elemento (int fila, int columna)
	{
		return (matriz_privada[fila][columna]);
	}
	
	/***********************************************************************/
	// Devuelve true si la tabla est� vac�a

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
	// A�ade una fila completa. La fila se porporciona en un objeto de 
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
	// Encontrar un car�cter en la matriz y devolver su posici�n.
	// El valor devuelto contiene informaci�n acerca de la posici�n 
	// (fila y columna) de "buscado".  
	// 		En el caso de que no est� contendr� {-1,-1}. 
	// La consulta de la fila y la columna se delega en los m�todos de 
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
	// "Vac�a" una tabla
	
	void EliminaTodos (void)
	{
		filas_utilizadas = 0;
	}
	
	/***********************************************************************/

	//calcula la traspuesta de una tabla y devuelve un valor del tipo TablaRectangularCaracteres

	TablaRectangularCaracteres Traspuesta(){
		TablaRectangularCaracteres traspuesta;

		for(int i = 0; i < filas_utilizadas; i++){
			for(int j = 0; j < ColumnasUtilizadas; j++){
				traspuesta[i][j] = matriz_privada[j][i];			
			}
		}
		return traspuesta;
	}

			
};

/***********************************************************************/
	
///////////////////////////////////////////////////////////////////////

int main (void)
{
	// Solicitar y filtrar las dimensiones de la tabla
	
	int num_filas, num_columnas; // filas y columnas de la tabla rectangular

	do{
		cout << "N�mero de filas: ";
		cin >> num_filas; 
	} while (num_filas < 0);

	do{
		cout << "N�mero de columnas: ";
		cin >> num_columnas; 
	} while (num_columnas < 0);


	// Crear la tabla (inicialmente vac�a)
	
	TablaRectangularCaracteres matriz (num_columnas);


	// Lectura de los datos que compondr�n la tabla

	cout << endl;
	cout << "Introduzca los caracteres de la matriz por filas:" << endl;
	cout << "(solo se consideraran los primeros " << setw(3) << num_columnas 
		 << " caracteres)" << endl;
	cout << endl;
	
	// Los datos que compondr�n cada fila se leer�n en un string.
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
			 
		// Nos quedamos con la subsecuencia inicial de tama�o "num_columnas"
		una_fila = una_fila.Subsecuencia(0,num_columnas); 
		
/*		
		cout << "una_fila (despu�s de ajustar) = ";	
		cout << "|";
		for (int p=0; p<una_fila.TotalUtilizados(); p++)
			cout << una_fila.Elemento(p) << "|";
		cout << endl << endl;
*/	
		
		// A�adimos la secuencia a la matriz
		// Estamos seguros de que tiene el tama�o correcto. 
		
		matriz.Aniade (una_fila);
	}
	
	// Impresi�n de la tabla
	
	cout << endl << endl;
		
	for (int f=0; f<matriz.FilasUtilizadas(); f++) {

		for (int c=0; c<matriz.ColumnasUtilizadas(); c++) {
			cout << matriz.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;


	// B�squeda

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

	//mostramos la traspuesta

	TablaRectangularCaracteres traspuesta;

	traspuesta = matriz.Traspuesta();

	for (int f=0; f<traspuesta.FilasUtilizadas(); f++) {

		for (int c=0; c<traspuesta.ColumnasUtilizadas(); c++) {
			cout << traspuesta.Elemento(f,c) << "  ";	
		}
		cout << endl;
	}
	cout << endl << endl;

	return (0);
}
