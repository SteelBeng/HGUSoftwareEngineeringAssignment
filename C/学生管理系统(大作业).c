#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PEOPLE 30
#define CLASS 6

void inputRecord(int people,int classes);                       //录入
void calculate(int people, int classes);                            //计算每门课程总分平均分
void calculate_everyone(int people, int classes);            //计算每个学生总分平均分
void sortByScore(int people, int classes);                       //成绩从高到低
void sortByScore_2(int people, int classes);                   //成绩由低到高
void sortByNumber(int people, int classes);                  //学号从小到大
void sortByName(int people, int classes);                      //姓名从小到大 
void search(int people, int classes);                               //按学号查找
void searchName(int people, int classes);                     //按姓名查找
void analysis(int people, int classes);                             //分析
void list(int people, int classes);                                     //列出成绩与总分平均分
void printNumAndScore(int people, int classes);          //打印学号和成绩 

int menu()     //菜单
{
    printf("1. 录入每个学生的学号、姓名和各科考试成绩\n");
    printf("2. 计算每门课程的总分和平均分\n");
    printf("3. 计算每个学生的总分和平均分\n");
    printf("4. 按每个学生的总分由高到低排出名次表\n");
    printf("5. 按每个学生的总分由低到高排出名次表\n");
    printf("6. 按学号由小到大排出成绩表\n");
    printf("7. 按姓名的字典顺序排出成绩表\n");
    printf("8. 按学号查询学生排名及成绩\n");
    printf("9. 按姓名查询学生排名及成绩\n");
    printf("10. 成绩分析\n");
    printf("11. 输出每个学生的学号，姓名，各科考试成绩，以及每门课程的总分和平均分\n");
    printf("0. 退出\n");
    printf("请输入一个数字：");
    int a;
    scanf("%d",&a);
    return a;
}   

struct student
 {
    int StudentNum;
    char StudentName[30];
    float score[CLASS];
}stu[PEOPLE];

int main()
{  

    int flag=1;    //循环标志
    int people,classes;             //学生人数
    int a=menu();
    printf("请输入需要录入的学生人数与课程门数（中间用空格分开）：");
    scanf("%d %d",&people,&classes);
    do
    {
        if (a == 1)  inputRecord(people,classes);
        if (a == 2)  calculate(people, classes);
        if (a == 3)  calculate_everyone(people, classes);
        if (a == 4)  sortByScore(people, classes);
        if (a == 5)  sortByScore_2(people, classes);
        if (a == 6)  sortByNumber(people, classes);
        if (a == 7)  sortByName(people, classes);
        if (a == 8)  search(people, classes);
        if (a == 9)  searchName(people, classes);
        if (a == 10)  analysis(people, classes);
        if (a == 11)  list(people, classes);
        if (a == 0)  return 0;

        printf("按下回车重新进入菜单。\n");
        getchar();
        getchar();
        a = menu();
    } while (flag);
    return 0;
}

void printNumAndScore(int people, int classes)
{
    int i,j;
    printf("\n以下为现有的学生成绩数据：\n");
    for (i = 0; i < people; i++)
    {
        printf("学生的学号为%d，姓名为%s，成绩为",stu[i].StudentNum, stu[i].StudentName);
        for (j = 0; j < classes-1; j++)
        {
            printf("%.2f，", stu[i].score[j]);
        }
        printf("%.2f。\n", stu[i].score[classes-1]);
    }
    printf("\n");
}

void inputRecord(int people, int classes)
{
    int i,j;
    printf("请输入学号，姓名与成绩（中间用空格分开）：\n");
    for (i = 0; i < people; i++)
    {
        scanf("%d", &stu[i].StudentNum);
        scanf("%s", &stu[i].StudentName);
        getchar();
        for (j = 0; j < classes; j++)
        {
            scanf("%f", &stu[i].score[j]);
        }
    }
    printNumAndScore(people,classes);
}

void calculate(int people, int classes)
{
    int i,j;
    float avg, sum[CLASS] = { 0 };
    for (i = 0; i < classes; i++)
    {
        for (j = 0; j < people; j++)
        {
            sum[i] = sum[i] + stu[j].score[i];
        }
    }
    for (i = 0; i < classes; i++)
    {
        printf("第%d科的总分为%.2f,平均分为%.2f。\n", i,sum[i], sum[i] /(float)people );
    }
    
    printNumAndScore(people,classes);
}

void calculate_everyone(int people, int classes)
{
    int i,j;
    float avg, sum[PEOPLE] = { 0 };
    for (i = 0; i < people; i++)
    {
        for (j = 0; j < classes; j++)
        {
            sum[i] = sum[i] + stu[i].score[j];
        }
    }
    for (i = 0; i < people; i++)
    {
        printf("第%d号学生的总分为%.2f,平均分为%.2f。\n", stu[i].StudentNum, sum[i], sum[i] / (float)classes);
    }
    printNumAndScore(people,classes);
}

