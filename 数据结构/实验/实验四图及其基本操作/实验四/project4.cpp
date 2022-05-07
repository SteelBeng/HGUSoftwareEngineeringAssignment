#include "mymain.h"

int main()
{
    AMGraph G;
    CreateGraph(G);
    int a;
    char b;
    FILE* fp;
    fp = fopen("main.txt", "a+");
    fscanf(fp, "%d %c", &a, &b);
    printf("DFS\n");
    DFS(G, a-1);
    printf("\nBES\n");
    BFS(G, a - 1);
    printf("\nPrim\n");
    MiniSpanTree_Prim(G, b);
    printf("Kruskal\n");
    MiniSpanTree_Kruskal(G);
    return 0;
}