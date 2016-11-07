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
// FICHERO MiCadenaClasica.h
//
/*	

este fichero contiene las cabeceras de las funciones, desarrolladas en MiCadenaClasica.cpp y utilizadas en DemosCadenasClasicas.cpp. 


*/
/*********************************************************************/


#ifndef MICADENACLASICA
#define MICADENACLASICA

//Esta funcíon recibe una cadena de caracteres clasica como parametro y devuelve su longitud.

int longitud_cadena (char *cadena);

//Esta funcion recibe dos cadenas de caracteres y compara sus tamanios.

int comparar_cadenas(char *cadena1, char *cadena2);

//Esta funcion recibe como parametro una cadena clasica de caracteres y nos informa de si es o no un palindromo.

bool palindromo(char *cadena);

//Esta funcion recibe una cadena clasica de caracteres y la invierte.

char * invierte_cadena(char *cadena, char *otra_cadena);

//Esta funcion copia el contenido de una cadena en otra.

void copia_cadena(char *cadena1, char *cadena2);

//Esta funcion aniade el contenido de una cadena al final de otra.

void encadenar_cadena(char *cadena1, char *cadena2);

//Esta funcion recibe como parametro una cadena un punto de la cadena y un a longitud y nos devuelve una 
//subcadena empezando en el punto p y de una longitud

char * subcadena(char *cadena, char *otra_cadena, int p, int l);

//Funcion de regalo, unicamente estetica

void pinta();

#endif