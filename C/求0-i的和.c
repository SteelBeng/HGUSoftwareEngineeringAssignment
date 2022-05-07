#include <stdio.h>

int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        i=i+1;
        sum=sum+i;
    }
    printf("%d",sum);
    return 0;
}
