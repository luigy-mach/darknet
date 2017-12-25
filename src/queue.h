
#ifndef QUEUE_H
#define QUEUE_H


#include<stdio.h>
#include<stdlib.h>

struct node_struct{
  int data;
  struct node_struct* next;
};

typedef struct node_struct node;


typedef struct{
  node* front;
  node* rear;
}queue;


#endif //end QUEUE_H
