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
// EJERCICIO 21
//
/*	
 Se quiere construir una clase para representar la tracción de una bicicleta, es decir,
el conjunto de platos (engranaje delantero), cadena y piñones (engranaje trasero).
Supondremos que se dispone de tres platos (numerados de 1 a 3, siendo 1 el más
pequeño) y 7 piñones (numeradas de 1 a 7, siendo 1 el piñón más grande).
La clase debe proporcionar métodos para cambiar de plato y piñón, sabiendo que los
platos avanzan o retroceden de 1 en 1 y los piñones cambian a saltos de uno o de
dos. Si ha llegado al límite superior (inferior) y se llama al método para subir (bajar) de
plato, la posición no variará. Lo mismo se aplica al piñón.
Cread un programa principal que lea desde un fichero externo los movimientos reali-
zados e imprima la situación final de plato y piñón. Los datos se leerán en el siguiente
formato: tipo de engranaje (piñón o plato) seguido del tipo de movimiento.
Para codificar esta información se usarán las siguientes letras: E indica un plato, P un
piñón, S para subir una posición, B para bajar una posición, T para subir dos posiciones
y C para bajar dos posiciones. T y C sólo se aplicarán sobre los piñones.
E S P S P S P S P C E S E B E B X
En este ejemplo los movimientos serían: el plato sube, el piñón sube en tres ocasio-
nes sucesivas, el piñón baja dos posiciones de golpe, el plato sube y vuelve a bajar.
Supondremos siempre que la posición inicial del plato es 1 y la del piñón 1. Así pues,
la posición final será Plato=1 y Piñón=2.
Mejorad la clase para que no permita cambiar la marcha (con el plato o el piñón)
cuando haya riesgo de que se rompa la cadena. Este riesgo se produce cuando la
marcha a la que queremos cambiar es de la siguiente forma:
• Plato igual a 1 y piñón mayor o igual que 5
• Plato igual a 2 y piñón o bien igual a 1 o bien igual a 7
• Plato igual a 3 y piñón menor o igual que 3


*/
/*********************************************************************/

#include <iostream>

using namespace std;

//declaramos un struct con dos variables enteras

struct Numeros{
    int pinion;
    int cadena;
};

//declaramos la calse bicicleta con una llamada al struct Numeros

class Bicicleta{
private:
    Numeros un_numero;

public:

	//constructor

    Bicicleta(){
	un_numero.pinion=1;
	un_numero.cadena=1;
    }

    //metodos que devuelven los valores de las variables 
    
    int GetPinion(){
	return un_numero.pinion;
    }
    
    int GetCadena(){
	return un_numero.cadena;
    }

    //metodo booleano que comprueba si es posible el cambio de marchas
        
    bool SePuede(){
			bool se_puede;
			
			if((un_numero.pinion=1)&&(un_numero.cadena>=5))
			    se_puede=false;
			if((un_numero.pinion=2)&&((un_numero.cadena=1)||(un_numero.cadena=7)))
			    se_puede=false;
			if((un_numero.pinion=3)&&(un_numero.cadena<=3))
			    se_puede=false;
			
			return se_puede;
    }

    //metodo que mueve el piñon
    
    void MuevePinion(char identifica ){
	
			if((identifica == toupper('s'))&&(SePuede()))
			    un_numero.pinion ++;
			if((identifica == toupper('t'))&&(SePuede()))
			    un_numero.pinion + 2;
			if((identifica == toupper('b'))&&(SePuede()))
			    un_numero.pinion --;
			if((identifica == toupper('c'))&&(SePuede()))
			    un_numero.pinion - 2;
			
    }

    //metodo que mueve el plato
    
    void MuevePlato(char plato_i){
	
			if((plato_i == toupper('s'))&&(SePuede()))
			    un_numero.cadena++;
			if((plato_i == toupper('t'))&&(SePuede()))
			   un_numero.cadena--;
	
    }

    //metodo que se encarga se saber si debemos mover el piñon o el plato

    void Eleccion(char seleccion, char accion){
	if(seleccion == toupper('e'))
	    MuevePlato(accion);
	if(seleccion == toupper('p'))
	    MuevePinion(accion);
    }
    
};


int main(){

	//llamada a la clase Bicicleta

    Bicicleta mi_bici;

    //variables
    
    char manillar, movimiento;

    //solicitud de datos
    
    cout << "\n\nMonte en la bici: ";
    cin>>manillar >> movimiento;

    //bucle que toma los datos con lectura adelantada
    
    while((manillar != toupper('x')) && (movimiento != toupper('x'))){
	
	mi_bici.Eleccion(manillar, movimiento);
	
	
	cin>>manillar >> movimiento;
    }
    
    //saliada de datos por pantalla con llamada a la clase
    
    cout << "\nEl plato vale "<<mi_bici.GetCadena()<<" y el pinion vale ";
    cout <<mi_bici.GetPinion()<<"\n\n";
    
    return(0);
}