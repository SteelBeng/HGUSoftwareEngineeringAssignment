#include <iostream>
#include <string>
#include <stack>

using namespace std;

void LongestCommonSequence(string A, string B)
{
    int m = A.length() + 1;
    int n = B.length() + 1;

    int** c = new int* [m];//A,B中对应的前i,j个字符的LCS的长度
    int** b = new int* [m];//箭头
    
    for (int i = 0; i < m; i++)//初始化并赋初值
    {
        c[i] = new int [n];
        b[i] = new int [n];
        for (int j = 0; j < n; j++)
        {
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (A[i] == B[j])
            {
                c[i + 1][j + 1] = c[i][j] + 1;
                b[i + 1][j + 1] = 1;//↖ 指向左上的箭头
            }
            else if (c[i][j + 1] >= c[i + 1][j])
            {
                c[i + 1][j + 1] = c[i][j + 1];
                b[i + 1][j + 1] = 2;//↑ 指向上的箭头
            }
            else
            {
                c[i + 1][j + 1] = c[i + 1][j];
                b[i + 1][j + 1] = 3;//← 指向左的箭头
            }
        }
    }

    stack<char> same;//存LCS字符
    for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; )
    {
        if (b[i][j] == 1)
        {
            i--;
            j--;
            same.push(A[i]);
        }
        else if (b[i][j] == 2)
            i--;
        else
            j--;
    }

    cout << "最长公共子序列为：";
    while (!same.empty())
    {
        cout << same.top();
        same.pop();
    }
    cout << endl << "长度为：" << c[m - 1][n - 1] << endl;
}

void CoinCollect()
{
    int n, m;//行数和列数
    int arr[15][15];//储存原始方格元素
    int f[15][15];//保存收集到的最大硬币数
    int arr2[15][15];//进行回溯操作时，保存路线坐标

    cout << "请输入格木板的行数（不超过10）:";
    cin >> n;
    cout << "请输入格木板的列数（不超过10）:";
    cin >> m;
    cout << "请输入格木板上硬币放置情况（有硬币为1，没有为0,中间以空格分开）：" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    //将第0行第0列赋值为0
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
        f[0][i] = 0;
    }

    //最大硬币数
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = arr[i][j] + max(f[i - 1][j], f[i][j - 1]);
        }
    }

    //回溯
    int i = n;
    int j = m;
    memset(arr2, 0, sizeof(arr2));//赋值为0
    arr2[1][1] = 1;
    arr2[n][m] = 1;
    while (i >= 1 && j >= 1)
    {
        if (f[i - 1][j] > f[i][j - 1])
        {
            arr2[i - 1][j] = 1;
            i--;
        }
        else
        {
            arr2[i][j - 1] = 1;
            j--;
        }
    }
    cout << "最多可以收集 " << f[n][m] << " 枚硬币" << endl;
    cout << "硬币的收集路线为:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string A = "ABCPDSFJGODIHJOFDIUSHGD";
    string B = "OSDIHGKODGHBLKSJBHKAGHI";

    LongestCommonSequence(A, B);
    CoinCollect();
    return 0;

}

