
#include <stdio.h>
#include <math.h>
#include <string.h>



#include <time.h>
#include <stdlib.h>

#include <gmodule.h>

#include "mycommon.h"


//#define SIZEOF_BUFF 4096

///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////



int main(){

  printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
  printf("&&&&&&&&&&&&&&&&&00000000&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
  

  FILE *fp;

  fp = fopen( MYFILE , "a");

  
  int i;
  int j;

  //int number_frame = 2;
  //int max_boundingbox_per_frame = 2;

  int number_frame = 4;
  int max_boundingbox_per_frame = 4;

  
  double demo_mythreshold_overlap = 0.40;
  
  //create_structure(&ll);
  //mylist* ll;
  //myList_create(&ll);


  GList * mylist = NULL;


  srand(time(0));
  for(j=0 ; j<number_frame ; j++)
  {
    printf("88888888888888888888888888888888888888888888888 for principal inicio %d \n", j);
    char buff[2048];
    fprintf(fp, "///////////////////////\n");
    sprintf(buff,"Frame numero: %d\n",j);
    fprintf(fp, buff);


    int random1 = rand()%30;
    int random2 = rand()%30;
    for(i=0 ; i<max_boundingbox_per_frame ; i++)
    {
    printf("88888888888888888888888888888888888888888888888 for secundario inicio %d \n",i);
      //int top   = rand()%30;
      //int left  = rand()%30;
      //int bot   = rand()%30;
      //int right = rand()%30;
//
      int top   = random1+i;
      int left  = random2+i;
      int bot   = top+5;
      int right = left+5;

      rectangle* myrect_temp;
      myRectangle_create( &myrect_temp );
      myRectangle_fill(myrect_temp, left, top, right, bot);

      //int num_frame = 12;
      //myList_insert_1_rect2(ll, myrect_temp, demo_mythreshold_overlap, j);
      GList* pGlist = NULL;
    printf("  55555555555555555 debug 11\n");
      if( mylist==NULL){
        printf("      antes   vacio g_list_find_custom   -> %s \n",mylist);
        tracking_obj* mytrack_temp = NULL;
        myTrackingObj_create( &mytrack_temp );
        printf(" debug  <<<<<<<<<<<<<<- 10 \n");
        myTrackingObj_init_create( mytrack_temp);
        printf(" debug  <<<<<<<<<<<<<<- 11 \n");
        myTrackingObj_addQueue( mytrack_temp,myrect_temp);
        printf(" debug  <<<<<<<<<<<<<<- 12 \n");
        mylist = g_list_append(mylist, mytrack_temp);
        printf("      despues vacio g_list_find_custom -> add mylist \n");
        printf("      despues vacio g_list_find_custom -> %s \n",mylist);

      }else{
        printf("      antes   no-vacio g_list_find_custom   flagUsed-> %d \n",((tracking_obj*)(mylist->data))->flagUsed);
        printf("      antes   no-vacio g_list_find_custom   lostBound-> %d \n",((tracking_obj*)(mylist->data))->lostBound);
        printf("      antes   no-vacio g_list_find_custom   velocidad-> %d \n",((tracking_obj*)(mylist->data))->velocidad);
        printf("      antes   no-vacio g_list_find_custom   distancia-> %d \n",((tracking_obj*)(mylist->data))->distancia);
        printf("      antes   no-vacio g_list_find_custom   pointcenterX-> %d \n",((tracking_obj*)(mylist->data))->pointcenterX);
        printf("      antes   no-vacio g_list_find_custom   pointcenterY-> %d \n",((tracking_obj*)(mylist->data))->pointcenterY);
        printf("      antes   no-vacio g_list_find_custom myrect  -> %s \n",myrect_temp);
        pGlist = g_list_find_custom(mylist, myrect_temp, &myfoo_GCompareFunc);
        printf("      despues no-vacio g_list_find_custom myrect  -> %s \n",myrect_temp);
        printf("      despues no-vacio g_list_find_custom -> %s \n",mylist);

        printf("  55555555555555555 debug 12\n");
          if( pGlist != NULL ){
        printf(" myTrackingObj_addQueue 10\n");
            myTrackingObj_addQueue( (tracking_obj*)(pGlist->data),
                                    myrect_temp );
        printf(" myTrackingObj_addQueue 11\n");
          }else{
        printf(" myTrackingObj_addQueue 13\n");
            tracking_obj* mytrack_temp = NULL;
            myTrackingObj_create( &mytrack_temp );
        printf(" debug  <<<<<<<<<<<<<<- 10 \n");
            myTrackingObj_init_create( mytrack_temp);
        printf(" debug  <<<<<<<<<<<<<<- 11 \n");
            myTrackingObj_addQueue( mytrack_temp,myrect_temp);
        printf(" debug  <<<<<<<<<<<<<<- 12 \n");
            mylist = g_list_append(mylist, mytrack_temp);
        printf(" debug  <<<<<<<<<<<<<<- 13\n");
        printf(" myTrackingObj_addQueue 14\n");
          }
      }
      //double temp = myList_buscar_rectangle_returnVeloc(ll, left, right, top, bot);
    printf("88888888888888888888888888888888888888888888888 for secundario fin %d \n",i);
    }
    
  printf("777777777777777777777777777777777 my-fun 11 \n");
    myTrackingObj_updateAllFlags(mylist);
  printf("777777777777777777777777777777777 my-fun 12 \n");
    myTrackingObj_deleletBoundinBoxLost(mylist);
  printf("777777777777777777777777777777777 my-fun 13 \n");
    //printf("··························································11\n");
    myTrackingObj_printListObjInFile(mylist,fp);    
    //printf("··························································12\n");
  printf("777777777777777777777777777777777 my-fun 14 \n");

    //myList_update_distancia(ll);
    //myList_update_velocidad(ll);
    //printf("myList_limpiar_perdida\n");
    //myList_limpiar_perdida(ll);
    //myList_print2(ll,fp);
    
    printf("88888888888888888888888888888888888888888888888 for principal fin %d \n",j);
  }

  fclose(fp);

  printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 11\n");
  printf("&&&&&&&&&&&&&&&&&&&&XXX!!!&&&&&&&&&&&&&&&&&&& 22\n");


  GList* pfirst = NULL;
  pfirst = g_list_first (mylist);
  int tam = g_list_length (mylist);

  printf("imprimiendo lista1\n");
  int g;
  for (g=0 ; g < tam ; g++){
    //printf("%s,%s,%s,%s \n",pfirst->data->topleft->x,pfirst->data->topleft->y);      
    printf("(%i,%i,%i,%i) \n" ,((tracking_obj*)(pfirst->data))->rootRect->topleft->x
                              ,((tracking_obj*)(pfirst->data))->rootRect->topleft->y
                              ,((tracking_obj*)(pfirst->data))->rootRect->bottomright->x
                              ,((tracking_obj*)(pfirst->data))->rootRect->bottomright->y );      
    myTrackingObj_print2( (tracking_obj*)(pfirst->data) );
    pfirst = pfirst->next;      
  }

  printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 33\n");
  printf("&&&&&&&&&&&&&&&&&&&&XXX!!!&&&&&&&&&&&&&&&&&&& 44\n");

  
  
  printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 33\n");
  printf("&&&&&&&&&&&&&&&&&&&&XXX!!!&&&&&&&&&&&&&&&&&&& 44\n");
  
  GList* pfirst2 = NULL;
  pfirst2 = g_list_first (mylist);
  int tam = g_list_length (mylist);

  printf("imprimiendo lista2\n");
  int g;
  for (g=0 ; g < tam ; g++){
    //printf("%s,%s,%s,%s \n",pfirst2->data->topleft->x,pfirst->data->topleft->y);      
    printf("(%i,%i,%i,%i) \n" ,((tracking_obj*)(pfirst2->data))->rootRect->topleft->x
                              ,((tracking_obj*)(pfirst2->data))->rootRect->topleft->y
                              ,((tracking_obj*)(pfirst2->data))->rootRect->bottomright->x
                              ,((tracking_obj*)(pfirst2->data))->rootRect->bottomright->y );      
    myTrackingObj_print2( (tracking_obj*)(pfirst2->data) );
    pfirst2 = pfirst2->next;      
  }


  
  printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
  printf("&&&&&&&&&&&&&&&&&&&xxx12&&&&&&&&&&&&&&&&&&&&&\n");


  printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
  printf("&&&&&&&&&&&&&&&&&&&&&&ZZZZZZ&&&&&&&&&&&&&&&&&&&&&&&\n");

  return 0;
}
