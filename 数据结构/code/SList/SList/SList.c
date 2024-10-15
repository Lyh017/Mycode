#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
SLTNode* BuySListNode(SLTDatatype x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPushBack(SLTNode** pphead, SLTDatatype x)
{
	SLTNode* newnode = BuySListNode(x);
	if (*pphead == NULL)  //û�нڵ�ʱ��β��
	{
		*pphead = newnode;   //���ﲻ��ֱ��phead=newnode�����βε��޸Ĳ���Ӱ��ʵ��
	}
	else
	{
		//��β�ڵ��ָ��
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;//����β�ڵ�
	}
	
}

void SListPushFront(SLTNode** pphead, SLTDatatype x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;

}
void SListPopBack(SLTNode** pphead)
{
	//1.����Ϊ��
	if (*pphead == NULL)
	{
		return;
	}
	//2.ֻ��һ���ڵ�
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.һ�����Ͻڵ�
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	SLTNode* newnext = (*pphead)->next;
	free(*pphead);
	*pphead = newnext;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDatatype x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
	
}

void SListErase(SLTNode** pphead,SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
	
}

SLTNode* SListFind(SLTNode* phead, SLTDatatype x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
