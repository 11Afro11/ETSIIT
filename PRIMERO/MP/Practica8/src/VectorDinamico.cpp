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
// EJERCICIO 1 -Vector Dinamico
//
/*	

 Implementar la clase VectorDinamico para trabajar con vectores de datos de tipo
TipoBase. Los vectores dinámicos tendrán un tamaño arbitrario, y no definido a priori.
Proponer una representación para la clase e implementar los siguientes métodos:


*/
/*********************************************************************/

#include "VectorDinamico.h"

#include <iostream>

#include <cstring>

using namespace std;

/*class VectorDinamico{

	private:
		int total_utilizados;
		Vector ptr;
		int casillas;
		static const int TAM_DEF = 10;
		static const int bloque = 5;*/

/***************************************************************************//*

Metodo Privado Reserva memoria que reserva memoria para un tamanio pasado como
 parametro

*//***************************************************************************/

		void VectorDinamico::ReservaMemoria(int tam){
			ptr = 0;
			if(tam > 0){
				ptr = new TipoBase[tam];
			}
		}

/***************************************************************************//*

Metodo Privado Libera memoria, que se encarga de borrar la memoria ocupada

*//***************************************************************************/

		void VectorDinamico::LiberaMemoria(){
			delete[]ptr;
			ptr = NULL;
		}

/***************************************************************************//*

Metodo Privado que copia loselementos de un objeto en otro objetode la misma clase

*//***************************************************************************/

		void VectorDinamico::Copia(const VectorDinamico &otro_vector){

			this->total_utilizados = otro_vector.total_utilizados;
			this->casillas = otro_vector.casillas;

			memcpy(ptr, otro_vector.ptr, sizeof(TipoBase)*total_utilizados);

		}

//	public:	


/***************************************************************************//*

Constructor por defecto que se encarga de crear un vector con TAM_DEF casillas

*//***************************************************************************/	

		VectorDinamico::VectorDinamico(){
			total_utilizados = 0;
			ReservaMemoria(TAM_DEF);


		}

/***************************************************************************//*

Constructorcon un argumento que crea un vector con un numero de casillas pasado 
por parametro

*//***************************************************************************/

		VectorDinamico::VectorDinamico(int numero_casillas){
			total_utilizados = 0;
			casillas = numero_casillas;
			ReservaMemoria(numero_casillas);

		}

/***************************************************************************//*

Constructor que crea un vector con un numero de casillas e iguala todos sus 
elementos al segundo parametro

*//***************************************************************************/

		VectorDinamico::VectorDinamico(int numero_casillas, TipoBase value = 0){
			total_utilizados = 0;
			casillas = numero_casillas;
			ReservaMemoria(numero_casillas);
			for(int i = 0; i < numero_casillas; i++){
				ptr[i] = value;
			}

		}

/***************************************************************************//*

Constructor de copia

*//***************************************************************************/


		VectorDinamico::VectorDinamico(const VectorDinamico &un_vector){
			
			ReservaMemoria(un_vector.casillas);
			Copia(un_vector);
		}

/***************************************************************************//*

Destructor

*//***************************************************************************/

		VectorDinamico::~VectorDinamico(){
			LiberaMemoria();
		}


/***************************************************************************//*

Metodo que aniade un elemento al final del vector

*//***************************************************************************/

		void VectorDinamico::Aniade(TipoBase elemento){

			if(total_utilizados >= casillas){			
				Redimensiona(DeUnoEnUno);
			}
			ptr[total_utilizados]=elemento;

			total_utilizados++;
		}

/***************************************************************************//*

Metodo que elimina la ultima posicion

*//***************************************************************************/

		void VectorDinamico::EliminaUltimo(){

			if(total_utilizados != 0){

				if(total_utilizados == 1){
					LiberaMemoria();
					total_utilizados = 0;
				}
				else{

					Vector aux;
					aux = ptr;
					total_utilizados--;
					ReservaMemoria(casillas);
					memcpy(ptr, aux,sizeof(TipoBase)*total_utilizados);

					delete[] aux;
				}
			}
		}

/***************************************************************************//*

Metodo que elimina una posicion pasada como parametro

*//***************************************************************************/

		void VectorDinamico::EliminaPosicion(int pos){

			if(total_utilizados != 0){

				if(pos == total_utilizados- 1){
					EliminaUltimo();
				}

				if((pos < total_utilizados) && total_utilizados > 1){
					Vector aux;
					aux = ptr;
					total_utilizados--;
					ReservaMemoria(casillas);
					for(int i = pos;i < total_utilizados; i++){
						ptr[i] = aux[i+1];
					}

					delete[] aux;
				}
				else{
					LiberaMemoria();
					total_utilizados = 0;
				}
			}
		}

