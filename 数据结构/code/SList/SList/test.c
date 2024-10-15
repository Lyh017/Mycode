#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
void test1()
{
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPushFront(&phead, 0);
	//SListPopFront(&phead);
	//SListPopBack(&phead);
	//想在某个数的前面插入,删除一个数
	SLTNode* pos = SListFind(phead, 2);
	if (pos)
	{
		//SListInsert(&phead, pos, 17);
		SListErase(&phead, pos);
	}
	

	//SListPopFront(&phead);
	SListPrint(phead);
}

int main()
{
	test1();
	return 0;
}