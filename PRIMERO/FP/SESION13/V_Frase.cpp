/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIER√çA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 9
//
//
Reescribid la soluciÛn al ejercicio 19 (clase Frase) de la relaciÛn de problemas IV
para que use como dato miembro privado un vector de palabras.
Cada palabra ser· un objeto de la clase Palabra. Un objeto de la clase palabra representa
a una sucesiÛn de caracteres que no contiene espacios en blanco intermedios.
Observen que las tareas que se realizan en algunos de los mÈtodos de la
antigua clase Frase corresponden ahora a la clase Palabra (por ejemplo,
EliminaBlancosIniciales y EliminaBlancosFinales) y otros mÈtodos deben
reescribirse completamente (por ejemplo, BorraPalabra).

/******************************************************************
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
/*CLASE PALABRA QUE SE USARA COMODATOS MIEMBRO DE LA CLASE FRASE*/

class Palabra{

private:
	static const int TAMANIO = 100;
	char palabra[TAMANIO];
	int total_utilizados;
public:
	
	//constructor sin argumentos
	
	Palabra (void){
		total_utilizados = 0;
	}
	
	//metodo que devuelve el tamaÒo del vector
	
	int TotalUtilizados(){
		return total_utilizados;
	}
	
	//metodo que devuelvelacapacidad del vector
	
	int Capacidad(){
		return TAMANIO;
	}
	
	//metodo que aniade elementos al vector
	
	void Aniade(char nuevo){
		if (total_utilizados < TAMANIO){
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}
	
	//metodo que muestra los elementosdel vector
	
	char Elemento(int indice){
		return vector_privado[indice];
	}
	
	//metodo que elimina una componente
		
	void Elimina (int indice){
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posiciÛn a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posiciÛn del ˙ltimo 
    
			for (int i = indice ; i < tope ; i++)
				palabra[i] = palabra[i+1];  
    
			total_utilizados--;    
		}
	}
	
	//metodo que elimina los blanco iniciales
	
	void EliminaBlancosIniciales (void){
		while (isspace(palabra[0]) && (total_utilizados>0)) 
			Elimina(0);
	}
	
	//metodo queeliminalos blancos finales
	
	void EliminaBlancosFinales (void){
		while (isspace(palabra[total_utilizados-1]) 
			   && (total_utilizados>0)) 
			Elimina(total_utilizados-1);
	}
	
};





class Frase{

private:
	
	//vector privado
	
	static const int TAMANIO = 100;
	Palabra cadena_privada[TAMANIO];
	int total_utilizados;
	
public:	
	/***********************************************************************/
	// Constructores
	
	// Constructor sin argumentos

	Frase (void) 	
	{
		total_utilizados = 0;
	}
	/***********************************************************************/
	Frase (Frase la_frase) 	
	{
		int longitud_la_frase = la_frase.length();
		
		if (longitud_la_frase <= TAMANIO) {
			
			for (int i=0; i<longitud_la_frase; i++)
				cadena_privada[i]= la_frase[i];
				
			total_utilizados = longitud_la_frase;
		}
		else 
			total_utilizados = 0;
	}

	/***********************************************************************/
	// MÈtodos de lectura (Get) de los datos individuales 
	
	// Devuelve el n˙mero de caracteres.
	
	int NumCaracteres (void)
	{
		return (total_utilizados);
	}
	
	// Devuelve el n˙mero de casillas disponibles
	
	int Capacidad (void)
	{
		return (TAMANIO);
	}
	
	/***********************************************************************/
	// Devuelve el car·cter de la casilla "indice" 
	// Recibe: indice, la posiciÛn del car·cter que queremos obtener.
	//
	// PRE: 0 <= indice < total_utilizados

	char GetCaracter (int indice)
	{
		return (cadena_privada[indice]);
	}

	/***********************************************************************/
	// AÒade un car·cter a la frase (al final)
	// Recibe: c, el car·cter que se va a aÒadir
	// Recibe: nuevo, el elemento que se va a aÒadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adiciÛn se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (Palabra c){
		if (total_utilizados < TAMANIO) {
			cadena_privada[total_utilizados] = c;
			total_utilizados++;
		}
	}

	/*****************************************************************/
	// Devuelve cu·ntas palabras hay en la frase.
	// Una palabra est· separada por otra por uno o m·s espacios en blanco. 

	int NumeroPalabras (void){
		return total_utilizados;	
	}

	/*****************************************************************/
	// Borra la palabra k-Èsima.
	// 
	// Recibe: k, el n˙mero de la palabra a borrar
	//
	// PRE: 1 <= k <= NumeroPalabras()
	
	void BorraPalabra (int k){
		// Recorremos de izquierda a derecha toda las componentes 
		// que hay a la derecha de la posiciÛn a eliminar
		//		Le asignamos a cada componente la que hay a su derecha

		if ((indice >= 0) && (indice < total_utilizados)) {

			int tope = total_utilizados-1; // posiciÛn del ˙ltimo 
    
			for (int i = indice ; i < tope ; i++)
				palabra[i] = palabra[i+1];  
    
			total_utilizados--;    
		}
	}

	/***********************************************************************/
	// Devuelva la k-Èsima palabra de la cadena.
	// Si hay menos de k palabras, devolver· la cadena vacÌa "".
	// Recibe: k, el n˙mero de la palabra a devolver
	//
	// PRE: 1 <= k <= NumeroPalabras()
	// Si   k > NumeroPalabras() devuelve la cadena vacÌa
	
	Palabra DevuelvePalabra (int k){
		return cadena_privada[k];
	}

	/***********************************************************************/
	
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

