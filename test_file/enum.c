#include <stdio.h>

enum order {first, second, third};
typedef enum order Order;

Order token_type[3];

int main(void){
	token_type[2] = second;
	if (token_type[2] == 1)
		printf("test success");
	else
		printf("test failed");
	return 0;
}
