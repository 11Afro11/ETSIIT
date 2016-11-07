#include <iostream>
#include <cstdlib>
#include "Verbose.h"

using namespace std;

int main(){

	char *c = new char;

	cout << "Introduce los caracteres(CTRL*D para parar): ";

	while(cin >> c){
		if(*c != '*'){
			cout << atoi(c)<<endl;
		}
	}
	cout << endl;

	delete []c;

	return 0;
}