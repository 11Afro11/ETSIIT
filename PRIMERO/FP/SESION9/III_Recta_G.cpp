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
// EJERCICIO 14
//
/*	
g) Métodos privados
Añada un método privado que nos indique si los coeficientes son correctos, es
decir, A y B no pueden ser simultáneamente nulos. Llame a este método en el
constructor y en el método SetCoeficientes y realice las operaciones que estime
oportuno en el caso



*/
/*********************************************************************/
#include <iostream>

using namespace std;

//Declaramos la clase Recta

class Recta{
    
private:
    
    //declaramos las variables del ambito privado
    
    double parametro_1;
    double parametro_2;
    double parametro_3;
    
    //declaramos un metodo privado que comprueba si son exaxtos los parametros
    
    bool EsCorrecto(){
	bool correctos = true;
	
	if((parametro_1==0) && (parametro_2==0))
	    correctos = false;
	return correctos;
    }
	
    
public:
    
    //declaramos un constructor
    
    Recta(){
	parametro_1 = 0;
	parametro_2 = 0;
	parametro_3 = 0;
	
	EsCorrecto();
    }
    
    //declatramos los metodos que devuelven los valores de las variables
    
    double GetParametro1(){
	return parametro_1;
    }
    
    double GetParametro2(){
	return parametro_2;
    }
    
    double GetParametro3(){
	return parametro_3;
    }
    
    //declaramos un metodo que asigna los valores a los coeficientes 
    // en funcion de la condicion dada en el metodo privado
    
    void SetCoeficientes(double dato1, double dato2, double dato3){
    
	if(EsCorrecto()){
	
	    parametro_1 = dato1;
	
	    parametro_2 = dato2;
	
	    parametro_3 = dato3;
	}
	else{
	    parametro_1 = 1;
	    parametro_2 = 1;
	    parametro_3 = 1;
	}
    }
    
    //declaramos un metodo que calcula la pendienta
    
    double Pendiente(){
	double pendiente;
	
	pendiente = -1 * (parametro_1) / parametro_2;
	
	return pendiente;
    }
    
    //declaramos un metodo que calcula la variable x
    
    double CalculaY(int x){
	
	int resultado;
	
	resultado = ((-1*(parametro_3)) - (x*parametro_1)) / parametro_2;

	return resultado;
    }
    
    //declaramos un metodo que calcula la variable y
    
    double CalculaX(int y){
	int resultado;
	
	resultado = ((-1*(parametro_3)) - (y*parametro_2)) / parametro_1;
	
	return resultado;
	
    }  
    
    
    
    
};


int main(){
    
    //declaramos la clase
    
    Recta una_recta;
    
    //declaramos las variables
    
    double coeficiente_1, coeficiente_2, coeficiente_3;
    int x, y;
    
    //solicitamos los datos por pantalla
    
    cout << "\n\nDame los coeficientes dela ecuacion: ";
    
    cin >> coeficiente_1 >> coeficiente_2 >> coeficiente_3;
    
    //asignamos los valores a la clase
    
    una_recta.SetCoeficientes(coeficiente_1,coeficiente_2, coeficiente_3);
    
    //mostramos los valores poe pantalla
    
    cout << "\n\nSu recta es: ";
    cout<< una_recta.GetParametro1()<<"x + "<<una_recta.GetParametro2()<<"y + "<<una_recta.GetParametro3()<<"\n\n";
    cout << "\n\nLa pendiente de la recta es: ";
    cout <<una_recta.Pendiente()<<"\n\n";
    cout << "\n\nDame una valor de X: ";
    cin >> x;
    
    cout << "\n\nEl valor de X para Y es: ";
    cout <<una_recta.CalculaX(y);
    cout << "\n\n";
    
    cout << "\n\nDame un valor de y: ";
    cin >> y;
    
    cout << "\n\nEl valor de Y para X es: ";
    cout <<una_recta.CalculaY(x);
    cout << "\n\n";
    
    
    return (0); 
}
    
 