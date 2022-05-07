#include "MyMain.h"

void CreateTree(BiTree& t)//�ȸ�������˳����һ�ö�����
{
	char ch = getchar();
	if (ch == '#')
	{
		t = NULL;
	}
	else
	{
		t = new BiTNode;
		t->data = ch;
		CreateTree(t->LChild);
		CreateTree(t->RChild);
	}
}
void PreOrderFact(BiTree t)//�������ȸ��ݹ����
{
	if (t)
	{
		printf("%c ", t->data);
		PreOrderFact(t->LChild);
		PreOrderFact(t->RChild);
	}
}
void MidOrderFact(BiTree t)//�������и��ݹ����
{
	if (t)
	{
		MidOrderFact(t->LChild);
		printf("%c ", t->data);
		MidOrderFact(t->RChild);
	}
}
void LastOrderFact(BiTree t)//����������ݹ����
{
	if (t)
	{
		LastOrderFact(t->LChild);
		LastOrderFact(t->RChild);
		printf("%c ", t->data);
	}
}

void PreOrder(BiTree t)//�������ȸ��ǵݹ����
{
	Stack s;
	InitStack(s);
	BiTree p = t;
	BiTree q = new BiTNode;
	while (p || !StackEmpty(s))
	{
		if (p)
		{
			printf("%c ", p->data);
			Push(s, p);
			p = p->LChild;
		}
		else
		{
			Pop(s, q);
			p = q->RChild;
		}
	}
	printf("\n");
}
void MidOrder(BiTree t)//�������и��ǵݹ����
{
	Stack s;
	InitStack(s);
	BiTree p = t;
	BiTree q = new BiTNode;
	while (p||!StackEmpty(s))
	{
		if (p)
		{
			Push(s, p);
			p = p->LChild;
		}
		else
		{
			Pop(s, q);
			printf("%c ", q->data);
			p = q->RChild;
		}
	}
	printf("\n");
}

int LeavesNode(BiTree t)//�������Ҷ�ӽ��ĸ���
{
	static int number = 0;
	if (!t) return 0;
	else
	{
		if (!t->LChild && !t->RChild)
			number++;
		LeavesNode(t->LChild);
		LeavesNode(t->RChild);
	}
	return number;
}
int Depth(BiTree t)//������������
{
	if (!t) return 0;
	else
	{
		int m, n;
		m = Depth(t->LChild);
		n = Depth(t->RChild);
		if (m > n) return m + 1;
		else return n + 1;
	}
}
void FloorOrder(BiTree t)//�������������
{
	Queue q;
	InitQueue(q);
	BiTree p = t;
	EnterQueue(q, p);
	while (!QueueEmpty(q))
	{
		OutQueue(q, p);
		printf("%c", p->data);
		if (p->LChild) EnterQueue(q, p->LChild);
		if (p->RChild) EnterQueue(q, p->RChild);
	}
}