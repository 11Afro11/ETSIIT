#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h> // Funciones para poder llamar sleep()
#include "mpi.h"


using namespace std;

#define soltar 	0
#define coger 	1

void Filosofo(int id, int nprocesos)
{
	int izq = (id + 1) % nprocesos;
	int der = (id + nprocesos - 1) % nprocesos;
	while(true){
		if(id == 0){
			cout << "Filosofo " << id << " coge el tenedor derecho."<<der << endl;
			MPI_Ssend(NULL, 0, MPI_INT, der, coger, MPI_COMM_WORLD);

			cout << "Filosofo " << id << " solicita tenedor izquierdo. " << izq << endl;
			MPI_Ssend(NULL, 0, MPI_INT, izq, coger, MPI_COMM_WORLD);
		}
		else{
			cout << "Filosofo " << id << " solicita tenedor izquierdo. " << izq << endl;
			MPI_Ssend(NULL, 0, MPI_INT, izq, coger, MPI_COMM_WORLD);

			cout << "Filosofo " << id << " coge el tenedor derecho."<<der << endl;
			MPI_Ssend(NULL, 0, MPI_INT, der, coger, MPI_COMM_WORLD);
		}


		cout << "Filosofo "<< id << " COMIENDO"<<endl;
		sleep((rand()%3)+1);

		cout << "Filosofo "<< id << "suelta el tenedor izquierdo"<< endl;
		MPI_Ssend(NULL, 0, MPI_INT, izq, soltar, MPI_COMM_WORLD);

		cout << "Filosofo " << id << " suelta tenedor derecho. " << der << endl;
        MPI_Ssend(NULL, 0, MPI_INT, der, soltar, MPI_COMM_WORLD);

        cout << "Filosofo " << id << " PENSANDO" << endl;
        sleep((rand()%3)+1);
    }
}

void Tenedor(int id, int nprocesos)
{
	int buf, Filo;
    MPI_Status status;
    while (true)
    {
        // Espera un peticion desde cualquier filosofo vecino ...
        MPI_Recv(&buf, 1, MPI_INT, MPI_ANY_SOURCE, coger, MPI_COMM_WORLD, &status);
 
        // Recibe la peticion del filosofo ...
        Filo=status.MPI_SOURCE; // Obtiene el rank del filosofo
        cout << "Ten. " << id << " recibe peticion. de " << Filo << endl;
 
        // Espera a que el filosofo suelte el tenedor...
        MPI_Recv(&Filo, 1, MPI_INT, Filo, soltar, MPI_COMM_WORLD, &status);
        cout << "Ten. " << id << " recibe liberacion. de " << Filo << endl;
    }
}

int main(int argc, char ** argv)
{
	int rank,size;
	srand(time(0));
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(size != 10){
		if(rank == 0)
			cout << "El numero de procesos debe deser 10\n";
		MPI_Finalize();
		return 0;
	}
	if(rank%2==0)
		Filosofo(rank,size);
	else 
		Tenedor(rank,size);

	MPI_Finalize();

	return 0;
}