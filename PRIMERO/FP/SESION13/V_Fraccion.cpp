/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIERIA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 6
//
//
En el ejercicio 20 de la relación de problemas III se creó una clase para representar
una fracción. Este ejemplo se ha usado reiteradamente en los apuntes de teoría. En
este ejercicio se pide rediseñar la clase Fraccion:
 Definid tres constructores para la clase:
– Constructor sin argumentos. Pensad y establecer adecuadamente los valores
por defecto que se consideren adecuados.
– Constructor con un argumento.
– Constructor con dos argumentos.
 Añadir métodos para sumar, restar, multiplicar y dividir dos fracciones. La declaración
será de la forma:
class Fraccion{
......
Fraccion Suma(Fraccion otra_fraccion)
......
};
de manera que el objeto implícito (sobre el que se aplica el método) y el objeto
explícito (otra_fraccion) no se modifican. Además, la fracción resultante de
la operación será una fracción irreducible.
/******************************************************************
*/
#include <iostream>

using namespace std;
//calse fraccion
class Fraccion{
private:
	//datos y metodos del ambito privado
	int numerador;
	int denominador;
	
	//calculo del mcm
	
	int MCD(){
		bool mcd_encontrado = false;
		int divisor, mcd;
		if (numerador == 0 || denominador == 0)
			mcd = 0;
		else{
			if (numerador > denominador)
				divisor = denominador;
			else
				divisor = numerador;
				mcd_encontrado = false;
				while (!mcd_encontrado){
					if (numerador % divisor == 0 && denominador % divisor == 0)
						mcd_encontrado = true;
					else
						divisor--;
				}
			mcd = divisor;
		}
		return mcd;
	}
public:
	
	/*Fraccion(){
		numerador = 1;
		denominador = 1;
	}*/
	
	/*Fraccion(int num){
		numerador = num;
		denominador = 1;
	}*/
	
	Fraccion(int num,int den){
		numerador = num;
		denominador = den;
	}
	
	//signacion del numerador
	
	void SetNumerador (int el_numerador){
		numerador = el_numerador;
	}
	//asignacion del denomiador
	void SetDenominador (int el_denominador){
		denominador = el_denominador;
	}
	//devuelve el numerador
	int Numerador(){
		return numerador;
	}
	//devuelve el denominador
	int Denominador(){
		return denominador;
	}
	//metodo que calcula la division
	double Division(){
		return 1.0 * numerador / denominador;
	}
	//metodo que normaliza la expresion
	void Normaliza(){
		int mcd;
		mcd = MCD();
		numerador = numerador/mcd;
		denominador = denominador/mcd;
	}
	
	//metodo que suma la fraccion
	
	Fraccion Suma(Fraccion otra_fraccion){
		int suma_numerador;
		int suma_denominador;
		
		suma_numerador = numerador * otra_fraccion.Denominador() +
			denominador * otra_fraccion.Numerador() ;
			
		suma_denominador = denominador * otra_fraccion.Denominador();
		
		Fraccion suma(suma_numerador, suma_denominador);
			
		suma.Normaliza();
		
		return suma;
	}
	//metodo que resta la fraccion
	Fraccion Resta(Fraccion otra_fraccion){
		int resta_numerador;
		int resta_denominador;
		
		resta_numerador = numerador * otra_fraccion.Denominador() -
			denominador * otra_fraccion.Numerador() ;
			
		resta_denominador = denominador * otra_fraccion.Denominador();
			
		Fraccion resta(resta_numerador, resta_denominador);
			
		resta.Normaliza();
		
		return resta;
	}
	//metodo que resta la fraccion
	
	Fraccion Multiplicacion(Fraccion otra_fraccion){
		int multiplicaccion_numerador;
		int multiplicaccion_denominador;
		
		multiplicaccion_numerador = numerador * otra_fraccion.Numerador();
		multiplicaccion_denominador = denominador * otra_fraccion.Denominador();
		
		Fraccion multiplica(multiplicaccion_numerador, multiplicaccion_denominador);
			
		multiplica.Normaliza();
		
		return multiplica;
	}
	
	//metodo que divide la fraccion
	
	Fraccion Division(Fraccion otra_fraccion){
		int division_numerador;
		int division_denominador;
		
		division_numerador = numerador * otra_fraccion.Denominador();
		division_denominador = denominador * otra_fraccion.Numerador();
		
		Fraccion divide(division_numerador, division_denominador);
			
		divide.Normaliza();
		
		return divide;
	}
	
	
};


int main(){
	
	//declaracion de variables y objetos
	int una_fraccion_numerador, una_fraccion_denominador,
	otra_fraccion_numerador, otra_fraccion_denominador;
	//recogemos los datos 
	cout << "\nIntroduzca numerador y denominador de las dos fracciones ";
	
	cin >> una_fraccion_numerador;
	cin >> una_fraccion_denominador;
	cin >> otra_fraccion_numerador;
	cin >> otra_fraccion_denominador;
	
	//asignamos los datos a la clase
	
	Fraccion una_fraccion (una_fraccion_numerador,
		una_fraccion_denominador);
		
	Fraccion otra_fraccion(otra_fraccion_numerador,
		otra_fraccion_denominador);
	//calculamos la suma
	Fraccion suma_fracciones (una_fraccion.Suma(otra_fraccion));
	suma_fracciones.Normaliza();
	//mostramos la suma
	cout << "\nResultado de la suma: "
	<< suma_fracciones.Numerador() << " / "
	<< suma_fracciones.Denominador();
	
	cout <<"\n\n";
	//calculamos la resta
	Fraccion resta_fracciones (una_fraccion.Resta(otra_fraccion));
	resta_fracciones.Normaliza();
	//mostramos la resta
	cout << "\nResultado de la suma: "
	<< resta_fracciones.Numerador() << " / "
	<< resta_fracciones.Denominador();
	
	cout <<"\n\n";
	//calculamos la multiplicacion
	Fraccion multiplica_fracciones (una_fraccion.Multiplicacion(otra_fraccion));
	multiplica_fracciones.Normaliza();
	//mostramos la multiplicacion
	cout << "\nResultado de la suma: "
	<< multiplica_fracciones.Numerador() << " / "
	<< multiplica_fracciones.Denominador();
	
	cout <<"\n\n";
	//calculamos la division
	Fraccion divide_fracciones (una_fraccion.Division(otra_fraccion));
	divide_fracciones.Normaliza();
	//mostramos la division
	cout << "\nResultado de la suma: "
	<< divide_fracciones.Numerador() << " / "
	<< divide_fracciones.Denominador();
	
	cout <<"\n\n";
	
	return(0);
	
	system ("pause");
	
}
		
		
		
		
		
