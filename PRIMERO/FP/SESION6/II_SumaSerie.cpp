#include <iostream>

using namespace std;

int main(){
    const int TOPE = 100;
    const int PARENTESIS = (-1);
    int potencia = 1;
    double ecuacion;
    double sumatoria = 0;
    
    for(int i = 1; i <= TOPE; i++){
	for(int multiplicar = 1; multiplicar <= i; multiplicar++)
	    potencia = potencia * PARENTESIS;
	
	ecuacion = (potencia * ((i*i)-1))/2*i;
	sumatoria = sumatoria + ecuacion;
    }
    
    cout<<"\n\nLa suma de los 100 primeros terminos es: "<<sumatoria<<"\n\n";
    
    return(0);
    
}
	