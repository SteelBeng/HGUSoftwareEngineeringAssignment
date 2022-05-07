#include "mymain.h"

void CreateGraph(AMGraph& G)//邻接矩阵 创建图
{
	FILE* fp;
	fp = fopen("school.txt", "a+");
	//printf("请输入图的顶点数：");
	fscanf(fp, "%d", &G.vexnum);
	//printf("请输入图的边数：");
	fscanf(fp, "%d", &G.arcnum);
	fgetc(fp);
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			G.arcs[i][j] = MaxInt;
		}
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		//printf("请输入第%d个顶点：", i + 1);
		fscanf(fp, "%s", &G.vex[i]);
		fgetc(fp);
		printf("%s", G.vex[i]);
	}
	for (int i = 0; i < G.arcnum; i++)
	{
		string temp1, temp2;
		int power = 0;
		//printf("请输入第%d条边所依附的两个顶点及其权值：", i + 1);
		fscanf(fp, "%s", &temp1);
		fgetc(fp);
		fscanf(fp, "%s", &temp2);
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

int LocateVex(AMGraph G, string v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vex[i] == v) return i;
	}
	return -1;
}

void TraverseGraph(AMGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		
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
	for (int i = 0; i < G.arcnum * 2; i++)
	{
		if (i % 2 == 0)
		{
			closedge[mod2] = closedge[i];
			mod2++;
		}
	}
}

void MiniTree(AMGraph G)//求一个连通图的最小生成树 Kruskal算法
{
	EdgeKruskal* closedge = new EdgeKruskal[G.arcnum * 2];
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