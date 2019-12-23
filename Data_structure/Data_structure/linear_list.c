#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
	线性表学习
*/

#define MAXSIZE 50

typedef struct node {
	int data[MAXSIZE]; //数据域
	int length;	//元素长度
}seqlist;


//初始化线性表
void init(seqlist *L)
{
	L->length = 0;
}

//插入元素
void insert(seqlist *L, int data, int position)
{
	int i;
	if (L->length == MAXSIZE)
	{
		printf("元素已满，无法插入！\n");
		return;
	}
	if (position <= 0 || position > L->length)
	{
		printf("插入的位置不对！\n");
		return;
	}
	for (i = L->length; i > position-1; i--) // i = 最后一个元素后面的位置 
		L->data[i] = L->data[i - 1]; // 元素往后移
	L->data[position-1] = data; //将指定位置赋值
	L->length++; //长度+1

}


//删除元素
void Delete(seqlist *L, int position)
{
	int i;
	if (L->length == 0)
	{
		printf("元素已满，无法插入！\n");
		return;
	}
	if (position <= 0 || position > L->length)
	{
		printf("删除的位置不存在！\n");
		return;
	}

	for (i = position-1; i < L->length - 1; i++)
		L->data[i] = L->data[i + 1];
	L->length--;

}

//线性表末尾插入元素
void append(seqlist *L, int data)
{
	if (L->length == MAXSIZE)
	{
		printf("元素已经满了");
		return;
	}
	L->data[L->length] = data;
	L->length++;
}

//判断线性表是否为空
int empty(seqlist *L)
{
	return (L->length == 0 ? 1:0);
}

//返回线性表元素位置
int find(seqlist *L, int data)
{
	int i = 0;
	while (i < L->length && L->data[i] != data)
		i++;
	return (i < L->length ? i : -1);
}

//返回线性表第i个元素的位置
int getData(seqlist *L, int i)
{
	if (i <= 0 || i > L->length)
	{
		printf("i的位置不存在！");
		return 1;
	}
	return L->data[i - 1];
}

int main02()
{
	int i;
	//定义线性表
	seqlist l = { { 1,2,3,4,5 },5 };

	//插入元素
	insert(&l, 4, 3);

	//删除元素
	Delete(&l, 0);

	for (i = 0; i < l.length; i++)
		printf("%d ", l.data[i]);

	system("pause");
	return EXIT_SUCCESS;
}