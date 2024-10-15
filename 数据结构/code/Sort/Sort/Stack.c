#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (STDatatype*)malloc(sizeof(STDatatype) * 4);
	ps->capacity = 4;
	ps->top = 0;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps,STDatatype x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDatatype* tmp = (STDatatype*)realloc(ps->a, ps->capacity * 2 * sizeof(STDatatype));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;

		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	//栈空了，直接报错
	assert(ps->top > 0);
	ps->top--;

}

STDatatype StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}