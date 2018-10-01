#ifndef PROC_H
#define PROC_H

void proceso_hijo( int np, int pipefd[] );
void proceso_padre( int pipefd[]  );

int * reservarMemoria( void );
void imprimirArreglo( int datos[] );
void llenarArreglo( int datos[] );

#endif
