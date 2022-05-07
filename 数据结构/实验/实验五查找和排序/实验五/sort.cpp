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

	printf("\n直接插入排序:");
	//InsertSort(list);
	printf("\n冒泡排序:");
	//BubbleSort(list);
	printf("\n简单选择排序:");
	//SelectSort(list);
	printf("\n快速排序:");
	QuickSort(list, 0, length - 1);
	Tervarse(list);
	printf("\n希尔排序:");
	printf("\n堆排序:");
}
void Tervarse(int list[])//遍历输出数组
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", list[i]);
	}
}
void Swap(int& a, int& b)//交换
{
	int temp = a;
	a = b;
	b = temp;
}
void InsertSort(int list[])//直接插入排序
{
	for (int i = 1; i < length; i++)
	{
		if (list[i] < list[i - 1])  //小于有序子表最大值 则插入子表 否则i++成为新的最大值
		{
			list[length] = list[i]; //将待插入的数据暂存
			list[i] = list[i - 1];  //i-1后移
			int j;
			for (j = i - 1; list[length] < list[j] ; j--)//从后向前寻找插入位置
			{
				list[j + 1] = list[j]; //逐个后移
			}
			list[j + 1] = list[length];//插入到正确位置
		}
	}
	Tervarse(list);//遍历输出
}
void BubbleSort(int list[])//冒泡排序
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
void SelectSort(int list[])//简单选择排序
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

void QuickSort(int list[], int left, int right)//快速排序
{
	int low = left, high = right, mid;//扫描下标 与 待比较的中间值
	mid = list[(low + high) / 2];
	while (low <= high)
	{
		while (list[low] < mid && low < right) //从左到右扫描 找到大于中间值的数并记录下标low
			low++;
		while (list[high] > mid && high > left) //从右到左扫描 找到小于中间值的数并记录下标high
			high--;
		//如果low <= high 交换位置  如果low和high交错了 跳出循环
		if (low <= high)
		{
			Swap(list[low], list[high]);
			low++;
			high--;
		}
	}
	if (left < high) QuickSort(list, left, high); //对左子表递归排序
	if (low < right) QuickSort(list, low, right); //右子表
}
void ShellSort(int list[], int dk)//希尔排序(选做)
{

}
void HeapSort(int list[])//堆排序(选做)
{

}