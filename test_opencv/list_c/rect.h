

#ifndef RECT_H
#define RECT_H


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




#endif //end RECT_H
