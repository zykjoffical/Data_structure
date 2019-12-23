#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
#define FINITY 5000 //5000���������
#define M 20
typedef struct {
	char vexs[M]; // ������Ϣ��
	int edges[M][M]; //�ڽӾ���
	int n, e; // �������������
}Mgraph;

void creat(Mgraph *g, int c)
{
	//c����0��ʾ�������磬��0��ʾ��������
	int i, j, k, w;
	scanf("%d,%d", &g->n, &g->e);
	for (i = 0; i < g->n; i++)
		scanf("%1s", &g->vexs[i]);
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			if (i == j) g->edges[i][j] = 0;
			else
				g->edges[i][j] = FINITY;
	for (k = 0; k < g->e; k++)
	{
		scanf("%d%d%d", &i, &j, &w);
		g->edges[i][j] = w;
		if (c == 0) g->edges[j][i] = w;

	}
}
*/

#define M 20
typedef struct node {
	int adjvex; //�ڽӵ�
	struct node *next;
}EdgeNode;

typedef struct vnode {
	char vertex;//������Ϣ
	EdgeNode *FirstEdge;//�ߵı�ͷָ��
}VertexNode;

typedef struct {
	VertexNode adjlist[M]; //��Ŷ����˳���
	int n, e; // ������ ����
}LinkedGraph;

void creat(LinkedGraph *g, int c)
{
	int i, j, k; EdgeNode *s;
	scanf("%d,%d", &g->n, &g->e);
	for (i = 0; i < g->n; i++)
	{
		scanf("%c", &g->adjlist[i].vertex); //��ȡ������Ϣ
		g->adjlist[i].FirstEdge = NULL; //�߱���Ϊ�ձ�
	}
	for (k = 0; k < g->e; k++)
	{
		scanf("%d,%d", &i, &j);
		s = (EdgeNode*)malloc(sizeof(EdgeNode)); s->adjvex = j;
		s->next = g->adjlist[i].FirstEdge;
		g->adjlist[i].FirstEdge = s;
		if (c == 0)
		{
			s = (EdgeNode*)malloc(sizeof(EdgeNode)); s->adjvex = i;
			s->next = g->adjlist[j].FirstEdge;
			g->adjlist[i].FirstEdge = s;
		}
	}
}


int visited[M]; //��ʾ�ýڵ��Ƿ񱻷���
//��ȱ���
void dfs(LinkedGraph g, int i)
{
	EdgeNode *p;
	printf("���� %c\n", g.adjlist[i].vertex);
	visited[i] = 1;
	p = g.adjlist[i].FirstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}

//��ȱ���ͼ
void DfsTraverse(LinkedGraph g)
{
	int i;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;
	for (i = 0; i < g.n; i++)
		if (!visited[i])
			if (!visited[i])
				dfs(g, i);
}

//��ȱ���
void bfs(LinkedGraph g, int i)
{
	int j; EdgeNode *p;
	int queue[M], front, rear; //�Ƚ��ȳ�����
	front = rear = 0;
	printf("%c ", g.adjlist[i].vertex);
	visited[i] = 1;
	queue[rear++] = i;
	while (rear > front)
	{
		j = queue[front++];
		p = g.adjlist[j].FirstEdge;
		while (p)
		{
			if (visited[p->adjvex] == 0)
			{
				prinf("%c", g.adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}

//��ȱ���ͼ
int BfsTraverse(LinkedGraph g)
{
	int i, count = 0;
	for (i = 0; i < g.n; i++)
		visited[i] = 0;
	for(i = 0;i<g.n;i++)
		if (!visited[i])
		{
			printf("\n");
			count++;
			bfs(g,i);
		}
	return count;
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}