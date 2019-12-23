#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	int ltag, rtag;
	struct node *lchild, *rchild;
}btnode;

btnode *pre = NULL; //初始化前驱节点
void inthreading(btnode *p)
{
	if (p)
	{
		inthreading(p->lchild);
		p->ltag = (p->lchild != NULL) ? 0 : 1;
		p->rtag = (p->rchild != NULL) ? 0 : 1;
		if (pre) {
			if (pre->rtag == 1) pre->rchild = p;
			if (p->ltag == 1) p->lchild = pre;
		}
		pre = p;
		inthreading(p->rchild);
	}
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}