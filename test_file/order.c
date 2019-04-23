#include <stdio.h>

int main(){
	char label[50][20];
	int i;
	
	for(i = 0; i < 50; i++){
		sprintf(label[i],"L%d",i);
		printf("%s\n", label[i]);
	}
	return 0;
}
