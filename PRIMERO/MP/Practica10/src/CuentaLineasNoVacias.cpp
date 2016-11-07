

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
	char * texto;
	const int TAM = 100;
	int cont = 0;

	while(strcmp(texto,"FIN")){
		cin.getline(texto, TAM);
		if(texto[0] != '\0'){
			cont ++;
		}
		cin.clear();
	}
	cout <<"Lineas vacias: "<<cont<<endl;
}