#include <iostream>

using namespace std;

int CalculaSuma(int numero){
    
    int sumatoria = 0;
    
    for(int i = 1; i < numero; i++){
	if(numero % i == 0)
	    sumatoria = sumatoria + i;
    }
    return sumatoria;
}

int PerfectoMenorQue(int tope){
    tope--;
    for(int j = tope; j > 0; j--){
	if(CalculaSuma(j) == tope)
	    return j;
	else
	    tope--;
    }
}
	    


int main(){
    
    int numero;
    
    cout << "\n\nDame un numero: ";
    cin >> numero;

    cout << "\n\nEl numero perfecto menor que "<<numero<<" es: "<<PerfectoMenorQue(numero)<<"\n\n";
    
    return (0);
    
}    
    
    
    
    
    
    
    