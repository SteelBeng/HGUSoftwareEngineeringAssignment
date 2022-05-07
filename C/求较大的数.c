#include <stdio.h>

int main()
{
    int i,j,n,max=0,min=9999;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&j);
        if(j>max)
        {
            max=j;
        }
        if(min>j)
        {
            min=j;
        }
    }
    printf("%d %d",max,min);
    return 0;
}
