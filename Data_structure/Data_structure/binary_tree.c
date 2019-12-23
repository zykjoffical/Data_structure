#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node *lchild, *rchild;
}btnode;

typedef btnode * bttree;
bttree root;

//´´½¨
bttree createbttree()
{
	char ch; bttree t;
	if ((ch = getchar()) == '#')
		return NULL;
	else {
		t = (btnode *)malloc(sizeof(btnode));
		t->data = ch;
		t->lchild = createbttree();
		t->rchild = createbttree();
		return t;
	}
}

//±éÀú
void preorder(bttree t)
{
	if (t)
	{
		printf("%c", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}