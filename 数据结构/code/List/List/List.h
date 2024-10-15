#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//双向带头循环链表
typedef int LTDatatype;
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDatatype data;
}ListNode;

//增删查改
ListNode* ListInit();
void ListDestory(ListNode* phead);
void ListPushBack(ListNode* phead, LTDatatype x);
ListNode* BuyListNode(LTDatatype x);
void ListPrint(ListNode* phead);
void ListPushFront(ListNode* phead, LTDatatype x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDatatype x);
void ListInsert(ListNode* pos, LTDatatype x);//在pos前插入数据
void ListErase(ListNode* pos);//删除pos处的值