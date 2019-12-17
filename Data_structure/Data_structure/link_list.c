#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
	链表学习
*/

typedef struct node {
	int data;	//数据域
	struct node * next;//指向下一个指针
}linklist;

//建立一个空的单链表
linklist *init() {
	return NULL;
}

//输出单链表的每个元素的值
void display(linklist *l)
{
	linklist *p;
	p = l;
	if (p == NULL)
	{
		printf("数据为空！");
		return;
	}
	else
	{
		while (p)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}

}

//查找第i个元素
linklist *find(linklist *head, int i)
{
	int j = 1;
	linklist *p = head;
	while (p!=NULL && j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//查找元素为x的节点
linklist *findx(linklist *head, int x)
{
	linklist *p = head;
	while (p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}

//插入
linklist *insert(linklist *head, int x, int i)
{
	linklist *p, *q;
	q = find(head, i-1);/*查找第i个结点*/
	if (!q&&i != 1)
		printf("\n 不能找到第: %d 个节点，不能插入 %d\n", i-1 x);
	else
	{
		p = (linklist*)malloc(sizeof(linklist));/*分配空间*/
		p->data = x;/*设置新结点*/
		if (i == 1) /* 插入的结点作为单链表的第一个结点*/
		{
			p->next = head;  /*插入(1)*/
			head = p; /*插入(2)*/
		}
		else
		{
			p->next = q->next;/*插入(1)*/
			q->next = p;/*插入(2)*/
		}
	}
	return head;
}

//删除第i个位置的节点
linklist *dele(linklist *head, int i)
{
	linklist *pre = NULL, *p;
	if (head == NULL)
	{
		printf("单链表为空\n");
		return head;  //单链表为空
	}
	if (i == 1)
	{
		/* 若要删除的是表的第一个结点 */
		p = head; /*p指向第1个结点*/
		head = head->next; /*从链表中删除*/
		free(p);  /*释放被删除结点 */
		return head;
	}
	pre = find(head, i - 1);/*pre是第i个结点的前驱结点*/

	if (pre == NULL || pre->next == NULL)
	{
		printf("查找失败 %d", i);
		return head;
	}
	else
	{
		p = pre->next;
		pre->next = p->next;
		free(p);
		return head;
	}
}

//删除元素为x位置的元素
linklist *deleX(linklist *head, int x)
{
	linklist *pre = NULL, *p;
	if (!head)
	{
		printf("list is empty！");
		return head;
	}
	p = head;
	while (p&&p->data != x)/*没有找到并且没有找完*/
	{
		pre = p;    /*pre指向p的前驱结点*/
		p = p->next;
	}

	if (!p)
	{
		printf("find Error :%d is not in", x);
		return head;//没有找到
	}

	if (!pre&&p->data == x)/*要删除的是第一个结点*/
		head = head->next;/*删除(1)*/
	else
		pre->next = p->next;
	free(p);
	return head;
}

//创建单链表(头创建)
linklist * creatlistf()
{
	int data;
	linklist * head, *s;
	head = NULL;
	scanf("%d", &data);
	while (data != 0)
	{
		s = (linklist *)malloc(sizeof(linklist));
		s->data = data;
		s->next = head;
		head = s;
		scanf("%d", &data);
	}
	return head;
}

//尾创建
linklist* creatlistr()
{
	int data;
	linklist *head, *s, *r;
	head = NULL;
	r = NULL;
	scanf("%d", &data);
	while (data)
	{
		s = (linklist *)malloc(sizeof(linklist));
		s->data = data;     /*产生新结点*/
		if (head == NULL)   head = s;  /*新结点插入空表*/
		else     r->next = s;
		r = s;
		scanf("%d", &data);
	}               /*处理表尾结点指针域*/
	if (r != NULL)  r->next = NULL;
	return head;
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}