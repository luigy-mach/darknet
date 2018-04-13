
#ifndef QUEUE_H
#define QUEUE_H


#include <stdio.h>
#include <stdlib.h>

#include "mytracking_obj.h"

#include "mycommon.h"



typedef struct tracking_obj tracking_obj;

typedef struct mynode mynode;
typedef struct queue queue;


typedef struct point point;
typedef struct rectangle rectangle;


struct mynode{
  rectangle* data_rect;
  mynode* next;
};



void create_mynode_queue(mynode** pnode);
void free_mynode_queue(mynode** pnode);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


struct queue{
  mynode* front;
  mynode* rear;
  int limit;
};

void create_queue(queue** myqueue);
void free_queue(queue** myqueue);

void enqueue_rectangle(queue* myqueue, rectangle* rect);
void dequeue_rectangle(queue* myqueue);

void print_queue_rectagles(queue* myqueue, FILE* fp);

double eval_distanceTotal_queue(queue* myqueue);

#endif //end QUEUE_H
