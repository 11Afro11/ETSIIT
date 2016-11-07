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
// SESION 6
//
/*	

 Considere una secuencia ordenada de datos almacenada en una lista.
a) Implemente una función para insertar un nuevo dato en su posición correcta.
b) Implemente una función para, dado un dato, eliminar la celda que lo contiene.


*/
/*********************************************************************/
#include <iostream>
#include "lista.h"

using namespace std;


int main(){

	pinta();
	cout <<endl<<endl;

	TipoLista *puntero;
	TipoLista *puntero2;
	puntero = CreaEstructuraLineal();

	if(EstaOrdenada(puntero) == true){
		cout << endl << "La lista esta ordenada"<<endl;
	}
	else{
		cout <<endl << "La lista NO esta ordenada"<<endl;
		cout << endl << "Vamos a ordenar la lista: "<<endl;
		Ordena_por_Seleccion(puntero);
	}

	MuestraEstructuraLineal(puntero);

	pinta();

	char sino;


	do{
		cout <<endl<< "¿Desea hacer algún cambio en la lista?[S/N]: ";
		cin >> sino;
		sino = toupper(sino);
	}while(sino != 'S' && sino != 'N');

	char eleccion;

	//bucle de operaciones

	while(sino == 'S'){

		//filtro de entrada de datos

		do{
			cout << endl << " ¿Que desea hacer?: "<<endl<<"a) Aniadir un elemento"<<endl<<"b) eliminar un elemento"<<endl;
			cin >> eleccion;
			eleccion = toupper(eleccion);
		}while(eleccion != 'A' && eleccion != 'B');


		if(eleccion == 'A'){
			double valor;
			cout << "Introduzca un dato :";
			cin >> valor;
			InsertarElemento(puntero, valor);
		}
		if(eleccion == 'B'){
			double valor;
			cout << "Introduzca un dato :";
			cin >> valor;
			EliminarElemento(puntero, valor);
			
		}
		MuestraEstructuraLineal(puntero);

		do{
			cout <<endl<< "¿Desea hacer algún cambio en la lista?[S/N]: ";
			cin >> sino;
			sino = toupper(sino);
		}while(sino != 'S' && sino != 'N');
	}
}