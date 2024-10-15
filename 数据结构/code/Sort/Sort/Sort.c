#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
void printArr(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//插入排序
//时间复杂度O(N^2)
//最坏情况：逆序，987654321，需要移动的次数为1，2，3，4，....n-1，等差数列
//最好情况，顺序，O(N)
void InsertSort(int* a, int n)
{
	// [0,end]有序，把end+1位置的值插进去，让[0,end+1]有序
	for (int i = 0; i < n - 1; i++) //n-1,防止越界
	{
		int end = i; //从0开始插入，类似摸扑克牌
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}

		}
		a[end + 1] = tmp;//无论是循环结束还是中途结束，都是break，然后把数放在end的后一个
	}
	
}

//希尔排序
//1.先进行预排序，让数组接近有序 2.直接插入排序
//多组间隔为gap的预排序，gap由大变小，gap越大，大的数越快的到后面，小的数越快到前面
//gap越大，预排序完越不接近有序，gap越小，越接近有序，当gap==1时，就是插入排序
//时间复杂度：O(logN*N)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)  //2^x = N ,时间复杂度为logN(2为底)
	{
		gap = gap / 2; //保证最后一次为1，即插入排序,gap>1都是预排序
		//gap = gap / 3 + 1;
		//这里每次i只会增加一个，也就是end每次向后增加一个，这样可以把间隔为gap的多组数据同时排
		//gap很大时，下面预排序时间复杂度O(N),  gap很小时，预排序已经完成，很接近有序，还是O(N)
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}

			}
			a[end + gap] = tmp;
		}
	
	}
	
}
void TestShellSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	printArr(a, n);
}

//直接选择排序 O(N^2) N+N-1+N-2+......
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)  //更新区间
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++) //在区间内找到一个最大的和最小的
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)  //防止begin==maxi时，最大值被换走，更新一下下标
		{
			maxi = mini;
		}
		Swap(&a[maxi], &a[end]);
		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = {9,3,5,2,7,8,6,-1,1,9,4,0 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	printArr(a, n);
}



//堆排序,借助堆帮助选择,堆顶的数据是最大/小的

void AdjustDown(int* a,int n,int root)  //向下调整算法，必须满足左右子树是大堆or小堆,这里是大堆
{
	int parent = root;
	int child = parent * 2 + 1; //默认是左孩子
	while (child < n)
	{
		//1.选出左右孩子中大的那个
		if (a[child + 1] > a[child] && child + 1 < n)
		{
			child += 1;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a,int n)  //整体时间复杂度：O(N*logN)
{
	//建堆 时间复杂度O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) //倒数的第一个非叶子节点开始调整 ，child=(parent-1)/2
	{
		AdjustDown(a, n, i);
	}

	//排升序，建大堆，如果这里建小堆，可以找到最小的数，
	//但是找次小的数的时候需要拿第二个数去做根，剩下的树的父子关系全乱了，只能重新建堆，效率太低，不如直接遍历
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);  //最大的换到最后，不把它看做堆里面的，此时左右子树都满足大堆，向下调整找出次大的
		AdjustDown(a, end, 0);
		end--;
	}


}

void TestHeapSort()
{
	int a[] = {3,5,2,7,8,6,1,9,4,0 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
			
		}
		if (exchange = 0)
		{
			break;
		}
	}
}
void TestBubbleSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,-1,4,0 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}


//三数取中  解决快排在有序情况下效率低的问题
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else   //a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}

//挖坑法
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	while (begin < end)
	{
		//右边找小，放到左边
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		//小的放到左边的坑里，同时自己形成坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大，放在右边
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		//大的放到右边的坑里，自己形成新的坑
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

//左右指针法
int PartSort2(int* a,int left,int right)  
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	
	int begin = left, end = right;
	int keyi = begin;
	
	while (begin < end)
	{
		//找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		//找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);

	}

	Swap(&a[begin], &a[keyi]);
	
	return begin;

}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			++prev;
			Swap(&a[prev], &a[cur]);
		}

		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

//快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//int keyIndex = PartSort1(a, left, right);
	// int keyIndex = PartSort2(a, left, right);
	int keyIndex = PartSort3(a, left, right);

	
	//QuickSort(a, left, keyIndex - 1);
	//QuickSort(a, keyIndex + 1, right);

	//小区间优化
	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}
	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}
}

void TestQuickSort()
{
	int a[] = { 6,3,5,2,7,8,9,4,0,1};
	QuickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	printArr(a, sizeof(a) / sizeof(a[0]));
}


//快速排序非递归  利用数据结构栈模拟过程
void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		int keyIndex = PartSort1(a, left, right); //单趟排序
		if (keyIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyIndex + 1);
		}
		if (left < keyIndex - 1)
		{
			StackPush(&st,keyIndex - 1);
			StackPush(&st,left);
		}
	}
	StackDestory(&st);
}

void TestQuickSortNonR()
{
	int a[] = { 6,3,5,2,7,8,9,4,0,1 };
	QuickSortNonR(a,sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}



//归并排序

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];     //归并，依次对比取小的放进新的临时数组

		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	//拷贝回去
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}

}

void MergeSort(int* a,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);

}

void TestMergeSort()
{
	int a[] = { 6,3,5,2,7,8,9,4,0,1 };
	MergeSort(a,sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}


//归并排序非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1; //每组数据个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//归并过程中右半区间不存在
			if (begin2 >= n)
			{
				break;
			}
			//右半区间算多了,修正
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];     //归并，依次对比取小的放进新的临时数组

				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}

			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			//拷贝回去
			for (int j = i; j <= end2; ++j)
			{
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
	
}

void TestMergeSortNonR()
{
	int a[] = { 6,3,5,2,7,8,9,4,0,1 };
	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}

//计数排序  ,统计出现的次数，在对应的数组上做映射
void CountSort(int* a,int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range); //初始化次数为0
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;  //统计位置上出现的次数
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j] = i + min;
			j++;
		}
	}


	free(count);

}

void TestCountSort()
{
	int a[] = { 6,3,5,2,7,8,9,4,0,1,9,7,1,1};
	CountSort(a, sizeof(a) / sizeof(a[0]));
	printArr(a, sizeof(a) / sizeof(a[0]));
}







// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];

	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	//printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	//printf("MergeSort:%d\n", end6 - begin6);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

int main()
{

	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestQuickSort();
	//TestBubbleSort();
	//TestMergeSort();
	//TestQuickSortNonR();
	//TestMergeSortNonR();
	TestCountSort();
	return 0;
}