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
// SESION 4
// FICHERO MiCadenaClasica.cpp
//
/*	

Fichero que contiene la función main que se encargara de probar las funciones desarrolladas en los ficheros 

MiCadenaClasica.h y MiCadenaClasica.cpp


*/
/*********************************************************************/



#include <iostream>
//incluimos las cabeceras de las funciones
#include <MiCadenaClasica.h>


using namespace std;


int main(){
	//declaramos las variables necesarias
	const int TAM = 100;
	char letra;
	char cadena[TAM];
	char cadena2[TAM];
	char cadena_auxiliar[TAM];
	int compara;

	//solicitamos los datos por pantalla

	cout << "Introduzca la cadena: ";

	cin.getline(cadena, TAM);

	cout <<endl;

	
	//llamada a la primera funcion, tamanio de las cadenas.

	cout <<endl<<"La longitud de la cadena es de: "<<longitud_cadena(cadena)<<endl;

	//tercera funcion, palindromo, mostramos por pantalla si las cadenas son o no son palindromos


	if(palindromo(cadena)){
		cout <<endl<<"La cadena es un palindromo"<<endl;
	}
	else{
		cout <<endl<<"La cadena NO es un palindromo"<<endl;
	}


	pinta();

	//llamada a la segunda funcion, comparamos cadenas, incluimos un filtro de las posibilidades con un mensaje



	cout << "Introduzca otra cadena: ";

	cin.getline(cadena2, TAM);

	pinta();

	compara = comparar_cadenas(cadena, cadena2);

	if(compara == -1){
		cout << endl <<"La primera cadena es menor que la segunda"<<endl;
	}
	if(compara == 1){
		cout << endl <<"La segunda cadena es menor que la primera"<<endl;
	}
	if(compara == 0){
		cout << endl <<"Las cadenas son iguales"<<endl;
	}

	pinta();


	//cuarta funcion, invertir, mostramos por pantalla las cadenas invertidas

	char *puntero = invierte_cadena(cadena, cadena_auxiliar);

	cout <<endl<<"La primera cadena invertida es: "<< puntero <<endl;

	char *puntero2 = invierte_cadena(cadena2, cadena_auxiliar);

	cout <<endl<<"La segunda cadena invertida es: "<< puntero2 << endl;;


	pinta();

	//sexta funcion, encadenar, vamos a encadenar a la primera cadena la segunda

	cout << endl << "vamos a encadenar las cadenas: ";
	
	encadenar_cadena(cadena,cadena2);

	cout << cadena<<endl;

	pinta();

	//quinta funcion, copiar, copiamos el contenido de la segunda cadena en la primera.

	cout <<endl<<"Valmos a copiar la cadena en la cadena2: ";

	copia_cadena(cadena2,cadena);

	cout << cadena2<<endl;

	int p;
	int l;

	pinta();

	//septima funcion, subcadena, recogemos los dos parametros necesarios y generamos una subcadena 
	//con dichos parametrso.
	//la salida de los datos esta condicionada por la generacion de la subcadena

	cout << endl << "Dame una posicion de la cadena: ";
	cin >> p;
	cout << endl << "Dame una longitud: ";
	cin >> l;

	char *subcadenas = subcadena(cadena,cadena_auxiliar, p, l);

	if(*subcadenas == '\0'){
		cout << endl <<"Imposible crear subcadena;"<<endl;
	}

	else{

		cout << endl <<"La subcadena resultante es: ";

		cout<< endl <<subcadenas<<endl;
	}


	pinta();


	return(0);


}