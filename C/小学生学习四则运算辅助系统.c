#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber()    //����һ�������
{
	int a = rand() % 10+1;
	return a;
}

int printfNumber()   //��ӡ���ֲ���ȡ�û����룬��ȷ����1�����󷵻�0
{
	int num_1, num_2,userInput;
	num_1 = randomNumber();
	num_2 = randomNumber();

	char a;
	int i;
	i = rand() % 4;
	switch (i)   //�������һ�������
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
	switch (a)    //������ȷ���
	{
	case '+': calculateResult = num_1 + num_2; break;
	case '-': calculateResult = num_1 - num_2; break;
	case '*': calculateResult = num_1 * num_2; break;
	case '/': calculateResult = num_1 / num_2; break;
	}

	if (calculateResult == userInput)  return 1;
	if (calculateResult != userInput)  return 0;

}

void randomRight()  //�������һ����ȷ��ʾ��
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

void randomWrong()   //�������һ��������ʾ��
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
	printf("**                  Сѧ��ѧϰ�������㸨��ϵͳ                 **\n");
	printf("**     ����1��������������Ĳ��� ����2��������������Ĳ���     **\n");
	printf("*****************************************************************\n");

	int a = getchar();

	srand(time(0));

	if (a == '1')   //��������������εĲ���
	{
		int i, j = 0, k = 0, m;
		//i���ڿ���ʮ�δ��⣬j������ȷ�Ĵ�����k�������Ĵ���
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
				if (k == 3)   //�������� ����
				{
					printf("Wrong!You have tried 3 times, test over.\n");
					break;
				}
			}	
		}
			
		
	}

	if (a == '2')    //��������������Ĳ���
	{

		int i, j = 0, k = 0, m, flag = 0;
		//i���ڿ���ʮ�δ��⣬j������ȷ�Ĵ�����k�������Ĵ���
		//flagΪ0ʱ��ȷ��С��75��Ϊ1ʱ����75

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