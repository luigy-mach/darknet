

#ifndef RECT_H
#define RECT_H



#include "mycommon.h"



typedef struct point point;
typedef struct rectangle rectangle;


///////////////////////////////////////////////////
///////////////////////////////////////////////////


struct point{
	int x;
	int y;
};


void create_myPoint(point** pp);
void init_myPoint(point* p);

void free_myPoint(point** pp);


///////////////////////////////////////////////////
///////////////////////////////////////////////////


struct rectangle{
	point* topleft;
	point* bottomright;
};


void create_myRectangle(rectangle** rect);
void init_myRectangle(rectangle* rect);

void free_myRectangle(rectangle** rect);

void fill_myRectangle(rectangle* myrect, int p1x, int p1y, int p2x, int p2y);


///////////////////////////////////////////////////
///////////////////////////////////////////////////

int max(int a, int b);
int min(int a, int b);

double myoverlap_rectangle(rectangle* rectA, rectangle* rectB);

void copy_rectangle(rectangle* rect1, rectangle* rect2);



#endif //end RECT_H
