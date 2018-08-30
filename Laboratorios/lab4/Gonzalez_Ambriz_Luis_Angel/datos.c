#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#define NUM_PROC 2


void procesoHIJO(int np);
void procesoPadre();
int main(int argc, char const *argv[])
{
	printf("Probando procesos ...\n");
	pid_t pid;
	int np;
	for( np=0;np <NUM_PROC;np++)
	{
		pid=fork();
			if(pid == -1)
			{
				perror("No se creo el procesos .. \n");
				exit(EXIT_FAILURE);
			}
			if( ! pid )
			{
				procesoHIJO(np);
			}
		
			
			
	}
	procesoPadre(np);
	return 0;


}

void procesoPadre()
{
			int np,estado;
			pid_t pid_hijo;
			printf("Proceso padre ejecutando con pid %d\n", getpid());
			for (np= 0; np < NUM_PROC; np++)
			{
				

				pid_hijo=wait(&estado);
				printf("procesos hijo %d termino con pid %d \n",estado>>8,pid_hijo);




			}



}

void procesoHIJO(int np)
{
	printf("procesos HIJO %d ejecutando con pid  %d\n",np,getpid());
	while(1);
	exit(np);
	
}