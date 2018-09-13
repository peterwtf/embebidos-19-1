#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_HILOS 4
#define N 64

void * funHilo( void *arg );
int contador;

pthread_mutex_t bloqueo;

int main(){
	//Declaracion de variables
	int nh, nh2, *hilo, nhs[NUM_HILOS];

	contador = 0;

	//Declaracion del hilo
	pthread_t tids[NUM_HILOS];

	//Inicializar el bloqueo
	pthread_mutex_init( &bloqueo, NULL );

	//Creacion del hilo
	for(nh = 0; nh < NUM_HILOS; nh++){
		nhs[nh] = nh;
		pthread_create( &tids[nh], NULL, funHilo, (void *)&nhs[nh] );
	}

	//Esperar al hilo
	for( nh2 = 0; nh2 < NUM_HILOS; nh2++){
		pthread_join( tids[nh2], (void **)&hilo );
		//Imprimir resultados
		printf("\n\t >> Terminando el hilo %d <<\n\n", *hilo);
	}

	//Destruyendo el bloqueo
	pthread_mutex_destroy( &bloqueo );
	return 0;
}

void * funHilo( void *arg ){
	register int i = 0;

	//Region critica con MUTEX (mecanismo de sincronización)
	pthread_mutex_lock( &bloqueo );
	contador++;

	printf("Hilo en ejecucion con contador en %d\n", contador);

	//Generando un retardo como un sleep
	while( (--i) );

	printf("Hilo finalizado con contador en %d \n",contador);

	pthread_mutex_unlock( &bloqueo );
	pthread_exit( arg );
}


