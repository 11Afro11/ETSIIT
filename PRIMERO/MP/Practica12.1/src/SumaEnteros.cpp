#include <iostream>
#include <fstream>
#include "Verbose.h"

using namespace std;

int main(){

	int c;
	int sum = 0;

	while(cin >> c){
		sum += c;
	}

	cout<<endl <<sum <<endl;

}