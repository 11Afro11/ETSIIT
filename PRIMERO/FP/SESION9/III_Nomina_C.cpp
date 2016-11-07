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
c) Supongamos que gestionamos las nóminas de varias sucursales de una empre-
sa. En cada sucursal hay un único diseñador pero el número de fabricantes es
distinto en cada sucursal. La forma de repartir el dinero es la siguiente: el dise-
ñador se lleva una parte del total y el resto se reparte a partes iguales entre los
fabricantes. En los apartados anteriores, por ejemplo, la parte que se llevaba el
diseñador era 2/5 y el resto (3/5) se repartía entre los tres fabricantes. La parte
que el diseñador se lleva puede ser distinta entre las distintas sucursales (2/5,
1/6, etc), pero no cambia nunca dentro de una misma sucursal. De la misma
forma, siempre hay un único diseñador en cada sucursal, aunque el número de
fabricantes puede variar entre distintas sucursales.
Suponed que las retenciones fiscales de los fabricantes y diseñador son distintas.
El programa leerá los siguientes datos desde un fichero externo:
? El número de sucursales.
? Los siguientes valores por cada una de las sucursales:
? Ingresos totales a repartir
? Número de fabricantes
? Parte que se lleva el diseñador
? Retención fiscal del diseñador
? Retención fiscal de los fabricantes

*/
/*********************************************************************/
#include <iostream>

using namespace std;

//declarmos la clase Nomina

class Nomina{
    
private:
    
    //declarmos los datos del ambito privado
	double fabricante;
	double diseniador;
	double precio;
	double cuantos_trabajadores;
public:
    
    //declaramos el constructor
    
    Nomina(){
	fabricante = 1;
	diseniador = 1;
	precio = 1;
	cuantos_trabajadores = 1;
    }
    
    //declaramos el metodo que asigna el valor de cuantos_trabajadores
    
    void SetTrabajadores(double trabajador){
	cuantos_trabajadores = trabajador;
    }
    
    //declaramos un metodo que devuelve el valor de cuantos_trabajadores
    
    double GetTrabajador(){
	return cuantos_trabajadores;
    }
    
    //declaramos los metodos que devuelven los valores de las demas variables
    
    double GetFabricante(){
	return fabricante;
    }
    
    double GetDiseniador(){
	return diseniador;
    }
    
    double GetPrecio(){
	return precio;
    }
    
    // declaramos los metodos que asignan valores a las demas variables
    
    void SetFabricante(double fabrica){
	fabricante = fabrica;
    }
    
    void SetDiseniador(double disenio){
	diseniador = disenio;
    }
    
    void SetPrecio(double dinero){
	precio = dinero;
    }
    
    //declaramos los metodos que calculan el reparto del precio
    
    Nomina ReparteDinero(){
	Nomina reparte;
	
	reparte.fabricante = precio/cuantos_trabajadores;
	reparte.diseniador = 2 * reparte.fabricante;
	
	return reparte;
    }
    
    //declaramos un metodo que cambia el valor del precio
    
    void SalarioNeto(int retencion){
	
	precio = precio - precio * retencion/100.0;
	
    }
    
    
};



int main(){
    
    //declaramos la clase
    
    Nomina una_nomina, reparte;
    
    //declaramos los datos de la funcion
    
    int precio, retencion, sucursales;
    double trabajador;
    
    //solicitamos los datos por teclado
    
    cout << "\n\nDame el precio: ";
    cin >>precio;
    una_nomina.SetPrecio(precio);
    cout << "\n\nDame la retencion:";
    cin >> retencion;
    cout << "\n\nDime cuantas sucursales: ";
    cin >> sucursales;
    
    //bucle for que repite los calculos con llamadas a la clase
    
    for(int i=1; i<sucursales; i++){
	
	//solicitamos los datos 
	
	cout << "¿Cuantos trabajadores hay en la sucursal "<<i<<" ? ";
	cin >>trabajador;
	
	una_nomina.SetTrabajadores(trabajador);
    
	una_nomina.SalarioNeto(retencion);
    
    
	reparte = una_nomina.ReparteDinero();
	
	//salida de datos por pantalla
    
	cout <<"\nEl diseniador cobra: "<<reparte.GetDiseniador()<<"\n";
	cout <<"\nCada trabajador cobra: "<<reparte.GetFabricante()<<"\n\n";
	
    }
    
    
    return(0);
}