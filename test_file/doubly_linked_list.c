#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tokenNode{
	struct tokenNode *prev;
	struct tokenNode *next;
	void *data;
};

typedef struct tokenNode TokenNode;

struct tokenList{
	TokenNode * firstNode;
	TokenNode * lastNode; 
	int len;
};

typedef struct tokenList TokenList;

//连入头节点 
void push(TokenList * list, void * data){
	TokenNode * node = (TokenNode *)malloc(sizeof(TokenNode));
	node->data = data;
	node->prev = list->lastNode;
	if (list->lastNode != NULL){
		list->lastNode->next = node;
	}
	list->lastNode = node;
	if (list->len == 0){
		list->firstNode = node;
	}
	list->len++;
}

//获取指定位置上的节点值
/*void *getVal(TokenList * list, int pos){
	if (pos < 0)
		return NULL;
	int i;
	TokenNode * curNode = list->firstNode;
	for(i = 0; i < pos; i++){
		if (curNode->next != NULL){
			curNode = curNode->next;
		}
		else{
			curNode = NULL;
			break;	
		}
	}
	if (curNode == NULL){
		return NULL;
	}
	return curNode->data;
}
*/

static void print_r(TokenList * list){
	printf("len = %d\n", list->len);
	int i = 0;
	TokenNode * node = list->firstNode;
	while(i != list->len){
		if (node == NULL)
			break;
		printf("list[%d]: %s\n", i, node->data);
		node = node->next;
		i++;
	}
}

int main(){
	TokenList * list = (TokenList*)malloc(sizeof(TokenList));
	list->firstNode = NULL;
	list->lastNode = NULL;
	list->len =0;
	
	push(list, "node 0");
	push(list, "node 1");
	push(list, "node 2");
	
	print_r(list);
	return 0;
}
