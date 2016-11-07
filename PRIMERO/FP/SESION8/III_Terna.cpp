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

//declaramos la clase terna con datos publicos y tres funciones 

class Terna_vs1{
public:
    int uno;
    int dos;
    int tres;
    
    double Max(){
	int max;
	
	if (uno > dos)
	    max = uno;
	else
	    max = dos;
	
	if(tres > max)
	    max = tres;
	
	return max;
    }
    
    double Min(){
	
	int min;
	
	if (uno < dos)
	    min = uno;
	else
	    min = dos;
	
	if(tres < min)
	    min = tres;
	
	return min;
    }
    double Media(){
	double media;
	
	media = (uno + dos + tres)/3;
	
	return media;
    }
};

int main(){
    
    
    Terna_vs1 una_terna;	//llamaos a la clase terna
    
    //recogemos los datos 
    
    cout << " \n\nDame tres valores";
    cin >> una_terna.uno >> una_terna.dos >> una_terna.tres;
    
    //salida de datos por pantalla con llamada a los metodos
    
    cout << "\nEl maximo es "<<una_terna.Max();
    cout << "\nEl minimo es "<<una_terna.Min();
    cout << "\nLa media es "<<una_terna.Media();
    
    return (0);
}
    
    


	
	
	