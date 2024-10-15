#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDatatype; //前置声明
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
void QueuePush(Queue* pq, QDatatype x);//队尾入
void QueuePop(Queue* pq);//队头出
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);