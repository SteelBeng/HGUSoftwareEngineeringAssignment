#pragma once
#define MY_MAIN

#include <stdio.h>
#include <iostream>
#define MAXSIZE 100

//二叉树
typedef struct BiTNode
{
    char data;
    struct BiTNode* LChild, * RChild;
}BiTNode, * BiTree;//二叉树类型的定义

void CreateTree(BiTree& t);//先根遍历的顺序建立一棵二叉树
void PreOrderFact(BiTree t);//二叉树先根递归遍历
void MidOrderFact(BiTree t);//二叉树中根递归遍历
void LastOrderFact(BiTree t);//二叉树后根递归遍历

void PreOrder(BiTree t);//二叉树先根非递归遍历
void MidOrder(BiTree t);//二叉树中根非递归遍历

int LeavesNode(BiTree t);//求二叉树叶子结点的个数
int Depth(BiTree t);//求二叉树的深度
void FloorOrder(BiTree t);//按层遍历二叉树

//栈
typedef struct
{
	BiTree* base;
	BiTree* top;
	int stackSize;
}Stack;//栈类型的定义

//栈的基本操作函数声明
bool InitStack(Stack& s); //栈的初始化
bool Push(Stack& s, BiTree c);//栈的进栈
bool Pop(Stack& s, BiTree& c);//栈的出栈
bool StackEmpty(Stack s);//判断栈空

//队列
typedef struct
{
	BiTree* base;
	int front;
	int rear;
}Queue;

//队列的基本操作函数声明
bool InitQueue(Queue& Q);//队列的初始化
bool EnterQueue(Queue& Q, BiTree c); //进队
bool OutQueue(Queue& Q, BiTree &c);//出队
bool QueueEmpty(Queue Q);//判空