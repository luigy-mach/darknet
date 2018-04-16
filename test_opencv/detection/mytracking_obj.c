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
  //obj->name         = VACIOSTRING;
  //obj->flagUsed     = 0;
  //obj->lostBound    = 0;
  //obj->velocidad    = 0;
  //obj->distancia    = 0.0;
  //obj->pointcenterX = 0;
  //obj->pointcenterY = 0;
  //obj->rootRect     = NULL;
  //obj->queue_rectangles = NULL;

  //free( obj->name );
  myRectangle_free(obj->rootRect);
  printf("      yyyyyyyyyyyyyyyyyy 11\n");
  g_queue_free_full(obj->queue_rectangles,&myRectangle_free);
  g_queue_free(obj->queue_rectangles);
  printf("      yyyyyyyyyyyyyyyyyy 12\n");
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

  g_queue_push_head(obj->queue_rectangles,rect1);
  myTrackingObj_updateFlag(obj);
  
  if(LIMIT_QUEUE<=tam_queue)
  {
    rectangle* rect_temp = g_queue_pop_tail(obj->queue_rectangles);
    myRectangle_free(rect_temp);

  }
  return;
}


void myTrackingObj_updateFlag(tracking_obj* obj){
  obj->flagUsed = (obj->flagUsed+1)%2; 
  return;
}


void myTrackingObj_updateAllFlags(GList* mylist){
  int i;
  GList* pfirst = NULL;
  pfirst = g_list_first (mylist);
printf("myTrackingObj_updateAllFlags 11\n" );
  while(pfirst)
  {
    if( ((tracking_obj*)(pfirst->data))->flagUsed == 0 )
    {
      ((tracking_obj*)(pfirst->data))->lostBound++;   
      printf("                        no-usado\n" );
    }
    if( ((tracking_obj*)(pfirst->data))->flagUsed == 1 )
    {
      ((tracking_obj*)(pfirst->data))->flagUsed  = 0;   
      ((tracking_obj*)(pfirst->data))->lostBound = 0;
      printf("                        si-usado\n" );
    }
    pfirst = pfirst->next;      
  }  
printf("myTrackingObj_updateAllFlags 12\n" );
  return;
}


void myTrackingObj_deleletBoundinBoxLost(GList* mylist){
  if(mylist==NULL){
    printf("Error: lista vacia \n");
    return;
  }
  int tam = g_list_length (mylist);
  int i;
  
  GList* pfirst = NULL;
  pfirst = g_list_first (mylist);
  //myTrackingObj_print( (tracking_obj*)(pfirst->data) );
  while(pfirst){
    printf("deleletBoundinBoxLost 11\n");
      if( ((tracking_obj*)(pfirst->data))->lostBound > LIMIT_PERDIDA ){
      printf("    WHILE - LIMITE SUPERADO 11 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
        GList* ptemp = pfirst;
        //pfirst = pfirst->prev;
        mylist = g_list_remove_link (mylist, ptemp);
        pfirst = g_list_first (mylist);
        myTrackingObj_free( (tracking_obj*)(ptemp->data) );
        g_list_free_1 (ptemp);
      printf("    WHILE - LIMITE SUPERADO 12 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
      }else{
      printf("    WHILE - NO SUPERADO 11 >>>>>>>>\n");
        pfirst = pfirst->next;
      printf("    WHILE - NO SUPERADO 12 >>>>>>>>\n");
      }
    printf("deleletBoundinBoxLost 12\n");
  }
  return;
}






void myTrackingObj_printListObjInFile(GList* mylist, FILE* fp){

  int i;
  
  GList* pfirst = NULL;
  pfirst = g_list_first (mylist);
  int tam = g_list_length (mylist);

  //for(i=0 ; i<tam ; i++){
  printf("&&&&&&&&&&&&&&&&&&& inicio while printListObjInFile \n");
  printf("&&&&&&&&&&&&&&&&&&& tam %d printListObjInFile \n", tam );
  while(pfirst){
    char temp[100]  = {0};
    sprintf(temp,"(%i,%i,%i,%i)<<<<<< \n" ,((tracking_obj*)(pfirst->data))->rootRect->topleft->x
                                          ,((tracking_obj*)(pfirst->data))->rootRect->topleft->y
                                          ,((tracking_obj*)(pfirst->data))->rootRect->bottomright->x
                                          ,((tracking_obj*)(pfirst->data))->rootRect->bottomright->y );      
    fprintf(fp, temp);
    myTrackingObj_printTrackingObjInFile((tracking_obj*)(pfirst->data),fp);       
    pfirst = pfirst->next;    
  }
  printf("&&&&&&&&&&&&&&&&&&& fin while printListObjInFile \n");
  return;
}


void myTrackingObj_printTrackingObjInFile(tracking_obj* obj, FILE* fp){

  int tam_queue = g_queue_get_length(obj->queue_rectangles);
  int i;

  printf("inicio for\n");
  printf("//&&SS>>%d\n",tam_queue );

  for(i=0 ; i<tam_queue ; i++){
    char temp[100]  = {0};
    printf("printTrackingObjInFile for inicio %d>>>\n",i );
    rectangle* myrect = g_queue_peek_nth (obj->queue_rectangles, i );
    sprintf(temp,"      (%i,%i,%i,%i) \n" ,myrect->topleft->x
                                          ,myrect->topleft->y
                                          ,myrect->bottomright->x
                                          ,myrect->bottomright->y );      
    fprintf(fp, temp);
    printf("printTrackingObjInFile for fin %d>>>\n",i );
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

