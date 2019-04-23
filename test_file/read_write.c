#include <stdio.h>

int main(){
	int i = 0;
	char n[100][100];
	char check_save[10];
	char check[] = "yes";
	char string[] = "end";
	printf("Do you want to save this data?(yes/no)\n");
	gets(check_save);
	printf("\n");
	if (strcmp(check_save,check)==0){
		FILE *fpWrite = fopen("data.txt", "w"); //写数据 
		if(fpWrite == NULL){
			return 0;
		}
		printf("Input 'end' to stop write the data\n\n");
		printf("Data have been saved in 'data.txt'\n");
		while(1){
		printf("Input: ");
		gets(n[i]);
		if(strcmp(n[i],string)==0)
            break;
        if(i != 0)
        	fprintf(fpWrite,"\n",n[i-1]); 
		fprintf(fpWrite,"%s",n[i]); 
		i++;
		}
		fclose(fpWrite);
	}
	
	printf("\n");
	char filename[20];
	printf("load: ");
	scanf("%s", &filename);
	printf("\n");
	char a[1024] = "\0";
	FILE *fpRead = fopen(filename, "r"); //读数据 
	if(fpRead == NULL){
		return 0;
	}
	while(!feof(fpRead)){
		fgets(a,1024,fpRead);
		printf("%s", a);	
	}
	
	return 0;
} 
