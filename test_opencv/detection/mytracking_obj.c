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
  ///////////////myRectangle_free(obj->rootRect);
  ///////////////printf("      yyyyyyyyyyyyyyyyyy 11\n");
  ///////////////g_queue_free_full(obj->queue_rectangles,&myRectangle_free);
  ///////////////g_queue_free(obj->queue_rectangles);
  ///////////////printf("      yyyyyyyyyyyyyyyyyy 12\n");
  /////////////////free( obj );
  ///////////////obj = NULL;

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

  g_queue_push_head(obj->queue_rectangles,rect1);
  myTrackingObj_updateFlagUsed(obj);
  
  int tam_queue = g_queue_get_length(obj->queue_rectangles);
  if(LIMIT_QUEUE<tam_queue)
  {
    rectangle* rect_temp = g_queue_pop_tail(obj->queue_rectangles);
    myRectangle_free(rect_temp);

  }
  return;
}


void myTrackingObj_updateFlagUsed(tracking_obj* obj){
  //obj->flagUsed = (obj->flagUsed+1)%2; 
  obj->flagUsed = 1; 
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
  
  mylist = g_list_first (mylist);
  return;
}


void myTrackingObj_deleletBoundinBoxLost(GList* mylist){
  if(mylist==NULL){
    printf("Error: lista vacia \n");
    return;
  }
  mylist = g_list_first(mylist);
  
  //int i;
  
  GList* pfirst = NULL;
  pfirst = mylist;
  int tam = g_list_length(pfirst);
  pfirst = mylist;
  
  //while(pfirst)
  for(pfirst=mylist ; pfirst ; pfirst=pfirst->next)
  {
    printf("deleletBoundinBoxLost 11\n");
    if( ((tracking_obj*)(pfirst->data))->lostBound >= LIMIT_PERDIDA )
    {
    printf("    WHILE - LIMITE SUPERADO 11 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
      mylist = g_list_remove_link(mylist, pfirst);
      myTrackingObj_free( (tracking_obj*)(pfirst->data) );
      g_list_free_1(pfirst);
    printf("    WHILE - LIMITE SUPERADO 12 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
    }else{
    printf("    WHILE - NO SUPERADO 11 >>>>>>>>\n");
      //pfirst = (GList*)(pfirst->next);
    printf("    WHILE - NO SUPERADO 12 >>>>>>>>\n");
    }
    printf("deleletBoundinBoxLost 12\n");
  }

  /////GList* mylist_temp = NULL;
  /////g_list_foreach(mylist,foo_GFunc_func,mylist_temp);

  //eliminar mylist_temp 
  return;
}





void myTrackingObj_deleletALLBoundinBoxLost(GList** mylist1){

  if((*mylist1)==NULL){
    printf("Error: lista vacia \n");
    return;
  }

  //int tam = g_list_length(mylist);

  GList* mylist = NULL;
  mylist = (*mylist1);

  GList* pfirst = NULL;
  mylist = g_list_first(mylist);
  pfirst = mylist;
  
  //for(pfirst=mylist ; pfirst ; pfirst=pfirst->next)
  while(pfirst)
  {
    printf("    deleletBoundinBoxLost data\n");
    printf("(%i,%i,%i,%i) \n" ,((tracking_obj*)(pfirst->data))->rootRect->topleft->x
                              ,((tracking_obj*)(pfirst->data))->rootRect->topleft->y
                              ,((tracking_obj*)(pfirst->data))->rootRect->bottomright->x
                              ,((tracking_obj*)(pfirst->data))->rootRect->bottomright->y ); 
    printf("    deleletBoundinBoxLost data\n");
    printf("deleletBoundinBoxLost 11\n");
    if( ((tracking_obj*)(pfirst->data))->lostBound >= LIMIT_PERDIDA )
    {
      
      printf("\n    WHILE - LIMITE SUPERADO 11 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
      ////////////if( pfirst->prev==NULL )
      ////////////{
      ////////////  printf("      soy el primero\n");
        /*
        /////GList* temp=pfirst;
        /////pfirst=pfirst->next;
        /////       temp->next =  NULL;
        /////       temp->prev =  NULL;
        printf("    debug  pfirst = pfirst->next;\n");
        /////pfirst->prev=NULL;
        /////mylist=pfirst;

        mylist = g_list_remove_link(mylist, pfirst);
        myTrackingObj_free (pfirst->data);

        printf("    debug  pfirst->prev = NULL;\n");
        myTrackingObj_free( (tracking_obj*)(pfirst->data));
        printf("    debug  myTrackingObj_free( (tracking_obj*)(pfirst->data) );\n");
        g_list_free(pfirst);
        printf("    debug  g_list_free_1(pfirst);\n");
        */
      //}else{

        printf("      %i >= %i \n",((tracking_obj*)(pfirst->data))->lostBound , LIMIT_PERDIDA );
          mylist = g_list_remove_link(mylist, pfirst);
        printf("    debug  mylist = g_list_remove_link(mylist, pfirst);\n");
          //myTrackingObj_free( (tracking_obj*)(pfirst->data));
        printf("    debug  myTrackingObj_free( (tracking_obj*)(pfirst->data) );\n");
          g_list_free_1(pfirst);
        //printf("    debug  g_list_free_1(pfirst);\n");
          mylist = g_list_first(mylist);
          pfirst=mylist;

        printf("    debug  todo de nuevo\n");

      //}
      printf("    WHILE - LIMITE SUPERADO 12 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n\n");
    }else{
      printf("\n    WHILE - NO SUPERADO 11 >>>>>>>>\n");
      printf("      %i >= %i \n",((tracking_obj*)(pfirst->data))->lostBound , LIMIT_PERDIDA );
      printf("      WHILE - NO SUPERADO 12 >>>>>>>>\n\n");
      pfirst = pfirst->next;
    }
    printf("deleletBoundinBoxLost 12\n");
  }
  mylist = g_list_first(mylist);

    printf("    >>>>deleletBoundinBoxLost data mylist\n");
    printf("(%i,%i,%i,%i) \n" ,((tracking_obj*)(mylist->data))->rootRect->topleft->x
                              ,((tracking_obj*)(mylist->data))->rootRect->topleft->y
                              ,((tracking_obj*)(mylist->data))->rootRect->bottomright->x
                              ,((tracking_obj*)(mylist->data))->rootRect->bottomright->y ); 
    printf("    >>>>deleletBoundinBoxLost data mylist\n");
  (*mylist1)=mylist;
  return;
}









//void foo_GFunc_func(gpointer data, gpointer user_data);{
///////void foo_GFunc_func(void* obj, void* mylist_temp ){
///////  //(GList*)(mylist_temp)
///////  //(tracking_obj*)(obj)
///////  obj = (tracking_obj*)(obj);
///////  mylist_temp = (GList*)(mylist_temp);
///////  if( obj->lostBound > LIMIT_PERDIDA )
///////  {
///////    //list = g_list_remove_link (list, llink);
///////    //free_some_data_that_may_access_the_list_again (llink->data);
///////    //g_list_free (llink);
///////  }
///////
///////}



void myTrackingObj_printListObjInFile(GList* mylist, FILE* fp){

  int i;
  
  GList* pfirst = NULL;
  mylist = g_list_first(mylist);
  pfirst = mylist;
  int tam = g_list_length(mylist);
  pfirst = mylist;

  //for(i=0 ; i<tam ; i++){
  printf("  &&&&&&&&&&&&&&&&&&& inicio while printListObjInFile \n");
  printf("  &&&&&&&&&&&&&&&&&&& tam %d printListObjInFile \n", tam );
  while(pfirst){
    char temp[100]  = {0};
    printf("    tam > %d printListObjInFile \n", tam );
    //printf("    tam > %a printListObjInFile \n", pfirst );
    sprintf(temp,"(%i,%i,%i,%i)<<<<<< \n" ,((tracking_obj*)(pfirst->data))->flagUsed
                                          ,((tracking_obj*)(pfirst->data))->flagUsed
                                          ,((tracking_obj*)(pfirst->data))->flagUsed
                                          ,((tracking_obj*)(pfirst->data))->flagUsed );      
    fprintf(fp, temp);
    myTrackingObj_printTrackingObjInFile((tracking_obj*)(pfirst->data),fp);       
    pfirst = pfirst->next;    
  }
  printf("  &&&&&&&&&&&&&&&&&&& fin while printListObjInFile \n");
  //return;
}


void myTrackingObj_printTrackingObjInFile(tracking_obj* obj, FILE* fp){

  printf("      inicio myTrackingObj_printTrackingObjInFile\n");
  int tam_queue = g_queue_get_length(obj->queue_rectangles);
  int i;

  printf("   inicio for\n");
  printf("      //&&SS>>%d\n",tam_queue );
  printf("      &&&&&&&&&&&&&&&&&&& tam %d printListObjInFile \n", tam_queue );

  for(i=0 ; i<tam_queue ; i++){
    char temp[100]  = {0};
    printf("     printTrackingObjInFile for inicio %d>>>\n",i );
    rectangle* myrect = g_queue_peek_nth (obj->queue_rectangles, i );
    sprintf(temp,"      (%i,%i,%i,%i) \n" ,myrect->topleft->x
                                          ,myrect->topleft->y
                                          ,myrect->bottomright->x
                                          ,myrect->bottomright->y );      
    fprintf(fp, temp);
    printf("     printTrackingObjInFile for fin %d>>>\n",i );
  }
  printf("      fin for\n");

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



////void mytrackingObj_updatePointCenter(tracking_obj* obj, rectangle* rect1){
////  if( obj->rootRect == NULL ){
////    printf("Error, puntero vacio, rect1.\n");
////    return;
////  }
////  if( rect1 == NULL ){
////    printf("Error, puntero vacio, rect2.\n");
////    //myRectangle_create(&rect2);
////    return;
////  }
////
////  obj->pointcenterX = rect1->topleft->x + (rect1->bottomright->x - rect1->topleft->x)/2;
////  obj->pointcenterY = rect1->topleft->y + (rect1->bottomright->y - rect1->topleft->y)/2;
////  return;
////}


/////double myTrackingObj_distancia_eu_2rect(rectangle* rect1, rectangle* rect2){
/////  if( rect1 == NULL ){
/////    printf("Error, puntero vacio, rect1.\n");
/////    //myRectangle_create(&rect2);
/////    return -1.0;
/////  }
/////
/////  if( rect2 == NULL ){
/////    printf("Error, puntero vacio, rect2.\n");
/////    //myRectangle_create(&rect2);
/////    return -1.0;
/////  }
/////
/////  int x1 = rect1->topleft->x + (rect1->bottomright->x - rect1->topleft->x)/2;
/////  int y1 = rect1->topleft->y + (rect1->bottomright->y - rect1->topleft->y)/2;
/////
/////  int x2 = rect2->topleft->x + (rect2->bottomright->x - rect2->topleft->x)/2;
/////  int y2 = rect2->topleft->y + (rect2->bottomright->y - rect2->topleft->y)/2;
/////
/////  double dist = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
/////
/////  return dist;
/////}


///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


                      //GList* a, rectangle* b
int myfoo_GCompareFunc(void* a, void* b){
  //rectangle* p1 = (rectangle*)(((tracking_obj*)(a))->rootRect);
  rectangle* p1 = (rectangle*)(((tracking_obj*)(a))->rootRect);
  printf("              debug myfoo_GCompareFunc p1  -> %s \n",p1);
  rectangle* p2 = (rectangle*)(b);
  printf("              debug myfoo_GCompareFunc p2  -> %s \n",p2);
  if(  (rectangle*)(((tracking_obj*)(a))->rootRect) == NULL )
  {
    printf("Error, puntero vacio, myfoo_GCompareFunc 1.\n");
    return -1;
  }
  if( (rectangle*)(b) == NULL )
  {
    printf("Error, puntero vacio, myfoo_GCompareFunc 2.\n");
    //myRectangle_create(&rect2);
    return -1;
  }
  double thresholdZZ = 0.10;
  double doubleOverlap = myRectangle_overlap(p1,p2);
  //double doubleOverlap = myRectangle_overlap( ((tracking_obj*)(a))->rootRect,
  //                                            (rectangle*)(b) );
  printf("              antes myfoo_GCompareFunc thresholdZZ  -> %lf \n",thresholdZZ);
  printf("              antes myfoo_GCompareFunc doubleOverlap-> %lf \n",doubleOverlap);
  //return   ? 0:-1;
  
  if(thresholdZZ <= doubleOverlap)
  {
    printf("              despues myfoo_GCompareFunc -> %d \n",0);
    return 0;
  }else{
    printf("              despues myfoo_GCompareFunc -> %d \n",-1);
    return -1;
  }
  //return  thresholdZZ <= doubleOverlap ? 0:-1;
}

///gcc *.c `pkg-config --cflags glib-2.0 pkg-config --libs glib-2.0` -lm