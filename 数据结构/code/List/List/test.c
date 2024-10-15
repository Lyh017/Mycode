#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
void test1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushFront(plist, 5);
	ListPrint(plist);
	ListPopFront(plist);
	/*ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	*/
	ListPopBack(plist);
	ListPrint(plist);
	//ListDestory(plist);
}

void test2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushFront(plist, 5);
	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		pos->data *= 10;  //查找也可以修改
		printf("找到了,并且节点乘以10\n");
	}
	else
	{
		printf("找不到\n");
	}
	ListInsert(pos, 300);
	ListErase(pos);
	ListPrint(plist);
}

int main()
{
	test1();
	test2();
	return 0;
}