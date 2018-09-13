#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_HILOS 4
#define N 100


void * funHilo( void *arg );


int mayorArreglo( int datos[] );
int menorArreglo( int datos[] );
void ordenarArreglo( int datos[] );
int promedioArreglo( int datos[] );



int * reservarMemoria( void );
void imprimirArreglo( int datos[]);
void llenarArreglo( int datos[]);

pthread_mutex_t bloqueo;

int *datos;
int mayor, menor, promedio;

int main(){
	//Declaracion de variables
	register int nh;
	int *resultado, nhs[NUM_HILOS];

	datos = reservarMemoria();
	
	srand(getpid());

	llenarArreglo( datos );
	imprimirArreglo( datos );


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
	for( nh = 0; nh < NUM_HILOS; nh++){
		pthread_join( tids[nh], (void **)&resultado );
		//Imprimir resultados
		if( *resultado == 3 ){
			printf("\n\t >> Terminando el hilo %d ordenando <<\n\n", nh);
			imprimirArreglo( datos );
		}
		else{
			printf("\n\t >> Terminando el hilo %d con resultado %d <<\n\n", nh, *resultado);
		}
	}

	//imprimirArreglo( datos );

	//Destruyendo el bloqueo
	pthread_mutex_destroy( &bloqueo );
	return 0;
}

void * funHilo( void *arg ){
	int oper = *(int *)arg;
	switch( oper ){
		case 0:
			pthread_mutex_lock( &bloqueo );
			mayor = mayorArreglo( datos );
			pthread_mutex_unlock( &bloqueo );
			pthread_exit( &mayor );
		break;
		case 1:
			pthread_mutex_lock( &bloqueo );
			menor = menorArreglo( datos );
			pthread_mutex_unlock( &bloqueo );
			pthread_exit( &menor );
		break;
		case 2:
			pthread_mutex_lock( &bloqueo );
			promedio = promedioArreglo( datos );
			pthread_mutex_unlock( &bloqueo );
			pthread_exit( &promedio );
		break;
		case 3:
			pthread_mutex_lock( &bloqueo );
			ordenarArreglo( datos );
			pthread_mutex_unlock( &bloqueo );
			pthread_exit( arg );
		break;
		default:
			pthread_exit( arg );
		break;
	}
}

//---------------FUNCIONES--------------------------------

void ordenarArreglo( int datos[] ){
	register int n, m;
	int aux;

  	for ( n = 0; n < N; n++){
   		for ( m = 0; m < (N - n - 1); m++){
      			if (datos[m] > datos[m+1]){
       				aux = datos[m];
        			datos[m]   = datos[m+1];
        			datos[m+1] = aux;
      			}
    		}
  	}
}

int promedioArreglo( int datos[] ){
	register int n;
   	int suma = 0;
	int  promedio;

        for( n = 0; n < N; n++){
		suma += datos[n];
        }

	promedio = suma/N;
        return promedio;
}

int menorArreglo( int datos[] ){
        register int n;
        int menor;
        menor = datos[0];
        for( n = 0; n < N; n++){
                if( datos[n] < menor){
                        menor = datos[n];
                }
        }
        return menor;
}


int mayorArreglo( int datos[] ){
	register int n;
	int mayor;
	mayor = datos[0];

	for( n = 0; n < N; n++){
                if( datos[n] > mayor){
			mayor = datos[n];
		}
        }
	return mayor;
}

//--------------FAUNCIONES DE ARREGLO-----------------

void imprimirArreglo( int datos[] ){
	register int n;
        for( n = 0; n < N; n++){
		if( !(n % 16))
			printf("\n");
        	printf("%3d ", datos[n]);
        }
	printf("\n\n");
}

void llenarArreglo( int datos[] ){
        register int n;
        for( n = 0; n < N; n++){
                datos[n] = rand() % 255;
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

