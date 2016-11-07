#include <iostream>

using namespace std;

bool EsMinuscula(char letra){
    bool es_minuscula = false;
    
    if((letra >= 'a') && (letra <='z'))
	es_minuscula = true;
    
    return es_minuscula;
}
char Convierte_a_Mayuscula(char letra){
    
      const char DISTANCIA_MAY_MIN = 'a'-'A';
      char otra_letra;
    
    if(EsMinuscula(letra)){
	otra_letra = letra - DISTANCIA_MAY_MIN;
    }
    else{
	otra_letra = letra;
    }
	
    return otra_letra;
}

int main(){
    
    char letra;
    
    cout << "\n\nDamme una letra: ";
    cin >> letra;
    
    cout << "\n\nSu letra es: "<<Convierte_a_Mayuscula(letra)<<"\n\n";
    
    return(0);
}
	
	