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
 En este ejercicio se plantean varias modificaciones. Debe entregar un fichero cpp por
cada uno de los apartados.
Se desea implementar una clase Recta para representar una recta en el plano. Una
recta viene determinada por tres coeficientes A, B, C, de forma que todos los puntos
(x,y) que pertenecen a la recta verifican lo siguiente (ecuación general de la recta):
Ax + By + C = 0
e) Constructor
Modifique el programa principal del último apartado e imprima los valores de los
datos miembros de una recta, antes de asignarles los coeficientes. Mostrará, ob-
viamente, un valor indeterminado. Para evitar este problema, añada un construc-
tor a la recta para que el objeto esté en un estado válido en el mismo momento
de su definición. El constructor deberá tener como parámetros, obligatoriamente,
los tres coeficientes de la recta. Tendrá que modificar convenientemente el main
para tener en cuenta este cambio.


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
    
    //declaramos es constructor
    
    Recta(){
	parametro_1 = 0;
	parametro_2 = 0;
	parametro_3 = 0;
    }
    
    //declaramos los metodos que devuelven los parametros
    
    double GetParametro1(){
	return parametro_1;
    }
    
    double GetParametro2(){
	return parametro_2;
    }
    
    double GetParametro3(){
	return parametro_3;
    }
    
    //declaraos un metodo que saigna vlaores a los coeficientes
    
    void SetCoeficientes(double dato1, double dato2, double dato3){
    
	parametro_1 = dato1;
    
	parametro_2 = dato2;
    
	parametro_3 = dato3;
    }
    
    //declaramos un metodo que calcula la pendiente
    
    double Pendiente(){
	double pendiente;
	
	pendiente = -1 * (parametro_1) / parametro_2;
	
	return pendiente;
    }
    
    //declaramos un metodo que calcula  el valor de y
    
    double CalculaY(int x){
	
	int resultado;
	
	resultado = ((-1*(parametro_3)) - (x*parametro_1)) / parametro_2;

	return resultado;
    }
    
    //declaramos un metodo que calcula el valor de X
    
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
    
    //pedimos los coeficientes
    
    
    cout << "\n\nDame los coeficientes dela ecuacion: ";
    
    cin >> coeficiente_1 >> coeficiente_2 >> coeficiente_3;
    
    //asignamos los coeficientes
    
    una_recta.SetCoeficientes(coeficiente_1,coeficiente_2, coeficiente_3);
    
    //salida de datos por pantalla con llamada al metodo de la clase recta
    
    cout << "\n\nSu recta es: ";
    cout<< una_recta.GetParametro1()<<"x + "<<una_recta.GetParametro2()<<"y + "<<una_recta.GetParametro3()<<"\n\n";
    cout << "\n\nLa pendiente de la recta es: ";
    cout <<una_recta.Pendiente()<<"\n\n";
    cout << "\n\nDame una valor de X: ";
    cin >> x;
    
    //calculamos el valor de X
    
    cout << "\n\nEl valor de X para Y es: ";
    cout <<una_recta.CalculaX(y);
    cout << "\n\n";
    
    //calculamos el valor de y
    
    cout << "\n\nDame un valor de y: ";
    cin >> y;
    
    cout << "\n\nEl valor de Y para X es: ";
    cout <<una_recta.CalculaY(x);
    cout << "\n\n";
    
    
    return (0); 
}
    
    
    
	