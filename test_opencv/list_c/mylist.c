#include "mylist.h"



void create_mynodelist(mynodelist** n){
  mynodelist* temp = (mynodelist*)malloc(sizeof(mynodelist));
  temp->next = NULL;
  temp->data_obj = NULL;
  (*n)=temp;
  return;
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////

void create_mylist(mylist** l){
  mylist* temp = malloc(sizeof(mylist));
  temp->root = NULL;
  (*l) = temp;
}

/*
void my_insert_list2(mynodelist* pnode, mynodelist* temp){
  if(pnode->next == NULL){
     pnode->next = temp;
    return;
  }
  my_insert_list2(pnode->next,temp);
}

void my_insert_list(mylist* l, tracking_obj* pdato){
  mynodelist* temp;
  create_mynodelist(&temp);
  temp->data_obj=pdato;
  if(l->root == NULL){
    l->root = temp;
    return;
  }
  my_insert_list2(l->root,temp);
}
*/



void my_insert_list2_rect(mynodelist* pnode, Rectangle* myrect, double threshold_rectangle){
	
  if(threshold_rectangle < myoverlap_rectangle(pnode->data_obj->bounding_box, myrect)){
	   enqueue_rectangle( pnode->data_obj->queue_rectangles, myrect);
     return;
  }
  if(pnode->next == NULL){
    mynodelist* temp;
    create_mynodelist(&temp);

    tracking_obj* temp_tracking_obj;
    create_new_tracking_obj(&temp_tracking_obj);
    temp_tracking_obj->bounding_box = myrect;
    
    temp->data_obj = temp_tracking_obj;
    pnode->next = temp;
    return;
  }
  my_insert_list2_rect(pnode->next, myrect, threshold_rectangle);
}




void my_insert_list_rect(mylist* l, Rectangle* myrect, double threshold_rectangle){

  if(l->root == NULL){
    mynodelist* temp;
    create_mynodelist(&temp);

    tracking_obj* temp_tracking_obj;
    create_new_tracking_obj(&temp_tracking_obj);

    temp_tracking_obj->bounding_box = myrect;

    temp->data_obj = temp_tracking_obj;
    l->root = temp;
    return;
  }

  my_insert_list2_rect(l->root ,myrect, threshold_rectangle);
}













//void my_delete_list(mylist* l, tracking_obj* pdato){
//  mynodelist* temp = (mynodelist*)malloc(sizeof(mynodelist));
//    temp->data_obj = pdato;
//    temp->next = NULL;
//    temp->prev = NULL;
//  if(l->root == NULL){
//    l->root = temp;
//    return;
//  }
//  my_insert_list2(l->root,temp);
//}
