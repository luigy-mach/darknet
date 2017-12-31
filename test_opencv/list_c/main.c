
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>


#include "mycommon.h"


//#define SIZEOF_BUFF 4096

///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////



int main(){
  tracking_obj* test;
  create_new_tracking_obj(&test);
  printf("%s\n", test->name);
  printf("%d\n", test->flag);
  printf("%d\n", test->perdida);
  printf("-----------------------\n" );
  printf("topleft x:%d\n", test->bounding_box->topleft.x);
  printf("topleft y:%d\n", test->bounding_box->topleft.y);
  printf("bottomright x:%d\n", test->bounding_box->topleft.x);
  printf("bottomright y:%d\n", test->bounding_box->topleft.y);
  printf("-----------------------\n" );


  tracking_obj* zzz;
  create_new_tracking_obj(&zzz);
  zzz->name="luigy";

  tracking_obj* tmp1;
  create_new_tracking_obj(&tmp1);
  
  printf("-----------------------\n" );
  //printf("el primer objeto es : %s \n",test->queue_rectangles);
  printf("-----------------------\n" );




////////////////////////////////////////////////////////
  //implemtar insertar tomando en cuenta el match de overlap
  //implementar funcion limpiar deacuerdo a (perdida=MAX) y recibe el numero de (frame%2)
    //antes de todo revisar el (flag) de acuerdo al frame

  //implementar funcion delete de list para 


  double threshold_rectangle = 0.4;


  Rectangle* myrect1;
  create_myRectangle(&myrect1);
  fill_myRectangle(myrect1, 0,0,10,10);

  Rectangle* myrect2;
  create_myRectangle(&myrect2);
  fill_myRectangle(myrect2, 10,10,20,20);

  Rectangle* myrect3;
  create_myRectangle(&myrect3);
  fill_myRectangle(myrect3, 20,20,30,30);

  Rectangle* myrect4;
  create_myRectangle(&myrect4);
  fill_myRectangle(myrect4, 30,30,40,40);

  Rectangle* myrect5;
  create_myRectangle(&myrect5);
  fill_myRectangle(myrect5, 40,40,50,50);

  Rectangle* myrect6;
  create_myRectangle(&myrect6);
  fill_myRectangle(myrect6, 1,1,11,11);

  Rectangle* myrect7;
  create_myRectangle(&myrect7);
  fill_myRectangle(myrect7, 2,2,12,12);

  int number_frame = 12;

  mylist* l;
  create_mylist(&l);
  my_insert_list_rect2(l, myrect1, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect2, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect3, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect4, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect5, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect6, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect7, threshold_rectangle,number_frame);

  
  l->root->data_obj->perdida=2;
  l->root->next->data_obj->perdida=3;
  l->root->next->next->data_obj->perdida=2;
  l->root->next->next->next->data_obj->perdida=3;
  l->root->next->next->next->next->data_obj->perdida=2;

  printf("%d\n", l->root->data_obj->perdida );
  printf("%d\n", l->root->next->data_obj->perdida);
  printf("%d\n", l->root->next->next->data_obj->perdida);
  printf("%d\n", l->root->next->next->next->data_obj->perdida);
  printf("%d\n", l->root->next->next->next->next->data_obj->perdida);
  limpiar_perdida(l);
  printf("++++++++++++++++++++++\n");
  printf("%d\n", l->root->data_obj->perdida );
  printf("%d\n", l->root->next->data_obj->perdida);
  printf("%d\n", l->root->next->next->data_obj->perdida);
  
  printf("******************************************\n");
  printf("*****************00000**********************\n");
  
  //char *buffer = (char*)malloc(sizeof(char));
  char buffer[4096];
  print_list(l, buffer);

  printf("%s\n", buffer );
  
 /* printf("******************************************\n");
  printf("********************1111**********************\n");
    char tagstr1[SIZEOF_BUFF];
    int pos = 0;
    int k1;
    int n1 = 5;

    for (k1=0; k1 < n1; k1++) {
        pos += sprintf(&tagstr1[pos], ", val%d", k1);
    }
    printf ("String is now: %s\n", tagstr1);
  printf("******************************************\n");
  printf("********************222*********************\n");

    char tagstr[60] = {0};
        int k;
        int n = 5;
        for (k=0; k < n; k++) {
            char temp[10]  = {0};
            sprintf(temp, ", val%d", k);
            strcat(tagstr, temp);
        }
        printf("[%s]\n", tagstr);
  printf("******************************************\n");
  printf("******************************************\n");
*/
/*
  printf("++++++++++++++++++++++++++++++++++++++++++\n");
  char* buff[4096];
  int length = 0;
  length += sprintf(buff+length, "Hello World");
  length += sprintf(buff+length, "Good Morning");
  length += sprintf(buff+length, "Good Afternoon");
  printf("%s\n", buff );
  printf("++++++++++++++++++++++++++++++++++++++++++\n");

#include <stdio.h>
#include <string.h>

#define LOC_MAXLEN 33
  char* buff2[4096];
  snprintf(buff2 , LOC_MAXLEN,"Hello World");
  snprintf(buff2 + strlen(buff2), LOC_MAXLEN - strlen(buff2),"Good Morning");
  snprintf(buff2 + strlen(buff2), LOC_MAXLEN - strlen(buff2),"Good Afternoon");
  printf("%s\n", buff2 );
  //double ddd;
  //ddd = myoverlap_rectangle(myrect1,myrect2);
  //printf("myrect1 y myrect2: %lf \n",ddd);
  //ddd = myoverlap_rectangle(myrect2,myrect3);
  //printf("myrect2 y myrect3: %lf \n",ddd);
  //ddd = myoverlap_rectangle(myrect1,myrect3);
  //printf("myrect1 y myrect3: %lf \n",ddd);




  printf("++++++++++++++++++++++++++++++++++++++++++\n");



  
  char dest[LOC_MAXLEN];
  snprintf(dest, LOC_MAXLEN, "%s%s", "abc", "def");
  snprintf(dest + strlen(dest), LOC_MAXLEN - strlen(dest), "%s", "ghi");
  snprintf(dest + strlen(dest), LOC_MAXLEN - strlen(dest), "%s", "jkl");
  printf("%s\n", dest);
  printf("%s\n", dest);

  printf("%s\n", dest);
  
 */





  printf("******************************************\n");
  printf("******************************************\n");

  Rectangle* myrect33;
  create_myRectangle(&myrect33);
  fill_myRectangle(myrect33, 0,0,10,10);

  Rectangle* myrect44;
  create_myRectangle(&myrect44);
  fill_myRectangle(myrect44, 0,0,5,5);


  double ddd;
  ddd = myoverlap_rectangle(myrect33,myrect44);
  printf("extern - overlap es ddd: %lf \n",ddd);


  float fff;
  fff = my_overlap(*myrect33,*myrect44); 
  printf("extern - overlap es fff: %lf \n",fff);


  return 0;
}
