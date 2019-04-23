#include <stdio.h>

int main(){
	int num[10] = {1,2};
	int *ptr;
	ptr = num;
	printf("%d", *ptr);
	return 0;
}
