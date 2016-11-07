#include <iostream>
#include <cmath>

using namespace std;
/*
double SumaHasta(int a, int erre, int tope){
    double ecuacion;
    double sumatoria = 0;
    for(int i = 1; i <= tope; i++){
	ecuacion = a * (pow(erre, (i-1)));
	sumatoria = sumatoria + ecuacion;
    }
    return sumatoria;
}

*/

double SumaHasta(int a, int erre, int tope){
    double ecuacion;
    
    ecuacion = (a * ((pow(erre, tope))-1))/(erre - 1);
    
    return ecuacion;
}


int main(){
    int a, erre, tope;
    
    cout << "\n\nDame el coeficiente a: ";
    cin >> a;
    cout << "\n\nDame el coeficiente r: ";
    cin >> erre;
    cout << "\n\nDame un numero tope de repeticiones: ";
    cin >> tope;
    
    cout << "\n\nLa sumatoria vale: "<<SumaHasta(a, erre, tope)<<"\n\n";
    
    return (0);
}