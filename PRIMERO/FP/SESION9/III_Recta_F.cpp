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
 Política de acceso a los datos miembro
Suprima ahora el método SetCoeficientes. De esta forma, una vez creado
el objeto (pasándole los datos apropiados en el constructor) ya no podremos
modificar los datos miembro. Esto es útil en aquellas situaciones en las que no
queremos permitir que el estado del objeto cambie, una vez se ha creado.


*/
/*********************************************************************/
#include <iostream>

using namespace std;

//declaramos la clase Recta

class Recta{
    
private:
    
    //declaramos las variables del ambito privado
    
    double parametro_1;
    double parametro_2;
    double parametro_3;
public:
    
    //inicializamos el constructor
    
    Recta(){
	parametro_1 = 3;
	parametro_2 = 5;
	parametro_3 = 7;
    }
    
    //declaramos los metodos que devuelven el valor de las variables
    
    double GetParametro1(){
	return parametro_1;
    }
    
    double GetParametro2(){
	return parametro_2;
    }
    
    double GetParametro3(){
	return parametro_3;
    }
    
    //declaramos el metodo que calcula la pendiente   
    
    double Pendiente(){
	double pendiente;
	
	pendiente = -1 * (parametro_1) / parametro_2;
	
	return pendiente;
    }
    
    //declaramos el metodo que calcula el valor de y
    
    double CalculaY(int x){
	
	int resultado;
	
	resultado = ((-1*(parametro_3)) - (x*parametro_1)) / parametro_2;

	return resultado;
    }
    
    //declaramos el metodo que calcula el valor de x
    
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
    
    double x, y;
    
    //solicitamos los datos
    
    cout << "\n\nSu recta es: ";
    cout<< una_recta.GetParametro1()<<"x + "<<una_recta.GetParametro2()<<"y + "<<una_recta.GetParametro3()<<"\n\n";
    cout << "\n\nLa pendiente de la recta es: ";
    cout <<una_recta.Pendiente()<<"\n\n";
    
    //solicitamos datos y calculamos la variable x
    
    cout << "\n\nDame una valor de X: ";
    cin >> x;
    
    cout << "\n\nEl valor de X para Y es: ";
    cout <<una_recta.CalculaX(y);
    cout << "\n\n";
    
    //solicitamos datos y calculamos la variable y
    
    cout << "\n\nDame un valor de y: ";
    cin >> y;
    
    cout << "\n\nEl valor de Y para X es: ";
    cout <<una_recta.CalculaY(x);
    cout << "\n\n";
    
    
    return (0); 
}