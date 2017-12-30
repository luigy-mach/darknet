#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <float.h>
#include <limits.h>
#include <time.h>

#include "tracking.h"


int max(int a, int b)
{
	if(a<b)
		return b;
	else return a;
}

int min(int a, int b)
{
	if(a<b)
		return a;
	else return b;
}



void myoverlap(Rectangle A, Rectangle B)
{
	int w1=fabs(A.bottomright.x-A.topleft.x);
	int h1=fabs(A.bottomright.y-A.topleft.y);
	int w2=fabs(B.bottomright.x-B.topleft.x);
	int h2=fabs(B.bottomright.y-B.topleft.y);


	float SA=w1*h1;
	float SB=w2*h2;

	float iLeft=max(A.topleft.x,B.topleft.x);
	float iRight=min(A.bottomright.x,B.bottomright.x);
	float iTop=max(A.topleft.y,B.topleft.y);
	float iBottom=min(A.bottomright.y,B.bottomright.y);

    float si = max(0, iRight - iLeft) * max(0, iBottom - iTop);
    
    float su=SA + SB -si;
    float myoverlap=si/su;
    printf("myoverlap es: %f \n",myoverlap);

}


