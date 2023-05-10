#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
	char data;
	struct treeNode* LChild;
	struct treeNode* RChild;
}*LPTREE,TREE;

LPTREE createNode(char data)//开创节点，并赋值给节点
{
	LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
	if (newNode == NULL)exit(-1);
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}

void printCurNodeData(LPTREE CurNode)//打印当前节点数据
{
	printf("%c\t", CurNode->data);
}

//递归法打印
//前序遍历
void preOrder(LPTREE root)
{
	if (root != NULL)
	{
		printCurNodeData(root);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
//中序遍历
void midOrder(LPTREE root)
{
	if (root != NULL)
	{
		midOrder(root->LChild);
		printCurNodeData(root);
		midOrder(root->RChild);
	}
}
//后序遍历
void lastOrder(LPTREE root)
{
	if (root != NULL)
	{
		lastOrder(root->LChild);
		lastOrder(root->RChild);
		printCurNodeData(root);
	}
}
//运用函数的递归就很好地解决了问题，但是能不能不用递归来做呢？  可以的，可以用栈做


void insertNode(LPTREE parentNode, LPTREE LChild, LPTREE RChild)
{
	parentNode->LChild = LChild;
	parentNode->RChild = RChild;
}
int main()
{
	LPTREE A = createNode('A');
	LPTREE B = createNode('B');
	LPTREE C = createNode('C');
	LPTREE D = createNode('D');
	LPTREE E = createNode('E');
	LPTREE F = createNode('F');
	LPTREE G = createNode('G');
	insertNode(A, B, C);
	insertNode(B, D, E);
	insertNode(E, F, G);
	printf("前序遍历\n");
	preOrder(A);
	printf("\n");
	printf("中序遍历\n");
	midOrder(A);
	printf("\n");
	printf("后序遍历\n");
	lastOrder(A);

	return 0;
}