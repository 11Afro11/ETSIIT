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

Este fichero contiene el desarrollo de las cabeceras del fichero .h 


*/
/*********************************************************************/

//referencia a MiCadenaClasica.h
#include <MiCadenaClasica.h>
#include <iostream>


/*************************************************************************************************/
//Funcion longitud:
//utiliza dos punteros, un siempre apunta al principio, el otro recorre la cadena asta encontrar el elemento '\0'
//una vez encontrado se resta el valor de los punteros para obtener la longitud.
/*************************************************************************************************/

int longitud_cadena(char *cadena){

	char *comienzo =cadena;
	char *final = comienzo;

	while(*final != '\0'){
		final++;
	}

	return (final-comienzo);

}

/*************************************************************************************************/
//Funcion Compara:
//Compara los tamanios de dos cadenas, haciendo uso de la función longitud, y muestra tres tipos de salidas diferentes
//1-> si la primera es mayosque la segunda,
//-1.> en el caso contrario.
//0->Si son iguales
/*************************************************************************************************/

int comparar_cadenas(char *cadena1, char *cadena2){

	int primer_tamanio = longitud_cadena(cadena1);
	int segundo_tamanio = longitud_cadena(cadena2);

	int dato_a_devolver;

	if(primer_tamanio > segundo_tamanio)
		dato_a_devolver = 1;
	else if(primer_tamanio < segundo_tamanio)
		dato_a_devolver = -1;
	else 
		dato_a_devolver = 0;


	return dato_a_devolver;

}

/*************************************************************************************************/
//Funcion palindromo:
//utiliza dos punteros; uno apunta al principio de la cadena y otro al final de esta,
//la funcion compara el contenido al que apuntan los dos punteros y, mientras que el primero sea mayor
//que el segundo, avanzara el primer puntero una posicion a la derecha y el segundo hacia la izquierda.
//Todo esto detro de un buche while que tendra en cuenta si en algun monento la palabra no es un palindromo 
//como condicion de parada
/*************************************************************************************************/

bool palindromo(char *cadena){

	bool es_palindromo = true;

	char *primero = cadena;
	char *segundo = primero + longitud_cadena(cadena)-1;


	while((primero < segundo) && es_palindromo){

		if(*primero != *segundo){
			es_palindromo = false;
		}

		primero++;
		segundo--;
	}

	return es_palindromo;
}

/*************************************************************************************************/
//Funcion invierte:
//esta funcion crea una cadena resultado de invertir una cadena pasada por parametro;
//la funcion utiliza dos punteros,una apunta a la ultima posicion de la cadena y el otro apunta 
//a otra cadena pasada por parametro, y aniade los elemento de forma inversa
//por ultimo devuelve la posicion en la que empieza la cadena invertida
/*************************************************************************************************/

char * invierte_cadena(char *cadena, char *otra_cadena){

	int longitud = longitud_cadena(cadena);

	char *invierte = otra_cadena;

	char *puntero;

	puntero = cadena + longitud-1;

	for(int i = 0; i < longitud; i++){

		*(invierte + i) = *(puntero - i);
	}
	*(invierte + longitud) = '\0';
	
	return invierte;

}

/*************************************************************************************************/
//Funcion copia:
//esta funcion copia el contenido de una cadena dentro de otra,
//para ello usamos dos puntero que apunten al principio de cada una de las cadenas y que introducen el valor de
//la primera cadea en la segunda
/*************************************************************************************************/

void copia_cadena(char *cadena1, char *cadena2){


	char *puntero = cadena2;
	char *puntero2 = cadena1;

	for(int i= 0; i <= longitud_cadena(cadena2); i++){
		*(puntero2 + i) = *(puntero +i);
	}


}

/*************************************************************************************************/
//Funcion Encadenar:
//esta funcion aniade el contenido de una cadena al final de otra
//para ello tiene un puntero apuntando a la primera posicion de la cadena que aniadiremos
//y otro apuntando a la ultima posicion de la cadena a al que se aniade.
/*************************************************************************************************/

void encadenar_cadena(char *cadena1, char *cadena2){

	char *puntero1 = cadena1;
	int longitud1 = longitud_cadena(cadena1);
	puntero1 = puntero1 + longitud1;
	char *puntero2 = cadena2;
	int longitud2 = longitud_cadena(cadena2);

	for(int i = 0; i <= longitud2; i++){

		*(puntero1 +i) = *(puntero2 + i);
	}


}

/*************************************************************************************************/
//Funcion subcadena:
//Eesta funcion crea una subcadena. Le pasamos por parametros dos cadena una posicion y una longitud.
//La funcion creara un puntero a la cadena auxiliar e incluira los elementos
//de la cadena empezando por la posicion p asta la poscicion p-l
/*************************************************************************************************/

char * subcadena(char *cadena, char *otra_cadena, int p, int l){

	char *subcadena = otra_cadena;
	char *puntero = cadena + p;

	int longitud = longitud_cadena(cadena);

	int i = 0;

	if(p < longitud){
		while((i < l) && (*puntero != '\0')){
			*(subcadena +i) = *puntero;
			i++;
			puntero++;
		}
		*(subcadena + i) = '\0';
	}
	else{
		*subcadena = '\0';
	}

	return subcadena;
}


/*************************************************************************************************/
//Funcion pinta:
//funcion estetica, separa las salidas en la consola.
/*************************************************************************************************/

void pinta(){

	std::cout <<std::endl<<"#################################################################################"<<std::endl;
	std::cout <<"#################################################################################"<<std::endl;
}
