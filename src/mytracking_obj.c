

#include "mytracking_obj.h"


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


void update_tracking_obj(tracking_obj* obj, Rectangle* rect1){
  if( obj->bounding_box == NULL ){
    printf("Error, puntero vacio, rect1.\n");
    return;
  }
  if( rect1 == NULL ){
    printf("Error, puntero vacio, rect2.\n");
    //create_myRectangle(&rect2);
    return;
  }

  obj->bounding_box->topleft.x     = rect1->topleft.x;
  obj->bounding_box->topleft.y     = rect1->topleft.y;
  obj->bounding_box->bottomright.x = rect1->bottomright.x;
  obj->bounding_box->bottomright.y = rect1->bottomright.y;

  return;
}