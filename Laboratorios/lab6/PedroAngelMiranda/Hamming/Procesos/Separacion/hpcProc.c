#include <stdio.h>
#include <math.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "defs.h"
#include "procesamiento.h"
#include "archivos.h"

float *A, *B, *C;
float seno[MUESTRAS];
float hamming[MUESTRAS];

int main(){

	//Declaracion de arreglo vidimencional
	pid_t pid;
	int pipefd[NUM_PROC][2], edo_pipe;
	register int np;

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

	for( np = 0; np < NUM_PROC; np++){
		edo_pipe = pipe(&pipefd[np][0]);

		if( edo_pipe == -1 ){
			perror("Error al crear el pipe\n");
			exit(EXIT_FAILURE);
		}

                pid = fork();

                if( pid == -1){
                        perror("Error al crear el proceso hijo\n");
                        exit(EXIT_FAILURE);
                }

                if( !pid ){
                        proceso_hijo( np, &pipefd[np][0] );
                }
        }

        proceso_padre( pipefd );

	imprimirArreglo2(C);
	guarda_datos(C, "resultado.dat");
	free(A);
	free(B);
	free(C);

	return 0;
}