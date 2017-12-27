#include "queue.h"



void create_queue(queue** myqueue){
    queue* temp=malloc(sizeof(queue));
           temp->front=NULL;
           temp->rear=NULL;
           temp->limit=0;
    *myqueue = temp;
    return;
}

 void create_mynode_queue(mynode** pnode){
  mynode* temp = (mynode*)malloc(sizeof(mynode));
          temp->data_rect = NULL; 
          temp->next = NULL;
  (*pnode) = temp;
  return;
 }



void enqueue_rectangle(queue* myqueue, Rectangle* rect){
  mynode* temp = NULL;
  create_mynode_queue(&temp);
  temp->data_rect = rect; 

  if(myqueue->front == NULL && myqueue->rear == NULL){
    myqueue->front = myqueue->rear = temp;
    myqueue->limit++;
    return;
  }
  if( myqueue->limit > LIMIT_QUEUE ){
      dequeue_rectangle(myqueue);
      printf("borrando \n");
  }
  myqueue->rear->next = temp;
  myqueue->rear = temp;
  myqueue->limit++;
  return;
}


void dequeue_rectangle(queue* myqueue) {
  mynode* temp = myqueue->front;
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
  myqueue->limit--;
}



/*

void enqueue(queue* myqueue, int x){
  mynode* temp = (mynode*)malloc(sizeof(mynode));
  //temp->data = x; 
  temp->next = NULL;
  if(myqueue->front == NULL && myqueue->rear == NULL){
    myqueue->front = myqueue->rear = temp;
    return;
  }
  myqueue->rear->next = temp;
  myqueue->rear = temp;
}


void dequeue(queue* myqueue) {
  mynode* temp = myqueue->front;
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

*/