#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define Max 50

//������
typedef struct
{
	int key;  //���ؼ���
	int start;//�鿪ʼ�±�
	int end;  //������±�
}Node;
typedef struct
{
	Node idx[5];  //����
	int length;    //��
}IdxTable;

void Search();
int SearchBlocking(IdxTable& table,int a[], int key);//�ֿ����

void Sort();
void Tervarse(int list[]);//�����������
void Swap(int& a, int& b);//����
void InsertSort(int list[]);//ֱ�Ӳ�������
void BubbleSort(int list[]);//ð������
void SelectSort(int list[]);//��ѡ������
void QuickSort(int list[], int left, int right);//��������
void ShellSort(int list[], int dk);//ϣ������(ѡ��)
void HeapSort(int list[]);//������(ѡ��)
