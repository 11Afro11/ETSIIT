#include <iostream>

using namespace std;

int CalcularSumandos(int numero){
    
    int suma = 0;
    int descomponer = 0;
    
    for(int i = 1; i < numero; i++){
	for(int j = i; j < numero; j++){
	    suma = suma + j;
	    if(suma == numero)
		descomponer++;
	}
	suma = 0;
    }  
    return descomponer;
}

int main(){
    int numero;
    
    cout << "\n\nDame un numero: ";
    cin >> numero;
    
    cout<<"\n\nEl numero "<<numero<<" puede descomponerse de "<<CalcularSumandos(numero)<<" formas\n\n";
    
    return(0);
}