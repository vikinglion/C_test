#include <stdio.h>
#include <string.h>

int main(void){
	char str[] = "lsjskt"; //a0 = "lsjkst"
	int * v0;
	int i = 0;
	
	while (1){
		if (str[i] == 107){
			printf("%c\n", str[i]);
			*v0 = str[i];
			printf("%d", v0);
			break; 
		}
		else if (str[i] == 0){
			v0 = NULL;
			printf("%d", v0);
			break;
		}
		i++;
	}
	return 0;
} 
