#ifndef MY_STACK

#define MY_STACK1
#include "mymain.h"
#define MAXSIZE 100

typedef struct
{
	char* base;
	char* top;
	int stackSize;
}CharStack;//字符栈类型的定义

typedef struct
{
	int* base;
	int* top;
	int stackSize;
}IntStack;//整数栈类型的定义

//栈的基本操作函数声明
bool InitStack(IntStack& s); //整数栈的初始化
bool Push(IntStack& s, int c);//整数栈的进栈
bool Pop(IntStack& s, int& c);//整数栈的出栈
char GetTop(IntStack s);//整数栈的取栈顶元素

bool InitStack(CharStack& s); //字符栈的初始化
bool Push(CharStack& s, char c);//字符栈的进栈
bool Pop(CharStack& s, char& c);//字符栈的出栈
char GetTop(CharStack s);//字符栈的取栈顶元素

#endif
