
#include "myrect.h"


void create_myPoint(point** pp){
	point* temp = (point*)malloc(sizeof(point));
		   //temp->x = -1;
		   //temp->y = -1;
	init_myPoint(temp);
	(*pp) = temp;
	return;
}

void init_myPoint(point* p){
	p->x = -1;
	p->y = -1;
	return;
}


void free_myPoint(point** pp){
	//printf("llamanado a: free(pp);11\n");
	free(*pp);
	(*pp)=NULL;
	//printf("llamanado a: free(pp);22\n");
	return;
}



/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////




void create_myRectangle(rectangle** rect){
	rectangle* temp = (rectangle*)malloc(sizeof(rectangle));
	init_myPoint(temp->topleft);
	init_myPoint(temp->bottomright);
	(*rect)=temp;
	return;
}


void init_myRectangle(rectangle* rect){
	init_myPoint(rect->topleft);
	init_myPoint(rect->bottomright);
	return;
}


void free_myRectangle(rectangle** rect){
	printf("llamando a: free_myPoint1-11\n");
	free_myPoint( &((*rect)->topleft) ) ;
	//free( &((*rect)->topleft) );
	printf("llamando a: free_myPoint1-22\n");

	printf("llamando a: free_myPoint2-11\n");
	free_myPoint( &((*rect)->bottomright) ) ;
	//free( &((*rect)->bottomright) );
	printf("llamando a: free_myPoint2-22\n");
	(*rect) = NULL;
	return;
}

void fill_myRectangle(rectangle* myrect, int p1x, int p1y, int p2x, int p2y){
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
double myoverlap_rectangle(rectangle* rectA, rectangle* rectB)
{
	double overlapp = 0;
	int w1 = fabs(rectA->bottomright->x - rectA->topleft->x);
	int h1 = fabs(rectA->bottomright->y - rectA->topleft->y);
	int w2 = fabs(rectB->bottomright->x - rectB->topleft->x);
	int h2 = fabs(rectB->bottomright->y - rectB->topleft->y);

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
	return overlapp; 
}



void copy_rectangle(rectangle* rect1, rectangle* rect2){
	if( rect1 == NULL ){
		printf("Error, puntero vacio, rect1.\n");
		return;
	}
	if( rect2 == NULL ){
		printf("Error, puntero vacio, rect2.\n");
		//create_myRectangle(&rect2);
		return;
	}
	rect1->topleft->x 	  = rect2->topleft->x;
	rect1->topleft->y 	  = rect2->topleft->y;
	rect1->bottomright->x = rect2->bottomright->x;
	rect1->bottomright->y = rect2->bottomright->y;
	return;
}
