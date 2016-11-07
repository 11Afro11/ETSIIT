#include <iostream>
#include "ConjuntoPreguntas.h"
#include "Test.h"
#include <fstream>
#include <cstdlib>
using namespace std;


int main(int argc, char * argv[]){
  if (argc > 3){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.Dime el nombre del fichero con las preguntas y posibles respuestas"<<endl;
      cout<<"3.-(Opcional) El nombre del fichero donde escribir el test"<<endl;
      return 0;
  }    
  
  ifstream fin(argv[1]);
  if (!fin){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  
  ConjuntoPreguntas CP;
  
  fin>>CP;
  cout<<"Leidas las preguntas. Numero Total : "<<CP.Size()<<endl;
  cout << endl << "Dame el numero de preguntas: ";
  int np;
  cin >> np;
  
  Test T(CP,np); // Se genera el test de forma aleatoria con el conjunto de preguntas
  cout<<"Generado el test..."<<endl;
  if (argc==1){
      cout<<T<<endl;
  }
  else {
    ofstream fout(argv[2]);
    if (!fout){
  cout<<"No puedo crear el fichero "<<argv[3]<<endl;
  return 0;
    }
    fout<<T;
  }
}  