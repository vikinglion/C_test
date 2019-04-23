#include <stdio.h>
#include <string.h>

int main(){
	
	int array[4][3] = {{1,2,3},{4,5,6},{7,8,9},{1,5,7}};
	int a = array[0][1];
	int *input = &a;
	int **input4 = &input;
	//memcpy(input4, array, sizeof(array));
	printf("%d\n", **input4);
	
	//int a = 3;
	//char c[4];
	//memcpy(c , &a , 4);
	//int b = 0;
	//memcpy(&b , c , 4);
	//printf("%d %d %d", a, *c, b);
	
	return 0;
}
