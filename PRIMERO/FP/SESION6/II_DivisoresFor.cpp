#include <iostream>

using namespace std;

int main(){
     int numero;
     int recorrido = 1;
     int divisor = 0;
     
      do{
	cout<<"\nDame un numero positivo: ";
	cin>>numero;	
    }while(numero <= 0);
    
    for(int recorrido = 1; recorrido < numero; recorrido++){
	if(numero % recorrido == 0)
	    divisor++;
    }
    
    cout<<"\n\nEl numero tiene "<<divisor<<" divisores\n\n";
    
    return (0);
}