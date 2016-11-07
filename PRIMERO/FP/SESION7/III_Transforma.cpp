#include <iostream>

using namespace std;

bool EsMinuscula(char letra){
    bool es_minuscula = false;
    
    if((letra >= 'a') && (letra <='z'))
	es_minuscula = true;
    
    return es_minuscula;
}
bool EsMayuscula(char letra){
    bool es_mayuscula = false;
    
    if((letra >= 'A') && (letra <='Z'))
	es_mayuscula = true;
    
    return es_mayuscula;
}
    
    
char Transforma(char letra){
    const int AMPLITUD = 'a'-'A';
    char otra_letra;
    
    if(EsMinuscula(letra))
	otra_letra = letra - AMPLITUD;
    else if(EsMayuscula(letra))
	    otra_letra = letra + AMPLITUD;
	else 
	    otra_letra = letra;
 
    return otra_letra;
}	
    

int main(){
    
    char letra;
    
    cout << "\n\nDamme una letra: ";
    cin >> letra;
    
    cout << "\n\nSu letra es: "<<Transforma(letra)<<"\n\n";
    
    return(0);
}