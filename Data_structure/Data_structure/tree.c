#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define m 3 //度数
typedef struct node {
	char data;
	struct node *child[m]; //指向子女的指针数组
}node;

typedef node *tree;

tree root; //表示指向树节点的指针

void levlorder(tree t)
{

	tree queue[100], p;
	int front, rear, i;
	front = rear = 0;
	printf("%c", t->data);
	queue[rear++] = t;
	while (front < rear)
	{
		p = queue[front++];
		for(i = 0;i<m;++i)
			if (p->child[i])
			{
				printf("%c", p->child[i]->data);
				queue[rear++] = p->child[i];
			}
	}
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;

}