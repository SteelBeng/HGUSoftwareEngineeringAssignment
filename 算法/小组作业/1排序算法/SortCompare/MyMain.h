#pragma once
#include<iostream>
#include<ctime>

using namespace std;

void RandomArray(int length, int list[]);
void ShunxuArray(int length, int list[]);
void NixuArray(int length, int list[]);
void Swap(int& a, int& b);//����
void InsertSort(int list[], int length);//ֱ�Ӳ�������
void BubbleSort(int list[], int length);//ð������
void SelectSort(int list[], int length);//��ѡ������
void QuickSort(int list[], int left, int right);//��������
void HeapAdjust(int list[], int s, int m);//����list[]�Ѿ��Ƕѣ��������Ϊ��list[s]Ϊ���ĵĴ����
void CreatHeap(int list[], int length);//���������н��ɴ����
void HeapSort(int list[], int length);//������(ѡ��)