#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "defs.h"
#include "procesamiento.h"

extern int *A, *B;
extern int pp;

extern pthread_mutex_t bloqueo;

// PRIMERA TECNICA, se puede hacer de la segunda tecnica tambien

void * funHilo( void *idh ){
	int nh = *(int *)idh;
	register int i;
	int sumaParcial = 0;

	//Calculando el inicio y fin de cada bloque
	int tamBloque = N / NUM_HILOS;
	int iniBloque = nh * tamBloque;
	int finBloque = iniBloque + tamBloque;

	for(i = iniBloque; i < finBloque; i++){
		sumaParcial += A[i] * B[i];
	}

	pthread_mutex_lock( &bloqueo );
	pp += sumaParcial;
	pthread_mutex_unlock( &bloqueo );

	pthread_exit( idh );
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

void imprimirArreglo( int datos[] ){
	register int n;
        for( n = 0; n < N; n++){
		if( !(n % 16))
			printf("\n");
        	printf("%5.d ", datos[n]);
        }
	printf("\n\n");
}

void llenarArreglo( int datos[] ){
        register int n;
        for( n = 0; n < N; n++){
                datos[n] = rand() % 255;
        }
}

