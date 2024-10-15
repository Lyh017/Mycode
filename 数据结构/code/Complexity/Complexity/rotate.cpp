#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
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
}    //时间复杂度O(k*N)，会超时


//思路二，空间换时间

//思路三，后k个逆置，前n-k个逆置，再整体逆置
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
		k = k % numsSize;//防止越界，这是一个循环的过程
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
//每个元素交换两次，时间复杂度O(2n)=O(n),空间复杂度O(1)



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