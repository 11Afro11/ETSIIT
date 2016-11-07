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
// EJERCICIO 17
//
/*	
 Recuperad la solución del ejercicio 8 de la Relación de Problemas II (actualización
de la retención fiscal y renta). En este problema se leían caracteres del teclado para
saber si una persona era autónomo, pensionista, etc. Por ejemplo (ver la solución
proporcionada para este ejercicio):
char opcionSN;
cout << "¿Autónomo (S/N)? : ";
cin >> opcionSN;
es_autonomo = (toupper(opcionSN) == ?S?);
ó siendo estrictos:
char opcionSN;
do{
cout << "¿Autónomo (S/N)? : ";
cin >> opcionSN;
opcionSN = toupper(opcionSN);
} while (opcionSN != ?S? && opcionSN != ?N?);
es_autonomo = (toupper(opcionSN) == ?S?);
Este código era casi idéntico para la lectura del resto de los datos. Para evitarlo, definid
una clase LectorOpcion que encapsule esta funcionalidad y cambiar el programa
principal para que use esta clase.


*/
/*********************************************************************/

#include <iostream>

using namespace std;

//declramos la clase LectorOpcion

class LectorOpcion{
private:
    
    //declaramos las variables del ambito privado
    
    char opcionSN;
    
public:
    
    //declaramos los metodo que leen los datos desde teclado y devuelven un bool
    
    bool LeerAutonomo(){
	
	bool es_autonomo;
	
	do{
	    cout << "¿Autónomo (S/N)? : ";
	    cin >> opcionSN;
	    opcionSN = toupper(opcionSN);
	    } while (opcionSN != 'S' && opcionSN != 'N');
	es_autonomo = (toupper(opcionSN) == 'S');
	
	return es_autonomo;
    }
    
    bool LeerPensionista(){
	bool es_pensionista;
	
	do{
	    cout << "¿Pensionista (S/N)? : ";
	    cin >> opcionSN;
	    opcionSN = toupper(opcionSN);
	    } while (opcionSN != 'S' && opcionSN != 'N');
	es_pensionista = (toupper(opcionSN) == 'S');
	
	return es_pensionista;
    }
    
    bool LeerCivil(){
	bool es_casado;
	
	do{
	    cout << "¿Casado (S/N)? : ";
	    cin >> opcionSN;
	    opcionSN = toupper(opcionSN);
	    } while (opcionSN != 'S' && opcionSN != 'N');
	es_casado = (toupper(opcionSN) == 'S');
	
	return es_casado;
    }


};



int main(){
    
    //llamamos  a la clase
    
    LectorOpcion una_opcion;
    
    
    
    int renta_bruta;		//Declaramos las variables que guardan los datos introducidos por teclado
    double nueva_retencion;
    double antigua_retencion;
    double renta_neta;
     
    //solicitud de datos por teclado
    
    cout<<"\nIntroduzca su renta: ";
    cin>>renta_bruta;
    cout<<"\nintroduzca la retencion inicial: ";
    cin>>antigua_retencion;
    
    //asignamos los valores de la clase
    
    una_opcion.LeerAutonomo();
    una_opcion.LeerCivil();
    una_opcion.LeerPensionista();
    
    //la primera condicion es que sea autonomo, si lo es el 
    //programa solo realizara una modificacion en 
    //la retencion y se parara.
    
    if(una_opcion.LeerAutonomo()){
	
	nueva_retencion = antigua_retencion - antigua_retencion * 3 / 100;
    }
    else{		//si no es autonomo se pueden dar los siguientes casos 
	if(una_opcion.LeerPensionista())//si es pensionista se aumenta un 1% la retencion
		
	    nueva_retencion = antigua_retencion + antigua_retencion / 100;
	    
	else{			//si no es pensionista se le sube la retencion un 2%
				//y a demas pueden ocurrir los siguientes casos
            nueva_retencion = antigua_retencion + antigua_retencion * 2 / 100;
	    antigua_retencion = nueva_retencion;
		
	    if(renta_bruta < 20000){		//si su renta es inferior a 20000 
						//se le aumenta uun 6% la retencion
		nueva_retencion = antigua_retencion + antigua_retencion * 6 / 100;
	     }
	    else{	//si no (es decir es superior o igual a 20000 se dan
			//dos casos
		    
		if(una_opcion.LeerCivil()){	//si esta casado se incrementa la
					//retencion un 8%
		   nueva_retencion = antigua_retencion + antigua_retencion * 8 / 100;
			
		 }
		    
		else{		//si no esta casado se aumenta la retencioon
				//un 10%
		     nueva_retencion = antigua_retencion + antigua_retencion * 10 / 100;
		}
		    
	    }
	 }
}



    //finalmente empleamos la nueva retencion para calcular la renta neta 
	
    renta_neta = renta_bruta - renta_bruta * nueva_retencion / 100;  
    
    //salida de datos por pantalla
    
    cout<<"\nSu renta neta es: "<<renta_neta<<" euros\n\n";
    
    //system ("pause");
    
    return (0);
    
}