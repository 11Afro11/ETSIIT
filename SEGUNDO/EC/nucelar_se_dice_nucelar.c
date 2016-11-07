#include <stdio.h>	// para printf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()/strlen()
#include <sys/time.h>	// para gettimeofday(), struct timeval

char password[]="nospmsiremoh\n";
int  passcode  = 2230;

void boom(){
	printf("                     __,-~~/~    `---.\n");
	printf("                   _/_,---(      ,    )\n");
	printf("               __ /        <    /   )  |___\n");
	printf("- ------===;;;'====------------------===;;;===----- -  -----\n");
	printf("                  |/  ------.------|--)---/\n");
	printf("                  (_ (   |  (     >    |)\n");
	printf("                   |_( _ <         >_>'\n");
	printf("                      ~ `-i' ::>|--\n");
	printf("                          I;|.|.|\n");
	printf("                         <|i::|i|`.\n");
	printf("                        (` ^'`-' ___)\n");
	printf("                       ***************\n");
	printf("                       *** BOOM!!! ***\n");
	printf("                       ***************\n");
	exit(-1);
}

void defused(){
	printf("          _ _,---._ \n");
	printf("       ,-','       `-.___ \n");
	printf("      /-;'               `._ \n");
	printf("     /`/          ._   _,'o ` \n");
	printf("    ( /`       _,--'`,','`. ) \n");
	printf("     |`      ,'o     `'    //` \n");
	printf("     |      `        /   ,--'""`-. \n");
	printf("     :       `_    _/ ,-'         `-._ \n");
	printf("      `        `--'  /                ) \n");
	printf("       `.  ``._    ,'     ________,',' \n");
	printf("         .--`     ,'  ,--` __`___,;' \n");
	printf("          ``.,-- ,' ,`_)--'  /`.,' \n");
	printf("           `( ;  | | )      (`-/ \n");
	printf("             `--'| |)       |-/ \n");
	printf("               | | |        | | \n");
	printf("               | | |,.,-.   | |_ \n");
	printf("               | `./ /   )---`  ) \n");
	printf("              _|  /    ,',   ,-' \n");
	printf("     -hrr-   ,'|_(    /-<._,' |--, \n");
	printf("             |    `--'---.     `/ ` \n");
	printf("             |          / `    /`  ` \n");
	printf("           ,-^---._     |  `  /  `  ` \n");
	printf("        ,-'        `----'   `/    `--`. \n");
	printf("       /            `              `   ` \n");
	printf("           *************************\n");
	printf("           *** bomba desactivada ***\n");
	printf("           *************************\n");
	exit(0);
}



void bomba(){
	printf("                  . . .                        \n");
	printf("                   )|/                         \n");
	printf("                 `--+--'                       \n");
	printf("                   /|(                         \n");
	printf("                  ' | '                        \n");
	printf("                    |                          \n");
	printf("                    |                          \n");
	printf("                ,--'#`--.                      \n");
	printf("                |#######|                      \n");
	printf("             _.-'#######`-._                   \n");
	printf("          ,-'###############`-.                \n");
	printf("        ,'#####################`,              \n");
	printf("       /#########################`             \n");
	printf("      |###########################|            \n");
	printf("     |#############################|           \n");
	printf("     |#############################|           \n");
	printf("     |#############################|           \n");
	printf("     |#############################|           \n");
	printf("      |###########################|            \n");
	printf("       `#########################/             \n");
	printf("        `.#####################,'              \n");
	printf("          `._###############_,'                \n");
	printf("             `--..#####..--'   \n");
	printf("\n\n");
}

void encriptado(char* solucion, int inicio, int fin){
	if(inicio < fin-1){
		char aux = solucion[inicio];
		solucion[inicio] = solucion[fin];
		solucion[fin] = aux;
		encriptado(solucion, inicio+1, fin-1);
	}
}

int codificado(int num){
	return num*2;
}

int main(){
#define SIZE 100
	char pass[SIZE];
	int  pasv = 0;
#define TLIM 50
	struct timeval tv1,tv2;	// gettimeofday() secs-usecs

	gettimeofday(&tv1,NULL);
	bomba();
	printf("Introduce la contrasenia: ");
	fgets(pass,SIZE,stdin);
	if(strlen(pass) >2)
		encriptado(pass, 0, strlen(pass) -2);

	printf("medida solve : %i\n",strlen(password));
	printf("medida dada : %i\n",strlen(pass));
	printf(password);
	printf(pass);
	if (strncmp(pass,password,strlen(password)))
	    boom();

	gettimeofday(&tv2,NULL);
	if (tv2.tv_sec - tv1.tv_sec > TLIM)
	    boom();

	printf("Introduce el codigo: ");
	scanf("%i",&pasv);
	pasv = codificado(pasv);
	if (pasv!=passcode) boom();

	gettimeofday(&tv1,NULL);
	if (tv1.tv_sec - tv2.tv_sec > TLIM)
	    boom();

	defused();
}
