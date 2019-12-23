#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int key;
	struct node *lchild, *rchild;
}bsnode;

typedef bsnode *bstree;

//返回二叉排序树的地址
bstree bssearch1(bstree t, int x)
{
	bstree p = t;
	while (p)
	{
		if (x == p->key) return p;
		p = (x < p->key) ? p->lchild : p->rchild;
	}
	return NULL;
}

//递归查找
bstree bssearch2(bstree t, int x)
{
	if (t == NULL || x == t->key) return t;
	if (x < t->key) return bssearch2(t->lchild, x);
	else return bssearch2(t->rchild, x);
}

//插入
void InsertBstree(bstree *t, int x)
{
	bstree f, p;
	p = *t;
	while (p)
	{
		if (x == p->key) return;
		f = p;
		p = (x < p->key) ? p->lchild : p->rchild;
	}
	p = (bstree)malloc(sizeof(bsnode));
	p->key = x;
	p->lchild = p->rchild = NULL;
	if (*t == NULL) *t = p;
	else
		if (x < f->key) f->lchild = p;
		else f->rchild = p;
}

//创建
bstree CreateBstree(int r[], int n)
{
	int i;
	bstree t = NULL;
	for (i = 0; i < n; i++)
		InsertBstree(&t, r[i]);
	return t;
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}