#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef struct {
	int data[MAXSIZE];
	int top;
}stack;


//初始化栈
void init(stack *st)
{
	st->top = 0;
}

//判断栈是否为空
int empty(stack st)
{
	return (st.top ? 0 : 1);
}

//获取栈顶元素的值
int read(stack st)
{
	if (empty(st))
	{
		printf("栈是空的！\n");
		return;
	}
	else
		return st.data[st.top - 1];
}

//入栈操作
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

//出栈操作
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