#include <iostream>
#include <cstdlib>
#include "Verbose.h"

using namespace std;


int main(){

	char texto;
	int i=0;

	cout << "Introduce un texto: ";
	texto = cin.get();

	while(!cin.eof()){
		i++;
		texto = cin.get();
	}

	cout <<i<<endl;

	return(0);
}