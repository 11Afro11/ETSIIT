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
// SESION 8
// EJERCICIO 29
//
/*	
 Se dice que un número natural es feliz si cumple que si sumamos los cuadrados de
sus dígitos y seguimos el proceso con los resultados obtenidos, finalmente obtenemos
uno (1) como resultado. Por ejemplo, el número 203 es un número feliz ya que 22 +
02 + 32 = 13 ? 12 + 32 = 10 ? 12 + 02 = 1.
Se dice que un número es feliz de grado k si es feliz en un máximo de k iteraciones.
Se entiende que una iteración se produce cada vez que se elevan al cuadrado los
dígitos del valor actual y se suman. En el ejemplo anterior, 203 es un número feliz de
grado 3 (además, es feliz de cualquier grado mayor o igual que 3)
Escribir un programa que diga si un número natural n es feliz para un grado k dado
de antemano. Tanto n como k son valores introducidos por el usuario.



*/
/*********************************************************************/
#include <iostream>

using namespace std;

int CuentaDigitos(int numero){
    
    int elevar = 0;
    
    while(numero > 9){	
	numero = numero / 10;
	elevar++;
    }
    
    return elevar;
}

int Sumatoria (int numero){
    int elevar = CuentaDigitos(numero);
    int potencia;
    int num_separado;
    int sumatoria = 0;
    
    
    while(elevar >= 0){		//La condicion para que se para el bucle es que el numero al que elevamos 
					//10 llegue a 0, es decir, que dividamos por uno, lo que guardara el ultimo
					//numero
	    potencia = pow(10, elevar);		//inicializamos la variable potencia
	    num_separado = numero / potencia;	//calculamos el primer numero	
	    
	    sumatoria_1 = sumatoria_1 + (pow(num_separado, 2));
	

	    numero = numero % potencia;		//nos aseguramos de que lo siguente que se divida sea el resto
	    elevar--;				//reducimos el exponente
	}
	return sumatoria
}

int Bucle(int tope, int numero){
    
    for(int k = 1; k <= tope; k++){
	
	num_separado = numero;
	sumatoria_1 = 0;
	
	return Sumatoria(numero);
    }
    
}


bool EsFeliz(int numero, int tope){
    
    bool es_feliz = false;
    
    if(Bucle(numero, tope)==1)
	es_feliz = true;
    return es_feliz;
}


int main(){
    
    int numero;
    int tope;
    
    cout << "\n\nIntroduce un numero cualquiera: ";
    cin >> numero;
    cout << "\n\nIntroduce un tope de interacciones: ";
    cin>>tope;
    cout<<"\n\n";
    
    if(EsFeliz(numero, tope)
	cout << "\n\nEl numero es feliz en "<<tope<<" interacciones\n\n";
    else
	cout << "\n\nEl numero no es feliz";

    
    return (0);
}


    
    
    