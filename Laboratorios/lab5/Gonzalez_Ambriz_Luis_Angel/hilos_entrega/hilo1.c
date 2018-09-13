#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int num1 = 60, num2 = 12;
void * suma( void *arg );
void * resta( void *arg );
void * multi( void *arg );
void * divi( void *arg );

int main(){
	//Declaracion de los resultados de retorno
	int *res_suma, *res_resta, *res_multi, *res_divi;

	//Declaracion del hilo
	pthread_t tid_suma, tid_resta, tid_multi, tid_divi;

	//Creacion del hilo
	pthread_create( &tid_suma, NULL, suma, NULL );
	pthread_create( &tid_resta, NULL, resta, NULL );
	pthread_create( &tid_multi, NULL, multi, NULL );
	pthread_create( &tid_divi, NULL, divi, NULL );

	//Esperar al hilo
	pthread_join( tid_suma, (void **)&res_suma );
	pthread_join( tid_resta, (void **)&res_resta );
	pthread_join( tid_multi, (void **)&res_multi );
	pthread_join( tid_divi, (void **)&res_divi );

	//Imprimir resultados
	printf("La suma es: %d\n\n", *res_suma);
	printf("La resta es: %d\n\n", *res_resta);
	printf("La multiplicacion es: %d\n\n", *res_multi);
	printf("La division es: %d\n\n", *res_divi);

	return 0;
}

void * suma( void *arg){
	//Forma uno de declarar la variable que no sea local
	static int res;
	res = num1 + num2;

	//Cerrar hilo
	pthread_exit( (void *)&res );
}

void * resta( void *arg){
	//Forma uno de declarar la variable que no sea local
        static int res;
        res = num1 - num2;

	//Cerrar hilo
        pthread_exit( (void *)&res );
}

void * multi( void *arg){
	//Otra forma de hacerlo reservando memoria
        int *res = (int *)malloc( sizeof(int) );
       	*res = num1 * num2;

	//Cerrar hilo
        pthread_exit( (void *)res );
}

void * divi( void *arg){
	//Otra forma de hacerlo reservando memoria
        int *res = (int *)malloc( sizeof(int) );
        *res = num1 / num2;

	//Cerrar hilo
        pthread_exit( (void *)res );
}

