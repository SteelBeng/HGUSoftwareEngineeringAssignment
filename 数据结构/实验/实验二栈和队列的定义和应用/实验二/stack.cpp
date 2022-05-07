#include "stack.h"

//整数栈
bool InitStack(IntStack& s)//整数栈的初始化
{
	s.base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!s.base) return false;
	s.top = s.base;
	s.stackSize = MAXSIZE;
	return true;
}
bool Push(IntStack& s, int c)//整数栈的进栈
{
	if (s.top - s.base == s.stackSize) return false;
	*s.top = c;
	s.top++;
	return true;
}
bool Pop(IntStack& s, int& c)//整数栈的出栈
{
	if (s.top == s.base) return false;
	c = *--s.top;
	return true;
}
char GetTop(IntStack s)//整数栈的取栈顶元素
{
	if (s.top != s.base) return *(s.top - 1);
	else return 0;
}

//字符栈
bool InitStack(CharStack& s)//字符栈的初始化
{
	s.base = (char*)malloc(MAXSIZE * sizeof(char));
	if (!s.base) return false;
	s.top = s.base;
	s.stackSize = MAXSIZE;
	return true;
}

bool Push(CharStack& s, char c)//字符栈的进栈
{
	if (s.top - s.base == s.stackSize) return false;
	*s.top = c;
	s.top++;
	return true;
}

bool Pop(CharStack& s, char& c)//字符栈的出栈
{
	if (s.top == s.base) return false;
	c = *--s.top;
	return true;
}

char GetTop(CharStack s)//字符栈的取栈顶元素
{
	if (s.top != s.base) return *(s.top - 1);
	else return 0;
}