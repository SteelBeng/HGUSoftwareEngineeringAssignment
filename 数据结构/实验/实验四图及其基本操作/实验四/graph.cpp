#include "mymain.h"

void CreateGraph(AMGraph& G)//邻接矩阵 创建图
{
	FILE* fp;
	fp = fopen("scanf_AM.txt", "a+");
	//printf("请输入图的顶点数：");
	fscanf(fp, "%d", &G.vexnum);
	//printf("请输入图的边数：");
	fscanf(fp, "%d", &G.arcnum);
	fgetc(fp);
	for (int i = 0; i < G.vexnum; i++)
	{
		//printf("请输入第%d个顶点：", i + 1);
		fscanf(fp, "%c", &G.vex[i]);
		fgetc(fp);
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		char temp1, temp2;
		int power = 0;
		//printf("请输入第%d条边所依附的两个顶点及其权值：", i + 1);
		fscanf(fp, "%c", &temp1);
		fgetc(fp);
		fscanf(fp, "%c", &temp2);
		//getchar();
		fscanf(fp, "%d", &power);
		fgetc(fp);

		int m = LocateVex(G, temp1);
		int n = LocateVex(G, temp2);
		G.arcs[m][n] = power;
		G.arcs[n][m] = power;
	}
	fclose(fp);
}
int LocateVex(AMGraph G, int v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vex[i] == v) return i;
	}
	return -1;
}


void DFS(AMGraph G, int v)//邻接矩阵 深度优先遍历
{
	static bool visited[MVNum] = { false };
	printf("%c ", G.vex[v]);
	visited[v] = true;
	for (int i = 0; i < G.vexnum; i++)
	{
		if ((G.arcs[v][i] != 0) && (!visited[i])) DFS(G, i);
	}
}
void BFS(AMGraph G, int v)//邻接矩阵 广度优先遍历
{
	static bool visited[MVNum] = { false };
	Queue Q;
	InitQueue(Q);

	visited[v] = true;
	printf("%c ", G.vex[v]);
	EnterQueue(Q, v);

	while (!QueueEmpty(Q))
	{
		int e;
		OutQueue(Q, e);
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[e][j] != 0 && !visited[j])
			{
				printf("%c ", G.vex[j]);
				visited[j] = true;
				EnterQueue(Q, j);
			}
		}
	}
}


void CreateGraph(ALGraph& G)//邻接表 创建无向图
{
	FILE* fp;
	fp = fopen("scanf_AL.txt", "a+");
	//printf("请输入图的顶点数：");
	fscanf(fp, "%d", &G.vexnum);
	//printf("请输入图的边数：");
	fscanf(fp, "%d", &G.arcnum);
	fgetc(fp);
	for (int i = 0; i < G.vexnum; i++)
	{
		//printf("请输入第%d个顶点：",i+1);
		fscanf(fp, "%c", &G.vertices[i].data);
		fgetc(fp);
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		char temp1, temp2;
		int tempInt1 = 0, tempInt2 = 0;
		//printf("请输入第%d条边所依附的两个顶点：",i+1);
		fscanf(fp, "%c", &temp1);
		fgetc(fp);
		fscanf(fp, "%c", &temp2);
		fgetc(fp);
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.vertices[j].data == temp1) tempInt1 = j;
			if (G.vertices[j].data == temp2) tempInt2 = j;
		}
		ArcPtr p1 = new ArcNode;
		p1->adjvex = tempInt2;
		p1->nextarc = G.vertices[tempInt1].firstarc;
		G.vertices[tempInt1].firstarc = p1;

		ArcPtr p2 = new ArcNode;
		p2->adjvex = tempInt1;
		p2->nextarc = G.vertices[tempInt2].firstarc;
		G.vertices[tempInt2].firstarc = p2;
	}
	fclose(fp);
}
void DFS(ALGraph  G, int v)//邻接表 深度优先遍历
{
	static bool visited[MVNum] = { false };
	printf("%c ", G.vertices[v].data);
	visited[v] = true;
	ArcPtr p = G.vertices[v].firstarc;
	while (p)
	{
		int w = p->adjvex;
		if (!visited[w]) DFS(G, w);
		p = p->nextarc;
	}
}
void BFS(ALGraph G, int v)//邻接表 广度优先遍历
{
	static bool visited[MVNum] = { false };
	printf("%c ", G.vertices[v].data);
	visited[v] = true;
	Queue Q;
	InitQueue(Q);
	EnterQueue(Q, v);
	while (!QueueEmpty(Q))
	{
		int u;
		OutQueue(Q, u);
		ArcPtr p = G.vertices[u].firstarc;
		while (p)
		{
			if (!visited[p->adjvex])
			{
				printf("%c ", G.vertices[p->adjvex].data);
				visited[p->adjvex] = true;
				EnterQueue(Q, p->adjvex);
			}
			p = p->nextarc;
		}
	}
}

