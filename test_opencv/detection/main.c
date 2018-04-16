
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

  printf("******************************************\n");
  printf("*****************00000**********************\n");
  

  FILE *fp;

  fp = fopen( MYFILE , "a");

  
  int i;
  int j;

  //int number_frame = 2;
  //int max_boundingbox_per_frame = 2;

  int number_frame = 20;
  int max_boundingbox_per_frame = 20;

  
  double demo_mythreshold_overlap = 0.40;
  
  //create_structure(&ll);
  //mylist* ll;
  //myList_create(&ll);


  GList * mylist = NULL;


  srand(time(0));
  for(j=0 ; j<number_frame ; j++)
  {
    char buff[2048];
    fprintf(fp, "///////////////////////\n");
    sprintf(buff,"Frame numero: %d\n",j);
    fprintf(fp, buff);
    for(i=0 ; i<max_boundingbox_per_frame ; i++)
    {
    printf("******************************************11\n");
      int top   = rand()%30;
      int left  = rand()%30;
      int bot   = top +15;
      int right = left+15;

      //int top   = 1+i;
      //int left  = 1+i;
      //int bot   = 5+i;
      //int right = 5+i;


      rectangle* myrect_temp;
      myRectangle_create( &myrect_temp );
      myRectangle_fill(myrect_temp, left, top, right, bot);

      //int num_frame = 12;
      //myList_insert_1_rect2(ll, myrect_temp, demo_mythreshold_overlap, j);
      GList* pGlist = NULL;
             pGlist = g_list_find_custom(mylist, myrect_temp, &myfoo_GCompareFunc);
      //printf(">>>>>>>>>**<<<<<<<<<<<<<<<<<<<\n" );
      //printf("%s \n", pGlist);    
      //printf(">>>>>>>>>**<<<<<<<<<<<<<<<<<<<\n" );

      if( pGlist != NULL ){
        myTrackingObj_addQueue( (tracking_obj*)(pGlist->data),
                                myrect_temp );
      }else{
        tracking_obj* mytrack_temp = NULL;
        myTrackingObj_create( &mytrack_temp );
        myTrackingObj_init_create( mytrack_temp);
        myTrackingObj_addQueue( mytrack_temp,myrect_temp);
        mylist = g_list_append(mylist, mytrack_temp);
      }
      //double temp = myList_buscar_rectangle_returnVeloc(ll, left, right, top, bot);
      printf("******************************************12\n");
    }
    
    myTrackingObj_updateAllFlags(mylist);
    //myTrackingObj_deleletBoundinBoxLost(mylist);
    //printf("··························································11\n");
    myTrackingObj_printListObjInFile(mylist,fp);    
    //printf("··························································12\n");

    //myList_update_distancia(ll);
    //myList_update_velocidad(ll);
    //printf("myList_limpiar_perdida\n");
    //myList_limpiar_perdida(ll);
    //myList_print2(ll,fp);
    
  }

  fclose(fp);

  printf("******************************************\n");
  printf("*******************xxx11***********************\n");


  GList* pfisrt = NULL;
  pfisrt = g_list_first (mylist);
  int tam = g_list_length (mylist);

  for (i=0 ; i < tam ; i++){
    //printf("%s,%s,%s,%s \n",pfisrt->data->topleft->x,pfisrt->data->topleft->y);      
    printf("%i, %i , %i, %i \n" ,((tracking_obj*)(pfisrt->data))->rootRect->topleft->x
                                ,((tracking_obj*)(pfisrt->data))->rootRect->topleft->y
                                ,((tracking_obj*)(pfisrt->data))->rootRect->bottomright->x
                                ,((tracking_obj*)(pfisrt->data))->rootRect->bottomright->y );      
    myTrackingObj_print2( (tracking_obj*)(pfisrt->data) );
    pfisrt = pfisrt->next;      
  }


  
  printf("******************************************\n");
  printf("*******************xxx12***********************\n");


  printf("******************************************\n");
  printf("*******************zzzz***********************\n");

  return 0;
}
