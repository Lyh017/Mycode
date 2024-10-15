#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

typedef char BTDatatype;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;//������
	struct BinaryTreeNode* right;//������
	BTDatatype data;
}BTNode;

void PrevOrder(BTNode* root)  //ǰ��
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root) //����
{
	
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}


void PostOrder(BTNode* root) //����
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

void TreeSize(BTNode* root,int* psize) //����ַ��ʵ��size�ĸı�
{
	if (root == NULL)
	{
		return;
	}
	else {
		++(*psize);
	}
	TreeSize(root->left, psize);
	TreeSize(root->right, psize);
}

int Tree_Size(BTNode* root)  //�������˼�룬�ȼ����������ټ���������������Լ�
{
	return root == NULL ? 0 : Tree_Size(root->left) + Tree_Size(root->right) + 1;
}

//Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

void LevelOrder(BTNode* root) //�������,��һ�����ʱ�����һ��Ľڵ�
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}

	}
	printf("\n");
	QueueDestory(&q);
}

void TreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
	//root = NULL;
}

int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");

	/*int ASize = Tree_Size(A);
	printf("%d \n", ASize);
	int LeafSize = TreeLeafSize(A);
	printf("LeafSize is %d\n", LeafSize);*/

	LevelOrder(A);

	/*int ASize = 0;
	int BSize = 0;
	TreeSize(A, &ASize);
	TreeSize(B, &BSize);
	printf("A TreeSize is %d\n", ASize);
	printf("B TreeSize is %d\n", BSize);*/

	return 0;
}