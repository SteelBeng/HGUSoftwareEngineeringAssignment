#include "MyMain.h"

bool InitStack(Stack& s)//栈的初始化
{
	s.base = new BiTree[MAXSIZE];
	if (!s.base) return false;
	s.top = s.base;
	s.stackSize = MAXSIZE;
	return true;
}

bool Push(Stack& s, BiTree c)//栈的进栈
{
	if (s.top - s.base == s.stackSize) return false;
	*s.top = c;
	s.top++;
	return true;
}

bool Pop(Stack& s, BiTree& c)//栈的出栈
{
	if (s.top == s.base) return false;
	c = *--s.top;
	return true;
}

bool StackEmpty(Stack s)//判断栈空
{
	return s.base == s.top;
}

