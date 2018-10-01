#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "archivos.h"

void guarda_res(int productoPunto){
	FILE *ap_arch;
	ap_arch = fopen("PP.dat","w");

	if(!ap_arch){
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}

	fprintf(ap_arch, "%d \n", productoPunto);
	
	fclose(ap_arch);
}

void guarda_datos(int datos[], char *doc){
	FILE *ap_arch;
	register int n;
	ap_arch = fopen(doc,"w");

	if(!ap_arch){
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}

	for(n = 0;n < N; n++){
		fprintf(ap_arch, "%d \n", datos[n]);
	}

	fclose(ap_arch);
}

