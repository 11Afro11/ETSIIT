#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "Verbose.h"

using namespace std;

int main(int argc, char **argv){

	if(argc != 2){
		cerr << "Falta el argumento" << endl;
		exit(1);
	}

	char c[100];
	int  n = atoi(argv[1]);
	int j = 0;	

	while(cin >> c){

		if(strlen(c) == n){
			j++;
		}
		
	}

	cout<<endl <<j <<endl;

}