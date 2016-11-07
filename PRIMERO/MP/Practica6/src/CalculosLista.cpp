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

 Ampliar el problema 6 de manera que una vez leídos los datos realice unos cálculos sobre los
datos almacenados en la lista. Se pide que se escriban tres funciones para calcular:
a) el número de celdas enlazadas.
b) la media de los datos almacenados.
c) la varianza de los datos almacenados.

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
	cout << endl <<"Su lista tiene "<<NumCeldas(puntero)<< " celdas" <<endl;
	pinta();

	cout << endl <<"La media de los valores es: "<<Media(puntero)<<endl;
	pinta();

	cout << endl <<"La varianza de los valores es: "<<Varianza(puntero)<<endl;
	pinta();
}