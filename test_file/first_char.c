#include <stdio.h>

int main(){
	int i = 0;
	char* input = "wxh";
	char c;
	char pre_c;
  	char next_c;
	while(1){
		c = *(input + i);
		next_c = *(input + i + 1);
		pre_c = '\0';
		if(i != 0)
			pre_c = *(input + i - 1);
		printf("%c\n", c);
		i++;
		if (c == '\0')
			break;
	}
	if (*input == 'w')
		printf("w is the first character");
	return 0;
}
