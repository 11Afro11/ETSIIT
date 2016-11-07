#include <iostream>

using namespace std;

int main(){
    
    int numero;
    double elevar;
    int factorial = 1;
    int producto = 1;
    
    cout<<"\n\nDame un numero (x): ";
    cin>>elevar;
    cout<<"\n\nDame un numero (n): ";
    cin>>numero;
    
    producto = elevar;
    
    if (numero == 0){
	factorial = 1;
	producto = 1;
    }
    else {
	for(int multiplicar = 1; multiplicar < numero; multiplicar++)
	    producto = producto * elevar;
	
	for(int mult = 1; mult <= numero; mult ++)
	    factorial = factorial * mult;
    }
    
    cout<<"\n\nLa pontencia de X elevado a n es: "<<producto<<".\n\n";
    cout<<"\n\nEl factorial de n es: "<<factorial<<".\n\n";

    return(0);
}
