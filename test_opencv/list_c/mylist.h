

#ifndef MYLIST_H
#define MYLIST_H


#include<stdio.h>
#include<stdlib.h>

#include "tracking_obj.h"
#include "queue.h"
#include "rect.h"


typedef struct mynodelist mynodelist;
typedef struct tracking_obj tracking_obj;

typedef struct Point Point;
typedef struct Rectangle Rectangle;


typedef struct mylist mylist;



struct mynodelist{
       tracking_obj* data_obj;
       mynodelist* next;
  //struct mynodelist* prev;
};

struct mylist{
  mynodelist* root;
};


//struct mylist_t{
//  mynodelist* root;
//  int x;
//};
//typedef struct mylist_t mylist;








#endif //end MYLIST_H
