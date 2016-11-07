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
// SESIÓN 5
// EJERCICIO 16
//
/*	

 Una empresa que tiene tres sucursales decide llevar la contabilidad de las ventas
de sus productos a lo largo de una semana. Para ello registra cada venta con tres
números, el identificador de la sucursal (1,2 ó 3), el código del producto (1, 2 ó 3)el 
número de unidades vendidas. Diseñar un programa que lea desde el teclado una
serie de registros compuestos por sucursal, producto, unidades y diga cuál
es la sucursal que más productos ha vendido. La serie de datos termina cuando la
sucursal introducida vale -1. Por ejemplo, con la serie de datos
1 2 10
1 2 4
1 1 1
1 1 1
1 3 2
2 2 15
2 2 6
2 1 20
3 3 40
-1

Se puede ver que la sucursal que más productos ha vendido es la número 2 con
41 unidades totales. La salida del programa deberá seguir exactamente el siguiente
formato:
SUCURSAL: 2
VENTAS: 41

Para comprobar que el programa funciona correctamente, cread un fichero de texto y
re-dirigid la entrada a dicho fichero.


*/
/*********************************************************************/


#include <iostream>

using namespace std;

int main(){
    
    int sucursal;		//declaramos las variables de eltrada:
    int producto;		//sucursal,producto e unidades.
    int unidades;
    int unidad_total_1 = 0;	//declaramos las variables que almacenan la informacion
    int unidad_total_2 = 0;	//almacenada de cada sucursal
    int unidad_total_3 = 0;
    int unidad_total;		//variable que mostrara cual es la sucursal por pantalla
    int sucursal_final;
    
    //solicitud de datos por pantalla
    
    cout<<"dame las caracteristicas de la venta: ";
    cin>>sucursal;
    
    //si el primer valor introducido es el finalizador el 
    //programa no leerea mas datos y se cerrara
    
    if(sucursal != -1){
	cin>>producto;
	cin>>unidades;
	
	while(sucursal != -1){	//mientras el valos no sea -1, el programa leera la sucursal 
				//y almacena las unidades de cada uno	    
	
	    if(sucursal == 1)
	    
		unidad_total_1 = unidad_total_1 + unidades;
	    
	    if(sucursal == 2)
	    
		unidad_total_2 = unidad_total_2 + unidades;
	    
	
	    if(sucursal == 3)
	    
		unidad_total_3 = unidad_total_3 + unidades;
	    
	    //vuelve a pedir datos aplicando el mismo filtro
	    //que al principio del programa
	
	    cout<<"dame las caracteristicas de la venta: ";
	    cin>>sucursal;
	    if(sucursal != -1){
		cin>>producto;
		cin>>unidades;
	}
	
	
    
        }
        
        //comparamos la unidades totales de cada empresa para comprobar cual es la mayor de todas 
        //y a que sucursal pertenece
    
        if((unidad_total_1 > unidad_total_2) && (unidad_total_1 > unidad_total_3)){
	    sucursal_final = 1;
	    unidad_total = unidad_total_1;
        }
        if((unidad_total_2 > unidad_total_1) && (unidad_total_2 > unidad_total_3)){
	    sucursal_final = 2;
	    unidad_total = unidad_total_2;
        }
        if((unidad_total_3 > unidad_total_2) && (unidad_total_3 > unidad_total_1)){
	    sucursal_final = 3;
	    unidad_total = unidad_total_3;
        }
    
	//por ultimo mostramos los datos por pantalla
    
        cout<<"\n\nSUCURSAL: "<<sucursal_final<<"\n\n";
        cout<<"\n\nVENTAS: "<<unidad_total<<"\n\n";
    }
    
    else	//mensaje que se mostrara si el primer numero introducido es el
		//finalizador
	cout<<"\n\nNo se ejecuto el programa.\n\n";   
    
    
    //system ("pause");
    
    return (0);
    
}