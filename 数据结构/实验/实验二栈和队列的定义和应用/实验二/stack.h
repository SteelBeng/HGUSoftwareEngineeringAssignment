#ifndef MY_STACK

#define MY_STACK1
#include "mymain.h"
#define MAXSIZE 100

typedef struct
{
	char* base;
	char* top;
	int stackSize;
}CharStack;//�ַ�ջ���͵Ķ���

typedef struct
{
	int* base;
	int* top;
	int stackSize;
}IntStack;//����ջ���͵Ķ���

//ջ�Ļ���������������
bool InitStack(IntStack& s); //����ջ�ĳ�ʼ��
bool Push(IntStack& s, int c);//����ջ�Ľ�ջ
bool Pop(IntStack& s, int& c);//����ջ�ĳ�ջ
char GetTop(IntStack s);//����ջ��ȡջ��Ԫ��

bool InitStack(CharStack& s); //�ַ�ջ�ĳ�ʼ��
bool Push(CharStack& s, char c);//�ַ�ջ�Ľ�ջ
bool Pop(CharStack& s, char& c);//�ַ�ջ�ĳ�ջ
char GetTop(CharStack s);//�ַ�ջ��ȡջ��Ԫ��

#endif
