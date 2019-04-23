#include <stdio.h>

int main(void){
	char stu_num[16] = "1609853mi0110036";
	int i = 0;
	
	while(1){
		if (stu_num[i] >= 48 && stu_num[i] <= 57){
			printf("%c", stu_num[i]);
		}
		else if (stu_num[i] == 0){
			break;
		}
		i++;
	}
	return 0;
} 
