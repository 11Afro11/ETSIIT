/*********************************************************************/
// METODOLOGÍA DE LA PROGRANACIÓN
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 8
//
// EJERCICIO 2 Matriz2D_1
//
/*	

 Implementar la clase Matriz2D-1 para elementos de tipo TipoBase. Empleando la repre-
sentación básica conocida, se trata de implementar los siguientes métodos:


*/
/*********************************************************************/
#ifndef MATRIZ_1
#define MATRIZ_1



typedef int TipoBase;
typedef TipoBase ** Matriz;

class Matriz2D_1
{
	private:
		Matriz matriz;
		int filas, columnas;
		static const TipoBase VAL = 7;

/***************************************************************************//*

Metodos privados: copia, reserva y libera

*//***************************************************************************/

		void ReservaEspacio(int fila, int columna);

		void Copia(const Matriz2D_1 &otra_matriz);

		void LiberaMemoria();

	public:

/***************************************************************************//*

 Constructor sin argumentos, que crea una matriz vacía.

*//***************************************************************************/

		Matriz2D_1();

/***************************************************************************//*

 Constructor con un argumento, que crea una matriz cuadrada con el número de 
filas y columnas indicado en el argumento.

*//***************************************************************************/

		Matriz2D_1(int fil);

/***************************************************************************//*

 Constructor con dos argumentos, que crea una matriz con el número de filas 
indicado en el primer argumento y con el número de columnas indicado en el segundo.

*//***************************************************************************/

		Matriz2D_1(int fil, int col);

/***************************************************************************//*

 Constructor con dos argumentos, que crea una matriz con el número de filas 
indicado en el primer argumento y con el número de columnas indicado en el segundo.
e inicualiza los valores al tercer parametro

*//***************************************************************************/

		Matriz2D_1(int fil, int col, TipoBase value);

/***************************************************************************//*

 Constructor de copia.

*//***************************************************************************/

		Matriz2D_1(const Matriz2D_1 &matrizd);

/***************************************************************************//*

 Destructor.

*//***************************************************************************/

		~Matriz2D_1();

/***************************************************************************//*

Metodo que comprueba si una matriz esta vacia

*//***************************************************************************/

		bool EstaVacia() const;

/***************************************************************************//*

Metodo que asigna un valor a un aposicion concreta e la matriz

*//***************************************************************************/

		void PonValor (int fila, int col, TipoBase valor);

/***************************************************************************//*

Metodo que devuelve un valor de la matriz

*//***************************************************************************/

		TipoBase LeeValor (int fila, int col)const;

/***************************************************************************//*

 Método que inicializa todas las casillas de la matriz al valor indicado como 
argumento. Si no se especifica ninguno, inicia todos los nodos al valor nulo.

*//***************************************************************************/

		void Asigna (TipoBase valor = VAL);

/***************************************************************************//*

Metodo que devuelve las filas 

*//***************************************************************************/

		int Filas()const;

/***************************************************************************//*

Metodo que devuelve las columnas

*//***************************************************************************/

		int Columnas() const;

};

/***************************************************************************//*

Funcion externa a la clase que muestra la matriz por pantalla.

*//***************************************************************************/

void PintaMatriz (const Matriz2D_1 &matr, char*etiqueta);

#endif