

#ifndef TRACKING_OBJ_H
#define TRACKING_OBJ_H


#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "rect.h"


//extern struct mynode;
typedef struct queue queue;
//extern typedef struct mynode mynode;
//extern typedef struct queue queue;

typedef struct tracking_obj tracking_obj;

#define VACIOSTRING "vacio-string"


struct tracking_obj{
   char *name;
   int flag; //0-1
   int perdida; //maximo 10
   Rectangle* bounding_box;
   //agregar cola para la persistencia del recorrido.
   //Rectangle recorrido_bounding_box[10];
   queue* queue_rectangles;
};



void create_new_tracking_obj(tracking_obj** obj);


#endif //end TRACKING_OBJ_H
