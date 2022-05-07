#include "MyMain.h"

int main()
{
	int length = 9999;
	int list[10000];
	//冒泡
	NixuArray(length, list);

	clock_t bubbleStartTime, bubbleEndTime;

	bubbleStartTime = clock();//计时开始
	BubbleSort(list, length);
	bubbleEndTime = clock();//计时结束

	cout << "The Bubble run time is: " << (double)(bubbleEndTime - bubbleStartTime) / CLOCKS_PER_SEC << "s" << endl;



	//插入
	NixuArray(length, list);

	clock_t InsertStartTime, InsertEndTime;

	InsertStartTime = clock();//计时开始
	InsertSort(list, length);
	InsertEndTime = clock();//计时结束

	cout << "The Insert run time is: " << (double)(InsertEndTime - InsertStartTime) / CLOCKS_PER_SEC << "s" << endl;

	//选择
	NixuArray(length, list);

	clock_t SelectStartTime, SelectEndTime;

	SelectStartTime = clock();//计时开始
	SelectSort(list, length);
	SelectEndTime = clock();//计时结束

	cout << "The Select run time is: " << (double)(SelectEndTime - SelectStartTime) / CLOCKS_PER_SEC << "s" << endl;

	//快速
	RandomArray(length, list);

	clock_t QuickStartTime, QuickEndTime;

	QuickStartTime = clock();//计时开始
	QuickSort(list, 0, length);
	QuickEndTime = clock();//计时结束

	cout << "The Quick run time is: " << (double)(QuickEndTime - QuickStartTime) / CLOCKS_PER_SEC << "s" << endl;

	//堆
	RandomArray(length, list);

	clock_t HeapStartTime, HeapEndTime;

	HeapStartTime = clock();//计时开始
	HeapSort(list, length);
	HeapEndTime = clock();//计时结束

	cout << "The Heap run time is: " << (double)(HeapEndTime - HeapStartTime) / CLOCKS_PER_SEC << "s" << endl;

	return 0;
}
