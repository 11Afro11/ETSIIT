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

 Se desea desarrollar una estructura de datos que permita representar de forma general di-
versas figuras poligonales. Cada figura poligonal se puede representar como un conjunto de
puntos en el plano unidos por segmentos de rectas entre cada dos puntos adyacentes. Por
esta razón se propone la representación mostrada en la figura 24.
Así, un polígono se representa como una secuencia circular y ordenada de nodos enlaza-
dos. Por ejemplo, el triángulo de puntos (2,0),(4,0) y (3,l) se representa como se indica en la
figura 24.


*/
/*********************************************************************/



#include <iostream>
#include "Poligono.h"

using namespace std;

int main(){

	int TAM = 10;	//tope
	Punto2D *puntero_dinamico;	//puntero
	puntero_dinamico = new Punto2D [TAM];	//reserva de memoria
	double eje_x;	//dato de entrada
	double eje_y;
	int total_utilizados = 0; 	//contador que cuentalos datos utilizados
	Poligono poligono;

	//solicitud de datos por pantalla

	cout << endl << "Introduzcalos datos: ";
	cin >> eje_x;

	while(eje_x >= 0){

		cin >> eje_y;

		//Si los datos intriducidos entan dentro de la memoria se añanden

		if(total_utilizados < TAM){
			puntero_dinamico[total_utilizados].x = eje_x;
			puntero_dinamico[total_utilizados].y = eje_y;
			total_utilizados ++;
		}
		else{
			//si no se amplia la memoria y se añade
			puntero_dinamico = Redimensiona (puntero_dinamico,TAM);
			puntero_dinamico[total_utilizados].x = eje_x;
			puntero_dinamico[total_utilizados].y = eje_y;
			total_utilizados ++;
		}

		cin >> eje_x;
	}
	poligono = CreaEstructuraGeometrica(puntero_dinamico, total_utilizados);

	MuestraEstructuraGeometrica(poligono);

	cout <<endl<<"su poligono tiene "<<CuentaCaras(poligono) <<" caras";

	char sino;


	do{
		cout <<endl<< "¿Desea liberar espacio en memoria?[S/N]: ";
		cin >> sino;
		sino = toupper(sino);
	}while(sino != 'S' && sino != 'N');

	if(sino == 'S'){
		LiberaEspacio(poligono);
	}

	Poligono geometrica;

	if(CuentaCaras(poligono) == 4){
		geometrica = TrianguloCuadrado(poligono);

	}

	if(CuentaCaras(poligono) == 3){
		geometrica = TrianguloCentral(poligono);
	}

	MuestraEstructuraGeometrica(geometrica);

	Punto2D centro;
	double radio;
	double a;

	cout << endl << "Introduce un parametro: ";
	cin >> a;
	cout << endl<< "Introduce el radio: ";
	cin >> radio;
	cout << endl << "Introduce el centro de la circunferencia: ";
	cin >>centro.x;
	cin >>centro.y;

	Poligono circulo;
	circulo = Circunferencia(centro, radio, a);

	MuestraEstructuraGeometrica(circulo);



}