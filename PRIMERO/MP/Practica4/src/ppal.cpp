//*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2014-2015
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// ppal_1.cpp
//
/*********************************************************************/

#include <iostream>
#include "opers_1mod.h"
using namespace std;

/*********************************************************************/

int main (void)
{
   int num1, num2; 

   cout << "Introduce un numero: "; 
   cin >> num1; 
   cout << "Introduce otro numero: "; 
   cin >> num2; 

   cout << "La suma es = " << suma (num1, num2) << "\n"; 
   cout << "La resta es = " << resta (num1, num2) << "\n"; 
   cout << "La multiplicaci�n es = " << multiplica (num1, num2) << "\n"; 
   cout << "La divisi�n es = " << divide (num1, num2) << "\n"; 

   return (0);
}

/*********************************************************************/
 
