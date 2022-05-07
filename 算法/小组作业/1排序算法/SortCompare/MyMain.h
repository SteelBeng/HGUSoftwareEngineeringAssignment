#pragma once
#include<iostream>
#include<ctime>

using namespace std;

void RandomArray(int length, int list[]);
void ShunxuArray(int length, int list[]);
void NixuArray(int length, int list[]);
void Swap(int& a, int& b);//交换
void InsertSort(int list[], int length);//直接插入排序
void BubbleSort(int list[], int length);//冒泡排序
void SelectSort(int list[], int length);//简单选择排序
void QuickSort(int list[], int left, int right);//快速排序
void HeapAdjust(int list[], int s, int m);//假设list[]已经是堆，将其调整为以list[s]为根的的大根堆
void CreatHeap(int list[], int length);//把无序序列建成大根堆
void HeapSort(int list[], int length);//堆排序(选做)