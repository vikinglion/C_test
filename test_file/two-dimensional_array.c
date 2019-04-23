#include <stdio.h>
#include <string.h>
#include <stdbool.h>

 
int main(void){
	int len = 3;
	int i = len;
	int n = 0;
	bool out = true;
	char str[i][20];
	while(out){
		printf("Please input the string you want to store.\n");
		scanf("%s", &str[n]);
		if(strcmp(str[n], "quit") == 0)
			out = false;
		n++;
	}
	for(n=0;n<i;n++){
		printf("str[%d]:%s\n", n, str[n]);	
	}
	return 0;
}

