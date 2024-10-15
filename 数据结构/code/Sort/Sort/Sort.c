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
//��������
//ʱ�临�Ӷ�O(N^2)
//����������987654321����Ҫ�ƶ��Ĵ���Ϊ1��2��3��4��....n-1���Ȳ�����
//��������˳��O(N)
void InsertSort(int* a, int n)
{
	// [0,end]���򣬰�end+1λ�õ�ֵ���ȥ����[0,end+1]����
	for (int i = 0; i < n - 1; i++) //n-1,��ֹԽ��
	{
		int end = i; //��0��ʼ���룬�������˿���
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
		a[end + 1] = tmp;//������ѭ������������;����������break��Ȼ���������end�ĺ�һ��
	}
	
}

//ϣ������
//1.�Ƚ���Ԥ����������ӽ����� 2.ֱ�Ӳ�������
//������Ϊgap��Ԥ����gap�ɴ��С��gapԽ�󣬴����Խ��ĵ����棬С����Խ�쵽ǰ��
//gapԽ��Ԥ������Խ���ӽ�����gapԽС��Խ�ӽ����򣬵�gap==1ʱ�����ǲ�������
//ʱ�临�Ӷȣ�O(logN*N)
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)  //2^x = N ,ʱ�临�Ӷ�ΪlogN(2Ϊ��)
	{
		gap = gap / 2; //��֤���һ��Ϊ1������������,gap>1����Ԥ����
		//gap = gap / 3 + 1;
		//����ÿ��iֻ������һ����Ҳ����endÿ���������һ�����������԰Ѽ��Ϊgap�Ķ�������ͬʱ��
		//gap�ܴ�ʱ������Ԥ����ʱ�临�Ӷ�O(N),  gap��Сʱ��Ԥ�����Ѿ���ɣ��ܽӽ����򣬻���O(N)
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

//ֱ��ѡ������ O(N^2) N+N-1+N-2+......
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)  //��������
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; i++) //���������ҵ�һ�����ĺ���С��
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
		if (begin == maxi)  //��ֹbegin==maxiʱ�����ֵ�����ߣ�����һ���±�
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



//������,�����Ѱ���ѡ��,�Ѷ������������/С��

void AdjustDown(int* a,int n,int root)  //���µ����㷨�������������������Ǵ��orС��,�����Ǵ��
{
	int parent = root;
	int child = parent * 2 + 1; //Ĭ��������
	while (child < n)
	{
		//1.ѡ�����Һ����д���Ǹ�
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
void HeapSort(int* a,int n)  //����ʱ�临�Ӷȣ�O(N*logN)
{
	//���� ʱ�临�Ӷ�O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) //�����ĵ�һ����Ҷ�ӽڵ㿪ʼ���� ��child=(parent-1)/2
	{
		AdjustDown(a, n, i);
	}

	//�����򣬽���ѣ�������ｨС�ѣ������ҵ���С������
	//�����Ҵ�С������ʱ����Ҫ�õڶ�����ȥ������ʣ�µ����ĸ��ӹ�ϵȫ���ˣ�ֻ�����½��ѣ�Ч��̫�ͣ�����ֱ�ӱ���
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);  //���Ļ�����󣬲���������������ģ���ʱ���������������ѣ����µ����ҳ��δ��
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

//ð������
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


//����ȡ��  ������������������Ч�ʵ͵�����
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

//�ڿӷ�
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	while (begin < end)
	{
		//�ұ���С���ŵ����
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		//С�ķŵ���ߵĿ��ͬʱ�Լ��γɿ�λ
		a[pivot] = a[end];
		pivot = end;

		//����Ҵ󣬷����ұ�
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		//��ķŵ��ұߵĿ���Լ��γ��µĿ�
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

//����ָ�뷨
int PartSort2(int* a,int left,int right)  
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	
	int begin = left, end = right;
	int keyi = begin;
	
	while (begin < end)
	{
		//��С
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		//�Ҵ�
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);

	}

	Swap(&a[begin], &a[keyi]);
	
	return begin;

}

//ǰ��ָ�뷨
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

//��������
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

	//С�����Ż�
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


//��������ǵݹ�  �������ݽṹջģ�����
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

		int keyIndex = PartSort1(a, left, right); //��������
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



//�鲢����

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
			tmp[index++] = a[begin1++];     //�鲢�����ζԱ�ȡС�ķŽ��µ���ʱ����

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

	//������ȥ
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


//�鲢����ǵݹ�
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	int gap = 1; //ÿ�����ݸ���
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//�鲢�������Ұ����䲻����
			if (begin2 >= n)
			{
				break;
			}
			//�Ұ����������,����
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];     //�鲢�����ζԱ�ȡС�ķŽ��µ���ʱ����

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
			//������ȥ
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

//��������  ,ͳ�Ƴ��ֵĴ������ڶ�Ӧ����������ӳ��
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
	memset(count, 0, sizeof(int) * range); //��ʼ������Ϊ0
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;  //ͳ��λ���ϳ��ֵĴ���
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







// ������������ܶԱ�
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