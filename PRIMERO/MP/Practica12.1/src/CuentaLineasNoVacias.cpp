

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Verbose.h"

using namespace std;

int main(){
	
	const int TAM = 100;
	char * texto = new char[TAM];
	int cont = 0;
	texto[cont] = '\0';

	while(!cin.eof()){
		cin.getline(texto, TAM);
		if(texto[0] != '\n'){
			cont ++;
		}
		cin.clear();
	}
	cout <<"Lineas No vacias: "<<cont<<endl;
}