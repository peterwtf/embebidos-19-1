#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "defs.h"
#include "procesamiento.h"

extern float *A, *B, *C;
extern float seno[MUESTRAS];
extern float hamming[MUESTRAS];

void * funHilo( void *idh ){
	int nh = *(int *)idh;
	register int i;

	//Calculando el inicio y fin de cada bloque

	for(i = nh; i < MUESTRAS; i += NUM_HILOS){
		C[i] = A[i] * B[i];
	}

	pthread_exit( idh );
}

float * reservarMemoria2( void ){
	float *mem;
	mem = (float *)malloc( sizeof(float)*MUESTRAS );
	if( !mem ){
		perror("Error al asignar memoria\n\n");
		exit(EXIT_FAILURE);
	}
	return mem;
}

void imprimirArreglo2( float datos[] ){
	register int n;
        for( n = 0; n < MUESTRAS; n++){
		if( !(n % 16))
			printf("\n");
        	printf("%0.3f ", datos[n]);
        }
	printf("\n\n");
}

void genera_seno(float seno[]){
	float f = 1000, fs = 45000;
	register int n;

	for(n = 0; n < MUESTRAS; n++){
		seno[n] = sinf(2*n*M_PI*f/fs);
	}
}

void genera_hamming(float hamming[]){
	register int n;

	for(n = 0; n < MUESTRAS; n++){
		hamming[n] = 0.54-(0.46*cosf(2*n*M_PI/(MUESTRAS-1)));
	}
}

