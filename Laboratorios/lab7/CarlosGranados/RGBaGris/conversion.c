//conversion.c Para convertir una imagen de RGB a escala de grises

#include <stdio.h>
#include <stdlib.h>
#include "imagen.h"

int main(){
	
	bmpInfoHeader info;
	unsigned char *imagen;

	abrirBMP("../img/hoja.bmp", &info);
	displayInfo(&info);

	free(imagen);

	return 0;
}