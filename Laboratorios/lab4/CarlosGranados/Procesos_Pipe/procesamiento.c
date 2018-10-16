#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "defs.h"

int mayorArreglo(int *datos){
	register int i , mayor;

	mayor = datos[0];

	for(i = 1; i < N; i++){
		if(datos[i] > mayor)
			mayor = datos[i];
	}

	return mayor;
}

int menorArreglo(int *datos){
	register int i , menor;

	menor = datos[0];

	for(i = 1; i < N; i++){
		if(datos[i] < menor)
			menor = datos[i];
	}

	return menor;
}

int promedioArreglo(int *datos){
	register int i, suma;
	int prom;
	suma = 0;

	for(i = 0; i < N; i++){
		suma = suma + datos[i];
	}

	prom = suma/N;

	return prom;
}

void ordenaArreglo(int *datos){
	register int i, j, menor;
	int temp;

	for (i = 0; i < N ; i++){

		menor = i;

		for (j = i + 1; j < N; j++){
			if(datos[j] < datos[menor])
				menor = j;
		}

		temp = datos[i];
		datos[i] = datos[menor];
		datos[menor] = temp;
	}

}