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
// EJERCICIO 27
//
/*	
 Una empresa quiere gestionar las nóminas de sus empleados. El cómputo de la nó-
mina se realiza en base a los siguientes criterios:
a) Hay cuatro tipos de categorías laborales: Operario, Base, Administrativo y Direc-
tivo.
b) Se parte de un salario base que depende de la antigüedad del trabajador y de
su categoría laboral. Para la categoría Operario, el salario base es de 900 euros,
1100 el puesto Base, 1200 los Administrativos y 2000 los Directivos. Dicho salario
base se incrementa con un tanto por ciento igual al número de años trabajados.
c) Los trabajadores tienen complementos en su nómina por el número de horas
extraordinarias trabajadas. La hora se paga distinta según la categoría: 16 euros
por hora para los operarios, 23 para el puesto Base, 25 los Administrativos y 30
los Directivos. Además, al complemento que sale al computar el número de horas
extraordinarias, se le aplica una subida con un tanto por ciento igual al número
de años trabajados.
Se pide diseñar la interfaz de una clase (también hay que incluir los datos miembro
privados) para poder trabajar con esta información. No se pide implementar la clase,
únicamente determinar la interfaz.



*/
/*********************************************************************/
#include <iostream>

using namespace std;

//declaramos la clase Nomina

class Nomina{
private:
    
    //declaramos la variables del metodo privado
    
    double operario,base,administrativo,directivo;
    
    
public:
    
    //declaramos un constructor
    
    Nomina(){
	operario = 900;
	base = 1100;
	administrativo = 1200; 
	directivo = 2000;
    }
    
    //declaramos los metodos que devuelven las variables
    
    double GetOperario(){
	return operario;
    }
    
    double GetBase(){
	return base;
    }
    
    double GetAdministrativo(){
	return administrativo;
    }
    
    double GetDirectivo(){
	return directivo;
    }
    
    //metodo que aumente el salario en funcion del porcentaje
    
    Nomina Porcentaje(double porciento){
	Nomina porcentaje;
	
	porcentaje.operario = operario + ((operario * porciento) / 100);
	porcentaje.base = base + ((base * porciento)/ 100);
	porcentaje.administrativo = administrativo + ((administrativo * porciento) / 100);
	porcentaje.directivo = directivo + ((directivo * porciento) / 100);
	
	return porcentaje;
    }
    
    //metodo que aumenta el salario en funcion de las horas
    
    Nomina Incrementa(double horas){
	Nomina incrementa, porcentaje;
	
	incrementa.operario = porcentaje.operario + 16 * horas;
	incrementa.base = porcentaje.base + 23 * horas;
	incrementa.administrativo = porcentaje.administrativo + 25 * horas;
	incrementa.directivo = porcentaje.directivo + 30 * horas;
	
	return incrementa;
    }
    
};

int main(){
    
    //daclaramos la clase  ne la funcion
    
    Nomina una_nomina, incrementa, porcentaje;
    
    //declaramos las variables de la funcion
    
    double porciento, horas;
    
    //solicitamos los datos por pantalla
    
    cout << "\n\nDame el porcentaje: ";
    cin >> porciento;
    
    cout << "\n\nHoras extra: ";
    cin >> horas;
    
    //asignamos valores a las variables de la clase
    
    porcentaje = una_nomina.Porcentaje(porciento);
    
    incrementa = una_nomina.Incrementa(horas);
    
    //salida de datos por pantalla
    
    cout << "\n\nEl operario cobrara: "<<incrementa.GetOperario()<<"\n";
    cout << "\n\nEl trabajador base cobrara: "<<incrementa.GetBase()<<"\n";
    cout << "\n\nEl administrativo cobrara: "<<incrementa.GetAdministrativo()<<"\n";
    cout << "\n\nEl directivo cobrara: "<<incrementa.GetDirectivo()<<"\n\n";
    
    return(0);
    
}