int MinNum(AMGraph G, Edge closedge[])//prim 在所有侯选边中找出权值最小的边
{
	int minCost = MaxInt, aim = 0;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (closedge[i].lowcost != 0 && minCost > closedge[i].lowcost)
		{
			aim = i;
			minCost = closedge[i].lowcost;
		}
	}
	return aim;
}

void MiniSpanTree_Prim(AMGraph G, char u)//求一个连通图的最小生成树 Prim算法
{
	int k = LocateVex(G, u);
	Edge* closedge = new Edge[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
	{
		if (i != k)
		{
			closedge[i].adjvex = k;
			closedge[i].lowcost = G.arcs[k][i];
		}
	}
	closedge[k].lowcost = 0;
	int count = 0;
	while(count != G.vexnum)
	{
		k = MinNum(G, closedge);
		if(count != 0) printf("%c %c\n", G.vex[closedge[k].adjvex], G.vex[k]);
		closedge[k].lowcost = 0;
		count++;
		for (int i = 0; i < G.vexnum; i++)
		{
			if (G.arcs[k][i] < closedge[i].lowcost)
			{
				closedge[i].adjvex = k;
				closedge[i].lowcost = G.arcs[k][i];
			}
		}
	}
}

void Sort(AMGraph G, EdgeKruskal*& closedge)//对辅助数组中的元素按权值从小到大排序
{
	int arcs = 0;
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[i][j] != MaxInt)
			{
				closedge[arcs].head = G.vex[i];
				closedge[arcs].tail = G.vex[j];
				closedge[arcs].lowcost = G.arcs[i][j];
				arcs++;
			}
		}
	}

	EdgeKruskal temp;
	for (int i = 0; i < G.arcnum * 2; i++)
	{
		for (int j = 0; j < G.arcnum * 2; j++)
		{
			if (closedge[j].lowcost > closedge[j + 1].lowcost)
			{
				temp = closedge[j];
				closedge[j] = closedge[j + 1];
				closedge[j + 1] = temp;
			}
		}
	}
	int mod2 = 0;
	for (int i = 0; i < G.arcnum*2; i++)
	{
		if (i % 2 == 0)
		{
			closedge[mod2] = closedge[i];
			mod2++;
		}
	}
}

void MiniSpanTree_Kruskal(AMGraph G)//求一个连通图的最小生成树 Kruskal算法
{
	EdgeKruskal* closedge = new EdgeKruskal[G.arcnum*2];
	Sort(G, closedge);
	int* Vexset = new int[G.vexnum];
	for (int i = 0; i < G.vexnum; i++)
	{
		Vexset[i] = i;
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		int v1 = LocateVex(G, closedge[i].head);
		int v2 = LocateVex(G, closedge[i].tail);
		int vs1 = Vexset[v1];
		int vs2 = Vexset[v2];
		if (vs1 != vs2)
		{
			printf("%c %c\n", closedge[i].head, closedge[i].tail);
			for (int j = 0; j < G.vexnum; j++)
			{
				if (Vexset[j] == vs2)
					Vexset[j] = vs1;
			}
		}
	}
}

void ShortestPath_DIJ(AMGraph G, int v0)//求一个图中给定点到其他各个顶点的最短路径 迪杰斯特拉算法
{
	int n = G.vexnum;
	for (int i = 0; i < n; i++)
	{

	}
}

void CriticalPath(ALGraph G)//求一个 AOE 网的关键路径
{

}

void TopologicalSort(ALGraph G, int topo[])//求一个 AOV 网的拓扑排序
{


}
