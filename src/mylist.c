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









void my_insert_list2_rect2(mynodelist* pnode, Rectangle* myrect, double threshold_rectangle, int number_frame){
  
  if(threshold_rectangle < myoverlap_rectangle(pnode->data_obj->bounding_box, myrect)){
     enqueue_rectangle( pnode->data_obj->queue_rectangles, myrect);
     pnode->data_obj->flag = number_frame % 2;

     return;
  }
  if(pnode->next == NULL){
    mynodelist* temp;
    create_mynodelist(&temp);

    tracking_obj* temp_tracking_obj;
    create_new_tracking_obj(&temp_tracking_obj);
    temp_tracking_obj->bounding_box = myrect;
    temp_tracking_obj->flag = number_frame % 2;
    
    temp->data_obj = temp_tracking_obj;
    pnode->next = temp;
    return;
  }
  my_insert_list2_rect2(pnode->next, myrect, threshold_rectangle,number_frame);
}




void my_insert_list_rect2(mylist* l, Rectangle* myrect, double threshold_rectangle,int number_frame){

  if(l->root == NULL){
    mynodelist* temp;
    create_mynodelist(&temp);

    tracking_obj* temp_tracking_obj;
    create_new_tracking_obj(&temp_tracking_obj);
    temp_tracking_obj->flag = number_frame % 2;

    temp_tracking_obj->bounding_box = myrect;

    temp->data_obj = temp_tracking_obj;
    l->root = temp;
    return;
  }

  my_insert_list2_rect2(l->root ,myrect, threshold_rectangle,number_frame);
}



void update_per2(mynodelist* pnode,int number_frame){
  if( pnode->data_obj->flag != (number_frame%2) ){
    ( pnode->data_obj->perdida)++;
  }
  if( pnode->next == NULL){
    return;
  }
  update_per2( pnode->next,number_frame);

}

void update_perdida(mylist* l, int number_frame){
  if(l->root==NULL){
    return;
  }
  update_per2(l->root,number_frame);
}






void limpiar_perdida(mylist* l){
  
  if( l->root == NULL ){
    return;
  }
  while(l->root!=NULL && l->root->data_obj->perdida >= LIMIT_PERDIDA  ){
        mynodelist* pnode = l->root;
        l->root = pnode->next;
        free(pnode);
  }
  
  if( l->root == NULL ){
    return;
  }

  
  mynodelist* pnode = l->root;        
  while( pnode->next!=NULL && pnode->next->data_obj->perdida >= LIMIT_PERDIDA ){
        mynodelist** ppnodeAvance = &(pnode->next);
        mynodelist* borrado = pnode->next;
        (*ppnodeAvance) = borrado->next;
        free(borrado);
        pnode = pnode->next;
  }  

  return;

}





/*
void limpiar_perdida(mylist* l){
  
  if( l->root == NULL ){
    printf("borrando2\n");
    return;
  }
  while(l->root!=NULL && l->root->data_obj->perdida >= LIMIT_PERDIDA  ){
        mynodelist* pnode = l->root;
        l->root = pnode->next;
        free(pnode);
        printf("borrando4\n");
  }
        printf("AAAAAAAAAAAAAAAAA\n");
  
  if( l->root == NULL ){
    printf("borrando5\n");
    return;
  }

  
  mynodelist* pnode = l->root;
        printf("AAAAAAAAAAAAAAAAA<<<<1\n");
  while( pnode->next->data_obj->perdida >= LIMIT_PERDIDA ){
        printf("AAAAAAAAAAAAAAAAA<<<<2\n");
        mynodelist** ppnodeAvance = &(pnode->next);
        mynodelist* borrado = pnode->next;
        (*ppnodeAvance) = borrado->next;
        free(borrado);
        printf("borrando6\n");
        pnode = pnode->next;
  }  
          printf("bbbbbbbbbbbbbbbb\n");

  return;

}


*/




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
