#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber()    //生成一个随机数
{
	int a = rand() % 10+1;
	return a;
}

int printfNumber()   //打印数字并读取用户输入，正确返回1，错误返回0
{
	int num_1, num_2,userInput;
	num_1 = randomNumber();
	num_2 = randomNumber();

	char a;
	int i;
	i = rand() % 4;
	switch (i)   //随机产生一个运算符
	{
	case 0: a = '+'; break;
	case 1: a = '-'; break;
	case 2: a = '*'; break;
	case 3: a = '/'; break;
	default: printf("error"); break;
	}

	printf("%d %c %d = ", num_1,a, num_2);
	scanf("%d", &userInput);

	float calculateResult;
	switch (a)    //计算正确结果
	{
	case '+': calculateResult = num_1 + num_2; break;
	case '-': calculateResult = num_1 - num_2; break;
	case '*': calculateResult = num_1 * num_2; break;
	case '/': calculateResult = num_1 / num_2; break;
	}

	if (calculateResult == userInput)  return 1;
	if (calculateResult != userInput)  return 0;

}

void randomRight()  //随机产生一个正确提示语
{
	int i = rand() % 4;
	switch (i)
	{
	case 0:printf("Very good!\n"); break;
	case 1:printf("Excellent!\n"); break;
	case 2:printf("Nice work!\n"); break;
	case 3:printf("Keep up the good work!\n"); break;
	default:printf("error\n"); break;
	}
}

void randomWrong()   //随机产生一个错误提示语
{
	int i = rand() % 4;
	switch (i)
	{
	case 0:printf("No.Please try again.\n"); break;
	case 1:printf("Wrong.Try once more.\n"); break;
	case 2:printf("Don't give up!\n"); break;
	case 3:printf("Not correct.Keep trying.\n"); break;
	default:printf("error\n"); break;
	}
}

int main()
{
	printf("*****************************************************************\n");
	printf("**                  小学生学习四则运算辅助系统                 **\n");
	printf("**     按下1进入有重做机会的测试 按下2进入无重做机会的测试     **\n");
	printf("*****************************************************************\n");

	int a = getchar();

	srand(time(0));

	if (a == '1')   //进入可以重做三次的测试
	{
		int i, j = 0, k = 0, m;
		//i用于控制十次答题，j计算正确的次数，k计算错误的次数
		for (i = 0; i < 10; i++)
		{
			m = printfNumber();
			if (m==1)
			{
				j++;
				k = 0;
				randomRight();
			}
			if (m==0)
			{
				k++;
				if (k < 3)
				{
					randomWrong();
				}
				if (k == 3)   //错误三次 结束
				{
					printf("Wrong!You have tried 3 times, test over.\n");
					break;
				}
			}	
		}
			
		
	}

	if (a == '2')    //进入无重做机会的测试
	{

		int i, j = 0, k = 0, m, flag = 0;
		//i用于控制十次答题，j计算正确的次数，k计算错误的次数
		//flag为0时正确率小于75，为1时大于75

		do
		{
			for (i = 0; i < 10; i++)
			{
				m = printfNumber();
				if (m == 1)
				{
					j++;
					randomRight();
				}
				if (m == 0)
				{
					k++;
					randomWrong();
				}
			}

			printf("Your score is %d,accuracy is %d%%.\n", 10 * j, 10 * j);
			flag = 1;

			if (10 * j < 75)
			{
				printf("Again!\n");
				flag = 0;
			}
		} while (flag == 0);
	}
	return 0;
}