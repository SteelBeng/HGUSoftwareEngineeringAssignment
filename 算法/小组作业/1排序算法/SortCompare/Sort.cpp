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

void Swap(int& a, int& b)//交换
{
	int temp = a;
	a = b;
	b = temp;
}
void InsertSort(int list[], int length)//直接插入排序
{
	for (int i = 1; i < length; i++)
	{
		if (list[i] < list[i - 1])
		{//小于有序子表最大值 则插入子表 否则i++成为新的最大值
			list[length] = list[i]; //将待插入的数据暂存
			list[i] = list[i - 1];  //i-1后移
			int j;
			for (j = i - 1; list[length] < list[j]; j--)
			{//从后向前寻找插入位置
				list[j + 1] = list[j]; //逐个后移
			}
			list[j + 1] = list[length];//插入到正确位置
		}
	}
}
void BubbleSort(int list[], int length)//冒泡排序
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
void SelectSort(int list[], int length)//简单选择排序
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

void QuickSort(int list[], int left, int right)//快速排序
{
	int low = left, high = right;//扫描下标
	int mid = list[(low + high) / 2];//待比较的值
	while (low <= high)
	{
		while (list[low] < mid && low < right)
			//从左到右扫描 找到大于key并记录下标low
			low++;
		while (list[high] > mid && high > left)
			//从右到左扫描 找到小于key的数并记录下标high
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
void HeapAdjust(int list[], int s, int len)
{//假设list[]已经是堆，将其调整为以list[s]为根的的大根堆
	//左右节点的索引
	int left = 2 * s + 1;
	int right = 2 * s + 2;
	//默认当前节点是最大值
	int largeIndex = s;
	if (left<len && list[left]>list[largeIndex])//有左节点并且左节点的值更大
	{
		largeIndex = left;
	}
	if (right<len && list[right]>list[largeIndex])
	{
		largeIndex = right;
	}
	if (largeIndex != s)
	{
		Swap(list[s], list[largeIndex]);//当前节点和最大值的子节点值互换
		HeapAdjust(list, largeIndex, len);//对该子节点的子节点进行调整
	}
}
void CreatHeap(int list[], int length)//把无序序列建成大根堆
{
	//从最后一个非叶结点开始向前遍历 使之成为大根堆
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(list, i, length);
	}
}
void HeapSort(int list[], int length)//堆排序
{
	int len = length;
	CreatHeap(list, length);   //构建大根堆
	for (int i = len - 1; i > 0; i--)
	{//交换堆顶和末尾结点 重置大根堆
		Swap(list[0], list[i]);
		len--;
		HeapAdjust(list, 0, len);
	}
}