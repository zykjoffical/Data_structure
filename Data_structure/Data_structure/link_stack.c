#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}link_stack;

typedef link_stack *linkstack;

//�����ʽջ��ջ�����
int read(linkstack top)
{
	if (!top) {
		printf("��ʽջΪ��\n");
		return 1;
	}
	return top->data;
}

//����һ��ֵΪx�Ľڵ�
linkstack push(linkstack top, int x)
{
	linkstack p;
	p = (linkstack)malloc(sizeof(link_stack));
	p->data = x;
	p->next = top;
	top = p;
	return top;
}

//ɾ��ջ��Ԫ��
linkstack pop(linkstack top)
{
	linkstack p;
	if (top == NULL) {
		printf("��ʽջ����Ϊ�գ�\n");
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