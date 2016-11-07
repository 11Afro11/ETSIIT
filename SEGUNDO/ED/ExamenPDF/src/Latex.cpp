#include "Latex.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <istream>
using namespace std;

void Cabecera(ostream & os, string nombre){
	ifstream fin(nombre.c_str());
	if(!fin){
		cout << "no se pue"<<endl;
	}
	string texto;
	while(getline(fin,texto)){
		os << texto<<endl;
	}
	fin.clear();
}

void Enumerate(ostream & os, string nombre){
	ifstream fin(nombre.c_str());
	if(!fin){
		cout << "no se pue"<<endl;
	}
	string texto;
	getline(fin, texto);
	os << texto<<endl;
	fin.clear();
}

void Item(ostream & os, string nombre, string item){
	ifstream fin(nombre.c_str());
	if(!fin){
		cout << "no se pue"<<endl;
	}
	string texto;
	getline(fin, texto);
	os << texto;
	os << item << endl;
	fin.clear();
}