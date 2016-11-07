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
// SESION 8
// EJERCICIO 13
//
/*	
  Se pide crear una clase Terna que represente un conjunto de 3 valores de tipo
double, sobre los que se quiere realizar las operaciones de calcular el máximo, el
mínimo y la media aritmética. Para ello, haced lo siguiente:
a) Definid en primer lugar la clase con tres datos miembro públicos llamados uno,
dos y tres. A esta primera versión de la clase, dadle el nombre
Terna_vs1
Añadid un método público Max. Este método tendrá la siguiente cabecera:
double Max()
Observad que el método Max actúa sobre los datos de la clase (uno, dos y
tres) por lo que no tiene parámetros. Observad la diferencia con la cabecera del
ejercicio 2 en el que Max era una función que estaba dentro de ninguna clase.
b) Añadid un método para calcular el mínimo de los tres valores.
c) Añadid ahora un método para calcular la media aritmética de los tres valores.
d) Cread un main que llame a los métodos anteriores.
Comprobad que podemos modificar directamente los datos miembro públicos
desde el main, lo cual no es muy recomendable como ya se ha visto en clase de
teoría. Para resolver este problema, hacemos lo siguiente:


*/
/*********************************************************************/
#include <iostream>

using namespace std;

//clase DepositoSimulacion con datos publicos y dos metodos

class DepositoSimulacion{
    
public:
    double capital;
    double interes;
    int anio;
    
    double CapitalAcumulado(){
    
	interes = (interes/100)*capital;
    
	for(int i = 0; i <= anio; i++){	//bucle for que declara un contador condicionado

    
	//sumamos el interes al capital
    
	capital = capital + interes;
	
	cout<<"\nEl total acumulado en el aÃ±o numero "<<i<<" es: " <<capital<<"\n\n";
	
	}
    
	return capital;	
    
    }
    
    double ReinvierteAsta(){
	
	 interes = (interes/100)*capital;
	 capital_inicial = capital;
	
	 while(capital <= 2 * capital_inicial){	//calculamos el interes acumulado por el capital astaa doblar el capital

	    //sumamos el interes al capital
	
	    capital = capital + interes;
	    
	    anio++;
	 }
	 return anio;
  
  }
};



int main(){
    DepositoSimulacion simulacion;	//declaramos la clase 
    
    cout << "\n\nDame el capital ";//recogemos los datos
    cin >> simulacion.capital;
    cout << "\n\nDame el interes ";
    cin >> simulacion.interes;
    cout << "\n\nDame el numero de años ";
    cin >> simulacion.anio;
    
    simulacion.CapitalAcumulado();//llamamos al metodo de la clase
    
    //salida de datos por pantalla 
    
    cout<<"\nSe necesitan "<<simulacion.ReinvierteAsta()<<" aÃ±os para doblar la inversion.\n\n";
    
    return(0);
}
    
    
    