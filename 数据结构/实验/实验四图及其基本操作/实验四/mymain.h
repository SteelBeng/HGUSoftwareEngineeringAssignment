#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MaxInt 100//����ֵ
#define MVNum 100//��󶥵���

//ͼ���ڽӾ���洢��ʾ
typedef struct
{
	char vex[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int arcnum, vexnum;//���� ����
}AMGraph;


//ͼ���ڽӱ�洢��ʾ
typedef struct ArcNode //�߽��
{
	int adjvex; //�ñ���ָ�Ķ���λ��
	struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
}ArcNode, * ArcPtr;
typedef struct VNode //������Ϣ
{
	char data;
	ArcNode* firstarc;//ָ���һ�������ö���ıߵ�ָ��
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;//������ ����
}ALGraph;

typedef struct
{
	char head;
	char tail;
	int lowcost;
}EdgeKruskal;//�������� Kruskal
typedef struct
{
	int adjvex;
	int lowcost;
}Edge;//�������� Prim

void CreateGraph(AMGraph& G);//�ڽӾ��� ����ͼ
int LocateVex(AMGraph G, int v);//���ڽӾ����ж�λv ������������±�
void DFS(AMGraph G, int v);//�ڽӾ��� ������ȱ���
void BFS(AMGraph G, int v);//�ڽӾ��� ������ȱ���

void CreateGraph(ALGraph& G);//�ڽӱ� ����ͼ
void DFS(ALGraph G, int v);//�ڽӱ� ������ȱ���
void BFS(ALGraph G, int v);//�ڽӱ� ������ȱ���

int MinNum(AMGraph G, Edge closedge[]);//prim �����к�ѡ�����ҳ�Ȩֵ��С�ı�
void MiniSpanTree_Prim(AMGraph G, char u);//��һ����ͨͼ����С������ Prim�㷨
void Sort(AMGraph G, EdgeKruskal*& closedge);//�Ը��������е�Ԫ�ذ�Ȩֵ��С��������
void MiniSpanTree_Kruskal(AMGraph G);//��һ����ͨͼ����С������ Kruskal�㷨
void ShortestPath_DIJ(AMGraph G, int v0);//��һ��ͼ�и����㵽����������������·�� �Ͻ�˹�����㷨
void CriticalPath(ALGraph G);//��һ�� AOE ���Ĺؼ�·��
void TopologicalSort(ALGraph G, int topo[]);//��һ�� AOV ������������

//����
typedef struct
{
	int *base;
	int front;
	int rear;
}Queue;
//���еĻ���������������
bool InitQueue(Queue& Q);//���еĳ�ʼ��
bool EnterQueue(Queue& Q, int c); //����
bool OutQueue(Queue& Q, int& c);//����
bool QueueEmpty(Queue Q);//�п