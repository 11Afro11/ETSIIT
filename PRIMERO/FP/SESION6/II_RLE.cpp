#include <iostream>

using namespace std;

int main(){
    int numero;
    int primer_numero;
    int cuenta_numero = 1;
    
    cout << "\n\nIntroduce una secuencia ordenada de numeros: ";
    cin >> primer_numero >> numero;
    
    cout << "\n\n";
    
    while((numero != -1) && (primer_numero != -1)){
	if(numero == primer_numero)
	    cuenta_numero++;
	else{
	    cout<<cuenta_numero<<" "<<primer_numero<<" ";
	    cuenta_numero = 1;
	}
	primer_numero = numero;
	cin>>numero;
    }
    
    cout <<cuenta_numero<<" "<<primer_numero<<"\n\n";
    return(0);
}
    
    