#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MaxInt 100//极大值
#define MVNum 100//最大顶点数

//图的邻接矩阵存储表示
typedef struct
{
	string vex[MVNum];//顶点表
	int arcs[MVNum][MVNum];//邻接矩阵
	int arcnum, vexnum;//点数 边数
}AMGraph;

typedef struct
{
	string head;
	string tail;
	int lowcost;
}EdgeKruskal;//辅助数组 Kruskal

void CreateGraph(AMGraph& G);//邻接矩阵 创建图
int LocateVex(AMGraph G, string v);
void TraverseGraph(AMGraph G);
void Sort(AMGraph G, EdgeKruskal*& closedge);//对辅助数组中的元素按权值从小到大排序
void MiniTree(AMGraph G);//求一个连通图的最小生成树 Kruskal算法
