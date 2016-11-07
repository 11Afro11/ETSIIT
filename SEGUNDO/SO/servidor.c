#include <sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include <unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>		//Needed for open
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

#include <time.h>

//Manejador de interrupciones
void mimanejador(int senal){
	pid_t borra = wait(NULL);
}

int main (int argc, char * argv[]){
	//comprobamos ell numero de argumentos
	if(argc != 2){
		perror("Se piden dos argumentos\n");
		exit(-1);
	}

	//declaramos el manejador de interrupciones para que reaccione al detectar un hijo
	struct sigaction est;
	est.sa_handler = mimanejador;
	if((sigaction(SIGCHLD, &est, NULL)) < 0){
		perror("no se ha podido capturar\n");
		exit(-1);
	}

	//declaramos los nombres de los fifos
	char nombrefifoe[20];
	char nombrefifos[20];

	//asignamos los nombres de los fifos
	sprintf(nombrefifoe, "%se", argv[1]);
	sprintf(nombrefifos, "%ss", argv[1]);

	umask(0);
	//creamos los fifos
	if((mkfifo(nombrefifoe, 0666)) < 0){
		perror("ha petao el fifo 1 loko\n");
		exit(-1);
	}

	if((mkfifo(nombrefifos, 0666)) < 0){
		perror("ha petao el fifo 2 loko\n");
		exit(-1);
	}

	int fs;
	int fd;
	int ft;

	//abrimos los fifos
	if( (fd=open(nombrefifoe,O_RDWR))<0) {
		perror("\nError en open");
		exit(-1);
	}

	if( (fs=open(nombrefifos,O_RDWR))<0) {
		perror("\nError en open");
		exit(-1);
	}

	//creamos el archivo de bloqueo
	if( (ft = open ("bloqueo", O_CREAT|O_RDWR|O_TRUNC,S_IRUSR|S_IWUSR))<0) {
		perror("\nError en open");
		exit(-1);
	}

	int k;
	pid_t pid;
	int fk;
	char fifo[20];

	//mientras podamos leer del fifo de entrada
	while((read(fd, &k, sizeof(int)) > 0)){
		//cremos un proceso hijo
		pid=fork(); 

		if(pid == 0)
		{	//si el pid es 0 sacamos el pid y creamos un fifo con ese pid en el nombre
			int p = getpid();
			sprintf(fifo, "fifo.%d", p);
			if((mkfifo(fifo, 0666)) < 0){
				perror("ha petao el fifo proxy loko\n");
				exit(-1);
			}
			//escribimos en el fifo de salida
			if((write(fs, &p, sizeof(int))) < 0){
				perror("no se pue\n");
				exit(-1);
			}
			//creamos un fichero
			if( (fk=open(fifo,O_RDONLY))<0) {
				perror("\nError en open");
				exit(-1);
			}
			// printf("amos a empesar\n");
			//duplicamos la ejecucion
			dup2(fk, STDIN_FILENO);
			//ejecutamos el proxy
			if((unlink(fifo)) < 0){
				perror("no se puede borrar el fifo\n");
			}
		  	if((execlp("./proxy", "proxy", 0))< 0){
		  		perror("no se ha podido\n");
		  		exit(-1);
		  	}

		}		
	}
}