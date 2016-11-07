#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int tope;
    int erre;
    int coeficiente;
    int resultado;
    int sumatoria = 0;
    
    cout<<"\n\nDame un numerro tope de repeticiones: ";
    cin>>tope;
    cout<<"\n\nDame el valor R: ";
    cin>>erre;
    cout<<"\n\nDame el valor del coeficiente a: ";
    cin>>coeficiente;
    
    /*
    
    for(int i = 1; i <= tope; i++){
	
	resultado = coeficiente * (pow((erre*1.0),(i-1)));
	
	sumatoria = sumatoria + resultado;
    }
    
    */
    
    for(int i = 1; i<=tope; i++){
	resultado = coeficiente * erre;
	coeficiente++;
	sumatoria = sumatoria + resultado;
    }
    
    cout<<"\n\nLa sumatoria es: "<<sumatoria<<"\n\n";
    
    return(0);
}

