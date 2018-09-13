#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 64

int * reservarMemoria( void );
void imprimirArreglo( int datos[]);
void llenarArreglo( int datos[]);

void * mayorArreglo( void * arg );
void * menorArreglo( void * arg );

int main(){
	int *datos;
	datos = reservarMemoria();
	llenarArreglo( datos );
	imprimirArreglo( datos );
	printf("\n\n");

	//Declaracion de los resultados de retorno
	int *res_mayor, *res_menor;

	//Declaracion del hilo
	pthread_t tid_mayor, tid_menor;

	//Creacion del hilo
	pthread_create( &tid_mayor, NULL, mayorArreglo, (void *)datos );
	pthread_create( &tid_menor, NULL, menorArreglo, (void *)datos );

	//Esperar al hilo
	pthread_join( tid_mayor, (void **)&res_mayor );
	pthread_join( tid_menor, (void **)&res_menor );

	//Imprimir resultados
	printf("El numero mayor es: %d\n", *res_mayor);
	printf("El numero menor es: %d\n", *res_menor);

	return 0;
}


void * menorArreglo( void *arg ){
        register int n;
        static int menor;
	int *datos = (int *)arg;
        menor = datos[0];
        for( n = 0; n < N; n++){
                if( datos[n] < menor){
                        menor = datos[n];
                }
        }
       	pthread_exit( (void *)&menor );
}


void *  mayorArreglo( void *arg ){
	register int n;
	static int mayor;
	int *datos = (int *)arg;
	mayor = datos[0];

	for( n = 0; n < N; n++){
                if( datos[n] > mayor){
			mayor = datos[n];
		}
        }
       	pthread_exit( (void *)&mayor );
}

void imprimirArreglo( int datos[] ){
	register int n;
        for( n = 0; n < N; n++){
		if( !(n % 16))
			printf("\n");
        	printf("%4.d ", datos[n]);
        }
	printf("\n");
}

void llenarArreglo( int datos[] ){
        register int n;
        for( n = 0; n < N; n++){
                datos[n] = rand() % 4096;
        }
}

int * reservarMemoria( void ){
	int *mem;
	mem = (int *)malloc( sizeof(int)*N );
	if( !mem ){
		perror("Error al asignar memoria\n\n");
		exit(EXIT_FAILURE);
	}
	return mem;
}
