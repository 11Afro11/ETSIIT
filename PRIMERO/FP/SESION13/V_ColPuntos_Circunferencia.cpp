/*/*******************************************
//FUNDAMENTOS DE PROGRAMACION
//GRADO EN INGENIERIA INFORMATICA
//
//CURSO 2014-2015
//(C) FRANCISCO JAVIER FUENTES BARRAGAN
//
//RELACION DE PROBLEMAS 5
//PROBLEMA NUMERO 3-4
//
//
Considerar la clase ColeccionPuntos2D que se usará para almacenar y gestionar
una colección de datos de tipo Punto2D. Por simplicidad consideraremos únicamente
puntos cuyas coordenadas sean positivas.
Realizar un programa que lea del teclado un número indeterminado de datos de tipo
Punto2D de manera que termine la lectura si el usuario escribe -1 cuando el programa
le pide la abscisa de un nuevo punto. Los puntos leídos los almacena en un objeto
ColeccionPuntos2D.
A continuación pide los datos necesarios, y crea un objeto Circunferencia,
y finalmente muestra cuáles de los puntos almacenados en la colección
ColeccionPuntos2D está en el círculo delimitado por la circunferencia.

/******************************************************************
*/
#include <iostream>

using namespace std;
//clase punto 2d
class Punto2D{
private:
	
	//metodos del ambito privado
	double abscisa;
	double ordenada;
public:
	//constructor con argumentos
	Punto2D(double abscisaPunto, double ordenadaPunto)
		:abscisa(abscisaPunto),
		ordenada(ordenadaPunto)
	{ }
	//metodo que devuelve la abcisa
	double GetAbscisa(){
		return abscisa;
	}
	//metodo que devuelvela ordenada
	double GetOrdenada(){
		return ordenada;
	}

};
//clase coleccion de puntos 2d
class ColeccionPuntos2D{
	private:
		//ambito privado
		static const int TAMANIO = 150;
		Punto2D vector[TAMANIO];
		int total_utilizados;

	public:
	//cosntructor
	ColeccionPuntos2D(){
		total_utilizador = 0;
	}
	//metodo que devuelve el tamanio del vector
	int TotalUtilizados(){
		return total_utilizados;
	}
	//metodo que devuelve la capacidad del vector
	int Capacidad(){
		return TAMANIO;
	}
	//metodo que aniade unelemento
	void Aniade(Punto2D un_punto){
		if (total_utilizados < TAMANIO){
			vector[total_utilizados-1].GetAbscisa() = un_punto.GetAbscisa();
			total_utilizados++;
		}
	}
	//metodod que devuelve un elemento
	 Punto2D Elemento(int indice){
		return vector[indice];
	}
};

class Circunferencia{
	
private:
	//ambito privado
	static const double PI= 3.1416
	Punto2D centro;
	double radio;
public:
	//constructor
	Circunferencia(Punto2D punto){
		centro.GetAbscisa() = punto.GetAbscisa();
		centro.GetOrdenada() = punto.GetOrdenada();		
	}
	//metodo que asigna el centro
	
	void SetCentro(double abscisa, double ordenada){
	centro.GetAbscisa() = abscisa;
	centro.GetOrdenada() = ordenada;
	}
	//metodo que signa el redio
	
	void SetRadio(double el_radio){
	radio = el_radio;
	}
	//metpdo que devuelve la abcisa
	
	double GetAbscisaCentro(){
	return centro.GetAbscisa();
	}
	//metodod que deuelve las ordenadas
	
	double GetOrdenadaCentro(){
	return centro.GetOrdenada();
	}
	//metodo que devuelve el radio
	
	double GetRadio(){
	return radio;
	}
	//metodo que devuelve la longitud
	double Longitud(){
	return 2*PI*radio;
	}
	//metodo que devuelveel area
	double Area(){
	return PI*radio*radio;
	}
	//metodo que devuelve el diametro
	double Diametro(){
	return 2*radio;
	}
	//metodo que traslada el punto
	void Traslada(double en_horizontal, double en_vertical){
	centro.GetAbscisa() = centro.GetAbscisa() + en_horizontal;
	centro.GetOrdenada = centro.GetOrdenada() + en_vertical;
	}
	//metodo que comprueba si el puto esta dentro de la circunferencia
	bool EsDentro(Punto2D puntillo){
		bool es_dentro;
		int longitud = ((puntillo.GetAbscisa() - punto.GetAbscisa()) *(puntillo.abscisa - punto.abscisa)) +
						((puntillo.GetOrdenada() - punto.GetOrdenada()) *(puntillo.GetOrdenada() - punto.GetOrdenada()));
		
		if(longitud <= (radio * radio))
			es_dentro = true;
		else
			es_dentro = false;
			
		return es_dentro;
	}
	
};

int main(){
	//creamos eobjetos de las clases
	Punto2D un_punto, otro_punto(0,0), ensenia_punto;
	Circunferencia circulo(otro_punto);
	ColeccionPuntoas2D coleccion;
	int puntos = 0;
	
	int abscisas;
	int ordenadas;
	
	int radio;
	//solicitud de datos
	cout << "\n\nDameel valor del radio: ";
	cin >> radio;
	
	circulo.SetRadio(radio);
	
	cout << "\n\nIntroduzca el valor de abscisas: ";
	cin >> abscisas;

	while(abscisas != -1){
		cout << "\n\nIntroduzca el valor de ordenadas: ";
		cin >> ordenadas;
		un_punto(abscisas, oredenadas);
		coleccion.Aniade(un_punto);
		cout << "\n\nIntroduzca el valor de abscisas: ";
		cin >> abscisas;		
	}
	
	//mostramos los datos porpantalla
	for(int i = 0; i < coleccion.TotalUtilizados; i++){
		if(circulo.EsDentro(coleccion.Elemento(i)))
			ensenia_punto = circulo.EsDentro(coleccion.Elemento(i));
			cout << " "<<ensenia_punto.GetAbscisa()<<" "<<ensenia_punto.GetOrdenada()<<" ";
	}
	
	cout << "\n\nHay "<<puntos<<" puntos dentro de la circunferencia\n\n"
	
	cout << "\n\n La longitud es: "<<circulo.Longitud()<<"\n\n";
	
	cout << "\n\n El area es: "<<circulo.Area()<<"\n\n";
	
	cout << "\n\nEl centro es: "<<circulo.GetCentro().GetAbscisa() << " " <<circulo.GetCentro().GetOrdenada();
	
	cout << "\n\n El diametro es: "<<circulo.Diametro()<<"\n\n";
	
}