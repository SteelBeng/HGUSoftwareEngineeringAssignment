#include "MyMain.h"

bool InitStack(Stack& s)//ջ�ĳ�ʼ��
{
	s.base = new BiTree[MAXSIZE];
	if (!s.base) return false;
	s.top = s.base;
	s.stackSize = MAXSIZE;
	return true;
}

bool Push(Stack& s, BiTree c)//ջ�Ľ�ջ
{
	if (s.top - s.base == s.stackSize) return false;
	*s.top = c;
	s.top++;
	return true;
}

bool Pop(Stack& s, BiTree& c)//ջ�ĳ�ջ
{
	if (s.top == s.base) return false;
	c = *--s.top;
	return true;
}

bool StackEmpty(Stack s)//�ж�ջ��
{
	return s.base == s.top;
}

