#include "mytracking_obj.h"

void myTrackingObj_create(tracking_obj** obj){
  tracking_obj* temp = (tracking_obj*)malloc(sizeof(tracking_obj));
  myTrackingObj_init_create(temp);
  (*obj)=temp;
  return;
}


void myTrackingObj_init_create(tracking_obj* obj){
  obj->name         = VACIOSTRING;
  obj->flagUsed     = 0;
  obj->lostBound    = 0;
  obj->velocidad    = 0;
  obj->distancia    = 0.0;
  obj->pointcenterX = 0;
  obj->pointcenterY = 0;
  obj->rootRect     = NULL;
  obj->queue_rectangles = NULL;

  myRectangle_create( &(obj->rootRect) );
  obj->queue_rectangles = g_queue_new();
  
  return;
}


void myTrackingObj_free(tracking_obj* obj){
  free( obj->name );
  myRectangle_free( obj->rootRect );
  g_queue_free_full (obj->queue_rectangles, &myTrackingObj_free);
  free( obj );
  obj = NULL;
  return;
}

//void myTrackingObj_free(tracking_obj** obj){
//  free( (*obj)->name );
//  myRectangle_free( &((*obj)->rootRect) );
//  //g_queue_free_full (obj->queue_rectangles, &myTrackingObj_free);
//  free( (*obj) );
//  (*obj) = NULL;
//  return;
//}




void myTrackingObj_updateRootRect(tracking_obj* obj, rectangle* rect1){
  if( obj->rootRect == NULL ){
    printf("Error, puntero vacio, rect1.\n");
    return;
  }
  if( rect1 == NULL ){
    printf("Error, puntero vacio, rect2.\n");
    //myRectangle_create(&rect2);
    return;
  }

  obj->rootRect->topleft->x     = rect1->topleft->x;
  obj->rootRect->topleft->y     = rect1->topleft->y;
  obj->rootRect->bottomright->x = rect1->bottomright->x;
  obj->rootRect->bottomright->y = rect1->bottomright->y;

  return;
}



void myTrackingObj_addQueue(tracking_obj* obj, rectangle* rect1){
  if( obj->rootRect == NULL ){
    printf("Error, puntero vacio, rect1.\n");
    return;
  }
  if( rect1 == NULL ){
    printf("Error, puntero vacio, rect2.\n");
    //myRectangle_create(&rect2);
    return;
  }
  myTrackingObj_updateRootRect(obj,rect1);

  int tam_queue = g_queue_get_length(obj->queue_rectangles);

  if( tam_queue!=0 ){
    g_queue_push_head( obj->queue_rectangles, rect1 );

    if( LIMIT_QUEUE <= tam_queue ){
      rectangle* rect_temp = g_queue_pop_tail( obj->queue_rectangles );
      //myRectangle_free( &rect_temp );
      myRectangle_free( rect_temp );
    }
    myTrackingObj_updateFlag(obj);
  }else{
    g_queue_push_head( obj->queue_rectangles, rect1 );
  } 

  return;
}





void myTrackingObj_updateFlag(tracking_obj* obj){
  obj->flagUsed = (obj->flagUsed+1)%2; 
  return;
}


void myTrackingObj_updateAllFlags(GList* mylist){
  int tam = g_list_length (mylist);
  int i;
  GList* pfisrt = NULL;
  pfisrt = g_list_first (mylist);
  while(pfisrt){
    if( ((tracking_obj*)(pfisrt->data))->flagUsed == 0 ){
      ((tracking_obj*)(pfisrt->data))->lostBound++;   
    }
    if( ((tracking_obj*)(pfisrt->data))->flagUsed == 1 ){
      ((tracking_obj*)(pfisrt->data))->flagUsed  = 0;   
      ((tracking_obj*)(pfisrt->data))->lostBound = 0;
    }
    pfisrt = pfisrt->next;      
  }  
  return;
}


void myTrackingObj_deleletBoundinBoxLost(GList* mylist){
  if(mylist==NULL){
    printf("Error: lista vacia \n");
    return;
  }
  
  int tam = g_list_length (mylist);
  int i;
  //LIMIT_QUEUE
  GList* pfisrt = NULL;
  pfisrt = g_list_first (mylist);
  //myTrackingObj_print( (tracking_obj*)(pfisrt->data) );
  while(pfisrt){
  printf("Error: lista vacia 11\n");
    if( ((tracking_obj*)(pfisrt->data))->lostBound > LIMIT_QUEUE ){
      mylist = g_list_remove_link (mylist, pfisrt);
    printf("    IF Error: lista vacia 11\n");
      //myTrackingObj_free( (tracking_obj*)(pfisrt->data) );
      myTrackingObj_free( (tracking_obj*)(pfisrt->data) );
    printf("    IF Error: lista vacia 12\n");
      g_list_free (pfisrt);
    }
    pfisrt = pfisrt->next;      
  printf("Error: lista vacia 12\n");
  }
  return;
}






