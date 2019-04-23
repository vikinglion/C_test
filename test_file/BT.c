#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char Elementtype;
typedef struct TreeNode * Node;
char * str = "helloworld";
int i =0;
char mygetc(){
	return str[i++];
}

//�������ڵ�ṹ 
struct treeNode{
	char Element;
	struct treeNode * left;
	struct treeNode * right;
};
typedef struct treeNode TreeNode;
//�������򴴽����� 
TreeNode * CreateTree(){
	TreeNode * treeNode = NULL;
	char c = mygetc();
	printf("%c", c);
	if (c !='\0'){
		treeNode = (TreeNode *)malloc(sizeof(TreeNode));
		treeNode->Element = c;
		treeNode->left = CreateTree();
		treeNode->right = CreateTree();
	}
	else {
		return ;
	}
}

//����ǰ���������
void PreOrderTree(TreeNode * Root){
	if (Root == NULL)
		return ;
	else{
		printf("%c",Root->Element);
		PreOrderTree(Root->left);
		PreOrderTree(Root->right);
	}
} 

//��ӡ����Ҷ�ӽڵ㺯��
/*void LeafOfTree(PTREE Tree){
	if (Tree == NULL)
		return ;
	else{
		if (Tree->left == NULL && Tree->right == NULL)
			putchar(Tree->Element);
		else{
			LeafOfTree(Tree->left);
			LeafOfTree(Tree->right);
		}
	}
}
*/ 

int main(){
	printf("Please input information for every node\n");
	printf("the result is: ");
	PreOrderTree(CreateTree());
	return 0;
}
