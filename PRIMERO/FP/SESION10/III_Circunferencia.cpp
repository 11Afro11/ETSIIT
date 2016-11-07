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
// SESION 10
// EJERCICIO 30
//
/*  
. Cread un struct llamado CoordenadasPunto2D para representar un par de
valores reales correspondientes a un punto en R2 . Cread ahora una clase lla-
mada Circunferencia. Para establecer el centro, se usará un valor del tipo
CoordenadasPunto2D. Añadid métodos para obtener la longitud de la circunferen-
cia y el área del círculo interior. Añadid también un método para saber si la circun-
ferencia contiene a un punto. Recordemos que un punto (x1 , y1) está dentro de una
circunferencia con centro (x0 , y0 ) y radio r si se verifica que:
(x0 − x1)2 + (y0 − y1 )2 <= r2
Observad que el valor de π debe ser constante, y el mismo para todos los objetos de
la clase Circunferencia.

*/
/*********************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

//declaramos un struct con dos valores de tipo entero

struct CoordenadasPunto2D{
    
    int eje_x;
    int eje_y;
};

//creamos la clase circunferencia con una llamada al struct  y con una variable
// constanta en el ambito privado

class Circunferencia{
private:
    CoordenadasPunto2D p,c,o;
    static const double PI = 3.141592;
public:
    
    //declaramos un constructor

    Circunferencia(){
	p.eje_x=0;
	p.eje_y=0;
	c.eje_x=0;
	c.eje_y=0;
    }    
    
    //declaramos los metodos que devuelven los valores de las vaariables

    CoordenadasPunto2D GetP(){
		return p;
    }
    
    CoordenadasPunto2D GetC(){
		return c;
    }

    CoordenadasPunto2D GetO(){
    	return o;
    }

    //declaramos los metodos que asignan valores a las variables
    
    CoordenadasPunto2D SetP(int x_1, int y_1){
		p.eje_x = x_1;
		p.eje_y = y_1;
    }
    
    CoordenadasPunto2D SetC(int x_2, int y_2){
		c.eje_x = x_2;
		c.eje_y = y_2;
    }

    CoordenadasPunto2D SetO(int x_3, int y_3){
	    o.eje_x = x_3;
	    o.eje_y = y_3;
    }

    //metodo booleano que comprueba si el punto se encuentra en la circunferencia
    
    bool EstaDentro(){
        bool es_dentro= true;
        if(o.eje_x > p.eje_y)
            es_dentro = false;
        if(o.eje_y > p.eje_y)
            es_dentro = false;

        return es_dentro;
    }

    //metodo que calcula el radio

    double CalculaRadio(){
        double radio;
        radio = sqrt(((p.eje_x-c.eje_x) * (p.eje_x-c.eje_x))
            +((p.eje_y-c.eje_y) * (p.eje_y-c.eje_y)));

        return radio;
    }

    //metodo que calcula la longitud 

    double CalculaLongitud(){
        double longitud;
        longitud = 2 * PI * CalculaRadio();

        return longitud;
    }



};

int main(){

    //declaramos la clase

    Circunferencia circulo;

    //declaramos las vcariables

    int x1,x2,x3,y1,y2,y3;

    //solicitamos loa datos por pantalla

    cout << "\n\nDame los puntos que forman la circunferencia: ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "\n\nDame un punto: ";
    cin >> x3 >> y3;

    //asignamos los valores a la clase

    circulo.SetP(x1, y1);
    circulo.SetC(x2, y2);
    circulo.SetO(x3, y3);

    //salida de datos por pantalla


    if(circulo.EstaDentro())
        cout << "\n\nEl punto esta dentro de la circinferencia\n";
    else 
        cout << "\n\nEl punto no esta dentro de la circunferencia";

    cout << "\n\nEl radio de la circunferencia vale "<<circulo.CalculaRadio()<<"\n\n";
    cout << "\n\nLa longitud vale: "<<circulo.CalculaLongitud()<<"\n\n";


    return(0);
}