

#ifndef RECT_H
#define RECT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Point Point;
typedef struct Rectangle Rectangle;

struct Point{
	int x;
	int y;
};


struct Rectangle{
	Point topleft;
	Point bottomright;
};

void create_myPoint(Point** pp);
void init_myPoint(Point* p);
void create_myRectangle(Rectangle** rect);
void fill_myRectangle(Rectangle* myrect, int p1x, int p1y, int p2x, int p2y);
int max(int a, int b);
int min(int a, int b);
float my_overlap(Rectangle A, Rectangle B);
double myoverlap_rectangle(Rectangle* A, Rectangle* B);


#endif //end RECT_H
