#include "MyMain.h"

bool InitQueue(Queue& Q)//���еĳ�ʼ��
{
	Q.base = new BiTree[MAXSIZE];
	if (!Q.base) return false;
	Q.front = 0;
	Q.rear = 0;
	return true;
}
bool EnterQueue(Queue& Q, BiTree c) //����
{
	if ((Q.rear + 1) % MAXSIZE == Q.front) return false;
	Q.base[Q.rear] = c;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
bool OutQueue(Queue& Q, BiTree& c)//����
{
	if (Q.front == Q.rear) return false;
	c = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}
bool QueueEmpty(Queue Q)//�п�
{
	return Q.front == Q.rear;
}