#include "myqueue.h"



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




void print_queue_rectagles(queue* myqueue, char buffer[SIZEOF_BUFF])
{
  mynode* temp_rect = myqueue->front;
  int i = 0;
  while(temp_rect){
    char temp[100]  = {0};
    sprintf(temp,"     cola-(%d): (%d,%d) (%d,%d)\n", i
                                      ,temp_rect->data_rect->topleft.x 
                                      ,temp_rect->data_rect->topleft.y
                                      ,temp_rect->data_rect->bottomright.x
                                      ,temp_rect->data_rect->bottomright.y ); 
    strcat(buffer, temp);
    temp_rect = temp_rect->next;
    i++;
  }
  return;
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