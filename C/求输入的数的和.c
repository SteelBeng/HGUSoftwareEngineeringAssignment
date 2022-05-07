#include <stdio.h>

int main()
{
    int i,sum=0;
    do
    {
        scanf("%d",&i);
        if(i>0)
        {
            sum=sum+i;
        }
        if(0==i)
        {
            printf("%d",sum);
            return 0;
        }
    }while(i!=0);
}
