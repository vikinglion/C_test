#include <stdio.h>

static int static_val = 0;

int main(){
	add();
	add2();
	printf("%d\n", static_val);
}

void add(){
	static_val += 10;
}

void add2(){
	static_val += 20;
}
