#include "MyMain.h"

bool InitQueue(Queue& Q)//队列的初始化
{
	Q.base = new int[MaxInt];
	if (!Q.base) return false;
	Q.front = 0;
	Q.rear = 0;
	return true;
}
bool EnterQueue(Queue& Q, int c) //进队
{
	if ((Q.rear + 1) % MaxInt == Q.front) return false;
	Q.base[Q.rear] = c;
	Q.rear = (Q.rear + 1) % MaxInt;
	return true;
}
bool OutQueue(Queue& Q, int& c)//出队
{
	if (Q.front == Q.rear) return false;
	c = Q.base[Q.front];
	Q.front = (Q.front + 1) % MaxInt;
	return true;
}
bool QueueEmpty(Queue Q)//判空
{
	return Q.front == Q.rear;
}