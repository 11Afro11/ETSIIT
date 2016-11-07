#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Verbose.h"

using namespace std;

int main(){
	
	const int TAM = 100;
	char * texto = new char[TAM];
	texto[0] = '\0';

	cout <<"Lineas No vacias: "<<endl;

	while(!cin.eof()){
		cin.getline(texto, TAM);
		if(texto[0] != '#' && strcmp(texto,"FIN")){
			cout << texto <<endl;
		}
		cin.clear();
	}
}