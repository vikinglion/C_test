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

//定义树节点结构 
struct treeNode{
	char Element;
	struct treeNode * left;
	struct treeNode * right;
};
typedef struct treeNode TreeNode;
//树的先序创建函数 
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

//树的前序遍历函数
void PreOrderTree(TreeNode * Root){
	if (Root == NULL)
		return ;
	else{
		printf("%c",Root->Element);
		PreOrderTree(Root->left);
		PreOrderTree(Root->right);
	}
} 

//打印树的叶子节点函数
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
