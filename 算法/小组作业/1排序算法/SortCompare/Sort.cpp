#include "MyMain.h"

void RandomArray(int length, int list[])
{
	srand((unsigned int)time(0));
	for (int i = 0; i < length; i++)
	{
		list[i] = rand();
	}
}

void ShunxuArray(int length, int list[])
{
	for (int i = 0; i < length; i++)
	{
		list[i] = i;
	}
}

void NixuArray(int length, int list[])
{
	for (int i = length, j = 0; i > 0; i--, j++)
	{
		list[j] = i;
	}
}

void Swap(int& a, int& b)//����
{
	int temp = a;
	a = b;
	b = temp;
}
void InsertSort(int list[], int length)//ֱ�Ӳ�������
{
	for (int i = 1; i < length; i++)
	{
		if (list[i] < list[i - 1])
		{//С�������ӱ����ֵ ������ӱ� ����i++��Ϊ�µ����ֵ
			list[length] = list[i]; //��������������ݴ�
			list[i] = list[i - 1];  //i-1����
			int j;
			for (j = i - 1; list[length] < list[j]; j--)
			{//�Ӻ���ǰѰ�Ҳ���λ��
				list[j + 1] = list[j]; //�������
			}
			list[j + 1] = list[length];//���뵽��ȷλ��
		}
	}
}
void BubbleSort(int list[], int length)//ð������
{
	int m = length - 1;
	bool flag = true;
	while (m > 0 && flag)
	{
		flag = false;
		for (int i = 0; i < m; i++)
		{
			if (list[i] > list[i + 1])
			{
				flag = true;
				Swap(list[i], list[i + 1]);
			}
		}
		m--;
	}
}
void SelectSort(int list[], int length)//��ѡ������
{
	for (int i = 0; i < length - 1; i++)
	{
		int k = i;
		int j;
		for (j = i + 1; j < length; j++)
		{
			if (list[j] < list[k]) k = j;
		}
		if (k != j)
		{
			Swap(list[i], list[k]);
		}
	}
}

void QuickSort(int list[], int left, int right)//��������
{
	int low = left, high = right;//ɨ���±�
	int mid = list[(low + high) / 2];//���Ƚϵ�ֵ
	while (low <= high)
	{
		while (list[low] < mid && low < right)
			//������ɨ�� �ҵ�����key����¼�±�low
			low++;
		while (list[high] > mid && high > left)
			//���ҵ���ɨ�� �ҵ�С��key��������¼�±�high
			high--;
		//���low <= high ����λ��  ���low��high������ ����ѭ��
		if (low <= high)
		{
			Swap(list[low], list[high]);
			low++;
			high--;
		}
	}
	if (left < high) QuickSort(list, left, high); //�����ӱ�ݹ�����
	if (low < right) QuickSort(list, low, right); //���ӱ�
}
void HeapAdjust(int list[], int s, int len)
{//����list[]�Ѿ��Ƕѣ��������Ϊ��list[s]Ϊ���ĵĴ����
	//���ҽڵ������
	int left = 2 * s + 1;
	int right = 2 * s + 2;
	//Ĭ�ϵ�ǰ�ڵ������ֵ
	int largeIndex = s;
	if (left<len && list[left]>list[largeIndex])//����ڵ㲢����ڵ��ֵ����
	{
		largeIndex = left;
	}
	if (right<len && list[right]>list[largeIndex])
	{
		largeIndex = right;
	}
	if (largeIndex != s)
	{
		Swap(list[s], list[largeIndex]);//��ǰ�ڵ�����ֵ���ӽڵ�ֵ����
		HeapAdjust(list, largeIndex, len);//�Ը��ӽڵ���ӽڵ���е���
	}
}
void CreatHeap(int list[], int length)//���������н��ɴ����
{
	//�����һ����Ҷ��㿪ʼ��ǰ���� ʹ֮��Ϊ�����
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(list, i, length);
	}
}
void HeapSort(int list[], int length)//������
{
	int len = length;
	CreatHeap(list, length);   //���������
	for (int i = len - 1; i > 0; i--)
	{//�����Ѷ���ĩβ��� ���ô����
		Swap(list[0], list[i]);
		len--;
		HeapAdjust(list, 0, len);
	}
}