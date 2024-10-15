#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ���
// [1,2,3,4,5,6,7]
void rotate1(int* nums, int numsSize, int k)
{
	while(k--)
	{
		int tmp = nums[numsSize - 1];
		for (int i = numsSize - 2; i >= 0; i--)
		{
			nums[i + 1] = nums[i];
		}
		nums[0] = tmp;
	}
}    //ʱ�临�Ӷ�O(k*N)���ᳬʱ


//˼·�����ռ任ʱ��

//˼·������k�����ã�ǰn-k�����ã�����������
void reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int temp = nums[right];
		nums[right] = nums[left];
		nums[left] = temp;
		left++;
		right--;
	}
}
void rotate(int* nums, int numsSize, int k)
{
	if (k > numsSize)
	{
		k = k % numsSize;//��ֹԽ�磬����һ��ѭ���Ĺ���
		reverse(nums, numsSize - k, numsSize - 1);
		reverse(nums, 0, numsSize - k - 1);
		reverse(nums, 0, numsSize - 1);
	}
	else
	{
		reverse(nums, numsSize - k, numsSize - 1);
		reverse(nums, 0, numsSize - k - 1);
		reverse(nums, 0, numsSize - 1);
	}
}
//ÿ��Ԫ�ؽ������Σ�ʱ�临�Ӷ�O(2n)=O(n),�ռ临�Ӷ�O(1)



int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	rotate(arr, sz, 10);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}