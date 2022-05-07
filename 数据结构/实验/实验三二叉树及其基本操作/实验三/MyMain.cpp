#include "MyMain.h"

int main()
{
    printf("请按先序输入二叉树，空用#表示：");

    BiTree t;
    CreateTree(t);

    printf("二叉树先根递归遍历：");
    PreOrderFact(t);
    printf("\n");

    printf("二叉树中根递归遍历：");
    MidOrderFact(t);
    printf("\n");

    printf("二叉树后根递归遍历：");
    LastOrderFact(t);
    printf("\n");

    printf("二叉树先根非递归遍历：");
    PreOrder(t);

    printf("二叉树中根非递归遍历：");
    MidOrder(t);

    printf("二叉树叶子结点的个数：");
    printf("%d\n", LeavesNode(t));

    printf("二叉树的深度：");
    printf("%d\n", Depth(t));

    printf("按层遍历二叉树：");
    FloorOrder(t);

    return 0;
}

