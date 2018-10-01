#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include "defs.h"
#include "procesamiento.h"
#include "archivos.h"

float *A, *B, *C;
float seno[MUESTRAS];
float hamming[MUESTRAS];

int main(){

	register int nh;
	int  *hilo, nhs[NUM_HILOS];
	

	//Declaracion del hilo
	pthread_t tids[NUM_HILOS];

	//Reservar memoria
	A = reservarMemoria2();
	B = reservarMemoria2();
	C = reservarMemoria2();

	//Llenar arreglos
	genera_seno(A);
	genera_hamming(B);

	//Imprimir los arreglos
	imprimirArreglo2(A);
	guarda_datos(A, "seno.dat");
	imprimirArreglo2(B);
	guarda_datos(B, "hamming.dat");

	//Creacion del hilo
	for(nh = 0; nh < NUM_HILOS; nh++){
		nhs[nh] = nh;
		pthread_create( &tids[nh], NULL, funHilo, (void *)&nhs[nh] );
	}

	//Esperar al hilo
	for(nh = 0; nh < NUM_HILOS; nh++){
		pthread_join( tids[nh], (void **)&hilo );
		printf("\n Terminando el hilo %d \n\n", *hilo);
	}

	imprimirArreglo2(C);
	guarda_datos(C, "resultado.dat");

	free(A);
	free(B);
	free(C);

	return 0;
}
