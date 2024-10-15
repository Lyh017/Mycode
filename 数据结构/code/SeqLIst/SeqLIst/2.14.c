#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
	int dst = 0;
	int src = 0;
	
	while (src < numsSize)
	{
		if (nums[src] == val)
		{
			src++;
			

		}
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			dst++;
			src++;
			

		}
		//else
		//{
			//src++;
		//}
	}
	return dst;
}

int main()
{
	int i = 0;
	int arr[] = { 6,7,2,1,4,5,6,1,1,1,1,1,8,1,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int ret=removeElement(arr, n, 1);
	for (i = 0; i < ret; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}