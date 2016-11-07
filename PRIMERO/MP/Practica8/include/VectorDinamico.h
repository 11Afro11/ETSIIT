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
//EJERCICIO 1 - VectorDinamico
//
/*	

Implementar la clase VectorDinamico para trabajar con vectores de datos de tipo
TipoBase. Los vectores dinámicos tendrán un tamaño arbitrario, y no definido a priori.
Proponer una representación para la clase e implementar los siguientes métodos:


*/
/*********************************************************************/

#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

//declaramos los datos de tipo TipoBase, por defecto int
typedef int TipoBase;

//declaamos un puntero a datos de tipo TipoBase
typedef TipoBase * Vector;

//declaramos el TipoRedimension
enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

//delcaramos la clase
class VectorDinamico{

	private:

		//atributos privados

		int total_utilizados;
		Vector ptr;
		int casillas;
		static const int TAM_DEF = 10;
		static const int bloque = 5;

/***************************************************************************//*

Metodos Privados

*//***************************************************************************/

		void ReservaMemoria(int tam);

		void LiberaMemoria();

		void Copia(const VectorDinamico &otro_vector);

	public:

/***************************************************************************//*

Constructores

*//***************************************************************************/

		VectorDinamico();

		VectorDinamico(int numero_casillas);

		VectorDinamico(int numero_casillas, TipoBase value);

		VectorDinamico(const VectorDinamico &un_vector);

/***************************************************************************//*

Destructor

*//***************************************************************************/

		~VectorDinamico();

/***************************************************************************//*

Metodo que anuiade un elemento al final

*//***************************************************************************/

		void Aniade(TipoBase elemento);

/***************************************************************************//*

Metodo que elimina la ultima posicion

*//***************************************************************************/

		void EliminaUltimo();

/***************************************************************************//*

Metodo que elimina una posicion pasada como parametro

*//***************************************************************************/

		void EliminaPosicion(int pos);

/***************************************************************************//*

Metodo que devuelve el numero de casillas

*//***************************************************************************/

		TipoBase ConsultaCasillas();

/***************************************************************************//*

metodo que devuelve un elemento

*//***************************************************************************/

		TipoBase Elemento(int pos);

/***************************************************************************//*

Metodo que devuelve el numero de casillas utilizadas

*//***************************************************************************/

		TipoBase ConsultaUtil();

/***************************************************************************//*

Metodo que redimensiona el vectos

*//***************************************************************************/

		void Redimensiona (TipoRedimension opcion);
		
};


/***************************************************************************//*

Funcion que pinta un vector

*//***************************************************************************/

		void PintaVectorDinamico(VectorDinamico vect, char*etiqueta);

#endif