

#include "Verbose.h"


bool Verbose(int argc, char **argv, int &devuelve){
	
	devuelve = 0;

	if (argc > 2) {
		cerr << "Error:    Demasiados parametros." << endl;
		cerr << "Formato:  " << argv[0] << " [-v]" << endl;
		devuelve = 1; 	
	}
	
	bool verbose = false;	
	
	if (argc==2) {
	
		if (strcmp(argv[1],"-v")) {
			cerr << "Error:    argumento incorrecto." << endl;
			cerr << "Formato:  " << argv[0] << " [-v]" << endl;
			devuelve = 2; 		
		}
		else verbose = true;
	}

	return verbose;
}