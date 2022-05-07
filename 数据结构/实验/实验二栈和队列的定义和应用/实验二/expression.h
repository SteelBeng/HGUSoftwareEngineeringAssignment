#ifndef MY_EXPRESSION

#define MY_ EXPRESSION

bool In(char ch);//判断ch是否是运算符
char Precede(char ch_1, char ch_2);//判断栈顶运算符 ch1 与栈外运算符 ch2 的优先级
int Operate(int a, char theta, int b);//num1 与 num2 进程 ch 运算，结果返回
int EvaluateExpression();//进行表达式求值的主体函数

#endif
