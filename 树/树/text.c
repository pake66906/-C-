#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
	char data;
	struct treeNode* LChild;
	struct treeNode* RChild;
}*LPTREE,TREE;

LPTREE createNode(char data)//�����ڵ㣬����ֵ���ڵ�
{
	LPTREE newNode = (LPTREE)malloc(sizeof(TREE));
	if (newNode == NULL)exit(-1);
	newNode->data = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}

void printCurNodeData(LPTREE CurNode)//��ӡ��ǰ�ڵ�����
{
	printf("%c\t", CurNode->data);
}

//�ݹ鷨��ӡ
//ǰ�����
void preOrder(LPTREE root)
{
	if (root != NULL)
	{
		printCurNodeData(root);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}
//�������
void midOrder(LPTREE root)
{
	if (root != NULL)
	{
		midOrder(root->LChild);
		printCurNodeData(root);
		midOrder(root->RChild);
	}
}
//�������
void lastOrder(LPTREE root)
{
	if (root != NULL)
	{
		lastOrder(root->LChild);
		lastOrder(root->RChild);
		printCurNodeData(root);
	}
}
//���ú����ĵݹ�ͺܺõؽ�������⣬�����ܲ��ܲ��õݹ������أ�  ���Եģ�������ջ��


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
	printf("ǰ�����\n");
	preOrder(A);
	printf("\n");
	printf("�������\n");
	midOrder(A);
	printf("\n");
	printf("�������\n");
	lastOrder(A);

	return 0;
}