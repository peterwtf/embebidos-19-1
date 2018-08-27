#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
	float num1=23 ,num2=12 ,suma ,resta;
	printf("Probando procesos ...\n");
	pid_t pid;
	pid=fork();

	if( ! pid )
	{
		printf("Soy hijo ejecutando con pid = %d\n",getpid());
		suma=num1+num2;
		printf("La suma es =%f\n",suma);
		sleep(12);
		exit(0);
	}
	else 
	{
		//sleep(5);
		wait(getpid);
		printf("Soy padre ejecutando con pid = %d\n",getppid());
		resta=num1-num2;
		printf("La resta es =%f\n",resta);
		exit(0);
	}
	return 0;


}