#include "mymian.h"

int length;
void Sort()
{
	int list[Max];
	FILE* fp;
	fp = fopen("List.txt", "a+");
	fscanf(fp, "%d", &length);
	for (int i = 0; i < length; i++)
	{
		fscanf(fp, "%d", &list[i]);
	}
	fclose(fp);

	printf("\nֱ�Ӳ�������:");
	//InsertSort(list);
	printf("\nð������:");
	//BubbleSort(list);
	printf("\n��ѡ������:");
	//SelectSort(list);
	printf("\n��������:");
	QuickSort(list, 0, length - 1);
	Tervarse(list);
	printf("\nϣ������:");
	printf("\n������:");
}
void Tervarse(int list[])//�����������
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", list[i]);
	}
}
void Swap(int& a, int& b)//����
{
	int temp = a;
	a = b;
	b = temp;
}
void InsertSort(int list[])//ֱ�Ӳ�������
{
	for (int i = 1; i < length; i++)
	{
		if (list[i] < list[i - 1])  //С�������ӱ����ֵ ������ӱ� ����i++��Ϊ�µ����ֵ
		{
			list[length] = list[i]; //��������������ݴ�
			list[i] = list[i - 1];  //i-1����
			int j;
			for (j = i - 1; list[length] < list[j] ; j--)//�Ӻ���ǰѰ�Ҳ���λ��
			{
				list[j + 1] = list[j]; //�������
			}
			list[j + 1] = list[length];//���뵽��ȷλ��
		}
	}
	Tervarse(list);//�������
}
void BubbleSort(int list[])//ð������
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
	Tervarse(list);
}
void SelectSort(int list[])//��ѡ������
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
	Tervarse(list);
}

void QuickSort(int list[], int left, int right)//��������
{
	int low = left, high = right, mid;//ɨ���±� �� ���Ƚϵ��м�ֵ
	mid = list[(low + high) / 2];
	while (low <= high)
	{
		while (list[low] < mid && low < right) //������ɨ�� �ҵ������м�ֵ��������¼�±�low
			low++;
		while (list[high] > mid && high > left) //���ҵ���ɨ�� �ҵ�С���м�ֵ��������¼�±�high
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
void ShellSort(int list[], int dk)//ϣ������(ѡ��)
{

}
void HeapSort(int list[])//������(ѡ��)
{

}