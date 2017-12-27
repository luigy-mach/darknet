
#ifndef QUEUE_H
#define QUEUE_H


#include <stdio.h>
#include <stdlib.h>

#include "tracking_obj.h"


#define LIMIT_QUEUE 10


//struct tracking_obj;	
typedef struct tracking_obj tracking_obj;

typedef struct mynode mynode;
typedef struct queue queue;


typedef struct Point Point;
typedef struct Rectangle Rectangle;


struct mynode{
  Rectangle* data_rect;
  mynode* next;
};



struct queue{
  mynode* front;
  mynode* rear;
  int limit;
};




void create_queue(queue** myqueue);
void create_mynode_queue(mynode** pnode);
void enqueue_rectangle(queue* myqueue, Rectangle* rect);
void dequeue_rectangle(queue* myqueue);


#endif //end QUEUE_H
