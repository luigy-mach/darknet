#ifndef TRACKING_H
#define TRACKING_H
#include <stdio.h>
#include <math.h>

#include "queue.h"


typedef struct 
{
	int x;
	int y;
}Point;


typedef struct 
{
	Point topleft;
	Point bottomright; 
	
}Rectangle;


typedef struct{
   char *name;
   int x;
   int y;
   Rectangle bounding_box;
   //agregar cola para la persistencia del recorrido.
   //Rectangle recorrido_bounding_box[10];
} tracking_obj;





//int myxxx(int i);




#endif //end TRACKING_H

