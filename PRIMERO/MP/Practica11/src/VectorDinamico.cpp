/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 1
//
// Implementación de la clase VectorDinamico 
// (Incluye constructor de copia, operador de asignación y sobrecarga de []).
//
// Fichero: VectorDinamico_Asignacion-Acceso.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	#include <cstring>
	#include <string>
	
	#include "VectorDinamico.h"
	
	using namespace std; 

    /***********************************************************************/
	// Constructor sin argumentos, o con un argumento
	VectorDinamico :: VectorDinamico (int tam_inicial) 
		: tam (tam_inicial), usados (0), tipo_redimension (EnBloques) 
	{
		PideMemoria (tam);
	}

    /***********************************************************************/
	// Constructor de copia
	VectorDinamico :: VectorDinamico (const VectorDinamico & otro)
		: tam (otro.tam), usados (otro.usados), 
		  tipo_redimension (otro.tipo_redimension)
	{
		PideMemoria (tam);
		CopiarDatos (otro);
	}
	
    /***********************************************************************/
	// Destructor
	VectorDinamico :: ~VectorDinamico (void)
	{
		LiberaMemoria();
	}

    /***********************************************************************/
	// Métodos de consulta de los datos privados

	// Devuelve el número de casillas reservadas 
	int VectorDinamico :: Capacidad (void) const
	{
		return (tam);
	}
	
	// Devuelve el número de casilllas ocuppadas
	int VectorDinamico :: NumDatosGuardados(void) const
	{
		return (usados);
	}
	
    /***********************************************************************/
	// Establece/consulta el tipo de redimensionamiento

	// Establece el tipo de redimensionamiento
	void VectorDinamico :: FijaRedimensionamiento (TipoRedimension tipo)
	{
		tipo_redimension = tipo;
	}

	// Devuelve el tipo de redimensionamiento
	TipoRedimension VectorDinamico :: ConsultaRedimensionamiento (void) const
	{
		return (tipo_redimension);
	}
	
    /***********************************************************************/
	// Añade un elemento al vector. Este método puede provocar el 
	// redimensionamiento del vector si no hay espacio disponible. 

	void VectorDinamico :: Aniade (TipoBase valor)
	{
		// Comprobar si es necesario redimensionar el almacén
		
		if (NumDatosGuardados() == Capacidad()) { 
			
			// Redimensionar 
			RedimensionaAlmacen ();
		}

		datos [usados] = valor;
		usados++;
	}

    /***********************************************************************/
	// Metodo de acceso individual a elementos
	// Metodo de lectura
	// PRE: 0 <= posicion < usados	
	
	TipoBase & VectorDinamico ::  operator [] (const int posicion)
	{
		return (datos [posicion]);
	}
	
	TipoBase & VectorDinamico ::  operator [] (const int posicion) const
	{
		return (datos [posicion]);
	}	
	
    /***********************************************************************/
	// Operador de asignación desde otro dato VectorDinamico
	VectorDinamico & VectorDinamico :: operator = (const VectorDinamico & otro)
	{
		if (this != &otro) { // Evitar autoasignación

			// Libera la memoria ocupada
			LiberaMemoria();	

			// Reserva de memoria para los datos del otro vector
			PideMemoria (otro.usados);

			// Copia los campos privados y los coeficientes
			CopiarDatos(otro);
		}
		return (*this);  // Devuelve el objeto implicito:
						 // parte izquierda de la asignación
	}
	
	/*********************************************************************/
	// Operador de asignación desde un dato TipoBase
	VectorDinamico & VectorDinamico :: operator = (const TipoBase & valor)
	{
		for (int i=0; i < usados; i++) 
			datos[i] = valor;
			  
		return (*this); // devuelve el objeto implicito:
						// parte izquierda de la asignación
	}

	/*********************************************************************/
	// Operadores de suma 

	VectorDinamico VectorDinamico::operator+  (const VectorDinamico &orig)const{
		VectorDinamico suma;
		suma.usados = usados + orig.usados;
		suma.datos = new TipoBase[suma.usados];
		memcpy(suma.datos, datos,sizeof(TipoBase)*usados);
		memcpy(suma.datos + usados-1,orig.datos, sizeof(TipoBase)*orig.usados);

		return suma;
	}

	VectorDinamico VectorDinamico::operator+  (const TipoBase dato)const{
		VectorDinamico suma;
		suma.datos = new TipoBase [usados + 1];
		memcpy(suma.datos, datos,sizeof(TipoBase)*usados);
		suma.datos[usados] = dato;
		suma.usados = usados +1;

		return suma;
	}

	/*********************************************************************/
	// Operadores mayor igual

	VectorDinamico &VectorDinamico::operator+=  (const VectorDinamico &orig){
		*this = *this + orig;

		return *this;
	}

	VectorDinamico &VectorDinamico::operator+=  (const TipoBase dato){
		
		*this = *this + dato;

		return *this;
	}

	/*********************************************************************/
	// Operadores booleanos
	/***************************************************************************/
	// igual

	bool VectorDinamico::operator==(const VectorDinamico & otro)const{
		bool igual = usados == otro.usados;

		for(int i = 0; i < usados && igual; i++){
			igual = datos[i] == otro.datos[i];
		}

		return igual;
	}

	/***************************************************************************/
	// Distinto

	bool VectorDinamico::operator!=(const VectorDinamico & otro)const{
		bool distinto = !(*this == otro);
		
		return distinto;
	}

	/***************************************************************************/
	//Mayor

	bool VectorDinamico::operator>(const VectorDinamico & otro)const{
		bool mayor = usados > otro.usados;
	
		if(usados == otro.usados || mayor){
			for(int i = 0; i < usados && !mayor; i++){
				mayor = datos[i] > otro.datos[i];
			}
		}

		return mayor;
	}

	/***************************************************************************/
	//menor

	bool VectorDinamico::operator<(const VectorDinamico & otro)const{
		bool menor = usados < otro.usados;
	

		if(usados == otro.usados || menor){
			for(int i = 0; i < usados && !menor; i++){
				menor = datos[i] < otro.datos[i];
			}
		}

		return menor;
	}

	/***************************************************************************/
	//Mayor igual


	bool VectorDinamico::operator>=(const VectorDinamico & otro)const{
		bool mayor_igual = (*this == otro) || (*this > otro);

		return mayor_igual;
	}

	/***************************************************************************/
	//Menor igual

	bool VectorDinamico::operator<=(const VectorDinamico & otro)const{
		bool menor_igual = (*this == otro) || (*this < otro);

		return menor_igual;
	}

    /***********************************************************************/
    // Pide memoria para guardar "num_casillas" datos	
	void VectorDinamico :: PideMemoria (const int num_casillas)
	{
		datos = new int[num_casillas]; 
	}
	
    /***********************************************************************/
    // Libera memoria
	void VectorDinamico :: LiberaMemoria (void)
	{
		delete [] datos;
	}

    /***********************************************************************/
    // Copiar datos desde otro objeto de la clase
    // PRE: Se ha reservado memoria para los datos
	void VectorDinamico :: CopiarDatos (const VectorDinamico & otro)
	{
		// Copia los valores de los campos privados desde "otro" 
		tam = otro.tam;  
		usados = otro.usados;			 

		// Copiar los valores 
		memcpy (datos, otro.datos, usados*sizeof(int));
	}
		
    /***********************************************************************/
	// Redimensiona el vector dinámico de acuerdo al tipo de redimensión 
	// establecido y registrado.
	// Copia todos los datos en el nuevo almacén.  

	void VectorDinamico :: RedimensionaAlmacen (void)
	{
        switch (tipo_redimension) {

            case (DeUnoEnUno): // 1 casilla más
                tam++;
                break;

            case (EnBloques): // TAM_BLOQUE casillas más
                tam+=TAM_BLOQUE;
                break;

            case (Duplicando): // Duplicar tamaño
                tam*=2;
                break;
        }
	
		cout << endl;
		cout << "REDIMENSIONADO HASTA --> " << tam << " CASILLAS" << endl;
		cout << endl;

		// Pedir memoria para el nuevo almacen 
		int * tmp = new int[tam]; 

		// Copiar los datos 
		memcpy (tmp, datos, usados*sizeof(int)); 
		
		// Liberar la memoria del antiguo almacén
		delete [] datos; 

		// Reasignacion del puntero "datos" paara que referencie a la 
		// nueva zona de memoria ampliada y con los datos copiados. 
		datos = tmp; 
	}


    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
    /***********************************************************************/
	// Muestra el contenido de un vector dinámico 
	void PintaVectorDinamico (const VectorDinamico &v, const char * const msg)
	{
		cout << endl; 
		cout << msg << endl;
		
		cout << "  Capacidad = " << v.Capacidad()  << " datos" << endl; 
		cout << "  Contiene = " << v.NumDatosGuardados() << " datos" << endl; 
		cout << "  Redimensionamiento = ";  
		PintaRedimensionamiento (v.ConsultaRedimensionamiento());
		cout << endl;    
		
		for (int i=0; i < v.NumDatosGuardados(); i++) 
			cout << setw(3) << v[i] << " ";  
		cout << endl << endl;
	}
	
    /***********************************************************************/
	// Muestra el cobtenido del valor enumerado de tipo "TipoRedimension"
	void PintaRedimensionamiento (TipoRedimension tipo)
	{
		string str_tipo;
		
		switch (tipo) { 
		
			case (DeUnoEnUno):	
						str_tipo = "de uno en uno";
						break;
			case (EnBloques):	
						str_tipo = "en bloques";
						break;
			case (Duplicando):	
						str_tipo = "duplicando";
						break; 
		}

		cout << str_tipo;
	}
	
	/***********************************************************************/
    /***********************************************************************/