void myTrackingObj_printListObjInFile(GList* mylist, FILE* fp){

  int i;
  
  GList* pfisrt = NULL;
  pfisrt = g_list_first (mylist);
  int tam = g_list_length (mylist);

  //for(i=0 ; i<tam ; i++){
    printf("&&&&&&&&&&&&&&&&&&& inicio while \n");
  while(pfisrt){
    char temp[100]  = {0};
    sprintf(temp,"(%i,%i,%i,%i)<<<<<< \n" ,((tracking_obj*)(pfisrt->data))->rootRect->topleft->x
                                          ,((tracking_obj*)(pfisrt->data))->rootRect->topleft->y
                                          ,((tracking_obj*)(pfisrt->data))->rootRect->bottomright->x
                                          ,((tracking_obj*)(pfisrt->data))->rootRect->bottomright->y );      
    fprintf(fp, temp);
    myTrackingObj_printTrackingObjInFile((tracking_obj*)(pfisrt->data),fp);       
    pfisrt = pfisrt->next;    
  }
  printf("&&&&&&&&&&&&&&&&&&& fin while \n");

  return;
}


void myTrackingObj_printTrackingObjInFile(tracking_obj* obj, FILE* fp){

  int tam_queue = g_queue_get_length(obj->queue_rectangles);
  int i;
  printf("inicio for\n");
  printf("//&&SS>>%d\n",tam_queue );

  for(i=0 ; i<tam_queue ; i++){
    char temp[100]  = {0};
    printf("%d>>>\n",i );

    rectangle* myrect = g_queue_peek_nth (obj->queue_rectangles, i );
    //if(obj->queue_rectangles ==NULL){
    //  return;
    //}
    sprintf(temp,"      (%i,%i,%i,%i) \n" ,myrect->topleft->x
                                          ,myrect->topleft->y
                                          ,myrect->bottomright->x
                                          ,myrect->bottomright->y );      
    fprintf(fp, temp);
  }
  printf("fin for\n");

  return;
}




void myTrackingObj_print2(tracking_obj* obj){

  int tam_queue = g_queue_get_length(obj->queue_rectangles);
  int i;

  for(i=0 ; i<tam_queue ; i++){
    rectangle* temp = g_queue_peek_nth (obj->queue_rectangles, i );
    printf("      (%i,%i,%i,%i) \n" ,temp->topleft->x
                                    ,temp->topleft->y
                                    ,temp->bottomright->x
                                    ,temp->bottomright->y );      
  }

  return;
}





///////////////////////////////////////////////////////
///////////////////////////////////////////////////////



void mytrackingObj_updatePointCenter(tracking_obj* obj, rectangle* rect1){
  if( obj->rootRect == NULL ){
    printf("Error, puntero vacio, rect1.\n");
    return;
  }
  if( rect1 == NULL ){
    printf("Error, puntero vacio, rect2.\n");
    //myRectangle_create(&rect2);
    return;
  }

  obj->pointcenterX = rect1->topleft->x + (rect1->bottomright->x - rect1->topleft->x)/2;
  obj->pointcenterY = rect1->topleft->y + (rect1->bottomright->y - rect1->topleft->y)/2;
  return;
}


double myTrackingObj_distancia_eu_2rect(rectangle* rect1, rectangle* rect2){
  if( rect1 == NULL ){
    printf("Error, puntero vacio, rect1.\n");
    //myRectangle_create(&rect2);
    return -1.0;
  }

  if( rect2 == NULL ){
    printf("Error, puntero vacio, rect2.\n");
    //myRectangle_create(&rect2);
    return -1.0;
  }

  int x1 = rect1->topleft->x + (rect1->bottomright->x - rect1->topleft->x)/2;
  int y1 = rect1->topleft->y + (rect1->bottomright->y - rect1->topleft->y)/2;

  int x2 = rect2->topleft->x + (rect2->bottomright->x - rect2->topleft->x)/2;
  int y2 = rect2->topleft->y + (rect2->bottomright->y - rect2->topleft->y)/2;

  double dist = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );

  return dist;
}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


                      //GList* a, rectangle* b
gint myfoo_GCompareFunc(void* a, void* b){
  double thresholdZZ = 0.10;
  double doubleOverlap = myRectangle_overlap( (rectangle*)(((tracking_obj*)(a))->rootRect),
                                              (rectangle*)(b) );
  return  thresholdZZ <= doubleOverlap ? 0:-1;
}

