#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "defs.h"
#include "procesamiento.h"

extern int *A, *B;
extern int pp;

extern pthread_mutex_t bloqueo;

void proceso_hijo( int np, int pipefd[] ){

	register int i;

	printf("Proceso hijo %d con pid %d  \n\n", np, getpid());

	close( pipefd[0] );

	for( i = np; i < N; i+= NUM_PROC){
		pp += A[i] * B[i];
	}

	write( pipefd[1], &pp, sizeof(int) );
	close(pipefd[1]);
	exit( np );
}

void proceso_padre( int pipefd[] ){
	register int np;
        int pid, proc;
	int sumaParcial;

        printf("Proceso padre con pid %d\n", getpid());
	close( pipefd[1] );

	for( np = 0; np < NUM_PROC; np++){

                pid = wait( &proc );
		proc = proc >> 8;

		read( pipefd[0], &sumaParcial , sizeof(int) );
		pp += sumaParcial;

		printf("Proceso hijo %d terminado, con pid %d\n\n", proc, pid);

	}
	close( pipefd[0] );
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
