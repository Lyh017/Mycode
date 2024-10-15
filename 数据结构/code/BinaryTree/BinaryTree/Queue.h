#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDatatype; //ǰ������
typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDatatype x);//��β��
void QueuePop(Queue* pq);//��ͷ��
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);