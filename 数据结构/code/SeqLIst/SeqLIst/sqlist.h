#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define N 10
typedef int SQDatatype;  //�޸���������
//��̬˳���
struct SeqList1
{
	SQDatatype a[N];
	int size;
};
typedef struct SeqList1 SL1;
//��̬˳���
typedef struct Seqlist
{
	SQDatatype* a;
	int size;//��Ч���ݵĸ���
	int capacity;//����

}SL;
//��ɾ��ĺ���
void SeqlistInit(SL* ps);
//ͷ��β��ͷɾβɾ
void SeqlistPushBack(SL* ps, SQDatatype x);
void SeqlistPushFront(SL* ps, SQDatatype x);
void SeqlistPopBack(SL* ps);
void SeqlistPopFront(SL* ps);
void SeqlistPrint(SL* ps);
void CheckCapacity(SL* ps);
void SeqlistInsert(SL* ps,int pos, SQDatatype x);
void SeqlistErase(SL* ps, int pos);
void SeqlistDestroy(SL* ps);
int SeqlistFind(SL* ps, SQDatatype);
void SeqlistModify(SL* ps, int pos, SQDatatype x);
