#include <iostream>
#include "Redimensiona.h"


int * Redimensiona (int *puntero, TipoRedimension opcion, int & TAM){

	int TAM_BLOQUE = 5;

	int *aux = puntero;
	if(opcion == 0){
		TAM = TAM + 1;
		puntero = new int [TAM];
	}
	if(opcion == 1){
		TAM = TAM + TAM_BLOQUE;
		puntero = new int [TAM];
	}
	if(opcion == 2){
		TAM = 2 * TAM;
		puntero = new int [TAM];
	}

	for(int i = 0; i < TAM; i++){
		puntero[i] = aux[i];
	}
	delete[] aux;

	return puntero;
}