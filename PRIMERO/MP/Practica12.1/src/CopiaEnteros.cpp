

#include <iostream>
#include "Verbose.h"

using namespace std;

int main(){

	int c;
		
	cout << "Introduce los caracteres(CTRL*D para parar): ";

	while(cin>>c){
		cout << c<<endl;
	}
	cout << endl;

	return 0;
}