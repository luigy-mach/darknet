#include <stdio.h>



typedef struct {
	int a;
	char name[10]={0};
}test;

int main(){
	test test1;
	test1.a=10;

	printf("%d\n",test1.a );
	return 0;
}