#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
}queue;

//��ʼ������
queue *init()
{
	queue *q;
	q = (queue*)malloc(sizeof(queue));
	if (q == NULL)
		return NULL;
	q->front = q->rear = 0;
	return q;
}

//��Ӳ���
int push(queue *q,int x)
{
	if (q->rear == MAXSIZE) {
		printf("������");
		return 0;
	}
	q->data[q->rear] = x;
	q->rear++;
	return 1;
}

//���Ӳ���
int dele(queue*q)
{
	if (q->front == q->rear) {
		printf("�ӿ�");
		return 0;
	}
	q->front++;
	return 1;
}

//ѭ���������
int c_push(queue *q, int x)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("ѭ����������\n");
		return 0;
	}
	q->data[q->rear] = x;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}

//ѭ�����г���
int c_dele(queue *q)
{
	if (q->front == q->rear)
	{
		printf("ѭ������Ϊ��\n");
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