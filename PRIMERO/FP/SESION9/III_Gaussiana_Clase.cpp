/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGAN
//
// SESION 9
// EJERCICIO 25
//
/*	

 Recuperad los ejercicios 13 y 22 de esta relación de problemas sobre la función
gaussiana. En vez de trabajar con funciones, plantead la solución con una clase.


*/
/*********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265;

//clase que calcula la gausiana con el area

class Gaussiana{
private:
    
    //declaramaos las variables en el campo privado
    int equis, sigma, mu;
    double b0;
    double b1;
    double b2;
    double b3;
    double b4;
    double b5;
    
    
public:
    
    //declaramos el constructor
    
    Gaussiana(){
	equis = 1;
	sigma = 1;
	mu = 1;
	b0 = 0.2316419;
	b1 = 0.319381530;
	b2 = -0.356563782;
	b3 = 1.781477937;
	b4 = -1.821255978;
	b5 = 1.330274429;
    }
    
    //metodo que devuelve la variable equis
    
    int GetEquis(){
	return equis;
    }
    
    //metodo  que devuelve la variable sigma
    
    int GetSigma(){
	return sigma;
    }
    
    //metodo que devuelve la variable mu
    
    int GetMu(){
	return mu;
    }
    
    //metodo que asigna valores a equis 
    
    void SetEquis(int coeficiente_1){
	equis = coeficiente_1;
    }
    
    //metodo que asignaa valores a sigma
    
    void SetSigma(int coeficiente_2){
	sigma = coeficiente_2;
    }
    
    //metodo que asigna valores a mu
    
    void SetMu(int coeficiente_3){
	mu = coeficiente_3;
    }
    
    //metodo que calcula la gaussiana
    
    double Gauss(){
	double exponencial;
	double gaussiana;
	
	exponencial = exp(-0.5 * (pow(((equis - mu)/sigma),2)));
	gaussiana = (exponencial/(sigma * (sqrt(2 * PI))));
	
	return gaussiana;
	
    }
    
    //metodo que calcula el area de la gaussiana
    
    double Area(double gauss, int x){
	double area;
	double t;
	t = 1/(1+x*b0);
	area = 1 - gauss*((t*b1)+(t*b2)+(t*b3)+(t*b4))+(t*b5);
	
	return area;
    }


    
};


int main(){
    
    //llamada a la clase Gaussiana 
    
    Gaussiana una_gaussiana;
    
    //declaramos las variables
    
    int coeficiente_1, coeficiente_2, coeficiente_3;
    double gausiana;
    
    //solicitamos los datos por pantalla
    
    cout<< "\n\nDame la variable sigma: ";
    cin>>coeficiente_2;
    
    cout << "\n\nDame la variable mu: ";
    cin >> coeficiente_3;
    
    cout << "\n\nDame la variable x: ";
    cin >> coeficiente_1;
    
    //asignamos los valores con los metodos de la clase    
    
    una_gaussiana.SetSigma(coeficiente_2);
    una_gaussiana.SetMu(coeficiente_3);
    una_gaussiana.SetEquis(coeficiente_1);
    
    //llamamos a los metodos que calculan el area y la gaussiana con los valores asignados
    
    gausiana = una_gaussiana.Gauss();
    
    cout << "\n\nEl valor de la gaussiana es: "<<una_gaussiana.Gauss()<<"\n\n";
    cout << "\n\nEl valor del area es: "<<una_gaussiana.Area(gausiana, coeficiente_1)<<"\n\n";
    
    return (0);
    
}