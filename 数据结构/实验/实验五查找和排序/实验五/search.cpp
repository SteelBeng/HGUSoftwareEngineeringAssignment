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
	printf("������Ҫ���ҵ����ݣ�");
	scanf("%d", &b);
	printf("���Ӧλ��Ϊ��%d", SearchBlocking(table, a, b));
}

int SearchBlocking(IdxTable& table,int a[], int key)//�ֿ����
{
	//������
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
	while (low <= high)//�۰����
	{
		mid = (low + high) / 2;
		if (key <= table.idx[mid].key)
		{
			if (key <= table.idx[mid - 1].key && mid != 0)
			{
				high = mid - 1;
			}
			else//˳�����
			{
				for (int i = table.idx[mid].start; i < table.idx[mid].end; i++)
				{
					if (key == a[i]) return i + 1;
				}
				printf("δ�ҵ���");
				return 0;
			}
		}
		else
		{
			low = mid + 1;
		}
	}
	printf("δ�ҵ���");
	return 0;
}