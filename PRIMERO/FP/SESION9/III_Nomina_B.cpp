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
b) Supongamos que se aplica una retención fiscal y que ésta es la misma para los
fabricantes y el diseñador. Una vez que se establezca la retención fiscal, ésta no
cambia. Los salarios netos se obtienen al aplicar la retención fiscal a los salarios
brutos (después de repartir los ingresos totales de la empresa):
salario_neto =
salario_bruto -
salario_bruto * retencion_fiscal / 100.0
El programa leerá el valor de los ingresos totales y la retención fiscal a aplicar y
calculará los salarios brutos y netos de los fabricantes y diseñador, llamando a
los métodos oportunos de la clase Nomina.


*/
/*********************************************************************/
#include <iostream>

using namespace std;

//declaramos la clase Nomina

class Nomina{
    
private:
    
    //declaramos las variables del ambito privado
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
    
    //declaramos los metodos que devuelven los valores de las variables
    
    double GetFabricante(){
	return fabricante;
    }
    
    double GetDiseniador(){
	return diseniador;
    }
    
    double GetPrecio(){
	return precio;
    }
    
    //declaramos los metodos que cambian los valores de las variables
    
    void SetFabricante(double fabrica){
	fabricante = fabrica;
    }
    
    void SetDiseniador(double disenio){
	diseniador = disenio;
    }
    
    void SetPrecio(double dinero){
	precio = dinero;
    }
    
    //metodo que reparte el precio entre los trabajadores
    
    Nomina ReparteDinero(){
	Nomina reparte;
	
	reparte.fabricante = precio/5;
	reparte.diseniador = (2*precio)/5;
	
	return reparte;
    }
    
    //metodo que cambia el valor del precio
    
    void SalarioNeto(int retencion){
	
	precio = precio - precio * retencion/100.0;
	
    }
    
    
};



int main(){
    
    //declaracion de la clase
    
    Nomina una_nomina, reparte;
    
    //declaramos las variables de la funcion
    
    int precio, retencion;
    
    //solicitamos los datos por teclado
    
    cout << "\n\nDame el precio: ";
    cin >>precio;
    una_nomina.SetPrecio(precio);
    cout << "\n\nDame la retencion:";
    cin >> retencion;
    
    
    
    una_nomina.SalarioNeto(retencion);
    
    
    reparte = una_nomina.ReparteDinero();
    
    //salida de datos por pantalla
    
    cout <<"\nEl diseniador cobra: "<<reparte.GetDiseniador()<<"\n";
    cout <<"\nCada trabajador cobra: "<<reparte.GetFabricante()<<"\n";
    
    
    return(0);
}