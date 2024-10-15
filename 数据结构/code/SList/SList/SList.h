#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int SLTDatatype;
struct SListNode
{
	SLTDatatype data;
	struct SListNode* next;
};
typedef struct SListNode SLTNode;

SLTNode* BuySListNode(SLTDatatype x);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDatatype x);
void SListPushFront(SLTNode** pphead, SLTDatatype x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
void SListInsert(SLTNode** pphead,SLTNode* pos,SLTDatatype x);
void SListErase(SLTNode** pphead,SLTNode* pos);
SLTNode* SListFind(SLTNode* phead, SLTDatatype x);
