
#include "myrect.h"


void myPoint_create(point** pp){
	point* temp = (point*)malloc(sizeof(point));
		   //temp->x = -1;
		   //temp->y = -1;
	myPoint_init_create(temp);
	(*pp) = temp;
	return;
}

void myPoint_init_create(point* p){
	p->x = -1;
	p->y = -1;
	return;
}


void myPoint_free(point* pp){
	//printf("llamanado a: free(pp);11\n");
	free(pp);
	pp=NULL;
	//printf("llamanado a: free(pp);22\n");
	return;
}

//
//void myPoint_free(point** pp){
//	//printf("llamanado a: free(pp);11\n");
//	free(*pp);
//	(*pp)=NULL;
//	//printf("llamanado a: free(pp);22\n");
//	return;
//}
//


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



void myRectangle_create(rectangle** rect){
	rectangle* temp = (rectangle*)malloc(sizeof(rectangle));
	myRectangle_init_create(temp);
	(*rect)=temp;
	return;
}


void myRectangle_init_create(rectangle* rect){

	myPoint_create( &(rect->topleft) );
	myPoint_init_create(rect->topleft);

	myPoint_create( &(rect->bottomright) );
	myPoint_init_create(rect->bottomright);

	return;
}


void myRectangle_free(rectangle* rect){
	myPoint_free( rect->topleft);
	myPoint_free( rect->bottomright);
	rect = NULL;
	return;
}

//void myRectangle_free(rectangle** rect){
//	myPoint_free( &((*rect)->topleft) ) ;
//	myPoint_free( &((*rect)->bottomright) ) ;
//	(*rect) = NULL;
//	return;
//}

void myRectangle_fill(rectangle* myrect, int p1x, int p1y, int p2x, int p2y){
	myrect->topleft->x = p1x;
	myrect->topleft->y = p1y;
	myrect->bottomright->x = p2x;
	myrect->bottomright->y = p2y;
	return;
}





/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



int max(int a, int b)
{
	if(a<b)
		return b;
	else return a;
}



int min(int a, int b)
{
	if(a<b)
		return a;
	else return b;
}



//OJO
//agregar caso donde:
//		-un area menor esta contenida dentro de otra mayor
//		-el resultado de esto deberia ser 100% 
double myRectangle_overlap(rectangle* rectA, rectangle* rectB)
{
	printf("              		antes myRectangle_overlap  -> \n");
	double overlapp = 0;
	printf("              		debug myRectangle_overlap  -> 11 \n");
	printf("              		debug myRectangle_overlap  -> 111 \n");
	printf("              		debug myRectangle_overlap  -> %d \n",rectA->bottomright->x);
	printf("              		debug myRectangle_overlap  -> 112\n");
	printf("              		debug myRectangle_overlap  -> %d \n",rectA->topleft->x);
	int w1 = fabs(rectA->bottomright->x - rectA->topleft->x);
	printf("              		debug myRectangle_overlap  -> %d \n",w1);
	int h1 = fabs(rectA->bottomright->y - rectA->topleft->y);
	printf("              		debug myRectangle_overlap  -> %d \n",h1);
	int w2 = fabs(rectB->bottomright->x - rectB->topleft->x);
	printf("              		debug myRectangle_overlap  -> %d \n",w2);
	int h2 = fabs(rectB->bottomright->y - rectB->topleft->y);
	printf("              		debug myRectangle_overlap  -> %d \n",h2);
	printf("              		debug myRectangle_overlap  -> 12 \n");

	double SA = w1*h1;
	double SB = w2*h2;

	double iLeft    = max(rectA->topleft->x     ,rectB->topleft->x);
	double iRight   = min(rectA->bottomright->x ,rectB->bottomright->x);
	double iTop  	  = max(rectA->topleft->y     ,rectB->topleft->y);
	double iBottom  = min(rectA->bottomright->y ,rectB->bottomright->y);

	double si = max(0, iRight - iLeft) * max(0, iBottom - iTop);

	double su = SA + SB - si;

	overlapp = si / su;
	//printf("overlap es11: %lf \n",overlapp);
	//double zzzz = 465;
	//printf("overlap es22 zzzz: %lf \n",zzzz);
	printf("              		despues myRectangle_overlap  ->  \n");
	return overlapp; 
}



void myRectangle_copy(rectangle* rect1, rectangle* rect2){
	if( rect1 == NULL ){
		printf("Error, puntero vacio, rect1.\n");
		return;
	}
	if( rect2 == NULL ){
		printf("Error, puntero vacio, rect2.\n");
		//myRectangle_create(&rect2);
		return;
	}
	rect1->topleft->x 	  = rect2->topleft->x;
	rect1->topleft->y 	  = rect2->topleft->y;
	rect1->bottomright->x = rect2->bottomright->x;
	rect1->bottomright->y = rect2->bottomright->y;
	return;
}
