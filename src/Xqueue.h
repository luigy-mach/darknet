
#ifndef QUEUE_H
#define QUEUE_H


#include<stdio.h>
#include<stdlib.h>

struct mynode_struct{
  int data;
  struct mynode_struct* next;
};

typedef struct mynode_struct mynode;


typedef struct{
  mynode* front;
  mynode* rear;
}queue;


#endif //end QUEUE_H
