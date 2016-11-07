/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
//
// CURSO 2014-2015
//
// GRUPO C
//
// FRANCISCO JAVIER FUENTES BARRAGÁN
//
// SESIÓN 4
// EJERCICIO 9
//
/*	

 Una compañía aérea establece el precio del billete como sigue: en primer lugar se fija
una tarifa base de 150 euros, la misma para todos los destinos. Si el destino estámenos de 200 kilómetros, el precio final es la tarifa inicial. Para destinos a más de 200
Km, se suman 10 céntimos por cada kilómetro de distancia al destino (a partir del Km
200).
En una campaña de promoción se va a realizar una rebaja lineal de 15 euros a to-
dos los viajes. Además, se pretenden añadir otras rebajas y se barajan las siguientes
alternativas de políticas de descuento:
a) Una rebaja del 3 % en el precio final, para destinos a más de 600Km.
b) Una rebaja del 4 % en el precio final, para destinos a más de 1100Km. En este
caso, no se aplica el anterior descuento.
c) Una rebaja del 5 % si el comprador es cliente previo de la empresa.
Cread un programa para que lea el número de kilómetros al destino y si el billete
corresponde a un cliente previo de la empresa. Calcular el precio final del billete con
las siguientes políticas de descuento:
• Aplicando c) de forma adicional a los descuentos a) y b)

• Aplicando c) de forma exclusiva con los anteriores, es decir, que si se aplica c),
no se aplicaría ni a) ni b)



*/
/*********************************************************************/


#include <iostream>

using namespace std;

int main(){
    
    int kilometro;		//declaramos las variables kilometro y
    char cliente_previo;	//cliente_previo las cuales leeren
    double precio = 150;	//los datos desde teclado y las variables
    double exclusivo;		//y las variables precio y excusivo  que 
				//mostraran los datos por pantalla
				
    //Solicitamos datos por teclado				
    
    cout<<"\n¿Es usted cliente usual de uestra compañia de viajes? [S/N]:";
    cin>>cliente_previo;
    
    cout<<"\n¿cuantos kilimetros desea viajar?_ ";
    cin>>kilometro;
    
    //si se desea viajar mas de 200 kilometro el precio sera intrementado 10 
    //centimos por kilometro.
    
    if(kilometro >= 200){
	precio = precio + ((precio - 200) * 0.1);
    }
    
    //se produce el primer descuento de 15 euros a todos los pasajeros 
    
    precio = precio - 15;
    
    //si el cliente ya habia volado con la compañia se le aplica un descuento 
    //del 5%. tambien guardamos ese valor en la variable excusivo 
    //para mostrarlo por pantalla
    
    if(cliente_previo = 'S'){
	
	precio = precio - (precio * 0.05);
	exclusivo = precio;
    }
    
    //si el cliente va a volar mas de 600 kilometros se le aplica un descuento 
    //del 3%
    
    if( (kilometro > 600) && (kilometro <= 1100) ){
	
	precio = precio - (precio * 0.03);
	
    }
    
    //si es superior a 1100se le aplica un descuento del 4% sin aplicar el 
    //anterior
    
    else if(kilometro > 1100){
	
	precio = precio - (precio * 0.04);
    }
    
    //salida de resultados por pantalla
    	
    cout<<"\nAplicandole el descuento exclusivo el total a pagar será:"<<exclusivo<<"\n\n";
    
    cout<<"\nAplicandonle el descuento especial el total a pagar será:"<<precio<<"\n\n";
    
    //system ("pause");
    
    return (0);
    
}