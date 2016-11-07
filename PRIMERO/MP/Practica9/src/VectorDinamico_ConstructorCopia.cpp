/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
// EJERCICIO 1
//
// Implementaci�n de la clase VectorDinamico (Incluye constructor de copia).
//
// Fichero: VectorDinamico_ConstructorCopia.cpp
//
/***************************************************************************/

	#include <iostream>
	#include <iomanip>
	#include <cstring>
	#include <string>
	
	#include "VectorDinamico_ConstructorCopia.h"
	
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
	// M�todos de consulta de los datos privados

	// Devuelve el n�mero de casillas reservadas 
	int VectorDinamico :: Capacidad (void) const
	{
		return (tam);
	}
	
	// Devuelve el n�mero de casilllas ocuppadas
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
	// A�ade un elemento al vector. Este m�todo puede provocar el 
	// redimensionamiento del vector si no hay espacio disponible. 

	void VectorDinamico :: Aniade (TipoBase valor)
	{
		// Comprobar si es necesario redimensionar el almac�n
		
		if (NumDatosGuardados() == Capacidad()) { 
			
			// Redimensionar 
			RedimensionaAlmacen ();
		}

		datos [usados] = valor;
		usados++;
	}

    /***********************************************************************/
	// Devuelve el contenido de la casilla "posicion"
	// PRE: 0 <= posicion < usados 

	TipoBase VectorDinamico :: Elemento (int posicion) const
	{
		return (datos [posicion]);
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

	void VectorDinamico :: Inicializar (const TipoBase &valor_inicial)
	{
		for (int i=0; i<tam; i++) 
			datos[i] = valor_inicial;
	}
		
    /***********************************************************************/
	// Redimensiona el vector din�mico de acuerdo al tipo de redimensi�n 
	// establecido y registrado.
	// Copia todos los datos en el nuevo almac�n.  

	void VectorDinamico :: RedimensionaAlmacen (void)
	{
        switch (tipo_redimension) {

            case (DeUnoEnUno): // 1 casilla m�s
                tam++;
                break;

            case (EnBloques): // TAM_BLOQUE casillas m�s
                tam+=TAM_BLOQUE;
                break;

            case (Duplicando): // Duplicar tama�o
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
		
		// Liberar la memoria del antiguo almac�n
		delete [] datos; 

		// Reasignacion del puntero "datos" paara que referencie a la 
		// nueva zona de memoria ampliada y con los datos copiados. 
		datos = tmp; 
	}


	VectorDinamico & VectorDinamico::operator= (const VectorDinamico & orig){
		if(&orig != this){
			LiberaMemoria();
			PideMemoria(orig.tam);
			CopiarDatos(orig);
		}
		return *this;
	}

	VectorDinamico & VectorDinamico::operator= (const TipoBase data){
		
		Inicializar(data);
		return *this;
	}

	TipoBase & VectorDinamico ::  operator [] (const int posicion)
	{
		return (datos [posicion]);
	}


    /***********************************************************************/
    /***********************************************************************/
	// Otras funciones no pertenecientes a la clase
    /***********************************************************************/
    /***********************************************************************/
    
    /***********************************************************************/
	// Muestra el contenido de un vector din�mico 
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
			cout << setw(3) << v.Elemento (i) << " "; ;  
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
