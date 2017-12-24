#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int a;
}tracking_obj;




int main(){

	tracking_obj **tracking_array_obj=NULL;

	tracking_array_obj = (tracking_obj**)calloc(20,sizeof(tracking_obj*));
	
	//printf("%d\n",test1.a );
	return 0;
}