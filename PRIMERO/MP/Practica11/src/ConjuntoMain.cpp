/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JAVIER FUENTES BARRAGAN
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 4
// EJERCICIO 7
//
// (Todos los apartados del Ejercicio 04-07)
//
// Ejercicio 04-07
//
/*********************************************************************/


#include "Conjunto.h"

using namespace std;


int main(void) 
{
	//..............................................

	Conjunto c; // constructor de cto. vacio
	PintaConjunto(c, "Conjunto c");
	cout << endl;

	Conjunto c1 (1); // constructor con un elemento
	PintaConjunto (c1, "Conjunto c1");

	//..............................................

	if (c1.Contiene(1)) 
		cout << "c1 Contiene 1" << endl;
	else 
		cout << "c1 NO Contiene 1" << endl;
	cout << endl;

	if (c1.Contiene(2)) 
		cout << "c1 Contiene 2" << endl;
	else 
		cout << "c1 NO Contiene 2" << endl;
	cout << endl;

	//..............................................

	Conjunto c2 = 2; // constructor con un elemento 
	PintaConjunto (c2, "Conjunto c2");

	if (c2.Contiene(1)) 
		cout << "c2 Contiene 1" << endl;
	else 
		cout << "c2 NO Contiene 1" << endl;
	cout << endl;

	if (c2.Contiene(2)) 
		cout << "c2 Contiene 2" << endl;
	else 
		cout << "c2 NO Contiene 2" << endl;
	cout << endl;

	//..............................................

	c1.Aniade (7);
	PintaConjunto (c1, "c1 tras aniadir 7");
	c1.Aniade (3);
	PintaConjunto (c1, "c1 tras aniadir 7 y 3");
	c1.Aniade (0);
	c1.Aniade (5);
	PintaConjunto (c1, "c1 tras aniadir 7, 3, 0 y 5");
	c1.Aniade (3);
	PintaConjunto (c1, "c1 tras intentar aniadir 3 de nuevo");	
	
	//..............................................

	c = c1; // Operador de asignacion

	PintaConjunto (c, "Conjunto c despues de c=c1");
	cout << endl;

	//..............................................

	// Constructor de copia

	Conjunto copia_c = c;

	PintaConjunto (copia_c, "Conjunto copia_c despues de copia_c=c");
	cout << endl;

	if (copia_c.EstaVacio())
		cout << "copia_c esta vacio\n";
	else 
		cout << "copia_c NO esta vacio\n";
	cout << endl;

	//..............................................

	// Adiciones y eliminaciones

	c1.Aniade (3); // Ya está
	PintaConjunto (c1, "c1 tras intentar aniadir 3 otra vez");

	c1.Aniade (0); // Ya está
	PintaConjunto (c1, "c1 tras intentar aniadir 0 otra vez");

	c1.Elimina (0); 
	PintaConjunto (c1, "c1 tras eliminar 0");

	c1.Elimina (3); 
	PintaConjunto (c1, "c1 tras eliminar 3");
	
	c1.Elimina (7); 
	PintaConjunto (c1, "c1 tras eliminar 7");

	c1.Elimina (7); // No está
	PintaConjunto (c1, "c1 tras eliminar 7 (ya no esta)");

	c1.Aniade (0); // Se vuelve a añadir el primero
	PintaConjunto (c1, "c1 tras aniadir 0");

	c1.Aniade (9); // Se añade el último
	PintaConjunto (c1, "c1 tras aniadir 9");

	//..............................................

	// Conjunto vacío

	Conjunto vacio;

	if (vacio.EstaVacio())
		cout << "vacio esta vacio\n";
	else 
		cout << "vacio NO esta vacio\n";
	cout << endl;

	if (copia_c.EstaVacio())
		cout << "copia_c esta vacio\n";
	else 
		cout << "copia_c NO esta vacio\n";
	cout << endl;


	copia_c = vacio;

	PintaConjunto (copia_c, "copia_c despues de copia_c = vacio");
	cout << endl;

	if (copia_c.EstaVacio())
		cout << "copia_c esta vacio\n";
	else 
		cout << "copia_c NO esta vacio\n";
	cout << endl;


	PintaConjunto (c1, "Conjunto c1");
	cout << endl;

	c1 = VACIO; // c1 = ConjuntoVacio();

	PintaConjunto (c1, "c1 despues de c1 = VACIO");
	cout << endl;

	if (c1.EstaVacio())
		cout << "c1 esta vacio\n";
	else 
		cout << "c1 NO esta vacio\n";
	cout << endl;

	//..............................................

	cout << endl; 
	cout << ".........................";
	cout << endl << endl; 


	/*******************************************************************************/

	cout << "Vamos a Sumar Conjunto:"<<endl;

	Conjunto suma;

	suma = c1 + copia_c;

	PintaConjunto (suma, "c1 + copia_c");

	cout << "Vamos a Sumar un dato:"<<endl;

	Conjunto suma_num;

	suma_num = c1 + 3;

	PintaConjunto (suma_num, "c1 + 3");

	cout << "Operador +=:"<<endl;

	c1 += suma;

	PintaConjunto (c1, "c1 +=suma");

	cout << "operado +=:"<<endl;

	c1 += 3;

	PintaConjunto (c1, "c1 += 3");

	cout << "Vamos a Restar c1s:"<<endl;

	Conjunto resta;

	resta = c1 - copia_c;

	PintaConjunto (resta, "c1 - copia_c");

	cout << "Vamos a Restar un dato:"<<endl;

	Conjunto resta_num;

	resta_num = c1 - 3;

	PintaConjunto (resta_num, "c1 - 3");

	cout << "Operador -=:"<<endl;

	c1 -= resta;

	PintaConjunto (c1, "c1 -=resta");

	cout << "operado -=:"<<endl;

	c1 -= 3;

	PintaConjunto (c1, "c1 -= 3");

	if(c1 == suma){
		cout <<"c1 igual a suma"<<endl;
	}

	if(c1 != suma){
		cout <<"c1 distinto a suma"<<endl;
	}

	if(c1 < resta){
		cout <<"c1 menor que resta"<<endl;
	}

	if(c1 > resta){
		cout <<"c1 mayor que resta"<<endl;
	}

	if(c1 <= suma){
		cout <<"c1 menor o igual que suma"<<endl;
	}

	if(c1 >= suma){
		cout <<"c1 mayor o igual que suma"<<endl;
	}


	
		
		

	return (0);
}
