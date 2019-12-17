#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
}queue;

//初始化队列
queue *init()
{
	queue *q;
	q = (queue*)malloc(sizeof(queue));
	if (q == NULL)
		return NULL;
	q->front = q->rear = 0;
	return q;
}

//入队操作
int push(queue *q,int x)
{
	if (q->rear == MAXSIZE) {
		printf("队满了");
		return 0;
	}
	q->data[q->rear] = x;
	q->rear++;
	return 1;
}

//出队操作
int dele(queue*q)
{
	if (q->front == q->rear) {
		printf("队空");
		return 0;
	}
	q->front++;
	return 1;
}

//循环队列入队
int c_push(queue *q, int x)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("循环队列已满\n");
		return 0;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

//循环队列出队
int c_dele(queue *q)
{
	if (q->front == q->rear)
	{
		printf("循环队列为空\n");
		return 0;
	}
	q->front = (q->front + 1) % MAXSIZE;
	return 1;
}


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}