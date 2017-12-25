
#ifndef QUEUE_H
#define QUEUE_H


#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

typedef struct node node;


typedef struct{
  node* front;
  node* rear;
}queue;


#endif //end QUEUE_H
