#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define Max 50

//索引表
typedef struct
{
	int key;  //最大关键字
	int start;//块开始下标
	int end;  //块结束下标
}Node;
typedef struct
{
	Node idx[5];  //表项
	int length;    //表长
}IdxTable;

void Search();
int SearchBlocking(IdxTable& table,int a[], int key);//分块查找

void Sort();
void Tervarse(int list[]);//遍历输出数组
void Swap(int& a, int& b);//交换
void InsertSort(int list[]);//直接插入排序
void BubbleSort(int list[]);//冒泡排序
void SelectSort(int list[]);//简单选择排序
void QuickSort(int list[], int left, int right);//快速排序
void ShellSort(int list[], int dk);//希尔排序(选做)
void HeapSort(int list[]);//堆排序(选做)
