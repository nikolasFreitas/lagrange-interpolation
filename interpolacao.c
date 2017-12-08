#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	const int imax = 3; // Number of imax
	double dist[imax], height[imax], xNumber[imax], pX[imax], Li; // xNumber the X dot to the Y of INTERPOLATION graphic
	int i, imax, j, k;

	for(i=0; i<imax; i++) //Get the "X" and the "Y" given by user or a file
	{
		scanf("%lf %lf", &dist[i], &height[i]);
		printf("X[%d] = %lf \t Y[%d] = %lf\n", i, dist[i], i, height[i]);
		xNumber[i] = dist[i];
	}

	// Limpará os índices do array
	for ( i = 0; i < imax; i++ ) {
		pX[i] = 0;
	}

	for ( k = 0; k < imax; k++) {

		for(i=0; i < imax; i++)
		{
			Li=1;

			for( j = 0; j < imax; j++ )
			{
				if( i!=j )
				{
					Li = Li*(xNumber[k] - dist[j])/(dist[i]-dist[j]); //applying lagrange
				}
			}

			pX[k] = pX[k] + height[i] * Li; //Do the sumatory
		}

	}


}
