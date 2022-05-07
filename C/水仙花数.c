#include <stdio.h>

int main()
{
    int i=99,a,b,c;
    for(;i<1000;i++)
    {
        a=i/100%10;
        b=i/10%10;
        c=i%10;
        if(a*a*a+b*b*b+c*c*c == i)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
