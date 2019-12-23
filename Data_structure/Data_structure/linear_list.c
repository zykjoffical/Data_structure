#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
	���Ա�ѧϰ
*/

#define MAXSIZE 50

typedef struct node {
	int data[MAXSIZE]; //������
	int length;	//Ԫ�س���
}seqlist;


//��ʼ�����Ա�
void init(seqlist *L)
{
	L->length = 0;
}

//����Ԫ��
void insert(seqlist *L, int data, int position)
{
	int i;
	if (L->length == MAXSIZE)
	{
		printf("Ԫ���������޷����룡\n");
		return;
	}
	if (position <= 0 || position > L->length)
	{
		printf("�����λ�ò��ԣ�\n");
		return;
	}
	for (i = L->length; i > position-1; i--) // i = ���һ��Ԫ�غ����λ�� 
		L->data[i] = L->data[i - 1]; // Ԫ��������
	L->data[position-1] = data; //��ָ��λ�ø�ֵ
	L->length++; //����+1

}


//ɾ��Ԫ��
void Delete(seqlist *L, int position)
{
	int i;
	if (L->length == 0)
	{
		printf("Ԫ���������޷����룡\n");
		return;
	}
	if (position <= 0 || position > L->length)
	{
		printf("ɾ����λ�ò����ڣ�\n");
		return;
	}

	for (i = position-1; i < L->length - 1; i++)
		L->data[i] = L->data[i + 1];
	L->length--;

}

//���Ա�ĩβ����Ԫ��
void append(seqlist *L, int data)
{
	if (L->length == MAXSIZE)
	{
		printf("Ԫ���Ѿ�����");
		return;
	}
	L->data[L->length] = data;
	L->length++;
}

//�ж����Ա��Ƿ�Ϊ��
int empty(seqlist *L)
{
	return (L->length == 0 ? 1:0);
}

//�������Ա�Ԫ��λ��
int find(seqlist *L, int data)
{
	int i = 0;
	while (i < L->length && L->data[i] != data)
		i++;
	return (i < L->length ? i : -1);
}

//�������Ա��i��Ԫ�ص�λ��
int getData(seqlist *L, int i)
{
	if (i <= 0 || i > L->length)
	{
		printf("i��λ�ò����ڣ�");
		return 1;
	}
	return L->data[i - 1];
}

int main02()
{
	int i;
	//�������Ա�
	seqlist l = { { 1,2,3,4,5 },5 };

	//����Ԫ��
	insert(&l, 4, 3);

	//ɾ��Ԫ��
	Delete(&l, 0);

	for (i = 0; i < l.length; i++)
		printf("%d ", l.data[i]);

	system("pause");
	return EXIT_SUCCESS;
}