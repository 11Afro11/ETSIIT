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
// EJERCICIO 8
//
/*	

 Cread un programa que lea los datos fiscales da una persona, reajuste su renta bruta
según el criterio que se indica posteriormente e imprima su renta neta final.
• La renta bruta es la cantidad de dinero íntegra que el trabajador gana.
• renta neta es la cantidad que le queda después de quitarle el porcentaje de re-
tención fiscal, es decir:
Renta_neta = Renta_bruta - Renta_bruta * Retención / 100
Los datos a leer son:
• Si la persona es un trabajador autónomo o no
• Si es pensionista o no
• Estado civil
• Renta bruta (total de ingresos obtenidos)
La modificación se hará de la siguiente forma:
• Bajar un 3 % la retención fiscal a los autónomos
• Para los no autónomos:
– Se sube un 1 % la retención fiscal a todos los pensionistas
– Al resto de los trabajadores se le sube un 2 % la retención fiscal. Una vez
hecha esta subida lineal del 2 %, se le aplica (sobre el resultado anterior) las
siguientes subidas adicionales, dependiendo de su estado civil y niveles de
ingresos:
◦ Subir un 6 % la retención fiscal a las rentas de trabajo inferiores a 20.000
euros
◦ Subir un 8 % la retención fiscal a los casados con rentas de trabajo supe-
riores a 20.000 euros
◦ Subir un 10 % la retención fiscal a los solteros con rentas de trabajo su-
periores a 20.000 euros
Nota: Cuando se pide subir un x % la retención fiscal, significa que la nueva retención
fiscal será la antigua más el resultado de realizar el x % sobre la antigua retención.
Nueva_retención = Antigua_retención + Antigua_retención * x / 100
De forma análoga, si se le baja la retención, habrá que restar en vez de sumar.
Finalidad: Plantear una estructura condicional anidada. Dificultad Baja.



*/
/*********************************************************************/


#include <iostream>

using namespace std;

int main(){
    
    int renta_bruta;		//Declaramos las variables que guardan los datos introducidos por teclado
    char es_autonomo;		//la variables char guardaran las condiciones para que se realicen las
    char es_civil;		//operaciones
    char es_pensionista;
    double nueva_retencion;
    double antigua_retencion;
    double renta_neta;
     
    //solicitud de datos por teclado
    
    cout<<"\nIntroduzca su renta: ";
    cin>>renta_bruta;
    cout<<"\nintroduzca la retencion inicial: ";
    cin>>antigua_retencion;
    cout<<"\nEs usted autonomo [S/N]: ";
    cin>>es_autonomo;
    cout<<"\nCual es su estado civil [C/S]: ";
    cin>>es_civil;
    cout<<"\nEs usted pensionista [S/N]: ";
    cin>>es_pensionista;
    
    //la primera condicion es que sea autonomo, si lo es el 
    //programa solo realizara una modificacion en 
    //la retencion y se parara.
    
    if(es_autonomo = 'S'){
	
	nueva_retencion = antigua_retencion - antigua_retencion * 3 / 100;
    }
    else{		//si no es autonomo se pueden dar los siguientes casos 
	if(es_pensionista = 'S')//si es pensionista se aumenta un 1% la retencion
		
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
		    
		if(es_civil = 'C'){	//si esta casado se incrementa la
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