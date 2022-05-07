#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MaxInt 100//����ֵ
#define MVNum 100//��󶥵���

//ͼ���ڽӾ���洢��ʾ
typedef struct
{
	string vex[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int arcnum, vexnum;//���� ����
}AMGraph;

typedef struct
{
	string head;
	string tail;
	int lowcost;
}EdgeKruskal;//�������� Kruskal

void CreateGraph(AMGraph& G);//�ڽӾ��� ����ͼ
int LocateVex(AMGraph G, string v);
void TraverseGraph(AMGraph G);
void Sort(AMGraph G, EdgeKruskal*& closedge);//�Ը��������е�Ԫ�ذ�Ȩֵ��С��������
void MiniTree(AMGraph G);//��һ����ͨͼ����С������ Kruskal�㷨
