
#include<stdio.h>
#include <math.h>
#include <string.h>



#include <time.h>
#include <stdlib.h>


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
  int number_frame = 50;
  mylist* ll;
  double demo_mythreshold_overlap = 0.40;
  create_structure(&ll);
  int j;

  int max_boundingbox_per_frame = 50;

  for(j=0;j<number_frame;j++)
  {
    char buff[2048];
    fprintf(fp, "///////////////////////\n");
    sprintf(buff,"Frame numero: %d\n",j);
    fprintf(fp, buff);

    for(i=0 ; i<max_boundingbox_per_frame ; i++)
    {
      int left  = rand()%100;
      int right = rand()%100;
      int top   = rand()%100;
      int bot   = rand()%100;

      
      //int zzz = rand()%300;
      //int left  = zzz;
      //int top   = zzz;
      //int right = zzz+10;
      //int bot   = zzz+10;

      rectangle* myrect_temp;
      create_myRectangle(&myrect_temp);
      fill_myRectangle(myrect_temp,left,top,right,bot);
      //int num_frame = 12;


      my_insert_list_rect2(ll, myrect_temp, demo_mythreshold_overlap, j);
      double temp = buscar_rectangle_returnVeloc(ll,left, right, top, bot);
      printf(">>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>%lf\n",temp );

    }
    printf("update_perdida\n");
    update_perdida_v2(ll, j);
    
    update_distancia(ll);
    update_velocidad(ll);

    printf("limpiar_perdida\n");
    

    limpiar_perdida(ll);
    print_list2(ll,fp);


  }

printf("******************************************\n");
  printf("*******************xxx***********************\n");



  

  fclose(fp);



  printf("******************************************\n");
  printf("*******************zzzz***********************\n");

  return 0;
}
