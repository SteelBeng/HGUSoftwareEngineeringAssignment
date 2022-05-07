#include "mymian.h"

void Search()
{
	IdxTable table;
	table.length = 5;
	int a[31];
	FILE* fp;
	fp = fopen("IdxTable.txt", "a+");
	for (int i = 0; i < 31; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	int b;
	printf("请输入要查找的数据：");
	scanf("%d", &b);
	printf("其对应位置为：%d", SearchBlocking(table, a, b));
}

int SearchBlocking(IdxTable& table,int a[], int key)//分块查找
{
	//建立表
	int count = 0;
	for (int i = 0; i < table.length; i++)
	{
		int max = 0;
		table.idx[i].start = count;
		for (int j = 0; j < 6; j++)
		{
			if (max < a[count]) max = a[count];
			count++;
		}
		table.idx[i].key = max;
		table.idx[i].end = count;
	}

	int low = 0, high = table.length - 1 , mid;
	while (low <= high)//折半查找
	{
		mid = (low + high) / 2;
		if (key <= table.idx[mid].key)
		{
			if (key <= table.idx[mid - 1].key && mid != 0)
			{
				high = mid - 1;
			}
			else//顺序查找
			{
				for (int i = table.idx[mid].start; i < table.idx[mid].end; i++)
				{
					if (key == a[i]) return i + 1;
				}
				printf("未找到！");
				return 0;
			}
		}
		else
		{
			low = mid + 1;
		}
	}
	printf("未找到！");
	return 0;
}