#include "sqlist.h"
void TestSqlist()
{
	SL sl;
	SeqlistInit(&sl);
	int i = 0;
	for (i = 0; i < 11; i++)
	{
		SeqlistPushBack(&sl, i);
	}
	SeqlistPushFront(&sl, 1);
	SeqlistPushFront(&sl, 2);
	SeqlistPushFront(&sl, 3);
	SeqlistPushFront(&sl, 4);
	
	SeqlistPrint(&sl);
	SeqlistPopBack(&sl);
	SeqlistPrint(&sl);
	SeqlistPopFront(&sl);
	SeqlistInsert(&sl,1,17);
	SeqlistPrint(&sl);
	SeqlistErase(&sl, 5);
	SeqlistPrint(&sl);
	SeqlistDestroy(&sl);

}
void menu()
{
	printf("******************************\n");
	printf("****1.尾插数据，2.头插数据****\n");
	printf("****3.尾删数据，4.头删数据****\n");
	printf("****5.查找数据，6.修改数据****\n");
	printf("****7.打印数据，0.退出********\n");
	printf("******************************\n");
	
	printf("请选择:>");
	

}
int main()
{
	int i = 0;
	int x = 0;
	SL sl;
	SeqlistInit(&sl);
	do
	{
			menu();
			scanf("%d", &i);
			switch (i)
			{
			case 1:
				printf("请输入要插入的数据，以-1结束\n");
				do {
					scanf("%d", &x);
					if (x != -1)
					{
						SeqlistPushBack(&sl, x);
					}
				} while (x != -1);
				break;
			case 2:
				break;
			case 7:
				SeqlistPrint(&sl);
				break;
			}
		
	} while (i != -1);
	//TestSqlist();
	return 0;
}