#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//思路一:把0到N加起来，减去数组元素的和
//思路二：异或
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	int i, j = 0;
	for (i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	for (j = 0; j < numsSize + 1; j++)
	{
		x ^= j;
	}
}

int missNum(int* nums, int numsSize)
{
	int sum = 0;
	int i, j = 0;
	for (i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}
	int ret = (numsSize + 1) * (0 + numsSize) / 2;
	return ret - sum;
}
