#include<signal.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 

void ISRsw (int sig);
int main () {
if (signal(SIGINT,*ISRsw)== SIG_ERR)
{
	perror ("Error al crear el ISR");
	exit(EXIT_FAILURE);
}
if (signal(SIGTERM,*ISRsw)== SIG_ERR)
{
	perror ("Error al crear el ISR");
	exit(EXIT_FAILURE);
}
printf("señal ejecutada \n");
while(1) pause ();
return 0;
}

void ISRsw ( int sig){
	if( sig==SIGINT)
	{
		printf("señal SIGINT detectada, no voy a terminar\n");
	}
	else if( sig==SIGTERM)
	{
		printf("señal SIGTERM detectada, no voy a terminar\n");
	}
}