/***************************************************************************//*

Metodo que devuelve el numero de casillas del vector

*//***************************************************************************/

		TipoBase VectorDinamico::ConsultaCasillas(){

			return casillas;
		}

/***************************************************************************//*

Metodo que devuelve el numero de casillas utilizadas

*//***************************************************************************/

		TipoBase VectorDinamico::ConsultaUtil(){
			return total_utilizados;
		}

/***************************************************************************//*

Metodo que recibe una posicion y devuelve el elemento que se almacena en esa 
posicion

*//***************************************************************************/

		TipoBase VectorDinamico::Elemento(int pos){
			return ptr[pos];
		}

/***************************************************************************//*

Metodo que redimensiona el vector que recibe como parametro un dato de tipo
TipoRedimension

*//***************************************************************************/

		void VectorDinamico::Redimensiona (TipoRedimension opcion){ 

			Vector aux;
			aux = ptr;
			if(opcion == DeUnoEnUno){
				casillas +=1;
			}
			if(opcion == EnBloques){
				casillas += bloque;
			}
			if(opcion == Duplicando){
				casillas = 2 * casillas;
			}

			ReservaMemoria(casillas);

			memcpy(ptr, aux, sizeof(TipoBase)*total_utilizados);
			
			delete[] aux;
		}


		VectorDinamico & VectorDinamico::operator= (const VectorDinamico & orig){
			if(&orig != this){
				Libera();
				Reserva(orig.n);
				Copia(orig);
			}
			return *this;
		}

		VectorDinamico & VectorDinamico::operator= (TipoBase dato){
			
			memset(ptr, dato, sizeof(TipoBase)*total_utilizados);
			return *this;
		}

		VectorDinamico& VectorDinamico::operator= (const TipoBase dato){
			
			memset(ptr, dato, sizeof(TipoBase)*total_utilizados);
			return *this;
		}

		TipoBase & VectorDinamico ::  operator [] (const int posicion)
		{
			return (ptr [posicion]);
		}

		VectorDinamico VectorDinamico::operator+  (const VectorDinamico &orig)const{
			VectorDinamico suma;
			suma.total_utilizados = total_utilizados + orig.total_utilizados;
			suma.ptr = new float[suma.total_utilizados];
			memcpy(suma.ptr, ptr,sizeof(float)*total_utilizados);
			memcpy(suma.ptr + total_utilizados-1,orig.ptr, sizeof(float)*orig.total_utilizados);

			return suma;
		}

		VectorDinamico VectorDinamico::operator+  (const TipoBase dato)const{
			VectorDinamico suma = new TipoBase [total_utilizados + 1];
			memcpy(suma.ptr, ptr,sizeof(float)*total_utilizados);
			suma.ptr[total_utilizados] = dato;
			total_utilizados++;

			return suma;
		}

		VectorDinamico &VectorDinamico::operator+=  (const VectorDinamico &orig){
			VectorDinamico suma;
			suma.total_utilizados = total_utilizados + orig.total_utilizados;
			suma.ptr = new float[suma.total_utilizados];
			memcpy(suma.ptr, ptr,sizeof(float)*total_utilizados);
			memcpy(suma.ptr + total_utilizados-1,orig.ptr, sizeof(float)*orig.total_utilizados);

			total_utilizados = suma.total_utilizados;

			Copia(suma);

			return *this;
		}

		VectorDinamico &VectorDinamico::operator+=  (const TipoBase dato){
			VectorDinamico suma = new TipoBase [total_utilizados + 1];
			memcpy(suma.ptr, ptr,sizeof(float)*total_utilizados);
			suma.ptr[total_utilizados] = dato;
			total_utilizados++;

			Copia(suma);

			return *this;
		}


		bool VectorDinamico::operator==(const VectorDinamico & otro)const{
			bool igual = false;
			if(total_utilizados == otro.total_utilizados){
				igual = true;
			}
			int i = 0;
			for(int i = 0; i < total_utilizados && igual; i++){
				if(ptr[i] != otro.ptr[i]){
					igual = false;
				}
			}

			return igual;
		}

		bool VectorDinamico::operator!=(const VectorDinamico & otro)const{
			bool distinto = false;
			if(total_utilizados != otro.total_utilizados){
				distinto = true;
			}
			else{
				int i = 0;
				for(int i = 0; i < total_utilizados && !distinto; i++){
					if(ptr[i] != otro.ptr[i]){
						distinto = true;
					}
				}
			}

			return distinto;
		}


		

/***************************************************************************//*

Funcion externa a la clase que muestra el vector por pantalla

*//***************************************************************************/

		void PintaVectorDinamico(VectorDinamico vec,char * etiqueta){
			cout << endl << etiqueta <<endl;
			for(int i = 0; i < vec.ConsultaUtil(); i++){
				cout << vec.Elemento(i) << " ";
			}
		}
		
//};