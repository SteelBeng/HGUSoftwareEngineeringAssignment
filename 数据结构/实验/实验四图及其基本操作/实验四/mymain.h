#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MaxInt 100//极大值
#define MVNum 100//最大顶点数

//图的邻接矩阵存储表示
typedef struct
{
	char vex[MVNum];//顶点表
	int arcs[MVNum][MVNum];//邻接矩阵
	int arcnum, vexnum;//点数 边数
}AMGraph;


//图的邻接表存储表示
typedef struct ArcNode //边结点
{
	int adjvex; //该边所指的顶点位置
	struct ArcNode* nextarc; //指向下一条边的指针
}ArcNode, * ArcPtr;
typedef struct VNode //顶点信息
{
	char data;
	ArcNode* firstarc;//指向第一条依附该顶点的边的指针
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;//顶点数 边数
}ALGraph;

typedef struct
{
	char head;
	char tail;
	int lowcost;
}EdgeKruskal;//辅助数组 Kruskal
typedef struct
{
	int adjvex;
	int lowcost;
}Edge;//辅助数组 Prim

void CreateGraph(AMGraph& G);//邻接矩阵 创建图
int LocateVex(AMGraph G, int v);//在邻接矩阵中定位v 即顶点数组的下标
void DFS(AMGraph G, int v);//邻接矩阵 深度优先遍历
void BFS(AMGraph G, int v);//邻接矩阵 广度优先遍历

void CreateGraph(ALGraph& G);//邻接表 创建图
void DFS(ALGraph G, int v);//邻接表 深度优先遍历
void BFS(ALGraph G, int v);//邻接表 广度优先遍历

int MinNum(AMGraph G, Edge closedge[]);//prim 在所有侯选边中找出权值最小的边
void MiniSpanTree_Prim(AMGraph G, char u);//求一个连通图的最小生成树 Prim算法
void Sort(AMGraph G, EdgeKruskal*& closedge);//对辅助数组中的元素按权值从小到大排序
void MiniSpanTree_Kruskal(AMGraph G);//求一个连通图的最小生成树 Kruskal算法
void ShortestPath_DIJ(AMGraph G, int v0);//求一个图中给定点到其他各个顶点的最短路径 迪杰斯特拉算法
void CriticalPath(ALGraph G);//求一个 AOE 网的关键路径
void TopologicalSort(ALGraph G, int topo[]);//求一个 AOV 网的拓扑排序

//队列
typedef struct
{
	int *base;
	int front;
	int rear;
}Queue;
//队列的基本操作函数声明
bool InitQueue(Queue& Q);//队列的初始化
bool EnterQueue(Queue& Q, int c); //进队
bool OutQueue(Queue& Q, int& c);//出队
bool QueueEmpty(Queue Q);//判空