#include <stdio.h>
#include <math.h>
#include "defs.h"

void genera_seno( float seno[] )
{
	float f = 1000, fs = 45000;
	register int n;

	for( n = 0; n < MUESTRAS; n++ )
//	for( n = MUESTRAS; n != 0; n-- )
	{
		seno[n] = sinf( 2*M_PI*f*n/fs );
	}
}




