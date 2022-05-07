#include <iostream>

#define SIGN(A) ((A>=0) ? 1:-1)

/// <summary>
/// 大整数乘法
/// </summary>
/// <param name="X">整数</param>
/// <param name="Y">整数</param>
/// <param name="N">X和Y小于2^N</param>
/// <returns></returns>
int BigIntegerMultiplication(int X, int Y, int N)
{
    if (X == 0 || Y == 0 || N==0) return 0;
    if (N == 1) return X * Y;

    int sign = SIGN(X) * SIGN(Y);//X与Y的符号乘积
    int x = abs(X);//取绝对值
    int y = abs(Y);

    //X=A*2^(N/2)+B   Y=C*2^(N/2)+D
    //XY = AC*2^n + ((A-B)(D-C)+AC+BD)*2^(N/2) + BD
    int A = x / (int)pow(10, (int)(N / 2));
    int B = x % (int)pow(10, (int)(N / 2));
    int C = y / (int)pow(10, (int)(N / 2));
    int D = y % (int)pow(10, (int)(N / 2));

    int AC = BigIntegerMultiplication(A, C, (int)(N / 2));
    int BD = BigIntegerMultiplication(B, D, (int)(N / 2));
    int ABCD = BigIntegerMultiplication(A - B, D - C, (int)(N / 2)) + AC + BD;
    
    return sign * (AC * (int)pow(10, (int)N / 2+ (int)N / 2) + ABCD * (int)pow(10, (int)N / 2) + BD);

}

int main()
{
    int x = 12345;
    int y = 23456;
    std::cout << "x * y = " << BigIntegerMultiplication(x, y, 5) << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
}
