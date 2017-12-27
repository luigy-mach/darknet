
#include<stdio.h>
#include<stdlib.h>
#include <math.h>


#include "tracking_obj.h"

#include "rect.h"
#include "queue.h"

#include "mylist.h"



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


  double threshold_rectangle = 0.5;


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

  int number_frame = 12;

  mylist* l;
  create_mylist(&l);
  my_insert_list_rect2(l, myrect1, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect2, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect3, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect4, threshold_rectangle,number_frame);
  my_insert_list_rect2(l, myrect5, threshold_rectangle,number_frame);

  
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
  printf("******************************************\n");

  //double ddd;
  //ddd = myoverlap_rectangle(myrect1,myrect2);
  //printf("myrect1 y myrect2: %lf \n",ddd);
  //ddd = myoverlap_rectangle(myrect2,myrect3);
  //printf("myrect2 y myrect3: %lf \n",ddd);
  //ddd = myoverlap_rectangle(myrect1,myrect3);
  //printf("myrect1 y myrect3: %lf \n",ddd);


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
