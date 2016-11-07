#include <iostream>
#include "ConjuntoPreguntas.h"
#include "Soluciones.h"
#include "Test.h"
#include <fstream>
#include <cstdlib>
#include <cctype>
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
  ifstream fin2(argv[2]);
  if (!fin2){
      cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
      return 0;
  }
  
  ConjuntoPreguntas CP;

  
  fin>>CP;
  Soluciones SC;


  fin2>>SC;
  cout<<"Leidas las preguntas. Numero Total : "<<CP.Size()<<endl;
  cout<<"Leidas las soluciones. Numero Total : "<<SC.Size()<<endl;
  
  
  // T.MuestraSoluciones();
  int aciertos,fallos;
  int aciertos_totales=0,fallos_totales=0,totales_p=0;
  bool salir = false;
  while(!salir){
    cout << endl << "Dame el numero de preguntas: ";
    int np;
    cin >> np;
    Test T(CP,np,SC); // Se genera el test de forma aleatoria con el conjunto de preguntas
    cout<<"Generado el test..."<<endl;
    aciertos = 0; fallos = 0;
    cout << "Constestaa las siguentes preguntas"<<endl;
    for(int i= 0; i < T.Size(); i++){
      cout << endl;
      cout<<"___________________________________________________"<<endl;
      cout<<i+1<<T[i]<<endl;
      cout<<"Inserta tu respuesta:";
      char resp;
      cin>>resp;
      char contes = T.MuestraSolucion(i);
      if (tolower(resp)==contes){
        cout<<"Correcta"<<endl;
        aciertos++;
      }
      else{
        cout<<"Fallo la contestacion correcta es : "<<contes<<endl;
        fallos++;
      }
    }
    cout<<"Aciertos: "<<aciertos<< " Fallos: "<<fallos<< " Porcentaje aciertos: "<<aciertos*100.0/np;
    aciertos_totales +=aciertos;
    fallos_totales +=fallos;
    totales_p+=np; //numero de pureguntas totales
    cout<<"¿Quieres hacer otro test?[S/N]"<<endl;
    char seguir_test;
    cin>>seguir_test;
    if (!(seguir_test=='S' || seguir_test=='s') ) salir=true;
   
  }
  cout<<"Resumen:"<<endl;
  cout<<"Numero de preguntas realizadas "<<totales_p<<endl;
  cout<<"Aciertos : "<<aciertos_totales<<endl;
  cout<<"Fallos: "<<fallos_totales<<endl;
  cout<<"Porcentaje aciertos:"<<aciertos_totales*100.0/totales_p<<endl<<endl;
 


/*  if (argc==2){
      cout<<T<<endl;
  }
  else {
    ofstream fout(argv[2]);
    if (!fout){
  cout<<"No puedo crear el fichero "<<argv[3]<<endl;
  return 0;
    }
    fout<<T;
  }*/
}  