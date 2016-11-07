#include <iostream>

using namespace std;

int Potencia(int numero){
    
    int producto = -1;
    
    for(int i = 1; i <= numero; i++)
	producto = producto * -1;
    
    return producto;
}

long long Sumatoria(int tope){
    double sumatoria = 0;
    double ecuacion;
    
    for(int k = 1; k <= tope; k++){
	
	ecuacion = (Potencia(k) * ((k*k)-1))/ (2*k);
	
	sumatoria = sumatoria + ecuacion;
    }
    
    return sumatoria;
}

int main(){
    
    int tope;
    
    cout << "\n\nDame un numero tope de repeticiones: ";
    cin >> tope;
    
    cout << "\n\nLa sumatoria vale: "<<Sumatoria(tope)<<"\n\n";
    
    return (0);
}
