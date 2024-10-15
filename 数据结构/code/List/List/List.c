#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

ListNode* ListInit() //����һ����Ҫ�Ľڵ�
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)  //��ʹ�ǿ�����Ҳû��ϵ��pheadָ��ǰ��ָ�붼ָ���Լ�
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	
}
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		ListNode*Next = cur->next;
		free(cur);
		cur = Next;

	}
	free(phead);
	phead = NULL;
}

void ListPushBack(ListNode* phead, LTDatatype x)
{
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	//����
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

ListNode* BuyListNode(LTDatatype x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

void ListPushFront(ListNode* phead, LTDatatype x)
{
	assert(phead);
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	newnode->next = first;
	first->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	second->prev = phead;
	phead->next = second;
	free(first);
	first = NULL;
}

ListNode* ListFind(ListNode* phead, LTDatatype x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;

}

void ListInsert(ListNode* pos, LTDatatype x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}