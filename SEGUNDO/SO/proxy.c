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
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//Funcion que bloquea los procesos

void Bloqueo(int fd)
{
    struct flock cerrojo;
    cerrojo.l_type =F_WRLCK;
    cerrojo.l_whence =SEEK_SET;
    cerrojo.l_start =0;
    cerrojo.l_len =0;


    if(fcntl(fd, F_SETLKW, &cerrojo) < 0) perror("   "), exit(1);
    getchar();

}

//funcion que desbloquea los procesos
void Desbloqueo(int fd)
{
    struct flock cerrojo;

    cerrojo.l_type = F_UNLCK;
    cerrojo.l_whence =SEEK_SET;
    cerrojo.l_start =0;
    cerrojo.l_len =0;


    if(fcntl(fd, F_SETLKW, &cerrojo) < 0) perror("   "), exit(1);
    getchar();
}

int main (int argc, char * argv[]){
	//declaramos el buffer en el que se escribira 
	char buffer[1024];
	int ft;
	//vamos a declara los archivos temporales en los que se almacenara la salida de clientes
	char proxy[20];
	FILE *tmp = tmpfile();
	int p = getpid();
	/*sprintf(tmp, "tmp.%d", p);
	// printf("He empesado\n");
	if( (ft = open (tmp, O_CREAT|O_RDWR|O_TRUNC,S_IRUSR|S_IWUSR))<0) {
		perror("\nError en open");
		exit(-1);
	}*/
	int leido;
	//leemos de la entrada estandar
	while((leido = read(STDIN_FILENO, &buffer, 1024)) > 0){
		if((fwrite(buffer, sizeof(char), leido, tmp)) < 0){
			perror("no se pue\n");
			exit(-1);
		}
	}

	//abrimos el archivo de bloqueo
	int dbloqueo;
	if((dbloqueo = open("bloqueo", O_RDWR)) < 0){
		perror("no se pue abrir\n");
		exit(-1);
	}

	int uno;
	//volvemos al principio del archivo para poder mostrarlo
	rewind(tmp);
	//nos bloqueamos
	Bloqueo(dbloqueo);

	/*struct flock cerrojo1;
    cerrojo1.l_type =F_WRLCK;
    cerrojo1.l_whence =SEEK_SET;
    cerrojo1.l_start =0;
    cerrojo1.l_len =0;*/


    /*if(fcntl(dbloqueo, F_SETLKW, &cerrojo1) < 0) perror("   "), exit(1);
    getchar();*/
	
	
	//mostramos en la salida estandar lo que se en
	/*while((uno = read(ft, &buffer, 1024)) != 0){
		if((write(STDOUT_FILENO, &buffer, uno)) < 0){
			perror("no se pue\n");
			exit(-1);
		}
	}*/

	while(!feof(tmp)){
		uno = fread(buffer, sizeof(char), 1024, tmp);
		if((write(STDOUT_FILENO, &buffer, uno)) < 0){
			perror("no se pue\n");
			exit(-1);
		}
	}

	//desbloqueamos el archivo de bloqueo
	Desbloqueo(dbloqueo);

	/*struct flock cerrojo2;

    cerrojo2.l_type = F_UNLCK;
    cerrojo2.l_whence =SEEK_SET;
    cerrojo2.l_start =0;
    cerrojo2.l_len =0;*/

/*
    if(fcntl(dbloqueo, F_SETLKW, &cerrojo2) < 0) perror("   "), exit(1);
    getchar();*/

    sprintf(proxy,"fifo.%d",getpid());
	unlink(proxy);
	fclose(tmp);

}