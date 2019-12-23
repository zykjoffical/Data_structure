#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}link_stack;

typedef link_stack *linkstack;

//获得链式栈的栈顶结点
int read(linkstack top)
{
	if (!top) {
		printf("链式栈为空\n");
		return 1;
	}
	return top->data;
}

//插入一个值为x的节点
linkstack push(linkstack top, int x)
{
	linkstack p;
	p = (linkstack)malloc(sizeof(link_stack));
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

//删除栈顶元素
linkstack pop(linkstack top)
{
	linkstack p;
	if (top == NULL) {
		printf("链式栈数据为空！\n");
		return top;
	}
	p = top;
	top = top->next;
	free(p);
	return top;
}

int main04()
{

	system("pause");
	return EXIT_SUCCESS;
}