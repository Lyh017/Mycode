#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//˼·һ:��0��N����������ȥ����Ԫ�صĺ�
//˼·�������
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
