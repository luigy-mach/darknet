
#include<stdio.h>
#include<stdlib.h>

#include "tracking_obj.h"

#include "rect.h"
#include "queue.h"

#include "mylist.h"



///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////


double foo(){
  double test = 123456;
  return test;
}


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
  fill_myRectangle(myrect1, 20,20,30,30);

  Rectangle* myrect2;
  create_myRectangle(&myrect2);
  fill_myRectangle(myrect2, 12,12,100,110);

  mylist* l;
  create_mylist(&l);
  my_insert_list_rect(l, myrect1, threshold_rectangle);
  my_insert_list_rect(l, myrect2, threshold_rectangle);


  printf("******************************************\n");
  printf("******************************************\n");



  double dd;
  dd = myoverlap_rectangle(myrect1,myrect2);
  //printf("%lf\n",dd);
  printf("extern - overlap es dd: %lf \n",dd);

  float ff;
  ff = my_overlap(*myrect1,*myrect2); 
  printf("extern - overlap es ff: %lf \n",ff);

  printf("******************************************\n");
  printf("******************************************\n");
  double xx = foo();
  printf("test return: %lf \n",xx);

 


}
