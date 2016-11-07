#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Verbose.h"

using namespace std;

int main(int argc, char **argv){

	if(argc != 2){
		cerr << "Falta el argumento" << endl;
		exit(1);
	}

	char c;
	char letra = argv[1][0];
	int i = 0;

	while(cin >> c){
		if(c == letra){
			i++;
		}
	}

	cout<<endl <<i <<endl;

}