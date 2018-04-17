

#ifndef TRACKING_OBJ_H
#define TRACKING_OBJ_H


#include "mytracking_obj.h"
//#include "mylist.h"
#include "myrect.h"
//#include "myqueue.h"


#include <math.h>
#include <stdio.h>

#include "mycommon.h"
//#define VACIOSTRING "vacio-string"
#include <gmodule.h>



//extern struct mynode;
typedef struct rectangle rectangle;
//extern typedef struct mynode mynode;
//extern typedef struct queue queue;

typedef struct tracking_obj tracking_obj;



struct tracking_obj{
   char *name;
   int   flagUsed; //0-1
   int   lostBound; //maximo 10

   double velocidad;
   double distancia;
   
   int pointcenterX;
   int pointcenterY;

   rectangle* rootRect;
   GQueue* queue_rectangles;
};



void myTrackingObj_create(tracking_obj** obj);
void myTrackingObj_init_create(tracking_obj* obj);

void myTrackingObj_updateRootRect(tracking_obj* obj, rectangle* rect1);

void myTrackingObj_addQueue(tracking_obj* obj, rectangle* rect1);


void myTrackingObj_FlagLost(tracking_obj* obj);

void myTrackingObj_updateAllFlags(GList* mylist);

void myTrackingObj_deleletBoundinBoxLost(GList* mylist);


void myTrackingObj_printListObjInFile(GList* mylist, FILE* fp);

void myTrackingObj_printTrackingObjInFile(tracking_obj* obj, FILE* fp);

void myTrackingObj_print2(tracking_obj* obj);

void myTrackingObj_updateFlagUsed(tracking_obj* obj);

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

void myTrackingObj_free(tracking_obj* obj);
//void myTrackingObj_free(tracking_obj** obj);


//void mytrackingObj_updatePointCenter(tracking_obj* obj, rectangle* rect1);
//
//double myTrackingObj_distancia_eu_2rect(rectangle* rect1, rectangle* rect2);





///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


int myfoo_GCompareFunc(void* a, void* b);



///////////////////////////////////////////////////////
///////////////////////////////////////////////////////






#endif //end TRACKING_OBJ_H
