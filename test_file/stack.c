#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

struct stack{
	int sta[SIZE];
	int top;
};

typedef struct stack Stack;

void init_stack(Stack * s){
	memset(s->sta, 0, sizeof(s->sta));
	s->top = -1;
}

int push(Stack * s, int data){
	if(s->top == SIZE-1){
		printf("the stack is full\n");
		return 1;
	}
	(s->top)++;
	s->sta[s->top] = data;
	return 0;
}

int pop(Stack * s){
	int tmp;
	if(s->top < 0){
		printf("the stack is empty\n");
		return -1;
	}
	else{
		tmp = (s->sta)[s->top];
		(s->top)--;
		return tmp;
	}
}

void destroy(Stack * s){
	s->top = -1;
	memset(s->sta, 0, sizeof((s->sta)));
}

int main(){
	Stack * S = (Stack *) malloc(sizeof(Stack));
	init_stack(S);
	int i, ret;
	
	for(i=0; i<SIZE; i++){
		ret = push(S, i+10);
		if(ret > 0){
			printf("push error\n");
			exit(1);
		}
	}
	
	for(i=0; i<SIZE; i++){
		ret = pop(S);
		if(ret<0){
			printf("pop error\n");
			exit(1);
		}
		printf("%d\n", ret);
	}
	printf("\n");
	
	destroy(S);
	return 0;
}

