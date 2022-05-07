#include <iostream>
#include <map>
#include <random>
#include <cmath>

using namespace std;

void Create(int a[], int length)
{
    random_device rd;//种子
    mt19937 gen(rd());//播种标准

    //产生在一个范围上均匀分布的整数值
    //uniform_int_distribution<> dis(10000, 200000);

    //每次试验成功概率准确为 0.5 的二项分布
    //binomial_distribution<> dis(200000, 0.5);

    //正态分布  值最可能接近平均  标准差影响生成的值距离平均数的分散
    normal_distribution<> dis{ 60000,1000 };

    

    for (int i = 0; i < length; i++)
    {
        a[i] = dis(gen);
    }
}

/*快速排序*/
int QuickSort(int list[], int left, int right)
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
            swap(list[low], list[high]);
            low++;
            high--;
        }
    }
    int part = (low + high) / 2;

    if (left < high) QuickSort(list, left, high); //对左子表递归排序
    if (low < right) QuickSort(list, low, right); //右子表

    return part;
}

/*求平均数*/
void Average(int a[], int length)
{
    long long int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += a[i];
    }
    int average = sum / length;
    cout << "平均数为:" << average << endl;
}

/*直接用快排*/
void MedianQuickSort(int a[], int length)
{
    QuickSort(a, 0, length);
    float median;

    if (length % 2 == 1)
    {
        median = a[(length + 1) / 2];
    }
    else
    {
        median = (a[length / 2] + a[length / 2 + 1]) / 2;
    }
    cout << "MedianQuickSort中位数为:" << median << endl;
}


/*随机选择算法*/
int RandomPartition(int a[], int start, int end)
{
    random_device rd;//种子
    mt19937 gen(rd());//播种标准

    //产生在一个范围上均匀分布的整数值
    uniform_int_distribution<> dis(start, end);

    int pivotIdx = dis(gen);
    
    return QuickSort(a, start, end);
}
int RandomSelection(int a[], int start, int end, int k)
{
    if (start == end) return a[start];
    int p = RandomPartition(a, start, end);
    int x = p - start + 1;

    if (k == x)
        return a[p];
    else if (k < x)
        return RandomSelection(a, start, p - 1, k);
    else
        return RandomSelection(a, p + 1, end, k - x);
}


/*BFPTR*/

//插入排序  
void InsertSort(int a[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (a[i - 1] > a[i])
        {
            int t = a[i];
            int j = i;
            while (j > l && a[j - 1] > t)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = t;
        }
    }
}
//寻找中位数的中位数  
int FindMid(int a[], int l, int r)
{
    if (l == r) return a[l];
    int i = 0;
    int n = 0;
    for (i = l; i < r - 5; i += 5)
    {
        InsertSort(a, i, i + 4);
        n = i - l;
        swap(a[l + n / 5], a[i + 2]);
    }

    //处理剩余元素  
    int num = r - i + 1;
    if (num > 0)
    {
        InsertSort(a, i, i + num - 1);
        n = i - l;
        swap(a[l + n / 5], a[i + num / 2]);
    }
    n /= 5;
    if (n == l) return a[l];
    return FindMid(a, l, l + n);
}
//寻找中位数的所在位置  
int FindId(int a[], int l, int r, int num)
{
    for (int i = l; i <= r; i++)
        if (a[i] == num)
            return i;
    return -1;
}
//进行划分过程  
int Partion(int a[], int l, int r, int p)
{
    swap(a[p], a[l]);
    int i = l;
    int j = r;
    int pivot = a[l];
    while (i < j)
    {
        while (a[j] >= pivot && i < j)
            j--;
        a[i] = a[j];
        while (a[i] <= pivot && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
int BFPTR(int a[], int l, int r, int k)
{
    int num = FindMid(a, l, r);    //寻找中位数的中位数  
    int p = FindId(a, l, r, num); //找到中位数的中位数对应的id  
    int i = Partion(a, l, r, p);

    int m = i - l + 1;
    if (m == k) return a[i];
    if (m > k)  return BFPTR(a, l, i - 1, k);
    return BFPTR(a, i + 1, r, k - m);
}


/*众数*/
void Mode(int a[], int length)
{

    int* b = new int[10000000]();//用于存放每个数据出现的次数；
    int i = 0, max = 0;
    int mode = 0;//众数
    for (i = 0; i < length; i++)
    {
        b[a[i]]++;
    }
    for (i = 0; i < length; i++)
    {
        if (max < b[a[i]])
        {
            max = b[a[i]];
            mode = a[i];
        }
    }
    cout << "众数为:" << mode << endl;
    delete[] b;
}


int main()
{
    clock_t start01, finish01;
    clock_t start02, finish02;
    clock_t start03, finish03;
    clock_t start04, finish04;
    clock_t start05, finish05;
    clock_t start06, finish06;

    int length = 10000000;
    int* a = new int[length]();
    Create(a, length);

    /**for (int i = 0; i < length; i++)
    {
        cout << a[i] << endl;
    }*/

    Average(a, length);

    start01 = clock();
    cout << "RandomSelection中位数为：" << RandomSelection(a, 0, length - 1, length / 2) << endl;
    finish01 = clock();
    cout << "Time:" << (double)(finish01 - start01) / CLOCKS_PER_SEC << "s" << endl;
    cout << endl;

    start02 = clock();
    MedianQuickSort(a, length);
    finish02 = clock();
    cout << "Time:" << (double)(finish02 - start02) / CLOCKS_PER_SEC << "s" << endl;
    cout << endl;

    start03 = clock();
    cout << "BFPTR中位数为：" << BFPTR(a, 0, length - 1, length / 2) << endl;
    finish03 = clock();
    cout << "Time:" << (double)(finish03 - start03) / CLOCKS_PER_SEC << "s" << endl;
    cout << endl;

    Mode(a, length);
    return 0;
}

