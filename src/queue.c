#include "queue.h"



void start_queue(queue* myqueue){
    myqueue->front=NULL;
    myqueue->rear=NULL;
    return;
}



void enqueue(queue* myqueue, int x){
  node* temp = (node*)malloc(sizeof(node));
  temp->data = x; 
  temp->next = NULL;
  if(myqueue->front == NULL && myqueue->rear == NULL){
    myqueue->front = myqueue->rear = temp;
    return;
  }
  myqueue->rear->next = temp;
  myqueue->rear = temp;
}


void dequeue(queue* myqueue) {
  node* temp = myqueue->front;
  if(myqueue->front == NULL){
    printf("Queue is Empty\n");
    return;
  }
  if(myqueue->front == myqueue->rear){
    myqueue->front = myqueue->rear = NULL;
  }else{
    myqueue->front = myqueue->front->next;
  }
  free(temp);
}



int front(queue* myqueue){
  if(myqueue->front == NULL) {
    printf("Queue is empty\n");
    return;
  }
  return myqueue->front->data;
}

void print(queue* myqueue) {
  node* temp = myqueue->front;
  while(temp != NULL) {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

