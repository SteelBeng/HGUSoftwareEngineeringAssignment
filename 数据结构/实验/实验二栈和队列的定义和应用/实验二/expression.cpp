#include "stack.h"
#include "expression.h"

bool In(char ch)//判断ch是否是运算符
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == '-)' || ch == '#';
}

char Precede(char ch_1, char ch_2)//判断栈顶运算符 ch1 与栈外运算符 ch2 的优先级
{
	char m[7][7] = {
		{'>','>','<','<','<','>','>'},
		{'>','>','<','<','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'<','<','<','<','<','=','0'},
		{'>','>','>','>','0','>','>'},
		{'<','<','<','<','<','0','='},
	};
	int a = 0, b = 0;
	switch (ch_1)
	{
	case '+': a = 0; break;
	case '-': a = 1; break;
	case '*': a = 2; break;
	case '/': a = 3; break;
	case '(': a = 4; break;
	case ')': a = 5; break;
	case '#': a = 6; break;
	default: break;
	}
	switch (ch_2)
	{
	case '+': b = 0; break;
	case '-': b = 1; break;
	case '*': b = 2; break;
	case '/': b = 3; break;
	case '(': b = 4; break;
	case ')': b = 5; break;
	case '#': b = 6; break;
	default: break;
	}
	return m[a][b];
}

int Operate(int a, char theta, int b)//num1 与 num2 进程 ch 运算，结果返回
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default: return 0;
	}
}

int EvaluateExpression()//进行表达式求值的主体函数
{
	IntStack OPND;
	CharStack OPTR;
	char ch;
	int a, b;
	char theta;
	InitStack(OPND);
	InitStack(OPTR);
	Push(OPTR, '#');
	ch = getchar();
	while (ch != '#' || GetTop(OPTR) != '#')
	{
		if (!In(ch))
		{
			Push(OPND, ch - '0');
			ch = getchar();
			while (!In(ch))
			{
				int temp;
				Pop(OPND, temp);
				temp = temp*10 + (ch - '0');
				Push(OPND, temp);
				ch = getchar();
			}
		}
		if(In(ch))
		{
			switch (Precede(GetTop(OPTR), ch))
			{
			case '<':
				Push(OPTR, ch);
				ch = getchar();
				break;
			case '>':
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b));
				break;
			case '=':
				char x;
				Pop(OPTR, x);
				ch = getchar();
				break;
			}
		}
	}
	return GetTop(OPND);
}