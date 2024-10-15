#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDatatype;
typedef struct Stack
{
	STDatatype* a;
	int top;
	int capacity;

}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDatatype x);
void StackPop(ST* ps);

STDatatype StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);