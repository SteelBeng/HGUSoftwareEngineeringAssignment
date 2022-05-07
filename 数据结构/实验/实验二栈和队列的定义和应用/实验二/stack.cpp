#include "stack.h"

//����ջ
bool InitStack(IntStack& s)//����ջ�ĳ�ʼ��
{
	s.base = (int*)malloc(MAXSIZE * sizeof(int));
	if (!s.base) return false;
	s.top = s.base;
	s.stackSize = MAXSIZE;
	return true;
}
bool Push(IntStack& s, int c)//����ջ�Ľ�ջ
{
	if (s.top - s.base == s.stackSize) return false;
	*s.top = c;
	s.top++;
	return true;
}
bool Pop(IntStack& s, int& c)//����ջ�ĳ�ջ
{
	if (s.top == s.base) return false;
	c = *--s.top;
	return true;
}
char GetTop(IntStack s)//����ջ��ȡջ��Ԫ��
{
	if (s.top != s.base) return *(s.top - 1);
	else return 0;
}

//�ַ�ջ
bool InitStack(CharStack& s)//�ַ�ջ�ĳ�ʼ��
{
	s.base = (char*)malloc(MAXSIZE * sizeof(char));
	if (!s.base) return false;
	s.top = s.base;
	s.stackSize = MAXSIZE;
	return true;
}

bool Push(CharStack& s, char c)//�ַ�ջ�Ľ�ջ
{
	if (s.top - s.base == s.stackSize) return false;
	*s.top = c;
	s.top++;
	return true;
}

bool Pop(CharStack& s, char& c)//�ַ�ջ�ĳ�ջ
{
	if (s.top == s.base) return false;
	c = *--s.top;
	return true;
}

char GetTop(CharStack s)//�ַ�ջ��ȡջ��Ԫ��
{
	if (s.top != s.base) return *(s.top - 1);
	else return 0;
}