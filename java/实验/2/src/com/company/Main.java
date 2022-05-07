package com.company;

import java.util.Scanner;

public class Main {
    //求一元二次方程的根
    public static void gen()
    {
        int a, b, c;
        Scanner scanner = new Scanner(System.in);
        System.out.println("1.求一元二次方程的根：");
        System.out.println("请输入方程的系数a、b、c：");
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        int delta = b*b - 4*a*c;
        double x1, x2;

        if(delta<0)
        {
            System.out.println("方程无实根！\n");
            return;
        }
        x1 = (-b + Math.sqrt(delta)) / (2*a);
        x2 = (-b - Math.sqrt(delta)) / (2*a);

        System.out.println("方程的两个根为：" + x1 + " " + x2 + "\n");
    }

    //求区间[100，999]上的所有水仙花数
    public static void shuiXianHuo()
    {
        System.out.println("2.求区间[100，999]上的所有水仙花数：");
        int count = 0, b, s, g;
        for(int i = 100; i <= 999; i++)
        {
            b = i/100;
            s = (i - 100*b)/10;
            g = (i - s*10 - b*100);
            if(i == b*b*b + s*s*s + g*g*g)
            {
                System.out.print(i + " ");
                count++;
            }
        }
        System.out.println();
        System.out.println("水仙花数一共有" + count + "个\n");
    }

    //打印九九乘法表
    public static void chengFaBiao()
    {
        System.out.println("3.打印九九乘法表：");
        for(int i = 1; i <= 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                while(j < i)
                {
                    System.out.print("\t\t");
                    j++;
                }
                System.out.print(i + "*" + j + "=" + i*j + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    //打印N*N螺旋矩阵
    public static void juZhen()
    {
        System.out.println("4.打印N*N螺旋矩阵：");
        System.out.println("请输入n的值：");
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int tempN = n;  //保存初始边长
        int a[][] = new int [n][n];
        int i, j, num = 0, first = 1;
        while(n>0)
        {
            a[num][num] = first;
            if(n>1)
            {
                for (i = num, j = num+1; j < n+num; j++)//从左到右
                {
                    a[i][j]=a[num][num]+j-num;
                }
                for (i = num+1, j = num+n-1; i < n+num; i++)//从上到下
                {
                    a[i][j]=a[i-1][j]+1;
                }
                for (i = num+n-1, j = num+n-2; j >= num; j--)//从右到左
                {
                    a[i][j]=a[i][j+1] + 1;
                }
                for (i = num+n-2, j = num; i >= num+1; i--)//从下到上
                {
                    a[i][j]=a[i+1][j] + 1;
                }
            }
            else break;

            first = first + 4*(n-1);
            n = n-2;
            num++;
        }
        for (i=0;i<tempN;i++)//打印矩阵
        {
            for (j = 0; j < tempN; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    //使用增强for循环语句遍历数组中的所有元素
    public static void tervarse() {
        System.out.println("5.使用增强for循环语句遍历数组中的所有元素：");
        int[] array = {1, 2, 3, 4, 5};
        for (int i : array)
        {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        System.out.println("@author 何雨彤420109070318");
        gen();
        shuiXianHuo();
        chengFaBiao();
        juZhen();
        tervarse();
    }
}
