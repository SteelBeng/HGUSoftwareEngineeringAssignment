#include <stdio.h>

int main()
{
    float price, money;
    scanf("%f,%f",&price,&money);
    float left = money - price;
    printf("%.2f",left);
    return 0;
}
