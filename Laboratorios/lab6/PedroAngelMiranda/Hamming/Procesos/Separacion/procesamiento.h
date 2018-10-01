#ifndef PROC_H
#define PROC_H

void proceso_hijo( int np, int pipefd[] );
void proceso_padre( int pipefd[NUM_PROC][2]  );
float * reservarMemoria2( void );
void imprimirArreglo2( float datos[] );
void genera_seno(float seno[]);
void genera_hamming(float hamming[]);

#endif
