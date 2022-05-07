#include <stdio.h>
#define RATE 0.0225

int main()
{
    float money_base;
    int year;
    scanf("%f",&money_base);
    getchar();
    scanf("%d",&year);
    float money = money_base + money_base*RATE*year;
    printf("%.2f",money);
    return 0;
}
