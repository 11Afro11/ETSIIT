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
// SESION 5
// FICHERO Redimensiona.cpp
//
/*	

Fichero que contiene la función main que se encargara de probar las funciones desarrolladas en los ficheros 

.cpp


*/
/*********************************************************************/

#include <iostream>
//Referencia al fichero Redimensiona.h
#include "RedimensionarVectorDinamico.h"

using namespace std;

int main(){

	//declaramos las variables

	int TAM = 10;	//tope
	int *puntero_dinamico;	//puntero
	puntero_dinamico = new int [TAM];	//reserva de memoria
	int dato;	//dato de entrada
	int total_utilizados = 0; 	//contador que cuentalos datos utilizados
	TipoRedimension opcion = DeUnoEnUno;	//dato enumerate

	//solicitud de datos por pantalla

	cout << endl << "Introduzcalos datos: ";
	cin >> dato;

	while(dato >= 0){

		//Si los datos intriducidos entan dentro de la memoria se añanden

		if(total_utilizados < TAM){
			puntero_dinamico[total_utilizados] = dato;
			total_utilizados ++;
		}
		else{
			//si no se amplia la memoria y se añade
			puntero_dinamico = Redimensiona (puntero_dinamico, opcion ,TAM);
			puntero_dinamico[total_utilizados] = dato;
			total_utilizados ++;
		}

		cin >> dato;
	}

	//mostramos el vector

	cout << endl <<"Su vector es: "<<endl;
	for(int i = 0; i < total_utilizados; i++){
		cout <<puntero_dinamico[i]<<" ";
	}
	cout <<endl;

	char sino;

	//preguntamos si desea expandir la memoria, con filtro de entrada

	do{
		cout << "Dispone usted de "<<TAM-total_utilizados<<" posiciones de memoria";
		cout <<endl<< "¿Desea ampliar la memoria reservada?[S/N]: ";
		cin >> sino;
		sino = toupper(sino);
	}while(sino != 'S' && sino != 'N');

	char eleccion;

	//bucle de operaciones

	while(sino == 'S'){

		//filtro de entrada de datos

		do{
			cout << endl << " Como desea ampliar la memoria: "<<endl<<"a) De Uno En Uno"<<endl<<"b) En Bloques"<<endl<<"c) Duplicar"<<endl;
			cin >> eleccion;
			eleccion = toupper(eleccion);
		}while(eleccion != 'A' && eleccion != 'B' && eleccion != 'C');

		//opciones seleccionables

		if(eleccion == 'A'){
			cout << "Introduzca un nuevo dato :";
			opcion = DeUnoEnUno;
		}
		if(eleccion == 'B'){
			cout << "Dispone usted de un bloque mas de memoria :";
			opcion = EnBloques;
			
		}
		if(eleccion == 'C'){
			cout << "Dispone usted del doble de memoria, introduzca los datos que desee:";
			opcion = Duplicando;
			
		}

		puntero_dinamico = Redimensiona(puntero_dinamico, opcion, TAM);

		//Volvemos a recoger los datos

		cin >> dato;
		while(dato >= 0 && total_utilizados < TAM){

			puntero_dinamico[total_utilizados] = dato;
			total_utilizados ++;
			cin >> dato;
			
		}

		//Volvemos a mostrar el vector

		cout << endl <<"Su vector es: "<<endl;
		for(int i = 0; i < total_utilizados; i++){
			cout <<puntero_dinamico[i]<<" ";
		}
		cout <<endl;

		//Filtro que vuelve a preguntar las iteracciones
		do{
			cout << "Dispone usted de "<<TAM-total_utilizados<<" posiciones de memoria";
			cout <<endl<< "¿Desea ampliar la memoria reservada?[S/N]: ";
			cin >> sino;
			sino = toupper(sino);
		}while(sino != 'S' && sino != 'N');

	}

	//mostramos la memoria

	cout << endl << "Memoria Actualizada."<< endl << "El vector resultante es: "<<endl<<endl;


	for(int i = 0; i < total_utilizados; i++){
		cout << puntero_dinamico[i] <<" ";
	}
	cout <<endl;


	return(0);

}