int main()
{

	int tope; 

	/*****************************************************************/
	Palabra una_palabra
	Frase una_frase;

	una_palabra.Aniade ('H');
	una_palabra.Aniade ('o');
	una_palabra.Aniade ('l');
	una_palabra.Aniade ('a');

	una_frase.Aniade(una_palabra)

	tope = una_frase.NumCaracteres();

	cout << "|";
	for (int i=0; i<tope; i++) 
		cout << una_frase.GetCaracter(i) << "|";

	cout << endl << endl;

	/*****************************************************************/

	Frase otra_frase (una_frase);


	tope = otra_frase.NumCaracteres();

	cout << "|";
	for (int i=0; i<tope; i++) 
		cout << otra_frase.GetCaracter(i) << "|";
	cout << endl << endl;

	cout << "Num. palabras = " << otra_frase.NumeroPalabras() << endl;
	cout << endl;
	
	for (int i=1; i<=otra_frase.NumeroPalabras(); i++) 	
		cout << "Palabra = " << i << ": " << otra_frase.Palabra(i) << endl;
	cout << endl << endl;

	/*****************************************************************/
	
	cout << endl;
	cout << "ELIMINANDO BLANCOS INICIALES" << endl; 	
	cout << endl;
		
	otra_frase.EliminaBlancosIniciales();
	
	tope = otra_frase.NumCaracteres(); // Es importante volver a calcularlo

	cout << "|";
	for (int i=0; i<tope; i++) 
		cout << otra_frase.GetCaracter(i) << "|";
	cout << endl << endl;

	cout << "Num. palabras = " << otra_frase.NumeroPalabras() << endl;
	cout << endl;
	
	/*****************************************************************/
	
	cout << endl;
	cout << "ELIMINANDO BLANCOS FINALES" << endl; 	
	cout << endl;
		
	otra_frase.EliminaBlancosFinales();
	
	tope = otra_frase.NumCaracteres(); // Es importante volver a calcularlo

	cout << "|";
	for (int i=0; i<tope; i++) 
		cout << otra_frase.GetCaracter(i) << "|";
	cout << endl << endl;

	cout << "Num. palabras = " << otra_frase.NumeroPalabras() << endl;
	cout << endl;

	/*****************************************************************/
	
	cout << endl;
	cout << "BORRANDO PALABRA 2" << endl; 	
	cout << endl;

	otra_frase.BorraPalabra (2);
		
	cout << "Num. palabras = " << otra_frase.NumeroPalabras() << endl;
	cout << endl;

	for (int i=1; i<=otra_frase.NumeroPalabras(); i++) 	
		cout << "Palabra = " << i << ": " << otra_frase.Palabra(i) << endl;
	cout << endl << endl;

	cout << "|";
	for (int i=0; i<otra_frase.NumCaracteres(); i++) 
		cout << otra_frase.GetCaracter(i) << "|";
	cout << endl << endl;	
	
	
	cout << endl;
	cout << "BORRANDO PALABRA 3" << endl; 	
	cout << endl;
	
	otra_frase.BorraPalabra (3);
	
	cout << "Num. palabras = " << otra_frase.NumeroPalabras() << endl;
	cout << endl;

	for (int i=1; i<=otra_frase.NumeroPalabras(); i++) 	
		cout << "Palabra = " << i << ": " << otra_frase.Palabra(i) << endl;
	cout << endl <<endl;
	
	cout << "|";
	for (int i=0; i<otra_frase.NumCaracteres(); i++) 
		cout << otra_frase.GetCaracter(i) << "|";
	cout << endl << endl;
	
	/*****************************************************************/

	Frase vacia;

	vacia.Aniade (' ');
	vacia.Aniade (' ');
	vacia.Aniade (' ');
	vacia.Aniade (' ');

	tope = vacia.NumCaracteres(); 


	cout << endl;
	cout << "CADENA VACIA" << endl; 	
	cout << endl;
	
	cout << "|";
	for (int i=0; i<tope; i++) 
		cout << vacia.GetCaracter(i) << "|";
	cout << endl << endl;

	cout << "Num. palabras = " << vacia.NumeroPalabras() << endl;
	cout << endl << endl;
	
	for (int i=1; i<=vacia.NumeroPalabras(); i++) 	
		cout << "Palabra = " << i << ": " << vacia.Palabra(i) << endl;
	cout << endl << endl;
	
	vacia.EliminaBlancosIniciales();
	
	tope = vacia.NumCaracteres(); 

	if (tope > 0) {
		cout << "|";
		for (int i=0; i<tope; i++) 
			cout << vacia.GetCaracter(i) << "|";
	}
	else 
		cout << "La cadena est· vacÌa";
	cout << endl;
	
	cout << endl << endl;

	return (0);
}
