#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//����Ķ���
typedef struct node
{
	int data;
	struct node* next;
}node, *link;

//����һ��״̬ 1Ϊ���� 0Ϊ�쳣
typedef int Status;

Status CreateLink(link& h, int n);//����ĳ�ʼ�� ����һ��״̬
Status GetElem(link h, int i, int& e);//ȡֵ ��e���������е�i��Ԫ�ص�ֵ
link FindLink(link h, int e);//�ҵ�����������Ϊe��һ����㲢����
Status InsertLink(link h, int i, int e);//���� �ڵ�i��λ�ò�������Ϊe�Ľ��
Status DelLink(link h, int i);//ɾ�� ɾ����i��λ�õĽ��
void Trave(link h);//���������������
int GetLength(link h);//���������
void UnionSection(link& A, link B);//�󼯺ϵĲ���
void InterSection(link& A, link B);//�󼯺ϵĽ���

int main()
{
	link A, B;
	int m, n;

	printf("the data's number of A:");
	scanf("%d", &m);
	printf("the data's number of B:");
	scanf("%d", &n);
	CreateLink(A, m);
	CreateLink(B, n);

	int i;
	printf("����1�󼯺ϵĽ���������2�󼯺ϵĲ�����\n");
	scanf("%d", &i);

	switch (i)
	{
	case 1:
		InterSection(A, B);
		printf("�󼯺ϵĽ���:");
		Trave(A);
		break;
	case 2:
		UnionSection(A, B);
		printf("�󼯺ϵĲ���:");
		Trave(A);
		break;
	default:
		printf("ERROR");
		break;
	}

	return 0;
}

Status CreateLink(link& p, int n)
{
	p = (link)malloc(sizeof(node));
	p->next = NULL;
	for (int i = 0; i < n; i++)
	{
		link s = (link)malloc(sizeof(node));
		if (!s) return 0;
		printf("input %d data��", i + 1);
		scanf("%d", &s->data);
		if (!FindLink(p, s->data))
		{
			s->next = p->next;
			p->next = s;
		}
	}
	return 1;
}

Status GetElem(link h, int i, int& e)
{
	link p = (link)malloc(sizeof(node));
	p = h;
	int j = 0;
	while (p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if (j == i)
	{
		e = p->data;
		return 1;
	}
	else
	{
		return 0;
	}
}

link FindLink(link h, int e)
{
	link p = h;
	while (p->next)
	{
		p = p->next;
		if (p->data == e) return p;
	}
	return p->next;
}

Status InsertLink(link h, int i, int e)
{
	link p = h;
	int j = 0;
	if (i < 1) return 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (j != i - 1) return 0;
	link s = (link)malloc(sizeof(node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return i;
}

Status DelLink(link h, int i)
{
	link p = h;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j != i - 1) return 0;
	link q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

void Trave(link h)
{
	link p = h;
	printf("\noutput data\n");
	while (p->next)
	{
		p = p->next;
		printf("%d ", p->data);
	}
}

int GetLength(link h)
{
	link p = h;
	int j = 0;
	while (p->next)
	{
		p = p->next;
		j++;
	}
	return j;
}

void UnionSection(link& A, link B)
{
	int m = GetLength(A);
	int n = GetLength(B);
	link p = B->next;
	for (int i = 1; i <= n; i++)
	{
		GetElem(B, i, p->data);
		if (!FindLink(A, p->data))
		{
			InsertLink(A, ++m, p->data);
		}
		p = p->next;
	}
}

void InterSection(link& A, link B)
{
	int m = GetLength(A);
	int n = GetLength(B);
	link p = A->next;
	for (int i = 1; i <= m; i++)
	{
		GetElem(A, i, p->data);
		if (!FindLink(B, p->data))
		{
			link q = p->next;
			DelLink(A, i);
			i--;
			m--;
			p->next = q;
		}
		else
			p = p->next;
	}
}