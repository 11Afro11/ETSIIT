#include <iostream>
#include "Redimensiona.h"

using namespace std;

int main(){
	int TAM = 10;
	int *puntero_dinamico;
	puntero_dinamico = new int [TAM];
	int dato;
	int contador = 0;
	TipoRedimension opcion = DeUnoEnUno;

	cout << endl << "Introduzcalos datos: ";
	cin >> dato;

	while(dato >= 0){

		if(contador < TAM){
			puntero_dinamico[contador] = dato;
			contador ++;
		}
		else{
			puntero_dinamico = Redimensiona (puntero_dinamico, opcion ,TAM);
			puntero_dinamico[contador] = dato;
			contador ++;
		}

		cin >> dato;
	}

	cout << endl <<"Su vector es: "<<endl;
	for(int i = 0; i < contador; i++){
		cout << puntero_dinamico[i];
	}
	cout <<endl;

	char sino;

	do{
		cout << "Dispone usted de "<<TAM-contador<<" posiciones de memoria";
		cout <<endl<< "¿Desea ampliar la mamoria reservada?[S/N]: ";
		cin >> sino;
		sino = toupper(sino);
	}while(sino != 'S' && sino != 'N');

	while(sino == 'S'){

		char eleccion;

		do{
			cout << endl << " Como desea ampliar la memoria: "<<endl<<"a) De Uno En Uno"<<endl<<"b) En Bloques"<<endl<<"c) Duplicar"<<endl;
			cin >> eleccion;
			eleccion = toupper(eleccion);
		}while(eleccion != 'A' && eleccion != 'B' && eleccion != 'C');

		if(eleccion == 'A'){
			cout << "Introduzca un nuevo dato :";
			opcion = DeUnoEnUno;
			puntero_dinamico = Redimensiona (puntero_dinamico, opcion ,TAM);
			cin >> dato;
			puntero_dinamico[contador] = dato;
			contador++;
		}
		if(eleccion == 'B'){
			cout << "Introduzca 5 datos :";
			opcion = EnBloques;
			puntero_dinamico = Redimensiona (puntero_dinamico, opcion ,TAM);
			cin >> dato;
			while(dato >= 0 && contador < TAM){

				if(contador < TAM){
					puntero_dinamico[contador] = dato;
					contador ++;
					cin >> dato;
				}
				else{
					cout << endl<< "Ha llenado la memoria existente"<<endl;
					dato = -1;
				}
			}
		}
		if(eleccion == 'C'){
			cout << "Dispone usted del doble de memoria, introduzca los datos que desee:";
			opcion = Duplicando;
			puntero_dinamico = Redimensiona (puntero_dinamico, opcion ,TAM);
			cin >> dato;
			while(dato >= 0 && contador < TAM){

				if(contador < TAM){
					puntero_dinamico[contador] = dato;
					contador ++;
					cin >> dato;
				}
				else{
					cout << endl<< "Ha llenado la memoria existente"<<endl;
					dato = -1;
				}
			}
		}

		cout << endl <<"Su vector es: "<<endl;
		for(int i = 0; i < contador; i++){
			cout << puntero_dinamico[i];
		}
		cout <<endl;
		do{
			cout << "Dispone usted de "<<TAM-contador<<" posiciones de memoria";
			cout <<endl<< "¿Desea ampliar la mamoria reservada?[S/N]: ";
			cin >> sino;
			sino = toupper(sino);
		}while(sino != 'S' && sino != 'N');

	}

	cout << endl << "Memoria Actualizada."<< endl << "El vector resultante es: "<<endl<<endl;


	for(int i = 0; i < contador; i++){
		cout << puntero_dinamico[i];
	}
	cout <<endl;


	return(0);

}