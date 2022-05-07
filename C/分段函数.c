#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d",&x);
    if(x<0)
    {
        y = x+10;
    }
    else
    {
        if(x>=10)
        {
            y = x-2;
        }
        else
        {
            y = 4*x -10;
        }
    }
    printf("%d",y);
    return 0;
}
