#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define N 30

void inputRecord(int num[],float score[],int n);                      //录入
void calculate(int num[],float score[],int n);                            //计算总分平均分
void sortByScore(int num[],float score[],int n);                       //成绩从高到低
void sortByNumber(int num[],float score[],int n);                  //学号从小到大
void search(int num[],float score[],int n);                               //按学号查找
void analysis(int num[],float score[],int n);                             //分析
void list(int num[],float score[],int n);                                     //列出成绩与总分平均分
void printNumAndScore(int num[], float score[], int n);        //打印学号和成绩 

int menu()     //菜单
{
    printf("1. 录入每个学生的学号和考试成绩\n");
    printf("2. 计算课程的总分和平均分\n");
    printf("3. 按成绩由高到低排出成绩表\n");
    printf("4. 按学号由小到大排出成绩表\n");
    printf("5. 按学号查询学生排名及成绩\n");
    printf("6. 成绩分析\n");
    printf("7. 输出每个学生的学号，考试成绩，总分和平均分\n");
    printf("0. 退出\n");
    printf("请输入一个数字：");
    int a;
    scanf("%d",&a);
    return a;
}
int main()
{  
    int num[N],flag=1;    //学号数组，循环标志
    float score[N];           //成绩数组
    int n;                         //学生人数
    int a=menu();
    printf("请输入需要录入的学生人数：");
    scanf("%d",&n);
    do
    {
        if (a == 1)  inputRecord(num,score,n);
        if (a == 2)  calculate(num,score,n);
        if (a == 3)  sortByScore(num, score, n);
        if (a == 4)  sortByNumber(num, score, n);
        if (a == 5)  search(num, score, n);
        if (a == 6)  analysis(num, score, n);
        if (a == 7)  list(num, score, n);
        if (a == 0)  return 0;

        printf("按下回车重新进入菜单。\n");
        getchar();
        getchar();
        a = menu();
    } while (flag);
    return 0;
}

void printNumAndScore(int num[], float score[], int n)
{
    int i;
    printf("\n以下为现有的学生成绩数据：\n");
    for (i = 0; i < n; i++)
    {
        printf("学生的学号为%d，成绩为%.2f。\n",num[i],score[i] );
    }
}

void inputRecord(int num[], float score[], int n)
{
    int i;
    printf("请输入学号与成绩（中间用空格分开）：\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %f", &num[i], &score[i]);
    }
    printNumAndScore(num, score, n);
}

void calculate(int num[],float score[], int n)
{
    int i;
    float avg, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + score[i];
    }
    printf("总分为%.2f,平均分为%.2f。\n\n", sum, sum / n);
    printNumAndScore(num, score, n);
}

void sortByScore(int num[], float score[], int n)
{
    int i,k,tempNum;
    float tempScore;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (score[i] < score[i + 1])
            {
                tempScore = score[i];
                score[i] = score[i + 1];
                score[i + 1] = tempScore;
                tempNum = num[i];
                num[i] = num[i + 1];
                num[i + 1] = tempNum;
            }
        }
    }
    printNumAndScore(num, score, n);
}

void sortByNumber(int num[], float score[], int n)
{
    int i, k, tempNum;
    float tempScore;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n-1; i++)
        {
            if (num[i] > num[i + 1])
            {
                tempScore = score[i];
                score[i] = score[i + 1];
                score[i + 1] = tempScore;
                tempNum = num[i];
                num[i] = num[i + 1];
                num[i + 1] = tempNum;
            }
        }
    }
    printNumAndScore(num, score, n);
}

void search(int num[], float score[], int n)
{
    int find,i,findScore,rank=1;
    printf("请输入需要查询的学号：");
    scanf("%d", &find);
    for (i = 0; i < n; i++)
    {
        if (num[i] == find)
        {
            findScore = score[i];
            printf("该学生的学号为%d，成绩为%.2f，", num[i], score[i]);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (score[i] > findScore) rank++;
    }
    printf("该学生是第%d名。\n",rank);
    printNumAndScore(num, score, n);
}

void analysis(int num[], float score[], int n)
{
    int i,class1=0,class2=0,class3=0,class4=0,class5=0;
    for (i = 0; i < n; i++)
    {
        if ((score[i] <= 100) && (score[i] >= 90)) class1++;
        if ((score[i] <= 89) && (score[i] >= 80)) class2++;
        if ((score[i] <= 79) && (score[i] >= 70)) class3++;
        if ((score[i] <= 69) && (score[i] >= 60)) class4++;
        if ((score[i] <= 59) && (score[i] >= 0)) class5++;
    }
    printf("优秀的人数为%d，所占百分比为%.2f%%\n", class1, 100 * (float)class1 / (float)n);
    printf("良好的人数为%d，所占百分比为%.2f%%\n", class2, 100 * (float)class2 / (float)n);
    printf("中等的人数为%d，所占百分比为%.2f%%\n", class3, 100 * (float)class3 / (float)n);
    printf("及格的人数为%d，所占百分比为%.2f%%\n", class4, 100 * (float)class4 / (float)n);
    printf("不及格的人数为%d，所占百分比为%.2f%%\n", class5, 100*(float)class5 / (float)n);
    printNumAndScore(num, score, n);
}

void list(int num[], float score[], int n)
{
    printNumAndScore(num, score, n);
    calculate(num, score, n);
}
