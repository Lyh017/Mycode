#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//˫���ͷѭ������
typedef int LTDatatype;
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDatatype data;
}ListNode;

//��ɾ���
ListNode* ListInit();
void ListDestory(ListNode* phead);
void ListPushBack(ListNode* phead, LTDatatype x);
ListNode* BuyListNode(LTDatatype x);
void ListPrint(ListNode* phead);
void ListPushFront(ListNode* phead, LTDatatype x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDatatype x);
void ListInsert(ListNode* pos, LTDatatype x);//��posǰ��������
void ListErase(ListNode* pos);//ɾ��pos����ֵ