void sortByScore(int people, int classes)
{
    int i,j,n;
    float sum[PEOPLE] = {0};
    struct student* p=stu;
    struct student temp;
    float sumTemp;
    for (i = 0; i < people; i++)
    {
        for (j = 0; j < classes; j++)
        {
            sum[i] = sum[i] + stu[i].score[j];
        }
    }
    for (j = 0; j < people; j++)
    {
        for (i =j+1; i < people; i++)
        {
            if (sum[j] < sum[i])
            {
                temp =*(p+i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
                sumTemp = sum[i];
                sum[i] = sum[j];
                sum[j] = sumTemp;
            }
        }
    }
    
    printNumAndScore(people, classes);
}

void sortByScore_2(int people, int classes)
{
    int i,j,n;
    float sum[PEOPLE] = {0}, tempScore;
    float sumTemp;
    struct student* p=stu;
    struct student temp;
    for (i = 0; i < people; i++)
    {
        for (j = 0; j < classes; j++)
        {
            sum[i] = sum[i] + stu[i].score[j];
        }
    }
    for (j = 0; j < people; j++)
    {
        for (i =j+1; i < people; i++)
        {
            if (sum[j] > sum[i])
            {
                temp =*(p+i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
                sumTemp = sum[i];
                sum[i] = sum[j];
                sum[j] = sumTemp;
            }
        }
    }

    printNumAndScore(people, classes);
}

void sortByNumber(int people, int classes)
{
    int i, j, n;
    struct student* p = stu;
    struct student temp;
    for (j = 0; j < people; j++)
    {
        for (i = j + 1; i < people; i++)
        {
            if (stu[j].StudentNum > stu[i].StudentNum)
            {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    printNumAndScore(people, classes);
}

void sortByName(int people, int classes)
{
    int i, j, n;
    struct student* p = stu;
    struct student temp;
    for (j = 0; j < people; j++)
    {
        for (i = j + 1; i < people; i++)
        {
            if (strcmp(stu[j].StudentName , stu[i].StudentName)>0)
            {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    printNumAndScore(people, classes);
}

void search(int people, int classes)
{
    int find,i,j,rank=1;
    float findScore[CLASS];
    printf("请输入需要查询的学号：");
    scanf("%d", &find);
    for (i = 0; i < people; i++)
    {
        if (stu[i].StudentNum == find)
        {
            for (j = 0; j < classes; j++)
            {
                findScore[j] = stu[i].score[j];
            }
            printf("该学生的学号为%d，姓名为%s，成绩为", stu[i].StudentNum, stu[i].StudentName);
            for (j = 0; j < classes; j++)
            {
                printf("%.2f ", findScore[j]);
            }
            printf("\n");
        }
    }
    printNumAndScore(people, classes);
}

void searchName(int people, int classes)
{
    int i,j,rank=1;
    char find[30];
    float findScore[CLASS];
    printf("请输入需要查询的姓名：");
    scanf("%s", &find);
    for (i = 0; i < people; i++)
    {
        if (stu[i].StudentName == find)
        {
            for (j = 0; j < classes; j++)
            {
                findScore[j] = stu[i].score[j];
            }
            printf("该学生的学号为%d，姓名为%s，成绩为", stu[i].StudentNum, stu[i].StudentName);
            for (j = 0; j < classes; j++)
            {
                printf("%.2f ", findScore[j]);
            }
            printf("\n");
        }
    }
    printNumAndScore(people, classes);
}


void analysis(int people, int classes)
{
    int i,j,class1=0,class2=0,class3=0,class4=0,class5=0;
    for (j = 0; j < classes; j++)
    {
        for (i = 0; i < people; i++)
        {
            if ((stu[i].score[j] <= 100) && (stu[i].score[j] >= 90)) class1++;
            if ((stu[i].score[j] <= 89) && (stu[i].score[j] >= 80)) class2++;
            if ((stu[i].score[j] <= 79) && (stu[i].score[j] >= 70)) class3++;
            if ((stu[i].score[j] <= 69) && (stu[i].score[j] >= 60)) class4++;
            if ((stu[i].score[j] <= 59) && (stu[i].score[j] >= 0)) class5++;
        }
        printf("第%d科中优秀的人数为%d，所占百分比为%.2f%%\n",j, class1, 100 * (float)class1 / (float)people);
        printf("第%d科中良好的人数为%d，所占百分比为%.2f%%\n", j,class2, 100 * (float)class2 / (float)people);
        printf("第%d科中中等的人数为%d，所占百分比为%.2f%%\n", j,class3, 100 * (float)class3 / (float)people);
        printf("第%d科中及格的人数为%d，所占百分比为%.2f%%\n", j,class4, 100 * (float)class4 / (float)people);
        printf("第%d科中不及格的人数为%d，所占百分比为%.2f%%\n\n",j, class5, 100 * (float)class5 / (float)people);
        
    }
    printNumAndScore(people, classes);
}

void list(int people, int classes)
{
    printNumAndScore(people,classes);
    calculate(people,classes);
}
