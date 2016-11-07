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
// EJERCICIO 19
//
/*	
 Se quiere construir una clase Nomina para realizar la funcionalidad descrita en el
ejercicio 12 de la Relaci�n de Problemas I sobre la n�mina del fabricante y dise�ador
(p�gina RP-I.5). Cread los siguientes programas (entregad un fichero por cada uno de
los apartados):

a) Suponed que s�lo gestionamos la n�mina de una empresa en la que hay un fabri-
cante y tres dise�adores. Los salarios brutos se obtienen al repartir los ingresos
de la empresa, de forma que el dise�ador cobra el doble de cada fabricante.
El programa leer� el valor de los ingresos totales y calcular� los salarios brutos
de los fabricantes y dise�ador, llamando a los m�todos oportunos de la clase
Nomina.


*/
/*********************************************************************/
#include <iostream>

using namespace std;

//declaramos la clase nomina

class Nomina{
    
private:
    
    //declaramos las variables enn el ambito privado
	double fabricante;
	double diseniador;
	double precio;
public:
    
    //declaramos el constructor
    
    Nomina(){
	fabricante = 1;
	diseniador = 1;
	precio = 1;
    }
    
    //declaramos el metodo que devuelve el valor de la variable fabricante
    
    double GetFabricante(){
	return fabricante;
    }
    
    //declaramos un metodo que devuelve el valor de la variable diseniador
    
    double GetDiseniador(){
	return diseniador;
    }
    
    //declaramos un metodo que devuelve el valor de la variable precio
    
    double GetPrecio(){
	return precio;
    }
    
    //declaramos los metodos que asignan los valores a las variables privadas
    
    void SetFabricante(double fabrica){
	fabricante = fabrica;
    }
    
    void SetDiseniador(double disenio){
	diseniador = disenio;
    }
    
    void SetPrecio(double dinero){
	precio = dinero;
    }
    
    //declaramos un metodo de tipo nomina que devuelve una variable nomina y calcula el precio 
    //el salario de cada empleado
    
    Nomina ReparteDinero(){
	Nomina reparte;
	
	reparte.fabricante = precio/5;
	reparte.diseniador = (2*precio)/5;
	
	return reparte;
    }
    
    
};



int main(){
    
    //declaramos la clase nomina 
    
    Nomina una_nomina, reparte;
    
    //declaramos las variables
    
    int precio;
    
    //solicitamos los datos y los asignamos a los metodos de la clase
    
    cout << "\n\nDame el precio: ";
    cin >>precio;
    una_nomina.SetPrecio(precio);
    
    //asignamos valores a laa variable del metodo Reparte    
    
    reparte = una_nomina.ReparteDinero();
    
    //salida  de datos por pantalla
    
    cout <<"\nEl diseniador cobra: "<<reparte.GetDiseniador()<<"\n";
    cout <<"\nCada trabajador cobra: "<<reparte.GetFabricante()<<"\n";
    
    
    return(0);
}
    
    
	

	
    