#include <iostream>

using namespace std;

int MultRusa(int multiplicando, int multiplicador){
    
    int mult_rusa = 0;
    
    while(multiplicando >= 1){
	
	//si el numero es impar, aplicando el algoritmo de la multiplicacion
	//debemos realizar la suma acumulada de multiplicador
	
	if(multiplicando % 2 != 0)
	    mult_rusa = mult_rusa + multiplicador;
	
	//dividimos el multiplicando por 2 y multiplicamos el multiplicador por 2,
	//tal y como dice el algoritmo de la multiplicacion rusa, usandolo como 
	//condicion del bucle.
	
	multiplicando = multiplicando / 2;
	multiplicador = multiplicador * 2;
	
    }
    
    return mult_rusa;
}

int main(){
    int multiplicando, multiplicador;
    
    cout<<"\n\nDame el multiplicando: ";
    cin>>multiplicando;
    cout<<"\n\nDame el multiplicador: ";
    cin>>multiplicador;
    
    cout<<"\n\nEl producto es: "<<MultRusa(multiplicando, multiplicador)<<"\n\n";
    
    return(0);
}