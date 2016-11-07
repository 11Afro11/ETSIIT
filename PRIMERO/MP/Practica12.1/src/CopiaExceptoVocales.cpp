#include <iostream>
#include <cstdlib>
#include "Verbose.h"

using namespace std;


int main(){

	char texto;

	cout << "Introduce un texto: ";
	texto = cin.get();
	while(!cin.eof()){
		 switch(tolower(texto)){ 
	      case 'a': 
	      case 'e': 
	      case 'i': 
	      case 'o': 
	      case 'u': 
	        /* se ignoran */ 
	        break; 
	      default: 
	        cout << texto; 
	        break;
	    }
	    texto = cin.get();

	}

	return(0);
}