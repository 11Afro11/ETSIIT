

#include <iostream>
#include <cstdlib>
#include "Verbose.h"

using namespace std;

int main(){

	const int TAM = 999;

	char * texto;

	cout << "Introduce un texto: ";
	cin.getline(texto, TAM);

	cout <<texto<<endl;

	return(0);
}