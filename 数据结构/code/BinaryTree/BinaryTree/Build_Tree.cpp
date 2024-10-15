#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//���ӣ�https://www.nowcoder.com/questionTerminal/4b91205483694f449f94c179883c1fef
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢����
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������

typedef struct TreeNode
{
	char val;
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;

TNode* CreateTree(char* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	TNode* root = (TNode*)malloc(sizeof(TNode));
	if (root == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	root->val = a[*pi];
	(*pi)++;
	root->left = CreateTree(a, pi);
	root->right = CreateTree(a, pi);
	return root; //���ص�ʱ����ǰһ�ڵ�����
}

void InOrder(TNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main()
{
	char str[100] = "abc##de#g##f###";
	//scanf("%s", str);
	int i = 0;
	TNode* root = CreateTree(str, &i);

	InOrder(root);

	return 0;
}