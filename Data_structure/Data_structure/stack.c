#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef struct {
	int data[MAXSIZE];
	int top;
}stack;


//��ʼ��ջ
void init(stack *st)
{
	st->top = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int empty(stack st)
{
	return (st.top ? 0 : 1);
}

//��ȡջ��Ԫ�ص�ֵ
int read(stack st)
{
	if (empty(st))
	{
		printf("ջ�ǿյģ�\n");
		return;
	}
	else
		return st.data[st.top - 1];
}

//��ջ����
int push(stack *st, int x) 
{ 
	if (st->top == MAXSIZE) 
	{ 
		return 0; 
	} 
	st->data[st->top] = x; 
	st->top++; 
	return 1; 
} 

//��ջ����
int pop(stack *st) 
{ 
	if (st->top == 0) 
	{ 
		return 0; 
	} 
	st->top--;
	return 1; 
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}