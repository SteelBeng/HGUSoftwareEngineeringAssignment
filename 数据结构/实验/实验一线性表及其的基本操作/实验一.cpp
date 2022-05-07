#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//链表的定义
typedef struct node
{
	int data;
	struct node* next;
}node, *link;

//定义一个状态 1为正常 0为异常
typedef int Status;

Status CreateLink(link& h, int n);//链表的初始化 返回一个状态
Status GetElem(link h, int i, int& e);//取值 用e返回链表中第i个元素的值
link FindLink(link h, int e);//找到链表中数据为e的一个结点并返回
Status InsertLink(link h, int i, int e);//插入 在第i个位置插入数据为e的结点
Status DelLink(link h, int i);//删除 删除第i个位置的结点
void Trave(link h);//遍历链表并输出数据
int GetLength(link h);//求表长并返回
void UnionSection(link& A, link B);//求集合的并集
void InterSection(link& A, link B);//求集合的交集

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
	printf("输入1求集合的交集，输入2求集合的并集。\n");
	scanf("%d", &i);

	switch (i)
	{
	case 1:
		InterSection(A, B);
		printf("求集合的交集:");
		Trave(A);
		break;
	case 2:
		UnionSection(A, B);
		printf("求集合的并集:");
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
		printf("input %d data：", i + 1);
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