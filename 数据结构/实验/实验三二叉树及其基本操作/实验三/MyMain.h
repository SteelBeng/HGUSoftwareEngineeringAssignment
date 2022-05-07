#pragma once
#define MY_MAIN

#include <stdio.h>
#include <iostream>
#define MAXSIZE 100

//������
typedef struct BiTNode
{
    char data;
    struct BiTNode* LChild, * RChild;
}BiTNode, * BiTree;//���������͵Ķ���

void CreateTree(BiTree& t);//�ȸ�������˳����һ�ö�����
void PreOrderFact(BiTree t);//�������ȸ��ݹ����
void MidOrderFact(BiTree t);//�������и��ݹ����
void LastOrderFact(BiTree t);//����������ݹ����

void PreOrder(BiTree t);//�������ȸ��ǵݹ����
void MidOrder(BiTree t);//�������и��ǵݹ����

int LeavesNode(BiTree t);//�������Ҷ�ӽ��ĸ���
int Depth(BiTree t);//������������
void FloorOrder(BiTree t);//�������������

//ջ
typedef struct
{
	BiTree* base;
	BiTree* top;
	int stackSize;
}Stack;//ջ���͵Ķ���

//ջ�Ļ���������������
bool InitStack(Stack& s); //ջ�ĳ�ʼ��
bool Push(Stack& s, BiTree c);//ջ�Ľ�ջ
bool Pop(Stack& s, BiTree& c);//ջ�ĳ�ջ
bool StackEmpty(Stack s);//�ж�ջ��

//����
typedef struct
{
	BiTree* base;
	int front;
	int rear;
}Queue;

//���еĻ���������������
bool InitQueue(Queue& Q);//���еĳ�ʼ��
bool EnterQueue(Queue& Q, BiTree c); //����
bool OutQueue(Queue& Q, BiTree &c);//����
bool QueueEmpty(Queue Q);//�п