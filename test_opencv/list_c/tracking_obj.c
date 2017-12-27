

#include "tracking_obj.h"


void create_new_tracking_obj(tracking_obj** obj){
  tracking_obj* temp = (tracking_obj*)malloc(sizeof(tracking_obj));
                temp->name = VACIOSTRING;
                temp->flag = 0;
                temp->perdida = 0;
                temp->bounding_box = NULL;
                create_myRectangle(&(temp->bounding_box));
                temp->queue_rectangles = NULL;
                create_queue(&temp->queue_rectangles);
  (*obj)=temp;
  return;
}