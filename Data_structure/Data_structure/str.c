#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
typedef struct {
	char str[MAXSIZE];
	int length;
}seqstring;

//插入一个子串
void strinsert(seqstring *S,int i,seqstring T)
{
	int k;
	if (i<1 || i>S->length + 1 || S->length + T.length > MAXSIZE + 1)
	{
		printf("不能插入\n");
		return;
	}
	else {
		for (k = S->length - 1; k >= i - 1; k--) 
			S->str[T.length + k] = S->str[k];
			for (k = 0; k < T.length; k++)
				S->str[i + k - 1] = T.str[k];
			S->length = S->length + T.length;
			S->str[S->length] = "\0";
	}
}

//删除
void strdelete(seqstring *S,int i ,int len)
{
	int k;
	if (i<1 || i>S->length || i + len - 1 >S->length)
	{
		printf("不能删除\n");
		return;
	}
	else {
		for (k = i + len + 1; k < S->length; k++)
			S->str[k - len] = S->str[k];
		S->length = S->length - len;
		S->str[S->length] = "\0";
	}
}

//连接
seqstring *strconcat(seqstring S1, seqstring S2)
{
	int i; seqstring *r;
	if (S1.length + S2.length > MAXSIZE)
	{
		printf("连接失败\n");
		return NULL;
	}
	else {
		r = (seqstring *)malloc(sizeof(seqstring));
		for (i = 0; i < S1.length; i++)  r->str[i] = S1.str[i];
		for (i = 0; i < S2.length; i++) r->str[S1.length + i] = S2.str[i];
		r->length = S1.length + S2.length;
		r->str[r->length] = "\0";
	}
	return r;
}

//求子串
seqstring *substring(seqstring S, int i, int len)
{
	int k; seqstring *r;
	if (i<1||i>S.length|| i +len -1 >S.length)
	{
		printf("错误\n");
		return NULL;
	}
	else {
		r = (seqstring *)malloc(sizeof(seqstring));
		for (k = 0; k < len; k++)  r->str[k] = S.str[i+k-1];
		r->length = len;
		r->str[r->length] = "\0";
	}
	return r;
}

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}