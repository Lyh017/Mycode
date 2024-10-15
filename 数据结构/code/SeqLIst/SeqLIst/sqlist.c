#include "sqlist.h"

void SeqlistInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
void SeqlistPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void CheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDatatype* tmp = (SQDatatype*)realloc(ps->a, newcapacity * sizeof(SQDatatype));
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

void SeqlistPushBack(SL* ps, SQDatatype x)
 {
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqlistPushFront(SL* ps, SQDatatype x)
{
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqlistPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}
void SeqlistPopFront(SL* ps)
{
	assert(ps->size > 0);
	int start = 0;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}
void SeqlistInsert(SL* ps, int pos, SQDatatype x)
{
	assert(pos < ps->size);
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;


}
void SeqlistErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int start = pos;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}
void SeqlistDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

int SeqlistFind(SL* ps, SQDatatype x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqlistModify(SL* ps, int pos, SQDatatype x)
{
	assert(pos < ps->size);
	ps->a[pos] = x;
}